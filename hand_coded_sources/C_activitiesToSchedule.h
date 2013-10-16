//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing UNIQUE STACK for activities to schedule    *
//                                                                           *
//  Copyright (C) 2004 Pierre Molinaro.                                      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes                                            *
//                                                                           *
//  This program is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU General Public License as published by the    *
//  Free Software Foundation.                                                *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//   more details.                                                           *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef UNIQUE_STACK_DEFINED
#define UNIQUE_STACK_DEFINED

//---------------------------------------------------------------------------*

#include "collections/TC_UniqueArray.h"
#include "strings/C_String.h"
#include "ExtendedList.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const PMSInt32 MARK_VDL_NODE = (PMSInt32) 0x80000000 ;

//---------------------------------------------------------------------------*

class C_activitiesToSchedule {
//----------------- CONSTRUCTORS AND DESTRUCTORS -----------------
//--- Constructor
  public : C_activitiesToSchedule (void) ; // Empty list

//--- Destructor
  public : virtual ~C_activitiesToSchedule (void) ;

//--- Control copy
  public : C_activitiesToSchedule (const C_activitiesToSchedule & inSource) ;
  public : C_activitiesToSchedule & operator = (const C_activitiesToSchedule & inSource) ;

//--------------------- PUBLIC USEFUL METHODS --------------------

//--- List empty ?
  public : bool isListEmpty (void) const ;
  
//--- Set to empty list
  public : void setToEmptyList (void) ;

//--- Add a new entry
  public : void addEntry (const PMSInt32 inActivityIndex,
                          const PMSInt32 inActivityPriority,
                          const PMSInt32 inActivityScheduleInstant) ;

//--- Get first activity to schedule
  public : PMSInt32 getFirstToScheduleAndSuppress (const PMSInt32 inCurrentInstant) ;
  public : PMSInt32 getMinimumBusyPeriod4Activity  (const PMSInt32 inCurrentActivity,
                                      const TC_UniqueArray <cActivity> & inActivities);
 
  public : PMSInt32 getMaximumBusyPeriod (const PMSInt32 currentActivityIndex,
                                        const TC_UniqueArray <cActivity> & inActivities); 
 
  public : PMSInt32 getMinimumBusyPeriod (const PMSInt32 currentActivityIndex,
                                        const TC_UniqueArray <cActivity> & inActivities); 
 
  public : PMSInt32 getLowerPriority (const PMSInt32 currentActivityIndex, 
                                    const TC_UniqueArray <cActivity> & inActivities) ;
  public : PMSInt32 getFirstToSchedule (const PMSInt32 inCurrentInstant) const ;
  public : PMSInt32 getFirstScheduledInstant (const PMSInt32 inCurrentInstant) const ;
  public : bool AnyReadyToScheduleAt (const PMSInt32 inCurrentInstant) const ;
  public : bool AnyNotReadyToScheduleAt (const PMSInt32 inCurrentInstant) const;

  public : PMSInt32 getNextScheduleTime (void) const ;

//--- Test for equality (returns true if the two lists are the same)
  public : bool operator == (const C_activitiesToSchedule & inOperand) const ;
  public : bool operator != (const C_activitiesToSchedule & inOperand) const ;

//--- Print a list
  public : void printList (AC_OutputStream & inStream,
                           const TC_UniqueArray <C_String> & inNames) const ;

//------------------------ INTERNAL STUFF ------------------------

//--- Pointers for handling a double-linked list of all existing variables
  protected : C_activitiesToSchedule * mPtrToNextExisting ;
  protected : C_activitiesToSchedule * mPtrToPreviousExisting ;
  private : void initLinks (void) ;
  
//--- Internal nodes
  public : class cVDLnodeInfo {
    public : cVDLnodeInfo * mPtrToNext ;
    public : PMSInt mID ;
    public : PMSInt32 mActivityIndex ;
    public : PMSInt32 mActivityPriority ;
    public : PMSInt32 mScheduleInstant ;
    
    public : PMSInt compare (const cVDLnodeInfo & inOperand) const ;
    
    public : inline bool isMarked (void) const {
      return (mID & MARK_VDL_NODE) != 0 ;
    }

    public : inline void mark (void) {
      mID |= MARK_VDL_NODE ;
    }

    public : inline void unmark (void) {
      mID &= ~ MARK_VDL_NODE ;
    }
    
    public : inline PMUInt32 getHashCodeForMap (void) const {
      return (PMUInt32) ((mActivityIndex << 17)
                     ^ (mActivityPriority << 13) 
                     ^ (mScheduleInstant << 7)
                     ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const PMSInt32 inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const PMSInt32 inNewCacheSize) ;

//--- Decision list
  protected : cVDLnodeInfo * mRootPointer ;

//--- Get pointer value
  public : inline PMSInt getPtr (void) const { return (PMSInt) mRootPointer ; }

//--- Get value ID (as PMSInt integer)
  public : inline PMSInt getLongID (void) const {
    return (mRootPointer != NULL) ? ((PMSInt) mRootPointer->mID) : 0 ;
  }

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static cVDLnodeInfo * find_or_add (const PMSInt32 inIndex,
                                                 const PMSInt32 inActivityPriority,
                                                 const PMSInt32 inScheduleInstant,
                                                 cVDLnodeInfo * const inPointerToNext) ;

  protected : static cVDLnodeInfo * internalAddEntry (const PMSInt32 inIndex,
                                                      const PMSInt32 inActivityPriority,
                                                      const PMSInt32 inScheduleInstant,
                                                       cVDLnodeInfo * const inPointerToNext) ;

  protected : static void internalGetFirstToScheduleAndSuppress (cVDLnodeInfo * & inPtr,
                                                      const PMSInt32 inActivityIndex) ;

  protected : static PMSInt32 smNodeCompare ;
  public : static PMUInt32 getNodeSize (void) ;
  public : static PMSInt32 getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static PMSInt32 smNodeCount ;
  public : static PMSInt32 getVDLnodeCount (void) { return smNodeCount ; }
  
  friend class cVDLnodeInfo ;
} ;

//--------------------------------------------------------------------------------

void SuccessorsMaxBusyDuration (PMSInt32 & ioBusyDuration, const PMSInt32 activityIndex, 
                                const PMSInt32 ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities);

void LowerPriorityOnResource (PMSInt32 & lowerPriority, const PMSInt32 activityIndex, 
                              const PMSInt32 ResourceIndex,
                              const TC_UniqueArray <cActivity> & inActivities);
                              
void SuccessorsMinBusyDuration (PMSInt32 & ioBusyDuration, const PMSInt32 activityIndex, 
                                const PMSInt32 ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities);
                                
void SuccessorsMinBusyDuration4Activity (PMSInt32 & ioBusyDuration, const PMSInt32 activityIndex, 
                                const PMSInt32 ResourceIndex,
                                const PMSInt32 priorityOfCurrentActivity,
                                const TC_UniqueArray <cActivity> & inActivities);
    
//---------------------------------------------------------------------------*

#endif
