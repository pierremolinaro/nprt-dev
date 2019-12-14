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

#include "C_us.h"

//---------------------------------------------------------------------------*

#include <stddef.h>
#include <string.h>
#include <limits.h>

//---------------------------------------------------------------------------*

uint64_t C_us::smTrivialAdd ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Cache for addition                                     *
//                                                                           *
//---------------------------------------------------------------------------*

//--- Cache is handled by an prime integer sized array 
#include "cache/TC_prime_cache2.h"
typedef TC_prime_cache2 <C_us::C_us_nodeInfo *> cCacheClass ;
static cCacheClass gCache ;

//---------------------------------------------------------------------------*
//                                                                           *
//  VDD objects hash map                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

#include "C_us_hashmap.h"

static C_us_hashmap gMap ;

//---------------------------------------------------------------------------*

void C_us::reallocUniqueTable (const int32_t inTableUniqueNewSize) {
  gMap.reallocMap (inTableUniqueNewSize) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//  Static VDL variable used as root of all existing C_us instances          *
//                                                                           *
//---------------------------------------------------------------------------*

static C_us * gFirstUS = NULL ;
static C_us * gLastUS = NULL ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Node count : for giving an unique ID to every node                  *
//                                                                           *
//---------------------------------------------------------------------------*

int32_t C_us::smNodeCount = 0 ;

//---------------------------------------------------------------------------*
//                                                                           *
//     Realloc addition cache                                                *
//                                                                           *
//---------------------------------------------------------------------------*

void C_us::reallocAdditionCache (const int32_t inNewCacheSize) {
  gCache.reallocCache (inNewCacheSize) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Default constructor                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

C_us::C_us (void) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (NULL) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

void C_us::initLinks (void) {
  if (gFirstUS == NULL) {
    gLastUS = this ;
  }else{
    gFirstUS->mPtrToPreviousExisting = this ;
  }
  mPtrToNextExisting = gFirstUS ;
  gFirstUS = this ;

//  mPtrToNextExisting = this ;
//  mPtrToPreviousExisting = this ;
//  C_us * nextFromRoot = gVDLlistRoot.mPtrToNextExisting ;
//  mPtrToPreviousExisting = & gVDLlistRoot ;
//  nextFromRoot->mPtrToPreviousExisting = this ;
//  mPtrToNextExisting = nextFromRoot ;
//  gVDLlistRoot.mPtrToNextExisting = this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor                                                          *
//                                                                           *
//---------------------------------------------------------------------------*

C_us::~C_us (void) {
  mRootPointer = NULL ;
//--- Unlink
  if (mPtrToPreviousExisting == NULL) {
    gFirstUS = gFirstUS->mPtrToNextExisting ;
  }else{
    mPtrToPreviousExisting->mPtrToNextExisting = mPtrToNextExisting ;
  }
  if (mPtrToNextExisting == NULL) {
    gLastUS = gLastUS->mPtrToPreviousExisting ;
  }else{
    mPtrToNextExisting->mPtrToPreviousExisting = mPtrToPreviousExisting ;
  }

//  C_us * next = mPtrToNextExisting ;
//  C_us * previous = mPtrToPreviousExisting ;
//  previous->mPtrToNextExisting = next ;
//  next->mPtrToPreviousExisting = previous ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Set to NULL vector                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_us::setToNullVector (void) {
  mRootPointer = (C_us_nodeInfo *) NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Null vector ?                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_us::isNullVector (void) const {
  return mRootPointer == NULL ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Vector comparison                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_us::operator == (const C_us & inOperand) const {
  return mRootPointer == inOperand.mRootPointer ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Push a new value on stack                                           *
//                                                                           *
//---------------------------------------------------------------------------*

void C_us::pushValue (const int32_t inIndex) {
  mRootPointer = find_or_add (inIndex, mRootPointer) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Reset entry to zero                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

void C_us::suppressEntryAtLevel (const int32_t inLevel) {
  mRootPointer = internalSuppressEntry (inLevel, mRootPointer) ;
}

//---------------------------------------------------------------------------*

C_us::C_us_nodeInfo * C_us::
internalSuppressEntry (const int32_t inLevel,
                       C_us_nodeInfo * const inPointer) {
  C_us_nodeInfo * result = NULL ;
  if (inPointer != NULL) {
    if (inLevel <= 0) {
      result = inPointer->mPtrToNext ;
    }else{
      result = find_or_add (inPointer->mIndex,
                            internalSuppressEntry (inLevel-1, inPointer->mPtrToNext)) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Handle copy                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_us::C_us (const C_us & inOperand) :
mPtrToNextExisting (this),
mPtrToPreviousExisting (this),
mRootPointer (inOperand.mRootPointer) {
  initLinks () ;
}

//---------------------------------------------------------------------------*

C_us & C_us::operator = (const C_us & inOperand) {
  mRootPointer = inOperand.mRootPointer ;
  return *this ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Cache for addition                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

uint64_t C_us::getCacheEntriesCount (void) {
  return (uint64_t) gCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_us::getCacheSuccessCount (void) {
  return (uint64_t) gCache.getCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_us::getCacheFailureCount (void) {
  return gCache.getCacheMissCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_us::getCacheOverrideCount (void) {
  return gCache.getCacheOverrideCount () ;
}

//---------------------------------------------------------------------------*

uint64_t C_us::getUnusedCacheEntriesCount (void) {
  return gCache.getUnusedCacheEntriesCount () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Explore a VDL                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_us::explore_vdl (C_us & ioVDL, int32_t & outIndex) {
  if (ioVDL.mRootPointer == NULL) {
    outIndex  = -1 ;
  }else{
    outIndex = ioVDL.mRootPointer->mIndex ;
    ioVDL.mRootPointer = ioVDL.mRootPointer->mPtrToNext ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for 'C_us::C_us_nodeInfo'                               *
//                                                                           *
//---------------------------------------------------------------------------*

int32_t C_us::smNodeCompare = 0 ;

intptr_t C_us::C_us_nodeInfo::
compare (const C_us_nodeInfo & inInfo) const {
  smNodeCompare ++ ;
  intptr_t result = ((intptr_t) mPtrToNext) - ((intptr_t) inInfo.mPtrToNext) ;
  if (result == 0) {
    result = mIndex - inInfo.mIndex ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get node size                                                       *
//                                                                           *
//---------------------------------------------------------------------------*

uint32_t C_us::getNodeSize (void) {
  return C_us_hashmap::getNodeSize () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Internal static method for adding a value to an index               *
//                                                                           *
//---------------------------------------------------------------------------*

C_us::C_us_nodeInfo * C_us::
find_or_add (const int32_t inIndex,
             C_us::C_us_nodeInfo * const inPointerToNext) {
//--- Do search or insert
  C_us_nodeInfo info ;
  info.mIndex = inIndex ;
  info.mPtrToNext = inPointerToNext ;
  bool insertionPerformed = false ; // Not used
  C_us_nodeInfo * p = gMap.search_or_insert (info, insertionPerformed) ;
  if (insertionPerformed) {
    smNodeCount ++ ;
    p->mID = smNodeCount ;
  }
  return p ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Print a vector                                                      *
//                                                                           *
//---------------------------------------------------------------------------*

 void C_us::printVector (AC_OutputStream & inStream,
                           const char * inPrefix,
                           const int32_t inFirst,
                           const int32_t inStep) const {
   bool firstPrint = true ;
   C_us_nodeInfo * p = mRootPointer ;
    while (p != NULL) {
     if (((p->mIndex - inFirst) % inStep) == 0) {
       if (firstPrint) {
         firstPrint = false ;
       }else{
         inStream << " " ;
       }
       inStream << inPrefix << cStringWithSigned ((p->mIndex - inFirst) / inStep) ;
     }
     p = p->mPtrToNext ;
   }
 }

//---------------------------------------------------------------------------*

 void C_us::printVector (AC_OutputStream & inStream,
                         const TC_UniqueArray <C_String> & inNames,
                         const int32_t inFirst,
                         const int32_t inStep) const {
   bool firstPrint = true ;
   C_us_nodeInfo * p = mRootPointer ;
    while (p != NULL) {
     if (((p->mIndex - inFirst) % inStep) == 0) {
       if (firstPrint) {
         firstPrint = false ;
       }else{
         inStream << " " ;
       }
       inStream << (inNames ((p->mIndex - inFirst) / inStep COMMA_HERE)) ;
     }
     p = p->mPtrToNext ;
   }
 }

//---------------------------------------------------------------------------*
//                                                                           *
//       Collect unused elements                                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_us::collectUnusedNodes (void) {
//--- First : clear all addition cache entries
  gCache.clearAllCacheEntries () ;
//--- Second : mark all used elements
  C_us * p = gFirstUS ;
  while (p != NULL) {
    C_us_nodeInfo * infoPtr = p->mRootPointer ;
    while ((infoPtr != NULL) && ! infoPtr->isMarked ()) {
      infoPtr->mark () ;
      infoPtr = infoPtr->mPtrToNext ;
    }
    p = p->mPtrToNextExisting ;
  }
//--- Third : sweep unused objets
  gMap.sweepUnmarkedObjects () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Print VDL summary                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

void C_us::printVDLsummary (AC_OutputStream & inOutputStream) {
  const uint64_t n = getTrivialAddCount () + getCacheSuccessCount () + getCacheFailureCount () ;
  inOutputStream << "Summary of VDL operations :\n"
                    "  " << cStringWithSigned (getVDLnodeCount ())
                 << " VDL used nodes (size " << cStringWithUnsigned (getNodeSize ()) << " bytes) ;\n"
                    "  " << cStringWithSigned (C_us_hashmap::getCreatedObjectCount ())
                 << " VDL created nodes (total size "
                 << cStringWithUnsigned (((uint32_t) C_us_hashmap::getCreatedObjectCount () * getNodeSize ()) / 1024UL)
                 << " kbytes) ;\n"
                    "  " << cStringWithSigned (getNodeComparesCount ()) << " comparisons ;\n"
                    "  " << cStringWithUnsigned (getTrivialAddCount ())
                 << " trivial additions (" << cStringWithUnsigned ((100ULL * getTrivialAddCount ()) / n)
                 << "%) ;\n"
                    "  " << cStringWithUnsigned (getCacheSuccessCount ())
                 << " cache successes (" << cStringWithUnsigned ((100ULL * getCacheSuccessCount ()) / n) << "%) ;\n"
                    "  " << cStringWithUnsigned (getCacheFailureCount ()) << " cache failures ("
                 << cStringWithUnsigned ((100ULL * getCacheFailureCount ()) / n) << "%), including "
                 << cStringWithUnsigned (getCacheOverrideCount ()) << " cache overrides ("
                 << cStringWithUnsigned ((100ULL * getCacheOverrideCount ()) / n) << "%) ;\n"
                    "  " << cStringWithUnsigned (getUnusedCacheEntriesCount ()) << " unused cache entries ("
                 << cStringWithUnsigned ((100ULL * getUnusedCacheEntriesCount ()) / getCacheEntriesCount ())
                 << "%, total entries = " << cStringWithUnsigned (getCacheEntriesCount ()) << ").\n" ;
}

//---------------------------------------------------------------------------*
