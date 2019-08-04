#include "global.h"
#include "main.h"
#include "save.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/game_stat.h"
#include "constants/flags.h"
#include "remembered_dreams.h"

#define SENTINAL 0xA0
#define VERSION 1

u16 CalculateChecksum(void *data, u16 size);

struct RememberedDreamsV1
{
	/*0x0000*/ u32 encryptionKey;
	/*0x0004*/ u32 gameStats[NUM_GAME_STATS];
	/*0x0104*/
};

struct RememberedDreams
{
	/*0x0000*/ u8 sentinal;
	/*0x0001*/ u8 version;
	/*0x0002*/ u16 counter;
	/*0x0004*/ union
	{
		u8 raw[0xFE0];
		struct RememberedDreamsV1 v1;
	} data;
	/*0x0FE4*/ u16 checksum;
	/*0x0FE6*/ u8 _padding[0x1C]; //Enough unused space to pad to 0x1000, to prevent buffer overflows when reading from Flash
	/*0x1002*/
};

EWRAM_DATA struct RememberedDreams gRememberedDreams = {0};

//////////////////////////////////////////////////////////////////////////////////

u32 GetRememberedStat(u8 index)
{
	if (index >= NUM_USED_GAME_STATS) return 0;
	return gRememberedDreams.data.v1.gameStats[index] ^ gRememberedDreams.data.v1.encryptionKey;
}

void RememberStat(u8 index, u32 value)
{
	if (index < NUM_USED_GAME_STATS)
        gRememberedDreams.data.v1.gameStats[index] = value ^ gRememberedDreams.data.v1.encryptionKey;
}

void RememberWhiteout()
{
	IncrementGameStat(GAME_STAT_NUM_WHITEOUTS);
}

//////////////////////////////////////////////////////////////////////////////////

void InitRememberedDreams()
{
	memset(&gRememberedDreams, 0, sizeof(gRememberedDreams));
	gRememberedDreams.sentinal = SENTINAL;
	gRememberedDreams.version = VERSION;
	gRememberedDreams.data.v1.encryptionKey = gSaveBlock2Ptr->encryptionKey;
	memcpy(gRememberedDreams.data.v1.gameStats, gSaveBlock1Ptr->gameStats, sizeof(gRememberedDreams.data.v1.gameStats));
}

void LoadAndProcessRememberedDreams()
{
#if EMULATOR_ONLY
	u16 checksum;
	// Attempt to read in the dream section
	if (TryReadSpecialSaveSection(SECTOR_ID_RECORDED_BATTLE, (void*)&gRememberedDreams) == 0xFF) goto badDreams;
	// Ensure this is an expected dream section
	if (gRememberedDreams.sentinal != SENTINAL) goto badDreams; 
	// Ensure this is an version we can handle, and convert if we can't
	if (gRememberedDreams.version != VERSION) goto badDreams;
	// Ensure the data is correct
	checksum = CalculateChecksum(gRememberedDreams.data.raw, sizeof(gRememberedDreams.data));
	if (checksum != gRememberedDreams.checksum) goto badDreams;
	
	// If we get here, we trust that the remembered dreams are correct
	// Check if we're loading up after a whiteout
	if (GetRememberedStat(GAME_STAT_NUM_WHITEOUTS) > GetGameStat(GAME_STAT_NUM_WHITEOUTS))
	{
		FlagSet(FLAG_LOADING_AFTER_WHITEOUT);
		FlagSet(FLAG_SHOULD_PLAY_LOSER_MUSIC);
	}
	//TODO: set flag is a dream is due, and do remembered dream
	
	// Copy over the more up-to-date stats into the game
	memcpy(gSaveBlock1Ptr->gameStats, gRememberedDreams.data.v1.gameStats, sizeof(gSaveBlock1Ptr->gameStats));
	return;
badDreams:
	FlagSet(FLAG_ERROR_READING_DREAMS);
	InitRememberedDreams();
	return;
#endif
}

void SaveRememberedDreams()
{
#if EMULATOR_ONLY
	// Calculate the checksum for saving
	gRememberedDreams.checksum = CalculateChecksum(gRememberedDreams.data.raw, sizeof(gRememberedDreams.data));
	gRememberedDreams.counter++;
	// Attempt to write the dreams
	if (TryWriteSpecialSaveSection(SECTOR_ID_RECORDED_BATTLE, (void*)&gRememberedDreams) == 0xFF) goto badDreams;
	FlagClear(FLAG_ERROR_WRITING_DREAMS);
	return;
badDreams:
	FlagSet(FLAG_ERROR_WRITING_DREAMS);
	return;
#endif
}

