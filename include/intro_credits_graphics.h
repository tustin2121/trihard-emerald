#ifndef GUARD_INTRO_CREDITS_GRAPHICS_H
#define GUARD_INTRO_CREDITS_GRAPHICS_H

extern u16 gUnknown_0203BD24;
extern s16 gUnknown_0203BD26;
extern s16 gUnknown_0203BD28;

extern const struct CompressedSpriteSheet gIntro2BrendanSpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2MaySpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2BicycleSpriteSheet[];
extern const struct CompressedSpriteSheet gIntro2FlygonSpriteSheet[];
extern const struct SpritePalette gIntroBikeAndFlygonPalette[];
extern const struct CompressedSpriteSheet gCreditsBrendanSpriteSheet[];
extern const struct CompressedSpriteSheet gCreditsMaySpriteSheet[];
extern const struct CompressedSpriteSheet gCreditsBikeSpriteSheet[];
extern const struct CompressedSpriteSheet gCreditsBrendanSpriteSheet2[];
extern const struct CompressedSpriteSheet gCreditsMaySpriteSheet2[];
extern const struct CompressedSpriteSheet gCreditsProtagMaleSpriteSheet[];
extern const struct CompressedSpriteSheet gCreditsProtagFemaleSpriteSheet[];
extern const struct CompressedSpriteSheet gCreditsProtagMale5SpriteSheet[];
extern const struct CompressedSpriteSheet gCreditsProtagFemale5SpriteSheet[];
extern const struct SpritePalette gCreditsPalettes1[];

void load_intro_part2_graphics(u8 a);
void sub_817B150(u8 a);
void sub_817B1C8(u8);
void sub_817B3A8(u8);
u8 CreateBicycleAnimationTask(u8 a, u16 b, u16 c, u16 d);
void sub_817B540(u8);
u8 intro_create_brendan_sprite(s16 x, s16 y);
u8 intro_create_may_sprite(s16 x, s16 y);
u8 intro_create_flygon_sprite(s16 a, s16 b);
u8 credits_create_maleprotag_sprite(s16 x, s16 y);
u8 credits_create_femaleprotag_sprite(s16 x, s16 y);

#endif // GUARD_INTRO_CREDITS_GRAPHICS_H
