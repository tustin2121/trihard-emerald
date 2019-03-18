#include "global.h"
#include "remembered_dreams.h"


enum {
	CONTEXT_OVERWORLD, // This memory took place in the overworld
	CONTEXT_WILD_BATTLE, // This memory took place in a wild battle
	CONTEXT_TRAINER_BATTLE, // This memory took place in a trainer battle
};

enum {
	// No memory recorded, dreamless night
	MEMORY_NONE,
	// Memory of making it into the hall of fame
	MEMORY_HALL_OF_FAME,
	// Memory of losing a battle and whiting out
	MEMORY_WHITEOUT,
	// Memory of gaining a party pokemon
	MEMORY_PARTY_MEMBER_GAINED,
	// Memory of losing a party pokemon
	MEMORY_PARTY_MEMBER_LOST, 
	// Memory of a party pokemon clutching in the red zone
	MEMORY_PARTY_MEMBER_CLUTCH,
	// Memory of fighting a tough pokemon
	MEMORY_POKEMON_FOUGHT, 
	// Memory of a desired pokemon fleeing
	MEMORY_POKEMON_FLED,
	// Memory of a desired pokemon fainting
	MEMORY_POKEMON_FAINT,
};

struct Memory {
	u8 memoryType; // One of the MEMORY_ enum
	u8 context; // One of the CONTEXT_ enum
	struct { // The subject of this memory, if there is one
		u16 species;
		u32 personality;
		u8 nickname[POKEMON_NAME_LENGTH];
	} subjectMon;
	union {
		struct {
			u16 wildSpecies;
			u8 numPokeballsUsed;
			
		} wild;
	} data;
};

#define NUM_MEMORIES 10

// TriHard Emerald: remembering the last thing the player did
struct RememberedDreams
{
	// Index into the Memory array for which memory was the last memory written to
	u8 lastMemory;
	// Array of memories which the protagonist remembers
	struct Memory memories[NUM_MEMORIES];
	
};

