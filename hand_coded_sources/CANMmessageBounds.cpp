#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "CANMessageBounds.h"

static bool ComputeWithMaxNumberOfBitStuffing = true;

//---------------------------------------------------------------------------*

static uint32 getStandardDataMessageMinSize ( uint32 inLengthInBytes) {
static const unsigned char kStandardMessageMinSize [9] = {
 //   0, 1, 2, 3, 4, 5, 6, 7, 8 }; 
  47, 55, 63, 71, 79, 87, 95, 103, 111} ;
  return kStandardMessageMinSize [inLengthInBytes] ;
}

//---------------------------------------------------------------------------*

static uint32 getExtendedDataMessageMinSize ( uint32 inLengthInBytes) {
static const unsigned char kExtendedMessageMinSize [9] = {
  67, 75, 83, 91, 99, 107, 115, 123, 131} ;
  return kExtendedMessageMinSize [inLengthInBytes] ;
}

//---------------------------------------------------------------------------*

static uint32 getStandardDataMessageMaxSize ( uint32 inLengthInBytes) {
static const unsigned char kStandardMessageMaxSize [9] = {
 //0, 1, 2, 3, 4, 5, 6, 7, 8 }; 
 55, 65, 75, 85, 95, 105, 115, 125, 135} ;
  return kStandardMessageMaxSize [inLengthInBytes] ;
}

//---------------------------------------------------------------------------*
static uint32 getExtendedDataMessageMaxSize ( uint32 inLengthInBytes) {
static const unsigned char kExtendedMessageMaxSize [9] = {
  80, 90, 100, 110, 120, 130, 140, 150, 160} ;
  return  kExtendedMessageMaxSize [inLengthInBytes] ;
}

//---------------------------------------------------------------------------*
static uint32
computeMaxStuffBitsForStandardMessage (uint32 inPriority,
                                   uint32 inLengthInBytes) {
  
  uint32 bitStream = 0 ;
//--- Enter DLC
  uint32 x = inLengthInBytes ;
  for (uint32 i=0 ; i<3 ; i++) {
    bitStream <<= 1 ;
    bitStream |= (x & 1) ;
    x >>= 1 ;
  }
//--- Enter r0, IDE et RTR (3 zero-bits)
  bitStream <<= 1 ;
//--- Enter Identifier
  x = inPriority ;
  for (uint32 i=0 ; i<11 ; i++) {
    bitStream <<= 1 ;
    bitStream |= (x & 1) ;
    x >>= 1 ;
  }
//--- Enter SOF
  bitStream <<= 1 ;
//--- Now compute bit stuffs
  uint32 bitStuffs = 0 ;
  bool currentBitValue = false ;
  uint32 currentCount = 0 ;
  for (uint32 i=0 ; i<19 ; i++) {
    bool c = (bitStream & 1) != 0 ;
    if (currentBitValue == c) {
      currentCount ++ ;
      if (currentCount == 5) {
        bitStuffs ++ ;
        currentCount = 1 ;
        currentBitValue = ! c ;
      }
    }else{
      currentCount = 1 ;
      currentBitValue = c ;
    }
    bitStream >>= 1 ;  
  }
//--- Return bitStuffs ; 
  return bitStuffs ;
}
//---------------------------------------------------------------------------*

static uint32
computeMaxStuffBitsForExtendedMessage (uint32 inPriority,
                                     uint32 inLengthInBytes) {

  uint64 bitStream = 0 ;
//--- Enter DLC
  uint32 x = inLengthInBytes ;
  for (uint32 i=0 ; i<3 ; i++) {
    bitStream <<= 1 ;
    bitStream |= (x & 1) ;
    x >>= 1 ;
  }
//--- Enter r0, IDE et RTR (3 zero-bits)
  bitStream <<= 1 ;
//--- Enter 18 least significant bits of Identifier
  x = inPriority ;
  for (uint32 i=0 ; i<18 ; i++) {
    bitStream <<= 1 ;
    bitStream |= (x & 1) ;
    x >>= 1 ;
  }
//--- Enter IDE and SRR (2 1-bit)
  bitStream <<= 2 ;
  bitStream |= 3 ;
//--- Enter 11 most significant bits of Identifier
  for (uint32 i=0 ; i<11 ; i++) {
    bitStream <<= 1 ;
    bitStream |= (x & 1) ;
    x >>= 1 ;
  }
//--- Enter SOF
  bitStream <<= 1 ;
//--- Now compute bit stuffs
  uint32 bitStuffs = 0 ;
  bool currentBitValue = false ;
  uint32 currentCount = 0 ;
  for (uint32 i=0 ; i<19 ; i++) {
    bool c = (bitStream & 1) != 0 ;
    if (currentBitValue == c) {
      currentCount ++ ;
      if (currentCount == 5) {
        bitStuffs ++ ;
        currentCount = 1 ;
        currentBitValue = ! c ;
      }
    }else{
      currentCount = 1 ;
      currentBitValue = c ;
    }
    bitStream >>= 1 ;  
  }
//--- Return bitStuffs count
  return bitStuffs ;
}

//---------------------------------------------------------------------------*

sint32 minCANMessageTime(const char c, const uint32 priority, const uint32 Num_Bytes){

  uint32 minTransTime = 0 ;
     switch (c) {
      case 'S' :
       if (ComputeWithMaxNumberOfBitStuffing) {
            minTransTime = getStandardDataMessageMinSize (Num_Bytes) ;
           }else{
            minTransTime = getStandardDataMessageMinSize (Num_Bytes)
              + computeMaxStuffBitsForStandardMessage (priority,Num_Bytes) ;
           }
        break ;
      case 'X' :
          if (ComputeWithMaxNumberOfBitStuffing) {
            minTransTime = getExtendedDataMessageMinSize (Num_Bytes) ;
          }else{
            minTransTime = getExtendedDataMessageMinSize (Num_Bytes)
              + computeMaxStuffBitsForExtendedMessage (priority,Num_Bytes) ;
           }
        break ;
      
  }
  return (sint32) minTransTime;     
}

//---------------------------------------------------------------------------*

sint32 maxCANMessageTime(const char c, const uint32 minTrTime, const uint32 Num_Bytes){

  uint32 maxTransTime = 0 ;
     switch (c) {
      case 'S' :
       if (ComputeWithMaxNumberOfBitStuffing) {
            maxTransTime = getStandardDataMessageMaxSize (Num_Bytes) ;
        }else{
            maxTransTime = minTrTime  + ((Num_Bytes * 8 + 16) / 5) ;
        }
        break ;
      case 'X' :
          if (ComputeWithMaxNumberOfBitStuffing) {
               maxTransTime = getExtendedDataMessageMaxSize (Num_Bytes) ;
        }else{
             maxTransTime = minTrTime + ((Num_Bytes * 8 + 16) / 5) ;
        }
        break ;
   }
      
    return (sint32) maxTransTime;
}

/*---------------------------------------------------------------------------*/ 