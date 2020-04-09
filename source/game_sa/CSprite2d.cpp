#include "StdInc.h"

void CSprite2d::InjectHooks()
{
    //HookInstall(0x727230, &CSprite2d::CSprite2d, 7);
    //HookInstall(0x7281E0, &CSprite2d::~CSprite2d, 7);
}

CSprite2d::CSprite2d()
{
//#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__thiscall*)(CSprite2d*))0x727230)(this);
//#else
//    m_pTexture = 0;
//#endif
}

CSprite2d::~CSprite2d()
{
//#ifdef USE_DEFAULT_FUNCTIONS
  ((void(__cdecl*)(CSprite2d*))0x7281E0)(this);
//#else
//    RwTextureDestroy(m_pTexture);
//#endif
}
