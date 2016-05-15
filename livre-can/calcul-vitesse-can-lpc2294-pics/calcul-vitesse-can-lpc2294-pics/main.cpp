//
//  main.cpp
//  calcul-vitesse-can-lpc2294-pics
//
//  Created by Pierre Molinaro on 23/07/13.
//  Copyright (c) 2013 ECN / IRCCyN. All rights reserved.
//
//-----------------------------------------------------------------------------*

#include <iostream>
#include <math.h>

//-----------------------------------------------------------------------------*

typedef struct {
  int mBRP ;
  int mB ;
  double mDureeBit ;
} cConfiguration ;

//-----------------------------------------------------------------------------*

typedef struct {
  int mIdxPIC ;
  int mIdxLPC ;
  double mEcart ;
} cMeilleureCombinaison ;

const int kNombreMeilleuresCombinaisons = 10 ;

//-----------------------------------------------------------------------------*

typedef struct {
  int mIdxLPC ;
  double mEcart ;
} cMeilleureConfiguration ;

const int kNombreMeilleuresConfigurations = 10 ;

//-----------------------------------------------------------------------------*

int main (int argc, const char * argv []) {
  const double quartzPIC = 40.0 ;
  printf ("**** Configurations PIC (horloge %g MHz) :\n", quartzPIC) ;
  printf ("* diviseur *    B  * Durée bit\n") ;
  cConfiguration configurationsPIC [1000] ;
  int idx = 0 ;
  for (int diviseur=1 ; diviseur<=50 ; diviseur++) {
    for (int b=7 ; b<=25 ; b++) {
      const double dureeBit = ((double) (diviseur * b)) * 2.0 / quartzPIC ;
      if ((dureeBit >= 1.0) && (dureeBit <= 8.0)) {
        printf ("|   %2d     |  %3d  | %g µs\n", diviseur, b, dureeBit) ;
        configurationsPIC [idx].mBRP = diviseur ;
        configurationsPIC [idx].mB = b ;
        configurationsPIC [idx].mDureeBit = dureeBit ;
        idx ++ ;
      }
    }
  }
  const int nbConfigurationsPIC = idx ;
  printf ("%d configurations pour le PIC\n", nbConfigurationsPIC) ;
//--- LPC 2294
  const double horlogeLPC2294 = 58.9824 ;
  printf ("**** Configurations LPC2294 (horloge %g MHz) :\n", horlogeLPC2294) ;
  printf ("* diviseur *    B  * Durée bit\n") ;
  cConfiguration configurationsLPC2294 [3000] ;
  idx = 0 ;
  for (int diviseur=1 ; diviseur<70 ; diviseur++) {
    for (int b=7 ; b<=25 ; b++) {
      const double dureeBit = ((double) (diviseur * b)) / horlogeLPC2294 ;
      if ((dureeBit >= 0.9) && (dureeBit <= 9.0)) {
        printf ("|   %2d     |  %3d  | %g µs\n", diviseur, b, dureeBit) ;
        configurationsLPC2294 [idx].mBRP = diviseur ;
        configurationsLPC2294 [idx].mB = b ;
        configurationsLPC2294 [idx].mDureeBit = dureeBit ;
        idx ++ ;
      }
    }
  } 
  const int nbConfigurationsLPC2294 = idx ;
  printf ("%d configurations pour le LPC\n", nbConfigurationsLPC2294) ;
//--- Calculer les deux configurations les plus proches entre 1 Mbit/s et 500 kbit/s
  cMeilleureCombinaison meilleuresCombinaisons [kNombreMeilleuresCombinaisons] ;
  for (int i=0 ; i<kNombreMeilleuresCombinaisons ; i++) {
    meilleuresCombinaisons [i].mEcart = 10000.0 ;
  }
  printf ("*************** Entre 1 Mbit/s et 100 kbit/s\n") ;
  for (int pic=0 ; pic<nbConfigurationsPIC ; pic++) {
    if ((configurationsPIC [pic].mDureeBit >= 1.0) && (configurationsPIC [pic].mDureeBit <= 2.0)) {
      for (int lpc=0 ; lpc<nbConfigurationsLPC2294 ; lpc++) {
        cMeilleureCombinaison candidat = {
          pic,
          lpc,
          2.0 * fabs (configurationsPIC [pic].mDureeBit - configurationsLPC2294 [lpc].mDureeBit) / (configurationsPIC [pic].mDureeBit + configurationsLPC2294 [lpc].mDureeBit)
        } ;
        for (int i=0 ; i<kNombreMeilleuresCombinaisons ; i++) {
          if (candidat.mEcart < meilleuresCombinaisons [i].mEcart) {
            cMeilleureCombinaison t = meilleuresCombinaisons [i] ;
            meilleuresCombinaisons [i] = candidat ;
            candidat = t ;
          }        
        }
      }
    }
  }
//--- Affichage
  for (int i=kNombreMeilleuresCombinaisons-1 ; i>=0 ; i--) {
    const int idxPIC = meilleuresCombinaisons [i].mIdxPIC ;
    const int idxLPC = meilleuresCombinaisons [i].mIdxLPC ;
    printf ("Combinaison (ecart %g ppm) :\n", meilleuresCombinaisons [i].mEcart * 1E6) ;
    printf ("  PIC : diviseur=%d, B=%d, duree=%g µs, %g kbit/s\n",
            configurationsPIC [idxPIC].mBRP,
            configurationsPIC [idxPIC].mB,
            configurationsPIC [idxPIC].mDureeBit,
            1000.0 / configurationsPIC [idxPIC].mDureeBit) ;
    printf ("  LPC : diviseur=%d, B=%d, duree=%g µs, %g kbit/s\n",
            configurationsLPC2294 [idxLPC].mBRP,
            configurationsLPC2294 [idxLPC].mB,
            configurationsLPC2294 [idxLPC].mDureeBit,
            1000.0 / configurationsLPC2294 [idxLPC].mDureeBit) ;
  }
//--- Calculer les deux configurations les plus proches entre 250 kbit/s et 125 kbit/s
  printf ("*************** Entre 250 kbit/s et 125 kbit/s\n") ;
  for (int i=0 ; i<kNombreMeilleuresCombinaisons ; i++) {
    meilleuresCombinaisons [i].mEcart = 10000.0 ;
  }
  for (int pic=0 ; pic<nbConfigurationsPIC ; pic++) {
    if ((configurationsPIC [pic].mDureeBit >= 4.0) && (configurationsPIC [pic].mDureeBit <= 8.0)) {
      for (int lpc=0 ; lpc<nbConfigurationsLPC2294 ; lpc++) {
        cMeilleureCombinaison candidat = {
          pic,
          lpc,
          2.0 * fabs (configurationsPIC [pic].mDureeBit - configurationsLPC2294 [lpc].mDureeBit) / (configurationsPIC [pic].mDureeBit + configurationsLPC2294 [lpc].mDureeBit)
        } ;
        for (int i=0 ; i<kNombreMeilleuresCombinaisons ; i++) {
          if (candidat.mEcart < meilleuresCombinaisons [i].mEcart) {
            cMeilleureCombinaison t = meilleuresCombinaisons [i] ;
            meilleuresCombinaisons [i] = candidat ;
            candidat = t ;
          }        
        }
      }
    }
  }
//--- Affichage
  for (int i=kNombreMeilleuresCombinaisons-1 ; i>=0 ; i--) {
    const int idxPIC = meilleuresCombinaisons [i].mIdxPIC ;
    const int idxLPC = meilleuresCombinaisons [i].mIdxLPC ;
    printf ("Combinaison (ecart %g ppm) :\n", meilleuresCombinaisons [i].mEcart * 1E6) ;
    printf ("  PIC : diviseur=%d, B=%d, duree=%g µs, %g kbit/s\n",
            configurationsPIC [idxPIC].mBRP,
            configurationsPIC [idxPIC].mB,
            configurationsPIC [idxPIC].mDureeBit,
            1000.0 / configurationsPIC [idxPIC].mDureeBit) ;
    printf ("  LPC : diviseur=%d, B=%d, duree=%g µs, %g kbit/s\n",
            configurationsLPC2294 [idxLPC].mBRP,
            configurationsLPC2294 [idxLPC].mB,
            configurationsLPC2294 [idxLPC].mDureeBit,
            1000.0 / configurationsLPC2294 [idxLPC].mDureeBit) ;
  }
//--- Quelle est la configuration LPC la plus proche de 125 kbit/s ?
  printf ("*************** Configuration LPC la plus proche de 125 kbit/s\n") ;
  cMeilleureConfiguration meilleuresConfigs [kNombreMeilleuresConfigurations] ;
  for (int i=0 ; i<kNombreMeilleuresConfigurations ; i++) {
    meilleuresConfigs [i].mEcart = 10000.0 ;
  }
   for (int lpc=0 ; lpc<nbConfigurationsLPC2294 ; lpc++) {
    cMeilleureConfiguration candidat = {
      lpc,
      2.0 * fabs (8.0 - configurationsLPC2294 [lpc].mDureeBit) / (8.0 + configurationsLPC2294 [lpc].mDureeBit)
    } ;
    for (int i=0 ; i<kNombreMeilleuresConfigurations ; i++) {
      if (candidat.mEcart < meilleuresConfigs [i].mEcart) {
        cMeilleureConfiguration t = meilleuresConfigs [i] ;
        meilleuresConfigs [i] = candidat ;
        candidat = t ;
      }
    }
  }
//--- Affichage
  for (int i=kNombreMeilleuresConfigurations-1 ; i>=0 ; i--) {
    const int idxLPC = meilleuresConfigs [i].mIdxLPC ;
    printf ("Configuration (ecart %g ppm) :\n", meilleuresConfigs [i].mEcart * 1E6) ;
    printf ("  LPC : diviseur=%d, B=%d, duree=%g µs, %g kbit/s\n",
            configurationsLPC2294 [idxLPC].mBRP,
            configurationsLPC2294 [idxLPC].mB,
            configurationsLPC2294 [idxLPC].mDureeBit,
            1000.0 / configurationsLPC2294 [idxLPC].mDureeBit) ;
  }
//--- Quelle est la configuration LPC la plus proche de 1 Mbit/s ?
  printf ("*************** Configuration LPC la plus proche de 1Mbit/s\n") ;
  for (int i=0 ; i<kNombreMeilleuresConfigurations ; i++) {
    meilleuresConfigs [i].mEcart = 10000.0 ;
  }
   for (int lpc=0 ; lpc<nbConfigurationsLPC2294 ; lpc++) {
    cMeilleureConfiguration candidat = {
      lpc,
      2.0 * fabs (1.0 - configurationsLPC2294 [lpc].mDureeBit) / (1.0 + configurationsLPC2294 [lpc].mDureeBit)
    } ;
    for (int i=0 ; i<kNombreMeilleuresConfigurations ; i++) {
      if (candidat.mEcart < meilleuresConfigs [i].mEcart) {
        cMeilleureConfiguration t = meilleuresConfigs [i] ;
        meilleuresConfigs [i] = candidat ;
        candidat = t ;
      }
    }
  }
//--- Affichage
  for (int i=kNombreMeilleuresConfigurations-1 ; i>=0 ; i--) {
    const int idxLPC = meilleuresConfigs [i].mIdxLPC ;
    printf ("Configuration (ecart %g ppm) :\n", meilleuresConfigs [i].mEcart * 1E6) ;
    printf ("  LPC : diviseur=%d, B=%d, duree=%g µs, %g kbit/s\n",
            configurationsLPC2294 [idxLPC].mBRP,
            configurationsLPC2294 [idxLPC].mB,
            configurationsLPC2294 [idxLPC].mDureeBit,
            1000.0 / configurationsLPC2294 [idxLPC].mDureeBit) ;
  }
}

//-----------------------------------------------------------------------------*
