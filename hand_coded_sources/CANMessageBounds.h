#ifdef _cplusplus
extern "C" {
#endif

#ifndef CANMESSAGEBOUNDS_H
#define CANMESSAGEBOUNDS_H

#include "utilities/M_machine.h"

PMSInt32 minCANMessageTime(const char c, const PMUInt32 priority, const PMUInt32 Num_Bytes) ;

PMSInt32 maxCANMessageTime(const char c, const PMUInt32 minTrTime, const PMUInt32 Num_Bytes) ;


#endif

#ifdef _cplusplus
}
#endif
