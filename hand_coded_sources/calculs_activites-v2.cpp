/*--------------------------------------------------------------------------*/

#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "HTMLFileWrite.h"
#include "MF_MemoryControl.h"
#include "Compiler.h"

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

uint32_t cPtr_C_5F_canIndependantMessage::getMessageDependanceValue (void) const {
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

uint32_t cPtr_C_5F_canMessageFromMessage::getMessageDependanceValue (void) const {
  return mProperty_mMessageIndex.uintValue () ;
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

uint32_t cPtr_C_5F_canMessageFromTask::getMessageDependanceValue (void) const {
  return mProperty_mTaskIndex.uintValue () ;
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

uint32_t cPtr_C_5F_independantTask::getTaskDependanceValue (void) const {
  return 0 ;
}

//--------------------------------------------------------------------------*

uint32_t cPtr_C_5F_independantTask::getTaskEveryParameter (void) const {
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

uint32_t cPtr_C_5F_taskDependsFromTask::getTaskDependanceValue (void) const {
  return mProperty_mTask.uintValue () ;
}

//--------------------------------------------------------------------------*

uint32_t cPtr_C_5F_taskDependsFromTask::getTaskEveryParameter (void) const {
  return mProperty_mEvery.mProperty_uint.uintValue () ;
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

uint32_t cPtr_C_5F_taskDependsFromMessage::getTaskDependanceValue (void) const {
  return mProperty_mMessage.uintValue () ;
}

//--------------------------------------------------------------------------*

uint32_t cPtr_C_5F_taskDependsFromMessage::getTaskEveryParameter (void) const {
  return mProperty_mEvery.mProperty_uint.uintValue () ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Build style file                                                     *
//                                                                          *
//--------------------------------------------------------------------------*


static void buildCSSfile (Compiler * inCompiler,
                          const String & inDirectory) {
//--- Style file name
  const String styleFileName = inDirectory + "/style.css" ;
//--- Build file
  TextFileWrite f (styleFileName) ;
  if (! f.isOpened ()) {
    String message ;
    message.appendString ("Cannot open '") ;
    message.appendString (styleFileName) ;
    message.appendString ("' file in write mode.") ;
    inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
  }
  f.appendString ("body {\n"
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
       "\n") ;
}

//--------------------------------------------------------------------------*
//                                                                          *
//     Perform scheduling computations                                      *
//                                                                          *
//--------------------------------------------------------------------------*

void
routine_performComputations_26__26__26__26_ (GALGAS_M_5F_processor & inProcessorMap,
                             GALGAS_M_5F_network & inNetworkMap,
                             GALGAS_M_5F_messages & inMessagesMap,
                             GALGAS_M_5F_tasks & inTasksMap,
                             Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  TC_UniqueArray <cResource> Resource ;
  TC_UniqueArray <cElement> Element ;

  const bool CreateIntermediateFiles = gOption_oa_5F_cli_5F_options_createIntermediateFiles.mValue ;
  const bool useCANmaxLengthOnly = gOption_oa_5F_cli_5F_options_useCANmaxLegth.mValue ;
  bool forceBalgorithm = false ;
  const String sourceFile = inCompiler->sourceFilePath () ;


  const String htmlFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + ".html" ;
  const String activitiesHTMLFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + "_activities.html" ;
  const String raw_outputHTMLFileName = sourceFile.stringByDeletingLastPathComponent () + "/" + sourceFile.lastPathComponentWithoutExtension () + "_raw_output.html" ;

  buildCSSfile (inCompiler, sourceFile.stringByDeletingLastPathComponent ()) ;

  HTMLFileWrite htmlFile (htmlFileName,
                             sourceFile.lastPathComponent () + " results",
                             "style.css",
                             "") ;
  if (! htmlFile.isOpened ()) {
    String message ;
    message.appendString ("Cannot open '") ;
    message.appendString (htmlFileName) ;
    message.appendString ("' file in write mode.") ;
    inCompiler->onTheFlySemanticError (message COMMA_HERE) ;
  }
  if(useCANmaxLengthOnly){
  	printf("Elements have their upper duration bounds.\n");
  }
  char MessageType = '\0' ;
  bool DependentHasOffset = false ;
	int32_t  index ;
//--- Print processors map
  htmlFile.appendCppTitleComment ("Processors map", "title") ;
  htmlFile.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
	htmlFile.appendRawData ("#<th>Name<th>ScaFactor</tr>") ;
	index = 1 ;
	cEnumerator_M_5F_processor processor (inProcessorMap, kENUMERATION_UP) ;
	while (processor.hasCurrentObject ()) {
	  htmlFile.appendRawData ("<tr class=\"result_line\"><td>") ;
	  htmlFile.appendSigned (index) ;
	  htmlFile.appendRawData ("</td><td>") ;
	  htmlFile.appendString (processor.current_lkey (HERE).mProperty_string.stringValue()) ;
	  htmlFile.appendRawData ("</td><td>") ;
	  htmlFile.appendUnsigned (processor.current_mStep (HERE).mProperty_uint.uintValue ()) ;
	  htmlFile.appendRawData ("</td></tr>") ;
	  processor.gotoNextObject () ;
	  index ++ ;
	}
	htmlFile.appendRawData ("</table>") ;
	htmlFile.appendRawData ("<br>");
//--- Build processors map
  index = 0 ;
  processor.rewind () ;
  while (processor.hasCurrentObject ()) {
    cResource resource ;
    strcpy (resource.mResourceName, processor.current_lkey (HERE).mProperty_string.stringValue ().cString ());
  	resource.mResourceType= 2; // Processor = 2
   	resource.mStep = (int32_t) processor.current_mStep (HERE).mProperty_uint.uintValue () ;

    Resource.appendObject (resource) ;
    processor.gotoNextObject () ;
    index ++ ;
  }
  int32_t NumberOfProcessors = index ;

  const char * kNetworkTypes [] = {"VAN","CAN"} ;
	cEnumerator_M_5F_network network (inNetworkMap, kENUMERATION_UP) ;
//--- Print network map
  htmlFile.appendCppTitleComment ("Networks map", "title") ;
  htmlFile.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>");
  htmlFile.appendRawData ("#<th>Name<th>Type<th>ScaFactor</tr>") ;
  index = 1 ;
  while (network.hasCurrentObject ()) {
    htmlFile.appendRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile.appendSigned (index) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendString (network.current_lkey (HERE).mProperty_string.stringValue()) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendString (kNetworkTypes [network.current_mCANnetwork (HERE).boolValue ()]) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (network.current_mScalingFactor (HERE).mProperty_uint.uintValue ()) ;
    htmlFile.appendRawData ("</td></tr>") ;
    network.gotoNextObject () ;
    index ++ ;
  }
  htmlFile.appendRawData ("</table>") ;
  htmlFile.appendRawData ("<br>");
//--- Build networks map
  int32_t min_NetworkStep = INT32_MAX ;
  index = 0 ;
  network.rewind ();
  while (network.hasCurrentObject ()) {
    cResource resource ;
    strcpy(resource.mResourceName,network.current_lkey (HERE).mProperty_string.stringValue ().cString ());
  	resource.mResourceType= network.current_mCANnetwork (HERE).boolValue ();
    resource.mStep = (int32_t) network.current_mScalingFactor (HERE).mProperty_uint.uintValue () ;
 		min_NetworkStep = std::min (min_NetworkStep, resource.mStep);

 	 	Resource.appendObject (resource) ;
    network.gotoNextObject () ;
    index ++ ;
  }

//--- Build tasks map
  cEnumerator_M_5F_tasks task (inTasksMap, kENUMERATION_UP) ;
  index = 0 ;
  while (task.hasCurrentObject ()) {
    cElement element ;
    strcpy(element.mElementName,task.current_lkey (HERE).mProperty_string.stringValue ().cString ());
    element.mElementType = 'T';
    element.mId_inList =index;
  	element.mResourceId = (int32_t) task.current_mProcessor (HERE).uintValue ();
    element.mPriority = (int32_t) task.current_mPriority (HERE).mProperty_uint.uintValue ();
// §    element.mEvery = 1 ;
    int32_t Sca = Resource (element.mResourceId COMMA_HERE).mStep ;
//    printf (" Sca : %ld \n",Sca);
    auto p = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    element.mEvery = (int32_t) p->getTaskEveryParameter () ;
  	element.mOffset = Sca*(int32_t) task.current_mOffset (HERE).mProperty_uint.uintValue ();
    element.mMaxDuration = Sca*(int32_t) task.current_mDurationMax (HERE).mProperty_uint.uintValue ();
    element.mMinDuration = useCANmaxLengthOnly
                          ? element.mMaxDuration :(Sca*(int32_t)  task.current_mDurationMin (HERE).mProperty_uint.uintValue ());

    element.mDeadline = (int32_t) task.current_mDeadline (HERE).mProperty_uint.uintValue ();
    if ( element.mDeadline !=  INT32_MAX){ // PMUINT32_MAX -> INT32_MAX by PM, 17/1/2005
    	 element.mDeadline = Sca*element.mDeadline;
    }
 //................................................
    auto ptr = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    if (ptr->taskDependsOnTask ()) {
    	int32_t elementIndex = (int32_t) ptr->getTaskDependanceValue ();
      auto q = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    	element.mEveryMultiple =
    		 (int32_t) q->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple;
   		element.mPeriod = Sca*(int32_t) task.current_mPeriod (HERE).mProperty_uint.uintValue ();
    } else if (ptr->taskDependsOnMessage ()){

    }else{
      auto q = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    	element.mEveryMultiple = (int32_t) q->getTaskEveryParameter () ;
    	element.mPeriod = Sca*(int32_t) task.current_mPeriod (HERE).mProperty_uint.uintValue ();
    }
 //................................................
  	if (ptr->taskDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T';
      element.mPredecessorId =
      int32_t (ptr->getTaskDependanceValue ());
    }else if (ptr->taskDependsOnMessage ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'M';
      element.mPredecessorId =
      int32_t (ptr->getTaskDependanceValue ()) ;
    }else{
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.appendObject (element) ;
		task.gotoNextObject () ;
    index ++ ;
  }
  int32_t NumberOfTasks = index;

  const char * kMessageClasses [] = {"standard", "extended", "  VAN   "} ;
  cEnumerator_M_5F_messages message (inMessagesMap, kENUMERATION_UP) ;

//--- Build messages map
  index = 0 ;
  message.rewind () ;
  while (message.hasCurrentObject ()) {
    cElement element ;
    strcpy(element.mElementName,message.current_lkey (HERE).mProperty_string.stringValue ().cString ());
  	element.mElementType = 'M';
    element.mId_inList = index;
  	element.mResourceId = NumberOfProcessors +
  		(int32_t) message.current_mNetworkIndex (HERE).uintValue ();
  	element.mPriority = (int32_t) message.current_mPriority (HERE).mProperty_uint.uintValue ();
  	element.mEvery = 1 ;
  	int32_t ScalingFactor =
					 Resource (element.mResourceId COMMA_HERE).mStep;
	//  printf (" Sca : %ld \n",ScalingFactor);
	  element.mOffset = ScalingFactor*(int32_t) message.current_mOffset (HERE).mProperty_uint.uintValue ();
  	if ( Resource (element.mResourceId COMMA_HERE).mResourceType == 1 ){ //CAN = 1
    	if (strstr(kMessageClasses [message.current_mClass (HERE).mProperty_uint.uintValue ()],"standard") != NULL){
    		MessageType = 'S';
    	}else if (strstr(kMessageClasses [message.current_mClass (HERE).mProperty_uint.uintValue ()],
      					"extended") != NULL){
      	MessageType = 'X' ;
      }else{
      	gCout.appendString ("ERROR : message #") ;
      	gCout.appendSigned (index) ;
      	gCout.appendString (" is neither standard (S) nor extended (X) message!\n") ;
      }

      element.mMaxDuration = ScalingFactor* maxCANMessageTime(MessageType,
      											 (uint32_t) element.mMinDuration,
      											 message.current_mBytesCount (HERE).mProperty_uint.uintValue ());

      element.mMinDuration = useCANmaxLengthOnly
        ? element.mMaxDuration
        : (ScalingFactor * minCANMessageTime(MessageType,
                            message.current_mPriority (HERE).mProperty_uint.uintValue (),
                            message.current_mBytesCount (HERE).mProperty_uint.uintValue ()));

  	}else if (Resource (element.mResourceId COMMA_HERE).mResourceType == 0 ){ //VAN = 0

    	element.mMinDuration= ScalingFactor *(64+10* (int32_t) message.current_mBytesCount (HERE).mProperty_uint.uintValue ()) ;

    	element.mMaxDuration= ScalingFactor* element.mMinDuration;
  	}else{
       printf ("ERROR : bus is neither CAN nor VAN!\n") ;
      fflush (stdout);
		}

    element.mDeadline =  (int32_t) message.current_mDeadline (HERE).mProperty_uint.uintValue ();
    if ( element.mDeadline !=  INT32_MAX){ // PMUINT32_MAX -> INT32_MAX by PM, 17/1/2005
    	 element.mDeadline = ScalingFactor *element.mDeadline;
    }
 //...........................................................................
    int32_t elementIndex ;
    auto ptr = (const cPtr_AC_5F_canMessage *) message.current_mMessageKind (HERE).ptr () ;
   if (ptr->messageDependsOnTask ()) {
   	 elementIndex = (int32_t) ptr->getMessageDependanceValue ();
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple ;
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ;
   }else if (ptr->messageDependsOnMessage ()) {
     elementIndex = (int32_t) ptr->getMessageDependanceValue () + NumberOfTasks ;
     element.mEveryMultiple = Element (elementIndex COMMA_HERE).mEveryMultiple;
     element.mPeriod = Element (elementIndex COMMA_HERE).mPeriod ;
   }else{
   	 element.mEveryMultiple = 1;
     element.mPeriod = ScalingFactor * (int32_t) message.current_mPeriod (HERE).mProperty_uint.uintValue ();
   }
 //.................................................................................
  	if (ptr->messageDependsOnTask ()) {
      element.mIsIndependant=false ;
    	element.mPredecessorType = 'T';
      element.mPredecessorId = (int32_t) ptr->getMessageDependanceValue ();
    }else if (ptr->messageDependsOnMessage ()) {
    	element.mIsIndependant=false ;
    	element.mPredecessorType = 'M';
      element.mPredecessorId = (int32_t) ptr->getMessageDependanceValue () ;
    }else{
    	element.mIsIndependant=true ;
    }
    if (!element.mIsIndependant && (element.mOffset != 0)){
      DependentHasOffset = DependentHasOffset || true ;
    }
    Element.appendObject (element) ;
	  message.gotoNextObject () ;
    index ++ ;
  }
  int32_t NumberOfMessages = index;
//*----------------------------------------------------------------------/
	//--- Print task map

	htmlFile.appendCppTitleComment ("Tasks map", "title") ;
  htmlFile.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.appendRawData ("#<th>Name<th>Processor<th>Priority<th>");
  htmlFile.appendRawData ("Offset<th>Min<th>Max<th>Period<th>") ;
  htmlFile.appendRawData ("Deadline<th>Dependence<th>Every</tr>") ;
  index = 1 ;
  task.rewind () ;
  while (task.hasCurrentObject ()) {
    htmlFile.appendRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile.appendSigned (index) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendString (task.current_lkey (HERE).mProperty_string.stringValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (task.current_mProcessor (HERE).uintValue ()+1) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (task.current_mPriority (HERE).mProperty_uint.uintValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (task.current_mOffset (HERE).mProperty_uint.uintValue ());
    htmlFile.appendRawData ("</td><td>") ;
    if (useCANmaxLengthOnly){
      htmlFile.appendUnsigned (task.current_mDurationMax (HERE).mProperty_uint.uintValue ()) ;
    }else {
      htmlFile.appendUnsigned (task.current_mDurationMin (HERE).mProperty_uint.uintValue ()) ;
    }
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (task.current_mDurationMax (HERE).mProperty_uint.uintValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;
//....................................................................
    auto ptr = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    if (ptr->taskDependsOnMessage ()) {
    	int32_t elementIndex = (int32_t) ptr->getTaskDependanceValue () + NumberOfTasks ;
      auto q = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    	Element (index-1 COMMA_HERE).mEveryMultiple =
    		 (int32_t) q->getTaskEveryParameter () * Element (elementIndex COMMA_HERE).mEveryMultiple;
    	Element (index-1 COMMA_HERE).mPeriod = Element (elementIndex COMMA_HERE).mPeriod  ;
    }
 //...................................................................
    int32_t resourceId = (int32_t) task.current_mProcessor (HERE).uintValue ();
    int32_t Scal = Resource (resourceId COMMA_HERE).mStep ;

    htmlFile.appendSigned (Element (index-1 COMMA_HERE).mEveryMultiple * Element (index-1 COMMA_HERE).mPeriod /Scal) ;
    htmlFile.appendRawData ("</td><td>") ;
    if (task.current_mDeadline (HERE).mProperty_uint.uintValue () == UINT32_MAX){
    	htmlFile.appendRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile.appendUnsigned (task.current_mDeadline (HERE).mProperty_uint.uintValue ()) ;
    	htmlFile.appendRawData ("</td><td>") ;
    }
    ptr = (const cPtr_AC_5F_task *) task.current_mTaskKind (HERE).ptr () ;
    if (ptr->taskDependsOnTask ()) {
      htmlFile.appendRawData ("task #") ;
      htmlFile.appendUnsigned (ptr->getTaskDependanceValue ()+1) ;
    }else if (ptr->taskDependsOnMessage ()) {
      htmlFile.appendRawData ("message #") ;
      htmlFile.appendUnsigned (ptr->getTaskDependanceValue ()+1) ;
    }else{
    	htmlFile.appendRawData (" ---") ;
    }
     htmlFile.appendRawData ("</td><td>") ;
     htmlFile.appendUnsigned (ptr->getTaskEveryParameter ()) ;

    htmlFile.appendRawData ("</td></tr>") ;
    task.gotoNextObject () ;
    index ++ ;
  }
  htmlFile.appendRawData ("</table>") ;
  htmlFile.appendRawData ("<br>");

//--- Print messages map
  htmlFile.appendCppTitleComment ("Messages map", "title") ;
  htmlFile.appendRawData ("<br><table class=\"result\"><tr class=\"result_title\"><td>") ;
  htmlFile.appendRawData ("#<th>Name<th>Network<th>Type<th>Priority<th>Byte");
  htmlFile.appendRawData ("<th> min--max ") ;
  htmlFile.appendRawData ("<th>Offset<th>Period<th>Deadline<th>Dependence</tr>") ;
  index = 1 ;
  message.rewind () ;
  while (message.hasCurrentObject ()) {
    htmlFile.appendRawData ("<tr class=\"result_line\"><td>") ;
    htmlFile.appendSigned (index) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendString (message.current_lkey (HERE).mProperty_string.stringValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (message.current_mNetworkIndex (HERE).uintValue () +1) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendString (kMessageClasses [message.current_mClass (HERE).mProperty_uint.uintValue ()]) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (message.current_mPriority (HERE).mProperty_uint.uintValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendUnsigned (message.current_mBytesCount (HERE).mProperty_uint.uintValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;

    int32_t resourceId =  NumberOfProcessors + (int32_t) message.current_mNetworkIndex (HERE).uintValue ();
    int32_t Scal = Resource (resourceId COMMA_HERE).mStep ;

    if ( (strstr(kMessageClasses [message.current_mClass (HERE).mProperty_uint.uintValue ()],"standard") != NULL)
    		||
    		(strstr(kMessageClasses [message.current_mClass (HERE).mProperty_uint.uintValue ()],"extended") != NULL)
    		){
      		if (useCANmaxLengthOnly){
      		  htmlFile.appendSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal) ;
      		}else{
      			htmlFile.appendSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMinDuration / Scal);
      			htmlFile.appendRawData ("--");
      			htmlFile.appendSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration / Scal) ;
      		}
    }else{
      htmlFile.appendSigned (Element((index-1+NumberOfTasks) COMMA_HERE).mMaxDuration /Scal) ;
    }
    htmlFile.appendRawData ("</td><td>");
    htmlFile.appendUnsigned (message.current_mOffset (HERE).mProperty_uint.uintValue ()) ;
    htmlFile.appendRawData ("</td><td>") ;
    htmlFile.appendSigned (Element (index-1 + NumberOfTasks  COMMA_HERE).mEveryMultiple *
                                   Element (index-1 + NumberOfTasks  COMMA_HERE).mPeriod /Scal);
    htmlFile.appendRawData ("</td><td>") ;
    if (message.current_mDeadline (HERE).mProperty_uint.uintValue () == UINT32_MAX){
    	htmlFile.appendRawData ("Unknown</td><td>") ;
    }else{
     	htmlFile.appendUnsigned (message.current_mDeadline (HERE).mProperty_uint.uintValue ()) ;
    	htmlFile.appendRawData ("</td><td>") ;
    }
    auto ptr = (const cPtr_AC_5F_canMessage *) message.current_mMessageKind (HERE).ptr () ;
   	if (ptr->messageDependsOnTask ()) {
    	htmlFile.appendRawData ("task #") ;
     	htmlFile.appendUnsigned (ptr->getMessageDependanceValue ()+1) ;
    }else if (ptr->messageDependsOnMessage ()) {
    	htmlFile.appendRawData ("message # ") ;
 	   	htmlFile.appendUnsigned (ptr->getMessageDependanceValue ()+1) ;
    }else{
    	htmlFile.appendRawData (" ---") ;
    }

    htmlFile.appendRawData ("</td></tr>") ;
    message.gotoNextObject () ;
    index ++ ;
  }
  htmlFile.appendRawData ("</table>") ;
  htmlFile.appendRawData ("<br>");
  htmlFile.flush () ;
//*----------------------------------------------------------------------/

// Verification of  necessary scheduling conditions

  if (NecessaryConditions_OK (inCompiler, Element, Resource) ){

  	TC_UniqueArray <cActivity> exElement ;
  	TC_UniqueArray <cResponseTime> responseTimeArray ;
  	TC_UniqueArray <cMTElement> MTElement ;
  	TC_UniqueArray <cReadyAtThisInstant>  ReadyAtThisInstant;

   int32_t NoInterButUseB =
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
    printf ("Results are stored in %s file.\n", htmlFileName.cString ());

 	}else{
    printf ("System map is stored in %s file.\n", htmlFileName.cString ());
 	}
 	fflush (stdout);
}

/*--------------------------------------------------------------------------*/
