#include "GenericUniqueArray.h"
#include "HTMLFileWrite.h"
#include "Compiler.h"

#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "ExtendedList-v2.h"


/*-----------------------------------------------------------------------------*/

cResponseTime::cResponseTime (void) :
mBestResponseTime (INT32_MAX),
mWorstResponseTime (0) {
} ;

/*-----------------------------------------------------------------------------*/

static uint64_t GCD(uint64_t a, uint64_t b) {
  uint64_t r;
  do{
    r = a%b;
    a = b;
    b = r;
  }while( r != 0);
  return (a);
}

/*---------------------------------------------------------------------------*/
static uint64_t
CalculateHyperPeriod (const GenericUniqueArray <cElement> & Element) {

  int32_t minimumOffset = INT32_MAX ;
  uint64_t LCM = 0 ;
  int32_t maximumOffset= 0 ;

// Calculate the LCM for independent elements only since dependent ones inherit periods
  const int32_t Nu_ofElements = Element.count () ;
  for (int32_t index = 0 ; index < Nu_ofElements; index++) {
    if (Element (index COMMA_HERE).mIsIndependant
        ||
        (Element (index COMMA_HERE).mEvery != 1) ) {
      if (LCM == 0) {
        LCM = (uint64_t) Element (index COMMA_HERE).mPeriod ;
      }else{
        LCM = ((uint64_t) (Element (index COMMA_HERE).mPeriod * Element (index COMMA_HERE).mEvery)) * LCM / GCD ((uint64_t) (Element (index COMMA_HERE).mPeriod * Element (index COMMA_HERE).mEvery), LCM) ;
      }
      if (Element (index COMMA_HERE).mIsIndependant){
        minimumOffset = std::min (minimumOffset, Element (index COMMA_HERE).mOffset);
        maximumOffset = std::max (maximumOffset, Element (index COMMA_HERE).mOffset);
      }
    }
  }

/*if all independent elements are activated simultaneously & all dependent elements
  can not be blocked if their precedence constraned are satisfied --> Hyper period = LCM
  otherwise, Hyper period = 2*LCM + maximum offset */

  uint64_t HyperPeriod = 0 ;
  if (minimumOffset == maximumOffset) {
    HyperPeriod  = LCM + (uint32_t) maximumOffset ;
  }else{
    HyperPeriod = LCM + LCM + (uint32_t) maximumOffset;
  }
  gCout.appendString ("HyperPeriod : ") ;
  gCout.appendUnsigned (HyperPeriod) ;
  gCout.appendString ("\n") ;

  return HyperPeriod ;
}

/*----------------------------------------------------------------------*/

// Unused function : commented out by PM 17/1/2005
/* static int32_t
CalculateExtendedListLength (const GenericUniqueArray <cElement> & Element,
                             const uint64_t inHyperPeriod) {

  int32_t ExtendedListLength=0;
  const int32_t N_Elements = Element.count () ;
  for(int32_t index =0; index < N_Elements; index ++){
    ExtendedListLength += int32_t ( inHyperPeriod / Element (index COMMA_HERE).mPeriod) ;
  }
  return ExtendedListLength;
}
*/

/*-----------------------------------------------------------------------------*/
static void
ExtractResourceMinDuration (GenericUniqueArray <cElement> & Element,
                            const GenericUniqueArray <cResource> & Resource){

int32_t NumOfResources = Resource.count();
int32_t NumOfElements = Element.count();
int32_t minDuration=INT32_MAX;

	for (int32_t index = 0; index < NumOfResources ;index++){
    for (int32_t i = 0; i < NumOfElements ;i++){
      if( index == Element (i COMMA_HERE).mResourceId){
       	minDuration = std::min( minDuration, Element (i COMMA_HERE).mMinDuration);
       	Element (i COMMA_HERE).mEvery = Element (i COMMA_HERE).mEveryMultiple;
      }
    }
	}
}

/*----------------------------------------------------------------------------*/
static void
InsertInOrderedList(const GenericUniqueArray <cElement> & Element,
	                  GenericUniqueArray <cElement> & ArrangedElement,
                    const int32_t ElementCounter) {
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
    int32_t i = 0;
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

  ArrangedElement.appendObject (element);
}

/*---------------------------------------------------------------------------*/
static void
ArrangingAccodingPrecedenceRelations(
                   const GenericUniqueArray <cElement> & Element,
                   GenericUniqueArray <cElement> & ArrangedElement,
                   const int32_t Nu_ofTasks,
                   const int32_t Nu_ofMessages) {

  int32_t TaskCounter = 0 ;
  int32_t MessageCounter = Nu_ofTasks ;
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
VerifyInterDependence (GenericUniqueArray <cElement> & Element){
 	const int32_t Nu_ofElements = Element.count () ;
 	bool interDependence=false;
  for (int32_t i = 0; (i < Nu_ofElements)  && !interDependence ;i++){
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
FindSuccessors (GenericUniqueArray <cElement> & Element){

  const int32_t Nu_ofElements = Element.count () ;
  Element (Nu_ofElements-1 COMMA_HERE).mSuccessorId = -1;
  Element (Nu_ofElements-1 COMMA_HERE).mOtherHeirId= -1;

  for( int32_t index = 0; index < Nu_ofElements-1 ;index++){
    Element (index COMMA_HERE).mSuccessorId = -1;

    int32_t temp_index = 0 ;

    for( int32_t i = index+1; i < Nu_ofElements ;i++){
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
static int32_t
DeployElements (GenericUniqueArray <cElement> & ArrangedElement,
                GenericUniqueArray <cActivity> & exElement,
                GenericUniqueArray <cMTElement> & outMTElement,
                const uint64_t inHyperPeriod){

//Arrange elements according to their precedence relations

  int32_t interIndex ;
  int32_t ExtendedIndicator =0;
  int32_t SuccessorGap;
  int32_t OtherHeirGap;

  const int32_t Nu_ofElements = ArrangedElement.count () ;
  int32_t Num_of_Activties = 0 ;
  for ( int32_t index = 0; index < Nu_ofElements; index ++) {
    cMTElement element;

    element.mPeriod = ArrangedElement (index COMMA_HERE).mPeriod;
  //Keep the number of occurence during the hyper period
    ArrangedElement (index COMMA_HERE).mInExtendedList = ExtendedIndicator;
    element.mWidth = (int32_t) inHyperPeriod / ArrangedElement(index COMMA_HERE).mPeriod ;
  /*
        printf("Element Id = %d & its 1st occurence is : %d and has awidth = %d.\n",
            index +1,ExtendedIndicator+1,element.mWidth); */

    if (ArrangedElement (index COMMA_HERE).mSuccessorId != -1) {
      SuccessorGap = 0;
      for(int32_t i= index; i< ArrangedElement (index COMMA_HERE).mSuccessorId;i++) {
        SuccessorGap += (int32_t) inHyperPeriod /ArrangedElement(i COMMA_HERE).mPeriod;
      }
      ArrangedElement (index COMMA_HERE).mSuccessorId =ExtendedIndicator + SuccessorGap ;
    }

    if (ArrangedElement (index COMMA_HERE).mOtherHeirId != -1) {
      OtherHeirGap = 0;
      for(int32_t i= index; i<ArrangedElement (index COMMA_HERE).mOtherHeirId;i++) {
        OtherHeirGap += (int32_t) inHyperPeriod /ArrangedElement(i COMMA_HERE).mPeriod;
      }
      ArrangedElement (index COMMA_HERE).mOtherHeirId =ExtendedIndicator + OtherHeirGap ;
    }

    ExtendedIndicator += (int32_t) element.mWidth;
    if (ArrangedElement (index COMMA_HERE).mPredecessorId == -1) {
      element.mOffset = ArrangedElement (index COMMA_HERE).mOffset;
     }else {
       int32_t predecessorId = ArrangedElement (index COMMA_HERE).mPredecessorId ;
       element.mOffset = outMTElement (predecessorId COMMA_HERE).mOffset;
     }

    outMTElement.appendObject (element);


    int32_t Repetition =0;

    for (int32_t clicktime = 0; (clicktime) <= ((int32_t) inHyperPeriod - ArrangedElement (index COMMA_HERE).mPeriod) ; clicktime++) {

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

        if (ArrangedElement (index COMMA_HERE).mDeadline == INT32_MAX) {
		     	MTelement.mDeadline = INT32_MAX;
		    }else{
		     	MTelement.mDeadline = clicktime +	ArrangedElement (index COMMA_HERE).mDeadline ;
		    }

//If the element is independent, it's predecessor Id will be -1

        if (ArrangedElement (index COMMA_HERE).mPredecessorId == -1) {
          MTelement.mPredecessorId = -1 ;
        }else{
          interIndex = int32_t (ArrangedElement(index COMMA_HERE).mPredecessorId);

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
      	exElement.appendObject (MTelement) ;
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
DisposeReadyAtRelations(const GenericUniqueArray <cElement> & ArrangedElement,
                        GenericUniqueArray <cActivity> & Activity,
                        GenericUniqueArray <cReadyAtThisInstant> & ReadyAtThisInstant,
                        const uint64_t inHyperPeriod){

GenericUniqueArray <cReadyAtThisInstant>  oReadyAtThisInstant ;

	//--- calculate max size
	int32_t Num_ofIndepStaringInstant=0;
	for ( int32_t index = 0; index < ArrangedElement.count(); index ++) {
   	if ( ArrangedElement (index COMMA_HERE).mPredecessorId < 0){
   	   Num_ofIndepStaringInstant += (int32_t) inHyperPeriod/ArrangedElement (index COMMA_HERE).mPeriod  ;
   	}
  }
  //--- Initilize
  for (int32_t i = 0; i <Num_ofIndepStaringInstant; i ++) {
	  cReadyAtThisInstant readyAtThisInstant;
      readyAtThisInstant.mThisInstant=-1;
      readyAtThisInstant.mActivityIndex=-1;
      readyAtThisInstant.mMarked = false;
    oReadyAtThisInstant.appendObject(readyAtThisInstant);
	}


	int32_t IdInList = 0;

  for ( int32_t index = 0; index < ArrangedElement.count(); index ++) {
   	if ( ArrangedElement (index COMMA_HERE).mPredecessorId < 0){
   	   int32_t NextOccurrence = ArrangedElement (index COMMA_HERE).mOffset ;
   	   while (NextOccurrence <= (ArrangedElement (index COMMA_HERE).mOffset+ ((int32_t)inHyperPeriod) - ArrangedElement (index COMMA_HERE).mPeriod)) {
   	     bool theSameInstantIsFound = false;
   	     int32_t interindex=0;
   	     while( (interindex < Num_ofIndepStaringInstant)
   	     			 &&
   	     			 (!theSameInstantIsFound)
   	     			 &&
   	           (oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant >= 0)){

   	           if (NextOccurrence == oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant){
   	           	 int32_t ActivityIndex = oReadyAtThisInstant (interindex COMMA_HERE).mActivityIndex;
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
   		IdInList += (int32_t) inHyperPeriod/ArrangedElement (index COMMA_HERE).mPeriod ;
   	}
  }

//  printf(" Num_ofIndepStaringInstant : %ld.\n", Num_ofIndepStaringInstant);
  int32_t sizeofStarting = 0;
  int32_t interindex=0;
  while ( (interindex < Num_ofIndepStaringInstant)
           &&
           (oReadyAtThisInstant (interindex COMMA_HERE).mThisInstant != -1) ){
  //  int32_t ActivityIndex = oReadyAtThisInstant (interindex COMMA_HERE).mActivityIndex; // Commented out PM 17/1/2005
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

  int32_t lIndex = 0 ;

   for ( int32_t index = 0; index < interindex ; index ++) {
  	int32_t minStarting = INT32_MAX;
  	for (int32_t i = 0; i < sizeofStarting ; i ++) {
    	if ( !oReadyAtThisInstant (i COMMA_HERE).mMarked){
    		if ( (minStarting=std::min(minStarting,oReadyAtThisInstant (i COMMA_HERE).mThisInstant))==
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
    ReadyAtThisInstant.appendObject(readyAtThisInstant);
  }
/*  for ( int32_t i = 0; i < sizeofStarting ; i ++) {
  	printf("------Activitites at : %ld are:\n",ReadyAtThisInstant (i COMMA_HERE).mThisInstant);
  	int32_t Activ =ReadyAtThisInstant (i COMMA_HERE).mActivityIndex;
    printf("Activity : %ld & ",Activ);
   	while ( (Activ = Activity (Activ COMMA_HERE).mOtherReadyAtThisInst) !=-1){
      printf("Activity : %ld & ",Activ);
   	}
    printf(".\n");
  }*/
}

/*-------------------------------------------------------------------------*/
static void
CreateActivitiesFile (Compiler * inCompiler,
                      const GenericUniqueArray <cActivity> & exElement,
							      	const String & activitiesHTMLFileName){

  const int32_t NumberOfElements = exElement.count () ;
  printf ("Extended activities list is stored in %s file.\n", activitiesHTMLFileName.cString ()) ;
  HTMLFileWrite act_htmlFile (activitiesHTMLFileName,
                              "Extended List Activities",
                              "style.css",
                              "") ;
  if (! act_htmlFile.isOpened ()) {
    String message ;
    message.appendString ("Cannot open '") ;
    message.appendString (activitiesHTMLFileName) ;
    message.appendString ("' file in write mode.") ;
    inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
  }

	act_htmlFile.appendCppTitleComment ("raw Activities map", "title") ;
	act_htmlFile.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	act_htmlFile.appendRawData ("#</td><td>Activity</td><td>Resource</td><td>Priority</td><td>");
  act_htmlFile.appendRawData ("Occurrence</td><td>Offset</td><td>minDur.</td><td>");
  act_htmlFile.appendRawData ("MaxDur.</td><td>Predecessor</td></tr>") ;

 	for (int32_t index = 0; index < NumberOfElements ;index++) {
 	  if ( (exElement (index COMMA_HERE).mOccurrence % exElement (index COMMA_HERE).mEvery) == 0 ){
			act_htmlFile.appendRawData ("<tr class=\"result_line\"><td>") ;
		  act_htmlFile.appendSigned (index) ;
		  act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendString (exElement (index COMMA_HERE).mElementName);
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mResourceId) ;
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mPriority) ;
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mOccurrence/exElement (index COMMA_HERE).mEvery);
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mOffset);
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mMinDuration);
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mMaxDuration);
	    act_htmlFile.appendRawData ("</td><td>") ;
		  act_htmlFile.appendSigned (exElement (index COMMA_HERE).mPredecessorId);
	    act_htmlFile.appendRawData ("</td><td>") ;
		}
	}
	act_htmlFile.appendRawData ("</table>") ;
	act_htmlFile.appendRawData ("<br>");
}

/*----------------------------------------------------------------------------*/

int32_t
BuildExtendedList (Compiler * inCompiler,
                   GenericUniqueArray <cReadyAtThisInstant> & oReadyAtThisInstant,
                   GenericUniqueArray <cElement> & Element,
                   const GenericUniqueArray <cResource> & Resource,
                   GenericUniqueArray <cActivity> & exElement,
                   GenericUniqueArray <cMTElement> & outMTElement,
                   const int32_t Nu_ofTasks, int32_t Nu_ofMessages,
                   bool CreateIntermediateFiles,
                   bool & ioUseBalgorithm,
                   const String & activitiesHTMLFileName) {


  ExtractResourceMinDuration(Element, Resource);
  const uint64_t HyperPeriod = CalculateHyperPeriod (Element) ;
  const int32_t Number_ofResources = Resource.count();
  GenericUniqueArray <cElement> ArrangedElement;
  int32_t NoInterDependenceButUseB = 0;
  ArrangingAccodingPrecedenceRelations (Element, ArrangedElement,
                                        Nu_ofTasks,Nu_ofMessages);

  FindSuccessors (ArrangedElement);
 // const int32_t ActivitiesNumber = CalculateExtendedListLength(Element, HyperPeriod) ; // Commented out PM 17/1/2005
	const int32_t Num_of_Activties =
	      DeployElements (ArrangedElement, exElement, outMTElement, HyperPeriod);

 	gCout.appendSigned (Num_of_Activties) ;
  gCout.appendString (" activities\n") ;
  gCout.flush ();
 	if (CreateIntermediateFiles){
	 	CreateActivitiesFile (inCompiler, exElement, activitiesHTMLFileName);
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
