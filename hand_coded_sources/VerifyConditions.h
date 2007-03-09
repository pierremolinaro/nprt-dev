#ifndef VERIFYCONDITIONS_H
#define VERIFYCONDITIONS_H

#include "generic_arraies/TC_UniqueArray.h"
class C_Lexique ;

bool 
NecessaryConditions_OK (C_Lexique & inLexique,
                        const TC_UniqueArray <cElement> & Element,
                        const TC_UniqueArray <cResource> & Resource);

#endif
