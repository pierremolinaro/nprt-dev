//---------------------------------------------------------------------------*
//                                                                           *
//  Main program for activities scheduler                                    *
//                                                                           *
//  Copyright (C) 2002-2004 Pierre Molinaro (started august 8th, 2002).      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This program is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU General Public License as published by the    *
//  Free Software Foundation.                                                *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#include "collections/TC_UniqueArray.h"
#include "streams/C_ConsoleOut.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/mainForLIBPM.h"
#include "time/C_Timer.h"
#include "utilities/TF_sup.h"
#include "utilities/TF_inf.h"
#include "utilities/F_GetPrime.h"
#include "ExtendedList.h"
#include "C_activitiesToSchedule.h"
#include "activities_core.h"

//---------------------------------------------------------------------------*

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

//---------------------------------------------------------------------------*

#define FORGET_ACTIVITY_NODES
//#define HASH_MAP

//---------------------------------------------------------------------------*
//                                                                           *
//    c A c t i v i t y S c h e d u l e                                      *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  class cActivitySchedule {
    public : PMSInt32 mActivityIndex ;
    public : PMSInt32 mActivityDuration ;
    public : PMSInt32 mActivityEndOfExecution ;
    public : cActivitySchedule * mPtrToOtherSchedule ;
    public : cActivitySchedule * mPtrToSameSchedule ;
    public : cActivitySchedule * mPtrToNextNode ;
    public : bool mMarked ;
  } ;
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//    c A c t i v i t y L i s t                                              *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  class cActivityList {
    protected : cActivitySchedule * mPtrToFirstActivity ;
    protected : cActivitySchedule * mPtrToLastActivity ;
  
    public : cActivityList (void) ;
  
    public : void push (const PMSInt32 inActivity,
                        const PMSInt32 inEndOfExecution,
                        const PMSInt32 inExecutionCounter) ;

    public : void mergeList (cActivityList & inOtherList) ;

    public : void suppressFirst (void) ;
  
    public : static void dumpSchedule (class cResourceSchedule * inPtr) ;

    public : static void computeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & ioResponseTimeArray) ;

  } ;
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  cActivityList::cActivityList (void) :
  mPtrToFirstActivity (NULL),
  mPtrToLastActivity (NULL) {
  }
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  static cActivitySchedule * gPtrNodeList = NULL ;
//  static PMSInt32 gAllocatedActivityNodesCount = 0 ;
#endif

static PMSInt32 gAllocatedActivityNodesCount = 0 ;
static bool NoInterdependenceButUseB ;
static bool DependentActivitiesHasOffset;
static PMSInt32 ResourceMinDuration[1000];

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
void cActivityList::push (const PMSInt32 inActivity,
                          const PMSInt32 inEndOfExecution,
                          const PMSInt32 inExecutionCounter) {
//  gAllocatedActivityNodesCount ++ ;
  cActivitySchedule * p = new cActivitySchedule ;
  p->mPtrToOtherSchedule = NULL ;
  p->mMarked = false ;
  p->mActivityIndex = inActivity ;
  p->mActivityDuration = inExecutionCounter ;
  p->mActivityEndOfExecution = inEndOfExecution ;
  p->mPtrToNextNode = gPtrNodeList ;
  gPtrNodeList = p ;
  if (mPtrToFirstActivity == NULL) {
    p->mPtrToSameSchedule = NULL ;
  }else{
    p->mPtrToSameSchedule = mPtrToFirstActivity ;
  }
  mPtrToFirstActivity = p ;
  mPtrToLastActivity = p ;
}
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  void cActivityList::suppressFirst (void) {
    mPtrToFirstActivity = mPtrToFirstActivity->mPtrToSameSchedule ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
void cActivityList::mergeList (cActivityList & inOtherList) {
  if (mPtrToFirstActivity == NULL) {
    mPtrToFirstActivity = inOtherList.mPtrToFirstActivity ;
    mPtrToLastActivity = inOtherList.mPtrToLastActivity ;
  }else if (inOtherList.mPtrToFirstActivity != NULL) {
    mPtrToLastActivity->mPtrToOtherSchedule = inOtherList.mPtrToFirstActivity ;
    mPtrToLastActivity = inOtherList.mPtrToLastActivity ;
  }
}
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//    c R e s o u r c e S c h e d u l e                                      *
//                                                                           *
//---------------------------------------------------------------------------*

class cResource2 {
  public : C_activitiesToSchedule mActivitiesToScheduleList ;
  public : PMSInt32 mCurrentActivity ;
  public : PMSInt32 mExecutionCounter ;
  public : bool mHasNoNewActivities ;
  public : PMSInt32 mLHBound ;
  public : PMSInt32 mStep ;

  public : cResource2 (void) ;

  public : inline bool operator == (const cResource2 & inOperand) const {
    return (mActivitiesToScheduleList == inOperand.mActivitiesToScheduleList)
      && (mCurrentActivity == inOperand.mCurrentActivity)
      && (mExecutionCounter == inOperand.mExecutionCounter) ;  
  }

  public : inline PMSInt compare (const cResource2 & inOperand) const {
    PMSInt result = mActivitiesToScheduleList.getPtr () - inOperand.mActivitiesToScheduleList.getPtr () ;
    if (result == 0) {
      result = mCurrentActivity - inOperand.mCurrentActivity ;
      if (result == 0) {
        result = mExecutionCounter - inOperand.mExecutionCounter ;
      }
    }
    return result ;  
  }

  public : inline PMUInt32 hash (void) const {
    return (PMUInt32) mActivitiesToScheduleList.getPtr () ;  
  }
} ;

//---------------------------------------------------------------------------*

class cResourceSchedule {
  public : TC_UniqueArray <cResource2> mArray ;
  public : cResourceSchedule * mPtrToOtherResource ;
  #ifndef FORGET_ACTIVITY_NODES
    public : cActivityList mActivityList ;
  #endif
  public : cResourceSchedule * mPtrToInf ;
  public : cResourceSchedule * mPtrToSup ;
  public : PMSInt32 mBalance ;
  public : PMUInt32 mHash ;
 
  public : cResourceSchedule (const PMSInt32 inResourceCount) ;

//--- No copy
  private : cResourceSchedule (const cResourceSchedule &) ;
  private : cResourceSchedule & operator = (const cResourceSchedule &) ;
  
  public : inline void hash (const PMSInt32 inResourceCount) {
    PMUInt32 hashValue = mArray (0 COMMA_HERE).hash () ;
    for (PMSInt32 i=1 ; i<inResourceCount ; i++) {
      hashValue <<= 3 ;
      hashValue ^= mArray (i COMMA_HERE).hash () ;
    }
    mHash = hashValue ;  
  }

} ;

//---------------------------------------------------------------------------*

cResource2::cResource2 (void) :
mActivitiesToScheduleList (),
mCurrentActivity (0),
mExecutionCounter (0),
mHasNoNewActivities (false),
mLHBound (0),
mStep (0) {
}

//---------------------------------------------------------------------------*

cResourceSchedule::
cResourceSchedule (const PMSInt32 inResourceCount) :
mArray (inResourceCount COMMA_HERE),
mPtrToOtherResource (NULL),
mPtrToInf (NULL),
mPtrToSup (NULL),
mBalance (0),
mHash (0) {
  mArray.addObjects (inResourceCount, cResource2 ()) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    c R e s o u r c e S c h e d u l e M a p                                *
//                                                                           *
//---------------------------------------------------------------------------*

class cScheduleMap {
  #ifdef HASH_MAP
    private : TC_UniqueArray <cResourceSchedule *> mResourceNodesAVLtree ;
    public : PMSInt32 mArraySize ;
  #else
    private : cResourceSchedule * mResourceNodesAVLtree ;
  #endif
  private : cResourceSchedule * mResourceNodesList ;
  private : PMSInt32 mCurrentInstant ;
  private : PMSInt32 mLastIndependantActivityScheduleInstant ;

//--- Constructor
  public : cScheduleMap (const PMSInt32 inResourceCount,
                         const PMSInt32 inLastIndependantActivityScheduleInstant,
                         const TC_UniqueArray <cActivity> & inActivities) ;
  public : void AddToScheduleMap (cResourceSchedule * inPtr,
                                  const PMSInt32 index,
                                  const TC_UniqueArray <cActivity> & inActivities);

//--- More work ?
  public : bool moreWorkToDo (void) const ;

  public : inline PMSInt32 getCurrentInstant (void) const { return mCurrentInstant ; }

  public : cResourceSchedule * retrieveResourceList (void) ;

  public : void insert (const PMSInt32 inResourceCount,
                        cResourceSchedule * inResource) ;

  public : void advanceToNextInstant (void) ;

  #ifndef FORGET_ACTIVITY_NODES
    public : void dumpStructure (void) ;
    public : void computeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & ioResponseTimeArray,
                                                   const PMSInt32 inActivitiesCount) ;
  #endif
} ;

//---------------------------------------------------------------------------*

static cResourceSchedule * gResourceFreeList = NULL ;
static PMSInt32 gAllocatedResourceNodesCount = 0 ;
static PMSInt32 gUsedResourceNodesCount = 0 ;

//---------------------------------------------------------------------------*

static inline cResourceSchedule * allocResourceNode (const PMSInt32 inResourceCount) {
  gUsedResourceNodesCount ++ ;
  cResourceSchedule * p = gResourceFreeList ;
  if (p == NULL) {
    p = new cResourceSchedule (inResourceCount) ;
    gAllocatedResourceNodesCount ++ ;
   }else{
    gResourceFreeList = p->mPtrToOtherResource ;
    p->mPtrToOtherResource = NULL ;
    p->mArray.removeAllObjects () ;
    p->mArray.addObjects (inResourceCount, cResource2 ()) ;
  }
  return p ;
}
//---------------------------------------------------------------------------*

static inline void disposeResourceNode (cResourceSchedule * inPtr) {
  inPtr->mPtrToOtherResource = gResourceFreeList ;
  gResourceFreeList = inPtr ;
}

//---------------------------------------------------------------------------*

cScheduleMap::
cScheduleMap (const PMSInt32 /*inResourceCount */,
              const PMSInt32 inLastIndependantActivityScheduleInstant,
              const TC_UniqueArray <cActivity> & /*inActivities*/) :
  
mResourceNodesAVLtree (),
mResourceNodesList (NULL),
mCurrentInstant (0),
mLastIndependantActivityScheduleInstant (inLastIndependantActivityScheduleInstant) {
   //--- Enter independant activities
//  printf ("%ld activities\n", inActivities.count ()) ;
//  fflush (stdout);
  mResourceNodesList = NULL ;
  #ifdef HASH_MAP
    mArraySize = getPrimeGreaterThan (1000000) ;
    mResourceNodesAVLtree.reallocArray (mArraySize COMMA_HERE) ;
    for (PMSInt32 r=0 ; r<mArraySize ; r++) {
      mResourceNodesAVLtree (r COMMA_HERE) = NULL ;
    }
  #else
    mResourceNodesAVLtree = NULL ;
  #endif

//--- Init resource node
  #ifdef HASH_MAP
    mResourceNodesList->hash (inResourceCount) ;
    mResourceNodesAVLtree ((PMSInt32) (mResourceNodesList->mHash % mArraySize) COMMA_HERE) = mResourceNodesList ;
  #else
    mResourceNodesAVLtree = mResourceNodesList ;
  #endif
}

//--------------------------------------------------------------------------*
void cScheduleMap::
AddToScheduleMap (cResourceSchedule * inPtr,
                  const PMSInt32 inIndex,
							    const TC_UniqueArray <cActivity> & inActivities) {
  PMSInt32 index = inIndex;
   do{
		  const PMSInt32 readyAt = inActivities (index COMMA_HERE).mOffset ;
      const PMSInt32 resourceIndex = inActivities (index COMMA_HERE).mResourceId ;
		  const PMSInt32 priority = inActivities (index COMMA_HERE).mPriority ;
		  //--- Insert activity into activity list
		  
  	 inPtr->mArray (resourceIndex COMMA_HERE).mActivitiesToScheduleList.addEntry (index, 
     								priority, readyAt);
    		
		 index = inActivities (index COMMA_HERE).mOtherReadyAtThisInst ;
	 }while(index != -1 );
}

//--------------------------------------------------------------------------*

bool cScheduleMap::moreWorkToDo (void) const {
  return (mResourceNodesList != NULL) || (mCurrentInstant <= mLastIndependantActivityScheduleInstant) ;
}

//---------------------------------------------------------------------------*

cResourceSchedule * cScheduleMap::retrieveResourceList (void) {
  cResourceSchedule * p = mResourceNodesList ;
  #ifdef HASH_MAP
    while (p != NULL) {
      mResourceNodesAVLtree ((PMSInt32) (p->mHash % mArraySize) COMMA_HERE) = NULL ;
      p = p->mPtrToOtherResource ;
    }
    p = mResourceNodesList ;
  #else
    mResourceNodesAVLtree = NULL ;
  #endif
  mResourceNodesList = NULL ;
  return p ;
}

//---------------------------------------------------------------------------*

void cScheduleMap::advanceToNextInstant (void) {
  mCurrentInstant ++ ;
}

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  static cActivityList gScheduleResults ;
#endif

//---------------------------------------------------------------------------*

static void
rotationGauche (cResourceSchedule * & a) {
// faire la rotation 
  cResourceSchedule * b = a->mPtrToSup ;
  a->mPtrToSup = b->mPtrToInf ;
  b->mPtrToInf = a;

// recalculer l'equilibrage 
  if (b->mBalance >= 0) {
    a->mBalance++ ;
  }else{
    a->mBalance +=  1 - b->mBalance ;
  }
  if (a->mBalance > 0) {
    b->mBalance += a->mBalance + 1 ;
  }else{
    b->mBalance++ ;
  }
  a = b ;
} 

//---------------------------------------------------------------------

static void
rotationDroite (cResourceSchedule * & a) {
// faire la rotation 
  cResourceSchedule * b = a->mPtrToInf ;
  a->mPtrToInf = b->mPtrToSup ;
  b->mPtrToSup = a ;
 
// recalculer l'equilibrage 
  if (b->mBalance > 0) {
    a->mBalance -= b->mBalance + 1 ;
  }else{
    a->mBalance-- ;
  } ;
  if (a->mBalance >= 0) {
    b->mBalance-- ;
  }else{
    b->mBalance += a->mBalance - 1 ;
  }
  a = b ;
}

//---------------------------------------------------------------------------*

static void
recursiveInsertResourceNode (cResourceSchedule * inResource,
                             cResourceSchedule * & ioRoot,
                             cResourceSchedule * & ioResourceNodesList,
                             const PMSInt32 inResourceCount,
                             bool & ioExtension) {
  if (ioRoot == NULL) {
    ioRoot = inResource ;
    ioRoot->mBalance = 0 ;
    ioRoot->mPtrToInf = NULL ;
    ioRoot->mPtrToSup = NULL ;
    ioRoot->mPtrToOtherResource = ioResourceNodesList ;
    ioResourceNodesList = ioRoot ;
    ioExtension = true ;
  }else{
    PMSInt comparaison = 0 ;
    for (PMSInt32 i=0 ; (i<inResourceCount) && (comparaison == 0) ; i++) {
      comparaison = ioRoot->mArray (i COMMA_HERE).compare (inResource->mArray (i COMMA_HERE)) ;
    }
    if (comparaison > 0) {
      recursiveInsertResourceNode (inResource, ioRoot->mPtrToInf, ioResourceNodesList, inResourceCount, ioExtension) ;
      if (ioExtension) {
        ioRoot->mBalance++;
        switch (ioRoot->mBalance) {
        case 0:
          ioExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRoot->mPtrToInf->mBalance == -1) {
            rotationGauche (ioRoot->mPtrToInf) ;
          }
          rotationDroite (ioRoot) ;
          ioExtension = false;
          break;
        }
      }
    }else if (comparaison < 0) {
      recursiveInsertResourceNode (inResource, ioRoot->mPtrToSup, ioResourceNodesList, inResourceCount, ioExtension) ;
      if (ioExtension) {
        ioRoot->mBalance-- ;
        switch (ioRoot->mBalance) {
        case 0:
          ioExtension = false ;
          break;
        case -1:
          break;
        case -2:
          if (ioRoot->mPtrToSup->mBalance == 1) {
            rotationDroite (ioRoot->mPtrToSup) ;
          }
          rotationGauche (ioRoot) ;
          ioExtension = false;
          break;
        }
      }
    }else{
      #ifndef FORGET_ACTIVITY_NODES
        ioRoot->mActivityList.mergeList (inResource->mActivityList) ;
      #endif
      disposeResourceNode (inResource) ;
      ioExtension = false;
    }
  }
}

//---------------------------------------------------------------------------*

void cScheduleMap::
insert (const PMSInt32 inResourceCount,
        cResourceSchedule * inResource) {
//--- Insert
  #ifdef HASH_MAP
    inResource->hash (inResourceCount) ;
  #endif
  bool extension ; // Unused
  recursiveInsertResourceNode (inResource,
                               #ifdef HASH_MAP
                                 mResourceNodesAVLtree ((PMSInt32) (inResource->mHash % mArraySize) COMMA_HERE),
                               #else
                                 mResourceNodesAVLtree,
                               #endif
                               mResourceNodesList,
                               inResourceCount,
                               extension) ;
  
}     

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  static void unMark (void) {
    cActivitySchedule * p = gPtrNodeList ;
    while (p != NULL) {
      p->mMarked = false ;
      p = p->mPtrToNextNode ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  static void
  internalComputeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & ioResponseTimeArray,
                                           cActivitySchedule * inPtr) {
    cActivitySchedule * p = inPtr ;
    while (p != NULL) {
      if (! p->mMarked) {
        p->mMarked = true ;
        const PMSInt32 activityIndex = p->mActivityIndex ;
        const PMSInt32 eoe = p->mActivityEndOfExecution ;
        if (ioResponseTimeArray (activityIndex COMMA_HERE).mBestResponseTime > eoe) {
          ioResponseTimeArray (activityIndex COMMA_HERE).mBestResponseTime = eoe ;
        }
        if (ioResponseTimeArray (activityIndex COMMA_HERE).mWorstResponseTime < eoe) {
          ioResponseTimeArray (activityIndex COMMA_HERE).mWorstResponseTime = eoe ;
        }
        internalComputeBestAndWorstResponseTime (ioResponseTimeArray, p->mPtrToSameSchedule) ;
      }
      p = p->mPtrToOtherSchedule ;
    }
  }
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
  void cActivityList::
  computeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & ioResponseTimeArray) {
    unMark () ;
    internalComputeBestAndWorstResponseTime (ioResponseTimeArray, gScheduleResults.mPtrToFirstActivity) ;
  }
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
void cScheduleMap::
computeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & outResponseTimeArray,
                                 const PMSInt32 inActivitiesCount) {
  TC_UniqueArray <cResponseTime> otherMethodResponseTimeArray (inActivitiesCount COMMA_HERE) ;
  for (PMSInt32 i=0 ; i<inActivitiesCount ; i++) {
    otherMethodResponseTimeArray (i COMMA_HERE).mBestResponseTime = PMSINT32_MAX ;
    otherMethodResponseTimeArray (i COMMA_HERE).mWorstResponseTime = 0 ;
  }
//--- First method
  cActivitySchedule * p = gPtrNodeList ;
  while (p != NULL) {
    const PMSInt32 activityIndex = p->mActivityIndex ;
    const PMSInt32 eoe = p->mActivityEndOfExecution ;
    if (outResponseTimeArray (activityIndex COMMA_HERE).mBestResponseTime > eoe) {
      outResponseTimeArray (activityIndex COMMA_HERE).mBestResponseTime = eoe ;
    }
    if (outResponseTimeArray (activityIndex COMMA_HERE).mWorstResponseTime < eoe) {
      outResponseTimeArray (activityIndex COMMA_HERE).mWorstResponseTime = eoe ;
    }
    p = p->mPtrToNextNode ;
  }
//--- Second method
  cActivityList::computeBestAndWorstResponseTime (otherMethodResponseTimeArray) ;
//--- Compare results
  for (PMSInt32 i=0 ; i<inActivitiesCount ; i++) {
    const bool ok = (outResponseTimeArray (i COMMA_HERE).mBestResponseTime == otherMethodResponseTimeArray (i COMMA_HERE).mBestResponseTime)
      && (outResponseTimeArray (i COMMA_HERE).mWorstResponseTime == otherMethodResponseTimeArray (i COMMA_HERE).mWorstResponseTime) ;
    if (! ok) {
      printf ("**** CHECK BEST AND WORST RESPONSE TIME ERROR for activity %ld :\n"
              "  [%ld, %ld] != [%ld, %ld]\n",
              i,
              outResponseTimeArray (i COMMA_HERE).mBestResponseTime,
              outResponseTimeArray (i COMMA_HERE).mWorstResponseTime,
              otherMethodResponseTimeArray (i COMMA_HERE).mBestResponseTime,
              otherMethodResponseTimeArray (i COMMA_HERE).mWorstResponseTime) ;
              fflush (stdout);
    }
  }
}
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
static void
internalDumpStructure (cActivitySchedule * inPtr) {
  cActivitySchedule * p = inPtr ;
  while (p != NULL) {
    if (! p->mMarked) {
      p->mMarked = true ;
      printf ("at 0x%08lX : activity %ld, duration : %ld, eoe : %ld, previous : 0x%08lX, other : 0x%08lX\n",
              (PMSInt32) p, p->mActivityIndex, p->mActivityDuration, p->mActivityEndOfExecution,
              (PMSInt32) p->mPtrToSameSchedule, (PMSInt32) p->mPtrToOtherSchedule) ;
      internalDumpStructure (p->mPtrToOtherSchedule) ;
    }
    p = p->mPtrToSameSchedule ;
  }
}
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
void
cActivityList::dumpSchedule (cResourceSchedule * inPtr) {
  unMark () ;
  cResourceSchedule * p = inPtr ;
  while (p != NULL) {
    printf ("------\n") ;
    internalDumpStructure (p->mActivityList.mPtrToFirstActivity) ;
    p = p->mPtrToOtherResource ;
  }
}
#endif

//---------------------------------------------------------------------------*

#ifndef FORGET_ACTIVITY_NODES
void cScheduleMap::
dumpStructure (void) {
  printf ("********** DUMP **********\n") ;
  printf ("Latest instant : %ld\n", mCurrentInstant) ;
  cActivityList::dumpSchedule (mResourceNodesList) ;
}
#endif

//---------------------------------------------------------------------------*
#ifndef FORGET_ACTIVITY_NODES
static void dumpStructure (void) {
  printf ("********** DUMP **********\n") ;
  cActivitySchedule * p = gPtrNodeList ;
  while (p != NULL) {
    printf ("at 0x%08lX : activity %ld, duration : %ld, eoe : %ld, previous : 0x%08lX, next :0x%08lX, other : 0x%08lX\n",
            (PMSInt32) p, p->mActivityIndex, p->mActivityDuration, p->mActivityEndOfExecution,
            (PMSInt32) p->mPtrToSameSchedule, (PMSInt32) p->mPtrToNextNode, (PMSInt32) p->mPtrToOtherSchedule) ;
            fflush (stdout);
    p = p->mPtrToNextNode ;
  }
}
#endif
//---------------------------------------------------------------------------*
//                                                                           *
//    H A N D L E    A N    I N P U T    F I L E                             *
//                                                                           *
//---------------------------------------------------------------------------*
static bool
WillRecieveHigherActivation(const cResourceSchedule * inPtr,
			                       const PMSInt32 inResourceCount,
			                       const PMSInt32 inSuccessorIndex,
			                       const PMSInt32 inCurrentInstant,
			                       const TC_UniqueArray <cActivity> & inActivities ) {
  
  bool WillReceive= false ;
   
  const PMSInt32 SuccessorResourceIndex =  inActivities (inSuccessorIndex COMMA_HERE).mResourceId ;
  const PMSInt32 SuccessorPriority = inActivities (inSuccessorIndex COMMA_HERE).mPriority ;
  const PMSInt32 SuccessorOffset = inActivities (inSuccessorIndex COMMA_HERE).mOffset ;
   
 //--- Test of any successor that has higher priority than the possible CA will be lunched!
  const bool AnyReadyAt= 
    	  inPtr->mArray (SuccessorResourceIndex COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ;
     //--- If yes, if the ready one is not higher priority--> Add successor
  if (AnyReadyAt){           
    const PMSInt32 HighestReadyAt=
        inPtr->mArray (SuccessorResourceIndex COMMA_HERE).mActivitiesToScheduleList.getFirstToSchedule (inCurrentInstant) ;
	  if ( inActivities (HighestReadyAt COMMA_HERE).mPriority < SuccessorPriority){
	 		WillReceive = true ;
    }
  }
  for(PMSInt32 index =0; (index<inResourceCount) && ! WillReceive; index++){
    const PMSInt32 currentActivity = inPtr->mArray (index COMMA_HERE).mCurrentActivity ;
    if (currentActivity >= 0){
      if ( inPtr->mArray (index COMMA_HERE).mExecutionCounter >=  
         (inActivities (currentActivity COMMA_HERE).mMaxDuration-SuccessorOffset)){
        const PMSInt32 successorIndex = inActivities (currentActivity COMMA_HERE).mSuccessorId ;
        if (successorIndex >= 0) {
	        if ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0){
	          const PMSInt32 successorResource = inActivities (successorIndex COMMA_HERE).mResourceId ;
		        const PMSInt32 successorPriority = inActivities (successorIndex COMMA_HERE).mPriority;
		        if ( (SuccessorResourceIndex == successorResource )
		           && 
		           (successorPriority < SuccessorPriority) ){
		               WillReceive = true;
		        }
		      }
	        PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
	        while ( (OtherHeirId >= 0) && !WillReceive ) {
            if ((inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0){
		          PMSInt32 const heirPriority = inActivities (OtherHeirId COMMA_HERE).mPriority;
			        PMSInt32 HeirResource = inActivities (OtherHeirId COMMA_HERE).mResourceId ;
			        if ( (SuccessorResourceIndex == HeirResource)
			           &&
		    	      (heirPriority < SuccessorPriority) ){
		    	          WillReceive = true;
		    	    }
		    	  }
	    	    OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId ;
		      }
	      }   
	    }
		}      
	}
	return  WillReceive;
}   
//---------------------------------------------------------------------------*
static PMSInt32 
LeastBusyDuration (const cResourceSchedule * inPtr,
                   const PMSInt32 leastBusyDuration,
                   const PMSInt32 inCurrentInstant,
                   const PMSInt32 inAdditionIndex,
                   const PMSInt32 inActivityIndex,
                   const PMSInt32 inResourceCount,
                   const TC_UniqueArray <cReadyAtThisInstant> & inReadyAtThisInstant,
                   const TC_UniqueArray <cActivity> & inActivities){
 
  PMSInt32 leastBusy =leastBusyDuration;
  PMSInt32 additionIndex = inAdditionIndex ;
  const PMSInt32 inActivityPriority = inActivities (inActivityIndex COMMA_HERE).mPriority; 
  //--- Include all independent Partitions in the busy period 
  while ( ( additionIndex < inReadyAtThisInstant.count())
         && 
        ((leastBusy + inCurrentInstant) >= inReadyAtThisInstant (additionIndex COMMA_HERE).mThisInstant) ){ 
    PMSInt32 nextActivityIndex = inReadyAtThisInstant (additionIndex COMMA_HERE). mActivityIndex;
    do{
       PMSInt32 inActivityResource = inActivities (inActivityIndex COMMA_HERE).mResourceId ;
       PMSInt32 nextActivityResource = inActivities (nextActivityIndex COMMA_HERE).mResourceId ;
       PMSInt32 priority = inActivities (nextActivityIndex COMMA_HERE).mPriority ;
       if ( (inActivityResource == nextActivityResource)
          &&(priority < inActivityPriority) ){
  	      	leastBusy += inActivities (nextActivityIndex COMMA_HERE).mMinDuration ;
	     }  
		   nextActivityIndex = inActivities (nextActivityIndex COMMA_HERE).mOtherReadyAtThisInst ;
	  }while( nextActivityIndex != -1 );
	  additionIndex ++;
  }
 //--- Add partitions from possible successors activated from other resources
  for(PMSInt32 index =0; index<inResourceCount; index++){
    const PMSInt32 currentActivity = inPtr->mArray (index COMMA_HERE).mCurrentActivity ;
    if (currentActivity >= 0){
 //--- If the CA on other resource certainely will be terminated after the busy period
      if ( inPtr->mArray (index COMMA_HERE).mExecutionCounter >=  (inActivities (currentActivity COMMA_HERE).mMaxDuration-leastBusy)){
        const PMSInt32 successorIndex = inActivities (currentActivity COMMA_HERE).mSuccessorId ;
        if ( successorIndex >= 0) {
          if ((inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0){
            //--- If the CA on the other resource has successor 
	          const PMSInt32 successorResource = inActivities (successorIndex COMMA_HERE).mResourceId ;
	          PMSInt32 successorPriority = inActivities (successorIndex COMMA_HERE).mPriority;
	          if ( inActivities (inActivityIndex COMMA_HERE).mResourceId == successorResource ){
              //--- and it is successor on the same resource
	            if (successorPriority < inActivityPriority ){
               //--- and has a higher priority than the activity that will be added --> add to busy period
	             leastBusy += inActivities (successorIndex COMMA_HERE).mMinDuration ;
	            }
	          }
	        }
 //--- Test of the current activity on the other resource has other successors, on the resource where the activity has to be added
	        PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
	        while (OtherHeirId >= 0 ){ 
	          if ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0){
		          PMSInt32 HeirPriority = inActivities (OtherHeirId COMMA_HERE).mPriority;
			        PMSInt32 HeirResource = inActivities (OtherHeirId COMMA_HERE).mResourceId ;
			        PMSInt32 inActivityResource = inActivities (inActivityIndex COMMA_HERE).mResourceId ;
			        if ( (inActivityResource == HeirResource) 
			           &&
		    	      (HeirPriority < inActivityPriority) ){
	                leastBusy += inActivities (OtherHeirId COMMA_HERE).mMinDuration ;
		    	    }
		    	  }
	    	    OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
		      }
	      }   
	    }
		}      
	}
  
 return leastBusy ;
}
//---------------------------------------------------------------------------*
static bool
HasToAddSuccessors (const cResourceSchedule * inPtr,
                    const PMSInt32 inResourceCount,
                    const PMSInt32 inAdditionIndex,
                    const TC_UniqueArray <cReadyAtThisInstant> & inReadyAtThisInstant,
			              const PMSInt32 inActivityIndex,
			              const PMSInt32 inCurrentInstant,
                    const TC_UniqueArray <cActivity> & inActivities ) {
  
  bool HasToAdd= false ; 
  PMSInt32 LeastBusyPeriod = 0 ;  
  const PMSInt32 SuccessorIndex = inActivities (inActivityIndex COMMA_HERE).mSuccessorId ;
  //--- Is any successor ?
  if (SuccessorIndex >= 0){ 
    if( (inActivities (SuccessorIndex COMMA_HERE).mOccurrence % inActivities (SuccessorIndex COMMA_HERE).mEvery) == 0 ){ 
      const PMSInt32 SuccessorResource = inActivities (SuccessorIndex COMMA_HERE).mResourceId ;
	    PMSInt32 SuccessorOffset =  inActivities (SuccessorIndex COMMA_HERE).mOffset ;
	    PMSInt32 SuccessorPriority = inActivities (SuccessorIndex COMMA_HERE).mPriority ;
      const PMSInt32 currentActivityOnSuccessurResource = inPtr->mArray (SuccessorResource COMMA_HERE).mCurrentActivity ;
      //--- Get the busy duration on the successor resource
      LeastBusyPeriod = 
        inPtr->mArray (SuccessorResource COMMA_HERE).mActivitiesToScheduleList.getMinimumBusyPeriod4Activity (SuccessorIndex,
                     inActivities);
                     
      LeastBusyPeriod = LeastBusyDuration (inPtr, LeastBusyPeriod, inCurrentInstant,
                                         inAdditionIndex, SuccessorIndex,
                                         inResourceCount,
                                         inReadyAtThisInstant, inActivities);   
                                         
      //--- The overall busy period is calculated

      if ( currentActivityOnSuccessurResource < 0 ){
        //--- if the successor resource is free: Does it will receive hiegher priority      
         
        bool willReceiveHihgerPriorityOnSuccResAtThisInst = 
      	           WillRecieveHigherActivation(inPtr, inResourceCount,
			                                         SuccessorIndex, inCurrentInstant,
			                                         inActivities);     
	      if (! willReceiveHihgerPriorityOnSuccResAtThisInst){
			    HasToAdd= true;
		    } 	
      }else if( (inPtr->mArray (SuccessorResource COMMA_HERE).mExecutionCounter + SuccessorOffset) >=
    			(inActivities (currentActivityOnSuccessurResource COMMA_HERE).mMinDuration + LeastBusyPeriod) ){
        //--- If it may be free, Test if any ready activity (at the addition instant) on that resource
        const bool AnyReadyAt= 
    	    inPtr->mArray (SuccessorResource COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ;
       //--- If yes, if the ready one is not higher priority--> Add successor
        if (AnyReadyAt){           
          const PMSInt32 HighestReadyAt=
            inPtr->mArray (SuccessorResource COMMA_HERE).mActivitiesToScheduleList.getFirstToSchedule (inCurrentInstant) ;
	        if ( (SuccessorPriority < inActivities (HighestReadyAt COMMA_HERE).mPriority )
	            ||
	            (SuccessorOffset >= inActivities (HighestReadyAt COMMA_HERE).mMinDuration ) ){
	          HasToAdd= true;
	        }
	      }else{
          //--- If no ready, add successor
	    	  HasToAdd= true;
	      }
      }
    }
//--- do the same for other heirs

		PMSInt32 OtherHeirId = inActivities (SuccessorIndex COMMA_HERE).mOtherHeirId ;
	  while ( (OtherHeirId >= 0) && !HasToAdd){ 
	    if( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ) {
			  PMSInt32 HeirResource = inActivities (OtherHeirId COMMA_HERE).mResourceId ;
			  PMSInt32 HeirOffset = inActivities (OtherHeirId COMMA_HERE).mOffset ;
			  PMSInt32 HeirPriority = inActivities (OtherHeirId COMMA_HERE).mPriority ;
				PMSInt32 currentActivityOnHeirResource = inPtr->mArray (HeirResource COMMA_HERE).mCurrentActivity ;
			
			  PMSInt32 
	        leastBusyPeriod = inPtr->mArray (HeirResource COMMA_HERE).mActivitiesToScheduleList.getMinimumBusyPeriod4Activity (OtherHeirId,
	                          inActivities);
	      leastBusyPeriod = LeastBusyDuration (inPtr, leastBusyPeriod, inCurrentInstant,
		                                         inAdditionIndex, OtherHeirId,
		                                         inResourceCount,
		                                         inReadyAtThisInstant, inActivities);   
				
			  if (currentActivityOnHeirResource < 0 ){
			    bool willReceiveHihgerPriorityOnHeirResAtThisInst = 
	      	               WillRecieveHigherActivation(inPtr, inResourceCount,
				                                             OtherHeirId, inCurrentInstant,
				                                             inActivities);      	
				  if (!willReceiveHihgerPriorityOnHeirResAtThisInst){
				  	  HasToAdd= true;
				  }
			  }else if( (inPtr->mArray (HeirResource COMMA_HERE).mExecutionCounter + HeirOffset) >=
		    			 (inActivities (currentActivityOnHeirResource COMMA_HERE).mMinDuration + leastBusyPeriod) ){
		    			 
			    const bool AnyReadyAt= 
	    	    inPtr->mArray (HeirResource COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ;

	        if (AnyReadyAt){
	          const PMSInt32 HighestReadyAt=
	            inPtr->mArray (HeirResource COMMA_HERE).mActivitiesToScheduleList.getFirstToSchedule (inCurrentInstant) ;

		        if ( (HeirPriority < inActivities (HighestReadyAt COMMA_HERE).mPriority )
		            ||
		            (HeirOffset >= inActivities (HighestReadyAt COMMA_HERE).mMinDuration ) ){
		          HasToAdd= true;
		        }
		      }else{
		      	 HasToAdd= true;
		      } 	
			 	}
			}
		  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
		}
	}
	
  return HasToAdd ;
}
/*--------------------------------------------------------------------------------------*/
static void
addSuccessors (cResourceSchedule * inPtr,
			         const PMSInt32 inActivityIndex,
               const TC_UniqueArray <cActivity> & inActivities,
               const PMSInt32 inCurrentInstant) {
             
  const PMSInt32 successorIndex = inActivities (inActivityIndex COMMA_HERE).mSuccessorId ;
           
  if (successorIndex >= 0) {
    if ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0 ){ 
			const PMSInt32 successorResource = inActivities (successorIndex COMMA_HERE).mResourceId ;
			const PMSInt32 successorOffset =  inActivities (successorIndex COMMA_HERE).mOffset ;
			inPtr->mArray (successorResource COMMA_HERE).mActivitiesToScheduleList.addEntry (successorIndex, 
										inActivities (successorIndex COMMA_HERE).mPriority,
						  			inCurrentInstant + successorOffset) ;
	  }
	  PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
    while (OtherHeirId >= 0) {
      if ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ){ 
		    const PMSInt32 HeirResource = inActivities (OtherHeirId COMMA_HERE).mResourceId ;
		    const PMSInt32 heirOffset = inActivities (OtherHeirId COMMA_HERE).mOffset ;
						 
		    inPtr->mArray (HeirResource COMMA_HERE).mActivitiesToScheduleList.addEntry (OtherHeirId, 
			 	  					  inActivities (OtherHeirId COMMA_HERE).mPriority,
			  						  inCurrentInstant + heirOffset) ;
			}
		  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
    }
	}
	
}
//---------------------------------------------------------------------------*
static bool 
IsOffsetTimeGTNextMinDur (const cResourceSchedule * inPtr, 
                          const TC_UniqueArray <cActivity> & inActivities,
                          const PMSInt32 inResourceIndex,
                          const PMSInt32 inCurrentInstant){
                          
	const PMSInt32 currentActivity = inPtr->mArray (inResourceIndex COMMA_HERE).mCurrentActivity ;
	PMSInt32 MaximumSuccessorOffset = 0 ;
  PMSInt32 HigestSuccessorPriority = PMSINT32_MAX ;
  bool WillReceiveNew = false;
  PMSInt32 successorIndex = inActivities (currentActivity COMMA_HERE).mSuccessorId ;
  if (successorIndex >= 0){
    if ( (inActivities (successorIndex COMMA_HERE).mOccurrence % inActivities (successorIndex COMMA_HERE).mEvery) == 0 ){   
		  PMSInt32 successorResource = inActivities (successorIndex COMMA_HERE).mResourceId ;
		  if (successorResource == inResourceIndex){
		  PMSInt32 successorOffset =  inActivities (successorIndex COMMA_HERE).mOffset ;
		  	MaximumSuccessorOffset = MAX( MaximumSuccessorOffset, successorOffset);
		  	HigestSuccessorPriority = min (HigestSuccessorPriority, inActivities (successorIndex COMMA_HERE).mPriority);
			}
	  }
	  PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId ;
	  while (OtherHeirId >= 0) {
	    if ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ){   
		  	PMSInt32 HeirResource = inActivities (OtherHeirId COMMA_HERE).mResourceId ;
		  	if (HeirResource == inResourceIndex){
		  		PMSInt32 heirOffset = inActivities (OtherHeirId COMMA_HERE).mOffset ;
		 			MaximumSuccessorOffset = MAX( MaximumSuccessorOffset, heirOffset);
		     	HigestSuccessorPriority = min (HigestSuccessorPriority, inActivities (OtherHeirId COMMA_HERE).mPriority);
		    }
		  }
			OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
		}
	  PMSInt32 HPA = 
	    inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.getFirstToSchedule (inCurrentInstant) ;
	  if ( ( (HPA == -1) && (MaximumSuccessorOffset != 0))
	      || 
	       ( (HPA != -1) && 
	       (inActivities (HPA COMMA_HERE).mMinDuration < MaximumSuccessorOffset)) ){ 
	     
			WillReceiveNew = true;
		}
	}
	return WillReceiveNew ;
}
//---------------------------------------------------------------------------*
static bool 
NewReadyInfluenceOnScheduling (const cResourceSchedule * inPtr, 
                               const TC_UniqueArray <cActivity> & inActivities,
                               const TC_UniqueArray <cReadyAtThisInstant> & inReadyAtThisInstant,
                               const PMSInt32 inAdditionIndex,
                               const PMSInt32 inResourceIndex,
                               const PMSInt32 inResourceCount,
                               const PMSInt32 inCurrentInstant){
   
  bool WillReceiveNew= false ; 
  PMSInt32 additionIndex = inAdditionIndex ; 
  bool AnyInsertedButNotReady = false;
  bool DirectSuccessor = false ;
  //--- If there is ready activity
  const PMSInt32 currentActivity = inPtr->mArray (inResourceIndex COMMA_HERE).mCurrentActivity ;
  const bool 
    AnyReadyAt= inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ;
  if (DependentActivitiesHasOffset){
    AnyInsertedButNotReady = inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.AnyNotReadyToScheduleAt (inCurrentInstant) ;
  }
  if (!AnyReadyAt){
    PMSInt32 lSuccessorId = inActivities (currentActivity COMMA_HERE).mSuccessorId ;
  	if (lSuccessorId >= 0){
  		if ((inActivities (lSuccessorId COMMA_HERE).mOffset == 0)
  		   &&
  		   (inResourceIndex == inActivities (lSuccessorId COMMA_HERE).mResourceId)){
  			DirectSuccessor = true;
  		}
  	}
  }
  //--- If all inserted activities are ready:   
  if ((AnyReadyAt || DirectSuccessor) && !AnyInsertedButNotReady){
     PMSInt32 HPAReadyAtInstant = 
      inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.getFirstScheduledInstant (inCurrentInstant);
    if (inCurrentInstant==HPAReadyAtInstant){
    	WillReceiveNew = true;
    }else{
      PMSInt32 MinimumHPBusyPeriod = 0;
      PMSInt32 MinimumBusyPeriod = 0;
     //  PMSInt32 PreviousPriority = PMSINT32_MAX; // Unused var ; commented out 1/1/2005
	    PMSInt32 MaximumBusyPeriod = inActivities (currentActivity COMMA_HERE).mMaxDuration -
	                               inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter;
	    MaximumBusyPeriod += 
	    	inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.getMaximumBusyPeriod (currentActivity, inActivities);    	
	 		PMSInt32 LowerPriorityActivity = inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.getLowerPriority (currentActivity, inActivities);
			
		  while (!WillReceiveNew 
		         &&
		         (additionIndex < inReadyAtThisInstant.count())
	           && 
	           ((MaximumBusyPeriod +inCurrentInstant) > inReadyAtThisInstant (additionIndex COMMA_HERE).mThisInstant) ){ 
	        PMSInt32 nextActivityIndex = inReadyAtThisInstant (additionIndex COMMA_HERE). mActivityIndex;
	        do{
	          PMSInt32 nextActivityResource = inActivities (nextActivityIndex COMMA_HERE).mResourceId ;
	          PMSInt32 activityPriority = inActivities (nextActivityIndex COMMA_HERE).mPriority;
	          if ( inResourceIndex == nextActivityResource){
	          	MinimumHPBusyPeriod = inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.getMinimumBusyPeriod4Activity (nextActivityIndex, inActivities);
	 						SuccessorsMinBusyDuration4Activity (MinimumHPBusyPeriod, currentActivity, 
	 						                                    inResourceIndex, activityPriority,
	 						                                    inActivities);
	 						if ( (MinimumHPBusyPeriod + inCurrentInstant) >= inReadyAtThisInstant (additionIndex COMMA_HERE).mThisInstant){
				      	LowerPriorityActivity = MAX(LowerPriorityActivity, activityPriority);
			         	LowerPriorityOnResource(LowerPriorityActivity, nextActivityIndex, inResourceIndex, inActivities); 
				      	MaximumBusyPeriod += inActivities (nextActivityIndex COMMA_HERE).mMaxDuration;
				      	SuccessorsMaxBusyDuration( MaximumBusyPeriod, nextActivityIndex, inResourceIndex, inActivities);  
				      	if (MinimumBusyPeriod ==0 ){
				      		MinimumBusyPeriod = MinimumHPBusyPeriod + inActivities (nextActivityIndex COMMA_HERE).mMinDuration;
				      	}else{
				      		MinimumBusyPeriod += inActivities (nextActivityIndex COMMA_HERE).mMinDuration;
				      	}
			      		SuccessorsMinBusyDuration(MinimumBusyPeriod, nextActivityIndex, inResourceIndex, inActivities);
							}else if( (activityPriority >= LowerPriorityActivity)
							         &&
							         ((MinimumBusyPeriod + inCurrentInstant) >= inReadyAtThisInstant (additionIndex COMMA_HERE).mThisInstant) ){
					  	  MaximumBusyPeriod += inActivities (nextActivityIndex COMMA_HERE).mMaxDuration;
					  	  SuccessorsMaxBusyDuration( MaximumBusyPeriod, nextActivityIndex, inResourceIndex, inActivities); 
					  	  MinimumBusyPeriod += inActivities (nextActivityIndex COMMA_HERE).mMinDuration;
					  	  SuccessorsMinBusyDuration(MinimumBusyPeriod, nextActivityIndex, inResourceIndex, inActivities);
							  LowerPriorityActivity = MAX(LowerPriorityActivity, activityPriority);
							  LowerPriorityOnResource(LowerPriorityActivity, nextActivityIndex, inResourceIndex, inActivities); 
							}else{
								WillReceiveNew= true; 
							}
	          } 
	          nextActivityIndex = inActivities (nextActivityIndex COMMA_HERE).mOtherReadyAtThisInst ;
	        }while(! WillReceiveNew && (nextActivityIndex != -1) );
	        additionIndex ++;
	    }
	  	  		  
		  if (!WillReceiveNew){
		  	if( !NoInterdependenceButUseB){
			  	for (PMSInt32 index = 0 ; (index < inResourceCount) && ! WillReceiveNew ; index++){
			  	  if (index != inResourceIndex){
			      	const PMSInt32 resCurrentActivity = inPtr->mArray (index COMMA_HERE).mCurrentActivity ;
			  			if (resCurrentActivity >= 0){
			  		  	PMSInt32 CertainFutureBusyDuration = 
			  		    	inActivities (resCurrentActivity COMMA_HERE).mMinDuration-inPtr->mArray (index COMMA_HERE).mExecutionCounter;
			  				
			  				CertainFutureBusyDuration =MAX(0, CertainFutureBusyDuration);
			  				if (CertainFutureBusyDuration < MaximumBusyPeriod ){
			  				 	PMSInt32 successorId = inActivities (resCurrentActivity COMMA_HERE).mSuccessorId;
			  					if (successorId >= 0){
			  					  if ( (inActivities (successorId COMMA_HERE).mOccurrence % inActivities (successorId COMMA_HERE).mEvery) == 0 ){   
			  						  PMSInt32 successorResource = inActivities (successorId COMMA_HERE).mResourceId;
			  						  if (successorResource == inResourceIndex){
			  							  WillReceiveNew = true;
			  						  }else if( (inActivities (successorId COMMA_HERE).mMinDuration + CertainFutureBusyDuration) < MaximumBusyPeriod  ){
			  							  WillReceiveNew = true;
			  							}
			  						}else if ( !WillReceiveNew && (ResourceMinDuration[index]+ CertainFutureBusyDuration) < MaximumBusyPeriod ){
			  				      WillReceiveNew = true;
			  					  }
			  						
			  						PMSInt32 OtherHeirId = inActivities (successorId COMMA_HERE).mOtherHeirId ;
    								while (OtherHeirId >= 0) {
	    							  PMSInt32 HeirResource = inActivities (OtherHeirId COMMA_HERE).mResourceId ;
	                    if ( (inActivities (OtherHeirId COMMA_HERE).mOccurrence % inActivities (OtherHeirId COMMA_HERE).mEvery) == 0 ){   
			  			          if (HeirResource == inResourceIndex){
			  							    WillReceiveNew = true;
			  						    }else	if( (inActivities (OtherHeirId COMMA_HERE).mMinDuration + CertainFutureBusyDuration) < MaximumBusyPeriod  ){
			  								  WillReceiveNew = true;
			  						    }
			  						  }else if ( !WillReceiveNew && (ResourceMinDuration[index]+ CertainFutureBusyDuration) < MaximumBusyPeriod ){
			  				        WillReceiveNew = true;
			  					    }
		                  OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
                    }
			  					}else if ( !WillReceiveNew && (ResourceMinDuration[index]+ CertainFutureBusyDuration) < MaximumBusyPeriod ){
			  				    WillReceiveNew = true;
			  					}
			  				}
			  			}else if (ResourceMinDuration[inResourceIndex] < MaximumBusyPeriod ){
			  			  WillReceiveNew = true;  
			  			}
			  		}else{ 
			  		  /*if(index == inResourceIndex) { //If the resource will chgange context on others
			  		  //--- 
			  		  for (PMSInt32 i = 0 ; (i < inResourceCount) && ! WillReceiveNew ; i++){
			  		    PMSInt32 CertainFutureDuration = 0 ;
			  		    if (i != inResourceIndex){
			      	    resCurrentActivity = inPtr->mArray (i COMMA_HERE).mCurrentActivity ;
			  		      if (currentActivity >= 0){
			  		  	    CertainFutureDuration = 
			  		    	    inActivities (currentActivity COMMA_HERE).mMinDuration-inPtr->mArray (i COMMA_HERE).mExecutionCounter;
			  				
			  				    CertainFutureDuration =MAX(0, CertainFutureDuration);
			  				  }
			  				  CertainFutureDuration += ResourceMinDuration[i]; 
			  				  if (CertainFutureDuration <= MaximumBusyPeriod ){
			  					  WillReceiveNew = true; 
			  		      }
			  		    } 
			  		  }*/
			  		}
			    }	    
			  }else if (DependentActivitiesHasOffset){ //NoInterdependenceButUseB
					WillReceiveNew = 
					 IsOffsetTimeGTNextMinDur( inPtr, inActivities, inResourceIndex, inCurrentInstant);
			  }
		  }
	  }
	}
  return WillReceiveNew ; 
}
//---------------------------------------------------------------------------*
static void
recursiveOP (cResourceSchedule * inPtr,
             const PMSInt32 inResourceIndex,
             const PMSInt32 inAdditionIndex,
             const TC_UniqueArray <cActivity> & inActivities,
             const PMSInt32 inCurrentInstant,
             const TC_UniqueArray <cReadyAtThisInstant> & inReadyAtThisInstant,
             cScheduleMap & ioScheduleMap,
             #ifdef FORGET_ACTIVITY_NODES
               TC_UniqueArray <cResponseTime> & ioResponseTimeArray,
             #endif
             const PMSInt32 inResourceCount) {
           
  if (inResourceIndex == inResourceCount) {
    bool terminated = true ;
    for (PMSInt32 i=0 ; i<inResourceCount ; i++) {
      if (inPtr->mArray (i COMMA_HERE).mCurrentActivity < 0) {
        inPtr->mArray (i COMMA_HERE).mCurrentActivity = inPtr->mArray (i COMMA_HERE).mActivitiesToScheduleList.getFirstToScheduleAndSuppress (inCurrentInstant) ;
        if (inPtr->mArray (i COMMA_HERE).mCurrentActivity < 0){
        	inPtr->mArray (i COMMA_HERE).mHasNoNewActivities = false;
        	inPtr->mArray (i COMMA_HERE).mLHBound = 0;
        }
      }
      if (inPtr->mArray (i COMMA_HERE).mCurrentActivity >= 0) {
         inPtr->mArray (i COMMA_HERE).mExecutionCounter ++ ;  
        terminated = false ;
      }else if (terminated && ! inPtr->mArray (i COMMA_HERE).mActivitiesToScheduleList.isListEmpty ()) {
        terminated = false ;
      }
    }
    
    if (terminated) {
      #ifndef FORGET_ACTIVITY_NODES
        gScheduleResults.mergeList (inPtr->mActivityList) ;
      #endif
      disposeResourceNode (inPtr) ;
    }else{
      ioScheduleMap.insert (inResourceCount, inPtr) ;
   }
  }else{
    const PMSInt32 currentActivity = inPtr->mArray (inResourceIndex COMMA_HERE).mCurrentActivity ;
    if (currentActivity < 0) {
     	recursiveOP (inPtr,
                   inResourceIndex + 1,
                   inAdditionIndex,
                   inActivities,
                   inCurrentInstant,
                   inReadyAtThisInstant,
                   ioScheduleMap,
                   #ifdef FORGET_ACTIVITY_NODES
                     ioResponseTimeArray,
                   #endif
                   inResourceCount) ;
    }else if (inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter < inActivities (currentActivity COMMA_HERE).mMinDuration) {
      
      recursiveOP (inPtr,
                   inResourceIndex + 1,
                   inAdditionIndex,
                   inActivities,
                   inCurrentInstant,
                   inReadyAtThisInstant,
                   ioScheduleMap,
                   #ifdef FORGET_ACTIVITY_NODES
                     ioResponseTimeArray,
                   #endif
                   inResourceCount) ;
    }else if (inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter == inActivities (currentActivity COMMA_HERE).mMaxDuration) {
      #ifndef FORGET_ACTIVITY_NODES
        inPtr->mActivityList.push (currentActivity, inCurrentInstant, inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter) ;
      #else
        if (ioResponseTimeArray (currentActivity COMMA_HERE).mBestResponseTime > inCurrentInstant) {
          ioResponseTimeArray (currentActivity COMMA_HERE).mBestResponseTime = inCurrentInstant ;
        }
        if (ioResponseTimeArray (currentActivity COMMA_HERE).mWorstResponseTime < inCurrentInstant) {
          ioResponseTimeArray (currentActivity COMMA_HERE).mWorstResponseTime = inCurrentInstant ;
        }
      #endif
      
      if (inActivities (currentActivity COMMA_HERE).mSuccessorId >= 0) {
      	addSuccessors (inPtr, currentActivity, inActivities, inCurrentInstant) ;
      }
      gAllocatedActivityNodesCount ++;
      inPtr->mArray (inResourceIndex COMMA_HERE).mCurrentActivity = -1 ;
      inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter = 0 ;
      recursiveOP (inPtr,
                    inResourceIndex + 1,
                    inAdditionIndex,
                    inActivities,
                    inCurrentInstant, 
                    inReadyAtThisInstant,
                    ioScheduleMap,
                    #ifdef FORGET_ACTIVITY_NODES
                      ioResponseTimeArray,
                    #endif
                    inResourceCount) ;             
    
    }else if ((inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter % inPtr->mArray (inResourceIndex COMMA_HERE).mStep) != 0 ){
    	 recursiveOP (inPtr,
                   inResourceIndex + 1,
                   inAdditionIndex,
                   inActivities,
                   inCurrentInstant,
                   inReadyAtThisInstant,
                   ioScheduleMap,
                   #ifdef FORGET_ACTIVITY_NODES
                     ioResponseTimeArray,
                   #endif
                   inResourceCount);
    }else{
          
      #ifdef FORGET_ACTIVITY_NODES
        if (ioResponseTimeArray (currentActivity COMMA_HERE).mBestResponseTime > inCurrentInstant) {
          ioResponseTimeArray (currentActivity COMMA_HERE).mBestResponseTime = inCurrentInstant ;
        }
       if (ioResponseTimeArray (currentActivity COMMA_HERE).mWorstResponseTime < inCurrentInstant) {
          ioResponseTimeArray (currentActivity COMMA_HERE).mWorstResponseTime = inCurrentInstant ;
        }
      #endif
  		
  		bool HasToAdd=false;
  		bool MarkLowerAndHigherBound=false;
      bool NewActivationDuringBusyPeriod =false ;
      bool ThereIsReady = false ;
      //--- Test if the busy period (BP) is already tested & there is new activation during it
      PMSInt32 SuccessorId = inActivities (currentActivity COMMA_HERE).mSuccessorId ;
      if (! inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities){
         NewActivationDuringBusyPeriod = 
            NewReadyInfluenceOnScheduling (inPtr, inActivities,
	         	  													   inReadyAtThisInstant,
	         																 inAdditionIndex,
	                                         inResourceIndex, inResourceCount, 
	                                         inCurrentInstant);
	        
	      //--- If no activation during BP:
	      ThereIsReady = 
	        inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ;
	      if (!ThereIsReady){
  				if ( (SuccessorId >= 0) 
  				    && 
  				    !DependentActivitiesHasOffset
  				    &&
  				    NoInterdependenceButUseB
  				    &&
  				    (inResourceIndex == inActivities (SuccessorId COMMA_HERE).mResourceId)){
  						ThereIsReady = true;
  				}
  			}
        if(! NewActivationDuringBusyPeriod && ThereIsReady){
	        inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities = true;
	      } 
	      
	      if (inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities
	          &&
	          (inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound == 0) ){
	        MarkLowerAndHigherBound = true;
	      }
	    }
   	    
   	  if (! NewActivationDuringBusyPeriod){
        if( inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities
           &&
		       (inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter == 
		        inActivities (currentActivity COMMA_HERE).mMinDuration)) {
		        NewActivationDuringBusyPeriod = true;
	      }else if( ! inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities ){
	        ThereIsReady = 
		        inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ;
	        if(ThereIsReady){
	          NewActivationDuringBusyPeriod = true;
	        }
	      }
	    } 
   	   		   	   
      if (! NewActivationDuringBusyPeriod && (SuccessorId >= 0)){
      	HasToAdd = HasToAddSuccessors (inPtr, inResourceCount, inAdditionIndex,
                                       inReadyAtThisInstant, currentActivity, 
                                       inCurrentInstant, inActivities);    
                                       
      	bool NotZeroOffsetOnSameResource =false;
      	PMSInt32 SuccessorResource = inActivities (SuccessorId COMMA_HERE).mResourceId ;
      	if ( DependentActivitiesHasOffset
      	    &&
      	    (SuccessorResource == inResourceIndex)
      	    && 
      	    (inActivities (SuccessorId COMMA_HERE).mOffset != 0) ){
	  				NotZeroOffsetOnSameResource = IsOffsetTimeGTNextMinDur( inPtr, inActivities, inResourceIndex, inCurrentInstant);
	  		}      	
      	//--- Test if there is a successor on the same resource with offset != 0
      	if ( DependentActivitiesHasOffset
      	     &&
      	     inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities
      	     && 
      	     NotZeroOffsetOnSameResource 
      	     && 
      	     (HasToAdd 
      	      || 
      	      (inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter == (inActivities (currentActivity COMMA_HERE).mMaxDuration -1 ) )
       	      ) ){ 
          //--- If the successor on the same resource will not inserted directlly: change the flag
      		inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities = false;
      		inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound = 0 ;
      	}		
      }
     	    
	    if ( (SuccessorId < 0)
            &&
            (inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound == 1)
            &&
            (inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter == 
              (inActivities (currentActivity COMMA_HERE).mMaxDuration -1 ) ) ){
        bool AnyReadyInAL = inPtr->mArray (inResourceIndex COMMA_HERE).mActivitiesToScheduleList.AnyReadyToScheduleAt (inCurrentInstant) ; ;
        //--- change the flag
        if(!AnyReadyInAL){
      	  inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities = false;
      		inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound = 0 ;
      	}
      }
	    
      if( HasToAdd || NewActivationDuringBusyPeriod ){ 
               
	      if ( NoInterdependenceButUseB
	           &&
	           inPtr->mArray (inResourceIndex COMMA_HERE).mHasNoNewActivities
	           &&
	           (inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound != 0) ){
	       
	          if ( inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound ==-1){
	            #ifndef FORGET_ACTIVITY_NODES
                inPtr->mActivityList.push (currentActivity, inCurrentInstant, inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter) ;
             	#endif 
             	gAllocatedActivityNodesCount ++;       
	        	  if (SuccessorId >= 0) {
		            addSuccessors (inPtr, currentActivity, inActivities, inCurrentInstant) ;
		          }
	        	  inPtr->mArray (inResourceIndex COMMA_HERE).mCurrentActivity = -1 ;
          	  inPtr->mArray (inResourceIndex COMMA_HERE).mExecutionCounter = 0 ; 
            }
            
            recursiveOP (inPtr, 
                         inResourceIndex + 1,
                         inAdditionIndex,
                         inActivities,
	                       inCurrentInstant, 
	                       inReadyAtThisInstant,
	                       ioScheduleMap,
	                       #ifdef FORGET_ACTIVITY_NODES
	                         ioResponseTimeArray,
	                       #endif
	                       inResourceCount) ;
	      
	      }else{
	        if (MarkLowerAndHigherBound){
		        inPtr->mArray (inResourceIndex COMMA_HERE).mLHBound = 1;
		      } 
		  	  cResourceSchedule *  resourceSchedule = allocResourceNode (inResourceCount) ;
		  	  
	    		for (PMSInt32 i=0 ; i<inResourceCount ; i++) {
		  		  resourceSchedule->mArray (i COMMA_HERE) = inPtr->mArray (i COMMA_HERE);
		  	  }
		  	  #ifndef FORGET_ACTIVITY_NODES
	       	  resourceSchedule->mActivityList = inPtr->mActivityList ;
	     			resourceSchedule->mActivityList.push (currentActivity, inCurrentInstant, resourceSchedule->mArray (inResourceIndex COMMA_HERE).mExecutionCounter) ;
	    		#endif
	    		gAllocatedActivityNodesCount ++;
	    		if (SuccessorId >= 0) {
		         addSuccessors (resourceSchedule, currentActivity, inActivities, inCurrentInstant) ;
		      }
		        
		      resourceSchedule->mArray (inResourceIndex COMMA_HERE).mCurrentActivity = -1 ;
          resourceSchedule->mArray (inResourceIndex COMMA_HERE).mExecutionCounter = 0 ;
    			
    			if (MarkLowerAndHigherBound){
	          resourceSchedule->mArray (inResourceIndex COMMA_HERE).mLHBound = -1;
	        }
	         
	        recursiveOP (resourceSchedule, 
		                   inResourceIndex + 1,
		                   inAdditionIndex,
	                     inActivities, inCurrentInstant, 
	                     inReadyAtThisInstant,
	                     ioScheduleMap,
				               #ifdef FORGET_ACTIVITY_NODES
				                 ioResponseTimeArray,
				               #endif
				               inResourceCount) ;
	      
	        recursiveOP (inPtr, 
	                     inResourceIndex + 1,
	                     inAdditionIndex,
	                     inActivities,
		                   inCurrentInstant, 
		                   inReadyAtThisInstant,
		                   ioScheduleMap,
		                   #ifdef FORGET_ACTIVITY_NODES
		                     ioResponseTimeArray,
		                   #endif
		                   inResourceCount) ;
	      } 
		  }else{      
		  // No cloning               
	    //--- First op : continue
	              
		     recursiveOP (inPtr,
				              inResourceIndex + 1,
				              inAdditionIndex,
				              inActivities,
				              inCurrentInstant, 
				              inReadyAtThisInstant,
				              ioScheduleMap,
				              #ifdef FORGET_ACTIVITY_NODES
				                ioResponseTimeArray,
				              #endif
				              inResourceCount) ;
		  } 
    }
  }
}
//---------------------------------------------------------------------------*

void
scheduleActivities (const PMSInt32 NoInterButUseB,
                    const bool DependentHasOffset,
                    const TC_UniqueArray <cReadyAtThisInstant> & ReadyAtThisInstant, 
                    const TC_UniqueArray <cActivity> & inActivities,
                    const TC_UniqueArray <cResource> & inResource,
                    TC_UniqueArray <cResponseTime> & outResponseTimeArray) {
 
  const PMSInt32 inResourceCount = inResource.count ();
  const PMSInt32 activitiesCount = inActivities.count () ;
  outResponseTimeArray.makeRoom (activitiesCount) ;
  outResponseTimeArray.addObjects (activitiesCount, cResponseTime ()) ;
  
  DependentActivitiesHasOffset = DependentHasOffset ;
  if (NoInterButUseB==1){
  	NoInterdependenceButUseB = true;
  }else{
  	NoInterdependenceButUseB = false;
  }
  for (PMSInt32 i = 0; i< inResourceCount ;i++){
  	ResourceMinDuration[i]= inResource(i COMMA_HERE).mMinDuration;
  }
  
  const PMSInt32 NumberOfIndependentInsertion =  ReadyAtThisInstant.count();
  const PMSInt32 lastActivityScheduleInstant = 
  						 ReadyAtThisInstant ((NumberOfIndependentInsertion-1) COMMA_HERE).mThisInstant ;
  cScheduleMap scheduleMap (inResourceCount, lastActivityScheduleInstant, inActivities) ;
  PMSInt32 AdditionIndex=0;
//--- Perform activities scheduling
  C_Timer Timer ;
  while (scheduleMap.moreWorkToDo ()) {
    
    cResourceSchedule * list = scheduleMap.retrieveResourceList () ;
    //--- Insert independent released activities    
    if ((AdditionIndex < NumberOfIndependentInsertion)
       &&
       (ReadyAtThisInstant (AdditionIndex COMMA_HERE).mThisInstant == scheduleMap.getCurrentInstant ())) {
      if (list == NULL) {
		    list = allocResourceNode (inResourceCount) ;
        for (PMSInt32 i=0 ; i<inResourceCount ; i++) {
          list->mArray (i COMMA_HERE).mActivitiesToScheduleList.setToEmptyList () ;
          list->mArray (i COMMA_HERE).mExecutionCounter = 0 ;
          list->mArray (i COMMA_HERE).mCurrentActivity = -1 ;
          list->mArray (i COMMA_HERE).mHasNoNewActivities=false ;
          list->mArray (i COMMA_HERE).mLHBound = 0 ;
          list->mArray (i COMMA_HERE).mStep = inResource (i COMMA_HERE).mStep ;
        }
      }
     
      const PMSInt32 AddedActivityIndex = ReadyAtThisInstant (AdditionIndex COMMA_HERE).mActivityIndex ;
      cResourceSchedule * p = list ;
      while (p != NULL) {
	      scheduleMap.AddToScheduleMap (p, AddedActivityIndex, inActivities);
        p= p->mPtrToOtherResource ;
      }
      AdditionIndex ++;
    }
    
     PMSInt32 nodeCount = 0 ;
    { cResourceSchedule * p = list ;
      while (p != NULL) {
        nodeCount ++ ;
        p = p->mPtrToOtherResource ;
      }
    }
//    dumpSchedule (p) ;
            
   {  cResourceSchedule * p = list ;
      while (p != NULL) {
    //--- Retrieve resource node from list
        cResourceSchedule * q = p->mPtrToOtherResource ;
        p->mPtrToOtherResource = NULL ;
    //--- Check if the coning has to be done!   
         recursiveOP (p, 0, AdditionIndex, 
        						 inActivities, scheduleMap.getCurrentInstant (),
        						 ReadyAtThisInstant,
      	  					 scheduleMap, 
      		  				 #ifdef FORGET_ACTIVITY_NODES
      			  			   outResponseTimeArray, 
      				  		 #endif
      					  	 inResourceCount) ;
        p = q ;
      }
    }
    
	  PMSInt32 devisor=100000;
	  if(nodeCount >500000){
	  	devisor = 1 ;
	  }else if (nodeCount >100000){
	  devisor = 20;
	  }else if (nodeCount >40000){
	   devisor = 50;
	  }else if (nodeCount >10000){
	   devisor = 100;
	  }else if (nodeCount >1000){
	  devisor = 500;
	  }
    const PMSInt32 currentInstant = scheduleMap.getCurrentInstant () ;
    if ( (currentInstant != 0) && ((currentInstant % devisor) == 0)) {
      co << "currentInstant " 
         << cStringWithSigned (currentInstant)
         << ", " << cStringWithSigned (nodeCount) << " resource nodes, "
         << Timer
         << "\n" ;
      co.flush () ;
    }
    scheduleMap.advanceToNextInstant () ;
  }
 
//--- Dump data structure
#ifndef FORGET_ACTIVITY_NODES
 dumpStructure () ;
#endif
//--- Build response time array
  #ifndef FORGET_ACTIVITY_NODES
    scheduleMap.computeBestAndWorstResponseTime (outResponseTimeArray, activitiesCount) ;
  #endif
    
  co << cStringWithSigned (gUsedResourceNodesCount) << " resource nodes used, " << cStringWithSigned (gAllocatedResourceNodesCount) << " allocated.\n" ;
 // #ifndef FORGET_ACTIVITY_NODES
    co << cStringWithSigned (gAllocatedActivityNodesCount) << " activity nodes allocated.\n" ;
 // #endif
}

/*------------------------------------------------------------------------*/
