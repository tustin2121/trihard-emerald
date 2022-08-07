#include "global.h"
#include "string_util.h"
#include "text.h"
#include "rtc.h"

// Reference to an assembly defined constant, the start of the ROM
// We don't actually use the value, just the address it's at.
extern const int Start;

extern const u8 gYN_Yeah[];
extern const u8 gYN_Nah[];
extern const u8 gYN_ERROR[];
#define gYN_DefaultYes gYN_Yeah
#define gYN_DefaultNo gYN_Nah

EWRAM_DATA u8 gStringVar1[0x100] = {0};
EWRAM_DATA u8 gStringVar2[0x100] = {0};
EWRAM_DATA u8 gStringVar3[0x100] = {0};
EWRAM_DATA u8 gStringVar4[0x3E8] = {0};

EWRAM_DATA u8 gStringWorking[0x100] = {0};
EWRAM_DATA u8 gYesNoStringVar[0x40] = {0};
EWRAM_DATA const u8* gYesString = gYN_DefaultYes;
EWRAM_DATA const u8* gNoString = gYN_DefaultNo;

static const u8 sDigits[] = __("0123456789ABCDEF");

static const s32 sPowersOfTen[] =
{
             1,
            10,
           100,
          1000,
         10000,
        100000,
       1000000,
      10000000,
     100000000,
    1000000000,
};

u8 *StringCopy10(u8 *dest, const u8 *src)
{
    u8 i;
    u32 limit = 10;

    for (i = 0; i < limit; i++)
    {
        dest[i] = src[i];

        if (dest[i] == EOS)
            return &dest[i];
    }

    dest[i] = EOS;
    return &dest[i];
}

u8 *StringGetEnd10(u8 *str)
{
    u8 i;
    u32 limit = 10;

    for (i = 0; i < limit; i++)
        if (str[i] == EOS)
            return &str[i];

    str[i] = EOS;
    return &str[i];
}

u8 *StringCopy7(u8 *dest, const u8 *src)
{
    s32 i;
    s32 limit = 7;

    for (i = 0; i < limit; i++)
    {
        dest[i] = src[i];

        if (dest[i] == EOS)
            return &dest[i];
    }

    dest[i] = EOS;
    return &dest[i];
}

u8 *StringCopy(u8 *dest, const u8 *src)
{
    while (*src != EOS)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = EOS;
    return dest;
}

u8 *StringAppend(u8 *dest, const u8 *src)
{
    while (*dest != EOS)
        dest++;

    return StringCopy(dest, src);
}

u8 *StringCopyN(u8 *dest, const u8 *src, u8 n)
{
    u16 i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];

    return &dest[n];
}

u8 *StringAppendN(u8 *dest, const u8 *src, u8 n)
{
    while (*dest != EOS)
        dest++;

    return StringCopyN(dest, src, n);
}

u16 StringLength(const u8 *str)
{
    u16 length = 0;

    while (str[length] != EOS)
        length++;

    return length;
}

s32 StringCompare(const u8 *str1, const u8 *str2)
{
    while (*str1 == *str2)
    {
        if (*str1 == EOS)
            return 0;
        str1++;
        str2++;
    }

    return *str1 - *str2;
}

s32 StringCompareN(const u8 *str1, const u8 *str2, u32 n)
{
    while (*str1 == *str2)
    {
        if (*str1 == EOS)
            return 0;
        str1++;
        str2++;
        if (--n == 0)
            return 0;
    }

    return *str1 - *str2;
}

bool8 IsStringLengthAtLeast(const u8 *str, s32 n)
{
    u8 i;

    for (i = 0; i < n; i++)
        if (str[i] && str[i] != EOS)
            return TRUE;

    return FALSE;
}

extern const u8 gText_Num1[];
extern const u8 gText_Num2[];
extern const u8 gText_Num3[];
extern const u8 gText_Num4[];
extern const u8 gText_Num5[];
u8 *ConvertIntToNameStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n)
{
    switch (value) {
        case 1: return StringCopy(dest, gText_Num1);
        case 2: return StringCopy(dest, gText_Num2);
        case 3: return StringCopy(dest, gText_Num3);
        case 4: return StringCopy(dest, gText_Num4);
        case 5: return StringCopy(dest, gText_Num5);
        default: return ConvertIntToDecimalStringN(dest,value, mode, n);
    }
}

u8 *ConvertIntToDecimalStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n)
{
    enum { WAITING_FOR_NONZERO_DIGIT, WRITING_DIGITS, WRITING_SPACES } state;
    s32 powerOfTen;
    s32 largestPowerOfTen = sPowersOfTen[n - 1];

    state = WAITING_FOR_NONZERO_DIGIT;

    if (mode == STR_CONV_MODE_RIGHT_ALIGN)
        state = WRITING_SPACES;

    if (mode == STR_CONV_MODE_LEADING_ZEROS)
        state = WRITING_DIGITS;

    for (powerOfTen = largestPowerOfTen; powerOfTen > 0; powerOfTen /= 10)
    {
        u8 c;
        u16 digit = value / powerOfTen;
        s32 temp = value - (powerOfTen * digit);

        if (state == WRITING_DIGITS)
        {
            u8 *out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (digit != 0 || powerOfTen == 1)
        {
            u8 *out;
            state = WRITING_DIGITS;
            out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (state == WRITING_SPACES)
        {
            *dest++ = 0x77;
        }

        value = temp;
    }

    *dest = EOS;
    return dest;
}

u8 *ConvertUIntToDecimalStringN(u8 *dest, u32 value, enum StringConvertMode mode, u8 n)
{
    enum { WAITING_FOR_NONZERO_DIGIT, WRITING_DIGITS, WRITING_SPACES } state;
    s32 powerOfTen;
    s32 largestPowerOfTen = sPowersOfTen[n - 1];

    state = WAITING_FOR_NONZERO_DIGIT;

    if (mode == STR_CONV_MODE_RIGHT_ALIGN)
        state = WRITING_SPACES;

    if (mode == STR_CONV_MODE_LEADING_ZEROS)
        state = WRITING_DIGITS;

    for (powerOfTen = largestPowerOfTen; powerOfTen > 0; powerOfTen /= 10)
    {
        u8 c;
        u16 digit = value / powerOfTen;
        u32 temp = value - (powerOfTen * digit);

        if (state == WRITING_DIGITS)
        {
            u8 *out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (digit != 0 || powerOfTen == 1)
        {
            u8 *out;
            state = WRITING_DIGITS;
            out = dest++;

            if (digit <= 9)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (state == WRITING_SPACES)
        {
            *dest++ = 0x77;
        }

        value = temp;
    }

    *dest = EOS;
    return dest;
}

u8 *ConvertIntToHexStringN(u8 *dest, s32 value, enum StringConvertMode mode, u8 n)
{
    enum { WAITING_FOR_NONZERO_DIGIT, WRITING_DIGITS, WRITING_SPACES } state;
    u8 i;
    s32 powerOfSixteen;
    s32 largestPowerOfSixteen = 1;

    for (i = 1; i < n; i++)
        largestPowerOfSixteen *= 16;

    state = WAITING_FOR_NONZERO_DIGIT;

    if (mode == STR_CONV_MODE_RIGHT_ALIGN)
        state = WRITING_SPACES;

    if (mode == STR_CONV_MODE_LEADING_ZEROS)
        state = WRITING_DIGITS;

    for (powerOfSixteen = largestPowerOfSixteen; powerOfSixteen > 0; powerOfSixteen /= 16)
    {
        u8 c;
        u32 digit = value / powerOfSixteen;
        s32 temp = value % powerOfSixteen;

        if (state == WRITING_DIGITS)
        {
            char *out = dest++;

            if (digit <= 0xF)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (digit != 0 || powerOfSixteen == 1)
        {
            char *out;
            state = WRITING_DIGITS;
            out = dest++;

            if (digit <= 0xF)
                c = sDigits[digit];
            else
                c = CHAR_QUESTION_MARK;

            *out = c;
        }
        else if (state == WRITING_SPACES)
        {
            *dest++ = 0x77;
        }

        value = temp;
    }

    *dest = EOS;
    return dest;
}

u8 *StringExpandPlaceholders(u8 *dest, const u8 *src)
{
    for (;;)
    {
        u8 c = *src++;
        u8 placeholderId;
        const u8 *expandedString;

        switch (c)
        {
            case PLACEHOLDER_BEGIN:
                placeholderId = *src++;
                expandedString = GetExpandedPlaceholder(placeholderId);
                dest = StringExpandPlaceholders(dest, expandedString);
                break;
            case EXT_CTRL_CODE_BEGIN:
                *dest++ = c;
                c = *src++;
                *dest++ = c;

                switch (c)
                {
                    case 0x07:
                    case 0x09:
                    case 0x0F:
                    case 0x15:
                    case 0x16:
                    case 0x17:
                    case 0x18:
                    // case 0x1C:
                        break;
                    case 0x04:
                        *dest++ = *src++;
                    case 0x0B:
                        *dest++ = *src++;
                    default:
                        *dest++ = *src++;
                }
                break;
            case EOS:
                *dest = EOS;
                return dest;
            case CHAR_PROMPT_SCROLL:
            case CHAR_PROMPT_CLEAR:
            case CHAR_NEWLINE:
            default:
                *dest++ = c;
        }
    }
}

u8 *StringBraille(u8 *dest, const u8 *src)
{
    u8 setBrailleFont[] = { EXT_CTRL_CODE_BEGIN, 0x06, 0x06, EOS };
    u8 gotoLine2[] = { CHAR_NEWLINE, EXT_CTRL_CODE_BEGIN, 0x0E, 0x02, EOS };

    dest = StringCopy(dest, setBrailleFont);

    for (;;)
    {
        u8 c = *src++;

        switch (c)
        {
            case EOS:
                *dest = c;
                return dest;
            case CHAR_NEWLINE:
                dest = StringCopy(dest, gotoLine2);
                break;
            default:
                *dest++ = c;
                *dest++ = c + 0x40;
                break;
        }
    }
}

u8* CompileYesNoString()
{
    u8 errCode = 0xA1;
    u8 *dest = gYesNoStringVar;
    
    // Sanity check: ensure the default strings are set
    if (gYesString == NULL) gYesString = gYN_DefaultYes;
    if (gNoString == NULL) gNoString = gYN_DefaultNo;
    
    // Sanity check: ensure the yes/no strings are pointing into the ROM
    if (gYesString < (const u8*)&Start || gNoString < (const u8*)&Start) {
        errCode += 1;
        goto error;
    }
    
    dest = StringExpandPlaceholders(dest, gYesString);
    *dest++ = CHAR_NEWLINE; //replace EOS with new line
    if (dest >= (u8*)&gYesString) 
    {   // Ran past the end of the string!
        errCode += 4;
        goto error;
    }
    dest = StringExpandPlaceholders(dest, gNoString);
    *dest++ = EOS; //ensure EOS
    if (dest >= (u8*)&gYesString) 
    {   // Ran past the end of the string!
        errCode += 5;
        goto error;
    }
    
    // Reset yes/no strings
    gYesString = gYN_DefaultYes;
    gNoString = gYN_DefaultNo;
    return gYesNoStringVar;

error:
    dest = StringExpandPlaceholders(gYesNoStringVar, gYN_ERROR);
    *dest++ = errCode;
    *dest++ = EOS;
    gYesNoStringVar[0x1F] = EOS;
#if !DEBUG //In debug mode, leave these as they are so we can debug
    gYesString = gYN_DefaultYes;
    gNoString = gYN_DefaultNo;
#endif
    return gYesNoStringVar;
}

// Placeholder Expansions woo!

static const u8 *ExpandPlaceholder_YesNoStringVar(void)
{
    return gYesNoStringVar;
}

static const u8 *ExpandPlaceholder_PlayerName(void)
{
    return gSaveBlock2Ptr->playerName;
}

static const u8 *ExpandPlaceholder_PlayerNameStutter(void)
{
    gStringWorking[0] = gSaveBlock2Ptr->playerName[0];
    gStringWorking[1] = 0xAE; //dash character
    StringCopy7(&gStringWorking[2], gSaveBlock2Ptr->playerName);
    return gStringWorking;
}

static const u8 *ExpandPlaceholder_StringVar1(void)
{
    return gStringVar1;
}

static const u8 *ExpandPlaceholder_StringVar2(void)
{
    return gStringVar2;
}

static const u8 *ExpandPlaceholder_StringVar3(void)
{
    return gStringVar3;
}

extern const u8 gExpandedPlaceholder_Brendan[];
extern const u8 gExpandedPlaceholder_May[];
static const u8 *ExpandPlaceholder_RivalBirch(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_May;
    else
        return gExpandedPlaceholder_Brendan;
}

extern const u8 gExpandedPlaceholder_Logan[];
static const u8 *ExpandPlaceholder_RivalHero(void)
{
    return gExpandedPlaceholder_Logan;
}

extern const u8 gExpandedPlaceholder_Alex[];
static const u8 *ExpandPlaceholder_RivalAlola(void)
{
    return gExpandedPlaceholder_Alex;
}

extern const u8 gExpandedPlaceholder_Bailey[];
static const u8 *ExpandPlaceholder_AquaBoy(void)
{
    return gExpandedPlaceholder_Bailey;
}

extern const u8 gExpandedPlaceholder_Jessica[];
static const u8 *ExpandPlaceholder_AquaGirl(void)
{
    return gExpandedPlaceholder_Jessica;
}

extern const u8 gExpandedPlaceholder_HeUppercase[];
extern const u8 gExpandedPlaceholder_SheUppercase[];
extern const u8 gExpandedPlaceholder_HimUppercase[];
extern const u8 gExpandedPlaceholder_HerUppercase[];
extern const u8 gExpandedPlaceholder_HisUppercase[];
extern const u8 gExpandedPlaceholder_HersUppercase[];

static const u8 *ExpandPlaceholder_PlayerTheyUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HeUppercase;
    else
        return gExpandedPlaceholder_SheUppercase;
}

static const u8 *ExpandPlaceholder_PlayerThemUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HimUppercase;
    else
        return gExpandedPlaceholder_HerUppercase;
}

static const u8 *ExpandPlaceholder_PlayerTheirUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HisUppercase;
    else
        return gExpandedPlaceholder_HerUppercase;
}

static const u8 *ExpandPlaceholder_PlayerTheirsUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HisUppercase;
    else
        return gExpandedPlaceholder_HersUppercase;
}

static const u8 *ExpandPlaceholder_RivalTheyUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_SheUppercase;
    else
        return gExpandedPlaceholder_HeUppercase;
}

static const u8 *ExpandPlaceholder_RivalThemUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HerUppercase;
    else
        return gExpandedPlaceholder_HimUppercase;
}

static const u8 *ExpandPlaceholder_RivalTheirUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HerUppercase;
    else
        return gExpandedPlaceholder_HisUppercase;
}

static const u8 *ExpandPlaceholder_RivalTheirsUpper(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HersUppercase;
    else
        return gExpandedPlaceholder_HisUppercase;
}

extern const u8 gExpandedPlaceholder_HeLowercase[];
extern const u8 gExpandedPlaceholder_SheLowercase[];
extern const u8 gExpandedPlaceholder_HimLowercase[];
extern const u8 gExpandedPlaceholder_HerLowercase[];
extern const u8 gExpandedPlaceholder_HisLowercase[];
extern const u8 gExpandedPlaceholder_HersLowercase[];

static const u8 *ExpandPlaceholder_PlayerTheyLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HeLowercase;
    else
        return gExpandedPlaceholder_SheLowercase;
}

static const u8 *ExpandPlaceholder_PlayerThemLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HimLowercase;
    else
        return gExpandedPlaceholder_HerLowercase;
}

static const u8 *ExpandPlaceholder_PlayerTheirLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HisLowercase;
    else
        return gExpandedPlaceholder_HerLowercase;
}

static const u8 *ExpandPlaceholder_PlayerTheirsLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HisLowercase;
    else
        return gExpandedPlaceholder_HersLowercase;
}

static const u8 *ExpandPlaceholder_RivalTheyLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_SheLowercase;
    else
        return gExpandedPlaceholder_HeLowercase;
}

static const u8 *ExpandPlaceholder_RivalThemLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HerLowercase;
    else
        return gExpandedPlaceholder_HimLowercase;
}

static const u8 *ExpandPlaceholder_RivalTheirLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HerLowercase;
    else
        return gExpandedPlaceholder_HisLowercase;
}

static const u8 *ExpandPlaceholder_RivalTheirsLower(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_HersLowercase;
    else
        return gExpandedPlaceholder_HisLowercase;
}

extern const u8 gExpandedPlaceholder_Sir[];
extern const u8 gExpandedPlaceholder_Miss[];
static const u8 *ExpandPlaceholder_SirMiss(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Sir;
    else
        return gExpandedPlaceholder_Miss;
}

extern const u8 gExpandedPlaceholder_Boy[];
extern const u8 gExpandedPlaceholder_Girl[];
static const u8 *ExpandPlaceholder_BoyGirl(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Boy;
    else
        return gExpandedPlaceholder_Girl;
}

static const u8 *ExpandPlaceholder_RivalBoyGirl(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Girl;
    else
        return gExpandedPlaceholder_Boy;
}

extern const u8 gExpandedPlaceholder_Dude[];
extern const u8 gExpandedPlaceholder_Gurl[];
static const u8 *ExpandPlaceholder_DudeGurl(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Dude;
    else
        return gExpandedPlaceholder_Gurl;
}

extern const u8 gExpandedPlaceholder_Man[];
extern const u8 gExpandedPlaceholder_Lady[];
static const u8 *ExpandPlaceholder_ManLady(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Man;
    else
        return gExpandedPlaceholder_Lady;
}

extern const u8 gExpandedPlaceholder_Guy[];
extern const u8 gExpandedPlaceholder_Girl[];
static const u8 *ExpandPlaceholder_GuyGirl(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Guy;
    else
        return gExpandedPlaceholder_Girl;
}

extern const u8 gExpandedPlaceholder_Buddy[];
extern const u8 gExpandedPlaceholder_Honey[];
static const u8 *ExpandPlaceholder_BuddyHoney(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Buddy;
    else
        return gExpandedPlaceholder_Honey;
}

extern const u8 gExpandedPlaceholder_Bro[];
extern const u8 gExpandedPlaceholder_Sis[];
static const u8 *ExpandPlaceholder_BroSis(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Bro;
    else
        return gExpandedPlaceholder_Sis;
}

extern const u8 gExpandedPlaceholder_Son[];
extern const u8 gExpandedPlaceholder_Daughter[];
static const u8 *ExpandPlaceholder_SonDaughter(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Son;
    else
        return gExpandedPlaceholder_Daughter;
}
static const u8 *ExpandPlaceholder_RivalSonDaughter(void)
{
    if (GetPlayerGender() == MALE)
        return gExpandedPlaceholder_Daughter;
    else
        return gExpandedPlaceholder_Son;
}

extern const u8 gExpandedPlaceholder_Morning[];
extern const u8 gExpandedPlaceholder_Afternoon[];
extern const u8 gExpandedPlaceholder_Evening[];
extern const u8 gExpandedPlaceholder_Night[];
static const u8 *ExpandPlaceholder_TimeOfDay(void)
{
    RtcCalcLocalTime();
    if (gLocalTime.hours < 12) {
        return gExpandedPlaceholder_Morning;
    } else if (gLocalTime.hours < 19) {
        return gExpandedPlaceholder_Afternoon;
    } else {
        return gExpandedPlaceholder_Evening;
    }
    return gExpandedPlaceholder_Night;
}


extern const u8 gExpandedPlaceholder_Empty[];
static const u8 *ExpandPlaceholder_Invalid(void)
{
    return gExpandedPlaceholder_Empty;
}

const u8 *GetExpandedPlaceholder(u32 id)
{
    typedef const u8 *(*ExpandPlaceholderFunc)(void);

    static const ExpandPlaceholderFunc funcs[] =
    {
        ExpandPlaceholder_Invalid, // 00
        ExpandPlaceholder_PlayerName, // 01
        ExpandPlaceholder_StringVar1,
        ExpandPlaceholder_StringVar2,
        ExpandPlaceholder_StringVar3,
        ExpandPlaceholder_RivalBirch, // 05
        ExpandPlaceholder_RivalHero,
        ExpandPlaceholder_RivalAlola, 
        ExpandPlaceholder_AquaBoy, 
        ExpandPlaceholder_AquaGirl, // 09
        ExpandPlaceholder_Invalid, // 0A
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_PlayerNameStutter, // 0F
        
        ExpandPlaceholder_PlayerTheyUpper, // 10
        ExpandPlaceholder_PlayerThemUpper,
        ExpandPlaceholder_PlayerTheirUpper,
        ExpandPlaceholder_PlayerTheirsUpper,
        ExpandPlaceholder_PlayerTheyLower, // 14
        ExpandPlaceholder_PlayerThemLower,
        ExpandPlaceholder_PlayerTheirLower,
        ExpandPlaceholder_PlayerTheirsLower,
        ExpandPlaceholder_SonDaughter, // 18
        ExpandPlaceholder_SirMiss, // 19
        ExpandPlaceholder_BoyGirl, 
        ExpandPlaceholder_DudeGurl, 
        ExpandPlaceholder_ManLady,
        ExpandPlaceholder_GuyGirl,
        ExpandPlaceholder_BuddyHoney,
        ExpandPlaceholder_BroSis, // 1F
        
        ExpandPlaceholder_RivalTheyUpper, // 20
        ExpandPlaceholder_RivalThemUpper,
        ExpandPlaceholder_RivalTheirUpper,
        ExpandPlaceholder_RivalTheirsUpper,
        ExpandPlaceholder_RivalTheyLower, // 24
        ExpandPlaceholder_RivalThemLower,
        ExpandPlaceholder_RivalTheirLower,
        ExpandPlaceholder_RivalTheirsLower,
        ExpandPlaceholder_RivalSonDaughter, // 28
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_RivalBoyGirl, 
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid,
        ExpandPlaceholder_Invalid, // 2F
        
        ExpandPlaceholder_TimeOfDay, //30
    };

    if (id >= ARRAY_COUNT(funcs))
        return gExpandedPlaceholder_Empty;
    else
        return funcs[id]();
}

u8 *StringFill(u8 *dest, u8 c, u16 n)
{
    u16 i;

    for (i = 0; i < n; i++)
        *dest++ = c;

    *dest = EOS;
    return dest;
}

u8 *StringCopyPadded(u8 *dest, const u8 *src, u8 c, u16 n)
{
    while (*src != EOS)
    {
        *dest++ = *src++;

        if (n)
            n--;
    }

    n--;

    while (n != (u16)-1)
    {
        *dest++ = c;
        n--;
    }

    *dest = EOS;
    return dest;
}

u8 *StringFillWithTerminator(u8 *dest, u16 n)
{
    return StringFill(dest, EOS, n);
}

u8 *StringCopyN_Multibyte(u8 *dest, u8 *src, u32 n)
{
    u32 i;

    for (i = n - 1; i != (u32)-1; i--)
    {
        if (*src == EOS)
        {
            break;
        }
        else
        {
            *dest++ = *src++;
            if (*(src - 1) == CHAR_SPECIAL_F9)
                *dest++ = *src++;
        }
    }

    *dest = EOS;
    return dest;
}

u32 StringLength_Multibyte(const u8 *str)
{
    u32 length = 0;

    while (*str != EOS)
    {
        if (*str == CHAR_SPECIAL_F9)
            str++;
        str++;
        length++;
    }

    return length;
}

u8 *WriteColorChangeControlCode(u8 *dest, u32 colorType, u8 color)
{
    *dest = EXT_CTRL_CODE_BEGIN;
    dest++;

    switch (colorType)
    {
    case 0:
        *dest = 1;
        dest++;
        break;
    case 1:
        *dest = 3;
        dest++;
        break;
    case 2:
        *dest = 2;
        dest++;
        break;
    }

    *dest = color;
    dest++;
    *dest = EOS;
    return dest;
}

bool32 IsStringJapanese(u8 *str)
{
    while (*str != EOS)
    {
        if (*str <= 0xA0)
            if (*str != CHAR_SPACE)
                return TRUE;
        str++;
    }

    return FALSE;
}

bool32 sub_800924C(u8 *str, s32 n)
{
    s32 i;

    for (i = 0; *str != EOS && i < n; i++)
    {
        if (*str <= 0xA0)
            if (*str != CHAR_SPACE)
                return TRUE;
        str++;
    }

    return FALSE;
}

u8 GetExtCtrlCodeLength(u8 code)
{
    static const u8 lengths[] =
    {
        [0x00]                    = 1,
        [EXT_CTRL_CODE_COLOR]     = 2,
        [EXT_CTRL_CODE_HIGHLIGHT] = 2,
        [EXT_CTRL_CODE_SHADOW]    = 2,
        [0x04]                    = 4,
        [0x05]                    = 2,
        [0x06]                    = 2,
        [EXT_CTRL_CODE_UNKNOWN_7] = 1,
        [0x08]                    = 2,
        [0x09]                    = 1,
        [0x0A]                    = 1,
        [0x0B]                    = 3,
        [0x0C]                    = 2,
        [0x0D]                    = 2,
        [0x0E]                    = 2,
        [0x0F]                    = 1,
        [0x10]                    = 3,
        [EXT_CTRL_CODE_CLEAR]     = 2,
        [0x12]                    = 2,
        [EXT_CTRL_CODE_CLEAR_TO]  = 2,
        [0x14]                    = 2,
        [EXT_CTRL_CODE_JPN]       = 1,
        [EXT_CTRL_CODE_ENG]       = 1,
        [0x17]                    = 1,
        [0x18]                    = 1,
        [0x19]                    = 1,
        [0x1A]                    = 1,
        [0x1B]                    = 1,
        [0x1C]                    = 2,
    };

    u8 length = 0;
    if (code < ARRAY_COUNT(lengths))
        length = lengths[code];
    return length;
}

static const u8 *SkipExtCtrlCode(const u8 *s)
{
    while (*s == EXT_CTRL_CODE_BEGIN)
    {
        s++;
        s += GetExtCtrlCodeLength(*s);
    }

    return s;
}

s32 StringCompareWithoutExtCtrlCodes(const u8 *str1, const u8 *str2)
{
    s32 retVal = 0;

    while (1)
    {
        str1 = SkipExtCtrlCode(str1);
        str2 = SkipExtCtrlCode(str2);

        if (*str1 > *str2)
            break;

        if (*str1 < *str2)
        {
            retVal = -1;
            if (*str2 == EOS)
                retVal = 1;
        }

        if (*str1 == EOS)
            return retVal;

        str1++;
        str2++;
    }

    retVal = 1;

    if (*str1 == EOS)
        retVal = -1;

    return retVal;
}

void ConvertInternationalString(u8 *s, u8 language)
{
    if (language == LANGUAGE_JAPANESE)
    {
        u8 i;

        StripExtCtrlCodes(s);
        i = StringLength(s);
        s[i++] = EXT_CTRL_CODE_BEGIN;
        s[i++] = 22;
        s[i++] = EOS;

        i--;

        while (i != (u8)-1)
        {
            s[i + 2] = s[i];
            i--;
        }

        s[0] = EXT_CTRL_CODE_BEGIN;
        s[1] = 21;
    }
}

void StripExtCtrlCodes(u8 *str)
{
    u16 srcIndex = 0;
    u16 destIndex = 0;
    while (str[srcIndex] != EOS)
    {
        if (str[srcIndex] == EXT_CTRL_CODE_BEGIN)
        {
            srcIndex++;
            srcIndex += GetExtCtrlCodeLength(str[srcIndex]);
        }
        else
        {
            str[destIndex++] = str[srcIndex++];
        }
    }
    str[destIndex] = EOS;
}
