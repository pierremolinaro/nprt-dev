#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "generic_arraies/TC_UniqueArray.h"
#include "files/C_HTML_FileWrite.h"

#include "ExtendedList.h"

//Declation of MTElement : Message Task Output Element

/*---------------------------------------------------------------------*/
//Extract absolut min=best & max =worst response times from the o/p extended list

void
ExtractWorstBestRT (const TC_UniqueArray <cActivity> & exElement,
          const TC_UniqueArray <cResource> & Resource,
          TC_UniqueArray <cMTElement> & MTElement,
          const TC_UniqueArray <cResponseTime> & inResponseTimeArray,
          bool CreateIntermediateFiles, 
   				const C_String & raw_outputHTMLFileName,
          C_HTML_FileWrite & in_htmlFile) {


 	const sint32 Num_ofResources = Resource.count () ;
  const sint32 Num_ofElements = MTElement.count () ;
  
  sint32 Smallest_bit_time = SINT32_MAX ;
  for (sint32 i=0 ; i < Num_ofResources ; i++ ){
  	Smallest_bit_time = min(Smallest_bit_time, Resource (i COMMA_HERE).mStep);
  }
  
  if(CreateIntermediateFiles){
    printf ("Raw output results are stored in %s file.\n", raw_outputHTMLFileName.cString ()) ;
			C_HTML_FileWrite raw_file (raw_outputHTMLFileName,
                              	  "Activities Outputs",
                              	  "style.css"
                              		COMMA_SAFARI_CREATOR
                                  COMMA_HERE) ;
    fflush (stdout);
     	 
		raw_file.writeCTitleComment ("raw Activities results map", "title") ;
		raw_file.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
		raw_file.outputRawData ("#</td><td>Activity</td><td>Resource</td><td>Occurrence</td><td>");
  	raw_file.outputRawData ("Offset</td><td>BRT</td><td>WRT</td></tr>") ;
		
		
		for (sint32 i=0 ; i<inResponseTimeArray.count () ; i++) {
		  if ( (exElement (i COMMA_HERE).mOccurrence % exElement (i COMMA_HERE).mEvery) == 0 ){
				raw_file.outputRawData ("<tr class=\"result_line\"><td>") ;
		    raw_file << i ;
		    raw_file.outputRawData ("</td><td>") ;
		    raw_file << exElement (i COMMA_HERE).mElementName ;
		    raw_file.outputRawData ("</td><td>") ;
		    raw_file << Resource (exElement (i COMMA_HERE).mResourceId COMMA_HERE).mResourceName ;
	  		raw_file.outputRawData ("</td><td>") ;
		    raw_file << exElement (i COMMA_HERE).mOccurrence/exElement (i COMMA_HERE).mEvery;
		    raw_file.outputRawData ("</td><td>") ;
		    raw_file << exElement (i COMMA_HERE).mOffset ;
		    raw_file.outputRawData ("</td><td>") ;
		    
		    if (inResponseTimeArray ( i COMMA_HERE).mBestResponseTime > SINT32_MAX) {
	      		raw_file.outputRawData ("Error</td><td>") ;
	      }else{
	      		raw_file << inResponseTimeArray ( i COMMA_HERE).mBestResponseTime ;
		  			raw_file.outputRawData ("</td><td>") ;
	      }
			    
			  if (inResponseTimeArray ( i COMMA_HERE).mWorstResponseTime == 0){
	      			raw_file.outputRawData ("Error</td></tr>") ;
	      }else{
	      	raw_file << inResponseTimeArray ( i COMMA_HERE).mWorstResponseTime ;
		  		raw_file.outputRawData ("</td></tr>") ;
	      } 
	    }
	  }
		raw_file.outputRawData ("</table>") ;
	  raw_file.outputRawData ("<br>");
	}
	sint32 DC= 0;     
  for( sint32 index =0; index< Num_ofElements; index++){

//In extended o/p list, elements will be subjected to the extraction process
    
    for(sint32 i= DC ; i< DC+MTElement ( index COMMA_HERE).mWidth ; i++){
//If the is the 1st occurence, maintain parameters

      if (i == (DC+exElement (i COMMA_HERE).mEvery-1)){
      	MTElement ( index COMMA_HERE).mResourceId = exElement (i COMMA_HERE).mResourceId ;
      	strcpy(MTElement ( index COMMA_HERE).mElementName,exElement (i COMMA_HERE).mElementName);
      	MTElement ( index COMMA_HERE).mPriority = exElement (i COMMA_HERE).mPriority ;
      	MTElement ( index COMMA_HERE).mEvery = exElement (i COMMA_HERE).mEvery ;
      //	MTElement ( index COMMA_HERE).mOffset = exElement (i COMMA_HERE).mOffset ;        
      	MTElement ( index COMMA_HERE).mBestResponseTime = 
         	inResponseTimeArray (i COMMA_HERE).mBestResponseTime ;
      	MTElement ( index COMMA_HERE).mWorstResponseTime = 
         	inResponseTimeArray (i COMMA_HERE).mWorstResponseTime ;
      	MTElement ( index COMMA_HERE).mDeadline = exElement (i-(exElement (i COMMA_HERE).mEvery-1) COMMA_HERE).mDeadline;            
      } else if ( (exElement (i COMMA_HERE).mOccurrence % exElement (i COMMA_HERE).mEvery) == 0 ){
              
      	MTElement ( index COMMA_HERE).mBestResponseTime = 
      		min(MTElement ( index COMMA_HERE).mBestResponseTime,
        	 	inResponseTimeArray (i COMMA_HERE).mBestResponseTime - 
            (i-DC-(exElement (i COMMA_HERE).mEvery-1))*MTElement ( index COMMA_HERE).mPeriod);
                  
      	MTElement ( index COMMA_HERE).mWorstResponseTime = 
      		MAX(MTElement ( index COMMA_HERE).mWorstResponseTime,
           	inResponseTimeArray (i COMMA_HERE).mWorstResponseTime - 
           	(i-DC-(exElement (i COMMA_HERE).mEvery-1))*MTElement ( index COMMA_HERE).mPeriod);
                           
      }
    }  
    sint32 resourceIndex = MTElement ( index COMMA_HERE).mResourceId ;
    sint32 resourceStep = Resource (resourceIndex COMMA_HERE).mStep ;
    
    MTElement ( index COMMA_HERE).mPeriod = MTElement ( index COMMA_HERE).mPeriod / resourceStep ;
    if ( MTElement ( index COMMA_HERE).mDeadline !=  SINT32_MAX){ // UINT32_MAX -> SINT32_MAX by PM 17/1/2005
         MTElement ( index COMMA_HERE).mDeadline = MTElement ( index COMMA_HERE).mDeadline / resourceStep ;
    }
    MTElement ( index COMMA_HERE).mBestResponseTime = 
     (MTElement ( index COMMA_HERE).mBestResponseTime  -
      MTElement ( index COMMA_HERE).mOffset)/resourceStep ;
    MTElement ( index COMMA_HERE).mWorstResponseTime = 
     	(sint32) ceil((MTElement ( index COMMA_HERE).mWorstResponseTime -
      MTElement ( index COMMA_HERE).mOffset)*1.0/resourceStep);
    
    DC=DC + sint32 (MTElement(index COMMA_HERE).mWidth) ;
  }

	in_htmlFile.writeCTitleComment ("Final results map", "title") ;
	in_htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	in_htmlFile.outputRawData ("#</td><td>Element</td><td>Resource</td><td>BRT</td><td>");
  in_htmlFile.outputRawData ("WRT</td><td>Period</td><td>Deadline</td><td>&nbsp;</td></tr>") ;
		
	sint32 ElementIndex = 1;
	for(sint32 index = 0; index <Num_ofResources ;index++) {
  	for(sint32 i = 0; i<Num_ofElements; i++){
  		if(index == MTElement ( i COMMA_HERE).mResourceId){
				in_htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
		    in_htmlFile << ElementIndex ;
		    in_htmlFile.outputRawData ("</td><td>") ;
		    in_htmlFile << MTElement ( i COMMA_HERE).mElementName ;
		    in_htmlFile.outputRawData ("</td><td>") ;
		    in_htmlFile << Resource ( index COMMA_HERE).mResourceName ;
	  		in_htmlFile.outputRawData ("</td><td>") ;
		    
		    if (MTElement ( i COMMA_HERE).mBestResponseTime > SINT32_MAX) {
      		in_htmlFile.outputRawData ("Error</td><td>") ;
      	}else{
      		in_htmlFile << MTElement ( i COMMA_HERE).mBestResponseTime ;
	  			in_htmlFile.outputRawData ("</td><td>") ;
      	}
		    
		    if (MTElement ( i COMMA_HERE).mWorstResponseTime == 0){
      			in_htmlFile.outputRawData ("Error</td><td>") ;
      	}else{
      		in_htmlFile << MTElement ( i COMMA_HERE).mWorstResponseTime ;
	  			in_htmlFile.outputRawData ("</td><td>") ;
      	} 
		    
		    in_htmlFile << MTElement ( i COMMA_HERE).mPeriod * MTElement ( i COMMA_HERE).mEvery ;
		    in_htmlFile.outputRawData ("</td><td>") ;
		    
		    if (MTElement ( i COMMA_HERE).mDeadline ==  SINT32_MAX){// UINT32_MAX -> SINT32_MAX by PM 17/1/2005
  				in_htmlFile.outputRawData ("Unkown</td><td>&nbsp;</td></tr>") ;
  			}else{
        	in_htmlFile << MTElement ( i COMMA_HERE).mDeadline ;
	  			in_htmlFile.outputRawData ("</td>") ;
        	
      		if (MTElement (i COMMA_HERE).mWorstResponseTime > 
      			MTElement ( i COMMA_HERE).mDeadline){
      			in_htmlFile.outputRawData ("<td><--- deadline Error!</td></tr>") ;
      		}else{
        		in_htmlFile.outputRawData ("<td>&nbsp;</td></tr>");
        	}
      	}
		    ElementIndex ++;
		  }
		} 
		if (index <(Num_ofResources-1)){
			in_htmlFile.outputRawData ("</td><td></td><td></td><td></td><td>");
  		in_htmlFile.outputRawData ("</td><td></td><td></td></tr>") ;
  	}
	}
	in_htmlFile.outputRawData ("</table>") ;
	in_htmlFile.outputRawData ("<br>");
	in_htmlFile.outputRawData("<tr>Response times are calculated with respect to offsets of independent tasks.</tr>"); 
}

/*---------------------------------------------------------------------*/

