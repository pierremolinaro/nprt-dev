#include "collections/TC_UniqueArray.h"
#include "files/C_HTML_FileWrite.h"
#include "galgas/C_CompilerEx.h"
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "ExtendedList.h"


/*-----------------------------------------------------------------------------*/

cResponseTime::cResponseTime (void) :
mBestResponseTime (PMSINT32_MAX),
mWorstResponseTime (0) {
} ;

/*-----------------------------------------------------------------------------*/

static PMUInt64 GCD(PMUInt64 a, PMUInt64 b) {
  PMUInt64 r;
  do{
    r = a%b;
    a = b;
    b = r;
  }while( r != 0);
  return (a);
}

/*---------------------------------------------------------------------------*/ 
static PMUInt64
CalculateHyperPeriod (const TC_UniqueArray <cElement> & Element) {
  
  PMSInt32 minimumOffset = PMSINT32_MAX ;
  PMUInt64 LCM = 0 ;
  PMSInt32 maximumOffset= 0 ;

// Calculate the LCM for independent elements only since dependent ones inherit periods  
  const PMSInt32 Nu_ofElements = Element.count () ;
  for (PMSInt32 index = 0 ; index < Nu_ofElements; index++) {
    if (Element (index COMMA_HERE).mIsIndependant
        || 
        (Element (index COMMA_HERE).mEvery != 1) ) {
      if (LCM == 0) {
        LCM = Element (index COMMA_HERE).mPeriod ;
      }else{
        LCM = Element (index COMMA_HERE).mPeriod * Element (index COMMA_HERE).mEvery * LCM / GCD (Element (index COMMA_HERE).mPeriod * Element (index COMMA_HERE).mEvery, LCM) ;
      }
      if (Element (index COMMA_HERE).mIsIndependant){
        minimumOffset = min (minimumOffset, Element (index COMMA_HERE).mOffset);
        maximumOffset = MAX (maximumOffset, Element (index COMMA_HERE).mOffset);
      }
    }
  }

/*if all independent elements are activated simultaneously & all dependent elements
  can not be blocked if their precedence constraned are satisfied --> Hyper period = LCM
  otherwise, Hyper period = 2*LCM + maximum offset */  
  
  PMUInt64 HyperPeriod = 0 ;
  if (minimumOffset == maximumOffset) {
    HyperPeriod  = LCM + maximumOffset ;
  }else{
    HyperPeriod = LCM + LCM + maximumOffset;
  }
  printf ("HyperPeriod : %llu\n", HyperPeriod) ;
  
  return HyperPeriod ;
}

/*----------------------------------------------------------------------*/

// Unused function : commented out by PM 17/1/2005
/* static PMSInt32 
CalculateExtendedListLength (const TC_UniqueArray <cElement> & Element,
                             const PMUInt64 inHyperPeriod) {
  
  PMSInt32 ExtendedListLength=0;
  const PMSInt32 N_Elements = Element.count () ;
  for(PMSInt32 index =0; index < N_Elements; index ++){
    ExtendedListLength += PMSInt32 ( inHyperPeriod / Element (index COMMA_HERE).mPeriod) ;
  }
  return ExtendedListLength;
}
*/

/*-----------------------------------------------------------------------------*/
static void
ExtractResourceMinDuration (TC_UniqueArray <cElement> & Element,
                            const TC_UniqueArray <cResource> & Resource){

PMSInt32 NumOfResources = Resource.count();
PMSInt32 NumOfElements = Element.count();
PMSInt32 minDuration=PMSINT32_MAX;

	for (PMSInt32 index = 0; index < NumOfResources ;index++){
    for (PMSInt32 i = 0; i < NumOfElements ;i++){
      if( index == Element (i COMMA_HERE).mResourceId){
       	minDuration = min( minDuration, Element (i COMMA_HERE).mMinDuration);
       	Element (i COMMA_HERE).mEvery = Element (i COMMA_HERE).mEveryMultiple;
      }
    }
	}
} 

/*----------------------------------------------------------------------------*/
static void 
InsertInOrderedList(const TC_UniqueArray <cElement> & Element,
	                  TC_UniqueArray <cElement> & ArrangedElement,
                    const PMSInt32 ElementCounter) {  
  cElement element;
   
  strcpy (element.mElementName, Element(ElementCounter COMMA_HERE).mElementName);   
  element.mElementType = Element(ElementCounter COMMA_HERE).mElementType;
  element.mResourceId = Element(ElementCounter COMMA_HERE).mResourceId;
  element.mPredecessorType =Element(ElementCounter COMMA_HERE).mPredecessorType;
  element.mId_inList = Element (ElementCounter COMMA_HERE).mId_inList;
  element.mEvery = Element (ElementCounter COMMA_HERE).mEvery;
  element.mPriority = Element(ElementCounter COMMA_HERE).mPriority;
  element.mOffset = Element(ElementCounter COMMA_HERE).mOffset;  
  element.mMinDuration = Element(ElementCounter COMMA_HERE).mMinDuration; //modified 
  element.mMaxDuration = Element(ElementCounter COMMA_HERE).mMaxDuration;
 // printf (" Min : %ld & Max : %ld \n",element.mMinDuration, element.mMaxDuration );
  element.mPeriod = Element(ElementCounter COMMA_HERE).mPeriod;
  element.mDeadline = Element(ElementCounter COMMA_HERE).mDeadline;
  
  if( Element (ElementCounter COMMA_HERE).mIsIndependant) {
    element.mPredecessorId = -1;
  }else{
    PMSInt32 i = 0;
    bool PredecessorIsFound = false;
    while(! PredecessorIsFound){
      if((ArrangedElement(i COMMA_HERE).mElementType == element.mPredecessorType)  
        && 
        (ArrangedElement (i COMMA_HERE).mId_inList == 
          Element(ElementCounter COMMA_HERE).mPredecessorId)) {
                    
               element.mPredecessorId = i;
               PredecessorIsFound =true;
                    
      }else{
        i++;
      }
    }   
  }    
  element.mOtherHeirId= -1; 
  
  ArrangedElement.addObject (element);  
}    

/*---------------------------------------------------------------------------*/ 
static void
ArrangingAccodingPrecedenceRelations(
                   const TC_UniqueArray <cElement> & Element,
                   TC_UniqueArray <cElement> & ArrangedElement,
                   const PMSInt32 Nu_ofTasks,
                   const PMSInt32 Nu_ofMessages) {
                             
  PMSInt32 TaskCounter = 0 ;
  PMSInt32 MessageCounter = Nu_ofTasks ;  
  do{
//If a task is independent or its  predecessor is arranged, insert it!
    while ( (TaskCounter <Nu_ofTasks) 
    				&&  
       			(Element (TaskCounter COMMA_HERE).mIsIndependant 
       			||
       			(Element (TaskCounter COMMA_HERE).mPredecessorType == 'T') 
       			||
       			( (Element (TaskCounter COMMA_HERE).mPredecessorType == 'M') 
       				&&
         			(Element (TaskCounter COMMA_HERE).mPredecessorId < (MessageCounter -Nu_ofTasks )) )
         		) ) { 
    				/*		printf("Task : %s and TaskCounter : %ld.\n", 
          				Element (TaskCounter COMMA_HERE).mElementName,
          				TaskCounter);*/
          InsertInOrderedList(Element, ArrangedElement,TaskCounter);
          TaskCounter ++;
    } 

//If a message is independent or all its predecessor is arranged, insert it!    
    while ( (MessageCounter <(Nu_ofTasks+Nu_ofMessages)) 
     				&&
        		(Element (MessageCounter COMMA_HERE).mIsIndependant 
        		||
        	  (Element (MessageCounter COMMA_HERE).mPredecessorType == 'M') 
        		||
        		( (Element (MessageCounter COMMA_HERE).mPredecessorType == 'T') 
        			&&
         			(Element (MessageCounter COMMA_HERE).mPredecessorId < TaskCounter) )
         		) ) {

          		/*	printf("Message : %s and MessageCounter : %ld.\n", 
          				Element (MessageCounter COMMA_HERE).mElementName,
          				MessageCounter-Nu_ofTasks);*/
          InsertInOrderedList(Element, ArrangedElement,MessageCounter);
          MessageCounter ++;
    }
    
  } while ((TaskCounter <Nu_ofTasks) || (MessageCounter <(Nu_ofMessages+Nu_ofTasks)));
}
    
/*----------------------------------------------------------------------------*/
static bool 
VerifyInterDependence (TC_UniqueArray <cElement> & Element){
 	const PMSInt32 Nu_ofElements = Element.count () ;
 	bool interDependence=false;
  for (PMSInt32 i = 0; (i < Nu_ofElements)  && !interDependence ;i++){
  	if( (Element (i COMMA_HERE).mPredecessorId >=0 )
         &&
         ( (Element (i COMMA_HERE).mResourceId != 
            Element (Element (i COMMA_HERE).mPredecessorId COMMA_HERE).mResourceId)) 
         ){
				 interDependence = true;
		}
  }
  return interDependence;
}

/*--------------------------------------------------------------------------*/

static void 
FindSuccessors (TC_UniqueArray <cElement> & Element){
  
  const PMSInt32 Nu_ofElements = Element.count () ;
  Element (Nu_ofElements-1 COMMA_HERE).mSuccessorId = -1;
  Element (Nu_ofElements-1 COMMA_HERE).mOtherHeirId= -1;
  
  for( PMSInt32 index = 0; index < Nu_ofElements-1 ;index++){
    Element (index COMMA_HERE).mSuccessorId = -1;
 
    PMSInt32 temp_index = 0 ;
    
    for( PMSInt32 i = index+1; i < Nu_ofElements ;i++){
      if(Element (i COMMA_HERE).mPredecessorId == index) {
    	  if (Element (index COMMA_HERE).mSuccessorId < 0 ) {
    	  	Element (index COMMA_HERE).mSuccessorId = i; 
    	  	temp_index = i;
    	 
    	  }else {
    	  	Element (temp_index COMMA_HERE).mOtherHeirId = i;
    	  	temp_index = i ;
    	  	
    	  }
      }
    } 
  }
}

/*---------------------------------------------------------------------------*/
static PMSInt32
DeployElements (TC_UniqueArray <cElement> & ArrangedElement,
                TC_UniqueArray <cActivity> & exElement,
                TC_UniqueArray <cMTElement> & outMTElement,
                const PMUInt64 inHyperPeriod){

//Arrange elements according to their precedence relations

  PMSInt32 interIndex ;
  PMSInt32 ExtendedIndicator =0;
  PMSInt32 SuccessorGap;
  PMSInt32 OtherHeirGap;
        
  const PMSInt32 Nu_ofElements = ArrangedElement.count () ;
  PMSInt32 Num_of_Activties = 0 ;
  for ( PMSInt32 index = 0; index < Nu_ofElements; index ++) {
    cMTElement element;
    
    element.mPeriod = ArrangedElement (index COMMA_HERE).mPeriod;
  //Keep the number of occurence during the hyper period
    ArrangedElement (index COMMA_HERE).mInExtendedList = ExtendedIndicator;            
    element.mWidth = 
          (PMSInt32) (inHyperPeriod /ArrangedElement(index COMMA_HERE).mPeriod) ; 
  /*    
        printf("Element Id = %d & its 1st occurence is : %d and has awidth = %d.\n",
            index +1,ExtendedIndicator+1,element.mWidth); */ 
      
    if (ArrangedElement (index COMMA_HERE).mSuccessorId != -1) {
      SuccessorGap = 0;
      for(PMSInt32 i= index; i< ArrangedElement (index COMMA_HERE).mSuccessorId;i++) {
        SuccessorGap += (PMSInt32) (inHyperPeriod /ArrangedElement(i COMMA_HERE).mPeriod);    
      }
      ArrangedElement (index COMMA_HERE).mSuccessorId =ExtendedIndicator + SuccessorGap ;
    } 
    
    if (ArrangedElement (index COMMA_HERE).mOtherHeirId != -1) {
      OtherHeirGap = 0;
      for(PMSInt32 i= index; i<ArrangedElement (index COMMA_HERE).mOtherHeirId;i++) {
        OtherHeirGap += (PMSInt32) (inHyperPeriod /ArrangedElement(i COMMA_HERE).mPeriod);    
      }
      ArrangedElement (index COMMA_HERE).mOtherHeirId =ExtendedIndicator + OtherHeirGap ;
    } 
      
    ExtendedIndicator += (PMSInt32) element.mWidth;    
    if (ArrangedElement (index COMMA_HERE).mPredecessorId == -1) {
      element.mOffset = ArrangedElement (index COMMA_HERE).mOffset;
     }else {
       PMSInt32 predecessorId = ArrangedElement (index COMMA_HERE).mPredecessorId ;
       element.mOffset = outMTElement (predecessorId COMMA_HERE).mOffset;
     }
    
    outMTElement.addObject (element);
    
    
    PMSInt32 Repetition =0;
        
    for(PMSInt32 clicktime = 0; 
    	((PMUInt32) clicktime) <= (inHyperPeriod - ArrangedElement (index COMMA_HERE).mPeriod) ; clicktime++) {
    
      if ( clicktime% ArrangedElement (index COMMA_HERE).mPeriod == 0) {
          
        cActivity MTelement ;  //Message or Task Element
        MTelement.mOtherReadyAtThisInst = -1;
        MTelement.mOccurrence = Repetition +1;
        MTelement.mResourceId = ArrangedElement (index COMMA_HERE).mResourceId ;
        MTelement.mEvery = ArrangedElement (index COMMA_HERE).mEvery ;
        strcpy(MTelement.mElementName, ArrangedElement (index COMMA_HERE).mElementName);
        MTelement.mPriority = ArrangedElement (index COMMA_HERE).mPriority ;
        
        if (ArrangedElement (index COMMA_HERE).mPredecessorId == -1) {
        	MTelement.mOffset = clicktime + ArrangedElement (index COMMA_HERE).mOffset;
        }else {
        	MTelement.mOffset = ArrangedElement (index COMMA_HERE).mOffset;
        }
                
        MTelement.mMinDuration = ArrangedElement (index COMMA_HERE).mMinDuration ;
        MTelement.mMaxDuration = ArrangedElement (index COMMA_HERE).mMaxDuration ;
        
        if (ArrangedElement (index COMMA_HERE).mDeadline == PMSINT32_MAX) {
		     	MTelement.mDeadline = PMSINT32_MAX;
		    }else{
		     	MTelement.mDeadline = clicktime +	ArrangedElement (index COMMA_HERE).mDeadline ;
		    }
        
//If the element is independent, it's predecessor Id will be -1
              
        if (ArrangedElement (index COMMA_HERE).mPredecessorId == -1) {
          MTelement.mPredecessorId = -1 ; 
        }else{ 
          interIndex = PMSInt32 (ArrangedElement(index COMMA_HERE).mPredecessorId);
                 
          MTelement.mPredecessorId = Repetition + 
               ArrangedElement (interIndex COMMA_HERE).mInExtendedList ; 
        }  
          
        if (ArrangedElement (index COMMA_HERE).mSuccessorId != -1)	{
          MTelement.mSuccessorId = 
          				Repetition + ArrangedElement (index COMMA_HERE).mSuccessorId;
        }else{
          MTelement.mSuccessorId = -1;
        }  
        
         if (ArrangedElement (index COMMA_HERE).mOtherHeirId != -1)	{
          MTelement.mOtherHeirId = 
          				Repetition + ArrangedElement (index COMMA_HERE).mOtherHeirId;
        }else{
          MTelement.mOtherHeirId = -1;
        }  
      	exElement.addObject (MTelement) ;
      	if ( (MTelement.mOccurrence %MTelement.mEvery) == 0){
      		Num_of_Activties ++;
      	}
        Repetition = Repetition +1;
      } //if time = multiple of element's period
    } // End timing the hyper period deployment 
  }
  return Num_of_Activties ;
}
/*-------------------------------------------------------------------------*/

static void 
DisposeReadyAtRelations(const TC_UniqueArray <cElement> & ArrangedElement,
                        TC_UniqueArray <cActivity> & Activity,
                        TC_UniqueArray <cReadyAtThisInstant> & ReadyAtThisInstant,
                        const PMUInt64 inHyperPeriod){

TC_UniqueArray <cReadyAtThisInstant>  oReadyAtThisInstant ;	

	//--- calculate max size
	PMSInt32 Num_ofIndepStaringInstant=0;
	for ( PMSInt32 index = 0; index < ArrangedElement.count(); index ++) {
   	if ( ArrangedElement (index COMMA_HERE).mPredecessorId < 0){
   	   Num_ofIndepStaringInstant += (PMSInt32) inHyperPeriod/ArrangedElement (index COMMA_HERE).mPeriod  ;
   	}
  }
  //--- Initilize 
  for (PMSInt32 i = 0; i <Num_ofIndepStaringInstant; i ++) {
	  cReadyAtThisInstant readyAtThisInstant;
      readyAtThisInstant.mThisInstant=-1;
      readyAtThisInstant.mActivityIndex=-1; 
      readyAtThisInstant.mMarked = false;  
    oReadyAtThisInstant.addObject(readyAtThisInstant); 
	}
  
    
	PMSInt32 IdInList = 0;
  
  for ( PMSInt32 index = 0; index < ArrangedElement.count(); index ++) {
   	if ( ArrangedElement (index COMMA_HERE).mPredecessorId < 0){
   	   PMSInt32 NextOccurrence = ArrangedElement (index COMMA_HERE).mOffset ;
   	   while (NextOccurrence <= (ArrangedElement (index COMMA_HERE).mOffset+ ((PMSInt32)inHyperPeriod) - ArrangedElement (index COMMA_HERE).mPeriod)) {
   	     bool theSameInstantIsFound = false;
   	     PMSInt32 interindex=0;
   	     while( (interindex < Num_ofIndepStaringInstant) 
   	     			 &&
   	     			 (!theSameInstantIsFound)
   	     			 &&
   	           (oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant >= 0)){
   	           
   	           if (NextOccurrence == oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant){
   	           	 PMSInt32 ActivityIndex = oReadyAtThisInstant (interindex COMMA_HERE).mActivityIndex;
   	           	 while (  Activity (ActivityIndex COMMA_HERE).mOtherReadyAtThisInst != -1){
   	           	   ActivityIndex = Activity (ActivityIndex COMMA_HERE).mOtherReadyAtThisInst ;
   	           	 }
   	           	 Activity (ActivityIndex COMMA_HERE).mOtherReadyAtThisInst = IdInList ;   	           
   	             theSameInstantIsFound = true;
   	           } 
   	      	 interindex ++;
   	     } 
   	     if(!theSameInstantIsFound){
   	     
   	     	 oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant = NextOccurrence ;
   	     	 oReadyAtThisInstant (interindex COMMA_HERE).mActivityIndex = IdInList ;
   	     
   	     }
   	     IdInList ++;
   	     
   	   	 NextOccurrence += ArrangedElement (index COMMA_HERE).mPeriod;
   	   }
   	} else {
   		IdInList += (PMSInt32) inHyperPeriod/ArrangedElement (index COMMA_HERE).mPeriod ;
   	}
  }
  
//  printf(" Num_ofIndepStaringInstant : %ld.\n", Num_ofIndepStaringInstant);
  PMSInt32 sizeofStarting = 0;
  PMSInt32 interindex=0;
  while ( (interindex < Num_ofIndepStaringInstant)
           &&
           (oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant != -1) ){
  //  PMSInt32 ActivityIndex = oReadyAtThisInstant (interindex COMMA_HERE).mActivityIndex; // Commented out PM 17/1/2005
    /*printf("Activitites ready at : %ld are:\n",Activity (ActivityIndex COMMA_HERE).mOffset);
    printf("Activity : %ld & ",ActivityIndex);
    fflush(stdout); */
    sizeofStarting ++;
   
    /*while ( (ActivityIndex = Activity (ActivityIndex COMMA_HERE).mOtherReadyAtThisInst) !=-1){
   	  printf("Activity : %ld & ",ActivityIndex);
   	  sizeofStarting ++;
   	}
    printf(".\n",interindex);*/
    interindex ++;
  }

  PMSInt32 lIndex = 0 ;
 
   for ( PMSInt32 index = 0; index < interindex ; index ++) {
  	PMSInt32 minStarting = PMSINT32_MAX;
  	for (PMSInt32 i = 0; i < sizeofStarting ; i ++) {
    	if ( !oReadyAtThisInstant (i COMMA_HERE).mMarked){
    		if ( (minStarting=min(minStarting,oReadyAtThisInstant (i COMMA_HERE).mThisInstant))==
    			oReadyAtThisInstant (i COMMA_HERE).mThisInstant ){
    		  lIndex=i;	
    		}
    	}
    }
    oReadyAtThisInstant (lIndex COMMA_HERE).mMarked = true;
  	cReadyAtThisInstant readyAtThisInstant;
     	readyAtThisInstant.mThisInstant = oReadyAtThisInstant (lIndex COMMA_HERE).mThisInstant;
    	readyAtThisInstant.mActivityIndex = oReadyAtThisInstant (lIndex COMMA_HERE).mActivityIndex;
    	readyAtThisInstant.mMarked = false;
    	
   // 	printf ("index : %ld Instant %ld\n",index,oReadyAtThisInstant (lIndex COMMA_HERE).mThisInstant);
    ReadyAtThisInstant.addObject(readyAtThisInstant); 
  }
/*  for ( PMSInt32 i = 0; i < sizeofStarting ; i ++) {
  	printf("------Activitites at : %ld are:\n",ReadyAtThisInstant (i COMMA_HERE).mThisInstant);
  	PMSInt32 Activ =ReadyAtThisInstant (i COMMA_HERE).mActivityIndex;
    printf("Activity : %ld & ",Activ);
   	while ( (Activ = Activity (Activ COMMA_HERE).mOtherReadyAtThisInst) !=-1){
      printf("Activity : %ld & ",Activ);
   	}
    printf(".\n");
  }*/
}

/*-------------------------------------------------------------------------*/
static void
CreateActivitiesFile (C_CompilerEx & inLexique,
                      const TC_UniqueArray <cActivity> & exElement,
							      	const C_String & activitiesHTMLFileName){

  const PMSInt32 NumberOfElements = exElement.count () ;
  printf ("Extended activities list is stored in %s file.\n", activitiesHTMLFileName.cString (HERE)) ;
  bool ok = false ;
  C_HTML_FileWrite act_htmlFile (activitiesHTMLFileName,
                              "Extended List Activities",
                              "style.css",
                              ""
                              COMMA_SAFARI_CREATOR,
                              ok) ;
  if (! ok) {
    C_String message ;
    message << "Cannot open '" << activitiesHTMLFileName << "' file in write mode." ;
    inLexique.onTheFlySemanticError (message COMMA_HERE) ;
  }
		
	act_htmlFile.appendCppTitleComment ("raw Activities map", "title") ;
	act_htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	act_htmlFile.outputRawData ("#</td><td>Activity</td><td>Resource</td><td>Priority</td><td>");
  act_htmlFile.outputRawData ("Occurrence</td><td>Offset</td><td>minDur.</td><td>");
  act_htmlFile.outputRawData ("MaxDur.</td><td>Predecessor</td></tr>") ;
		
 	for (PMSInt32 index = 0; index < NumberOfElements ;index++) {
 	  if ( (exElement (index COMMA_HERE).mOccurrence % exElement (index COMMA_HERE).mEvery) == 0 ){
			act_htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
		  act_htmlFile << cStringWithSigned (index) ;
		  act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << exElement (index COMMA_HERE).mElementName;  
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mResourceId) ;
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mPriority) ;
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mOccurrence/exElement (index COMMA_HERE).mEvery);
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mOffset);  
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mMinDuration); 
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mMaxDuration);
	    act_htmlFile.outputRawData ("</td><td>") ;
		  act_htmlFile << cStringWithSigned (exElement (index COMMA_HERE).mPredecessorId);
	    act_htmlFile.outputRawData ("</td><td>") ;
		}
	}
	act_htmlFile.outputRawData ("</table>") ;
	act_htmlFile.outputRawData ("<br>");	    
}
	
/*----------------------------------------------------------------------------*/

PMSInt32
BuildExtendedList (C_CompilerEx & inLexique,
                   TC_UniqueArray <cReadyAtThisInstant> & oReadyAtThisInstant,
                   TC_UniqueArray <cElement> & Element,
                   const TC_UniqueArray <cResource> & Resource,
                   TC_UniqueArray <cActivity> & exElement,
                   TC_UniqueArray <cMTElement> & outMTElement,
                   const PMSInt32 Nu_ofTasks, PMSInt32 Nu_ofMessages,
                   bool CreateIntermediateFiles,
                   bool & ioUseBalgorithm,
                   const C_String & activitiesHTMLFileName) {

      
  ExtractResourceMinDuration(Element, Resource);
  const PMUInt64 HyperPeriod = CalculateHyperPeriod (Element) ;
  const PMSInt32 Number_ofResources = Resource.count();
  TC_UniqueArray <cElement> ArrangedElement;
  PMSInt32 NoInterDependenceButUseB = 0;
  ArrangingAccodingPrecedenceRelations (Element, ArrangedElement,
                                        Nu_ofTasks,Nu_ofMessages);
  
  FindSuccessors (ArrangedElement);
 // const PMSInt32 ActivitiesNumber = CalculateExtendedListLength(Element, HyperPeriod) ; // Commented out PM 17/1/2005
	const PMSInt32 Num_of_Activties = 
	      DeployElements (ArrangedElement, exElement, outMTElement, HyperPeriod);
 	
 	co << cStringWithSigned (Num_of_Activties) << " activities\n" ;
  co.flush ();
 	if (CreateIntermediateFiles){
	 	CreateActivitiesFile (inLexique, exElement, activitiesHTMLFileName);
  } 
  															
  if (! VerifyInterDependence (ArrangedElement)) {
    if (ioUseBalgorithm) {
      DisposeReadyAtRelations( ArrangedElement, exElement, oReadyAtThisInstant, HyperPeriod); 
      NoInterDependenceButUseB = 1;
  	//  printf("There is no interdependence between resources. But by command line option\n");
      fflush (stdout) ;
    }else{
      if (Number_ofResources == 1) {
      	printf("Only one resource.\n");
      } else{
     	  printf("There is no interdependence between resources.\n");
      }
      fflush (stdout) ;
    }
  }else{
    ioUseBalgorithm = true ;
  //  printf("There is an interdependence between resources.\n");
    fflush (stdout);
    DisposeReadyAtRelations( ArrangedElement, exElement, oReadyAtThisInstant, HyperPeriod);
  }
    	    
  return NoInterDependenceButUseB ;
}

/*---------------------------------------------------------------------------*/
