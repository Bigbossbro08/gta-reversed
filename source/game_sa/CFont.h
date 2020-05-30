/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"
#include "CRGBA.h"
#include "CRect.h"
#include "CSprite2d.h"

#define MAX_FONT_SPRITES 2
#define MAX_FONT_BUTTON_SPRITES 15
#define MAX_STRING_WIDTH 400

enum  eFontAlignment : unsigned char {
    ALIGN_CENTER,
    ALIGN_LEFT,
    ALIGN_RIGHT
};

enum  eFontStyle : unsigned char {
    FONT_GOTHIC,
    FONT_SUBTITLES,
    FONT_MENU,
    FONT_PRICEDOWN
};

// Thanks Nick007J
enum ePS2Sprites : unsigned char {
    PS2_NONE,
    PS2_UP,         ///<  1  ~U~
    PS2_DOWN,       ///<  2  ~D~
    PS2_LEFT,       ///<  3  ~<~  
    PS2_RIGHT,      ///<  4  ~>~  
    PS2_CROSS,      ///<  5  ~X~  PS2: cross    / XBOX: A
    PS2_CIRCLE,     ///<  6  ~O~  PS2: circle   / XBOX: B
    PS2_SQUARE,     ///<  7  ~Q~  PS2: square   / XBOX: X
    PS2_TRIANGLE,   ///<  8  ~T~  PS2: triangle / XBOX: Y
    PS2_L1,         ///<  9  ~K~  PS2: L1       /
    PS2_L2,         ///< 10  ~M~  PS2: L2       /
    PS2_L3,         ///< 11  ~A~  PS2: L3       / XBOX: LStick
    PS2_R1,         ///< 12  ~J~  PS2: R1       /
    PS2_R2,         ///< 13  ~V~  PS2: R2       /
    PS2_R3,         ///< 14  ~C~  PS2: R3       / XBOX: RStick

    PS2_SPRITE_COUNT,
};

// Thanks Nick007J
enum eFontData : unsigned char {
    SPRITE_FONT1 = 1,
    SPRITE_FONT2 = 0,
    SPRITE_FONT_SPECIAL = 2,

    FONT_BUFFER_SIZE = 512, // in bytes
    FONT_SPRITE_COUNT = 3,   // 2
    FONT_SYMBOL_COUNT = 208,
    FONT_CHAR_SPACE = 208,
    FONT_CHAR_UNPROP = 209,
    FONT_CHAR_COUNT = 210,
};

// Thanks Nick007J
enum eFontSymbol : unsigned char {
    FONT_TABLE_BASE     = 32,
    FONT_TABLE_ROW      = 16,
    FONT_TABLE_ROWS     = 13,
    FONT_TABLE_SIZE     = FONT_TABLE_ROW * FONT_TABLE_ROWS,
    CHAR_SPACE          = ' '   -     FONT_TABLE_BASE,  ///< 0
    CHAR_EXCL           = '!'   -     FONT_TABLE_BASE,  ///< 1   !
    CHAR_QUOT           = '"'   -     FONT_TABLE_BASE,  ///< 2   "
    CHAR_POUND          = '#'   -     FONT_TABLE_BASE,  ///< 3   #
    CHAR_DOLLAR         = '$'   -     FONT_TABLE_BASE,  ///< 4   $
    CHAR_PERCENT        = '%'   -     FONT_TABLE_BASE,  ///< 5   %
    CHAR_AMP            = '&'   -     FONT_TABLE_BASE,  ///< 6   &
    CHAR_SINGLEQUOTE    = '\''  -     FONT_TABLE_BASE,  ///< 7   '
    CHAR_LPARENTHESIS   = '('   -     FONT_TABLE_BASE,  ///< 8   (
    CHAR_RPARENTHESIS   = ')'   -     FONT_TABLE_BASE,  ///< 9   )
    CHAR_MINUS          = '-'   -     FONT_TABLE_BASE,  ///< 13  -
    CHAR_DOT            = '.'   -     FONT_TABLE_BASE,  ///< 14  .
    CHAR_SLASH          = '/'   -     FONT_TABLE_BASE,  ///< 15  /
    CHAR_COLON          = ':'   -     FONT_TABLE_BASE,  ///< 26  :
    CHAR_BACKSLASH      = '\\'  -     FONT_TABLE_BASE,  ///< 60  
    CHAR_UNDERSCORE     = '_'   -     FONT_TABLE_BASE,  ///< 63  _
};

class CFontDetails
{
public:
    char m_cLetter;
    char _pad0[3];
    CVector2D m_vPosn;
    int m_fWidth;
    int m_fHeigth;
    RwRGBA m_color;
    int m_fWrap;
    int m_fSlant;
    CVector2D m_vSlanRefPoint;
    char m_bContainImages;
    char m_nFontStyle;
    char m_bPropOn;
    char _pad1;
    short m_wFontTexture;
    char m_nOutline;
    char _pad2;

    CFontDetails* operator=(CFontDetails const* rhs);
};

VALIDATE_SIZE(CFontDetails, 0x30);

class tFontData
{
public:
    char m_propValues[208];
    char m_spaceValue;
    char m_unpropValue;
};

VALIDATE_SIZE(tFontData, 0xD2);

class  CFont {
public:
    // static variables

    // font textures array. Num of elements: MAX_FONT_SPRITES (2)
    static CSprite2d *Sprite;
    // button textures array. Num of elements: MAX_FONT_BUTTON_SPRITES (15)
    static CSprite2d *ButtonSprite;
    static unsigned char& PS2Symbol;
    static bool& m_bNewLine;

    static CRGBA& m_Color;
    static CVector2D *m_Scale;
    static float& m_fSlant;
    static CVector2D *m_fSlantRefPoint;
    static bool& m_bFontJustify;
    static bool& m_bFontCentreAlign;
    static bool& m_bFontRightAlign;
    static bool& m_bFontBackground;
    static bool& m_bEnlargeBackgroundBox;
    static bool& m_bFontPropOn;
    static bool& m_bFontIsBlip;
    static unsigned int m_dwFontAlpha;
    static CRGBA& m_FontBackgroundColor;
    static float& m_fWrapx;
    static float& m_fFontCentreSize;
    static float& m_fRightJustifyWrap;
    static unsigned char& m_FontTextureId;
    static unsigned char& m_FontStyle;
    static unsigned char& m_nFontShadow;
    static CRGBA& m_FontDropColor;
    static unsigned char& m_nFontOutlineSize;
    static unsigned char& m_nFontOutline;
    static CFontDetails& RenderState;
    static CFontDetails*& pEmptyChar;
    static CFontDetails& setup;

    static tFontData* gFontData;

    // static functions

    static void InjectHooks();

    // CFont initialisation
    static void Initialise();
    // CFont closing
    static void Shutdown();
    // this adds a single character into rendering buffer
    static void PrintChar(float x, float y, char character);
    // get next ' ' character in a string
    static char *GetNextSpace(char *string);
    // tags processing
    static char* ParseToken(char *text, CRGBA & color, bool isBlip, char *tag);
    // text scaling
    static void SetScale(float w, float h);
    // text scaling depends on current language
    static void SetScaleForCurrentlanguage(float w, float h);
    // set text rotation point
    static void SetSlantRefPoint(float x, float y);
    // set text rotation angle
    static void SetSlant(float value);
    // set text color
    static void SetColor(CRGBA color);
    // set text style
    static void SetFontStyle(short style);
    // set line width at right
    static void SetWrapx(float value);
    // set line width at center
    static void SetCentreSize(float value);
    static void SetRightJustifyWrap(float value);
    // like a 'global' font alpha, multiplied with each text alpha (from SetColor)
    static void SetAlphaFade(float alpha);
    // drop color is used for text shadow and text outline
    static void SetDropColor(CRGBA color);
    // set shadow size
    static void SetDropShadowPosition(short value);
    // set outline size
    static void SetEdge(short value);
    // toggles character proportions in text
    static void SetProportional(bool on);
    // setups text background
    static void SetBackground(bool enable, bool includeWrap);
    // sets background color
    static void SetBackgroundColor(CRGBA color);
    static void SetJustify(bool on);
    static void SetAllignment(eFontAlignment alignment);
    // need to call this each frame
    static void InitPerFrame();
    // draw text we have in buffer
    static void RenderFontBuffer();
    static int GetCharacterSize(char letterId);
    static float GetStringWidth(char *string, bool bFull, bool bScriptText);
    static double SetCharacterOutline(char letterId);
    // same as RenderFontBuffer()
    static void DrawFonts();
    static short ProcessCurrentString(bool print, float x, float y, char *text);
    static short GetNumberLines(float x, float y, char *text);
    static short ProcessStringToDisplay(float x, float y, char *text);
    static void GetTextRect(CRect *rect, float x, float y, char *text);
    static void PrintString(float x, float y, char *text);
    static void PrintStringFromBottom(float x, float y, char *text);

    static void LoadFontValue();
    static int GetLetterIdPropValue(char letterId);
    static int GetLetterIdPropValue(char letterId, char fontType);
};
