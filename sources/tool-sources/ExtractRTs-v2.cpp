#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>

#include "GenericUniqueArray.h"
#include "HTMLFileWrite.h"
#include "Compiler.h"

#include "ExtendedList-v2.h"

//Declation of MTElement : Message Task Output Element

/*---------------------------------------------------------------------*/
//Extract absolut min=best & max =worst response times from the o/p extended list

void
ExtractWorstBestRT (Compiler * inCompiler,
                    const GenericUniqueArray <cActivity> & exElement,
          const GenericUniqueArray <cResource> & Resource,
          GenericUniqueArray <cMTElement> & MTElement,
          const GenericUniqueArray <cResponseTime> & inResponseTimeArray,
          bool CreateIntermediateFiles,
   				const String & raw_outputHTMLFileName,
          HTMLFileWrite & in_htmlFile) {


 	const int32_t Num_ofResources = Resource.count () ;
  const int32_t Num_ofElements = MTElement.count () ;

  int32_t Smallest_bit_time = INT32_MAX ;
  for (int32_t i=0 ; i < Num_ofResources ; i++ ){
  	Smallest_bit_time = std::min(Smallest_bit_time, Resource (i COMMA_HERE).mStep);
  }

  if(CreateIntermediateFiles){
    printf ("Raw output results are stored in %s file.\n", raw_outputHTMLFileName.cString ()) ;
    HTMLFileWrite raw_file (raw_outputHTMLFileName,
                               "Activities Outputs",
                               "style.css",
                               "") ;
    if (! raw_file.isOpened ()) {
      String message ;
      message.appendString ("Cannot open '") ;
      message.appendString (raw_outputHTMLFileName) ;
      message.appendString ("' file in write mode.") ;
      inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
    }
    fflush (stdout);

		raw_file.appendCppTitleComment ("raw Activities results map", "title") ;
		raw_file.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
		raw_file.appendRawData ("#</td><td>Activity</td><td>Resource</td><td>Occurrence</td><td>");
  	raw_file.appendRawData ("Offset</td><td>BRT</td><td>WRT</td></tr>") ;


		for (int32_t i=0 ; i<inResponseTimeArray.count () ; i++) {
		  if ( (exElement (i COMMA_HERE).mOccurrence % exElement (i COMMA_HERE).mEvery) == 0 ){
				raw_file.appendRawData ("<tr class=\"result_line\"><td>") ;
		    raw_file.appendSigned (i) ;
		    raw_file.appendRawData ("</td><td>") ;
		    raw_file.appendString (exElement (i COMMA_HERE).mElementName) ;
		    raw_file.appendRawData ("</td><td>") ;
		    raw_file.appendString (Resource (exElement (i COMMA_HERE).mResourceId COMMA_HERE).mResourceName) ;
	  		raw_file.appendRawData ("</td><td>") ;
		    raw_file.appendSigned (exElement (i COMMA_HERE).mOccurrence/exElement (i COMMA_HERE).mEvery);
		    raw_file.appendRawData ("</td><td>") ;
		    raw_file.appendSigned (exElement (i COMMA_HERE).mOffset) ;
		    raw_file.appendRawData ("</td><td>") ;

		    if (inResponseTimeArray (i COMMA_HERE).mBestResponseTime == INT32_MAX) {
	      		raw_file.appendRawData ("Error</td><td>") ;
	      }else{
	      		raw_file.appendSigned (inResponseTimeArray ( i COMMA_HERE).mBestResponseTime) ;
		  			raw_file.appendRawData ("</td><td>") ;
	      }

			  if (inResponseTimeArray ( i COMMA_HERE).mWorstResponseTime == 0){
	      			raw_file.appendRawData ("Error</td></tr>") ;
	      }else{
	      	raw_file.appendSigned (inResponseTimeArray ( i COMMA_HERE).mWorstResponseTime) ;
		  		raw_file.appendRawData ("</td></tr>") ;
	      }
	    }
	  }
		raw_file.appendRawData ("</table>") ;
	  raw_file.appendRawData ("<br>");
	}
	int32_t DC= 0;
  for( int32_t index =0; index< Num_ofElements; index++){

//In extended o/p list, elements will be subjected to the extraction process

    for(int32_t i= DC ; i< DC+MTElement ( index COMMA_HERE).mWidth ; i++){
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
      		std::min(MTElement ( index COMMA_HERE).mBestResponseTime,
        	 	inResponseTimeArray (i COMMA_HERE).mBestResponseTime -
            (i-DC-(exElement (i COMMA_HERE).mEvery-1))*MTElement ( index COMMA_HERE).mPeriod);

      	MTElement ( index COMMA_HERE).mWorstResponseTime =
      		std::max (MTElement ( index COMMA_HERE).mWorstResponseTime,
           	inResponseTimeArray (i COMMA_HERE).mWorstResponseTime -
           	(i-DC-(exElement (i COMMA_HERE).mEvery-1))*MTElement ( index COMMA_HERE).mPeriod);

      }
    }
    int32_t resourceIndex = MTElement ( index COMMA_HERE).mResourceId ;
    int32_t resourceStep = Resource (resourceIndex COMMA_HERE).mStep ;

    MTElement ( index COMMA_HERE).mPeriod = MTElement ( index COMMA_HERE).mPeriod / resourceStep ;
    if ( MTElement ( index COMMA_HERE).mDeadline !=  INT32_MAX){ // PMUINT32_MAX -> INT32_MAX by PM 17/1/2005
         MTElement ( index COMMA_HERE).mDeadline = MTElement ( index COMMA_HERE).mDeadline / resourceStep ;
    }
    MTElement ( index COMMA_HERE).mBestResponseTime =
     (MTElement ( index COMMA_HERE).mBestResponseTime  -
      MTElement ( index COMMA_HERE).mOffset)/resourceStep ;
    MTElement ( index COMMA_HERE).mWorstResponseTime =
     	(int32_t) ceil((MTElement ( index COMMA_HERE).mWorstResponseTime -
      MTElement ( index COMMA_HERE).mOffset)*1.0/resourceStep);

    DC=DC + int32_t (MTElement(index COMMA_HERE).mWidth) ;
  }

	in_htmlFile.appendCppTitleComment ("Final results map", "title") ;
	in_htmlFile.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	in_htmlFile.appendRawData ("#</td><td>Element</td><td>Resource</td><td>BRT</td><td>");
  in_htmlFile.appendRawData ("WRT</td><td>Period</td><td>Deadline</td><td>&nbsp;</td></tr>") ;

	int32_t ElementIndex = 1;
	for(int32_t index = 0; index <Num_ofResources ;index++) {
  	for(int32_t i = 0; i<Num_ofElements; i++){
  		if(index == MTElement ( i COMMA_HERE).mResourceId){
				in_htmlFile.appendRawData ("<tr class=\"result_line\"><td>") ;
		    in_htmlFile.appendSigned (ElementIndex) ;
		    in_htmlFile.appendRawData ("</td><td>") ;
		    in_htmlFile.appendString (MTElement ( i COMMA_HERE).mElementName) ;
		    in_htmlFile.appendRawData ("</td><td>") ;
		    in_htmlFile.appendString (Resource ( index COMMA_HERE).mResourceName) ;
	  		in_htmlFile.appendRawData ("</td><td>") ;

		    if (MTElement ( i COMMA_HERE).mBestResponseTime == INT32_MAX) {
      		in_htmlFile.appendRawData ("Error</td><td>") ;
      	}else{
      		in_htmlFile.appendSigned (MTElement ( i COMMA_HERE).mBestResponseTime) ;
	  			in_htmlFile.appendRawData ("</td><td>") ;
      	}

		    if (MTElement ( i COMMA_HERE).mWorstResponseTime == 0){
      			in_htmlFile.appendRawData ("Error</td><td>") ;
      	}else{
      		in_htmlFile.appendSigned (MTElement ( i COMMA_HERE).mWorstResponseTime) ;
	  			in_htmlFile.appendRawData ("</td><td>") ;
      	}

		    in_htmlFile.appendSigned (MTElement ( i COMMA_HERE).mPeriod * MTElement ( i COMMA_HERE).mEvery) ;
		    in_htmlFile.appendRawData ("</td><td>") ;

		    if (MTElement ( i COMMA_HERE).mDeadline ==  INT32_MAX){// PMUINT32_MAX -> INT32_MAX by PM 17/1/2005
  				in_htmlFile.appendRawData ("Unkown</td><td>&nbsp;</td></tr>") ;
  			}else{
        	in_htmlFile.appendSigned (MTElement ( i COMMA_HERE).mDeadline) ;
	  			in_htmlFile.appendRawData ("</td>") ;

      		if (MTElement (i COMMA_HERE).mWorstResponseTime >
      			MTElement ( i COMMA_HERE).mDeadline){
      			in_htmlFile.appendRawData ("<td><--- deadline Error!</td></tr>") ;
      		}else{
        		in_htmlFile.appendRawData ("<td>&nbsp;</td></tr>");
        	}
      	}
		    ElementIndex ++;
		  }
		}
		if (index <(Num_ofResources-1)){
			in_htmlFile.appendRawData ("</td><td></td><td></td><td></td><td>");
  		in_htmlFile.appendRawData ("</td><td></td><td></td></tr>") ;
  	}
	}
	in_htmlFile.appendRawData ("</table>") ;
	in_htmlFile.appendRawData ("<br>");
	in_htmlFile.appendRawData("<tr>Response times are calculated with respect to offsets of independent tasks.</tr>");
}

/*---------------------------------------------------------------------*/

