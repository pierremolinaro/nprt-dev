#include <stdlib.h> 

#include "ExtendedList-v2.h"
#include "VerifyConditions-v2.h"
#include "C_us.h"

#include "galgas2/C_Compiler.h"

bool
NecessaryConditions_OK (C_Compiler * inCompiler,
                        const TC_UniqueArray <cElement> & Element,
            						const TC_UniqueArray <cResource> & Resource){
                        
  const PMSInt32 NumOfElements = Element.count ();
  const PMSInt32 NumOfResources = Resource.count ();            
	
  bool NecessaryConditionOK = true ;
  
  const char *ResType[3]={"Network","Network","Processor"};

//Verify if the maximum load for each resource is not greater than 1

  for (PMSInt32 index = 0; index < NumOfResources ;index++){
    double ResourceLoad = 0.0 ;
    for (PMSInt32 i = 0; i < NumOfElements ;i++){
      if( index == Element (i COMMA_HERE).mResourceId){
       	ResourceLoad += double( Element (i COMMA_HERE).mMaxDuration)/ (Element (i COMMA_HERE).mPeriod * Element (i COMMA_HERE).mEveryMultiple );
      }
    }
    if(ResourceLoad > 1){
    	NecessaryConditionOK = false ;
    	C_String errorMessage ;
    	errorMessage << "Maximum load for "
    	             <<  ResType[Resource (index COMMA_HERE).mResourceType]
    	             << " ("
    	             << Resource (index COMMA_HERE).mResourceName
    	             << ") is: "
    	             << cStringWithDouble (ResourceLoad)
    	             << " (greater than 1.0) !\n" ;

      inCompiler->onTheFlySemanticError (errorMessage COMMA_HERE) ;
    }else{ 
     	NecessaryConditionOK = NecessaryConditionOK && true;
    }   
  }
  return NecessaryConditionOK;
} 






