//---------------------------------------------------------------------------*
//                                                                           *
//  Main program for CAN message scheduler                                   *
//                                                                           *
//  Copyright (C) 2002-2004 Pierre Molinaro (started august 8th, 2002).      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
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

#ifndef ACTIVITIES_CORE_DEFINED
#define ACTIVITIES_CORE_DEFINED

#include "generic_arraies/TC_unique_grow_array.h"
#include "ExtendedList.h"

//---------------------------------------------------------------------------*

void
scheduleActivities (const sint32 NoInterButUseB,
                    const bool DependentHasOffset,
                    const TC_unique_grow_array <cReadyAtThisInstant> & inReadyAtThisInstant,
                    const TC_unique_grow_array <cActivity> & inActivities,
                    const TC_unique_grow_array <cResource> & inResource,
                    TC_unique_grow_array <cResponseTime> & outResponseTimeArray) ;

void
independantResourcesScheduleActivities (const TC_unique_grow_array <cActivity> & inActivities,
                                        TC_unique_grow_array <cResponseTime> & outResponseTimeArray) ;

//---------------------------------------------------------------------------*

#endif
