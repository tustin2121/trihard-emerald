#include "global.h"
#include "battle_setup.h"
#include "data.h"
#include "event_data.h"
#include "string_util.h"
#include "battle.h"
#include "gym_leader_rematch.h"
#include "match_call.h"
#include "pokenav.h"
#include "constants/region_map_sections.h"
#include "constants/maps.h"
#include "constants/layouts.h"
#include "constants/trainers.h"

// NPC below means non-trainer character (no rematch or check page)
// Steven also uses this type but has a check page by using a MatchCallCheckPageOverride
enum
{
    MC_TYPE_NPC,
    MC_TYPE_TRAINER,
    MC_TYPE_WALLY,
    MC_TYPE_BIRCH,
    MC_TYPE_RIVAL,
    MC_TYPE_LEADER,
    MC_TYPE_ALEX,
};

// Static type declarations

typedef struct MatchCallTextDataStruct {
    const u8 *text;
    u16 flag;
    u16 flag2;
} match_call_text_data_t;

struct MatchCallStructCommon {
    u8 type;
    u8 mapSec;
    u16 flag;
};

struct MatchCallStructNPC {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
    u16 dailyFlag;
};

// Shared by MC_TYPE_TRAINER and MC_TYPE_LEADER
struct MatchCallStructTrainer {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

struct MatchCallLocationOverride {
    u16 flag;
    u8 mapSec;
};

struct MatchCallWally {
    u8 type;
    u8 mapSec;
    u16 flag;
    u16 rematchTableIdx;
    const u8 *desc;
    const match_call_text_data_t *textData;
    const struct MatchCallLocationOverride *locationData;
};

struct MatchCallBirch {
    u8 type;
    u8 mapSec;
    u16 flag;
    const u8 *desc;
    const u8 *name;
};

struct MatchCallRival {
    u8 type;
    u8 playerGender;
    u16 flag;
    const u8 *desc;
    const u8 *name;
    const match_call_text_data_t *textData;
};

typedef union {
    const struct MatchCallStructCommon *common;
    const struct MatchCallStructNPC *npc;
    const struct MatchCallStructTrainer *trainer;
    const struct MatchCallWally *wally;
    const struct MatchCallBirch *birch;
    const struct MatchCallRival *rival;
    const struct MatchCallStructTrainer *leader;
} match_call_t;

struct MatchCallCheckPageOverride {
    u16 idx;
    u16 facilityClass;
    u32 flag;
    const u8 *flavorTexts[CHECK_PAGE_ENTRY_COUNT];
};

// Static RAM declarations

// Static ROM declarations

static bool32 MatchCallGetFlag_NPC(match_call_t);
static bool32 MatchCallGetFlag_Trainer(match_call_t);
static bool32 MatchCallGetFlag_Wally(match_call_t);
static bool32 MatchCallGetFlag_Rival(match_call_t);
static bool32 MatchCallGetFlag_Birch(match_call_t);

static u8 MatchCall_GetMapSec_NPC(match_call_t);
static u8 MatchCall_GetMapSec_Trainer(match_call_t);
static u8 MatchCall_GetMapSec_Wally(match_call_t);
static u8 MatchCall_GetMapSec_Rival(match_call_t);
static u8 MatchCall_GetMapSec_Birch(match_call_t);

static bool32 MatchCall_IsRematchable_NPC(match_call_t);
static bool32 MatchCall_IsRematchable_Trainer(match_call_t);
static bool32 MatchCall_IsRematchable_Wally(match_call_t);
static bool32 MatchCall_IsRematchable_Rival(match_call_t);
static bool32 MatchCall_IsRematchable_Birch(match_call_t);

static bool32 MatchCall_HasCheckPage_NPC(match_call_t);
static bool32 MatchCall_HasCheckPage_Trainer(match_call_t);
static bool32 MatchCall_HasCheckPage_Wally(match_call_t);
static bool32 MatchCall_HasCheckPage_Rival(match_call_t);
static bool32 MatchCall_HasCheckPage_Birch(match_call_t);

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Wally(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t);
static u32 MatchCall_GetRematchTableIdx_Birch(match_call_t);

static void MatchCall_GetMessage_NPC(match_call_t, u8 *);
static void MatchCall_GetMessage_Trainer(match_call_t, u8 *);
static void MatchCall_GetMessage_Wally(match_call_t, u8 *);
static void MatchCall_GetMessage_Rival(match_call_t, u8 *);
static void MatchCall_GetMessage_Birch(match_call_t, u8 *);
static void MatchCall_GetMessage_Alex(match_call_t, u8*);

static void MatchCall_GetNameAndDesc_NPC(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Trainer(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Wally(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Rival(match_call_t, const u8 **, const u8 **);
static void MatchCall_GetNameAndDesc_Birch(match_call_t, const u8 **, const u8 **);

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *, u8 *);
static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *, u16, u8 *);
static void MatchCall_GetNameAndDescByRematchIdx(u32, const u8 **, const u8 **);

extern const u8 gText_MrStone_Pokenav_2B60C0[];
extern const u8 gText_MrStone_Pokenav_2B61E6[];
extern const u8 gText_MrStone_Pokenav_2B6302[];
extern const u8 gText_MrStone_Pokenav_2B63A0[];
extern const u8 gText_MrStone_Pokenav_2B64A2[];
extern const u8 gText_MrStone_Pokenav_2B6526[];
extern const u8 gText_MrStone_Pokenav_2B65BB[];
extern const u8 gText_MrStone_Pokenav_2B6664[];
extern const u8 gText_MrStone_Pokenav_2B66B1[];
extern const u8 gText_MrStone_Pokenav_2B6703[];
extern const u8 gText_MrStone_Pokenav_2B67ED[];

extern const u8 gMatchCallDesc_MrStone[];
extern const u8 gMatchCallName_MrStone[];

extern const u8 gMatchCallDesc_Alex[];
extern const u8 gMatchCallName_Alex[];

extern const u8 gMatchCallDesc_ProfBirch[];
extern const u8 gMatchCallName_ProfBirch[];

extern const u8 gText_Dad_Pokenav_NoAnswer[];
extern const u8 gText_Dad_Pokenav_Starting[];
extern const u8 gText_Dad_Pokenav_AreYouHurt[];
extern const u8 gText_Dad_Pokenav_TeamWarn[];
extern const u8 gText_Dad_Pokenav_LegendaryWarn[];
extern const u8 gText_Dad_Pokenav_CallYouBack[];
extern const u8 gText_Dad_Pokenav_Singlehanded[];
extern const u8 gText_Dad_Pokenav_EverGrande[];
extern const u8 gMatchCallDesc_Dad[];
extern const u8 gMatchCallName_Dad[];

extern const u8 gText_Steven_Pokenav_2B5B95[];
extern const u8 gText_Steven_Pokenav_2B5C53[];
extern const u8 gText_Steven_Pokenav_2B5CC9[];
extern const u8 gText_Steven_Pokenav_2B5DB4[];
extern const u8 gText_Steven_Pokenav_2B5E26[];
extern const u8 gText_Steven_Pokenav_2B5EA2[];
extern const u8 gText_Steven_Pokenav_2B5ED9[];
extern const u8 gMatchCallDesc_Steven[];
extern const u8 gMatchCallName_Steven[];

extern const u8 gText_May_Pokenav_2B3AB3[];
extern const u8 gText_May_Pokenav_2B3B3F[];
extern const u8 gText_May_Pokenav_2B3C13[];
extern const u8 gText_May_Pokenav_2B3CF3[];
extern const u8 gText_May_Pokenav_2B3D4B[];
extern const u8 gText_May_Pokenav_2B3DD1[];
extern const u8 gText_May_Pokenav_2B3E69[];
extern const u8 gText_May_Pokenav_2B3ECD[];
extern const u8 gText_May_Pokenav_2B3F2B[];
extern const u8 gText_May_Pokenav_2B3FFB[];
extern const u8 gText_May_Pokenav_2B402B[];
extern const u8 gText_May_Pokenav_2B414B[];
extern const u8 gText_May_Pokenav_2B4228[];
extern const u8 gText_May_Pokenav_2B42E0[];
extern const u8 gText_May_Pokenav_2B4350[];
extern const u8 gMatchCallDesc_Rival[];
extern const u8 gExpandedPlaceholder_May[];
extern const u8 gText_Brendan_Pokenav_2B43EF[];
extern const u8 gText_Brendan_Pokenav_2B4486[];
extern const u8 gText_Brendan_Pokenav_2B4560[];
extern const u8 gText_Brendan_Pokenav_2B463F[];
extern const u8 gText_Brendan_Pokenav_2B46B7[];
extern const u8 gText_Brendan_Pokenav_2B4761[];
extern const u8 gText_Brendan_Pokenav_2B47F4[];
extern const u8 gText_Brendan_Pokenav_2B4882[];
extern const u8 gText_Brendan_Pokenav_2B4909[];
extern const u8 gText_Brendan_Pokenav_2B49C4[];
extern const u8 gText_Brendan_Pokenav_2B4A44[];
extern const u8 gText_Brendan_Pokenav_2B4B28[];
extern const u8 gText_Brendan_Pokenav_2B4C15[];
extern const u8 gText_Brendan_Pokenav_2B4CD8[];
extern const u8 gText_Brendan_Pokenav_2B4D46[];
extern const u8 gExpandedPlaceholder_Brendan[];
extern const u8 gText_Wally_Pokenav_2B4DE2[];
extern const u8 gText_Wally_Pokenav_2B4E57[];
extern const u8 gText_Wally_Pokenav_2B4EA5[];
extern const u8 gText_Wally_Pokenav_2B4F41[];
extern const u8 gText_Wally_Pokenav_2B4FF3[];
extern const u8 gText_Wally_Pokenav_2B50B1[];
extern const u8 gText_Wally_Pokenav_2B5100[];
extern const u8 gMatchCallDesc_Wally[];
extern const u8 gText_Scott_Pokenav_2B5184[];
extern const u8 gText_Scott_Pokenav_2B5275[];
extern const u8 gText_Scott_Pokenav_2B5323[];
extern const u8 gText_Scott_Pokenav_2B53DB[];
extern const u8 gText_Scott_Pokenav_2B54A5[];
extern const u8 gText_Scott_Pokenav_2B5541[];
extern const u8 gText_Scott_Pokenav_2B56CA[];
extern const u8 gMatchCallDesc_Scott[];
extern const u8 gMatchCallName_Scott[];
extern const u8 gText_Roxanne_Pokenav_2B2456[];
extern const u8 gText_Roxanne_Pokenav_2B250E[];
extern const u8 gText_Roxanne_Pokenav_2B25C1[];
extern const u8 gText_Roxanne_Pokenav_2B2607[];
extern const u8 gMatchCallDesc_Roxanne[];
extern const u8 gText_Brawly_Pokenav_2B2659[];
extern const u8 gText_Brawly_Pokenav_2B275D[];
extern const u8 gText_Brawly_Pokenav_2B286F[];
extern const u8 gText_Brawly_Pokenav_2B28D1[];
extern const u8 gMatchCallDesc_Brawly[];
extern const u8 gText_Wattson_Pokenav_2B2912[];
extern const u8 gText_Wattson_Pokenav_2B29CA[];
extern const u8 gText_Wattson_Pokenav_2B2AB6[];
extern const u8 gText_Wattson_Pokenav_2B2B01[];
extern const u8 gMatchCallDesc_Wattson[];
extern const u8 gText_Flannery_Pokenav_2B2B4D[];
extern const u8 gText_Flannery_Pokenav_2B2C0E[];
extern const u8 gText_Flannery_Pokenav_2B2CF1[];
extern const u8 gText_Flannery_Pokenav_2B2D54[];
extern const u8 gMatchCallDesc_Flannery[];
extern const u8 gText_Norman_Pokenav_2B5719[];
extern const u8 gText_Norman_Pokenav_2B5795[];
extern const u8 gText_Norman_Pokenav_2B584D[];
extern const u8 gText_Norman_Pokenav_2B58E3[];
extern const u8 gMatchCallDesc_Norman[];
extern const u8 gText_Winona_Pokenav_2B2DA4[];
extern const u8 gText_Winona_Pokenav_2B2E2B[];
extern const u8 gText_Winona_Pokenav_2B2EC2[];
extern const u8 gText_Winona_Pokenav_2B2F16[];
extern const u8 gMatchCallDesc_Winona[];
extern const u8 gText_TateLiza_Pokenav_2B2F97[];
extern const u8 gText_TateLiza_Pokenav_2B306E[];
extern const u8 gText_TateLiza_Pokenav_2B3158[];
extern const u8 gText_TateLiza_Pokenav_2B31CD[];
extern const u8 gMatchCallDesc_TateLiza[];
extern const u8 gText_Juan_Pokenav_2B3249[];
extern const u8 gText_Juan_Pokenav_2B32EC[];
extern const u8 gText_Juan_Pokenav_2B33AA[];
extern const u8 gText_Juan_Pokenav_2B341E[];
extern const u8 gMatchCallDesc_Juan[];
extern const u8 gText_Sidney_Pokenav_2B34CC[];
extern const u8 gMatchCallDesc_EliteFour[];
extern const u8 gText_Phoebe_Pokenav_2B3561[];
extern const u8 gText_Glacia_Pokenav_2B35E4[];
extern const u8 gText_Drake_Pokenav_2B368B[];
extern const u8 gText_Wallace_Pokenav_2B3790[];
extern const u8 gMatchCallDesc_Champion[];
extern const u8 gText_MatchCallSteven_Strategy[];
extern const u8 gText_MatchCallSteven_Pokemon[];
extern const u8 gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle[];
extern const u8 gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle[];
extern const u8 gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle[];
extern const u8 gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle[];
extern const u8 gText_MatchCallBrendan_Strategy[];
extern const u8 gText_MatchCallBrendan_Pokemon[];
extern const u8 gText_MatchCallBrendan_Intro1[];
extern const u8 gText_MatchCallBrendan_Intro2[];
extern const u8 gText_MatchCallMay_Strategy[];
extern const u8 gText_MatchCallMay_Pokemon[];
extern const u8 gText_MatchCallMay_Intro1[];
extern const u8 gText_MatchCallMay_Intro2[];
// .rodata

static const match_call_text_data_t sMrStoneTextScripts[] = {
    // { gText_MrStone_Pokenav_2B60C0, 0xFFFF,              FLAG_ENABLE_MR_STONE_POKENAV },
    // { gText_MrStone_Pokenav_2B61E6, FLAG_ENABLE_MR_STONE_POKENAV,          0xFFFF },
    // { gText_MrStone_Pokenav_2B6302, FLAG_UNUSED_0x0BD,          0xFFFF },
    // { gText_MrStone_Pokenav_2B63A0, FLAG_RECEIVED_EXP_SHARE,          0xFFFF },
    // { gText_MrStone_Pokenav_2B64A2, FLAG_RECEIVED_TM54,          0xFFFF },
    // { gText_MrStone_Pokenav_2B6526, FLAG_DEFEATED_PETALBURG_GYM,          0xFFFF },
    // { gText_MrStone_Pokenav_2B65BB, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    // { gText_MrStone_Pokenav_2B6664, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,          0xFFFF },
    // { gText_MrStone_Pokenav_2B66B1, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    // { gText_MrStone_Pokenav_2B6703, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    // { gText_MrStone_Pokenav_2B67ED, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStructNPC sMrStoneMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_RUSTBORO_CITY,
    .flag = 0xFFFF, 
    .desc = gMatchCallDesc_MrStone,
    .name = gMatchCallName_MrStone,
    .textData = sMrStoneTextScripts,
    .dailyFlag = 0xFFFF,
};

//-----------------------------------------------------------------------------

extern const u8 gText_Alex_Pokenav_CatchUp[];
extern const u8 gText_Alex_Pokenav_RainsBegan[];
extern const u8 gText_Alex_Pokenav_MidResearch[];
extern const u8 gText_Alex_Pokenav_PostResearch[];
extern const u8 gText_Alex_Pokenav_Unavailable[];
extern const u8 gText_Alex_Pokenav_GymChallenge[];
extern const u8 gText_Alex_Pokenav_TeamAqua[];
extern const u8 gText_Alex_Pokenav_Grandma[];
extern const u8 gText_Alex_Pokenav_Magma[];
extern const u8 gText_Alex_Pokenav_Stern[];
extern const u8 gText_Alex_Pokenav_SternAfter[];
extern const u8 gText_Alex_Pokenav_E4Day1[];
extern const u8 gText_Alex_Pokenav_E4Day2[];
extern const u8 gText_Alex_Pokenav_E4Day3[];
extern const u8 gText_Alex_Pokenav_E4Day3_Hero[];
extern const u8 gText_Alex_Pokenav_E4Day4[];
extern const u8 gText_Alex_Pokenav_E4Day5[];
extern const u8 gText_Alex_Pokenav_Logan_Base[];
extern const u8 gText_Alex_Pokenav_Logan_Deaths[];
extern const u8 gText_Alex_Pokenav_SpaceCenter[];
extern const u8 gText_Alex_Pokenav_PostReport_BaseHelped[];
extern const u8 gText_Alex_Pokenav_PostReport_BaseKnown[];
extern const u8 gText_Alex_Pokenav_PostReport_BaseUnknown[];
extern const u8 gText_Alex_Pokenav_PostReport_OutcomeNormal[];
extern const u8 gText_Alex_Pokenav_PostReport_OutcomeHero[];
extern const u8 gExpandedPlaceholder_Empty[];

static const match_call_text_data_t sAlexTextScripts_CatchingUp[] = {
    { gText_Alex_Pokenav_CatchUp,      0xFFFF,                              FLAG_ALEX_KNOWS_TO_R120 },
    { gText_Alex_Pokenav_GymChallenge, FLAG_ALEX_KNOWS_TO_R120,             FLAG_ALEX_KNOWS_GYM },
    { gText_Alex_Pokenav_TeamAqua,     FLAG_ALEX_KNOWS_GYM,                 FLAG_ALEX_DISCUSSED_AQUA },
    { NULL,                            0xFFFF,                              0xFFFF }
};

static const match_call_text_data_t sAlexTextScripts_BeforeLegendaries[] = {
    { gText_Alex_Pokenav_SpaceCenter,  FLAG_DEFEATED_MAGMA_SPACE_CENTER,    FLAG_ALEX_DISCUSSED_SPACE_CENTER },
    { gText_Alex_Pokenav_Logan_Base,   FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, FLAG_ALEX_DISCUSSED_LOGAN },
    { gText_Alex_Pokenav_SternAfter,   FLAG_TEAM_AQUA_STOLE_SUBMARINE,      FLAG_ALEX_DISCUSSED_STERN },
    { gText_Alex_Pokenav_Stern,        FLAG_ALEX_DISCUSSED_MAGMA,           FLAG_ALEX_DISCUSSED_STERN },
    { gText_Alex_Pokenav_Magma,        FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, FLAG_ALEX_DISCUSSED_MAGMA },
    { gText_Alex_Pokenav_Grandma,      FLAG_SAW_DREAM_1200,                 FLAG_ALEX_DISCUSSED_GRANDMA },
    { NULL,                            0xFFFF,                         0xFFFF }
};
static const match_call_text_data_t sAlexTextScripts_DuringLegendaries[] = {
    { gText_Alex_Pokenav_PostResearch, FLAG_ALEX_TOLD_SKY_PILLAR,      0xFFFF },
    { gText_Alex_Pokenav_MidResearch,  FLAG_ALEX_KNOWS_LEGENDARIES,    0xFFFF },
    { gText_Alex_Pokenav_RainsBegan,   FLAG_LEGENDARIES_IN_SOOTOPOLIS, FLAG_ALEX_CALL_LEGENDARIES },
    { NULL,                            0xFFFF,                         0xFFFF }
};
static const match_call_text_data_t sAlexTextScripts_AfterLegendaries[] = {
    { gText_Alex_Pokenav_PostReport_BaseHelped,  FLAG_ALEX_TOLD_SKY_PILLAR,   FLAG_ALEX_KNOWS_LEGENDARY_OUTCOME },
    { gText_Alex_Pokenav_PostReport_BaseKnown,   FLAG_ALEX_KNOWS_LEGENDARIES, FLAG_ALEX_KNOWS_LEGENDARY_OUTCOME },
    { gText_Alex_Pokenav_PostReport_BaseUnknown, 0xFFFF,                      FLAG_ALEX_KNOWS_LEGENDARY_OUTCOME },
//  { gText_Alex_Pokenav_PostReport_BaseUnknown, FLAG_ALEX_KNOWS_E4,          FLAG_ALEX_KNOWS_LEGENDARY_OUTCOME },
    { NULL,                                      0xFFFF,                      0xFFFF }
};

static const struct MatchCallStructNPC sAlexMatchCallHeader =
{
    .type = MC_TYPE_ALEX,
    .mapSec = MAPSEC_ALOLA,
    .flag = FLAG_ENABLE_ALEX_MATCH_CALL,
    .desc = gMatchCallDesc_Alex,
    .name = gMatchCallName_Alex,
    .textData = NULL, // Unused since we're doing a custom GetMessage
    .dailyFlag = FLAG_DAILY_ALEX_CALL, //Unused
};

// MatchCall_BufferCallMessageText -> Checks scripts table from bottom up
static const u8* MatchCall_GetMessageText_AllOnce(const match_call_text_data_t *textData)
{   // -> Checks scripts table from top down, like the dream table
	u32 i;
	#define REQ_FLAG textData[i].flag
	#define DONE_FLAG textData[i].flag2
    
    for (i = 0; TRUE; i++) {
        // If we reached the sentinel at the bottom, something went wrong. panic!
		if (textData[i].text == NULL) {
            // return gText_Dad_Pokenav_NoAnswer; //"The number you have dialed is unavailable"
            return NULL;
        }
        // Skip entries which don't meet the prerequisite
        if (REQ_FLAG != 0xFFFF && FlagGet(REQ_FLAG) == FALSE) continue;
        // Skip entires which have already been done
        if (DONE_FLAG != 0xFFFF && FlagGet(DONE_FLAG) == TRUE) continue;
        // Entires with neither of the above are always chosen
        break;
    }
    // If there's a doneFlag specified, set it as part of this call
    if (DONE_FLAG != 0xffff) {
        FlagSet(DONE_FLAG);
    }
    return textData[i].text;
}

static const u8* MatchCall_GetMessageText_NewestOnly(const match_call_text_data_t *textData)
{
    u32 i;
	#define REQ_FLAG textData[i].flag
	#define DONE_FLAG textData[i].flag2
    
    for (i = 0; TRUE; i++) {
        // If flag1 is set, or if there's no flag specified, we can use this entry
        if (REQ_FLAG != 0xffff && FlagGet(REQ_FLAG) == TRUE) break;
    }
    // If there's a flag2 specified, set it as part of this call
    if (DONE_FLAG != 0xffff) {
        if (FlagGet(DONE_FLAG)) return NULL; // Skip if we've already done this
        FlagSet(DONE_FLAG);
    }
    // Return the text of the entry
    return textData[i].text;
}

static void MatchCall_GetMessage_Alex(match_call_t matchCall, u8* dest)
{
    const u8* textPtr = NULL;
    // Handle E4 if the player is in there.
    if (textPtr == NULL && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(EVER_GRANDE_CITY_WAITING_ROOM1)) {
        switch (gSaveBlock1Ptr->location.mapNum) {
            case MAP_NUM(EVER_GRANDE_CITY_WAITING_ROOM1): textPtr = gText_Alex_Pokenav_E4Day1; break;
            case MAP_NUM(EVER_GRANDE_CITY_WAITING_ROOM2): textPtr = gText_Alex_Pokenav_E4Day2; break;
            case MAP_NUM(EVER_GRANDE_CITY_WAITING_ROOM3): textPtr = (FlagGet(FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY))? gText_Alex_Pokenav_E4Day3_Hero : gText_Alex_Pokenav_E4Day3; break;
            case MAP_NUM(EVER_GRANDE_CITY_WAITING_ROOM4): textPtr = gText_Alex_Pokenav_E4Day4; break;
            case MAP_NUM(EVER_GRANDE_CITY_WAITING_ROOM5): textPtr = gText_Alex_Pokenav_E4Day5; break;
        }
    }
    if (textPtr == NULL && FlagGet(FLAG_LEGENDARIES_IN_SOOTOPOLIS)) {
        textPtr = MatchCall_GetMessageText_AllOnce(sAlexTextScripts_DuringLegendaries);
        FlagSet(FLAG_ALEX_KNOWS_LEGENDARIES); // cheat: if we're getting from here, we have told / are telling Alex about the legendaries
    }
    if (FlagGet(FLAG_LEGENDARIES_CLEARED)) {
        if (FlagGet(FLAG_DAILY_ALEX_CALL)) goto afterSelected;
        if (textPtr == NULL) {
            textPtr = MatchCall_GetMessageText_AllOnce(sAlexTextScripts_AfterLegendaries);
        }
        if (textPtr != NULL) FlagSet(FLAG_DAILY_ALEX_CALL);
    }
    else {
        if (FlagGet(FLAG_DAILY_ALEX_CALL)) goto afterSelected;
        if (textPtr == NULL) {
            textPtr = MatchCall_GetMessageText_AllOnce(sAlexTextScripts_CatchingUp);
        }
        if (textPtr == NULL) {
            textPtr = MatchCall_GetMessageText_NewestOnly(sAlexTextScripts_BeforeLegendaries);
        }
        if (textPtr != NULL) FlagSet(FLAG_DAILY_ALEX_CALL);
    }
afterSelected:
    if (textPtr == NULL) {
        textPtr = gText_Alex_Pokenav_Unavailable;
    }
    
    // Special handling for string expansions
    if (textPtr == gText_Alex_Pokenav_Logan_Base) {
        if (VarGet(VAR_LOGAN_AQUA_FIGHT_LOST_MON_COUNT) > 0) {
            ConvertIntToNameStringN(gStringVar2, VarGet(VAR_LOGAN_AQUA_FIGHT_LOST_MON_COUNT), 0, 1);
            StringExpandPlaceholders(gStringVar1, gText_Alex_Pokenav_Logan_Deaths);
        } else {
            StringExpandPlaceholders(gStringVar1, gExpandedPlaceholder_Empty);
        }
    }
    if (textPtr == gText_Alex_Pokenav_PostReport_BaseHelped || textPtr == gText_Alex_Pokenav_PostReport_BaseKnown || gText_Alex_Pokenav_PostReport_BaseUnknown) {
        if (FlagGet(FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY)) {
            StringExpandPlaceholders(gStringVar1, gText_Alex_Pokenav_PostReport_OutcomeHero);
        } else {
            StringExpandPlaceholders(gStringVar1, gText_Alex_Pokenav_PostReport_OutcomeNormal);
        }
        FlagClear(FLAG_ALEX_CALL_LEGENDARIES); // Clear the due call, if it's ongoing
    }
    StringExpandPlaceholders(dest, textPtr);
}

//-----------------------------------------------------------------------------

static const struct MatchCallBirch sProfBirchMatchCallHeader =
{
    .type = 3,
    .mapSec = MAPSEC_LITTLEROOT_TOWN,
    .flag = FLAG_ENABLE_PROF_BIRCH_MATCH_CALL,
    .desc = gMatchCallDesc_ProfBirch,
    .name = gMatchCallName_ProfBirch
};

static const match_call_text_data_t sDadTextScripts[] = {
    { gText_Dad_Pokenav_Starting,       0xFFFF, 0xFFFF },
    { gText_Dad_Pokenav_AreYouHurt,     FLAG_DAD_IS_AT_WORK, 0xFFFF },
    { gText_Dad_Pokenav_CallYouBack,    FLAG_BADGE01_GET, 0xFFFF },
    { gText_Dad_Pokenav_TeamWarn,       FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, 0xFFFF },
    //TODO more text for various items
    { gText_Dad_Pokenav_LegendaryWarn,  FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { gText_Dad_Pokenav_Singlehanded,   FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, 0xFFFF },
    { gText_Dad_Pokenav_EverGrande,     FLAG_VISITED_EVER_GRANDE_CITY, 0xFFFF },
    { gText_Dad_Pokenav_NoAnswer,       FLAG_DAILY_DAD_CALL, 0xffff },
    
    // { gText_Mom_Pokenav_2B227B, 0xffff,              0xffff },
    // { gText_Mom_Pokenav_2B2310, FLAG_DEFEATED_PETALBURG_GYM,          0xffff },
    // { gText_Mom_Pokenav_2B23F3, FLAG_SYS_GAME_CLEAR, 0xffff },
//     { gText_Norman_Pokenav_2B5719, FLAG_ENABLE_NORMAN_MATCH_CALL,           0xFFFF },
//     { gText_Norman_Pokenav_2B5795, FLAG_DEFEATED_DEWFORD_GYM,           0xFFFF },
//     { gText_Norman_Pokenav_2B584D, FLAG_DEFEATED_LAVARIDGE_GYM,           0xFFFF },
//     { gText_Norman_Pokenav_2B58E3, FLAG_DEFEATED_PETALBURG_GYM,           0xFFFF },
//     { gText_Norman_Pokenav_2B5979, FLAG_RECEIVED_RED_OR_BLUE_ORB,           0xFFFF },
//     { gText_Norman_Pokenav_2B5A07, 0xFFFE,               0xFFFF },
//     { gText_Norman_Pokenav_2B5A69, FLAG_SYS_GAME_CLEAR,  0xFFFF },
//     { gText_Norman_Pokenav_2B5ACF, FLAG_SYS_GAME_CLEAR,  0xFFFF },
//     { gText_Norman_Pokenav_2B5B5E, FLAG_SYS_GAME_CLEAR,  0xFFFF },
    { NULL,                     0xffff,              0xffff }
};

static const struct MatchCallStructNPC sDadMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_LITTLEROOT_TOWN,
    .flag = 0xFFFF,//FLAG_ENABLE_MOM_MATCH_CALL,
    .desc = gMatchCallDesc_Dad,
    .name = gMatchCallName_Dad,
    .textData = sDadTextScripts,
    .dailyFlag = FLAG_DAILY_DAD_CALL,
};

static const match_call_text_data_t sStevenTextScripts[] = {
    { gText_Steven_Pokenav_2B5B95, 0xffff,              0xffff },
    { gText_Steven_Pokenav_2B5C53, FLAG_RUSTURF_TUNNEL_OPENED,          0xffff },
    { gText_Steven_Pokenav_2B5CC9, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xffff },
    { gText_Steven_Pokenav_2B5DB4, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xffff },
    { gText_Steven_Pokenav_2B5E26, FLAG_DEFEATED_MOSSDEEP_GYM,          0xffff },
    { gText_Steven_Pokenav_2B5EA2, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN,          0xffff },
    { gText_Steven_Pokenav_2B5ED9, FLAG_SYS_GAME_CLEAR, 0xffff },
    { NULL,                        0xffff,              0xffff },
};

static const struct MatchCallStructNPC sStevenMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_REGISTERED_STEVEN_POKENAV,
    .desc = gMatchCallDesc_Steven,
    .name = gMatchCallName_Steven,
    .textData = sStevenTextScripts,
    .dailyFlag = 0xFFFF,
};

static const match_call_text_data_t sMayTextScripts[] = {
    { gText_May_Pokenav_2B3AB3, 0xFFFF,              0xFFFF },
    { gText_May_Pokenav_2B3B3F, FLAG_DEFEATED_DEWFORD_GYM,          0xFFFF },
    { gText_May_Pokenav_2B3C13, FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { gText_May_Pokenav_2B3CF3, FLAG_HIDE_MAUVILLE_CITY_WALLY,          0xFFFF },
    { gText_May_Pokenav_2B3D4B, FLAG_RECEIVED_TM54,          0xFFFF },
    { gText_May_Pokenav_2B3DD1, FLAG_DEFEATED_LAVARIDGE_GYM,          0xFFFF },
    { gText_May_Pokenav_2B3E69, FLAG_DEFEATED_PETALBURG_GYM,          0xFFFF },
    { gText_May_Pokenav_2B3ECD, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_May_Pokenav_2B3F2B, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xFFFF },
    { gText_May_Pokenav_2B3FFB, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,          0xFFFF },
    { gText_May_Pokenav_2B402B, FLAG_MET_TEAM_AQUA_HARBOR,          0xFFFF },
    { gText_May_Pokenav_2B414B, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_May_Pokenav_2B4228, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN,          0xFFFF },
    { gText_May_Pokenav_2B42E0, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_May_Pokenav_2B4350, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                     0xFFFF,              0xFFFF }
};

static const struct MatchCallRival sMayMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .playerGender = MALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gMatchCallDesc_Rival,
    .name = gExpandedPlaceholder_May,
    .textData = sMayTextScripts
};

static const match_call_text_data_t sBrendanTextScripts[] = {
    { gText_Brendan_Pokenav_2B43EF, 0xFFFF,              0xFFFF },
    { gText_Brendan_Pokenav_2B4486, FLAG_DEFEATED_DEWFORD_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4560, FLAG_DELIVERED_DEVON_GOODS,          0xFFFF },
    { gText_Brendan_Pokenav_2B463F, FLAG_HIDE_MAUVILLE_CITY_WALLY,          0xFFFF },
    { gText_Brendan_Pokenav_2B46B7, FLAG_RECEIVED_TM54,          0xFFFF },
    { gText_Brendan_Pokenav_2B4761, FLAG_DEFEATED_LAVARIDGE_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B47F4, FLAG_DEFEATED_PETALBURG_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4882, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4909, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xFFFF },
    { gText_Brendan_Pokenav_2B49C4, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,          0xFFFF },
    { gText_Brendan_Pokenav_2B4A44, FLAG_MET_TEAM_AQUA_HARBOR,          0xFFFF },
    { gText_Brendan_Pokenav_2B4B28, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_Brendan_Pokenav_2B4C15, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN,          0xFFFF },
    { gText_Brendan_Pokenav_2B4CD8, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_Brendan_Pokenav_2B4D46, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallRival sBrendanMatchCallHeader =
{
    .type = MC_TYPE_RIVAL,
    .playerGender = FEMALE,
    .flag = FLAG_ENABLE_RIVAL_MATCH_CALL,
    .desc = gMatchCallDesc_Rival,
    .name = gExpandedPlaceholder_Brendan,
    .textData = sBrendanTextScripts
};

static const match_call_text_data_t sWallyTextScripts[] = {
    { gText_Wally_Pokenav_2B4DE2, 0xFFFF,     0xFFFF },
    { gText_Wally_Pokenav_2B4E57, FLAG_RUSTURF_TUNNEL_OPENED, 0xFFFF },
    { gText_Wally_Pokenav_2B4EA5, FLAG_DEFEATED_LAVARIDGE_GYM, 0xFFFF },
    { gText_Wally_Pokenav_2B4F41, FLAG_RECEIVED_CASTFORM, 0xFFFF },
    { gText_Wally_Pokenav_2B4FF3, FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 0xFFFF },
    { gText_Wally_Pokenav_2B50B1, FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, 0xFFFF },
    { gText_Wally_Pokenav_2B5100, FLAG_DEFEATED_WALLY_VICTORY_ROAD, 0xFFFF },
    { NULL,                       0xFFFF,     0xFFFF }
};

const struct MatchCallLocationOverride sWallyLocationData[] = {
    { FLAG_HIDE_MAUVILLE_CITY_WALLY,         MAPSEC_VERDANTURF_TOWN },
    { FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT,   MAPSEC_NONE },
    { FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY, MAPSEC_VICTORY_ROAD },
    { 0xFFFF,                                MAPSEC_NONE }
};

static const struct MatchCallWally sWallyMatchCallHeader =
{
    .type = MC_TYPE_WALLY,
    .mapSec = 0,
    .flag = FLAG_ENABLE_WALLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_WALLY_3,
    .desc = gMatchCallDesc_Wally,
    .textData = sWallyTextScripts,
    .locationData = sWallyLocationData
};

static const match_call_text_data_t sScottTextScripts[] = {
    { gText_Scott_Pokenav_2B5184, 0xFFFF,              0xFFFF },
    { gText_Scott_Pokenav_2B5275, FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY,          0xFFFF },
    { gText_Scott_Pokenav_2B5323, FLAG_RECEIVED_CASTFORM,          0xFFFF },
    { gText_Scott_Pokenav_2B53DB, FLAG_RECEIVED_RED_OR_BLUE_ORB,          0xFFFF },
    { gText_Scott_Pokenav_2B54A5, FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE,          0xFFFF },
    { gText_Scott_Pokenav_2B5541, FLAG_DEFEATED_SOOTOPOLIS_GYM,          0xFFFF },
    { gText_Scott_Pokenav_2B56CA, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                       0xFFFF,              0xFFFF }
};


static const struct MatchCallStructNPC sScottMatchCallHeader =
{
    .type = MC_TYPE_NPC,
    .mapSec = MAPSEC_NONE,
    .flag = FLAG_ENABLE_SCOTT_MATCH_CALL,
    .desc = gMatchCallDesc_Scott,
    .name = gMatchCallName_Scott,
    .textData = sScottTextScripts,
    .dailyFlag = 0xFFFF,
};

static const match_call_text_data_t sRoxanneTextScripts[] = {
    { gText_Roxanne_Pokenav_2B2456, 0xFFFE,              0xFFFF },
    { gText_Roxanne_Pokenav_2B250E, 0xFFFF,              0xFFFF },
    { gText_Roxanne_Pokenav_2B25C1, 0xFFFF,              0xFFFF },
    { gText_Roxanne_Pokenav_2B2607, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sRoxanneMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 10,
    .flag = FLAG_ENABLE_ROXANNE_MATCH_CALL,
    .rematchTableIdx = REMATCH_ROXANNE,
    .desc = gMatchCallDesc_Roxanne,
    .name = NULL,
    .textData = sRoxanneTextScripts
};

static const match_call_text_data_t sBrawlyTextScripts[] = {
    { gText_Brawly_Pokenav_2B2659, 0xFFFE,              0xFFFF },
    { gText_Brawly_Pokenav_2B275D, 0xFFFF,              0xFFFF },
    { gText_Brawly_Pokenav_2B286F, 0xFFFF,              0xFFFF },
    { gText_Brawly_Pokenav_2B28D1, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sBrawlyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 2,
    .flag = FLAG_ENABLE_BRAWLY_MATCH_CALL,
    .rematchTableIdx = REMATCH_BRAWLY,
    .desc = gMatchCallDesc_Brawly,
    .name = NULL,
    .textData = sBrawlyTextScripts
};

static const match_call_text_data_t sWattsonTextScripts[] = {
    { gText_Wattson_Pokenav_2B2912, 0xFFFE,              0xFFFF },
    { gText_Wattson_Pokenav_2B29CA, 0xFFFF,              0xFFFF },
    { gText_Wattson_Pokenav_2B2AB6, 0xFFFF,              0xFFFF },
    { gText_Wattson_Pokenav_2B2B01, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                         0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWattsonMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 9,
    .flag = FLAG_ENABLE_WATTSON_MATCH_CALL,
    .rematchTableIdx = REMATCH_WATTSON,
    .desc = gMatchCallDesc_Wattson,
    .name = NULL,
    .textData = sWattsonTextScripts
};

static const match_call_text_data_t sFlanneryTextScripts[] = {
    { gText_Flannery_Pokenav_2B2B4D, 0xFFFE,              0xFFFF },
    { gText_Flannery_Pokenav_2B2C0E, 0xFFFF,              0xFFFF },
    { gText_Flannery_Pokenav_2B2CF1, 0xFFFF,              0xFFFF },
    { gText_Flannery_Pokenav_2B2D54, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                          0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sFlanneryMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 3,
    .flag = FLAG_ENABLE_FLANNERY_MATCH_CALL,
    .rematchTableIdx = REMATCH_FLANNERY,
    .desc = gMatchCallDesc_Flannery,
    .name = NULL,
    .textData = sFlanneryTextScripts
};

static const match_call_text_data_t sNormanTextScripts[] = {
    { gText_Norman_Pokenav_2B5719, 0xFFFE,              0xFFFF },
    { gText_Norman_Pokenav_2B5795, 0xFFFF,              0xFFFF },
    { gText_Norman_Pokenav_2B584D, 0xFFFF,              0xFFFF },
    { gText_Norman_Pokenav_2B58E3, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sNormanMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 7,
    .flag = FLAG_ENABLE_NORMAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_NORMAN,
    .desc = gMatchCallDesc_Norman,
    .name = NULL, //gMatchCallName_Norman,
    .textData = sNormanTextScripts
};

static const match_call_text_data_t sWinonaTextScripts[] = {
    { gText_Winona_Pokenav_2B2DA4, 0xFFFE,              0xFFFF },
    { gText_Winona_Pokenav_2B2E2B, 0xFFFF,              0xFFFF },
    { gText_Winona_Pokenav_2B2EC2, 0xFFFF,              0xFFFF },
    { gText_Winona_Pokenav_2B2F16, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                        0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sWinonaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 11,
    .flag = FLAG_ENABLE_WINONA_MATCH_CALL,
    .rematchTableIdx = REMATCH_WINONA,
    .desc = gMatchCallDesc_Winona,
    .name = NULL,
    .textData = sWinonaTextScripts
};

static const match_call_text_data_t sTateLizaTextScripts[] = {
    { gText_TateLiza_Pokenav_2B2F97, 0xFFFE,              0xFFFF },
    { gText_TateLiza_Pokenav_2B306E, 0xFFFF,              0xFFFF },
    { gText_TateLiza_Pokenav_2B3158, 0xFFFF,              0xFFFF },
    { gText_TateLiza_Pokenav_2B31CD, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                          0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sTateLizaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 13,
    .flag = FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL,
    .rematchTableIdx = REMATCH_TATE_AND_LIZA,
    .desc = gMatchCallDesc_TateLiza,
    .name = NULL,
    .textData = sTateLizaTextScripts
};

static const match_call_text_data_t sJuanTextScripts[] = {
    { gText_Juan_Pokenav_2B3249, 0xFFFE,              0xFFFF },
    { gText_Juan_Pokenav_2B32EC, 0xFFFF,              0xFFFF },
    { gText_Juan_Pokenav_2B33AA, 0xFFFF,              0xFFFF },
    { gText_Juan_Pokenav_2B341E, FLAG_SYS_GAME_CLEAR, 0xFFFF },
    { NULL,                      0xFFFF,              0xFFFF }
};

static const struct MatchCallStructTrainer sJuanMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 14,
    .flag = FLAG_ENABLE_JUAN_MATCH_CALL,
    .rematchTableIdx = REMATCH_JUAN,
    .desc = gMatchCallDesc_Juan,
    .name = NULL,
    .textData = sJuanTextScripts
};

static const match_call_text_data_t sSidneyTextScripts[] = {
    { gText_Sidney_Pokenav_2B34CC, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sSidneyMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 15,
    .flag = FLAG_REMATCH_SIDNEY,
    .rematchTableIdx = REMATCH_SIDNEY,
    .desc = gMatchCallDesc_EliteFour,
    .name = NULL,
    .textData = sSidneyTextScripts
};

static const match_call_text_data_t sPhoebeTextScripts[] = {
    { gText_Phoebe_Pokenav_2B3561, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sPhoebeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 15,
    .flag = FLAG_REMATCH_PHOEBE,
    .rematchTableIdx = REMATCH_PHOEBE,
    .desc = gMatchCallDesc_EliteFour,
    .name = NULL,
    .textData = sPhoebeTextScripts
};

static const match_call_text_data_t sGlaciaTextScripts[] = {
    { gText_Glacia_Pokenav_2B35E4, 0xFFFF, 0xFFFF },
    { NULL,                        0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sGlaciaMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 15,
    .flag = FLAG_REMATCH_GLACIA,
    .rematchTableIdx = REMATCH_GLACIA,
    .desc = gMatchCallDesc_EliteFour,
    .name = NULL,
    .textData = sGlaciaTextScripts
};

static const match_call_text_data_t sDrakeTextScripts[] = {
    { gText_Drake_Pokenav_2B368B, 0xFFFF, 0xFFFF },
    { NULL,                       0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sDrakeMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 15,
    .flag = FLAG_REMATCH_DRAKE,
    .rematchTableIdx = REMATCH_DRAKE,
    .desc = gMatchCallDesc_EliteFour,
    .name = NULL,
    .textData = sDrakeTextScripts
};

static const match_call_text_data_t sWallaceTextScripts[] = {
    { gText_Wallace_Pokenav_2B3790, 0xFFFF, 0xFFFF },
    { NULL,                         0xFFFF, 0xFFFF }
};

static const struct MatchCallStructTrainer sWallaceMatchCallHeader =
{
    .type = MC_TYPE_LEADER,
    .mapSec = 15,
    .flag = FLAG_REMATCH_WALLACE,
    .rematchTableIdx = REMATCH_WALLACE,
    .desc = gMatchCallDesc_Champion,
    .name = NULL,
    .textData = sWallaceTextScripts
};

static const match_call_t sMatchCallHeaders[] = {
    {.npc    = &sAlexMatchCallHeader}, // Player char sorts this to the top of the list
    {.npc    = &sDadMatchCallHeader},
    {.birch  = &sProfBirchMatchCallHeader},
    {.rival  = &sBrendanMatchCallHeader},
    {.rival  = &sMayMatchCallHeader},
    {.wally  = &sWallyMatchCallHeader},
//  {.npc    = &sMrStoneMatchCallHeader},
    {.npc    = &sStevenMatchCallHeader},
    {.npc    = &sScottMatchCallHeader},
    {.leader = &sRoxanneMatchCallHeader},
    {.leader = &sBrawlyMatchCallHeader},
    {.leader = &sWattsonMatchCallHeader},
    {.leader = &sFlanneryMatchCallHeader},
    {.leader = &sNormanMatchCallHeader},
    {.leader = &sWinonaMatchCallHeader},
    {.leader = &sTateLizaMatchCallHeader},
    {.leader = &sJuanMatchCallHeader},
    {.leader = &sSidneyMatchCallHeader},
    {.leader = &sPhoebeMatchCallHeader},
    {.leader = &sGlaciaMatchCallHeader},
    {.leader = &sDrakeMatchCallHeader},
    {.leader = &sWallaceMatchCallHeader}
};

static bool32 (*const sMatchCallGetFlagFuncs[])(match_call_t) = {
    MatchCallGetFlag_NPC,
    MatchCallGetFlag_Trainer,
    MatchCallGetFlag_Wally,
    MatchCallGetFlag_Rival,
    MatchCallGetFlag_Birch,
    MatchCallGetFlag_NPC,
};

static u8 (*const sMatchCallGetMapSecFuncs[])(match_call_t) = {
    MatchCall_GetMapSec_NPC,
    MatchCall_GetMapSec_Trainer,
    MatchCall_GetMapSec_Wally,
    MatchCall_GetMapSec_Rival,
    MatchCall_GetMapSec_Birch, 
    MatchCall_GetMapSec_NPC,
};

static bool32 (*const sMatchCall_IsRematchableFunctions[])(match_call_t) = {
    MatchCall_IsRematchable_NPC,
    MatchCall_IsRematchable_Trainer,
    MatchCall_IsRematchable_Wally,
    MatchCall_IsRematchable_Rival,
    MatchCall_IsRematchable_Birch,
    MatchCall_IsRematchable_NPC,
};

static bool32 (*const sMatchCall_HasCheckPageFunctions[])(match_call_t) = {
    MatchCall_HasCheckPage_NPC,
    MatchCall_HasCheckPage_Trainer,
    MatchCall_HasCheckPage_Wally,
    MatchCall_HasCheckPage_Rival,
    MatchCall_HasCheckPage_Birch,
    MatchCall_HasCheckPage_NPC,
};

static u32 (*const sMatchCall_GetRematchTableIdxFunctions[])(match_call_t) = {
    MatchCall_GetRematchTableIdx_NPC,
    MatchCall_GetRematchTableIdx_Trainer,
    MatchCall_GetRematchTableIdx_Wally,
    MatchCall_GetRematchTableIdx_Rival,
    MatchCall_GetRematchTableIdx_Birch,
    MatchCall_GetRematchTableIdx_NPC,
};

static void (*const sMatchCall_GetMessageFunctions[])(match_call_t, u8 *) = {
    MatchCall_GetMessage_NPC,
    MatchCall_GetMessage_Trainer,
    MatchCall_GetMessage_Wally,
    MatchCall_GetMessage_Rival,
    MatchCall_GetMessage_Birch,
    MatchCall_GetMessage_Alex,
};

static void (*const sMatchCall_GetNameAndDescFunctions[])(match_call_t, const u8 **, const u8 **) = {
    MatchCall_GetNameAndDesc_NPC,
    MatchCall_GetNameAndDesc_Trainer,
    MatchCall_GetNameAndDesc_Wally,
    MatchCall_GetNameAndDesc_Rival,
    MatchCall_GetNameAndDesc_Birch,
    MatchCall_GetNameAndDesc_NPC,
};

static const struct MatchCallCheckPageOverride sCheckPageOverrides[] = {
    {
        .idx = 7, //MC_HEADER_STEVEN,
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = 0xFFFF,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_BeforeMeteorFallsBattle,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_BeforeMeteorFallsBattle
        }
    },
    {
        .idx = 7, //MC_HEADER_STEVEN,
        .facilityClass = FACILITY_CLASS_STEVEN,
        .flag = FLAG_DEFEATED_MOSSDEEP_GYM,
        .flavorTexts = {
            [CHECK_PAGE_STRATEGY] = gText_MatchCallSteven_Strategy,
            [CHECK_PAGE_POKEMON]  = gText_MatchCallSteven_Pokemon,
            [CHECK_PAGE_INTRO_1]  = gText_MatchCallSteven_Intro1_AfterMeteorFallsBattle,
            [CHECK_PAGE_INTRO_2]  = gText_MatchCallSteven_Intro2_AfterMeteorFallsBattle
        }
    },
    {
        .idx = 3, //MC_HEADER_BRENDAN,
        .facilityClass = FACILITY_CLASS_BRENDAN,
        .flag = 0xFFFF,
        .flavorTexts = MCFLAVOR(Brendan)
    },
    {
        .idx = 4, //MC_HEADER_MAY,
        .facilityClass = FACILITY_CLASS_MAY,
        .flag = 0xFFFF,
        .flavorTexts = MCFLAVOR(May)
    }
};

// .text

static u32 MatchCallGetFunctionIndex(match_call_t matchCall)
{
    switch (matchCall.common->type)
    {
        default:
        case MC_TYPE_NPC:
            return 0;
        case MC_TYPE_TRAINER:
        case MC_TYPE_LEADER:
            return 1;
        case MC_TYPE_WALLY:
            return 2;
        case MC_TYPE_RIVAL:
            return 3;
        case MC_TYPE_BIRCH:
            return 4;
        case MC_TYPE_ALEX:
            return 5;
    }
}

u32 GetTrainerIdxByRematchIdx(u32 rematchIdx)
{
    return gRematchTable[rematchIdx].trainerIds[0];
}

s32 GetRematchIdxByTrainerIdx(s32 trainerIdx)
{
    s32 rematchIdx;

    for (rematchIdx = 0; rematchIdx < REMATCH_TABLE_ENTRIES; rematchIdx++)
    {
        if (gRematchTable[rematchIdx].trainerIds[0] == trainerIdx)
            return rematchIdx;
    }
    return -1;
}

bool32 MatchCall_GetEnabled(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetFlagFuncs[i](matchCall);
}

static bool32 MatchCallGetFlag_NPC(match_call_t matchCall)
{
    if (matchCall.npc->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.npc->flag);
}

static bool32 MatchCallGetFlag_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.trainer->flag);
}

static bool32 MatchCallGetFlag_Wally(match_call_t matchCall)
{
    if (matchCall.wally->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.wally->flag);
}

static bool32 MatchCallGetFlag_Rival(match_call_t matchCall)
{
    if (matchCall.rival->playerGender != GetPlayerGender())
        return FALSE;
    if (matchCall.rival->flag == 0xffff)
        return TRUE;
    return FlagGet(matchCall.rival->flag);
}

static bool32 MatchCallGetFlag_Birch(match_call_t matchCall)
{
    return FlagGet(matchCall.birch->flag);
}

u8 MatchCall_GetMapSec(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCallGetMapSecFuncs[i](matchCall);
}

static u8 MatchCall_GetMapSec_NPC(match_call_t matchCall)
{
    return matchCall.npc->mapSec;
}

static u8 MatchCall_GetMapSec_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->mapSec;
}

static u8 MatchCall_GetMapSec_Wally(match_call_t matchCall)
{
    s32 i;

    for (i = 0; matchCall.wally->locationData[i].flag != 0xffff; i++)
    {
        if (!FlagGet(matchCall.wally->locationData[i].flag))
            break;
    }
    return matchCall.wally->locationData[i].mapSec;
}

static u8 MatchCall_GetMapSec_Rival(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

static u8 MatchCall_GetMapSec_Birch(match_call_t matchCall)
{
    return MAPSEC_NONE;
}

bool32 MatchCall_IsRematchable(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return 0;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_IsRematchableFunctions[i](matchCall);
}

static bool32 MatchCall_IsRematchable_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Trainer(match_call_t matchCall)
{
    if (matchCall.trainer->rematchTableIdx >= REMATCH_ELITE_FOUR_ENTRIES)
        return FALSE;
    return gSaveBlock1Ptr->trainerRematches[matchCall.trainer->rematchTableIdx] ? TRUE : FALSE;
}

static bool32 MatchCall_IsRematchable_Wally(match_call_t matchCall)
{
    return gSaveBlock1Ptr->trainerRematches[matchCall.wally->rematchTableIdx] ? TRUE : FALSE;
}

static bool32 MatchCall_IsRematchable_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_IsRematchable_Birch(match_call_t matchCall)
{
    return FALSE;
}

bool32 MatchCall_HasCheckPage(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return FALSE;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    if (sMatchCall_HasCheckPageFunctions[i](matchCall))
        return TRUE;
    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return TRUE;
    }
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_NPC(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Trainer(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Wally(match_call_t matchCall)
{
    return TRUE;
}

static bool32 MatchCall_HasCheckPage_Rival(match_call_t matchCall)
{
    return FALSE;
}

static bool32 MatchCall_HasCheckPage_Birch(match_call_t matchCall)
{
    return FALSE;
}

u32 MatchCall_GetRematchTableIdx(u32 idx)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return REMATCH_TABLE_ENTRIES;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    return sMatchCall_GetRematchTableIdxFunctions[i](matchCall);
}

static u32 MatchCall_GetRematchTableIdx_NPC(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Trainer(match_call_t matchCall)
{
    return matchCall.trainer->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Wally(match_call_t matchCall)
{
    return matchCall.wally->rematchTableIdx;
}

static u32 MatchCall_GetRematchTableIdx_Rival(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

static u32 MatchCall_GetRematchTableIdx_Birch(match_call_t matchCall)
{
    return REMATCH_TABLE_ENTRIES;
}

void MatchCall_GetMessage(u32 idx, u8 *dest)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetMessageFunctions[i](matchCall, dest);
}

static void MatchCall_GetMessage_NPC(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.npc->textData, dest);
    // Set the daily flag, if there is one, as part of this call
    if (matchCall.npc->dailyFlag != 0xFFFF)
        FlagSet(matchCall.npc->dailyFlag);
}

static void MatchCall_GetMessage_Trainer(match_call_t matchCall, u8 *dest)
{
    if (matchCall.common->type != 5)
        MatchCall_BufferCallMessageText(matchCall.trainer->textData, dest);
    else
        MatchCall_BufferCallMessageTextByRematchTeam(matchCall.leader->textData, matchCall.leader->rematchTableIdx, dest);
}

static void MatchCall_GetMessage_Wally(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.wally->textData, dest);
}

static void MatchCall_GetMessage_Rival(match_call_t matchCall, u8 *dest)
{
    MatchCall_BufferCallMessageText(matchCall.rival->textData, dest);
}

static void MatchCall_GetMessage_Birch(match_call_t matchCall, u8 *dest)
{
    sub_8197080(dest);
}

static void MatchCall_BufferCallMessageText(const match_call_text_data_t *textData, u8 *dest)
{
    u32 i;
    // Find the bottom of the call array
    for (i = 0; textData[i].text != NULL; i++);
    if (i) i--;
    // Work our way up from the bottom of the table
    while (i) {
        // If flag1 is set, or if there's no flag specified, we can use this entry
        if (textData[i].flag != 0xffff && FlagGet(textData[i].flag) == TRUE)
            break;
        i--;
    }
    // If there's a flag2 specified, set it as part of this call
    if (textData[i].flag2 != 0xffff) {
        FlagSet(textData[i].flag2);
    }
    // Return the text of the entry
    StringExpandPlaceholders(dest, textData[i].text);
}

static void MatchCall_BufferCallMessageTextByRematchTeam(const match_call_text_data_t *textData, u16 idx, u8 *dest)
{
    u32 i;
    // Loop through the table
    for (i = 0; textData[i].text != NULL; i++)
    {
        // If flag is "FFFE", we found the start of the rematch entries, accept it
        if (textData[i].flag == 0xfffe)
            break;
        // If the flag specified is not set, accept it.
        // This is effectively the same as the story progressive method
        if (textData[i].flag != 0xffff && !FlagGet(textData[i].flag))
            break;
    }
    // If the accepted entry isn't an fffe entry
    // (This code block was previously used for Norman, basically, who had rematch entries, but also story progress entries)
    if (textData[i].flag != 0xfffe)
    {
        if (i)
            i--;
        // Set any specified flag2
        if (textData[i].flag2 != 0xffff)
            FlagSet(textData[i].flag2);
        // Return the text of the entry
        StringExpandPlaceholders(dest, textData[i].text);
    }
    // Otherwise, if the accepted entry is FFFE
    else
    {
        // If the game is cleared
        if (FlagGet(FLAG_SYS_GAME_CLEAR))
        {
            do //Loop does nothing but make a useless block?
            {
                // If there's a rematch available, choose entry 2
                // (usually "We're waiting for you in the gym!")
                if (gSaveBlock1Ptr->trainerRematches[idx])
                    i += 2;
                // If we have rematched them, choose entry 3
                // (usually "I've lost, but I'll get better.")
                else if (CountBattledRematchTeams(idx) >= 2)
                    i += 3;
                // Otherwise, choose entry 1
                // (usually "Congrats, new champion!")
                else
                    i++;
            } while (0);
        }
        // Return the text of the selected entry
        StringExpandPlaceholders(dest, textData[i].text);
    }
}

void MatchCall_GetNameAndDesc(u32 idx, const u8 **desc, const u8 **name)
{
    match_call_t matchCall;
    u32 i;

    if (idx > ARRAY_COUNT(sMatchCallHeaders) - 1)
        return;
    matchCall = sMatchCallHeaders[idx];
    i = MatchCallGetFunctionIndex(matchCall);
    sMatchCall_GetNameAndDescFunctions[i](matchCall, desc, name);
}

static void MatchCall_GetNameAndDesc_NPC(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.npc->desc;
    *name = matchCall.npc->name;
}

static void MatchCall_GetNameAndDesc_Trainer(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    match_call_t _matchCall = matchCall;
    if (_matchCall.trainer->name == NULL)
        MatchCall_GetNameAndDescByRematchIdx(_matchCall.trainer->rematchTableIdx, desc, name);
    else
        *name = _matchCall.trainer->name;
    *desc = _matchCall.trainer->desc;
}

static void MatchCall_GetNameAndDesc_Wally(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    MatchCall_GetNameAndDescByRematchIdx(matchCall.wally->rematchTableIdx, desc, name);
    *desc = matchCall.wally->desc;
}

static void MatchCall_GetNameAndDesc_Rival(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.rival->desc;
    *name = matchCall.rival->name;
}

static void MatchCall_GetNameAndDesc_Birch(match_call_t matchCall, const u8 **desc, const u8 **name)
{
    *desc = matchCall.birch->desc;
    *name = matchCall.birch->name;
}

static void MatchCall_GetNameAndDescByRematchIdx(u32 idx, const u8 **desc, const u8 **name)
{
    const struct Trainer *trainer = gTrainers + GetTrainerIdxByRematchIdx(idx);
    *desc = gTrainerClassNames[trainer->trainerClass];
    *name = trainer->trainerName;
}

const u8 *MatchCall_GetOverrideFlavorText(u32 idx, u32 offset)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
        {
            for (; i + 1 < ARRAY_COUNT(sCheckPageOverrides) &&
                sCheckPageOverrides[i + 1].idx == idx &&
                FlagGet(sCheckPageOverrides[i + 1].flag); i++);
            return sCheckPageOverrides[i].flavorTexts[offset];
        }
    }
    return NULL;
}

int MatchCall_GetOverrideFacilityClass(u32 idx)
{
    u32 i;

    for (i = 0; i < ARRAY_COUNT(sCheckPageOverrides); i++)
    {
        if (sCheckPageOverrides[i].idx == idx)
            return sCheckPageOverrides[i].facilityClass;
    }
    return -1;
}

bool32 MatchCall_HasRematchId(u32 idx)
{
    int i;

    for (i = 0; i < (int)ARRAY_COUNT(sMatchCallHeaders); i++)
    {
        u32 r0 = MatchCall_GetRematchTableIdx(i);
        if (r0 != REMATCH_TABLE_ENTRIES && r0 == idx)
            return TRUE;
    }
    return FALSE;
}

void SetMatchCallRegisteredFlag(void)
{
    int r0 = GetRematchIdxByTrainerIdx(gSpecialVar_0x8004);
    if (r0 >= 0)
        FlagSet(FLAG_MATCH_CALL_REGISTERED + r0);
}
