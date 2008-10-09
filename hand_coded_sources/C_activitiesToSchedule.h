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
#include "utilities/C_String.h"
#include "ExtendedList.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const sint32 MARK_VDL_NODE = 0x80000000 ;

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
  public : void addEntry (const sint32 inActivityIndex,
                          const sint32 inActivityPriority,
                          const sint32 inActivityScheduleInstant) ;

//--- Get first activity to schedule
  public : sint32 getFirstToScheduleAndSuppress (const sint32 inCurrentInstant) ;
  public : sint32 getMinimumBusyPeriod4Activity  (const sint32 inCurrentActivity,
                                      const TC_UniqueArray <cActivity> & inActivities);
 
  public : sint32 getMaximumBusyPeriod (const sint32 currentActivityIndex,
                                        const TC_UniqueArray <cActivity> & inActivities); 
 
  public : sint32 getMinimumBusyPeriod (const sint32 currentActivityIndex,
                                        const TC_UniqueArray <cActivity> & inActivities); 
 
  public : sint32 getLowerPriority (const sint32 currentActivityIndex, 
                                    const TC_UniqueArray <cActivity> & inActivities) ;
  public : sint32 getFirstToSchedule (const sint32 inCurrentInstant) const ;
  public : sint32 getFirstScheduledInstant (const sint32 inCurrentInstant) const ;
  public : bool AnyReadyToScheduleAt (const sint32 inCurrentInstant) const ;
  public : bool AnyNotReadyToScheduleAt (const sint32 inCurrentInstant) const;

  public : sint32 getNextScheduleTime (void) const ;

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
    public : ptrAsSint mID ;
    public : sint32 mActivityIndex ;
    public : sint32 mActivityPriority ;
    public : sint32 mScheduleInstant ;
    
    public : ptrAsSint compare (const cVDLnodeInfo & inOperand) const ;
    
    public : inline bool isMarked (void) const {
      return (mID & MARK_VDL_NODE) != 0 ;
    }

    public : inline void mark (void) {
      mID |= MARK_VDL_NODE ;
    }

    public : inline void unmark (void) {
      mID &= ~ MARK_VDL_NODE ;
    }
    
    public : inline uint32 getHashCodeForMap (void) const {
      return (uint32) ((mActivityIndex << 17)
                     ^ (mActivityPriority << 13) 
                     ^ (mScheduleInstant << 7)
                     ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const sint32 inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const sint32 inNewCacheSize) ;

//--- Decision list
  protected : cVDLnodeInfo * mRootPointer ;

//--- Get pointer value
  public : inline ptrAsSint getPtr (void) const { return (ptrAsSint) mRootPointer ; }

//--- Get value ID (as ptrAsSint integer)
  public : inline ptrAsSint getLongID (void) const {
    return (mRootPointer != NULL) ? ((ptrAsSint) mRootPointer->mID) : 0 ;
  }

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static cVDLnodeInfo * find_or_add (const sint32 inIndex,
                                                 const sint32 inActivityPriority,
                                                 const sint32 inScheduleInstant,
                                                 cVDLnodeInfo * const inPointerToNext) ;

  protected : static cVDLnodeInfo * internalAddEntry (const sint32 inIndex,
                                                      const sint32 inActivityPriority,
                                                      const sint32 inScheduleInstant,
                                                       cVDLnodeInfo * const inPointerToNext) ;

  protected : static void internalGetFirstToScheduleAndSuppress (cVDLnodeInfo * & inPtr,
                                                      const sint32 inActivityIndex) ;

  protected : static sint32 smNodeCompare ;
  public : static uint32 getNodeSize (void) ;
  public : static sint32 getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static sint32 smNodeCount ;
  public : static sint32 getVDLnodeCount (void) { return smNodeCount ; }
  
  friend class cVDLnodeInfo ;
} ;

//--------------------------------------------------------------------------------

void SuccessorsMaxBusyDuration (sint32 & ioBusyDuration, const sint32 activityIndex, 
                                const sint32 ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities);

void LowerPriorityOnResource (sint32 & lowerPriority, const sint32 activityIndex, 
                              const sint32 ResourceIndex,
                              const TC_UniqueArray <cActivity> & inActivities);
                              
void SuccessorsMinBusyDuration (sint32 & ioBusyDuration, const sint32 activityIndex, 
                                const sint32 ResourceIndex,
                                const TC_UniqueArray <cActivity> & inActivities);
                                
void SuccessorsMinBusyDuration4Activity (sint32 & ioBusyDuration, const sint32 activityIndex, 
                                const sint32 ResourceIndex,
                                const sint32 priorityOfCurrentActivity,
                                const TC_UniqueArray <cActivity> & inActivities);
    
//---------------------------------------------------------------------------*

#endif
