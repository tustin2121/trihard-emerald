#ifndef TE_DEBUG_GUARD_H
#define TE_DEBUG_GUARD_H

// #include "global.h"

struct DebugInterrupts
{
    u8 funcId;
	u8 args[7];
    bool8 skipBattles : 1;
    
};
// Defined in main.c for memory location purposes
extern struct DebugInterrupts gDebugInterrupts;

#endif //TE_DEBUG_GUARD_H