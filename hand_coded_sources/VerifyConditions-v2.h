#pragma once

#include "generic-arraies/TC_UniqueArray.h"
class Compiler ;

bool
NecessaryConditions_OK (Compiler * inCompiler,
                        const TC_UniqueArray <cElement> & Element,
                        const TC_UniqueArray <cResource> & Resource);
