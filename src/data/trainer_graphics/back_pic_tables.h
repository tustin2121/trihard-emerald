const struct MonCoords gTrainerBackPicCoords[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RED] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_LEAF] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_WALLY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_STEVEN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_MALE_1] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_MALE_2] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_MALE_3] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_MALE_4] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_MALE_5] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_FEMALE_1] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_FEMALE_2] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_FEMALE_3] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_FEMALE_4] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_PROTAG_FEMALE_5] = {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
const struct CompressedSpriteSheet gTrainerBackPicTable[] =
{
    (const u32 *)gTrainerBackPic_Brendan, 0x2000, TRAINER_BACK_PIC_BRENDAN,
    (const u32 *)gTrainerBackPic_May, 0x2000, TRAINER_BACK_PIC_MAY,
    (const u32 *)gTrainerBackPic_Red, 0x2800, TRAINER_BACK_PIC_RED,
    (const u32 *)gTrainerBackPic_Leaf, 0x2800, TRAINER_BACK_PIC_LEAF,
    (const u32 *)gTrainerBackPic_RubySapphireBrendan, 0x2000, TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN,
    (const u32 *)gTrainerBackPic_RubySapphireMay, 0x2000, TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY,
    (const u32 *)gTrainerBackPic_Wally, 0x2000, TRAINER_BACK_PIC_WALLY,
    (const u32 *)gTrainerBackPic_Steven, 0x2000, TRAINER_BACK_PIC_STEVEN,
    (const u32 *)gTrainerBackPicTable_ProtagMale1, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_1,
    (const u32 *)gTrainerBackPicTable_ProtagFemale1, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_1,
    (const u32 *)gTrainerBackPicTable_ProtagMale2, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_2,
    (const u32 *)gTrainerBackPicTable_ProtagFemale2, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_2,
    (const u32 *)gTrainerBackPicTable_ProtagMale3, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_3,
    (const u32 *)gTrainerBackPicTable_ProtagFemale3, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_3,
    (const u32 *)gTrainerBackPicTable_ProtagMale4, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_4,
    (const u32 *)gTrainerBackPicTable_ProtagFemale4, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_4,
    (const u32 *)gTrainerBackPicTable_ProtagMale5, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_5,
    (const u32 *)gTrainerBackPicTable_ProtagFemale5, 0x2000, TRAINER_BACK_PIC_PROTAG_MALE_5,
};

const struct CompressedSpritePalette gTrainerBackPicPaletteTable[] =
{
    TRAINER_BACK_PAL(BRENDAN, gTrainerPalette_Brendan),
    TRAINER_BACK_PAL(MAY, gTrainerPalette_May),
    TRAINER_BACK_PAL(RED, gTrainerBackPicPalette_Red),
    TRAINER_BACK_PAL(LEAF, gTrainerBackPicPalette_Leaf),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_BRENDAN, gTrainerPalette_RubySapphireBrendan),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_MAY, gTrainerPalette_RubySapphireMay),
    TRAINER_BACK_PAL(WALLY, gTrainerPalette_Wally),
    TRAINER_BACK_PAL(STEVEN, gTrainerPalette_Steven),
    TRAINER_BACK_PAL(PROTAG_MALE_1, gTrainerBackPicPalette_ProtagMale),
    TRAINER_BACK_PAL(PROTAG_FEMALE_1, gTrainerBackPicPalette_ProtagFemale),
    TRAINER_BACK_PAL(PROTAG_MALE_2, gTrainerBackPicPalette_ProtagMale),
    TRAINER_BACK_PAL(PROTAG_FEMALE_2, gTrainerBackPicPalette_ProtagFemale),
    TRAINER_BACK_PAL(PROTAG_MALE_3, gTrainerBackPicPalette_ProtagMale),
    TRAINER_BACK_PAL(PROTAG_FEMALE_3, gTrainerBackPicPalette_ProtagFemale),
    TRAINER_BACK_PAL(PROTAG_MALE_4, gTrainerBackPicPalette_ProtagMale),
    TRAINER_BACK_PAL(PROTAG_FEMALE_4, gTrainerBackPicPalette_ProtagFemale),
    TRAINER_BACK_PAL(PROTAG_MALE_5, gTrainerBackPicPalette_ProtagMale),
    TRAINER_BACK_PAL(PROTAG_FEMALE_5, gTrainerBackPicPalette_ProtagFemale),
};
