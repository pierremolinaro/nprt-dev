#ifndef VERIFYCONDITIONS_H
#define VERIFYCONDITIONS_H

#ifdef _cplusplus
extern "C" {
#endif

bool 
NecessaryConditions_OK (C_Lexique & inLexique,
                        const TC_UniqueArray <cElement> & Element,
                        const TC_UniqueArray <cResource> & Resource);

#endif

#ifdef _cplusplus
}
#endif
