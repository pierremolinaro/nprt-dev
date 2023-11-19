#include "collections/TC_UniqueArray.h"

class C_String ;

#ifdef _cplusplus
extern "C" {
#endif

#ifndef EXTENDEDLIST_H
#define EXTENDEDLIST_H

class C_HTML_FileWrite ;

#define nprt_min_macro(x, y)   ((x) < (y) ? (x) : (y))
#define nprt_max_macro(x, y)   ((x) > (y) ? (x) : (y))

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

class C_Compiler ;


int32_t
BuildExtendedList (C_Compiler * inCompiler,
                   TC_UniqueArray < cReadyAtThisInstant> & ReadyAtThisInstant,
                   TC_UniqueArray <cElement> & Element,
                   const TC_UniqueArray <cResource> & Resource,
                   TC_UniqueArray <cActivity> & exElement,
                   TC_UniqueArray <cMTElement> & outMTElement,
                   const int32_t Nu_oftasks, const int32_t Nu_ofMessages,
                   bool CreateIntermediateFiles,
                   bool & ioUseBalgorithm,
                   const C_String & activitiesHTMLFileName);
                   

void
ExtractWorstBestRT (C_Compiler * inCompiler,
                    const TC_UniqueArray <cActivity> & exElement,
                    const TC_UniqueArray <cResource> & Resource,
                    TC_UniqueArray <cMTElement> & MTElement,
                    const TC_UniqueArray <cResponseTime> & inResponseTimeArray,
                    bool CreateIntermediateFiles, 
                    const C_String & raw_outputHTMLFileName,
                    C_HTML_FileWrite & in_htmlFile);


#endif

#ifdef _cplusplus
}
#endif
