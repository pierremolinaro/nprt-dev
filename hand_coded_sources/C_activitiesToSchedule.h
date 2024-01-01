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

#include "TC_UniqueArray.h"
#include "String-class.h"
#include "ExtendedList-v2.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const int32_t MARK_VDL_NODE = (int32_t) 0x80000000 ;

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
  public : void addEntry (const int32_t inActivityIndex,
                          const int32_t inActivityPriority,
                          const int32_t inActivityScheduleInstant) ;

//--- Get first activity to schedule
  public : int32_t getFirstToScheduleAndSuppress (const int32_t inCurrentInstant) ;
  public : int32_t getMinimumBusyPeriod4Activity  (const int32_t inCurrentActivity,
                                                    const TC_UniqueArray <cActivity> & inActivities) const ;

  public : int32_t getMaximumBusyPeriod (const int32_t currentActivityIndex,
                                          const TC_UniqueArray <cActivity> & inActivities) const ;

  public : int32_t getMinimumBusyPeriod (const int32_t currentActivityIndex,
                                          const TC_UniqueArray <cActivity> & inActivities) const ;

  public : int32_t getLowerPriority (const int32_t currentActivityIndex,
                                      const TC_UniqueArray <cActivity> & inActivities) const ;

  public : int32_t getFirstToSchedule (const int32_t inCurrentInstant) const ;
  public : int32_t getFirstScheduledInstant (const int32_t inCurrentInstant) const ;
  public : bool AnyReadyToScheduleAt (const int32_t inCurrentInstant) const ;
  public : bool AnyNotReadyToScheduleAt (const int32_t inCurrentInstant) const;

  public : int32_t getNextScheduleTime (void) const ;

//--- Test for equality (returns true if the two lists are the same)
  public : bool operator == (const C_activitiesToSchedule & inOperand) const ;
  public : bool operator != (const C_activitiesToSchedule & inOperand) const ;

//--- Print a list
  public : void printList (AbstractOutputStream & inStream,
                           const TC_UniqueArray <String> & inNames) const ;

//------------------------ INTERNAL STUFF ------------------------

//--- Pointers for handling a double-linked list of all existing variables
  protected : C_activitiesToSchedule * mPtrToNextExisting ;
  protected : C_activitiesToSchedule * mPtrToPreviousExisting ;
  private : void initLinks (void) ;

//--- Internal nodes
  public : class cVDLnodeInfo {
    public : cVDLnodeInfo * mPtrToNext ;
    public : intptr_t mID ;
    public : int32_t mActivityIndex ;
    public : int32_t mActivityPriority ;
    public : int32_t mScheduleInstant ;

    public : intptr_t compare (const cVDLnodeInfo & inOperand) const ;

    public : inline bool isMarked (void) const {
      return (mID & MARK_VDL_NODE) != 0 ;
    }

    public : inline void mark (void) {
      mID |= MARK_VDL_NODE ;
    }

    public : inline void unmark (void) {
      mID &= ~ MARK_VDL_NODE ;
    }

    public : inline uint32_t getHashCodeForMap (void) const {
      return (uint32_t) ((mActivityIndex << 17)
                     ^ (mActivityPriority << 13)
                     ^ (mScheduleInstant << 7)
                     ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const int32_t inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const int32_t inNewCacheSize) ;

//--- Decision list
  protected : cVDLnodeInfo * mRootPointer ;

//--- Get pointer value
  public : inline intptr_t getPtr (void) const { return (intptr_t) mRootPointer ; }

//--- Get value ID (as intptr_t integer)
  public : inline intptr_t getLongID (void) const {
    return (mRootPointer != NULL) ? ((intptr_t) mRootPointer->mID) : 0 ;
  }

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static cVDLnodeInfo * find_or_add (const int32_t inIndex,
                                                 const int32_t inActivityPriority,
                                                 const int32_t inScheduleInstant,
                                                 cVDLnodeInfo * const inPointerToNext) ;

  protected : static cVDLnodeInfo * internalAddEntry (const int32_t inIndex,
                                                      const int32_t inActivityPriority,
                                                      const int32_t inScheduleInstant,
                                                       cVDLnodeInfo * const inPointerToNext) ;

  protected : static void internalGetFirstToScheduleAndSuppress (cVDLnodeInfo * & inPtr,
                                                      const int32_t inActivityIndex) ;

  protected : static int32_t smNodeCompare ;
  public : static uint32_t getNodeSize (void) ;
  public : static int32_t getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static int32_t smNodeCount ;
  public : static int32_t getVDLnodeCount (void) { return smNodeCount ; }

  friend class cVDLnodeInfo ;
} ;

//--------------------------------------------------------------------------------

void SuccessorsMaxBusyDuration (int32_t & ioBusyDuration, const int32_t activityIndex,
                                const int32_t ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities);

void LowerPriorityOnResource (int32_t & lowerPriority, const int32_t activityIndex,
                              const int32_t ResourceIndex,
                              const TC_UniqueArray <cActivity> & inActivities);

void SuccessorsMinBusyDuration (int32_t & ioBusyDuration, const int32_t activityIndex,
                                const int32_t ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities);

void SuccessorsMinBusyDuration4Activity (int32_t & ioBusyDuration, const int32_t activityIndex,
                                const int32_t ResourceIndex,
                                const int32_t priorityOfCurrentActivity,
                                const TC_UniqueArray <cActivity> & inActivities);

//---------------------------------------------------------------------------*

#endif
