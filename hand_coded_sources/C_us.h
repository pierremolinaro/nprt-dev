//---------------------------------------------------------------------------*
//                                                                           *
//     C++ class for implementing UNIQUE STACK                               *
//                                                                           *
//  Copyright (C) 2003 Pierre Molinaro.                                      *
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

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const PMSInt MARK_VDL_NODE = PMSINT_MIN ;

//---------------------------------------------------------------------------*

class C_us {
//--- Constructor et destructor
  public : C_us (void) ; // Null vector
  public : virtual ~C_us (void) ;

//--- Control copy
  public : C_us (const C_us & inSource) ;
  public : C_us & operator = (const C_us & inSource) ;

//--- Pointers for handling a double-linked list of all existing variables
  protected : C_us * mPtrToNextExisting ;
  protected : C_us * mPtrToPreviousExisting ;
  private : void initLinks (void) ;
  
//--- Internal nodes
  public : class C_us_nodeInfo {
    public : C_us_nodeInfo * mPtrToNext ;
    public : PMSInt mID ;
    public : PMSInt32 mIndex ;
    
    public : PMSInt compare (const C_us_nodeInfo & inOperand) const ;
    
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
      return (PMUInt32) ((mIndex << 11)
                    ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const PMSInt32 inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const PMSInt32 inNewCacheSize) ;

//--- Decision list
  protected : C_us_nodeInfo * mRootPointer ;

//--- Set to NULL vector
  public : void setToNullVector (void) ;

//--- Null vector ?
  public : bool isNullVector (void) const ;

//--- Vector comparison
  public : bool operator == (const C_us & inOperand) const ;

//--- Explore a VDL
  public : static void explore_vdl (C_us & ioVDL, PMSInt32 & outIndex) ;

//--- print a vector
  public : void printVector (AC_OutputStream & inStream,
                             const TC_UniqueArray <C_String> & inNames,
                             const PMSInt32 inFirst,
                             const PMSInt32 inStep) const ;

  public : void printVector (AC_OutputStream & inStream,
                             const char * inPrefix,
                             const PMSInt32 inFirst,
                             const PMSInt32 inStep) const ;

//--- Print VDL summary
  public : static void printVDLsummary (AC_OutputStream & inOutputStream) ;

//--- Get value ID (as PMSInt integer)
  public : inline PMSInt getLongID (void) const {
    return (mRootPointer != NULL) ? ((PMSInt) mRootPointer->mID) : 0 ;
  }

//--- Push a new value on stack
  public : void pushValue (const PMSInt32 inIndex) ;

//--- Suppress an entry
  public : void suppressEntryAtLevel (const PMSInt32 inLevel) ;

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static C_us_nodeInfo * find_or_add (const PMSInt32 inIndex,
                                                 C_us_nodeInfo * const inPointerToNext) ;

  protected : static C_us_nodeInfo * internalSuppressEntry (const PMSInt32 inLevel,
                                                           C_us_nodeInfo * const inPointer) ;

  protected : static PMSInt32 smNodeCompare ;
  public : static PMUInt32 getNodeSize (void) ;
  public : static PMSInt32 getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static PMSInt32 smNodeCount ;
  public : static PMSInt32 getVDLnodeCount (void) { return smNodeCount ; }
  protected : static PMUInt64 smTrivialAdd ;
  public : static PMUInt64 getTrivialAddCount (void) { return smTrivialAdd ; }
  public : static PMUInt64 getCacheSuccessCount (void) ;
  public : static PMUInt64 getCacheFailureCount (void) ;
  public : static PMUInt64 getCacheOverrideCount (void) ;
  public : static PMUInt64 getUnusedCacheEntriesCount (void) ;
  public : static PMUInt64 getCacheEntriesCount (void) ;
  
  friend class C_us_nodeInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
