#include <stdlib.h>

#include "ExtendedList-v2.h"
#include "VerifyConditions-v2.h"
#include "C_us.h"

#include "Compiler.h"

bool
NecessaryConditions_OK (Compiler * inCompiler,
                        const GenericUniqueArray <cElement> & Element,
            						const GenericUniqueArray <cResource> & Resource){

  const int32_t NumOfElements = Element.count ();
  const int32_t NumOfResources = Resource.count ();

  bool NecessaryConditionOK = true ;

  const char *ResType[3]={"Network","Network","Processor"};

//Verify if the maximum load for each resource is not greater than 1

  for (int32_t index = 0; index < NumOfResources ;index++){
    double ResourceLoad = 0.0 ;
    for (int32_t i = 0; i < NumOfElements ;i++){
      if( index == Element (i COMMA_HERE).mResourceId){
       	ResourceLoad += double( Element (i COMMA_HERE).mMaxDuration)/ (Element (i COMMA_HERE).mPeriod * Element (i COMMA_HERE).mEveryMultiple );
      }
    }
    if(ResourceLoad > 1){
    	NecessaryConditionOK = false ;
    	String errorMessage ;
    	errorMessage.appendString ("Maximum load for ") ;
    	errorMessage.appendString (ResType[Resource (index COMMA_HERE).mResourceType]) ;
    	errorMessage.appendString (" (") ;
    	errorMessage.appendString (Resource (index COMMA_HERE).mResourceName) ;
    	errorMessage.appendString (") is: ") ;
    	errorMessage.appendDouble (ResourceLoad) ;
    	errorMessage.appendString (" (greater than 1.0) !\n") ;

      inCompiler->onTheFlySemanticError (errorMessage COMMA_HERE) ;
    }else{
     	NecessaryConditionOK = NecessaryConditionOK && true;
    }
  }
  return NecessaryConditionOK;
}






