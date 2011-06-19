//---------------------------------------------------------------------------*
//                                                                           *
//  Main program for CAN message scheduler                                   *
//                                                                           *
//  Copyright (C) 2002 Pierre Molinaro (started august 8th, 2002).           *
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

#include "C_activitiesToSchedule.h"
#include "activities_core.h"

//---------------------------------------------------------------------------*

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

//---------------------------------------------------------------------------*
//                                                                           *
//    c A c t i v i t y S c h e d u l e                                      *
//                                                                           *
//---------------------------------------------------------------------------*

class cIndependantResourcesActivitySchedule {
  public : PMSInt32 mActivityIndex ;
  public : PMSInt32 mActivityDuration ;
  public : PMSInt32 mActivityEndOfExecution ;
  public : cIndependantResourcesActivitySchedule * mPtrToOtherSchedule ;
  public : cIndependantResourcesActivitySchedule * mPtrToPreviousActivity ;
  public : cIndependantResourcesActivitySchedule * mPtrToNextNode ;
  public : bool mMarked ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//    c R e s o u r c e S c h e d u l e                                      *
//                                                                           *
//---------------------------------------------------------------------------*

class cIndependantResourceSchedule  {
  public : PMSInt32 mResourceIndex ;
  public : C_activitiesToSchedule mActivitiesToScheduleList ;
  public : cIndependantResourceSchedule  * mPtrToOtherResource ;
  public : cIndependantResourcesActivitySchedule * mPtrToFirstActivity ;
  public : cIndependantResourcesActivitySchedule * mPtrToLastActivity ;
  
  public : cIndependantResourceSchedule (void) ;
  
  private : cIndependantResourceSchedule (const cIndependantResourceSchedule &) ;
  private : cIndependantResourceSchedule & operator = (const cIndependantResourceSchedule &) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//    c R e s o u r c e S c h e d u l e M a p                                *
//                                                                           *
//---------------------------------------------------------------------------*

class cIndependantResourcesScheduleMap {
  private : TC_UniqueArray <cIndependantResourceSchedule  *> mResourceScheduleArray ;
  private : PMSInt32 mCurrentInstant ;
  private : PMSInt32 mLatestInstant ;

//--- Constructor
  public : cIndependantResourcesScheduleMap (void) ;

//--- Enter an activity to schedule
 public : void enterActivity (const PMSInt32 inActivityIndex,
                              const PMSInt32 inActivityPriority,
                              const PMSInt32 inActivityReadyAt,
                              const PMSInt32 inRessourceIndex) ;
  
//--- More work ?
  public : bool moreWorkToDo (void) const ;
  public : inline PMSInt32 getCurrentInstant (void) const { return mCurrentInstant ; }
  public : inline PMSInt32 getFarestInstant (void) const { return mLatestInstant ; }
  public : cIndependantResourceSchedule  * retrieveResourceList (void) ;
  public : void insertAtNextInstant (cIndependantResourceSchedule  * inResource) ;
  public : void advanceToNextInstant (void) ;
  public : void dumpStructure (void) ;
  public : void insertAtInstant (cIndependantResourceSchedule  * inResource,
                                 const PMSInt32 inInstant) ;
  public : void computeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & ioResponseTimeArray) ;
  protected : void reallocIfNeeded (const PMSInt32 inInstant) ;

} ;

//---------------------------------------------------------------------------*

cIndependantResourceSchedule::cIndependantResourceSchedule (void) :
mResourceIndex (0),
mActivitiesToScheduleList (),
mPtrToOtherResource (NULL),
mPtrToFirstActivity (NULL),
mPtrToLastActivity (NULL) {
}

//---------------------------------------------------------------------------*

static cIndependantResourceSchedule * gResourceFreeList = NULL ;
static PMSInt32 gAllocatedResourceNodesCount = 0 ;
static PMSInt32 gUsedResourceNodesCount = 0 ;
static PMSInt32 gAllocatedActivityNodesCount = 0 ;

//---------------------------------------------------------------------------*

static inline cIndependantResourceSchedule  * allocResourceNode (void) {
  gUsedResourceNodesCount ++ ;
  cIndependantResourceSchedule  * p = gResourceFreeList ;
  if (p == NULL) {
    p = new cIndependantResourceSchedule  ;
    gAllocatedResourceNodesCount ++ ;
  }else{
    gResourceFreeList = p->mPtrToOtherResource ;
    p->mPtrToOtherResource = NULL ;
  }
  return p ;
}

//---------------------------------------------------------------------------*

static inline void disposeResourceNode (cIndependantResourceSchedule  * inPtr) {
  inPtr->mPtrToOtherResource = gResourceFreeList ;
  gResourceFreeList = inPtr ;
}

//---------------------------------------------------------------------------*

cIndependantResourcesScheduleMap::cIndependantResourcesScheduleMap (void) :
mResourceScheduleArray (),
mCurrentInstant (0),
mLatestInstant (0) {
}

//---------------------------------------------------------------------------*

#define EXTRA 1000

void cIndependantResourcesScheduleMap::
reallocIfNeeded (const PMSInt32 inInstant) {
//--- Realloc schedule map ?
  if (inInstant >= mResourceScheduleArray.count ()) {
    const PMSInt32 actualCount = mResourceScheduleArray.count () ;
    const PMSInt32 newCount = inInstant + EXTRA + 1 ;
    mResourceScheduleArray.addObjects (newCount - actualCount, NULL) ;
  }
}

//---------------------------------------------------------------------------*

void cIndependantResourcesScheduleMap::
enterActivity (const PMSInt32 inActivityIndex,
               const PMSInt32 inActivityPriority,
               const PMSInt32 inActivityReadyAt,
               const PMSInt32 inRessourceIndex) {
//--- Realloc schedule map ?
  reallocIfNeeded (inActivityReadyAt) ;
//--- Is instant is far than farest ?
  if (mLatestInstant < inActivityReadyAt) {
    mLatestInstant = inActivityReadyAt ;
  }
//--- Find a node for resource
  cIndependantResourceSchedule  * p = mResourceScheduleArray (0 COMMA_HERE) ;
  while ((p != NULL) && (p->mResourceIndex != inRessourceIndex)) {
    p = p->mPtrToOtherResource ;
  }
//--- If not found, insert a new node
  if (p == NULL) {
    p = allocResourceNode () ;
    p->mResourceIndex = inRessourceIndex ;
    p->mPtrToFirstActivity = NULL ;
    p->mPtrToLastActivity = NULL ;
    p->mPtrToOtherResource = mResourceScheduleArray (0 COMMA_HERE) ;
    mResourceScheduleArray (0 COMMA_HERE) = p ;
  }
//--- Insert activity into activity list
  p->mActivitiesToScheduleList.addEntry (inActivityIndex, inActivityPriority, inActivityReadyAt) ;
}

//---------------------------------------------------------------------------*

bool cIndependantResourcesScheduleMap::moreWorkToDo (void) const {
  bool moreWork = mLatestInstant > mCurrentInstant ;
  cIndependantResourceSchedule  * p = mResourceScheduleArray (mCurrentInstant COMMA_HERE) ;
  while ((p != NULL) && ! moreWork) {
    moreWork = ! p->mActivitiesToScheduleList.isListEmpty () ;
    p = p->mPtrToOtherResource ;
  }
  return moreWork ;
}

//---------------------------------------------------------------------------*

cIndependantResourceSchedule  * cIndependantResourcesScheduleMap::retrieveResourceList (void) {
  cIndependantResourceSchedule  * p = mResourceScheduleArray (mCurrentInstant COMMA_HERE) ;
  if (p != NULL) {
//    printf ("Retrieve at %ld\n", mCurrentInstant) ;
  }
  mResourceScheduleArray (mCurrentInstant COMMA_HERE) = NULL ;
  return p ;
}

//---------------------------------------------------------------------------*

void cIndependantResourcesScheduleMap::advanceToNextInstant (void) {
  mCurrentInstant ++ ;
}

//---------------------------------------------------------------------------*

void cIndependantResourcesScheduleMap::insertAtNextInstant (cIndependantResourceSchedule  * inResource) {
  insertAtInstant (inResource, mCurrentInstant+1) ;
}

//---------------------------------------------------------------------------*

void cIndependantResourcesScheduleMap::
insertAtInstant (cIndependantResourceSchedule  * inResource,
                 const PMSInt32 inInstant) {
//  printf ("Insert at %ld\n", inInstant) ;
//--- Realloc schedule map ?
  reallocIfNeeded (inInstant) ;
//--- Is instant is far than latest ?
  if (mLatestInstant < inInstant) {
    mLatestInstant = inInstant ;
  }
//--- Find a node with same activity list for the same resource
  cIndependantResourceSchedule  * p = mResourceScheduleArray (inInstant COMMA_HERE) ;
  while ((p != NULL)
         &&
         ((p->mResourceIndex != inResource->mResourceIndex)
          ||
         (p->mActivitiesToScheduleList != inResource->mActivitiesToScheduleList)
        )
       ) {
    p = p->mPtrToOtherResource ;
  }
//--- If found, merge lists ; if not insert node
  if (p != NULL) {
    if (inResource->mPtrToFirstActivity == NULL) {
    
    }else if (p->mPtrToFirstActivity == NULL) {
      p->mPtrToFirstActivity = inResource->mPtrToFirstActivity ;
      p->mPtrToLastActivity = inResource->mPtrToLastActivity ;
    }else{
      p->mPtrToLastActivity->mPtrToOtherSchedule = inResource->mPtrToFirstActivity ;
      p->mPtrToLastActivity = inResource->mPtrToLastActivity ;
    }
    disposeResourceNode (inResource) ;
  }else{
    inResource->mPtrToOtherResource = mResourceScheduleArray (inInstant COMMA_HERE) ;
    mResourceScheduleArray (inInstant COMMA_HERE) = inResource ;
  }
}     

//---------------------------------------------------------------------------*

static cIndependantResourcesActivitySchedule * gPtrNodeList = NULL ;

//---------------------------------------------------------------------------*

static void unMark (void) {
  cIndependantResourcesActivitySchedule * p = gPtrNodeList ;
  while (p != NULL) {
    p->mMarked = false ;
    p = p->mPtrToNextNode ;
  }
}

//---------------------------------------------------------------------------*

void cIndependantResourcesScheduleMap::
computeBestAndWorstResponseTime (TC_UniqueArray <cResponseTime> & ioResponseTimeArray) {
  cIndependantResourcesActivitySchedule * p = gPtrNodeList ;
  while (p != NULL) {
    const PMSInt32 activityIndex = p->mActivityIndex ;
    const PMSInt32 eoe = p->mActivityEndOfExecution ;
    if (ioResponseTimeArray (activityIndex COMMA_HERE).mBestResponseTime > eoe) {
      ioResponseTimeArray (activityIndex COMMA_HERE).mBestResponseTime = eoe ;
    }
    if (ioResponseTimeArray (activityIndex COMMA_HERE).mWorstResponseTime < eoe) {
      ioResponseTimeArray (activityIndex COMMA_HERE).mWorstResponseTime = eoe ;
    }
    p = p->mPtrToNextNode ;
  }
}

//---------------------------------------------------------------------------*

static void
internalDumpStructure (cIndependantResourcesActivitySchedule * inPtr) {
  cIndependantResourcesActivitySchedule * p = inPtr ;
  while (p != NULL) {
    cIndependantResourcesActivitySchedule * q = p ;
    while (q != NULL) {
      if (! q->mMarked) {
        q->mMarked = true ;
        co << "at " << cStringWithPointer (q)
           << ": activity " << cStringWithSigned (q->mActivityIndex)
           << ", duration: " << cStringWithSigned (q->mActivityDuration)
           << ", eoe:" << cStringWithSigned (q->mActivityEndOfExecution)
           << ", previous:" << cStringWithPointer (q->mPtrToPreviousActivity)
           << ", other: " << cStringWithPointer (q->mPtrToOtherSchedule)
           << "\n" ;
        co.flush ();
        internalDumpStructure (q->mPtrToOtherSchedule) ;
      }
      q = q->mPtrToPreviousActivity ;
    }
    p = p->mPtrToPreviousActivity ;
  }
}

//---------------------------------------------------------------------------*

static void
dumpSchedule (cIndependantResourceSchedule  * inPtr) {
  unMark () ;
  cIndependantResourceSchedule  * p = inPtr ;
  while (p != NULL) {
    co << "at " << cStringWithPointer (p)
       << ": resource:" << cStringWithSigned (p->mResourceIndex)
       << ", activities: 0x" << cStringWithPointer (p->mPtrToFirstActivity)
       << " (last 0x" << cStringWithPointer (p->mPtrToLastActivity)
       << "\n" ;
    co.flush ();
    internalDumpStructure (p->mPtrToFirstActivity) ;
    p = p->mPtrToOtherResource ;
  }
}

//---------------------------------------------------------------------------*

void cIndependantResourcesScheduleMap::
dumpStructure (void) {
  co << "********** DUMP **********\n"
        "Latest instant: " << cStringWithSigned (mLatestInstant) << "\n" ;
  dumpSchedule (mResourceScheduleArray (mLatestInstant COMMA_HERE)) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//    H A N D L E    A N    I N P U T    F I L E                             *
//                                                                           *
//---------------------------------------------------------------------------*

void
independantResourcesScheduleActivities (const TC_UniqueArray <cActivity> & inActivities,
                                        TC_UniqueArray <cResponseTime> & outResponseTimeArray) {
//--- Schedule map
  cIndependantResourcesScheduleMap scheduleMap ;
//--- Enter independant activities
  const PMSInt32 activitiesCount = inActivities.count () ;
  co << cStringWithSigned (activitiesCount) << " activities\n" ;
  fflush (stdout);
  for (PMSInt32 i=0 ; i<activitiesCount ; i++) {
    if (inActivities (i COMMA_HERE).mPredecessorId < 0) {
      scheduleMap.enterActivity (i,
                                 inActivities (i COMMA_HERE).mPriority,
                                 inActivities (i COMMA_HERE).mOffset,
                                 inActivities (i COMMA_HERE).mResourceId) ;
    }
  }
//--- Perform activities scheduling
  while (scheduleMap.moreWorkToDo ()) { 
    cIndependantResourceSchedule  * p = scheduleMap.retrieveResourceList () ;
//    dumpSchedule (p) ;
    while (p != NULL) {
      cIndependantResourceSchedule  * q = p->mPtrToOtherResource ;
      p->mPtrToOtherResource = NULL ;
      if (p->mActivitiesToScheduleList.isListEmpty ()) {
        scheduleMap.insertAtNextInstant (p) ;      
      }else if (p->mActivitiesToScheduleList.AnyReadyToScheduleAt (scheduleMap.getCurrentInstant ())) {
      //  printf ("Iteration %ld, latest : %ld\n", iteration, scheduleMap.getFarestInstant ()) ;
        C_activitiesToSchedule list = p->mActivitiesToScheduleList ;
        const PMSInt32 activityIndex = list.getFirstToScheduleAndSuppress (scheduleMap.getCurrentInstant ()) ;
        const PMSInt32 successorIndex = inActivities (activityIndex COMMA_HERE).mSuccessorId ;
        const PMSInt32 minDuration = inActivities (activityIndex COMMA_HERE).mMinDuration ;
        const PMSInt32 maxDuration = inActivities (activityIndex COMMA_HERE).mMaxDuration ;
        for (PMSInt32 i=minDuration ; i<=maxDuration ; i++) {
          gAllocatedActivityNodesCount ++ ;
          cIndependantResourcesActivitySchedule * pActivity = new cIndependantResourcesActivitySchedule ;
          pActivity->mMarked = false ;
          pActivity->mActivityIndex = activityIndex ;
          pActivity->mActivityDuration = i ;
          pActivity->mActivityEndOfExecution = scheduleMap.getCurrentInstant () + i ;
          pActivity->mPtrToOtherSchedule = NULL ;
          pActivity->mPtrToPreviousActivity = p->mPtrToFirstActivity ;
          pActivity->mPtrToNextNode = gPtrNodeList ;
          gPtrNodeList = pActivity ;
          cIndependantResourceSchedule  * r = allocResourceNode () ;
          r->mResourceIndex = p->mResourceIndex ;
          r->mActivitiesToScheduleList = list ;
         
          if (successorIndex >= 0) {
          	if (inActivities (successorIndex COMMA_HERE).mResourceId != 
          			inActivities (activityIndex COMMA_HERE).mResourceId) {
          			
           	} else {
          
            	r->mActivitiesToScheduleList.addEntry (successorIndex,
                                                   inActivities (successorIndex COMMA_HERE).mPriority,
                                                   pActivity->mActivityEndOfExecution + 
                                                   inActivities (successorIndex COMMA_HERE).mOffset);
            }
          	
          	PMSInt32 OtherHeirId = inActivities (successorIndex COMMA_HERE).mOtherHeirId;
          	
          	while (OtherHeirId >= 0){
          		
          		if (inActivities (OtherHeirId COMMA_HERE).mResourceId != 
          			inActivities (activityIndex COMMA_HERE).mResourceId) {
                         
          		} else {
          
            		r->mActivitiesToScheduleList.addEntry (OtherHeirId,
                                                   inActivities (OtherHeirId COMMA_HERE).mPriority,
                                                   pActivity->mActivityEndOfExecution + 
                                                   inActivities (OtherHeirId COMMA_HERE).mOffset);
           		}
          	          	           		
            	OtherHeirId = inActivities (OtherHeirId COMMA_HERE).mOtherHeirId;
          	}
          }
          r->mPtrToFirstActivity = pActivity ;
          r->mPtrToLastActivity = pActivity ;
          r->mPtrToOtherResource = NULL ;
          scheduleMap.insertAtInstant (r, pActivity->mActivityEndOfExecution) ;
        }
        disposeResourceNode (p) ;
      }else{
        scheduleMap.insertAtNextInstant (p) ;      
      }
      p = q ;
    }
    scheduleMap.advanceToNextInstant () ;
  }
//--- Dump data structure
//  scheduleMap.dumpStructure () ;
//--- Build response time array
  outResponseTimeArray.removeAllObjects () ;
  outResponseTimeArray.makeRoom (activitiesCount) ;
  outResponseTimeArray.addObjects (activitiesCount, cResponseTime ()) ;
  scheduleMap.computeBestAndWorstResponseTime (outResponseTimeArray) ;
  
  co << cStringWithSigned (gUsedResourceNodesCount) << " resource nodes used, "
     << cStringWithSigned (gAllocatedResourceNodesCount) << " allocated.\n"
     << cStringWithSigned (gAllocatedActivityNodesCount) << " activity nodes allocated.\n" ;
}

/*------------------------------------------------------------------------*/
