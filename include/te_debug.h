#ifndef TE_DEBUG_GUARD_H
#define TE_DEBUG_GUARD_H

// #include "global.h"

// Everything is volatile to prevent it being optimized away. These
// variables will never be referenced within the application. They're 
// meant to be set externally.
struct DebugInterrupts
{
    volatile u8 funcId;
	volatile s8 returnVal;
	volatile u8 args[12]; //args[2] is word aligned
    volatile bool8 skipBattles : 1;
    // 15 bits remaining
}; //size = 0x10
// Defined in main.c for memory location purposes
extern volatile struct DebugInterrupts gDebugInterrupts;
extern void DebugCheckInterrupts();
extern void DebugSetCallbackSuccess();
extern void DebugSetCallbackFailure();

#endif //TE_DEBUG_GUARD_H