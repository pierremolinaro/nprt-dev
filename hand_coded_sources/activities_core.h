//---------------------------------------------------------------------------*
//                                                                           *
//  Main program for CAN message scheduler                                   *
//                                                                           *
//  Copyright (C) 2002-2004 Pierre Molinaro (started august 8th, 2002).      *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
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

#include "GenericUniqueArray.h"
#include "ExtendedList-v2.h"

//---------------------------------------------------------------------------*

void
scheduleActivities (const int32_t NoInterButUseB,
                    const bool DependentHasOffset,
                    const GenericUniqueArray <cReadyAtThisInstant> & inReadyAtThisInstant,
                    const GenericUniqueArray <cActivity> & inActivities,
                    const GenericUniqueArray <cResource> & inResource,
                    GenericUniqueArray <cResponseTime> & outResponseTimeArray) ;

void
independantResourcesScheduleActivities (const GenericUniqueArray <cActivity> & inActivities,
                                        GenericUniqueArray <cResponseTime> & outResponseTimeArray) ;

//---------------------------------------------------------------------------*

#endif
