/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "StdInc.h"

CSprite2d* CFont::Sprite = (CSprite2d*)0xC71AD0;
CSprite2d* CFont::PS2Sprite = (CSprite2d*)0xC71AD8;
unsigned char& CFont::PS2Symbol = *(unsigned char*)0xC71A54;
bool& CFont::m_bNewLine = *(bool*)0xC71A55;
CRGBA& CFont::m_Color = *(CRGBA*)0xC71A60;
CVector2D* CFont::m_Scale = (CVector2D*)0xC71A64;
float& CFont::m_fSlant = *(float*)0xC71A6C;
CVector2D& CFont::m_fSlantRefPoint = *(CVector2D*)0xC71A70;
bool& CFont::m_bFontJustify = *(bool*)0xC71A78;
bool& CFont::m_bFontCentreAlign = *(bool*)0xC71A79;
bool& CFont::m_bFontRightAlign = *(bool*)0xC71A7A;
bool& CFont::m_bFontBackground = *(bool*)0xC71A7B;
bool& CFont::m_bEnlargeBackgroundBox = *(bool*)0xC71A7C;
bool& CFont::m_bFontPropOn = *(bool*)0xC71A7D;
bool& CFont::m_bFontIsBlip = *(bool*)0xC71A7E;
unsigned int CFont::m_dwFontAlpha = *(unsigned int*)0xC71A80;
CRGBA& CFont::m_FontBackgroundColor = *(CRGBA*)0xC71A84;
float& CFont::m_fWrapx = *(float*)0xC71A88;
float& CFont::m_fFontCentreSize = *(float*)0xC71A8C;
float& CFont::m_fRightJustifyWrap = *(float*)0xC71A90;
unsigned char& CFont::m_FontTextureId = *(unsigned char*)0xC71A94;
unsigned char& CFont::m_FontStyle = *(unsigned char*)0xC71A95;
unsigned char& CFont::m_nFontShadow = *(unsigned char*)0xC71A96;
CRGBA& CFont::m_FontDropColor = *(CRGBA*)0xC71A97;
unsigned char& CFont::m_nFontOutlineSize = *(unsigned char*)0xC71A9B;
unsigned char& CFont::m_nFontOutline = *(unsigned char*)0xC71A9C;
CFontDetails& CFont::RenderState = *(CFontDetails*)0xC71AA0;
CFontDetails*& CFont::pEmptyChar = *(CFontDetails**)0xC716A8;
CFontDetails& CFont::setup = *(CFontDetails*)0xC716B0;

tFontData* CFont::gFontData = (tFontData*)0xC718B0;


void CFont::InjectHooks()
{
    HookInstall(0x5BA690, &CFont::Initialise, 7);
    HookInstall(0x7189B0, &CFont::Shutdown, 7);
    HookInstall(0x719420, &CFont::SetSlant, 7);
    HookInstall(0x719400, &CFont::SetSlantRefPoint, 7);
    HookInstall(0x719430, &CFont::SetColor, 7);
    HookInstall(0x7194D0, &CFont::SetWrapx, 7);
    HookInstall(0x7194E0, &CFont::SetCentreSize, 7);
    HookInstall(0x719380, &CFont::SetScale, 7);
    HookInstall(0x7193A0, &CFont::SetScaleForCurrentlanguage, 7);
    HookInstall(0x7194F0, &CFont::SetRightJustifyWrap, 7);
    HookInstall(0x719500, &CFont::SetAlphaFade, 7);
    HookInstall(0x719510, &CFont::SetDropColor, 7);
    HookInstall(0x719570, &CFont::SetDropShadowPosition, 7);
    HookInstall(0x719590, &CFont::SetEdge, 7);
    HookInstall(0x7195B0, &CFont::SetProportional, 7);
    HookInstall(0x7195C0, &CFont::SetBackground, 7);
    HookInstall(0x7195E0, &CFont::SetBackgroundColor, 7);
    HookInstall(0x719600, &CFont::SetJustify, 7);
    HookInstall(0x719610, &CFont::SetAllignment, 7);
    HookInstall(0x719490, &CFont::SetFontStyle, 7);
    HookInstall(0x71A210, &CFont::DrawFonts, 7);
    //HookInstall(0x71A620, &CFont::GetTextRect, 7);
    HookInstall(0x719800, &CFont::InitPerFrame, 7);
    //HookInstall(0x71A820, &CFont::PrintStringFromBottom, 7);
    //HookInstall(0x71A600, &CFont::ProcessStringToDisplay, 7);
    //HookInstall(0x71A700, (void(*)(float, float, char*))&CFont::PrintString, 7);
    //HookInstall(0x719B40, (void(*)(float, float, char*, char*, float)) & CFont::PrintString, 7);
    //HookInstall(0x7187C0, &CFont::LoadFontValue, 7);
    //HookInstall(0x718770, &CFont::GetLetterIdPropValue, 7);
    //HookInstall(0x7192C0, &CFont::FindSubFontCharacter, 7);
    //HookInstall(0x718A10, &CFont::PrintChar, 7);
    //HookInstall(0x71A5E0, &CFont::GetNumberLines, 7);
    //HookInstall(0x71A0E0, &CFont::GetStringWidth, 7);
    //HookInstall(0x719750, &CFont::GetCharacterSize, 7);
    //HookInstall(0x719670, &CFont::SetCharacterOutline, 7);
    //HookInstall(0x718ED0, &CFont::GetNextSpace, 7);
    //HookInstall(0x718ED0, &CFont::ParseToken, 7);
    //HookInstall(0x719840, &CFont::RenderFontBuffer, 7);
    //HookInstall(0x71A220, &CFont::ProcessCurrentString, 7);
}

void CFont::Initialise()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x5BA690)();
#else
    int fontsTxdIdSlot = CTxdStore::AddTxdSlot("fonts");
    CTxdStore::LoadTxd(fontsTxdIdSlot, "MODELS\\FONTS.TXD");
    CTxdStore::AddRef(fontsTxdIdSlot);
    CTxdStore::PushCurrentTxd();
    CTxdStore::SetCurrentTxd(fontsTxdIdSlot);
    Sprite[SPRITE_FONT2].SetTexture("font2", "font2m");
    Sprite[SPRITE_FONT1].SetTexture("font1", "font1m");
    CFont::LoadFontValue();
    CFont::SetScale(1.0, 1.0);
    CFont::SetSlantRefPoint((float)RsGlobal.maximumWidth, 0.0);
    CFont::SetSlant(0.0);
    CRGBA fontColor = CRGBA(0xFFu, 0xFFu, 0xFFu, 0);
    SetColor(fontColor);
    SetAllignment(ALIGN_LEFT);
    SetJustify(false);
    SetWrapx((float)RsGlobal.maximumWidth);
    SetCentreSize((float)RsGlobal.maximumWidth);
    SetBackground(0, 0);
    CRGBA fontBackgroundColor = CRGBA(0x80u, 0x80u, 0x80u, 0x80u);
    SetBackgroundColor(fontBackgroundColor);
    SetProportional(true);
    SetFontStyle(FONT_GOTHIC);
    SetRightJustifyWrap(0.0);
    SetAlphaFade(255.0);
    SetDropShadowPosition(0);
    CTxdStore::PopCurrentTxd();
    int ps2buttonsTxdIdSlot = CTxdStore::AddTxdSlot("ps2btns");
    CTxdStore::LoadTxd(ps2buttonsTxdIdSlot, "MODELS\\PCBTNS.TXD");
    CTxdStore::AddRef(ps2buttonsTxdIdSlot);
    CTxdStore::PushCurrentTxd();
    CTxdStore::SetCurrentTxd(ps2buttonsTxdIdSlot);
    CSprite2d::PS2Sprite[0].SetTexture("up", "upA");
    CSprite2d::PS2Sprite[1].SetTexture("down", "downA");
    CSprite2d::PS2Sprite[2].SetTexture("left", "leftA");
    CSprite2d::PS2Sprite[3].SetTexture("right", "rightA");
    CTxdStore::PopCurrentTxd();
#endif
}

void CFont::Shutdown()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x7189B0)();
#else
    Sprite[SPRITE_FONT2].Delete();
    Sprite[SPRITE_FONT1].Delete();
    int fontsTxdIdSlot = CTxdStore::FindTxdSlot("fonts");
    CTxdStore::RemoveTxdSlot(fontsTxdIdSlot);
    for (int i = 0; i < 4; i++)
    {
        CSprite2d::PS2Sprite[i].Delete();
    }
    int ps2buttonsTxdIdSlot = CTxdStore::FindTxdSlot("ps2btns");
    CTxdStore::RemoveTxdSlot(ps2buttonsTxdIdSlot);
#endif
}

#define USE_DEFAULT_FUNCTIONS

void CFont::PrintChar(float x, float y, char character)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, char))0x718A10)(x, y, character);
#else
    if (y >= 0.0 && RsGlobal.maximumHeight >= y && x >= 0.0 && RsGlobal.maximumWidth >= x)
    {
        CRect rect;

        if (PS2Symbol)
        {
            rect.left = x;
            rect.top = RenderState.m_fHeigth +RenderState.m_fHeigth + y;
            rect.right = RenderState.m_fHeigth * 17.0f + x;
            rect.bottom = RenderState.m_fHeigth * 19.0f + y;
            CRGBA fontColor = CRGBA(255u, 255u, 255u, RenderState.m_color.alpha);
            PS2Sprite[PS2Symbol].Draw(rect, fontColor);
        }
        else
        {
            bool isLetter = false;
            if (!character || character == '?')
            {
                isLetter = true;
                character = 0;
            }
            float letterIdPropValue = GetLetterIdPropValue(character) / 32;
            if (RenderState.m_nFontStyle == FONT_SUBTITLES && character == 0xD0u)
                character = 0;
            const float xRatio = 1.0f / 16.0f;
            const float yRatio = 1.0f / 12.8f;
            const float widthOffset = 1.0f / 10000.0f;
            float u1 = static_cast<float>(character & 0xF) * xRatio;
            if (RenderState.m_wFontTexture && RenderState.m_wFontTexture != 1)
            {
                if (!isLetter)
                {
                    float v1 = (character >> 4) / 16.0f;
                    rect.top = y;
                    rect.left = x;
                    rect.right = RenderState.m_fWidth * 32.0f * letterIdPropValue + x;
                    rect.bottom = RenderState.m_fHeigth * 32.0f * 0.5f + y;
                    float v3 = v1 + xRatio;
                    float u2 = letterIdPropValue / 16 + u1;
                    float v4 = v3 - widthOffset;
                    float u4 = u2 - widthOffset;
                    float v2 = v1;
                    CSprite2d::AddToBuffer(rect, RenderState.m_color, u1, v1, u2, v2, u1, v3, u4, v4);
                }
            }
            else
            {
                if (!isLetter)
                {
                    float characterRatio = (character >> 4) * 0.078125f;
                    rect.left = x;
                    if (RenderState.m_fSlant == 0.0f)
                    {
                        rect.top = y;
                        rect.right = RenderState.m_fWidth * 32.0f + x;
                        if (character < 192)
                        {
                            rect.bottom = RenderState.m_fHeigth * 40.0f * 0.5f + y;
                            float v3 = characterRatio + yRatio - 0.0021f;
                            float u2 = u1 + xRatio - (widthOffset * 10.0f);
                            float v1 = characterRatio + 0.0021f;
                            float v2 = v1;
                            float u3 = u1;
                            float u4 = y;
                            float v4 = v3;
                            CSprite2d::AddToBuffer(rect, RenderState.m_color, u1, v1, u2, v2, u3, v3, u4, v4);
                        }
                        else
                        {
                            rect.bottom = RenderState.m_fHeigth * 32.0f * 0.5f + y;
                            float offset = characterRatio + yRatio;
                            float u2 = u1 + xRatio - (widthOffset * 10.0f);
                            float v1 = characterRatio + 0.0021f;
                            float v4 = offset - 0.015f;
                            float v3 = offset - 0.016f;
                            float v2 = v1;
                            float u4 = y;
                            float u3 = u2;
                            CSprite2d::AddToBuffer(rect, RenderState.m_color, u1, v1, u2 , v2, u3, v3, u4, v4);
                        }
                    }
                    else
                    {
                        rect.top = y + 0.015f;
                        rect.right = RenderState.m_fWidth * 32.0f + x;
                        rect.bottom = RenderState.m_fHeigth * 40.0f * 0.5f + y + 0.015f;
                        float offset = characterRatio + yRatio;
                        float u2 = u1 + xRatio - 0.001f;
                        float v4 = offset - 0.0021f + (widthOffset * 100.0f);
                        float v3 = offset - 0.009f;
                        float v2 = characterRatio + 0.0121f;
                        float v1 = characterRatio + 0.00055f;
                        float u3 = u1;
                        float u4 = y;
                        CSprite2d::AddToBuffer(rect, RenderState.m_color, u1, v1, u2, v2, u3, v3, u4, v4);
                    }
                }
            }
        }
    }
#endif
}

char* __cdecl CFont::GetNextSpace(char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((char* (__cdecl*)(char*))0x718ED0)(text);
#else
    while (*text) {
        if (*text == ' ')
            break;
        if (*text == '\0')
            break;
        if (*text == '~')
            break;
        ++text;
    }
    return text;
#endif
}

char* CFont::ParseToken(char* text, CRGBA& colour, bool disableColor, char* colorCode)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((char* (__cdecl*)(char*, CRGBA&, bool, char*))0x718ED0)(text, colour, disableColor, colorCode);
#else
    char nbColor;

    switch (text[1]) {
        // symbols

    case 'N':
    case 'n':
        m_bNewLine = true;
        break;
    case 'U':
    case 'u':
        PS2Symbol = PS2_UP; // 1
        break;
    case 'D':
    case 'd':
        PS2Symbol = PS2_DOWN;  // 2
        break;
    case '<':
        PS2Symbol = PS2_LEFT;  // 3
        break;
    case '>':
        PS2Symbol = PS2_RIGHT; // 4
        break;
    case 'x':
    case 'X':
        PS2Symbol = PS2_CROSS; // 5
        break;
    case 'o':
    case 'O':
        PS2Symbol = PS2_CIRCLE; // 6
        break;
    case 'q':
    case 'Q':
        PS2Symbol = PS2_SQUARE; // 7
        break;
    case 'T':
    case 't':
        PS2Symbol = PS2_TRIANGLE; // 8
        break;
    case 'K':
    case 'k':
        PS2Symbol = PS2_L1;
        break;
    case 'M':
    case 'm':
        PS2Symbol = PS2_L2;
        break;
    case 'A':
    case 'a':
        PS2Symbol = PS2_L3;
        break;
    case 'J':
    case 'j':
        PS2Symbol = PS2_R1;
        break;
    case 'v':
    case 'V':
        PS2Symbol = PS2_R2;
        break;
    case 'C':
    case 'c':
        PS2Symbol = PS2_R3;
        break;

        // colors

    case 'B':
    case 'b':
        nbColor = TEXT_COLOUR_BLUE;
        break;
    case 'G':
    case 'g':
        nbColor = TEXT_COLOUR_GREEN;
        break;
    case 'l':
        nbColor = TEXT_COLOUR_BLACK;
        break;
    case 'p':
    case 'P':
        nbColor = TEXT_COLOUR_PURPLE;
        break;
    case 'r':
    case 'R':
        nbColor = TEXT_COLOUR_RED;
        break;
    case 's':
    case 'S':
        nbColor = TEXT_COLOUR_WHITE;
        break;
    case 'w':
    case 'W':
        nbColor = TEXT_COLOUR_WHITE;
        break;
    case 'y':
    case 'Y':
        nbColor = TEXT_COLOUR_YELLOW;
        break;

    case '=':
    case '?':
    case '@':
    case 'E':
    case 'F':
    case 'I':
    case 'L':
    case 'Z':
    case '[':
    case '\\':
    case ']':
    case '^':
    case '_':
    case '`':
    case 'e':
    case 'f':
    case 'i':
        break;
    default:
        assert("Unknown GXT token given: ~%c~", text[1]);
        break;
    }

    if (PS2Symbol != PS2_NONE) {
        assert(PS2Symbol < PS2_SPRITE_COUNT);
        assert(PS2Sprite[PS2Symbol].IsTextureLoaded(), "Symbol %d for GXT token ~%c~ is not loaded", PS2Symbol, text[1]);
    }

    if (nbColor != -1) {
        if (!disableColor) {
            colour = HudColour.GetRGB(nbColor, colour.a);
        }
        if (colorCode) {
            *colorCode = text[1];
        }
    }

    do {
        ++text;
    } while (*text && *text != '~');
    return text + 1;
#endif
}

#undef USE_DEFAULT_FUNCTIONS

void CFont::SetScale(float w, float h)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float))0x719380)(w, h);
#else
    m_Scale->x = w;
    m_Scale->y = h;
#endif
}

void CFont::SetScaleForCurrentlanguage(float w, float h)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float))0x7193A0)(w, h);
#else
    switch (FrontEndMenuManager.m_nLanguage)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        m_Scale->y = h;
        m_Scale->x = w * 0.80000001f;
        break;
    default:
        m_Scale->x = w;
        m_Scale->y = h;
        break;
    }
#endif
}

void CFont::SetSlantRefPoint(float x, float y)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float))0x719400)(x, y);
#else
    m_fSlantRefPoint.x = x;
    m_fSlantRefPoint.y = y;
#endif
}

void CFont::SetSlant(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x719420)(value);
#else
    m_fSlant = value;
#endif
}

void CFont::SetColor(CRGBA color)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRGBA))0x719430)(color);
#else
    m_Color = color;
    if (m_dwFontAlpha < 255)
        m_Color.a = color.a * m_dwFontAlpha / 255;
#endif
}

void CFont::SetFontStyle(short style)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(short))0x719490)(style);
#else
    if (style == 2)
    {
        m_FontTextureId = 0;
        m_FontStyle = 2;
    }
    else if (style == 3)
    {
        m_FontTextureId = 1;
        m_FontStyle = 1;
    }
    else
    {
        m_FontTextureId = (unsigned char)style;
        m_FontStyle = 0;
    }
#endif
}

void CFont::SetWrapx(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x7194D0)(value);
#else
    m_fWrapx = value;
#endif
}

void CFont::SetCentreSize(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x7194E0)(value);
#else
    m_fFontCentreSize = value;
#endif
}

void CFont::SetRightJustifyWrap(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x7194F0)(value);
#else
    m_fRightJustifyWrap = value;
#endif
}

void CFont::SetAlphaFade(float alpha)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x719500)(alpha);
#else
    m_dwFontAlpha = (unsigned int)alpha;
#endif
}

void CFont::SetDropColor(CRGBA color)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRGBA))0x719510)(color);
#else
    m_FontDropColor = color;
    if (m_dwFontAlpha < 255)
        m_FontDropColor.a = color.a * m_dwFontAlpha / 255; //(m_Color->a * m_dwFontAlpha * (unsigned char)0.0039215689);
#endif
}

void CFont::SetDropShadowPosition(short value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(short))0x719570)(value);
#else
    m_nFontOutlineSize = 0;
    m_nFontOutline = 0;
    m_nFontShadow = (unsigned char)value;
#endif
}

void CFont::SetEdge(short value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(short))0x719590)(value);
#else
    m_nFontOutlineSize = (unsigned char)value;
    m_nFontOutline = (unsigned char)value;
    m_nFontShadow = 0;
#endif
}

void CFont::SetProportional(bool on)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(bool))0x7195B0)(on);
#else
    m_bFontPropOn = on;
#endif
}

void CFont::SetBackground(bool enable, bool includeWrap)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(bool, bool))0x7195C0)(enable, includeWrap);
#else
    m_bFontBackground = enable;
    m_bEnlargeBackgroundBox = includeWrap;
#endif
}

void CFont::SetBackgroundColor(CRGBA color)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRGBA))0x7195E0)(color);
#else
    m_FontBackgroundColor = color;
#endif
}

void CFont::SetJustify(bool on)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(bool))0x719600)(on);
#else
    m_bFontJustify = on;
#endif
}

void CFont::SetAllignment(eFontAlignment alignment)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(eFontAlignment))0x719610)(alignment);
#else
    if (alignment)
    {
        if (alignment == ALIGN_LEFT)
        {
            m_bFontCentreAlign = 0;
            m_bFontRightAlign = 0;
        }
        else if (alignment == ALIGN_RIGHT)
        {
            m_bFontCentreAlign = 0;
            m_bFontRightAlign = 1;
        }
    }
    else
    {
        m_bFontCentreAlign = 1;
        m_bFontRightAlign = 0;
    }
#endif
}

void CFont::InitPerFrame()
{
#ifdef USE_DEFAULT_FUNCTIONS
  ((void(__cdecl*)())0x719800)();
#else
    m_nFontOutlineSize = 0;
    m_nFontOutline = 0;
    m_nFontShadow = 0;
    m_bNewLine = 0;
    PS2Symbol = 0;
    RenderState.m_wFontTexture = -1;
    pEmptyChar = &setup;
    CSprite::InitSpriteBuffer();
#endif
}

#define USE_DEFAULT_FUNCTIONS

float CFont::GetStringWidth(char* str, bool bFull, bool bScriptText)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((float(__cdecl*)(char*, bool, bool))0x71A0E0)(str, bFull, bScriptText);
#else
    char string[400]; 
    memset(string, 0, 400);
    float width = 0.0;
    bool bLastWasTag = 0;
    bool bLastWasLetter = 0;
    int stringLength = CMessages::GetStringLength(str); // ?
    int i = 0;
    for (i = 0; ; ++i)
    {
        if (stringLength > MAX_STRING_WIDTH - 1) {
            stringLength = MAX_STRING_WIDTH - 1;
        }
        if (i >= MAX_STRING_WIDTH - 1)
            break;
        string[i] = string[str - string + i];
    }
    string[i] = 0;
    CMessages::InsertPlayerControlKeysInString(string);
    char* curr = string;
    while (1)
    {
        char pCurr = *curr;
        if (*curr == ' ' && !bFull)
            break;
        if (!pCurr)
            break;
        if (pCurr == '~')
        {
            if (!bFull && (bLastWasTag || bLastWasLetter))
                return width;
            char tagSymbol = curr[1];
            char letter;
            char* j = curr + 1;
            if (tagSymbol != '~')
            {
                do
                    letter = (j++)[1];
                while (letter != '~');
            }
            curr = j + 1;
            if (bLastWasLetter || *curr == '~')
                bLastWasTag = 1;
        }
        else
        {
            if (!bFull && pCurr == ' ' && bLastWasTag)
                return width;
            char letterId = pCurr - 32;
            if (bScriptText)
            {
                ++curr;
                width = SetCharacterOutline(letterId) + width;
            }
            else
            {
                ++curr;
                width = GetCharacterSize(letterId) + width;
            }
            bLastWasLetter = 1;
        }
    }
    return width;
#endif
}

int CFont::GetCharacterSize(char letterId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((char(__cdecl*)(char))0x719750)(letterId);
#else
    unsigned __int8 letterIdPropValue;
    int result;

    letterIdPropValue = letterId;
    if (letterId == '?')
    {
        letterIdPropValue = 0;
        letterId = 0;
    }
    if (m_FontStyle)
    {
        letterIdPropValue = FindSubFontCharacter(letterId, m_FontStyle);
    }
    else if (letterIdPropValue == -111)
    {
        letterIdPropValue = 64;
    }
    else if (letterIdPropValue > 0x9Bu)
    {
        letterIdPropValue = 0;
    }
    if (m_bFontPropOn)
        result = gFontData[m_FontTextureId].m_propValues[letterIdPropValue];
    else
        result = gFontData[m_FontTextureId].m_unpropValue;
    return result;
#endif
}

double CFont::SetCharacterOutline(char letterId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((char(__cdecl*)(char))0x719670)(letterId);
#else
    char font = 0;
    char idForPropValue;
    float totalOutlineValue;

    char prevLetterId = letterId;
    if (letterId == 63)
    {
        prevLetterId = 0;
        letterId = 0;
    }
    char proportional = CTheScripts::IntroTextLines[CTheScripts::NumberOfIntroTextLinesThisFrame].proportional;
    float letterWidth = CTheScripts::IntroTextLines[CTheScripts::NumberOfIntroTextLinesThisFrame].letterWidth;
    char outlineType = CTheScripts::IntroTextLines[CTheScripts::NumberOfIntroTextLinesThisFrame].outlineType;
    if (CTheScripts::IntroTextLines[CTheScripts::NumberOfIntroTextLinesThisFrame].font == 2)
    {
        idForPropValue = FindSubFontCharacter(letterId, 2);
    }
    else if (CTheScripts::IntroTextLines[CTheScripts::NumberOfIntroTextLinesThisFrame].font == 3)
    {
        idForPropValue = FindSubFontCharacter(letterId, 1);
    }
    else
    {
        font = CTheScripts::IntroTextLines[CTheScripts::NumberOfIntroTextLinesThisFrame].font;
        idForPropValue = prevLetterId;
        if (prevLetterId == -111)
        {
            idForPropValue = 64;
        }
        else if (prevLetterId > 0x9Bu)
        {
            idForPropValue = 0;
        }
    }
    if (proportional)
        totalOutlineValue = gFontData[font].m_propValues[idForPropValue] + outlineType;
    else
        totalOutlineValue = gFontData[font].m_unpropValue + outlineType;
    return letterWidth * totalOutlineValue;
#endif
}

void CFont::RenderFontBuffer()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x719840)();
#else
    printf("CFont::RenderFontBuffer called.\n");
    CRGBA col;
    CVector2D pos;
    char outline;
    if (pEmptyChar->m_cLetter != setup.m_cLetter)
    {
        Sprite[RenderState.m_wFontTexture].SetRenderState();
        RwRenderStateSetFunction(rwRENDERSTATEVERTEXALPHAENABLE);
        RenderState = setup;
        col = RenderState.m_color;
        pos.x = RenderState.m_vPosn.x;
        pos.y = RenderState.m_vPosn.y;

        for (int i = setup.m_cLetter; i < pEmptyChar->m_cLetter; )
        {
            if (!i)
            {
                for (int j = (i + 1); j & 3; j = (j + 1)) {
                    if (j >= pEmptyChar->m_cLetter)
                        break;
                    i = j + 1;
                }

                for (PS2Symbol = 0; setup.m_cLetter == '~';) {
                    if (PS2Symbol)
                        break;
                    i = (int)ParseToken(&setup.m_cLetter, col, RenderState.m_bContainImages, 0);
                    if (!RenderState.m_bContainImages) {
                        RenderState.m_color.red = col.r;
                        RenderState.m_color.green = col.g;
                        RenderState.m_color.blue = col.b;
                        RenderState.m_color.alpha = col.a;
                    }
                }
            }

            char letterIndex = setup.m_cLetter - 32;
            if (RenderState.m_nFontStyle) {
                letterIndex = FindSubFontCharacter(letterIndex, RenderState.m_nFontStyle);
            }
            else {
                if (letterIndex == 0x91u) {
                    letterIndex = '@';
                }
                else if (letterIndex > 155u) {
                    letterIndex = 0;
                }
            }

            if (RenderState.m_fSlant != 0.0)
                pos.y = (RenderState.m_vSlanRefPoint.x - pos.x) * RenderState.m_fSlant + RenderState.m_vSlanRefPoint.y;

            if (!PS2Symbol || !RenderState.m_bContainImages) {
                PrintChar(pos.x, pos.y, letterIndex);
            }

            if (PS2Symbol) {
                outline = RenderState.m_nOutline;
                pos.x = RenderState.m_fHeigth * 17.0 + RenderState.m_nOutline + pos.x;
            }
            else {
                if (letterIndex == '?')
                    letterIndex = 0;
                if (RenderState.m_bPropOn == 1)
                    outline = gFontData[RenderState.m_wFontTexture].m_propValues[letterIndex];
                else
                    outline = gFontData[RenderState.m_wFontTexture].m_unpropValue;
                char _outline = outline;
                outline = RenderState.m_nOutline;
                pos.x = (RenderState.m_nOutline + _outline) * *&RenderState.m_fWidth + pos.x;
            }

            if (setup.m_cLetter) {
                if (PS2Symbol)
                    goto LABEL_39;
                i = i + 1;
            }
            else if (PS2Symbol) {
            LABEL_39:
                PS2Symbol = 0;
                Sprite[RenderState.m_wFontTexture].SetRenderState();
                continue;
            }
        }
        CSprite::FlushSpriteBuffer();
        CSprite2d::RenderVertexBuffer();
        pEmptyChar = &setup;
    }
#endif
}

#undef USE_DEFAULT_FUNCTIONS

void CFont::DrawFonts()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x71A210)();
#else
    RenderFontBuffer();
#endif
}

#define USE_DEFAULT_FUNCTIONS

short CFont::ProcessCurrentString(bool display, float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((short(__cdecl*)(bool, float, float, char*))0x71A220)(display, x, y, text);
#else
    short lines = 0;
    short spaces = 0;

    if (!text || !text[0]) {
        return lines;
    }

    CRGBA rgbaBackup = CFont::m_Color;

    char buffer[256] = { 0 };
    char* start = text;
    char* end = text;

    float rightX = 0.0f;
    float lastLineRightX = 0.0f;

    bool unknown = true;

    if (!(m_bFontCentreAlign || m_bFontRightAlign))
    {
        rightX = x;
    }

    CRGBA colour;
    char tag = false;

    while (*start) {
        CFont::PS2Symbol = 0;
        float wordWidth = CFont::GetStringWidth(end, WIDTH_FIRSTWORD, false);
        if (*end == '~') {
            end = CFont::ParseToken(end, colour, true, &tag);
        }

        float rightMaxX = 0.f;
        if (m_bFontCentreAlign)
            rightMaxX = m_fFontCentreSize;
        else if (m_bFontRightAlign)
            rightMaxX = x - m_fRightJustifyWrap;
        else
            rightMaxX = m_fWrapx;

        if ((rightX + wordWidth <= rightMaxX || unknown) && !CFont::m_bNewLine) {
            rightX += wordWidth;

            end = CFont::GetNextSpace(end);

            if (!end[0]) { // we have one word to render, okay
                float leftX;
                if (m_bFontCentreAlign)
                    leftX = x - rightX / 2.f;
                else if (m_bFontRightAlign)
                    leftX = x - rightX;
                else
                    leftX = x;

                ++lines;
                if (display) {
                    CFont::PrintString(leftX, y, start, end, 0.f);
                }
                printf("2014/12/17 [nick7]: is this bug present in original version or it's just mine?");
                // here's a little fix in cause we have trailing spaces, otherwise last line won't be rendered
                start = end;
                continue; // actually, it's break as loop will be ended
            }
            if (!unknown) {
                ++spaces;
            }

            // actually _pStrTo points to a one of space chars, so
            // we just add a space and skip this char
            if (*end != '~') {
                ++end;
                rightX += CFont::GetCharacterSize(CHAR_SPACE); // add space
            }
            lastLineRightX = rightX;
            unknown = false;
            continue;
        }

        if (PS2Symbol) {
            end -= 3; // ~?~
        }

        if (m_bNewLine) {
            end -= 3; // ~n~
        }

        float leftX = 0;
        float unknown = 0.f;

        if (m_bFontCentreAlign) {
            leftX = x - rightX / 2.f;
        }
        else if (m_bFontRightAlign) {
            leftX = x - (rightX - GetCharacterSize(0));
        }
        else {
            leftX = x;
        }

        if (!m_bFontCentreAlign && m_bFontJustify) {
            unknown = (m_fWrapx - rightX) / float(spaces);
        }

        ++lines;
        if (display) {
            CFont::PrintString(leftX, y, start, end, unknown);
        }

        if (m_bNewLine) {
            end += 3;
        }

        if (tag) {
            printf(gString, "~%c~", tag);
            AsciiToGxtChar(gString, buffer);
            end = GxtCharStrcat(buffer, end);
            tag = 0;
        }

        // begin rendering new line
        m_bNewLine = false;
        y += m_Scale->y * (32.f / 2.f + 2.f); //CFont::GetHeight(false);

        if (m_bFontCentreAlign || m_bFontRightAlign)
            rightX = 0.f;
        else
            rightX = x;

        start = end;
        spaces = 0;
        lastLineRightX = 0;
        unknown = true;
    }

    if (!display) {
        SetColor(rgbaBackup); // restore color
    }

    return lines;
#endif
}

short CFont::GetNumberLines(float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((short(__cdecl*)(float, float, char*))0x71A5E0)(x, y, text);
#else
    return ProcessCurrentString(0, x, y, text);
#endif
}

short CFont::ProcessStringToDisplay(float x, float y, char* text) //
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((short(__cdecl*)(float, float, char*))0x71A600)(x, y, text);
#else
    return GetNumberLines(x, y, text);
#endif
}

void CFont::GetTextRect(CRect* rect, float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRect*, float, float, char*))0x71A620)(rect, x, y, text);
#else
    float fontCentreX;
    float wrapx;

    unsigned char nLines = GetNumberLines(x, y, text);
    if (m_bFontCentreAlign)
    {
        rect->left = x - (m_fFontCentreSize * 0.5f + 4.0f);
        fontCentreX = m_fFontCentreSize * 0.5f + 4.0f + x;
    }
    else
    {
        if (m_bFontRightAlign)
        {
            rect->left = m_fRightJustifyWrap - 4.0f;
            wrapx = x;
        }
        else
        {
            rect->left = x - 4.0f;
            wrapx = m_fWrapx;
        }
        fontCentreX = wrapx + 4.0f;
    }
    rect->right = fontCentreX;
    rect->bottom = y - 4.0f;
    rect->top = (m_Scale->y * 32.0f * 0.5f + m_Scale->y + m_Scale->y) * nLines + y + 4.0f;
#endif
}

void CFont::PrintString(float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, char*))0x71A700)(x, y, text);
#else
    CRect coords;

    if (*text != '*' && *text)
    {
        if (m_bFontBackground)
        {
            RenderState.m_color.red = m_Color.r;
            RenderState.m_color.green = m_Color.g;
            RenderState.m_color.blue = m_Color.b;
            CRect coords = { 1000000.0f, -1000000.0f, -1000000.0f, 1000000.0f };
            GetTextRect(&coords, x, y, text);
            if (m_bEnlargeBackgroundBox)
            {
                coords.bottom -= 1.0;
                coords.top += 1.0;
                coords.left -= 1.0;
                coords.right += 1.0;
                FrontEndMenuManager.DrawWindow(coords, 0, 0, m_FontBackgroundColor, 0, 1);
            }
            else
            {
                CSprite2d::DrawRect(coords, m_FontBackgroundColor);
            }
            m_bFontBackground = false;
        }
        ProcessCurrentString(true, x, y, text);
    }
#endif
}

void CFont::PrintString(float x, float y, char* start, char* end, float wrap)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, char*, char*, float wrap))0x719B40)(x, y, start, end, wrap);
#else
    CRGBA col = m_Color;
    if (RenderState.m_wFontTexture != m_FontTextureId)
    {
        RenderFontBuffer();
        RenderState.m_wFontTexture = m_FontTextureId;
    }

    if (m_nFontShadow == 0.0)
    {
        end = (char*)m_nFontOutlineSize;
        m_Color = m_FontDropColor;
        m_bFontIsBlip = 1;
        m_nFontOutlineSize = 0;
        if (m_fSlant != 0.0)
        {
            m_fSlantRefPoint.x = RsGlobal.maximumWidth * 0.0015625 * m_nFontOutlineSize + m_fSlantRefPoint.x;
            m_fSlantRefPoint.y = RsGlobal.maximumHeight * 0.002232143 * m_nFontOutlineSize + m_fSlantRefPoint.y;
        }

        float _x, _y;
        _y = y - RsGlobal.maximumHeight * 0.002232143 * *(float*)&end;
        _x = RsGlobal.maximumWidth * 0.0015625 * *(float*)&end + x;
        PrintString(_x, _y, start, end, wrap);
        _y = y - RsGlobal.maximumHeight * 0.002232143 * *(float*)&end;
        _x = x - RsGlobal.maximumWidth * 0.0015625 * *(float*)&end;
        PrintString(_x, _y, start, end, wrap);
        _y = RsGlobal.maximumHeight * 0.002232143 * *(float*)&end + y;
        _x = RsGlobal.maximumWidth * 0.0015625 * *(float*)&end + x;
        PrintString(_x, _y, start, end, wrap);
        _y = RsGlobal.maximumHeight * 0.002232143 * *(float*)&end + y;
        _x = x - RsGlobal.maximumWidth * 0.0015625 * *(float*)&end;
        PrintString(_x, _y, start, end, wrap);
        _x = RsGlobal.maximumWidth * 0.0015625 * *(float*)&end + x;
        PrintString(_x, y, start, end, wrap);
        _x = x - RsGlobal.maximumWidth * 0.0015625 * *(float*)&end;
        PrintString(_x, y, start, end, wrap);
        _y = RsGlobal.maximumHeight * 0.002232143 * *(float*)&end + y;
        PrintString(x, _y, start, end, wrap);
        _y = y - RsGlobal.maximumHeight * 0.002232143 * *(float*)&end;
        PrintString(x, _y, start, end, wrap);
    }
#endif
}

void CFont::PrintStringFromBottom(float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, char*))0x71A820)(x, y, text);
#else
    y -= (m_Scale->y * 32.0f * 0.5f + m_Scale->y + m_Scale->y) * GetNumberLines(x, y, text);
    if (m_fSlant != 0.0)
        y -= ((m_fSlantRefPoint.x - x) * m_fSlant + m_fSlantRefPoint.y);
    CFont::PrintString(x, y, text);
#endif
}

//7187C0
void CFont::LoadFontValue()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x7187C0)();
#else
    CFileMgr::SetDir(gta_empty_string);
    FILE* fontDatFile = CFileMgr::OpenFile("DATA\\FONTS.DAT", "rb");
    char* line;
    for (line = CFileLoader::LoadLine(fontDatFile); line; line = CFileLoader::LoadLine(fontDatFile))
    {
        if (*line != '#' && *line)
        {
            unsigned int fontId = 0, totalFonts, propValues[8], replacementSpaceChar;
            char attribute;
            sscanf(line, "%s", &attribute);
            if (!memcmp(&attribute, "[TOTAL_FONTS]", 0xEu))
            {
                sscanf(CFileLoader::LoadLine(fontDatFile), "%d", &totalFonts);
            }
            else if (!memcmp(&attribute, "[FONT_ID]", 0xAu))
            {
                sscanf(CFileLoader::LoadLine(fontDatFile), "%d", &fontId);
            }
            else if (!memcmp(&attribute, "[REPLACEMENT_SPACE_CHAR]", 0x19u))
            {
                sscanf(CFileLoader::LoadLine(fontDatFile), "%d", &replacementSpaceChar);
                gFontData[fontId].m_spaceValue = replacementSpaceChar;
            }
            else if (!memcmp(&attribute, "[PROP]", 7u))
            {
                tFontData* pFontData = &gFontData[fontId];
                for (int propIndex = 0; propIndex < 26; propIndex++)
                {
                    char* line = CFileLoader::LoadLine(fontDatFile);
                    sscanf(line, "%d  %d  %d  %d  %d  %d  %d  %d", &propValues[0], &propValues[1], &propValues[2], &propValues[3], &propValues[4], &propValues[5], &propValues[6], &propValues[7]);
                    for (int i = 0; i < 8; i++)
                    {
                        pFontData->m_propValues[propIndex + i] = propValues[i];
                    }
                }
            }
            else if (!memcmp(&attribute, "[UNPROP]", 9u))
            {
                unsigned int unpropValue;
                sscanf(CFileLoader::LoadLine(fontDatFile), "%d", &unpropValue);
                gFontData[fontId].m_unpropValue = unpropValue;
            }
        }
    }
    CFileMgr::CloseFile(fontDatFile);
#endif
}

int CFont::GetLetterIdPropValue(char letterId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((int(__cdecl*)(char))0x718770)(letterId);
#else
    if (letterId == 63)
        letterId = 0;
    if (RenderState.m_bPropOn == 1)
        return gFontData[RenderState.m_wFontTexture].m_propValues[letterId];
    else
        return gFontData[RenderState.m_wFontTexture].m_unpropValue;
#endif
}

// Thanks nick7.
int CFont::FindSubFontCharacter(char index, char fontAttribute)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((int(__cdecl*)(char, char))0x7192C0)(index, fontAttribute);
#else
    if (fontAttribute == 1) { // STYLE_HEADING
        switch (index) {
        case CHAR_DOLLAR: // 4
            return 93;
        case CHAR_LPARENTHESIS: // 8
            return 94;
        case CHAR_RPARENTHESIS: // 9
            return 95;
        case CHAR_COLON: // 26 - :
            return 154;
        case CHAR_SINGLEQUOTE: // 7
            return 206;
        case CHAR_DOT: // 14
            return 207;
        case CHAR_EXCL: // 1
            return 208;
        }
    }

    if (index == CHAR_AMP)
        return 10;
    if (index >= 16 && index <= 25)
        return index + 128;
    if (index == 31)
        return 91;
    if (index >= 33 && index <= 58)
        return index + 122;
    if (index == 62)
        return 32;
    if (index >= 65 && index <= 90)
        return index + 90;
    if (index >= 96 && index <= 118)
        return index + 85;
    if (index >= 119 && index <= 140)
        return index + 62;
    if (index >= 141 && index <= 142)
        return 204;
    if (index == 143)
        return 205;

    return index;
#endif
}

#undef USE_DEFAULT_FUNCTIONS

CFontDetails* CFontDetails::operator=(CFontDetails const* rhs)
{
    *&this->m_cLetter = *&rhs->m_cLetter;
    this->m_vPosn.x = rhs->m_vPosn.x;
    this->m_vPosn.y = rhs->m_vPosn.y;
    this->m_fWidth = rhs->m_fWidth;
    this->m_fHeigth = rhs->m_fHeigth;
    this->m_color.red = rhs->m_color.red;
    this->m_color.green = rhs->m_color.green;
    this->m_color.blue = rhs->m_color.blue;
    this->m_color.alpha = rhs->m_color.alpha;
    this->m_fWrap = rhs->m_fWrap;
    this->m_fSlant = rhs->m_fSlant;
    this->m_vSlanRefPoint.x = rhs->m_vSlanRefPoint.x;
    this->m_vSlanRefPoint.y = rhs->m_vSlanRefPoint.y;
    this->m_bContainImages = rhs->m_bContainImages;
    this->m_nFontStyle = rhs->m_nFontStyle;
    this->m_bPropOn = rhs->m_bPropOn;
    this->m_wFontTexture = rhs->m_wFontTexture;
    this->m_nOutline = rhs->m_nOutline;

    return this;
}
