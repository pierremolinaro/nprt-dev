#include<stdlib.h> 
#include "oa_main.h"
#include "ExtendedList.h"
#include "VerifyConditions.h"
#include "C_us.h"

bool
NecessaryConditions_OK (C_lexique & inLexique,
                        const TCUniqueArray <cElement> & Element,
            						const TCUniqueArray <cResource> & Resource){
                        
  const sint32 NumOfElements = Element.count ();
  const sint32 NumOfResources = Resource.count ();            
	
  bool NecessaryConditionOK = true ;
  
  const char *ResType[3]={"Network","Network","Processor"};

//Verify if the maximum load for each resource is not greater than 1

  for (sint32 index = 0; index < NumOfResources ;index++){
    double ResourceLoad = 0.0 ;
    for (sint32 i = 0; i < NumOfElements ;i++){
      if( index == Element (i COMMA_HERE).mResourceId){
       	ResourceLoad += double( Element (i COMMA_HERE).mMaxDuration)/ (Element (i COMMA_HERE).mPeriod * Element (i COMMA_HERE).mEveryMultiple );
      }
    }
    if(ResourceLoad > 1){
    	NecessaryConditionOK = false ;
    	C_string errorMessage ;
    	errorMessage << "Maximum load for "
    	             <<  ResType[Resource (index COMMA_HERE).mResourceType]
    	             << " ("
    	             << Resource (index COMMA_HERE).mResourceName
    	             << ") is: "
    	             << ResourceLoad
    	             << " (greater than 1.0) !\n" ;

      inLexique.onTheFlySemanticError (errorMessage) ;
    }else{ 
     	NecessaryConditionOK = NecessaryConditionOK && true;
    }   
  }
  return NecessaryConditionOK;
} 






