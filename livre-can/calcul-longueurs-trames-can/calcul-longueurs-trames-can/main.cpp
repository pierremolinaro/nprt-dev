//
//  main.cpp
//  calcul-longueurs-trames-can
//
//  Created by Pierre Molinaro on 15/05/2016.
//  Copyright © 2016 Pierre Molinaro. All rights reserved.
//
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <utility>

using namespace std ;

//----------------------------------------------------------------------------------------------------------------------

static const int RESULT_COUNT = 10 ;

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
  if (bitEngine.crc () != 0) {
    cout << "CRC error for standard idf 0x" << inIdentifier << ": " << bitEngine.crc () << endl ;
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
    cout << "CRC error for extended idf 0x" << inIdentifier << ": " << bitEngine.crc () << endl ;
  }
  return bitEngine.frameLength () ;
}

//----------------------------------------------------------------------------------------------------------------------

class cZeroByteResult {
  public : uint32_t mIdentifier ;
  public : int mFrameLength ;
  
  public : cZeroByteResult (void) : mIdentifier (0), mFrameLength (0) {}
  
  public : cZeroByteResult (const uint32_t inIdentifier, const int inFrameLength) :
  mIdentifier (inIdentifier),
  mFrameLength (inFrameLength) {
  }
} ;

//----------------------------------------------------------------------------------------------------------------------

static void compareAllStandardFramesZeroData (void) {
  cZeroByteResult shortestFrames [RESULT_COUNT] ;
  cZeroByteResult longuestFrames [RESULT_COUNT] ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    shortestFrames [i].mFrameLength = INT_MAX ;
  }
  for (uint16_t identifier = 0 ; identifier < (1 << 11) ; identifier ++) {
    const cZeroByteResult result (identifier, zeroDataStandardFrameLength (identifier)) ;
    cZeroByteResult r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength < shortestFrames [i].mFrameLength) {
        swap (r, shortestFrames [i]) ;
      }
    }
    r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength > longuestFrames [i].mFrameLength) {
        swap (r, longuestFrames [i]) ;
      }
    }
  }
//--- Display shortest frames
  cout << "Shortest standard frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    cout << dec << shortestFrames [i].mFrameLength << " for identifier 0x"
              << hex << shortestFrames [i].mIdentifier << endl ;
  }
//--- Display longuest frames
  cout << "Longuest standard frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    cout << dec << longuestFrames [i].mFrameLength << " for identifier 0x"
              << hex << longuestFrames [i].mIdentifier << endl ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void compareAllExtendedFramesZeroData (void) {
  cZeroByteResult shortestFrames [RESULT_COUNT] ;
  cZeroByteResult longuestFrames [RESULT_COUNT] ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    shortestFrames [i].mFrameLength = INT_MAX ;
  }
  for (uint32_t identifier = 0 ; identifier < (1 << 29) ; identifier ++) {
    const cZeroByteResult result (identifier, zeroDataExtendedFrameLength (identifier)) ;
    cZeroByteResult r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength < shortestFrames [i].mFrameLength) {
        swap (r, shortestFrames [i]) ;
      }
    }
    r = result ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (r.mFrameLength > longuestFrames [i].mFrameLength) {
        swap (r, longuestFrames [i]) ;
      }
    }
  }
//--- Display shortest frames
  cout << "Shortest extended frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    cout << dec << shortestFrames [i].mFrameLength << " for identifier 0x"
         << hex << shortestFrames [i].mIdentifier << endl ;
  }
//--- Display longuest frames
  cout << "Longuest extended frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    cout << dec << longuestFrames [i].mFrameLength << " for identifier 0x"
         << hex << longuestFrames [i].mIdentifier << endl ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static int oneByteStandardFrameLength (const uint16_t inIdentifier, const uint8_t inByte) {
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
  bitEngine.enterBit (true) ; // dlc0
//--- Enter byte
  for (int idx = 7 ; idx >= 0 ; idx--) { // Data 0
    const bool bit = (inByte & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit ) ;
  }
//--- Enter CRC SEQUENCE
  const uint16_t computed_crc = bitEngine.crc () ;
  for (int idx = 14 ; idx >= 0 ; idx--) {
    const bool bit = (computed_crc & (1 << idx)) != 0 ;
    bitEngine.enterBit (bit) ;
  }
//---
  if (bitEngine.crc () != 0) {
    cout << "CRC error for standard idf 0x" << inIdentifier << ": " << bitEngine.crc () << endl ;
  }
  return bitEngine.frameLength () ;
}

//----------------------------------------------------------------------------------------------------------------------

class cOneByteResult {
  public : uint32_t mIdentifier ;
  public : int mByte ;
  public : int mFrameLength ;
  
  public : cOneByteResult (void) : mIdentifier (0), mByte (0), mFrameLength (0) {}
  
  public : cOneByteResult (const uint32_t inIdentifier, const int inByte, const int inFrameLength) :
  mIdentifier (inIdentifier),
  mByte (inByte),
  mFrameLength (inFrameLength) {
  }
} ;

//----------------------------------------------------------------------------------------------------------------------

static void compareAllStandardFramesOneByteData (void) {
  cOneByteResult shortestFrames [RESULT_COUNT] ;
  cOneByteResult longuestFrames [RESULT_COUNT] ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    shortestFrames [i].mFrameLength = INT_MAX ;
  }
  for (uint16_t identifier = 0 ; identifier < (1 << 11) ; identifier ++) {
    for (int byte = 0 ; byte < 256 ; byte ++) {
      const cOneByteResult result (identifier, byte, oneByteStandardFrameLength (identifier, uint8_t (byte))) ;
      cOneByteResult r = result ;
      for (int i=0 ; i<RESULT_COUNT ; i++) {
        if (r.mFrameLength < shortestFrames [i].mFrameLength) {
          swap (r, shortestFrames [i]) ;
        }
      }
      r = result ;
      for (int i=0 ; i<RESULT_COUNT ; i++) {
        if (r.mFrameLength > longuestFrames [i].mFrameLength) {
          swap (r, longuestFrames [i]) ;
        }
      }
    }
  }
//--- Display shortest frames
  cout << "Shortest one byte standard frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    cout << dec << shortestFrames [i].mFrameLength << " for identifier 0x"
         << hex << shortestFrames [i].mIdentifier
         << ", byte 0x" << shortestFrames [i].mByte
         << endl ;
  }
//--- Display longuest frames
  cout << "Longuest one byte standard frames:\n" ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    cout << dec << longuestFrames [i].mFrameLength << " for identifier 0x"
         << hex << longuestFrames [i].mIdentifier
         << ", byte 0x" << shortestFrames [i].mByte
         << endl ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

int main(int /* argc */, const char * /* argv */ []) {
  compareAllStandardFramesZeroData () ;
  compareAllStandardFramesOneByteData () ;
//  compareAllExtendedFramesZeroData () ;
  return 0 ;
}
//----------------------------------------------------------------------------------------------------------------------
