#ifdef _cplusplus
extern "C" {
#endif

#ifndef CANMESSAGEBOUNDS_H
#define CANMESSAGEBOUNDS_H

#include "streams/C_string_input_stream.h"


sint32 minCANMessageTime(const char c, const uint32 priority, const uint32 Num_Bytes) ;

sint32 maxCANMessageTime(const char c, const uint32 minTrTime, const uint32 Num_Bytes) ;


#endif

#ifdef _cplusplus
}
#endif
