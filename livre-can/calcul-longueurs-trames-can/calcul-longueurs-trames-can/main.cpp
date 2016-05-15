//
//  main.cpp
//  calcul-longueurs-trames-can
//
//  Created by Pierre Molinaro on 15/05/2016.
//  Copyright © 2016 Pierre Molinaro. All rights reserved.
//
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>

//----------------------------------------------------------------------------------------------------------------------

class cBitEngine {
  public : cBitEngine (void) :
  mCRC (0),
  mFrameLength (13),
  mLastBitValue (true),
  mConsecutiveBitCount (0) {
  }
  
  public : void enterBit (const bool inBit) {
  //--- Compute CRC
    const bool bit14 = (mCRC & (1 << 14)) != 0 ;
    const bool crc_nxt = inBit ^ bit14 ;
    mCRC <<= 1 ;
    mCRC &= (1 << 15) - 1 ;
    if (crc_nxt) {
      mCRC ^= 0x4599U ;
    }
  //--- Emit bit
    mFrameLength ++ ;
  //--- add a stuff bit ?
    if (mLastBitValue == inBit) {
      mConsecutiveBitCount ++ ;
      if (mConsecutiveBitCount == 5) {
        mFrameLength ++ ; // Emit S bit
        mLastBitValue ^= true ;
        mConsecutiveBitCount = 1 ;
      }
    }else{
      mLastBitValue = inBit ;
      mConsecutiveBitCount = 1 ;
    }
  }

  private : uint16_t mCRC ;
  public : uint16_t crc (void) const { return mCRC ; }
  
  private : int mFrameLength ;
  public : int frameLength (void) const { return mFrameLength ; }
  
  private : bool mLastBitValue ;
  private : int mConsecutiveBitCount ;
} ;

//----------------------------------------------------------------------------------------------------------------------

static int zeroDataStandardFrameLength (const uint16_t inIdentifier) {
  cBitEngine bitEngine ;
  bitEngine.enterBit (false) ; // SOF
  for (int idx = 10 ; idx >= 0 ; idx--) { // Identifier
    const bool bit = (inIdentifier & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit ) ;
  }
  bitEngine.enterBit (false) ; // RTR
  bitEngine.enterBit (false) ; // r1
  bitEngine.enterBit (false) ; // r0
  bitEngine.enterBit (false) ; // dlc3
  bitEngine.enterBit (false) ; // dlc2
  bitEngine.enterBit (false) ; // dlc1
  bitEngine.enterBit (false) ; // dlc0
//--- Enter CRC SEQUENCE
  const uint16_t computed_crc = bitEngine.crc () ;
  for (int idx = 14 ; idx >= 0 ; idx--) {
    const bool bit = (computed_crc & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit) ;
  }
//---
//---
  if (bitEngine.crc () != 0) {
    std::cout << "CRC error for standard idf 0x" << inIdentifier << ": " << bitEngine.crc () << std::endl ;
  }
  return bitEngine.frameLength () ;
}

//----------------------------------------------------------------------------------------------------------------------

static int zeroDataExtendedFrameLength (const uint32_t inIdentifier) {
  cBitEngine bitEngine ;
  bitEngine.enterBit (false) ; // SOF
  for (int idx = 28 ; idx >= 18 ; idx--) { // Identifier
    const bool bit = (inIdentifier & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit ) ;
  }
  bitEngine.enterBit (true) ; // SRR
  bitEngine.enterBit (true) ; // IDE
  for (int idx = 17 ; idx >= 0 ; idx--) { // Identifier
    const bool bit = (inIdentifier & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit ) ;
  }
  bitEngine.enterBit (false) ; // r1
  bitEngine.enterBit (false) ; // r0
  bitEngine.enterBit (false) ; // dlc3
  bitEngine.enterBit (false) ; // dlc2
  bitEngine.enterBit (false) ; // dlc1
  bitEngine.enterBit (false) ; // dlc0
//--- Enter CRC SEQUENCE
  const uint16_t computed_crc = bitEngine.crc () ;
  for (int idx = 14 ; idx >= 0 ; idx--) {
    const bool bit = (computed_crc & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit) ;
  }
//---
  if (bitEngine.crc () != 0) {
    std::cout << "CRC error for extended idf 0x" << inIdentifier << ": " << bitEngine.crc () << std::endl ;
  }
  return bitEngine.frameLength () ;
}

//----------------------------------------------------------------------------------------------------------------------

class cResult {
  public : uint32_t mIdentifier ;
  public : int mFrameLength ;
  
  public : cResult (void) : mIdentifier (0), mFrameLength (0) {}
  
  public : cResult (const uint32_t inIdentifier, const int inFrameLength) :
  mIdentifier (inIdentifier),
  mFrameLength (inFrameLength) {
  }
} ;

//----------------------------------------------------------------------------------------------------------------------

const int RESULT_COUNT = 10 ;

//----------------------------------------------------------------------------------------------------------------------

static void compareAllStandardFramesZeroData (void) {
  cResult shortestFrames [RESULT_COUNT] ;
  cResult longuestFrames [RESULT_COUNT] ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    shortestFrames [i].mFrameLength = INT_MAX ;
  }
  for (uint16_t identifier = 0 ; identifier < (1 << 11) ; identifier ++) {
    const cResult result (identifier, zeroDataStandardFrameLength (identifier)) ;
    cResult r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength < shortestFrames [i].mFrameLength) {
        cResult temp = r ; r = shortestFrames [i] ; shortestFrames [i] = temp ;
      }
    }
    r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength > longuestFrames [i].mFrameLength) {
        cResult temp = r ; r = longuestFrames [i] ; longuestFrames [i] = temp ;
      }
    }
  }
//--- Display shortest frames
  std::cout << "Shortest standard frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    std::cout << std::dec << shortestFrames [i].mFrameLength << " for identifier 0x"
              << std::hex << shortestFrames [i].mIdentifier << std::endl ;
  }
//--- Display longuest frames
  std::cout << "Longuest standard frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    std::cout << std::dec << longuestFrames [i].mFrameLength << " for identifier 0x"
              << std::hex << longuestFrames [i].mIdentifier << std::endl ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void compareAllExtendedFramesZeroData (void) {
  cResult shortestFrames [RESULT_COUNT] ;
  cResult longuestFrames [RESULT_COUNT] ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    shortestFrames [i].mFrameLength = INT_MAX ;
  }
  for (uint32_t identifier = 0 ; identifier < (1 << 29) ; identifier ++) {
    const cResult result (identifier, zeroDataExtendedFrameLength (identifier)) ;
    cResult r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength < shortestFrames [i].mFrameLength) {
        cResult temp = r ; r = shortestFrames [i] ; shortestFrames [i] = temp ;
      }
    }
    r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength > longuestFrames [i].mFrameLength) {
        cResult temp = r ; r = longuestFrames [i] ; longuestFrames [i] = temp ;
      }
    }
  }
//--- Display shortest frames
  std::cout << "Shortest extended frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    std::cout << std::dec << shortestFrames [i].mFrameLength << " for identifier 0x"
              << std::hex << shortestFrames [i].mIdentifier << std::endl ;
  }
//--- Display longuest frames
  std::cout << "Longuest extended frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    std::cout << std::dec << longuestFrames [i].mFrameLength << " for identifier 0x"
              << std::hex << longuestFrames [i].mIdentifier << std::endl ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

int main(int /* argc */, const char * /* argv */ []) {
  compareAllStandardFramesZeroData () ;
  compareAllExtendedFramesZeroData () ;
  return 0 ;
}
//----------------------------------------------------------------------------------------------------------------------
