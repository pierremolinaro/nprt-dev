/*--------------------------------------------------------------------------*/

#include <stdlib.h> 
#include <string.h> 
#include "files/C_HTML_FileWrite.h"
#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_Compiler.h"

#include "oa_semantics.h"
#include "CANMessageBounds.h"
#include "ExtendedList-v2.h"
#include "VerifyConditions-v2.h"
#include "activities_core.h"
#include "oa_cli_options.h"

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_5F_canIndependantMessage                                      *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_5F_canIndependantMessage::messageDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_5F_canIndependantMessage::messageDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_canIndependantMessage::getMessageDependanceValue (void) const {
  return 0 ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_5F_canMessageFromMessage                                      *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_5F_canMessageFromMessage::messageDependsOnMessage (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_5F_canMessageFromMessage::messageDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_canMessageFromMessage::getMessageDependanceValue (void) const {
  return mAttribute_mMessageIndex.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_5F_canMessageFromTask                                         *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_5F_canMessageFromTask::messageDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_5F_canMessageFromTask::messageDependsOnTask (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_canMessageFromTask::getMessageDependanceValue (void) const {
  return mAttribute_mTaskIndex.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_5F_independantTask                                            *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_5F_independantTask::taskDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_5F_independantTask::taskDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_independantTask::getTaskDependanceValue (void) const {
  return 0 ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_independantTask::getTaskEveryParameter (void) const {
  return 1 ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_5F_taskDependsFromTask                                        *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_5F_taskDependsFromTask::taskDependsOnTask (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_5F_taskDependsFromTask::taskDependsOnMessage (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_taskDependsFromTask::getTaskDependanceValue (void) const {
  return mAttribute_mTask.uintValue () ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_taskDependsFromTask::getTaskEveryParameter (void) const {
  return mAttribute_mEvery.mAttribute_uint.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     cPtr_C_5F_taskDependsFromMessage                                     *
//                                                                          *
//--------------------------------------------------------------------------*

bool cPtr_C_5F_taskDependsFromMessage::taskDependsOnTask (void) const {
  return false ;
}

//--------------------------------------------------------------------------*

bool cPtr_C_5F_taskDependsFromMessage::taskDependsOnMessage (void) const {
  return true ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_taskDependsFromMessage::getTaskDependanceValue (void) const {
  return mAttribute_mMessage.uintValue () ;
}

//--------------------------------------------------------------------------*

PMUInt32 cPtr_C_5F_taskDependsFromMessage::getTaskEveryParameter (void) const {
  return mAttribute_mEvery.mAttribute_uint.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Build style file                                                     *
//                                                                          *
//--------------------------------------------------------------------------*


static void buildCSSfile (C_Compiler * inCompiler,
                          const C_String & inDirectory) {
//--- Style file name
  const C_String styleFileName = inDirectory + "/style.css" ;
//--- Build file
  bool ok = false ;
  C_TextFileWrite f (styleFileName COMMA_SAFARI_CREATOR, ok) ;
  if (! ok) {
    C_String message ;
    message << "Cannot open '" << styleFileName << "' file in write mode." ;
    inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
  }
  f << "body {\n"
       "  font-family: Helvetica, sans-serif ;\n"
       "	font-size: small ;\n"
       "}\n"
       "\n"
       "h1 {\n"
       "  text-align: center ;\n"
       "}\n"
       "\n"
       "a.header_link {\n"
       "	 border: 1px solid #999999 ;\n"
       "	 padding: 4px ;\n"
       "  background-color: #FFFFCC ;\n"
       "  font-weight: bold ;\n"
       "}\n"
       "\n"
       "a:visited, a:link, a:active{\n"
       " color: blue ;\n"
       " text-decoration: underline ;\n"
       "}\n"
       "\n"
       "a:hover {\n"
       "  color:green ;\n"
       "  background-color: #FF9966 ;\n"
       "  text-decoration: none ;\n"
       "}\n"
       "\n"
       "table.title {\n"
       "  width: 100% ;\n"
       "	border: 1px solid #999999 ;\n"
       "  background-color: yellow ;\n"
       "  font-weight: bold ;\n"
       "	text-align: center ;\n"
       "}\n"
       "\n"
       "table.result {\n"
       "	border: 1px solid #999999 ;\n"
       "}\n"
       "\n"
       "tr.result_line {\n"
       "  background-color: #EEEEEE ;\n"
       "}\n"
       "\n"
       "tr.result_title {\n"
       "  background-color: #CCFFFF ;\n"
       "  font-weight: bold ;\n"
       "}\n"
       "\n"
       "span.error {\n"
       "  font-weight: bold ;\n"
       "  color: red ;\n"
       "}\n"
       "\n"
       "span.warning {\n"
       "  font-weight: bold ;\n"
       "  color: #FF9966 ;\n"
       "}\n"
       "\n"
       "span.success {\n"
       "  font-weight: bold ;\n"
       "  color: green ;\n"
       "}\n"
       "\n"
       "span.list {\n"
       "  display: block ;\n"
       "  line-height: 100% ;\n"
       "}\n"
       "\n"
       "\n" ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Perform scheduling computations                                      *
//                                                                          *
//--------------------------------------------------------------------------*

void
routine_performComputations (GALGAS_M_5F_processor & inProcessorMap,
                             GALGAS_M_5F_network & inNetworkMap,
                             GALGAS_M_5F_messages & inMessagesMap,
                             GALGAS_M_5F_tasks & inTasksMap,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {  
  TC_UniqueArray <cResource> Resource ;
  TC_UniqueArray <cElement> Element ;

  const bool CreateIntermediateFiles = gOption_oa_5F_cli_5F_options_createIntermediateFiles.mValue ;
  const bool useCANmaxLengthOnly = gOption_oa_5F_cli_5F_options_useCANmaxLegth.mValue ;
  bool forceBalgorithm = true ;
  const C_String sourceFile = inCompiler->sourceFileName () ;
  

  const C_String htmlFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + ".html" ;
  const C_String activitiesHTMLFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + "_activities.html" ;
  const C_String raw_outputHTMLFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + "_raw_output.html" ;

  buildCSSfile (inCompiler, sourceFile.stringByDeletingLastPathComponent ()) ;
  bool ok = false ;
  C_HTML_FileWrite htmlFile (htmlFileName,
                             sourceFile.lastPathComponent () + " results",
                             "style.css",
                             ""
                             COMMA_SAFARI_CREATOR,
                             ok) ;
  if (! ok) {
    C_String message ;
    message << "Cannot open '" << htmlFileName << "' file in write mode." ;
    inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
  }
  if(useCANmaxLengthOnly){
  	printf("Elements have their upper duration bounds.\n"); 
  }
  char MessageType = '\0' ;
  bool DependentHasOffset = false ;
	PMSInt32  index ;
//--- Print processors map
  htmlFile.appendCppTitleComment ("Processors map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	htmlFile.outputRawData ("#<th>Name<th>ScaFactor</tr>") ;
	index = 1 ;
	cEnumerator_M_5F_processor processor (inProcessorMap, true) ;
	while (processor.hasCurrentObject ()) {
	  htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
	  htmlFile << cStringWithSigned (index) ;
	  htmlFile.outputRawData ("</td><td>") ;
	  htmlFile << processor.current_lkey (HERE) ;
	  htmlFile.outputRawData ("</td><td>") ;
	  htmlFile << cStringWithUnsigned (processor.current_mStep (HERE).mAttribute_uint.uintValue ()) ;
	  htmlFile.outputRawData ("</td></tr>") ;
	  processor.gotoNextObject () ;
	  index ++ ;
	}
	htmlFile.outputRawData ("</table>") ;
	htmlFile.outputRawData ("<br>");
//--- Build processors map  
  index = 0 ;
  processor.rewind () ;
  while (processor.hasCurrentObject ()) {
    cResource resource ;
    strcpy (resource.mResourceName, processor.current_lkey (HERE).mAttribute_string.stringValue ().cString (HERE));
  	resource.mResourceType= 2; // Processor = 2
   	resource.mStep = (PMSInt32) processor.current_mStep (HERE).mAttribute_uint.uintValue () ;
    
    Resource.addObject (resource) ;
    processor.gotoNextObject () ;
    index ++ ;
  }
  PMSInt32 NumberOfProcessors = index ;
	
  const char * kNetworkTypes [] = {"VAN","CAN"} ;
	cEnumerator_M_5F_network network (inNetworkMap, true) ;
//--- Print network map
  htmlFile.appendCppTitleComment ("Networks map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
  htmlFile.outputRawData ("#<th>Name<th>Type<th>ScaFactor</tr>") ;
  index = 1 ;
  while (network.hasCurrentObject ()) {
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << cStringWithSigned (index) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << network.current_lkey (HERE) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << kNetworkTypes [network.current_mCANnetwork (HERE).boolValue ()] ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (network.current_mScalingFactor (HERE).mAttribute_uint.uintValue ()) ;
    htmlFile.outputRawData ("</td></tr>") ;
    network.gotoNextObject () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");
//--- Build networks map  
  PMSInt32 min_NetworkStep = PMSINT32_MAX ;
  index = 0 ;
  network.rewind ();
  while (network.hasCurrentObject ()) {
    cResource resource ;
    strcpy(resource.mResourceName,network.current_lkey (HERE).mAttribute_string.stringValue ().cString (HERE));
  	resource.mResourceType= network.current_mCANnetwork (HERE).boolValue ();
    resource.mStep = (PMSInt32) network.current_mScalingFactor (HERE).mAttribute_uint.uintValue () ;		
 		min_NetworkStep = min (min_NetworkStep, resource.mStep);
 	 	
 	 	Resource.addObject (resource) ;
    network.gotoNextObject () ;
    index ++ ;
  }
  
//--- Build tasks map  
  cEnumerator_M_5F_tasks task (inTasksMap, true) ;
  index = 0 ;
  while (task.hasCurrentObject ()) {
    cElement element ;
    strcpy(element.mElementName,task.current_lkey (HERE).mAttribute_string.stringValue ().cString (HERE));   
    element.mElementType = 'T';    
    element.mId_inList =index;
  	element.mResourceId = (PMSInt32) task.current_mProcessor (HERE).uintValue ();
    element.mPriority = (PMSInt32) task.current_mPriority (HERE).mAttribute_uint.uintValue ();
// §    element.mEvery = 1 ;
    PMSInt32 Sca = Resource (element.mResourceId COMMA_HERE).mStep ;
//    printf (" Sca : %ld \n",Sca);
    element.mEvery = (PMSInt32) task.current_mTaskKind (HERE).ptr ()->getTaskEveryParameter () ;
  	element.mOffset = Sca*(PMSInt32) task.current_mOffset (HERE).mAttribute_uint.uintValue ();  
    element.mMaxDuration = Sca*(PMSInt32) task.current_mDurationMax (HERE).mAttribute_uint.uintValue (); 
    element.mMinDuration = useCANmaxLengthOnly
                          ? element.mMaxDuration :(Sca*(PMSInt32)  task.current_mDurationMin (HERE).mAttribute_uint.uintValue ());
        
    element.mDeadline = (PMSInt32) task.current_mDeadline (HERE).mAttribute_uint.uintValue ();
    if ( element.mDeadline !=  PMSINT32_MAX){ // PMUINT32_MAX -> PMSINT32_MAX by PM, 17/1/2005
    	 element.mDeadline = Sca*element.mDeadline;
    }  
 //................................................   
    if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnTask ()) {
    	PMSInt32 elementIndex = (PMSInt32) task.current_mTaskKind (HERE).ptr ()->getTaskDependanceValue ();
    	element.mEveryMultiple = 
    		 (PMSInt32) task.current_mTaskKind (HERE).ptr ()->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple; 
   		element.mPeriod = Sca*(PMSInt32) task.current_mPeriod (HERE).mAttribute_uint.uintValue ();
    } else if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnMessage ()){
    
    }else{
    	element.mEveryMultiple = (PMSInt32) task.current_mTaskKind (HERE).ptr ()->getTaskEveryParameter () ;
    	element.mPeriod = Sca*(PMSInt32) task.current_mPeriod (HERE).mAttribute_uint.uintValue ();
    }
 //................................................
  	if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T'; 
      element.mPredecessorId = 
      PMSInt32 (task.current_mTaskKind (HERE).ptr ()->getTaskDependanceValue ());
    }else if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnMessage ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'M'; 
      element.mPredecessorId = 
      PMSInt32 (task.current_mTaskKind (HERE).ptr ()->getTaskDependanceValue ()) ;
    }else{ 
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.addObject (element) ;
		task.gotoNextObject () ;
    index ++ ;
  }
  PMSInt32 NumberOfTasks = index;
	
  const char * kMessageClasses [] = {"standard", "extended", "  VAN   "} ;
  cEnumerator_M_5F_messages message (inMessagesMap, true) ;

//--- Build messages map
  index = 0 ;
  message.rewind () ;
  while (message.hasCurrentObject ()) {
    cElement element ;
    strcpy(element.mElementName,message.current_lkey (HERE).mAttribute_string.stringValue ().cString (HERE));
  	element.mElementType = 'M';
    element.mId_inList = index;
  	element.mResourceId = NumberOfProcessors + 
  		(PMSInt32) message.current_mNetworkIndex (HERE).uintValue ();
  	element.mPriority = (PMSInt32) message.current_mPriority (HERE).mAttribute_uint.uintValue ();
  	element.mEvery = 1 ;
  	PMSInt32 ScalingFactor = 
					 Resource (element.mResourceId COMMA_HERE).mStep;
	//  printf (" Sca : %ld \n",ScalingFactor);
	  element.mOffset = ScalingFactor*(PMSInt32) message.current_mOffset (HERE).mAttribute_uint.uintValue (); 
  	if ( Resource (element.mResourceId COMMA_HERE).mResourceType == 1 ){ //CAN = 1
    	if (strstr(kMessageClasses [message.current_mClass (HERE).mAttribute_uint.uintValue ()],"standard") != NULL){ 
    		MessageType = 'S';
    	}else if (strstr(kMessageClasses [message.current_mClass (HERE).mAttribute_uint.uintValue ()],
      					"extended") != NULL){ 
      	MessageType = 'X' ;
      }else{ 
      	co << "ERROR : message #"
      	   << cStringWithSigned (index)
      	   << " is neither standard (S) nor extended (X) message!\n" ;
      }
      
      element.mMaxDuration = ScalingFactor* maxCANMessageTime(MessageType,
      											 (PMUInt32) element.mMinDuration,
      											 message.current_mBytesCount (HERE).mAttribute_uint.uintValue ());
  
      element.mMinDuration = useCANmaxLengthOnly
        ? element.mMaxDuration
        : (ScalingFactor * minCANMessageTime(MessageType,
                            message.current_mPriority (HERE).mAttribute_uint.uintValue (),
                            message.current_mBytesCount (HERE).mAttribute_uint.uintValue ()));
                            
  	}else if (Resource (element.mResourceId COMMA_HERE).mResourceType == 0 ){ //VAN = 0
    	
    	element.mMinDuration= ScalingFactor *(64+10* (PMSInt32) message.current_mBytesCount (HERE).mAttribute_uint.uintValue ()) ;

    	element.mMaxDuration= ScalingFactor* element.mMinDuration;
  	}else{ 
       printf ("ERROR : bus is neither CAN nor VAN!\n") ;
      fflush (stdout);  
		}
		
    element.mDeadline =  (PMSInt32) message.current_mDeadline (HERE).mAttribute_uint.uintValue ();
    if ( element.mDeadline !=  PMSINT32_MAX){ // PMUINT32_MAX -> PMSINT32_MAX by PM, 17/1/2005
    	 element.mDeadline = ScalingFactor *element.mDeadline;
    }  
 //...........................................................................
    PMSInt32 elementIndex ;
   if (message.current_mMessageKind (HERE).ptr ()->messageDependsOnTask ()) {
   	 elementIndex = (PMSInt32) message.current_mMessageKind (HERE).ptr ()->getMessageDependanceValue ();
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple ;  
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ; 
   }else if (message.current_mMessageKind (HERE).ptr ()->messageDependsOnMessage ()) {
     elementIndex = (PMSInt32) message.current_mMessageKind (HERE).ptr ()->getMessageDependanceValue () + NumberOfTasks ;
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple; 
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ;
   } else{
   	 element.mEveryMultiple = 1;
   	  element.mPeriod = ScalingFactor * (PMSInt32) message.current_mPeriod (HERE).mAttribute_uint.uintValue ();
   }
 //.................................................................................   
  	if (message.current_mMessageKind (HERE).ptr ()->messageDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T'; 
      element.mPredecessorId = 
         (PMSInt32) message.current_mMessageKind (HERE).ptr ()->getMessageDependanceValue ();
    }else if (message.current_mMessageKind (HERE).ptr ()->messageDependsOnMessage ()) {
    	element.mIsIndependant=false ;
    	element.mPredecessorType = 'M'; 
      element.mPredecessorId = (PMSInt32) message.current_mMessageKind (HERE).ptr ()->getMessageDependanceValue () ;
    }else{ 
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.addObject (element) ;
	  message.gotoNextObject () ;
    index ++ ;
  }
  PMSInt32 NumberOfMessages = index;  
//*----------------------------------------------------------------------/  
	//--- Print task map
  
	htmlFile.appendCppTitleComment ("Tasks map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.outputRawData ("#<th>Name<th>Processor<th>Priority<th>");
  htmlFile.outputRawData ("Offset<th>Min<th>Max<th>Period<th>") ;
  htmlFile.outputRawData ("Deadline<th>Dependence<th>Every</tr>") ;
  index = 1 ;
  task.rewind () ;
  while (task.hasCurrentObject ()) {
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << cStringWithSigned (index) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << task.current_lkey (HERE).mAttribute_string.stringValue ().cString (HERE) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task.current_mProcessor (HERE).uintValue ()+1) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task.current_mPriority (HERE).mAttribute_uint.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task.current_mOffset (HERE).mAttribute_uint.uintValue ());
    htmlFile.outputRawData ("</td><td>") ;
    if (useCANmaxLengthOnly){
      htmlFile << cStringWithUnsigned (task.current_mDurationMax (HERE).mAttribute_uint.uintValue ()) ;
    }else {
      htmlFile << cStringWithUnsigned (task.current_mDurationMin (HERE).mAttribute_uint.uintValue ()) ;
    }
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (task.current_mDurationMax (HERE).mAttribute_uint.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
//....................................................................   
    if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnMessage ()) {
    	PMSInt32 elementIndex = (PMSInt32) task.current_mTaskKind (HERE).ptr ()->getTaskDependanceValue () + NumberOfTasks ;
    	Element (index-1 COMMA_HERE).mEveryMultiple = 
    		 (PMSInt32) task.current_mTaskKind (HERE).ptr ()->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple; 
    	Element (index-1 COMMA_HERE).mPeriod = Element (elementIndex COMMA_HERE).mPeriod  ;
    }
 //...................................................................
    PMSInt32 resourceId = (PMSInt32) task.current_mProcessor (HERE).uintValue ();
    PMSInt32 Scal = Resource (resourceId COMMA_HERE).mStep ;

    htmlFile << cStringWithSigned (Element (index-1 COMMA_HERE).mEveryMultiple * Element (index-1 COMMA_HERE).mPeriod /Scal) ;
    htmlFile.outputRawData ("</td><td>") ;
    if (task.current_mDeadline (HERE).mAttribute_uint.uintValue () == PMUINT32_MAX){
    	htmlFile.outputRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile << cStringWithUnsigned (task.current_mDeadline (HERE).mAttribute_uint.uintValue ()) ;
    	htmlFile.outputRawData ("</td><td>") ;
    }
    if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnTask ()) {
      htmlFile.outputRawData ("task #") ;
      htmlFile << cStringWithUnsigned (task.current_mTaskKind (HERE).ptr ()->getTaskDependanceValue ()+1) ;
    }else if (task.current_mTaskKind (HERE).ptr ()->taskDependsOnMessage ()) {
      htmlFile.outputRawData ("message #") ;
      htmlFile << cStringWithUnsigned (task.current_mTaskKind (HERE).ptr ()->getTaskDependanceValue ()+1) ;
    }else{
    	htmlFile.outputRawData (" ---") ;
    }
     htmlFile.outputRawData ("</td><td>") ;
     htmlFile << cStringWithUnsigned (task.current_mTaskKind (HERE).ptr ()->getTaskEveryParameter ()) ;
      
    htmlFile.outputRawData ("</td></tr>") ;
    task.gotoNextObject () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");

//--- Print messages map
  htmlFile.appendCppTitleComment ("Messages map", "title") ;
  htmlFile.outputRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.outputRawData ("#<th>Name<th>Network<th>Type<th>Priority<th>Byte");
  htmlFile.outputRawData ("<th> min--max ") ;
  htmlFile.outputRawData ("<th>Offset<th>Period<th>Deadline<th>Dependence</tr>") ;
  index = 1 ;
  message.rewind () ;
  while (message.hasCurrentObject ()) {
    htmlFile.outputRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile << cStringWithSigned (index) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << message.current_lkey (HERE).mAttribute_string.stringValue ().cString (HERE) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (message.current_mNetworkIndex (HERE).uintValue () +1) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << kMessageClasses [message.current_mClass (HERE).mAttribute_uint.uintValue ()];
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (message.current_mPriority (HERE).mAttribute_uint.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithUnsigned (message.current_mBytesCount (HERE).mAttribute_uint.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    
    PMSInt32 resourceId =  NumberOfProcessors + (PMSInt32) message.current_mNetworkIndex (HERE).uintValue ();
    PMSInt32 Scal = Resource (resourceId COMMA_HERE).mStep ;
    
    if ( (strstr(kMessageClasses [message.current_mClass (HERE).mAttribute_uint.uintValue ()],"standard") != NULL)
    		|| 
    		(strstr(kMessageClasses [message.current_mClass (HERE).mAttribute_uint.uintValue ()],"extended") != NULL)
    		){ 
      		if (useCANmaxLengthOnly){
      		  htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal) ;
      		}else{
      			htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMinDuration / Scal);
      			htmlFile.outputRawData ("--");
      			htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal) ;
      		}
    }else{
      htmlFile << cStringWithSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration /Scal) ;
    }
    htmlFile.outputRawData ("</td><td>");    
    htmlFile << cStringWithUnsigned (message.current_mOffset (HERE).mAttribute_uint.uintValue ()) ;
    htmlFile.outputRawData ("</td><td>") ;
    htmlFile << cStringWithSigned (Element (index-1 + NumberOfTasks  COMMA_HERE).mEveryMultiple *  
                                   Element (index-1 + NumberOfTasks  COMMA_HERE).mPeriod /Scal);
    htmlFile.outputRawData ("</td><td>") ; 
    if (message.current_mDeadline (HERE).mAttribute_uint.uintValue () == PMUINT32_MAX){
    	htmlFile.outputRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile << cStringWithUnsigned (message.current_mDeadline (HERE).mAttribute_uint.uintValue ()) ;
    	htmlFile.outputRawData ("</td><td>") ;
    }
   	if (message.current_mMessageKind (HERE).ptr ()->messageDependsOnTask ()) {
    	htmlFile.outputRawData ("task #") ;
     	htmlFile << cStringWithUnsigned (message.current_mMessageKind (HERE).ptr ()->getMessageDependanceValue ()+1) ;
    }else if (message.current_mMessageKind (HERE).ptr ()->messageDependsOnMessage ()) {
    	htmlFile.outputRawData ("message # ") ;
 	   	htmlFile << cStringWithUnsigned (message.current_mMessageKind (HERE).ptr ()->getMessageDependanceValue ()+1) ;
    }else{
    	htmlFile.outputRawData (" ---") ;
    }
    
    htmlFile.outputRawData ("</td></tr>") ;
    message.gotoNextObject () ;
    index ++ ;
  }
  htmlFile.outputRawData ("</table>") ;
  htmlFile.outputRawData ("<br>");
  htmlFile.flush () ;
//*----------------------------------------------------------------------/  
  
// Verification of  necessary scheduling conditions 

  if (NecessaryConditions_OK (inCompiler, Element, Resource) ){
  
  	TC_UniqueArray <cActivity> exElement ;
  	TC_UniqueArray <cResponseTime> responseTimeArray ;
  	TC_UniqueArray <cMTElement> MTElement ;
  	TC_UniqueArray <cReadyAtThisInstant>  ReadyAtThisInstant;
   
   PMSInt32 NoInterButUseB = 
         BuildExtendedList (inCompiler,
                            ReadyAtThisInstant, Element, 
             Resource, exElement, 
             MTElement,NumberOfTasks,
             NumberOfMessages,CreateIntermediateFiles,
             forceBalgorithm,
             activitiesHTMLFileName);
 	
 		// ScheduleExtendedList (exElement, responseTimeArray) ;    
    if (forceBalgorithm) {
  //    printf ("Algorithm \"B\" is used.\n") ; fflush (stdout) ;
      scheduleActivities (NoInterButUseB, DependentHasOffset, 
                          ReadyAtThisInstant, exElement, 
                          Resource, responseTimeArray) ;
    }else{
      printf ("Algorithm \"A\" is used.\n") ; fflush (stdout) ;
      independantResourcesScheduleActivities (exElement, responseTimeArray) ;
    }
		//Extract absolute bornes (min & max)
  	ExtractWorstBestRT (inCompiler,
                        exElement, Resource, MTElement, 
                        responseTimeArray, CreateIntermediateFiles, 
                        raw_outputHTMLFileName, htmlFile);
    printf ("Results are stored in %s file.\n", htmlFileName.cString (HERE));
    
 	}else{
    printf ("System map is stored in %s file.\n", htmlFileName.cString (HERE));
 	}
 	fflush (stdout);
}

/*--------------------------------------------------------------------------*/
