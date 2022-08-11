#include "global.h"
#include "main.h"
#include "save.h"
#include "text.h"
#include "overworld.h"
#include "event_data.h"
#include "field_weather.h"
#include "script.h"
#include "constants/maps.h"
#include "constants/game_stat.h"
#include "constants/flags.h"
#include "constants/weather.h"
#include "remembered_dreams.h"

#define SENTINAL 0xA0
#define VERSION 1

u16 CalculateChecksum(void *data, u16 size);
bool16 ShouldLegendaryMusicPlayAtLocation(struct WarpData *warp);

struct RememberedDreamsV1
{
	/*0x0000*/ u32 gameStats[NUM_GAME_STATS];
	/*0x0100*/ u8 flags[8];
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
	return gRememberedDreams.data.v1.gameStats[index];
}

void RememberStat(u8 index, u32 value)
{
	if (index < NUM_USED_GAME_STATS)
        gRememberedDreams.data.v1.gameStats[index] = value;
}

u8 *GetRememberedFlagPointer(u16 id)
{
	return &gRememberedDreams.data.v1.flags[(id - REMEMBERED_FLAGS_START) / 8];
}

void RememberWhiteout()
{
	IncrementGameStat(GAME_STAT_NUM_WHITEOUTS);
}

//////////////////////////////////////////////////////////////////////////////////

void InitRememberedDreams()
{
	u8 i;
	memset(&gRememberedDreams, 0, sizeof(gRememberedDreams));
	gRememberedDreams.sentinal = SENTINAL;
	gRememberedDreams.version = VERSION;
	for (i = 0; i < NUM_GAME_STATS; i++)
	{
		RememberStat(i, GetGameStat(i));
	}
}

void LoadAndProcessRememberedDreams()
{
#if EMULATOR_ONLY
	u16 checksum;
	u8 i;
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
	if (GetRememberedStat(GAME_STAT_DIED_TO_LEGENDARIES) > GetGameStat(GAME_STAT_DIED_TO_LEGENDARIES))
	{
		FlagSet(FLAG_LOADING_AFTER_LEGENDARY_DEATH);
	}
	//TODO: set flag is a dream is due, and do remembered dream
	
	// Copy over the more up-to-date stats into the game
	for (i = 0; i < NUM_GAME_STATS; i++)
	{
		SetGameStat(i, GetRememberedStat(i));
	}
	// Special case: Dream 700 is the only dream that affects the real world, by enabling
	// Alex to call the player. We need to make sure this is still the case upon load, since
	// the dream happens after the save.
	if (!FlagGet(FLAG_ENABLE_ALEX_MATCH_CALL) && FlagGet(FLAG_SAW_DREAM_0700)) {
		// If Alex isn't in our phonebook, but we saw the dream, enable the counter to the first call,
		// which will add alex to our phone book.
		FlagSet(FLAG_ENABLE_ALEX_FIRST_CALL);
	}
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

//////////////////////////////////////////////////////////////////////////////////

extern const u8 DreamScript_CantSleep[];
extern const u8 DreamScript_0100[];
extern const u8 DreamScript_0150[];
extern const u8 DreamScript_0200[];
extern const u8 DreamScript_0300[];
extern const u8 DreamScript_0400[];
extern const u8 DreamScript_0500[];
extern const u8 DreamScript_0600[];
extern const u8 DreamScript_0700[];
extern const u8 DreamScript_0800[];
extern const u8 DreamScript_0801[];
extern const u8 DreamScript_0802[];
extern const u8 DreamScript_0900[];
extern const u8 DreamScript_1000[];
extern const u8 DreamScript_1001[];
extern const u8 DreamScript_1200[];

struct DreamDataStruct {
	const u8 *script;
	u16 requiredFlag;
	u16 doneFlag;
	u16 reqLoc;
};

static const struct DreamDataStruct sDreamScripts[] = {
	// Highest priority
	{ DreamScript_1000, FLAG_LEGENDARIES_IN_SOOTOPOLIS,   FLAG_SAW_DREAM_1000,     MAP_MOSSDEEP_CITY_POKEMON_CENTER_1F},
	{ DreamScript_1001, FLAG_LEGENDARIES_IN_SOOTOPOLIS,   FLAG_SAW_DREAM_1000,     0xFFFF}, // Must be below Mossdeep one
	{ DreamScript_0900, FLAG_PLAYER_HAS_SURFED,           FLAG_SAW_DREAM_0900,     0xFFFF},
	{ DreamScript_0800, FLAG_RECEIVED_TM54,               FLAG_SAW_DREAM_0800,     0xFFFF}, // Post Rusturf Tunnel
	// Sequential dreams
	{ DreamScript_0100, FLAG_DAD_IS_AT_WORK,              FLAG_SAW_DREAM_0100,     0xFFFF},
	{ DreamScript_0150, FLAG_VISITED_RUSTBORO_CITY,       FLAG_SAW_DREAM_0150,     0xFFFF},
	{ DreamScript_0200, FLAG_AQUA_FETCH_QUEST_COMPLETED,  FLAG_SAW_DREAM_0200,     0xFFFF},
	{ DreamScript_0300, FLAG_DELIVERED_DEVON_GOODS,       FLAG_SAW_DREAM_0300,     0xFFFF},
	{ DreamScript_0400, FLAG_DEFEATED_RIVAL_R110,         FLAG_SAW_DREAM_0400,     0xFFFF},
//	{ DreamScript_????, FLAG_MET_ARCHIE_METEOR_FALLS,     FLAG_SAW_DREAM_????,     0xFFFF},
	{ DreamScript_0500, FLAG_DEFEATED_LAVARIDGE_GYM,      FLAG_SAW_DREAM_0500,     0xFFFF},
//	{ DreamScript_????, FLAG_HIDE_ROUTE_119_TEAM_AQUA,    FLAG_SAW_DREAM_????,     0xFFFF}, // post weather institute
	{ DreamScript_0700, FLAG_VISITED_ROUTE120,            FLAG_SAW_DREAM_0700,     0xFFFF},
	{ DreamScript_1200, FLAG_VISITED_MT_PYRE,             FLAG_SAW_DREAM_1200,     0xFFFF}, // post mt Pyre
//	{ DreamScript_????, FLAG_VISITED_AQUA_BASE,           FLAG_SAW_DREAM_????,     0xFFFF},
	{ DreamScript_0600, FLAG_DEFEATED_MAGMA_SPACE_CENTER, FLAG_SAW_DREAM_0600,     0xFFFF},
//	{ DreamScript_????, FLAG_DEFEATED_WALLY_VICTORY_ROAD, FLAG_SAW_DREAM_????,     0xFFFF},
	// Lowest priority
	{ DreamScript_0801, FLAG_SAW_DREAM_0800,              FLAG_SKIPPED_NIGHT_0801, 0xFFFF},
	{ DreamScript_0802, FLAG_SKIPPED_NIGHT_0801,          FLAG_SAW_DREAM_0802,     0xFFFF},
	{ NULL,             0xFFFF,                           0xFFFF,                  0xFFFF},
};


void CheckIsWeatherAlternating()
{
	if (GetSav1Weather() == WEATHER_ALTERNATING) {
		FlagSet(FLAG_RESULT);
	} else {
		FlagClear(FLAG_RESULT);
	}
	VarSet(VAR_RESULT, GetSav1Weather() == WEATHER_ALTERNATING);
	
}

bool8 DoDreamCutscenes(struct ScriptContext *ctx)
{
	u32 i;
	if (ShouldLegendaryMusicPlayAtLocation(&gSaveBlock1Ptr->location)) {
		// If we can't change the music at this location (ie, in the center 
		// during the legendary fight). Don't do the dreams
		ScriptCall(ctx, DreamScript_CantSleep);
		return TRUE;
	}
	
	#define REQ_FLAG sDreamScripts[i].requiredFlag
	#define DONE_FLAG sDreamScripts[i].doneFlag
	#define REQ_LOC sDreamScripts[i].reqLoc
	
	for (i = 0; TRUE; i++) {
		// If we reached the sentinel at the bottom, no dreams apply
		if (sDreamScripts[i].script == NULL) return FALSE;
		// If requiredFlag if set and doneFlag is not, we can use this entry
		// Also if doneFlag is not set, skip anyway
		if (REQ_FLAG == 0xFFFF || FlagGet(REQ_FLAG) == FALSE) continue;
		if (DONE_FLAG == 0xFFFF || FlagGet(DONE_FLAG) == TRUE) continue;
		if (REQ_LOC != 0xFFFF) {
			if (gSaveBlock1Ptr->location.mapGroup != (REQ_LOC >> 8)
				|| gSaveBlock1Ptr->location.mapNum != (REQ_LOC & 0xFF)) continue;
		}
		break;
	}
	ScriptCall(ctx, sDreamScripts[i].script);
	FlagSet(DONE_FLAG);
	SaveRememberedDreams();
	return TRUE;
}




