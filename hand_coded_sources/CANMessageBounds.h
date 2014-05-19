#ifdef _cplusplus
extern "C" {
#endif

#ifndef CANMESSAGEBOUNDS_H
#define CANMESSAGEBOUNDS_H

#include "utilities/M_machine.h"

int32_t minCANMessageTime(const char c, const uint32_t priority, const uint32_t Num_Bytes) ;

int32_t maxCANMessageTime(const char c, const uint32_t minTrTime, const uint32_t Num_Bytes) ;


#endif

#ifdef _cplusplus
}
#endif
