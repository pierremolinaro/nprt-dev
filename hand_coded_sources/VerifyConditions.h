#ifndef VERIFYCONDITIONS_H
#define VERIFYCONDITIONS_H

#include "collections/TC_UniqueArray.h"
class C_CompilerEx ;

bool 
NecessaryConditions_OK (C_CompilerEx & inLexique,
                        const TC_UniqueArray <cElement> & Element,
                        const TC_UniqueArray <cResource> & Resource);

#endif
