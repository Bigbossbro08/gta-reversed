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

CFontDetails& CFont::details = *(CFontDetails*)0xC71A60;

//CRGBA& CFont::m_Color = *(CRGBA*)0xC71A60;
//CVector2D* CFont::m_Scale = (CVector2D*)0xC71A64;
//float& CFont::m_fSlant = *(float*)0xC71A6C;
//CVector2D& CFont::m_fSlantRefPoint = *(CVector2D*)0xC71A70;
//bool& CFont::m_bFontJustify = *(bool*)0xC71A78;
//bool& CFont::m_bFontCentreAlign = *(bool*)0xC71A79;
//bool& CFont::m_bFontRightAlign = *(bool*)0xC71A7A;
//bool& CFont::m_bFontBackground = *(bool*)0xC71A7B;
//bool& CFont::m_bEnlargeBackgroundBox = *(bool*)0xC71A7C;
//bool& CFont::m_bFontPropOn = *(bool*)0xC71A7D;
//bool& CFont::m_bFontIsBlip = *(bool*)0xC71A7E;
//unsigned int CFont::m_dwFontAlpha = *(unsigned int*)0xC71A80;
//CRGBA& CFont::m_FontBackgroundColor = *(CRGBA*)0xC71A84;
//float& CFont::m_fWrapx = *(float*)0xC71A88;
//float& CFont::m_fFontCentreSize = *(float*)0xC71A8C;
//float& CFont::m_fRightJustifyWrap = *(float*)0xC71A90;
//unsigned char& CFont::m_FontTextureId = *(unsigned char*)0xC71A94;
//unsigned char& CFont::m_FontStyle = *(unsigned char*)0xC71A95;
//unsigned char& CFont::m_nFontShadow = *(unsigned char*)0xC71A96;
//CRGBA& CFont::m_FontDropColor = *(CRGBA*)0xC71A97;
//unsigned char& CFont::m_nFontOutlineSize = *(unsigned char*)0xC71A9B;
//unsigned char& CFont::m_nFontOutline = *(unsigned char*)0xC71A9C;

CFontRenderState& CFont::RenderState = *(CFontRenderState*)0xC71AA0;
CFontRenderState*& CFont::pEmptyChar = *(CFontRenderState**)0xC716A8;
CFontRenderState& CFont::setup = *(CFontRenderState*)0xC716B0;

tFontData* CFont::gFontData = (tFontData*)0xC718B0;


void CFont::InjectHooks()
{
    HookInstall(0x5BA690, &CFont::Initialise, 7);
    //HookInstall(0x7187C0, &CFont::LoadFontValue, 7); //Wrong
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
    HookInstall(0x718A10, &CFont::PrintChar, 7);
    HookInstall(0x71A620, &CFont::GetTextRect, 7);
    HookInstall(0x719800, &CFont::InitPerFrame, 7);
    HookInstall(0x71A820, &CFont::PrintStringFromBottom, 7);
    HookInstall(0x71A0E0, &CFont::GetStringWidth, 7);
    HookInstall(0x719670, &CFont::SetCharacterOutline, 7);
    HookInstall(0x718770, &CFont::GetLetterIdPropValue, 7); //fine
    HookInstall(0x718ED0, &CFont::GetNextSpace, 7);
    HookInstall(0x718ED0, &CFont::ParseToken, 7);
    HookInstall(0x71A700, (void(*)(float, float, char*)) & CFont::PrintString, 7);
    HookInstall(0x71A600, &CFont::ProcessStringToDisplay, 7);

#ifdef BROKEN
    HookInstall(0x719750, &CFont::GetCharacterSize, 7); //broken
    HookInstall(0x7192C0, &CFont::FindSubFontCharacter, 7); //broken

    HookInstall(0x71A5E0, &CFont::GetNumberLines, 7);

    HookInstall(0x719B40, (void(*)(float, float, char*, char*, float)) & CFont::PrintString, 7);
    HookInstall(0x71A220, &CFont::ProcessCurrentString, 7);
    HookInstall(0x719840, &CFont::RenderFontBuffer, 7);
#endif
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

void CFont::PrintChar(float x, float y, unsigned char character)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, unsigned char))0x7189B0)();
#else
    double v5; // st7
    float u2; // ST38_4
    float _v4; // ST24_4
    float u4; // ST20_4
    double v9; // st7
    double v10; // st7
    float v11; // ST30_4
    float v12; // ST24_4
    float v13; // ST1C_4
    float v14; // ST38_4
    float v15; // ST30_4
    double v16; // st7
    float v17; // ST24_4
    float v18; // ST1C_4
    float v19; // ST14_4
    float v20; // ST0C_4
    float v1; // [esp+24h] [ebp-1Ch]
    float u1; // [esp+28h] [ebp-18h]

    CRect rect;
    unsigned char charCopy;

    if (y >= 0.0 && RsGlobal.maximumHeight >= y && x >= 0.0 && RsGlobal.maximumWidth >= x)
    {
        if (CFont::PS2Symbol)
        {
            rect.left = x;
            rect.top = CFont::RenderState.m_Scale.y + CFont::RenderState.m_Scale.y + y;
            rect.right = CFont::RenderState.m_Scale.y * 17.0 + x;
            rect.bottom = CFont::RenderState.m_Scale.y * 19.0 + y;
            CRGBA fontColor = CRGBA(255u, 255u, 255u, RenderState.m_Color.a);
            PS2Sprite[PS2Symbol].Draw(rect, fontColor);
        }
        else
        {
            charCopy = character;
            bool isLetter = false;
            if (!character || character == '?')
            {
                charCopy = 0;
                isLetter = true;
                character = 0;
            }
            float letterIdPropValue = GetLetterIdPropValue(character) * (1.0 / 32.0);
            if (CFont::RenderState.m_nFontStyle == 1 && charCopy == 0xD0u)
                charCopy = 0;

            const float xRatio = 1.0f / 16.0f;
            const float yRatio = 1.0f / 12.8f;
            const float widthOffset = 1.0f / 10000.0f;

            v5 = (charCopy >> 4);
            u1 = (charCopy & 0xF) * xRatio;                 // 1 : 16
            if (CFont::RenderState.m_wFontTexture && CFont::RenderState.m_wFontTexture != 1)
            {
                v1 = v5 * (1.0 / 16.0);
                if (!isLetter)
                {
                    rect.left = y;
                    rect.top = x;
                    rect.right = *&CFont::RenderState.m_Scale.x * 32.0 * letterIdPropValue + x;
                    rect.bottom = CFont::RenderState.m_Scale.y * 32.0 * 0.5 + y;
                    y = v1 + xRatio;
                    u2 = letterIdPropValue * xRatio + u1;
                    _v4 = y - 0.0001; //0.000099999997
                    u4 = u2 - 0.0001; //0.000099999997
                    CSprite2d::AddToBuffer(rect, CFont::RenderState.m_Color, u1, v1, u2, v1, u1, y, u4, _v4);
                }
            }
            else
            {
                //v1a = v5 * (5.0 / 64.0);
                float characterRatio = (charCopy >> 4) * 0.078125f;
                if (!isLetter)
                {
                    //
                    //float left;          // x1
                    //float bottom;        // y1
                    //float right;         // x2
                    //float top;           // y2
                    rect.left = x;
                    if (CFont::RenderState.m_fSlant == 0.0)
                    {
                        rect.top = y;
                        rect.right = *&CFont::RenderState.m_Scale.x * 32.0 + x;
                        v9 = CFont::RenderState.m_Scale.y;
                        if (charCopy < 0xC0u)
                        {
                            rect.bottom = v9 * 40.0 * 0.5 + y;
                            v14 = characterRatio + yRatio - 0.0021; //0.0020999999
                            y = u1 + xRatio - (widthOffset * 10.0f);
                            v15 = characterRatio + 0.0021;
                            CSprite2d::AddToBuffer(rect, RenderState.m_Color, u1, v15, y, v15, u1, v14, y, v14);
                        }
                        else
                        {
                            rect.bottom = v9 * 32.0 * 0.5 + y;
                            v10 = characterRatio + yRatio;
                            y = u1 + xRatio - (widthOffset * 10.0f);
                            v11 = characterRatio + 0.0021;
                            v12 = v10 - 0.015;
                            v13 = v10 - 0.016;
                            CSprite2d::AddToBuffer(rect, RenderState.m_Color, u1, v11, y, v11, u1, v13, y, v12);
                        }
                    }
                    else
                    {
                        rect.top = y + 0.015;
                        rect.right = *&CFont::RenderState.m_Scale.x * 32.0 + x;
                        rect.bottom = CFont::RenderState.m_Scale.y * 40.0 * 0.5 + y + 0.015;
                        v16 = characterRatio + yRatio; //0.078125
                        y = u1 + xRatio - 0.001;
                        v17 = v16 - 0.0021 + (widthOffset * 100.0f);
                        v18 = v16 - 0.009;
                        v19 = characterRatio + 0.0121;
                        v20 = characterRatio + 0.00055;
                        CSprite2d::AddToBuffer(rect, RenderState.m_Color, u1, v20, y, v19, u1, v18, y, v17);
                    }
                }
            }
        }
    }
#endif
}

char* CFont::GetNextSpace(char* text)
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

//bug
#define USE_DEFAULT_FUNCTIONS

char* CFont::ParseToken(char* text, CRGBA& colour, bool disableColor, char* colorCode)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((char* (__cdecl*)(char*, CRGBA&, bool, char*))0x718ED0)(text, colour, disableColor, colorCode);
#else
    char nbColor = -1;

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
    details.m_Scale.x = w;
    details.m_Scale.y = h;
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
        details.m_Scale.y = h;
        details.m_Scale.x = w * 0.8f;
        break;
    default:
        details.m_Scale.x = w;
        details.m_Scale.y = h;
        break;
    }
#endif
}

void CFont::SetSlantRefPoint(float x, float y)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float))0x719400)(x, y);
#else
    details.m_SlantRef.x = x;
    details.m_SlantRef.y = y;
#endif
}

void CFont::SetSlant(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x719420)(value);
#else
    details.m_fSlant = value;
#endif
}

void CFont::SetColor(CRGBA color)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRGBA))0x719430)(color);
#else
    details.m_Color = color;
    if (details.m_fFontAlpha < 255)
        details.m_Color.a = color.a * details.m_fFontAlpha / 255;
#endif
}

void CFont::SetFontStyle(char style)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(short))0x719490)(style);
#else
    if (style == FONT_MENU)
    {
        details.m_FontTextureId = 0;
        details.m_FontStyle = FONT_MENU;
    }
    else if (style == FONT_PRICEDOWN)
    {
        details.m_FontTextureId = 1;
        details.m_FontStyle = FONT_SUBTITLES;
    }
    else
    {
        details.m_FontTextureId = style;
        details.m_FontStyle = FONT_GOTHIC;
    }
#endif
}

void CFont::SetWrapx(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x7194D0)(value);
#else
    details.m_fWrapx = value;
#endif
}

void CFont::SetCentreSize(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x7194E0)(value);
#else
    details.m_fFontCentreSize = value;
#endif
}

void CFont::SetRightJustifyWrap(float value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x7194F0)(value);
#else
    details.m_fRightJustifyWrap = value;
#endif
}

void CFont::SetAlphaFade(float alpha)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float))0x719500)(alpha);
#else
    details.m_fFontAlpha = alpha;
#endif
}

void CFont::SetDropColor(CRGBA color)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRGBA))0x719510)(color);
#else
    details.m_FontDropColor = color;
    if (details.m_fFontAlpha < 255)
        details.m_FontDropColor.a = color.a * details.m_fFontAlpha / 255; //(m_Color->a * m_dwFontAlpha * (unsigned char)0.0039215689);
#endif
}

void CFont::SetDropShadowPosition(char value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(short))0x719570)(value);
#else
    details.m_nFontOutlineSize = 0;
    details.m_nFontOutline = 0;
    details.m_nFontShadow = (unsigned char)value;
#endif
}

void CFont::SetEdge(char value)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(short))0x719590)(value);
#else
    details.m_nFontOutlineSize = value;
    details.m_nFontOutline = value;
    details.m_nFontShadow = 0;
#endif
}

void CFont::SetProportional(bool on)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(bool))0x7195B0)(on);
#else
    details.m_bFontPropOn = on;
#endif
}

void CFont::SetBackground(bool enable, bool includeWrap)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(bool, bool))0x7195C0)(enable, includeWrap);
#else
    details.m_bFontBackground = enable;
    details.m_bEnlargeBackgroundBox = includeWrap;
#endif
}

void CFont::SetBackgroundColor(CRGBA color)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRGBA))0x7195E0)(color);
#else
    details.m_FontBackgroundColor = color;
#endif
}

void CFont::SetJustify(bool on)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(bool))0x719600)(on);
#else
    details.m_bFontJustify = on;
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
            details.m_bFontCentreAlign = false;
            details.m_bFontRightAlign = false;
        }
        else if (alignment == ALIGN_RIGHT)
        {
            details.m_bFontCentreAlign = false;
            details.m_bFontRightAlign = true;
        }
    }
    else
    {
        details.m_bFontCentreAlign = true;
        details.m_bFontRightAlign = false;
    }
#endif
}

void CFont::InitPerFrame()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x719800)();
#else
    details.m_nFontOutlineSize = 0;
    details.m_nFontOutline = false;
    details.m_nFontShadow = false;
    m_bNewLine = false;
    PS2Symbol = false;
    RenderState.m_wFontTexture = -1;
    pEmptyChar = &setup;
    CSprite::InitSpriteBuffer();
#endif
}

//#define USE_DEFAULT_FUNCTIONS

float CFont::GetStringWidth(char* str, bool bFull, bool bScriptText)
{
#if false
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
    int size = 0;

    letterIdPropValue = letterId;
    if (letterId == 63)
    {
        letterIdPropValue = 0;
        letterId = 0;
    }
    if (details.m_FontStyle)
    {
        letterIdPropValue = FindSubFontCharacter(letterId, details.m_FontStyle);
    }
    else if (letterIdPropValue == 145)
    {
        letterIdPropValue = 64;
    }
    else if (letterIdPropValue > 155)
    {
        letterIdPropValue = 0;
    }

    if (details.m_bFontPropOn)
        size = (gFontData[details.m_FontTextureId].m_propValues[letterIdPropValue] + details.m_nFontOutlineSize) * details.m_Scale.x;
    else
        size = (gFontData[details.m_FontTextureId].m_unpropValue + details.m_nFontOutlineSize) * details.m_Scale.x;

    return size;
#endif
}

#undef USE_DEFAULT_FUNCTIONS

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

#define USE_DEFAULT_FUNCTIONS

void CFont::RenderFontBuffer()
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)())0x719840)();
#else
    //printf("CFont::RenderFontBuffer called.\n");
    CRGBA col;
    CVector2D pos;
    char outline;
    unsigned char letterCopyIter = 0;
    int j = 0;

    if (pEmptyChar->m_cLetter != setup.m_cLetter)
    {
        Sprite[RenderState.m_wFontTexture].SetRenderState();
        RwRenderStateSetFunction(rwRENDERSTATEVERTEXALPHAENABLE);
        RenderState = setup;
        col = RenderState.m_Color;
        pos.x = RenderState.m_Position.x;
        pos.y = RenderState.m_Position.y;

        for (int i = setup.m_cLetter; i < pEmptyChar->m_cLetter; letterCopyIter = pEmptyChar->m_cLetter)
        {
            printf("%c", pEmptyChar->m_cLetter);
            if (!i)
            {
                for (int j = (i + 1); j & 3; j = (j + 1)) {
                    if (j >= pEmptyChar->m_cLetter)
                        break;
                    i = j + 1;
                }

                //CTextRender::Set(&CFont::RenderState, j);
                RenderState = pEmptyChar; //I believe this is assigned to emptyChar, not sure
                pos.y = CFont::RenderState.m_Position.y;
                //v13 = CFont::RenderState.m_Color.b;
                pos.x = CFont::RenderState.m_Position.x;
                col = CFont::RenderState.m_Color;
                i = j + 1;
            }

            for (PS2Symbol = 0; setup.m_cLetter == '~';) {
                if (PS2Symbol)
                    break;
                i = (int)ParseToken(&setup.m_cLetter, col, RenderState.m_bForcedColor, 0);
                if (!RenderState.m_bForcedColor) {
                    RenderState.m_Color.r = col.r;
                    RenderState.m_Color.g = col.g;
                    RenderState.m_Color.b = col.b;
                    RenderState.m_Color.a = col.a;
                }
            }

            unsigned char letterIndex = setup.m_cLetter - 32;
            if (RenderState.m_nFontStyle) {
                letterIndex = FindSubFontCharacter(letterIndex, RenderState.m_nFontStyle);
            }
            else
            {
                if (letterIndex == 0x91u) {
                    letterIndex = '@';
                }
                else if (letterIndex > 155u) {
                    letterIndex = 0;
                }
            }

            if (RenderState.m_fSlant != 0.0)
                pos.y = (RenderState.m_SlantRef.x - pos.x) * RenderState.m_fSlant + RenderState.m_SlantRef.y;

            if (!PS2Symbol || !RenderState.m_bForcedColor) {
                PrintChar(pos.x, pos.y, letterIndex);
            }

            if (PS2Symbol) {
                outline = RenderState.m_nOutline;
                pos.x = RenderState.m_Scale.y * 17.0 + RenderState.m_nOutline + pos.x;
            }
            else
            {
                if (letterIndex == '?')
                    letterIndex = 0;
                if (RenderState.m_bPropOn == 1)
                    outline = gFontData[RenderState.m_wFontTexture].m_propValues[letterIndex];
                else
                    outline = gFontData[RenderState.m_wFontTexture].m_unpropValue;
                char _outline = outline;
                outline = RenderState.m_nOutline;
                pos.x = (RenderState.m_nOutline + _outline) * *&RenderState.m_Scale.x + pos.x;
            }

            if (!letterIndex)
                pos.x = CFont::RenderState.m_fWrap + pos.x;

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

short CFont::GetNumberLines(char bPrint, float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((short(__cdecl*)(float, float, char*))0x71A5E0)(x, y, text);
#else
    return ProcessCurrentString(0, x, y, text);
#endif
}

#undef USE_DEFAULT_FUNCTIONS

short CFont::ProcessStringToDisplay(float x, float y, char* text) //
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((short(__cdecl*)(float, float, char*))0x71A600)(x, y, text);
#else
    return GetNumberLines(true, x, y, text);
#endif
}

void CFont::GetTextRect(CRect* rect, float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CRect*, float, float, char*))0x71A620)(rect, x, y, text);
#else
    float fontCentreX;
    float wrapx;

    unsigned char nLines = GetNumberLines(false, x, y, text);
    if (details.m_bFontCentreAlign)
    {
        rect->left = x - (details.m_fFontCentreSize * 0.5f + 4.0f);
        fontCentreX = details.m_fFontCentreSize * 0.5f + 4.0f + x;
    }
    else
    {
        if (details.m_bFontRightAlign)
        {
            rect->left = details.m_fRightJustifyWrap - 4.0f;
            wrapx = x;
        }
        else
        {
            rect->left = x - 4.0f;
            wrapx = details.m_fWrapx;
        }
        fontCentreX = wrapx + 4.0f;
    }
    rect->right = fontCentreX;
    rect->bottom = y - 4.0f;
    rect->top = (details.m_Scale.y * 32.0f * 0.5f + details.m_Scale.y + details.m_Scale.y) * nLines + y + 4.0f;
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
        if (details.m_bFontBackground)
        {
            RenderState.m_Color.r = details.m_Color.r;
            RenderState.m_Color.g = details.m_Color.g;
            RenderState.m_Color.b = details.m_Color.b;
            CRect coords = { 1000000.0f, -1000000.0f, -1000000.0f, 1000000.0f };
            GetTextRect(&coords, x, y, text);
            if (details.m_bEnlargeBackgroundBox)
            {
                coords.bottom -= 1.0;
                coords.top += 1.0;
                coords.left -= 1.0;
                coords.right += 1.0;
                FrontEndMenuManager.DrawWindow(coords, 0, 0, details.m_FontBackgroundColor, 0, 1);
            }
            else
            {
                CSprite2d::DrawRect(coords, details.m_FontBackgroundColor);
            }
            details.m_bFontBackground = false;
        }
        ProcessCurrentString(true, x, y, text);
    }
#endif
}

#define USE_DEFAULT_FUNCTIONS

void CFont::PrintString(float x, float y, char* start, char* end, float wrap)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, char*, char*, float))0x71A700)(x, y, start, end, wrap);
#else
    CRGBA col = details.m_Color;
    if (RenderState.m_wFontTexture != details.m_FontTextureId)
    {
        RenderFontBuffer();
        RenderState.m_wFontTexture = details.m_FontTextureId;
    }

    if (details.m_nFontShadow == 0.0)
    {
        end = (char*)details.m_nFontOutlineSize;
        details.m_Color = details.m_FontDropColor;
        details.m_bFontIsBlip = 1;
        details.m_nFontOutlineSize = 0;
        if (details.m_fSlant != 0.0)
        {
            details.m_SlantRef.x = RsGlobal.maximumWidth * 0.0015625 * details.m_nFontOutlineSize + details.m_SlantRef.x;
            details.m_SlantRef.y = RsGlobal.maximumHeight * 0.002232143 * details.m_nFontOutlineSize + details.m_SlantRef.y;
        }

        //((void(__cdecl*)(float, float, char*, char*, float wrap))0x719B40)(x, y, start, end, wrap);

        //return;
        float _x, _y;
        _y = y - RsGlobal.maximumHeight * 0.002232143 * *(float*)&end;
        _x = RsGlobal.maximumWidth * 0.0015625 * *(float*)&end + x;
        PrintString(_x, _y, start);//, end, wrap);
        _y = y - RsGlobal.maximumHeight * 0.002232143 * *(float*)&end;
        _x = x - RsGlobal.maximumWidth * 0.0015625 * *(float*)&end;
        PrintString(_x, _y, start);//, end, wrap);
        _y = RsGlobal.maximumHeight * 0.002232143 * *(float*)&end + y;
        _x = RsGlobal.maximumWidth * 0.0015625 * *(float*)&end + x;
        PrintString(_x, _y, start);//, end, wrap);
        _y = RsGlobal.maximumHeight * 0.002232143 * *(float*)&end + y;
        _x = x - RsGlobal.maximumWidth * 0.0015625 * *(float*)&end;
        PrintString(_x, _y, start);//, end, wrap);
        _x = RsGlobal.maximumWidth * 0.0015625 * *(float*)&end + x;
        PrintString(_x, y, start);//, end, wrap);
        _x = x - RsGlobal.maximumWidth * 0.0015625 * *(float*)&end;
        PrintString(_x, y, start);//, end, wrap);
        _y = RsGlobal.maximumHeight * 0.002232143 * *(float*)&end + y;
        PrintString(x, _y, start);//, end, wrap);
        _y = y - RsGlobal.maximumHeight * 0.002232143 * *(float*)&end;
        PrintString(x, _y, start);//, end, wrap);
    }
#endif
}

#undef USE_DEFAULT_FUNCTIONS

void CFont::PrintStringFromBottom(float x, float y, char* text)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(float, float, char*))0x71A820)(x, y, text);
#else
    y -= (details.m_Scale.y * 32.0f * 0.5f + details.m_Scale.y + details.m_Scale.y) * GetNumberLines(false, x, y, text);
    if (details.m_fSlant != 0.0)
        y -= ((details.m_SlantRef.x - x) * details.m_fSlant + details.m_SlantRef.y);
    PrintString(x, y, text);
#endif
}

//7187C0
void CFont::LoadFontValue()
{
#if true
    ((void(__cdecl*)())0x7187C0)();
#else
    //CFileMgr::SetDir(gta_empty_string);
    CFileMgr::SetDir("");
    FILE* fontDatFile = CFileMgr::OpenFile("DATA\\FONTS.DAT", "rb");
    char* line;
    for (line = CFileLoader::LoadLine(fontDatFile); line; line = CFileLoader::LoadLine(fontDatFile))
    {
        if (*line != '#' && *line)
        {
            unsigned int fontId = 0, totalFonts, propValues[8], replacementSpaceChar;
            char attribute[32];
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
                        pFontData->m_propValues[0] = propValues[i];
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

#define USE_DEFAULT_FUNCTIONS

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

int CFont::GetLetterIdPropValue(char letterId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return ((int(__cdecl*)(char))0x718770)(letterId);
#else
    if (letterId == CHAR_UNDERSCORE)
        letterId = CHAR_SPACE;
    if (RenderState.m_bPropOn == 1)
        return gFontData[RenderState.m_wFontTexture].m_propValues[letterId];
    else
        return gFontData[RenderState.m_wFontTexture].m_unpropValue;
#endif
}

CFontRenderState* CFontRenderState::operator=(CFontRenderState const* rhs)
{
    this->m_cLetter = rhs->m_cLetter;
    this->m_Position = rhs->m_Position;
    this->m_Scale = rhs->m_Scale;
    this->m_Color = rhs->m_Color;
    this->m_fWrap = rhs->m_fWrap;
    this->m_fSlant = rhs->m_fSlant;
    this->m_SlantRef = rhs->m_SlantRef;
    this->m_bForcedColor = rhs->m_bForcedColor;
    this->m_nFontStyle = rhs->m_nFontStyle;
    this->m_bPropOn = rhs->m_bPropOn;
    this->m_wFontTexture = rhs->m_wFontTexture;
    this->m_nOutline = rhs->m_nOutline;

    return this;
}
