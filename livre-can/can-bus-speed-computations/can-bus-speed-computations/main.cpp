//
//  main.cpp
//  can-bus-speed-computations
//
//  Created by Pierre Molinaro on 15/05/2016.
//  Copyright © 2016 Pierre Molinaro. All rights reserved.
//
//----------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <math.h>

using namespace std ;

//----------------------------------------------------------------------------------------------------------------------

class cSetting {
  private : double mClockFrequency ; // In MHz
  private : int mPrescaler ;
  private : int mB ;
  
  public : cSetting (const double inClockFrequency, const int inPrescaler, const int inB) :
  mClockFrequency (inClockFrequency),
  mPrescaler (inPrescaler),
  mB (inB) {
  }
  
  public : cSetting (void) :
  mClockFrequency (1E-6), // Very low frequency: 1 Hz
  mPrescaler (1),
  mB (1) {
  }

  public : double bitDuration (void) const { return ((double) (mPrescaler * mB)) / mClockFrequency ; } // In µs

  public : double busFrequency (void) const { return 1.0 / bitDuration () ; } // In Mbit/s

  public : double distanceFrom (const double inBitDuration) const { return fabs (inBitDuration - bitDuration ()) ; } // In µs

  public : void display (void) const {
    printf ("| %3d | %3d |  %8.4f µs ", mPrescaler, mB, bitDuration ()) ;
  }
} ;

//----------------------------------------------------------------------------------------------------------------------

static vector <cSetting> computeSettings (const double inClockFrequency,
                                          const int inClockDivisorMin,
                                          const int inClockDivisorMax,
                                          const int inBMin,
                                          const int inBMax) {
  vector <cSetting> allSettings ;
  for (int divisor = inClockDivisorMin ; divisor <= inClockDivisorMax ; divisor ++) {
    for (int b = inBMin ; b <= inBMax ; b ++) {
      const cSetting setting (inClockFrequency, divisor, b) ;
      const double bitDuration = setting.bitDuration () ;
      if ((bitDuration >= 1.0) && (bitDuration <= 2.0)) {
        allSettings.push_back (setting) ;
      }
    }
  }
  return allSettings ;
}

//----------------------------------------------------------------------------------------------------------------------

static void displayBestSettings (const vector <cSetting> & inAllSettings, const double inNominalBitDuration) {
  const int RESULT_COUNT = 10 ;
  cSetting resultArray [RESULT_COUNT] ;
  for (auto it = inAllSettings.cbegin () ; it != inAllSettings.cend () ; ++it) {
    cSetting setting = * it ;
    for (int i=0 ; i<RESULT_COUNT ; i++) {
      if (setting.distanceFrom (inNominalBitDuration) < resultArray [i].distanceFrom (inNominalBitDuration)) {
        swap <cSetting> (setting, resultArray [i]) ;
      }
    }
  }
//--- Display results
  cout << "Best settings for bit duration " << inNominalBitDuration << " µs, frequency " << (1.0 / inNominalBitDuration) << " MHz\n" ;
  printf ("|   D |   B | Bit duration |  distance\n") ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    resultArray [i].display () ;
    const double perCent = 100.0 * resultArray [i].distanceFrom (inNominalBitDuration) / inNominalBitDuration ;
    printf ("|  %7.4f %%\n", perCent) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static double distanceBetweenSettings (const pair <cSetting, cSetting> & inSetting) {
  const double nominal = (inSetting.first.bitDuration () + inSetting.second.bitDuration ()) / 2.0 ;
  const double distance = fabs (inSetting.first.bitDuration () - inSetting.second.bitDuration ()) ;
  return distance / nominal ;
}

//----------------------------------------------------------------------------------------------------------------------

static void displayBestSettings (const vector <cSetting> & inAllSettings1,
                                 const vector <cSetting> & inAllSettings2) {
  const int RESULT_COUNT = 30 ;
  pair <cSetting, cSetting> resultArray [RESULT_COUNT] ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    resultArray [i].second = cSetting (1.0, 1, 1) ;
  }
  for (auto it1 = inAllSettings1.cbegin () ; it1 != inAllSettings1.cend () ; ++it1) {
    for (auto it2 = inAllSettings2.cbegin () ; it2 != inAllSettings2.cend () ; ++it2) {
      pair <cSetting, cSetting> setting (* it1, * it2) ;
      for (int i=0 ; i<RESULT_COUNT ; i++) {
        const double d = distanceBetweenSettings (setting) ;
        if (d < distanceBetweenSettings (resultArray [i])) {
          swap <cSetting> (setting, resultArray [i]) ;
        }
      }
    }
  }
//--- Display results
  printf ("| Frequency | Distance | Divisor |    B  | Bit duration | Divisor |    B  | Bit duration\n") ;
  for (int i=0 ; i<RESULT_COUNT ; i++) {
    const double d = fabs (resultArray [i].first.bitDuration () - resultArray [i].second.bitDuration ()) ;
    const double nominal = (resultArray [i].first.bitDuration () + resultArray [i].second.bitDuration ()) / 2.0 ;
    const double perCent = 100.0 * d / nominal ;
    printf ("| %5.1f kHz | %6.4f %% ", 1000.0 / nominal, perCent) ;
    resultArray [i].first.display () ;
    resultArray [i].second.display () ;
    printf ("\n") ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

int main (int /* argc */, const char * /* argv */ []) {
//--- Compute all settings for LPC2294
  const vector <cSetting> allLPC2294settings = computeSettings (58.9824, 1, 512, 5, 27) ;
  cout << "LPC2294: " << allLPC2294settings.size () << " configurations\n" ;
//------------------------------------------------ Compute nearest setting from a given bit time
  const double nominalBitDuration = 1.0 / .577 ; // in µs
  displayBestSettings (allLPC2294settings, nominalBitDuration) ;
//--- Compute all settings for PIC
  const vector <cSetting> allPICsettings = computeSettings (64.0, 1, 64, 4, 25) ;
  cout << "PIC: " << allPICsettings.size () << " configurations\n" ;
//------------------------------------------------ Compute nearest settings for LPC2294 and PIC
  displayBestSettings (allLPC2294settings, allPICsettings) ;
//---
  return 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
