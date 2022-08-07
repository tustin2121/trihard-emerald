#ifndef GUARD_FIELD_MESSAGE_BOX_H
#define GUARD_FIELD_MESSAGE_BOX_H

enum
{
    FIELD_MESSAGE_BOX_HIDDEN,
    FIELD_MESSAGE_BOX_UNUSED,
    FIELD_MESSAGE_BOX_NORMAL,
    FIELD_MESSAGE_BOX_AUTO_SCROLL,
};

enum
{
    FIELD_MESSAGE_TYPE_DEFAULT,
    FIELD_MESSAGE_TYPE_STANDARD,
    FIELD_MESSAGE_TYPE_DIALOG,
    FIELD_MESSAGE_TYPE_SIGN,
    FIELD_MESSAGE_TYPE_DESCRIBE,
    FIELD_MESSAGE_TYPE_DREAM,
};

bool8 ShowFieldMessage(const u8 *message);
bool8 sub_8098238(const u8 *message);
bool8 sub_80982B8(void);
bool8 ShowFieldAutoScrollMessage(const u8 *message);
void HideFieldMessageBox(void);
bool8 IsFieldMessageBoxHidden(void);
u8 GetFieldMessageBoxMode(void);
void SetFieldMessageBoxType(u8 type);
void sub_8098374(void);
void InitFieldMessageBox(void);

#endif // GUARD_FIELD_MESSAGE_BOX_H
