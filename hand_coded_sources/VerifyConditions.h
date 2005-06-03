#ifndef VERIFYCONDITIONS_H
#define VERIFYCONDITIONS_H

#ifdef _cplusplus
extern "C" {
#endif

bool 
NecessaryConditions_OK (C_lexique & inLexique,
                        const TCUniqueArray <cElement> & Element,
                        const TCUniqueArray <cResource> & Resource);

#endif

#ifdef _cplusplus
}
#endif
