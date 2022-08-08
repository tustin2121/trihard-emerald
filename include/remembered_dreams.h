#ifndef GUARD_REMEMBERED_DREAMS_H
#define GUARD_REMEMBERED_DREAMS_H

u32 GetRememberedStat(u8 index);
void RememberStat(u8 index, u32 value);
void RememberWhiteout();
u8 *GetRememberedFlagPointer(u16 id);

void InitRememberedDreams();
void LoadAndProcessRememberedDreams();
void SaveRememberedDreams();

struct ScriptContext;
bool8 DoDreamCutscenes(struct ScriptContext *ctx);


#endif // GUARD_REMEMBERED_DREAMS_H
