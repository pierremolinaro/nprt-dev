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

const intptr_t MARK_VDL_NODE = INTPTR_MIN ;

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
    public : intptr_t mID ;
    public : int32_t mIndex ;
    
    public : intptr_t compare (const C_us_nodeInfo & inOperand) const ;
    
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
      return (uint32_t) ((mIndex << 11)
                    ^ ((mPtrToNext == NULL) ? -1 : mPtrToNext->mID)) ;
    }
  } ;

//--- Realloc unique table
  public : static void reallocUniqueTable (const int32_t inTableUniqueNewSize) ;

//--- Realloc addition cache
  public : static void reallocAdditionCache (const size_t inNewCacheSize) ;

//--- Decision list
  protected : C_us_nodeInfo * mRootPointer ;

//--- Set to NULL vector
  public : void setToNullVector (void) ;

//--- Null vector ?
  public : bool isNullVector (void) const ;

//--- Vector comparison
  public : bool operator == (const C_us & inOperand) const ;

//--- Explore a VDL
  public : static void explore_vdl (C_us & ioVDL, int32_t & outIndex) ;

//--- print a vector
  public : void printVector (AC_OutputStream & inStream,
                             const TC_UniqueArray <C_String> & inNames,
                             const int32_t inFirst,
                             const int32_t inStep) const ;

  public : void printVector (AC_OutputStream & inStream,
                             const char * inPrefix,
                             const int32_t inFirst,
                             const int32_t inStep) const ;

//--- Print VDL summary
  public : static void printVDLsummary (AC_OutputStream & inOutputStream) ;

//--- Get value ID (as intptr_t integer)
  public : inline intptr_t getLongID (void) const {
    return (mRootPointer != NULL) ? ((intptr_t) mRootPointer->mID) : 0 ;
  }

//--- Push a new value on stack
  public : void pushValue (const int32_t inIndex) ;

//--- Suppress an entry
  public : void suppressEntryAtLevel (const int32_t inLevel) ;

//--- Collect unused elements
  public : static void collectUnusedNodes (void) ;

//--- Internal methods
  protected : static C_us_nodeInfo * find_or_add (const int32_t inIndex,
                                                 C_us_nodeInfo * const inPointerToNext) ;

  protected : static C_us_nodeInfo * internalSuppressEntry (const int32_t inLevel,
                                                           C_us_nodeInfo * const inPointer) ;

  protected : static int32_t smNodeCompare ;
  public : static uint32_t getNodeSize (void) ;
  public : static int32_t getNodeComparesCount (void) { return smNodeCompare ; }
  protected : static int32_t smNodeCount ;
  public : static int32_t getVDLnodeCount (void) { return smNodeCount ; }
  protected : static uint64_t smTrivialAdd ;
  public : static uint64_t getTrivialAddCount (void) { return smTrivialAdd ; }
  public : static uint64_t getCacheSuccessCount (void) ;
  public : static uint64_t getCacheFailureCount (void) ;
  public : static uint64_t getCacheOverrideCount (void) ;
  public : static uint64_t getUnusedCacheEntriesCount (void) ;
  public : static uint64_t getCacheEntriesCount (void) ;
  
  friend class C_us_nodeInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
