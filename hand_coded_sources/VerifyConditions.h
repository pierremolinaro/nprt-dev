#ifndef VERIFYCONDITIONS_H
#define VERIFYCONDITIONS_H

#ifdef _cplusplus
extern "C" {
#endif

bool 
NecessaryConditions_OK (C_lexique & inLexique,
                        const TC_unique_grow_array <cElement> & Element,
                        const TC_unique_grow_array <cResource> & Resource);

#endif

#ifdef _cplusplus
}
#endif