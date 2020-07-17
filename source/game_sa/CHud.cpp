#include "StdInc.h"

CSprite2d* CHud::Sprites = (CSprite2d*)0xBAB1FC;

void CHud::InjectHooks()
{
#ifndef USE_DEFAULT_FUNCTIONS
    HookInstall(0x58D7D0, &CHud::DrawWeaponIcon);
#endif
}

// Needs refactoring
void CHud::DrawWeaponIcon(CPed* ped, float x, float y, float alpha)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__cdecl*)(CPed*, int, int, float))0x727420)(ped, x, y, alpha);
#else
    RwEngineInstance->dOpenDevice.fpRenderStateSet(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);

    if (ped->GetActiveWeapon().m_nType <= 0)
    {
        Sprites[HUDSPRITE_FIST].Draw(CRect(x, y, x + SCREEN_SCALE_X(47.0f), y + SCREEN_SCALE_Y(58.0f)), CRGBA(255, 255, 255, alpha));
    }
    else
    {
        eWeaponType WeaponType = ped->GetActiveWeapon().m_nType;
        CWeaponInfo* weaponInfo = CWeaponInfo::GetWeaponInfo((eWeaponType)WeaponType, 1);
        CBaseModelInfo* weaponModel = CModelInfo::GetModelInfo(weaponInfo->m_nModelId1);
        RwTexDictionary** weaponTexDictionary;
        int32_t txdIndex = weaponModel->m_nTxdIndex;
        if ((CTxdStore::ms_pTxdPool->m_byteMap[txdIndex].IntValue() & 0x80u) == 0)
            weaponTexDictionary = (RwTexDictionary**)((char*)CTxdStore::ms_pTxdPool->m_pObjects + 12 * txdIndex);
        else
            weaponTexDictionary = nullptr;

        RwTexDictionary* pWeaponTexDictionary = *weaponTexDictionary;
        if (*weaponTexDictionary)
        {
            uint32_t key = CKeyGen::AppendStringToKey(weaponModel->m_nKey, "ICON");
            RwTexture* weaponTexure = RwTexDictionaryFindHashNamedTexture(pWeaponTexDictionary, key);
            if (weaponTexure)
            {
                RwEngineInstance->dOpenDevice.fpRenderStateSet(rwRENDERSTATEZTESTENABLE, 0);
                RwEngineInstance->dOpenDevice.fpRenderStateSet(rwRENDERSTATETEXTURERASTER, weaponTexure->raster);
                CSprite::RenderOneXLUSprite(x + (SCREEN_SCALE_X(47.0f) / 2), y + (SCREEN_SCALE_Y(58.0f) / 2), 1.0f, SCREEN_SCALE_X(47.0f) / 2, SCREEN_SCALE_Y(58.0f) / 2, 255, 255, 255, 255, 1.0f, 255, 0, 0);
                RwEngineInstance->dOpenDevice.fpRenderStateSet(rwRENDERSTATEZWRITEENABLE, 0);
            }
        }
    }
#endif
}
