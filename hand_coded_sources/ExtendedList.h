#ifdef _cplusplus
extern "C" {
#endif

#ifndef EXTENDEDLIST_H
#define EXTENDEDLIST_H

class C_HTML_FileWrite ;

#define min(x, y)   ((x) < (y) ? (x) : (y))
#define MAX(x, y)   ((x) > (y) ? (x) : (y))

class cActivity {
  public : sint32 mOccurrence ; //Element occurrence during the hyper period
  public : char mElementName[14]; //Name of the activivty
  public : sint32 mResourceId; //
  public : sint32 mPriority ;
  public : sint32 mOffset ; 
  public : sint32 mEvery ;
  public : sint32 mMinDuration ;
  public : sint32 mMaxDuration ; 
  public : sint32 mDeadline ;
  public : sint32 mPredecessorId ; // -1 if independant
  public : sint32 mSuccessorId;  // -1 if no successor, or its index
  public : sint32 mOtherHeirId; //
  public : sint32 mOtherReadyAtThisInst;
};

class cResponseTime {
  public : sint32 mBestResponseTime;
  public : sint32 mWorstResponseTime;
  public : cResponseTime (void) ;
} ;

class cReadyAtThisInstant {
  public : sint32 mThisInstant;
  public : sint32 mActivityIndex;
  public : bool mMarked;

};

class cResource {
  public : char mResourceName[14];
  public : sint32 mResourceType; //CAN = 1, VAN = 0 & Processor = 2
  public : sint32 mStep; // Granularity temporel
  public : sint32 mMinDuration;
};

class cElement {
  public : char mElementName[14]; //Name of the activivty
  public : char mElementType ; // Message--->M or Task ---->T
  public : sint32 mId_inList;
  public : sint32 mResourceId; //
  public : sint32 mPriority ;
  public : sint32 mOffset ;
  public : sint32 mEvery ;
  public : sint32 mMinDuration ;
  public : sint32 mMaxDuration ; 
  public : sint32 mDeadline ;
  public : sint32 mPeriod ;
  public : bool mIsIndependant;
  public : sint32 mEveryMultiple;
  public : char mPredecessorType ; // Message--->M or Task ---->T
  public : sint32 mPredecessorId;
  public : sint32 mSuccessorId;
  public : sint32 mInExtendedList;
  public : sint32 mOtherHeirId; //
} ;


class cMTElement {
  public :char mElementName[14];
  public : sint32 mWidth;
  public : sint32 mEvery ;
  public : sint32 mResourceId; //
  public : sint32 mPriority;
  public : sint32 mOffset ;
  public : sint32 mBestResponseTime ;
  public : sint32 mWorstResponseTime ; 
  public : sint32 mPeriod ; 
  public : sint32 mDeadline ;
} ;



sint32
BuildExtendedList (TC_UniqueArray < cReadyAtThisInstant> & ReadyAtThisInstant,
                   TC_UniqueArray <cElement> & Element,
                   const TC_UniqueArray <cResource> & Resource,
                  TC_UniqueArray <cActivity> & exElement,
                  TC_UniqueArray <cMTElement> & outMTElement,
                  const sint32 Nu_oftasks, const sint32 Nu_ofMessages,
                  bool CreateIntermediateFiles,
                  bool & ioUseBalgorithm,
                  const C_String & activitiesHTMLFileName);
                   

void
ExtractWorstBestRT (const TC_UniqueArray <cActivity> & exElement,
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
