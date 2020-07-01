#include "StdInc.h"

void CTaskSimpleStealthKill::InjectHooks()
{
    HookInstall(0x62E540, &CTaskSimpleStealthKill::ProcessPed_Reversed);
    //HookInstall(0x6225F0, &CTaskSimpleStealthKill::Constructor);
    //HookInstall(0x623830, &CTaskSimpleStealthKill::Clone_Reversed);
    HookInstall(0x622670, &CTaskSimpleStealthKill::GetId_Reversed);
    //HookInstall(0x6296D0, &CTaskSimpleStealthKill::ManageAnim);
}

CTaskSimpleStealthKill::CTaskSimpleStealthKill(bool bKeepTargetAlive, CPed* pTarget, int nAssocGroupId)
{
    m_bKeepTargetAlive = bKeepTargetAlive;
    m_pTarget = pTarget;
    m_nAssocGroupId = nAssocGroupId;
    m_bIsAborting = false;
    m_bIsFinished = false;
    m_pAnim = nullptr;
    m_nTime = 0;
    if (pTarget)
        pTarget->RegisterReference(reinterpret_cast<CEntity**>(&m_pTarget));
}

#define USE_DEFAULT_FUNCTIONS
CTaskSimpleStealthKill* CTaskSimpleStealthKill::Constructor(bool bKeepTargetAlive, CPed* pTarget, int nAssocGroupId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallMethodAndReturn<CTaskSimpleStealthKill*, 0x6225F0, CTaskSimpleStealthKill*, bool, CPed*, int>(this, bKeepTargetAlive, pTarget, nAssocGroupId);
#else
    this->CTaskSimpleStealthKill::CTaskSimpleStealthKill(bKeepTargetAlive, pTarget, nAssocGroupId);
    return this;
#endif
}
#undef USE_DEFAULT_FUNCTIONS

bool CTaskSimpleStealthKill::ProcessPed_Reversed(CPed* ped) {
    if (m_bIsAborting || !m_pTarget)
        return true;

    if (!m_pAnim)
    {
        if (!m_bKeepTargetAlive)
            ped->SetPedState(PEDSTATE_DIE_BY_STEALTH);

        ManageAnim(ped);
        if (!m_pAnim) {
            if (m_bIsFinished)
                return false;
        }
    }

    ped->m_pedIK.bSlopePitch = true;

    CVector distance = m_pTarget->GetPosition() - ped->GetPosition();

    if (!m_bKeepTargetAlive) {
        if (!m_pAnim || m_pAnim->m_nAnimId == ANIM_ID_KILL_KNIFE_PED_DAMAGE) {
            ped->m_fAimingRotation = atan2(-(distance.x * -1.0f), distance.y * -1.0f);
            return false;
        }
        return false;
    }

    float normalizedDistance = distance.Magnitude() - 1.0f;
    if (fabs(normalizedDistance) <= 0.02f)
    {
        ped->m_fAimingRotation = atan2(-distance.x, distance.y);
    }
    else
    {
        float timeStepMultiplier = CTimer::ms_fTimeStep * 0.05f;
        if (normalizedDistance > timeStepMultiplier)
            normalizedDistance = timeStepMultiplier;
        ped->m_vecAnimMovingShiftLocal.y = normalizedDistance;
        ped->m_vecAnimMovingShiftLocal.x = 0.0f;
        ped->m_fAimingRotation = atan2(-distance.x, distance.y);
    }

    return false;
}

bool CTaskSimpleStealthKill::ProcessPed(CPed* ped)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallMethodAndReturn<bool, 0x62E540, CTask*, CPed*>(this, ped);
#else
    return CTaskSimpleStealthKill::ProcessPed_Reversed(ped);
#endif
}

#define USE_DEFAULT_FUNCTIONS
CTask* CTaskSimpleStealthKill::Clone_Reversed()
{
    return new CTaskSimpleStealthKill(m_bKeepTargetAlive, m_pTarget, m_nAssocGroupId);
}
#undef USE_DEFAULT_FUNCTIONS

CTask* CTaskSimpleStealthKill::Clone()
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallMethodAndReturn<CTaskSimpleStealthKill*, 0x623830, CTaskSimpleStealthKill*>(this);
#else
    return CTaskSimpleStealthKill::Clone_Reversed();
#endif
}

bool CTaskSimpleStealthKill::MakeAbortable(class CPed* ped, eAbortPriority priority, class CEvent* _event)
{
    return plugin::CallMethodAndReturn<bool, 0x6226F0, CTaskSimpleStealthKill*, CPed*, eAbortPriority, CEvent*>(this, ped, priority, _event);
}

// Unfinished
bool CTaskSimpleStealthKill::MakeAbortable_Reversed(class CPed* ped, eAbortPriority priority, class CEvent* _event)
{
    return plugin::CallMethodAndReturn<bool, 0x6226F0, CTaskSimpleStealthKill*, CPed*, eAbortPriority, CEvent*>(this, ped, priority, _event);
    /*if (priority == ABORT_PRIORITY_IMMEDIATE)
    {
        if (m_pAnim)
        {
            m_pAnim->SetDeleteCallback(CDefaultAnimCallback::DefaultAnimCB, 0);
            m_pAnim = nullptr;
        }

        m_bIsAborting = true;
    }
    else if (
        priority == ABORT_PRIORITY_URGENT &&
        !m_bKeepTargetAlive &&
        m_pAnim != nullptr &&
        m_pAnim->m_nAnimId == ANIM_ID_KILL_KNIFE_PED_DIE &&
        _event->GetEventType() == EVENT_DAMAGE &&)
    {
        
    }*/
}

eTaskType CTaskSimpleStealthKill::GetId()
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallMethodAndReturn<eTaskType, 0x622670, CTaskSimpleStealthKill*>(this);
#else
    return CTaskSimpleStealthKill::GetId_Reversed();
#endif
}

#define USE_DEFAULT_FUNCTIONS

void CTaskSimpleStealthKill::ManageAnim(CPed* ped)
{
#ifdef USE_DEFAULT_FUNCTIONS
    ((void(__thiscall*)(CTaskSimpleStealthKill*, CPed*))0x6296D0)(this, ped);
#else
    CAnimBlock* pAnimBlock = CAnimManager::ms_aAnimAssocGroups[m_nAssocGroupId].m_pAnimBlock;
    if (pAnimBlock && pAnimBlock->bLoaded)
    {
        if (m_bKeepTargetAlive)
        {
            m_pAnim = CAnimManager::BlendAnimation(ped->m_pRwClump, m_nAssocGroupId, ANIM_ID_KILL_KNIFE_PLAYER, 8.0);
        }
        else if (m_bIsFinished)
        {
            m_pAnim = CAnimManager::BlendAnimation(ped->m_pRwClump, m_nAssocGroupId, ANIM_ID_KILL_KNIFE_PED_DIE, 8.0);
            CPedDamageResponseCalculator damageCalculator = CPedDamageResponseCalculator(ped, CPedDamageResponseCalculator::ms_damageFactor, m_pTarget->m_aWeapons[m_pTarget->m_nActiveWeaponSlot].m_nType, PED_PIECE_TORSO, false);

            int pedFlag = (ped->m_nPedFlags >> 8) & 0xFFFFFF01;
            CEventDamage eventDamage = CEventDamage(m_pTarget, CTimer::m_snTimeInMilliseconds, m_pTarget->m_aWeapons[m_pTarget->m_nActiveWeaponSlot].m_nType, PED_PIECE_TORSO, 0, 0, pedFlag);
            if (eventDamage.AffectsPed(ped))
            {
                CPedDamageResponse damageResponse;
                damageCalculator.ComputeDamageResponse(ped, &damageResponse, true);

                // Got no clue what these are and what role they really has

                //v13 = m_nAssocGroupId;
                //v14 = 350;
                //v15 = 0x41000000;
                //v16 = 0x3F800000;
                //v12 |= 4u;

                ped->m_pIntelligence->m_eventGroup.Add(&eventDamage, 0);
            }
            eventDamage.~CEventDamage();
            damageCalculator.~CPedDamageResponseCalculator();
        }
        else
        {
            m_pAnim = CAnimManager::BlendAnimation(ped->m_pRwClump, m_nAssocGroupId, ANIM_ID_KILL_KNIFE_PED_DAMAGE, 8.0);
        }
        m_pAnim->SetFinishCallback(CTaskSimpleStealthKill::FinishAnimStealthKillCB, this);
        m_bIsFinished = true;
    }
    else
    {
        float timer = CTimer::ms_fTimeStep * 0.02 * 1000.0;
        m_nTime += timer;
        if (timer > 10000)
            m_bIsAborting = true;
    }
#endif
}
#undef USE_DEFAULT_FUNCTIONS

void CTaskSimpleStealthKill::FinishAnimStealthKillCB(CAnimBlendAssociation* pAnimAssoc, void* something)
{
    return ((void(__cdecl*)(CAnimBlendAssociation*, void*))0x622790)(pAnimAssoc, something);
}
