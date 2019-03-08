#ifndef TE_DEBUG_GUARD_H
#define TE_DEBUG_GUARD_H

// #include "global.h"

struct DebugInterrupts
{
    u8 funcId;
	s8 returnVal;
	u8 args[12]; //args[2] is word aligned
    bool8 skipBattles : 1;
    // 15 bits remaining
}; //size = 0x10
// Defined in main.c for memory location purposes
extern struct DebugInterrupts gDebugInterrupts;

#endif //TE_DEBUG_GUARD_H