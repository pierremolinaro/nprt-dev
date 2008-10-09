//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//                                                                           *
//  For heap efficiency, elements are allocated by blocks.                   *
//                                                                           *
//  COPY OF ITS INSTANCES IS FORBIDDEN BY REDEFINITION OF COPY CONSTRUCTOR   *
//  AND ASSIGNMENT OPERATOR.                                                 *
//                                                                           *
//  Copyright (C) 2001 Pierre Molinaro.                                      *
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

#include "C_VDL_hashmap.h"
#include "utilities/F_GetPrime.h"

//---------------------------------------------------------------------------*

static const sint32 BLOCK_SIZE = 131072 ;

//---------------------------------------------------------------------------*

C_VDL_hashmap::cAllocInfo C_VDL_hashmap::smAllocInfo ;

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

void * C_VDL_hashmap::MyBlockavltree_element_for_collision::operator new (const size_t /*inByteSize*/) {
  if (smAllocInfo.mFreeList == NULL) {
    C_TreeForCollision::allocBlock () ;
  }
  smAllocInfo.mAllocatedObjectCount ++ ;
  MyBlockavltree_element_for_collision * result = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = smAllocInfo.mFreeList->mPtrToSup ;
  return result ;
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap::MyBlockavltree_element_for_collision::operator delete (void * inPtr) {
  MyBlockavltree_element_for_collision * p = (MyBlockavltree_element_for_collision *) inPtr ;
  p->mPtrToSup = smAllocInfo.mFreeList ;
  smAllocInfo.mFreeList = p ;
  smAllocInfo.mAllocatedObjectCount -- ;
  if (smAllocInfo.mAllocatedObjectCount == 0) {
    for (sint32 i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      delete [] smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = (char * *) NULL ;
    smAllocInfo.mAllocatedBlockCount = 0 ;
    smAllocInfo.mAllocatedBlockListSize = 0 ;
    smAllocInfo.mFreeList = (MyBlockavltree_element_for_collision *) NULL ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::allocBlock (void) {
//--- Realloc block list ?
  if (smAllocInfo.mAllocatedBlockListSize <= smAllocInfo.mAllocatedBlockCount) {
    const sint32 newSize = smAllocInfo.mAllocatedBlockCount + 1024 ;
    char ** newBlockList = new char * [newSize] ;
    for (sint32 i=0 ; i<smAllocInfo.mAllocatedBlockCount ; i++) {
      newBlockList [i] = smAllocInfo.mAllocatedBlockList [i] ;
    }
    delete [] smAllocInfo.mAllocatedBlockList ;
    smAllocInfo.mAllocatedBlockList = newBlockList ;
    smAllocInfo.mAllocatedBlockListSize = newSize ;
  }
//--- Alloc block
  smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] = new char [BLOCK_SIZE] ;
  char * ptr = & (smAllocInfo.mAllocatedBlockList [smAllocInfo.mAllocatedBlockCount] [0]) ;
  smAllocInfo.mAllocatedBlockCount ++ ;
  sint32 blockSize = BLOCK_SIZE ;
  const sint32 ALIGNMENT = 32 ;
//--- Align pointer
  if ((((ptrAsSint) ptr) % ALIGNMENT) != 0) {
    ptr = (char *) (((((ptrAsSint) ptr) / ALIGNMENT) + 1) * ALIGNMENT) ;
    blockSize -= ALIGNMENT ;
  }
  const sint32 nbNewObjects = blockSize / ((sint32) sizeof (MyBlockavltree_element_for_collision)) ;
  for (sint32 i=0 ; i<nbNewObjects ; i++) {
    MyBlockavltree_element_for_collision * newObjectPtr = (MyBlockavltree_element_for_collision *) ptr ;
    newObjectPtr->mPtrToSup = smAllocInfo.mFreeList ;
    smAllocInfo.mFreeList = newObjectPtr ;
    ptr += sizeof (MyBlockavltree_element_for_collision) ;
  }
  smAllocInfo.mCreatedObjectCount += nbNewObjects ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Constructor for avl tree                                            *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDL_hashmap::C_TreeForCollision::C_TreeForCollision (void) :
mRoot (NULL) {
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Destructor for avl tree                                             *
//                                                                           *
//---------------------------------------------------------------------------*

C_VDL_hashmap::C_TreeForCollision::~C_TreeForCollision (void) {
  delete mRoot ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Get allocated size (in bytes)                                       *
//                                                                           *
//---------------------------------------------------------------------------*

uint32 C_VDL_hashmap::getAllocatedSizeInBytes (void) {
  return (uint32) (BLOCK_SIZE * smAllocInfo.mAllocatedBlockCount) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Rotate left                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
rotateLeft (MyBlockavltree_element_for_collision * & ioPtr) {
//--- Rotate 
  MyBlockavltree_element_for_collision * ptr = ioPtr->mPtrToSup ;
  ioPtr->mPtrToSup = ptr->mPtrToInf ;
  ptr->mPtrToInf = ioPtr ;
//--- Update balance 
  if (ptr->mBalance < 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance ++ ;
  if (ioPtr->mBalance > 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance ++ ;
  ioPtr = ptr ;
} 

//---------------------------------------------------------------------------*
//                                                                           *
//       Rotate right                                                        *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
rotateRight (MyBlockavltree_element_for_collision * & ioPtr) {
//--- Rotate 
  MyBlockavltree_element_for_collision * ptr = ioPtr->mPtrToInf ;
  ioPtr->mPtrToInf = ptr->mPtrToSup ;
  ptr->mPtrToSup = ioPtr ;
 //--- Update balance 
  if (ptr->mBalance > 0) {
    ioPtr->mBalance -= ptr->mBalance ;
  }
  ioPtr->mBalance -- ;
  if (ioPtr->mBalance < 0) {
    ptr->mBalance += ioPtr->mBalance ;
  }
  ptr->mBalance-- ;
  ioPtr = ptr ;
}
 
//---------------------------------------------------------------------------*
//                                                                           *
//       Recursive search and insert                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_VDL_hashmap::C_TreeForCollision::
avltree_search (MyBlockavltree_element_for_collision * ioRootPointer,
                 const C_activitiesToSchedule::cVDLnodeInfo & inInfo) {
  C_activitiesToSchedule::cVDLnodeInfo * result = NULL ;
  if (ioRootPointer == NULL) {
    result = (C_activitiesToSchedule::cVDLnodeInfo *) NULL ;
  }else{
    const sint32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = avltree_search (ioRootPointer->mPtrToSup, inInfo) ;
    }else if (comp < 0) {
      result = avltree_search (ioRootPointer->mPtrToInf, inInfo) ;
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
    }
  }
  return result ;
}
 
//---------------------------------------------------------------------------*
//                                                                           *
//       Recursive search and insert                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_VDL_hashmap::C_TreeForCollision::
recursiveSearchOrInsert (MyBlockavltree_element_for_collision * & ioRootPointer,
                         const C_activitiesToSchedule::cVDLnodeInfo & inInfo,
                         bool & outExtension,
                         bool & outInsertionPerformed) {
  C_activitiesToSchedule::cVDLnodeInfo * result ;
  if (ioRootPointer == NULL) {
    ioRootPointer = new MyBlockavltree_element_for_collision (inInfo) ;
    result = & (ioRootPointer->mInfo) ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    outInsertionPerformed = false ;
    const sint32 comp = ioRootPointer->mInfo.compare (inInfo) ;
    if (comp > 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToSup, inInfo, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            rotateRight (ioRootPointer->mPtrToSup) ;
          }
          rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      result = recursiveSearchOrInsert (ioRootPointer->mPtrToInf, inInfo, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      result = & (ioRootPointer->mInfo) ;
      outExtension = false;
    }
  }
  return result ;
}
 
//---------------------------------------------------------------------------*
//                                                                           *
//       Search and insert if not found                                      *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_VDL_hashmap::C_TreeForCollision::
search_or_insert (const C_activitiesToSchedule::cVDLnodeInfo & inInfo,
                  bool & outInsertionPerformed) {
  bool unused = false ;
  return recursiveSearchOrInsert (mRoot, inInfo, unused, outInsertionPerformed) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Search only                                                         *
//                                                                           *
//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_VDL_hashmap::C_TreeForCollision::
search (const C_activitiesToSchedule::cVDLnodeInfo & inInfo) {
  return avltree_search (mRoot, inInfo) ;
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
recursiveInsertElement (MyBlockavltree_element_for_collision * & ioRootPointer,
                        MyBlockavltree_element_for_collision * const inElementPointer,
                        bool & outExtension,
                        bool & outInsertionPerformed) {
  if (ioRootPointer == NULL) {
    ioRootPointer = inElementPointer ;
    inElementPointer->mPtrToInf = NULL ;
    inElementPointer->mPtrToSup = NULL ;
    inElementPointer->mBalance = 0 ;
    outExtension = true ;
    outInsertionPerformed = true ;
  }else{
    const sint32 comp = ioRootPointer->compare (* inElementPointer) ;
    if (comp > 0) {
      recursiveInsertElement (ioRootPointer->mPtrToSup, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance -- ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case -1:
          break;
        case -2:
          if (ioRootPointer->mPtrToSup->mBalance == 1) {
            rotateRight (ioRootPointer->mPtrToSup) ;
          }
          rotateLeft (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else if (comp < 0) {
      recursiveInsertElement (ioRootPointer->mPtrToInf, inElementPointer, outExtension, outInsertionPerformed) ;
      if (outExtension) {
        ioRootPointer->mBalance ++ ;
        switch (ioRootPointer->mBalance) {
        case 0:
          outExtension = false;
          break;
        case 1:
          break;
        case 2:
          if (ioRootPointer->mPtrToInf->mBalance == -1) {
            rotateLeft (ioRootPointer->mPtrToInf) ;
          }
          rotateRight (ioRootPointer) ;
          outExtension = false;
          break;
        default :
          break ;
        }
      }
    }else{ // Found
      outInsertionPerformed = false ;
      outExtension = false;
    }
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Sweep unmarked objects                                              *
//                                                                           *
//---------------------------------------------------------------------------*

uint32 C_VDL_hashmap::C_TreeForCollision::internalRecursiveSweep (C_VDL_hashmap::MyBlockavltree_element_for_collision * inElement) {
  uint32 sweepedNodes = 0 ;
  if (inElement != NULL) {
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToInf) ;
    sweepedNodes += internalRecursiveSweep (inElement->mPtrToSup) ;
    inElement->mPtrToInf = NULL ;
    inElement->mPtrToSup = NULL ;
    inElement->mBalance = 0 ;
    if (inElement->mInfo.isMarked ()) {
      inElement->mInfo.unmark () ;
      bool extension ; // Unused
      bool insertionPerformed ; // Unused
      recursiveInsertElement (mRoot, inElement, extension, insertionPerformed) ;
    }else{
      delete inElement ;
      sweepedNodes ++ ;
    }
  }
  return sweepedNodes ;
}

//---------------------------------------------------------------------------*

uint32 C_VDL_hashmap::C_TreeForCollision::sweepUnmarkedObjects (void) {
  MyBlockavltree_element_for_collision * temporaryRoot = mRoot ;
  mRoot = (MyBlockavltree_element_for_collision *) NULL ;
  return internalRecursiveSweep (temporaryRoot) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       Tranfert objects in a new map array                                 *
//                                                                           *
//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
recursiveTransfertElementsInNewMapArray (MyBlockavltree_element_for_collision * const inElementPointer,
                                         C_TreeForCollision * inNewMapArray,
                                         const uint32 inNewSize) {
  if (inElementPointer != NULL) {
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToInf, inNewMapArray, inNewSize) ;
    recursiveTransfertElementsInNewMapArray (inElementPointer->mPtrToSup, inNewMapArray, inNewSize) ;
    inElementPointer->mPtrToInf = (MyBlockavltree_element_for_collision *) NULL ;
    inElementPointer->mPtrToSup = (MyBlockavltree_element_for_collision *) NULL ;
    inElementPointer->mBalance = 0 ;
    const uint32 hash = inElementPointer->mInfo.getHashCodeForMap () % inNewSize ;
    bool extension ; // Unused
    bool insertionPerformed ; // Unused
    recursiveInsertElement (inNewMapArray [hash].mRoot, inElementPointer, extension, insertionPerformed) ;
  }
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
transfertElementsInNewMapArray (C_TreeForCollision * inNewMapArray,
                                const uint32 inNewSize) {
  recursiveTransfertElementsInNewMapArray (mRoot, inNewMapArray, inNewSize) ;
  mRoot = (MyBlockavltree_element_for_collision *) NULL ;
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
internalRecursiveUnmark (MyBlockavltree_element_for_collision * inElement) {
  if (inElement != NULL) {
    inElement->mInfo.unmark () ;
    internalRecursiveUnmark (inElement->mPtrToInf) ;
    internalRecursiveUnmark (inElement->mPtrToSup) ;
  }
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap::C_TreeForCollision::
unmarkAllObjects (void) {
  internalRecursiveUnmark (mRoot) ;
}

//---------------------------------------------------------------------------*

sint32 C_VDL_hashmap::C_TreeForCollision::
internalMarkedNodeCount (const MyBlockavltree_element_for_collision * const inElement) const {
  sint32 result = 0 ;
  if (inElement != NULL) {
    if (inElement->mInfo.isMarked ()) {
      result ++ ;
    }
    result += internalMarkedNodeCount (inElement->mPtrToInf) ;
    result += internalMarkedNodeCount (inElement->mPtrToSup) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

sint32 C_VDL_hashmap::C_TreeForCollision::
getMarkedNodesCount (void) const {
  return internalMarkedNodeCount (mRoot) ;
}

//---------------------------------------------------------------------------*

C_VDL_hashmap::C_VDL_hashmap (void) :
mEntryCurrentCount (1),
mMinimumMapArray (),
mMapArray (& mMinimumMapArray) {
}

//---------------------------------------------------------------------------*

C_VDL_hashmap::~C_VDL_hashmap (void) {
  if (mEntryCurrentCount > 1) {
    delete [] mMapArray ;
  }
}

//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_VDL_hashmap::
search_or_insert (const C_activitiesToSchedule::cVDLnodeInfo & inInfo,
                  bool & outInsertionPerformed) {
  uint32 hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (uint32) mEntryCurrentCount ;
  return mMapArray [hashCode].search_or_insert (inInfo, outInsertionPerformed) ;
}

//---------------------------------------------------------------------------*

C_activitiesToSchedule::cVDLnodeInfo * C_VDL_hashmap::
search (const C_activitiesToSchedule::cVDLnodeInfo & inInfo) {
  uint32 hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (uint32) mEntryCurrentCount ;
  return mMapArray [hashCode].search (inInfo) ;
}

//---------------------------------------------------------------------------*

uint32 C_VDL_hashmap::sweepUnmarkedObjects (void) {
  uint32 sweepedNodes = 0 ;
  for (sint32 i=0 ; i<mEntryCurrentCount ; i++) {
    sweepedNodes += mMapArray [i].sweepUnmarkedObjects () ;
  }
  return sweepedNodes ;
}

//---------------------------------------------------------------------------*

uint32 C_VDL_hashmap
::getMapSizeInBytes (void) const {
  return ((uint32) mEntryCurrentCount) * sizeof (C_TreeForCollision) ;
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap
::reallocMap (const sint32 inNewSize) {
  const sint32 newSize = (inNewSize < 1) ? 1 : getPrimeGreaterThan (inNewSize) ;
  if (newSize != mEntryCurrentCount) {
    C_TreeForCollision * newMapArray = (newSize > 1) ? new C_TreeForCollision [newSize] : (& mMinimumMapArray) ;
    for (sint32 i=0 ; i<mEntryCurrentCount ; i++) {
      mMapArray [i].transfertElementsInNewMapArray (newMapArray, (uint32) newSize) ;
    }
    if (mEntryCurrentCount > 1) {
      delete [] mMapArray ;
    }
    mMapArray = newMapArray ;
    mEntryCurrentCount = newSize ;
  }
}

//---------------------------------------------------------------------------*

void C_VDL_hashmap::unmarkAllObjects (void) {
  for (sint32 i=0 ; i<mEntryCurrentCount ; i++) {
    mMapArray [i].unmarkAllObjects () ;
  }
}

//---------------------------------------------------------------------------*

sint32 C_VDL_hashmap::getMarkedNodesCount (void) const {
  sint32 count = 0 ;
  for (sint32 i=0 ; i<mEntryCurrentCount ; i++) {
    count += mMapArray [i].getMarkedNodesCount () ;
  }
  return count ;
}

//---------------------------------------------------------------------------*
