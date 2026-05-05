#ifndef GUARD_FOSSIL_REVIVAL_H
#define GUARD_FOSSIL_REVIVAL_H

#include "global.h"

struct FossilRevival {
    u16 fossilItemId;
    u16 speciesId;
};

u16 GetFossilItemId(void);
u16 GetFossilItemIdFromIndex(void);
u16 GetSpeciesFromFossil(void);
u16 GetSpeciesFromFossilIndex(void);
bool8 GetHasMultipleFossils(void);

#endif // GUARD_FOSSIL_REVIVAL_H
