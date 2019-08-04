#ifndef GUARD_REMEMBERED_DREAMS_H
#define GUARD_REMEMBERED_DREAMS_H

u32 GetRememberedStat(u8 index);
void RememberStat(u8 index, u32 value);
void RememberWhiteout();

void InitRememberedDreams();
void LoadAndProcessRememberedDreams();
void SaveRememberedDreams();


#endif // GUARD_REMEMBERED_DREAMS_H
