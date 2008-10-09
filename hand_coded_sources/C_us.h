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
#include "utilities/C_String.h"

//---------------------------------------------------------------------------*

#include <stdio.h>

//---------------------------------------------------------------------------*

const ptrAsSint MARK_VDL_NODE = PTR_AS_SINT_MIN ;

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
    public : ptrAsSint mID ;
    public : sint32 mIndex ;
    
    public : ptrAsSint compare (const C_us_nodeInfo & inOperand) const ;
    
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
      return (uint32) ((mIndex << 11)
                    ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const sint32 inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const sint32 inNewCacheSize) ;

//--- Decision list
  protected : C_us_nodeInfo * mRootPointer ;

//--- Set to NULL vector
  public : void setToNullVector (void) ;

//--- Null vector ?
  public : bool isNullVector (void) const ;

//--- Vector comparison
  public : bool operator == (const C_us & inOperand) const ;

//--- Explore a VDL
  public : static void explore_vdl (C_us & ioVDL, sint32 & outIndex) ;

//--- print a vector
  public : void printVector (AC_OutputStream & inStream,
                             const TC_UniqueArray <C_String> & inNames,
                             const sint32 inFirst,
                             const sint32 inStep) const ;

  public : void printVector (AC_OutputStream & inStream,
                             const char * inPrefix,
                             const sint32 inFirst,
                             const sint32 inStep) const ;

//--- Print VDL summary
  public : static void printVDLsummary (AC_OutputStream & inOutputStream) ;

//--- Get value ID (as ptrAsSint integer)
  public : inline ptrAsSint getLongID (void) const {
    return (mRootPointer != NULL) ? ((ptrAsSint) mRootPointer->mID) : 0 ;
  }

//--- Push a new value on stack
  public : void pushValue (const sint32 inIndex) ;

//--- Suppress an entry
  public : void suppressEntryAtLevel (const sint32 inLevel) ;

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static C_us_nodeInfo * find_or_add (const sint32 inIndex,
                                                 C_us_nodeInfo * const inPointerToNext) ;

  protected : static C_us_nodeInfo * internalSuppressEntry (const sint32 inLevel,
                                                           C_us_nodeInfo * const inPointer) ;

  protected : static sint32 smNodeCompare ;
  public : static uint32 getNodeSize (void) ;
  public : static sint32 getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static sint32 smNodeCount ;
  public : static sint32 getVDLnodeCount (void) { return smNodeCount ; }
  protected : static uint64 smTrivialAdd ;
  public : static uint64 getTrivialAddCount (void) { return smTrivialAdd ; }
  public : static uint64 getCacheSuccessCount (void) ;
  public : static uint64 getCacheFailureCount (void) ;
  public : static uint64 getCacheOverrideCount (void) ;
  public : static uint64 getUnusedCacheEntriesCount (void) ;
  public : static uint64 getCacheEntriesCount (void) ;
  
  friend class C_us_nodeInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
