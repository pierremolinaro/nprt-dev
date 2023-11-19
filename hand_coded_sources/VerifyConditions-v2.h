#pragma once

#include "collections/TC_UniqueArray.h"
class C_Compiler ;

bool 
NecessaryConditions_OK (C_Compiler * inCompiler,
                        const TC_UniqueArray <cElement> & Element,
                        const TC_UniqueArray <cResource> & Resource);
