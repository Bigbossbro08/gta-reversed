#pragma once
#include "CTaskSimple.h"
#include "CTaskTimer.h"

class CTaskSimplePause : public CTaskSimple 
{
public:
    CTaskTimer m_timer;
    int m_nTime;

    static void InjectHooks();
    CTaskSimplePause(int time);
    ~CTaskSimplePause();
private:
    CTaskSimplePause* Constructor(int time);
public:
    eTaskType GetId() override { return TASK_SIMPLE_PAUSE; };
    CTask* Clone_Reversed();
    CTask* Clone() override;
    bool MakeAbortable(CPed* ped, eAbortPriority priority, CEvent* _event) override;
    bool MakeAbortable_Reversed(CPed* ped, eAbortPriority priority, CEvent* _event);
    bool ProcessPed(CPed* ped) override;
    bool ProcessPed_Reversed(CPed* ped);
};

VALIDATE_SIZE(CTaskSimplePause, 0x18);
