#pragma once

#include "GenericUniqueArray.h"

class Compiler ;

bool
NecessaryConditions_OK (Compiler * inCompiler,
                        const GenericUniqueArray <cElement> & Element,
                        const GenericUniqueArray <cResource> & Resource);
