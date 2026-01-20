//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//                                                                           *
//  For heap efficiency, elements are allocated by blocks.                   *
//                                                                           *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                           *
//  Copyright (C) 2005 Pierre Molinaro.                                      *
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
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef C_us_hashmap_DEFINED
#define C_us_hashmap_DEFINED

//---------------------------------------------------------------------------*

#include "C_us.h"

//---------------------------------------------------------------------------*

#include <stddef.h>

//---------------------------------------------------------------------------*

class C_us_hashmap {
//--- Constructor
  public : C_us_hashmap (void) ;

//--- Destructor
  public : virtual ~C_us_hashmap (void) ;

//--- Search or insert
  public : C_us::C_us_nodeInfo * search_or_insert (const C_us::C_us_nodeInfo & inInfo,
                                                   bool & outInsertionPerformed) ;

//--- Search
  public : C_us::C_us_nodeInfo * search (const C_us::C_us_nodeInfo & inInfo) ;

//--- Change size
  public : void reallocMap (const int32_t inNewSize) ;

//--- Get map size (in bytes)
  public : uint32_t getMapSizeInBytes (void) const ;

//--- Get marked nodes count
  public : int32_t getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : uint32_t sweepUnmarkedObjects (void) ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Current Entry count
  protected : size_t mEntryCurrentCount ;
  public : inline size_t getHashMapEntryCount (void) const { return mEntryCurrentCount ; }

//--- Get node size (in bytes)
  public : static uint32_t getNodeSize (void) { return (uint32_t) sizeof (MyBlockavltree_element_for_collision) ; }

//--- Get allocated size (in bytes)
  public : static uint32_t getAllocatedSizeInBytes (void) ;

//--- No copy
  private : C_us_hashmap (const C_us_hashmap &) ;
  private : void operator = (const C_us_hashmap &) ;

  private : class MyBlockavltree_element_for_collision ;
  
//------------------- C_TreeForCollision embedded class
  private : class C_TreeForCollision {
//--- Constructor and destructor
  public : C_TreeForCollision (void) ;
  public : virtual ~C_TreeForCollision (void) ;

//--- Search or insert
  public : C_us::C_us_nodeInfo * search_or_insert (const C_us::C_us_nodeInfo & inInfo,
                                                   bool & outInsertionPerformed) ;

//--- Search
  public : inline C_us::C_us_nodeInfo * search (const C_us::C_us_nodeInfo & inInfo) ;

//--- Get marked nodes count
  public : int32_t getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : uint32_t sweepUnmarkedObjects (void) ;

//--- No copy
  private : C_TreeForCollision (const C_TreeForCollision &) ;
  private : void operator = (const C_TreeForCollision &) ;
  
//--- Root
  protected : MyBlockavltree_element_for_collision * mRoot ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Allocation of a block
  public : static void allocBlock (void) ;

//--- Transfer object in a new map array
  public : void transfertElementsInNewMapArray (C_TreeForCollision * inNewMapArray,
                                                const uint32_t inNewSize) ;

//--- Internal methods
  protected : static void rotateLeft (MyBlockavltree_element_for_collision * & ioPtr) ;

  protected : static void rotateRight (MyBlockavltree_element_for_collision * & ioPtr) ;

  protected : C_us::C_us_nodeInfo * avltree_search (MyBlockavltree_element_for_collision * ioRootPointer,
                                                       const C_us::C_us_nodeInfo & inInfo) ;

  protected : C_us::C_us_nodeInfo * recursiveSearchOrInsert (MyBlockavltree_element_for_collision * & ioRootPointer,
                                                             const C_us::C_us_nodeInfo & inInfo,
                                                             bool & outExtension,
                                                             bool & outInsertionPerformed) ;

  protected : static void recursiveInsertElement (MyBlockavltree_element_for_collision * & ioRootPointer,
                                           MyBlockavltree_element_for_collision * const inElementPointer,
                                           bool & outExtension,
                                           bool & outInsertionPerformed) ;

  protected : int32_t internalMarkedNodeCount (const MyBlockavltree_element_for_collision * const inElement) const ;

  protected : uint32_t internalRecursiveSweep (MyBlockavltree_element_for_collision * inElement) ;

  protected : void internalRecursiveUnmark (MyBlockavltree_element_for_collision * inElement) ;

  protected : static void recursiveTransfertElementsInNewMapArray
                                             (MyBlockavltree_element_for_collision * const inElementPointer,
                                              C_TreeForCollision * inNewMapArray,
                                              const uint32_t inNewSize) ;
//--- Friend
  friend class MyBlockavltree_element_for_collision ;
  friend class cAllocInfo ;
} ;

//------------------- MyBlockavltree_element_for_collision embedded class
  private : class MyBlockavltree_element_for_collision {
    public : C_us::C_us_nodeInfo mInfo ;
    public : MyBlockavltree_element_for_collision * mPtrToSup ;
    public : MyBlockavltree_element_for_collision * mPtrToInf ;
    public : int32_t mBalance ;
    public : MyBlockavltree_element_for_collision (const C_us::C_us_nodeInfo & inInfo) :
    mInfo (inInfo),
    mPtrToSup (NULL),
    mPtrToInf (NULL),
    mBalance (0) {
    }
    public : ~MyBlockavltree_element_for_collision (void) {
      delete mPtrToSup ;
      delete mPtrToInf ;
    }
    public : intptr_t compare (const MyBlockavltree_element_for_collision & inElement) const {
      return mInfo.compare (inElement.mInfo) ;
    }
    public : void * operator new (const size_t inByteSize) ;
    public : void operator delete (void * inPtr) ;
    private : MyBlockavltree_element_for_collision (const MyBlockavltree_element_for_collision & inSource) ;
    private : void operator = (const MyBlockavltree_element_for_collision & inSource) ;
  } ;

//------------------- MyBlockavltree_element_for_collision embedded class
  private : class cAllocInfo {
    public : char * * mAllocatedBlockList ;
    public : size_t mAllocatedBlockListSize ;
    public : size_t mAllocatedBlockCount ;
    public : MyBlockavltree_element_for_collision * mFreeList ;
    public : size_t mAllocatedObjectCount ;
    public : size_t mCreatedObjectCount ;
    public : cAllocInfo (void) :
    mAllocatedBlockList (NULL),
    mAllocatedBlockListSize (0),
    mAllocatedBlockCount (0),
    mFreeList (NULL),
    mAllocatedObjectCount (0),
    mCreatedObjectCount (0) {
    }
  } ;

//--- Minimum map array (1 entry)
  protected : C_TreeForCollision mMinimumMapArray ;

//--- map array
  protected : C_TreeForCollision * mMapArray ;

//--- Get created element count
  public : static size_t getCreatedObjectCount (void) { return smAllocInfo.mCreatedObjectCount ; }

//--- Get currently used element count
  public : static size_t getCurrentObjectCount (void) { return smAllocInfo.mAllocatedObjectCount ; }

//--- Allocation info (static variable)
  protected : static cAllocInfo smAllocInfo ;
} ;

//---------------------------------------------------------------------------*

#endif
