#pragma once

#include "TC_UniqueArray.h"

class String ;

#ifdef _cplusplus
extern "C" {
#endif

class HTMLFileWrite ;


class cActivity {
  public : int32_t mOccurrence ; //Element occurrence during the hyper period
  public : char mElementName[14]; //Name of the activivty
  public : int32_t mResourceId; //
  public : int32_t mPriority ;
  public : int32_t mOffset ;
  public : int32_t mEvery ;
  public : int32_t mMinDuration ;
  public : int32_t mMaxDuration ;
  public : int32_t mDeadline ;
  public : int32_t mPredecessorId ; // -1 if independant
  public : int32_t mSuccessorId;  // -1 if no successor, or its index
  public : int32_t mOtherHeirId; //
  public : int32_t mOtherReadyAtThisInst;
};

class cResponseTime {
  public : int32_t mBestResponseTime;
  public : int32_t mWorstResponseTime;
  public : cResponseTime (void) ;
} ;

class cReadyAtThisInstant {
  public : int32_t mThisInstant;
  public : int32_t mActivityIndex;
  public : bool mMarked;

};

class cResource {
  public : char mResourceName[14];
  public : int32_t mResourceType; //CAN = 1, VAN = 0 & Processor = 2
  public : int32_t mStep; // Granularity temporel
  public : int32_t mMinDuration;
};

class cElement {
  public : char mElementName[14]; //Name of the activivty
  public : char mElementType ; // Message--->M or Task ---->T
  public : int32_t mId_inList;
  public : int32_t mResourceId; //
  public : int32_t mPriority ;
  public : int32_t mOffset ;
  public : int32_t mEvery ;
  public : int32_t mMinDuration ;
  public : int32_t mMaxDuration ;
  public : int32_t mDeadline ;
  public : int32_t mPeriod ;
  public : bool mIsIndependant;
  public : int32_t mEveryMultiple;
  public : char mPredecessorType ; // Message--->M or Task ---->T
  public : int32_t mPredecessorId;
  public : int32_t mSuccessorId;
  public : int32_t mInExtendedList;
  public : int32_t mOtherHeirId; //
} ;


class cMTElement {
  public :char mElementName[14];
  public : int32_t mWidth;
  public : int32_t mEvery ;
  public : int32_t mResourceId; //
  public : int32_t mPriority;
  public : int32_t mOffset ;
  public : int32_t mBestResponseTime ;
  public : int32_t mWorstResponseTime ;
  public : int32_t mPeriod ;
  public : int32_t mDeadline ;
} ;

class Compiler ;


int32_t
BuildExtendedList (Compiler * inCompiler,
                   TC_UniqueArray < cReadyAtThisInstant> & ReadyAtThisInstant,
                   TC_UniqueArray <cElement> & Element,
                   const TC_UniqueArray <cResource> & Resource,
                   TC_UniqueArray <cActivity> & exElement,
                   TC_UniqueArray <cMTElement> & outMTElement,
                   const int32_t Nu_oftasks, const int32_t Nu_ofMessages,
                   bool CreateIntermediateFiles,
                   bool & ioUseBalgorithm,
                   const String & activitiesHTMLFileName);


void
ExtractWorstBestRT (Compiler * inCompiler,
                    const TC_UniqueArray <cActivity> & exElement,
                    const TC_UniqueArray <cResource> & Resource,
                    TC_UniqueArray <cMTElement> & MTElement,
                    const TC_UniqueArray <cResponseTime> & inResponseTimeArray,
                    bool CreateIntermediateFiles,
                    const String & raw_outputHTMLFileName,
                    HTMLFileWrite & in_htmlFile);


#ifdef _cplusplus
}
#endif
