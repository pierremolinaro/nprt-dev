#ifdef _cplusplus
extern "C" {
#endif

#ifndef EXTENDEDLIST_H
#define EXTENDEDLIST_H

class C_HTML_FileWrite ;

#define min(x, y)   ((x) < (y) ? (x) : (y))
#define MAX(x, y)   ((x) > (y) ? (x) : (y))

class cActivity {
  public : PMSInt32 mOccurrence ; //Element occurrence during the hyper period
  public : char mElementName[14]; //Name of the activivty
  public : PMSInt32 mResourceId; //
  public : PMSInt32 mPriority ;
  public : PMSInt32 mOffset ; 
  public : PMSInt32 mEvery ;
  public : PMSInt32 mMinDuration ;
  public : PMSInt32 mMaxDuration ; 
  public : PMSInt32 mDeadline ;
  public : PMSInt32 mPredecessorId ; // -1 if independant
  public : PMSInt32 mSuccessorId;  // -1 if no successor, or its index
  public : PMSInt32 mOtherHeirId; //
  public : PMSInt32 mOtherReadyAtThisInst;
};

class cResponseTime {
  public : PMSInt32 mBestResponseTime;
  public : PMSInt32 mWorstResponseTime;
  public : cResponseTime (void) ;
} ;

class cReadyAtThisInstant {
  public : PMSInt32 mThisInstant;
  public : PMSInt32 mActivityIndex;
  public : bool mMarked;

};

class cResource {
  public : char mResourceName[14];
  public : PMSInt32 mResourceType; //CAN = 1, VAN = 0 & Processor = 2
  public : PMSInt32 mStep; // Granularity temporel
  public : PMSInt32 mMinDuration;
};

class cElement {
  public : char mElementName[14]; //Name of the activivty
  public : char mElementType ; // Message--->M or Task ---->T
  public : PMSInt32 mId_inList;
  public : PMSInt32 mResourceId; //
  public : PMSInt32 mPriority ;
  public : PMSInt32 mOffset ;
  public : PMSInt32 mEvery ;
  public : PMSInt32 mMinDuration ;
  public : PMSInt32 mMaxDuration ; 
  public : PMSInt32 mDeadline ;
  public : PMSInt32 mPeriod ;
  public : bool mIsIndependant;
  public : PMSInt32 mEveryMultiple;
  public : char mPredecessorType ; // Message--->M or Task ---->T
  public : PMSInt32 mPredecessorId;
  public : PMSInt32 mSuccessorId;
  public : PMSInt32 mInExtendedList;
  public : PMSInt32 mOtherHeirId; //
} ;


class cMTElement {
  public :char mElementName[14];
  public : PMSInt32 mWidth;
  public : PMSInt32 mEvery ;
  public : PMSInt32 mResourceId; //
  public : PMSInt32 mPriority;
  public : PMSInt32 mOffset ;
  public : PMSInt32 mBestResponseTime ;
  public : PMSInt32 mWorstResponseTime ; 
  public : PMSInt32 mPeriod ; 
  public : PMSInt32 mDeadline ;
} ;

class C_Compiler ;


PMSInt32
BuildExtendedList (C_Compiler & inLexique,
                   TC_UniqueArray < cReadyAtThisInstant> & ReadyAtThisInstant,
                   TC_UniqueArray <cElement> & Element,
                   const TC_UniqueArray <cResource> & Resource,
                   TC_UniqueArray <cActivity> & exElement,
                   TC_UniqueArray <cMTElement> & outMTElement,
                   const PMSInt32 Nu_oftasks, const PMSInt32 Nu_ofMessages,
                   bool CreateIntermediateFiles,
                   bool & ioUseBalgorithm,
                   const C_String & activitiesHTMLFileName);
                   

void
ExtractWorstBestRT (C_Compiler & inLexique,
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
