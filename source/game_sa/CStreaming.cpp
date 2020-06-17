#include "StdInc.h"

unsigned int& CStreaming::ms_memoryAvailable = *reinterpret_cast<unsigned int*>(0x8A5A80);
int& CStreaming::desiredNumVehiclesLoaded = *reinterpret_cast<int*>(0x8A5A84);
bool& CStreaming::ms_bLoadVehiclesInLoadScene = *reinterpret_cast<bool*>(0x8A5A88);
int* CStreaming::ms_aDefaultCopCarModel = reinterpret_cast<int*>(0x8A5A8C);
int& CStreaming::ms_DefaultCopBikeModel = *reinterpret_cast<int*>(0x8A5A9C);
int* CStreaming::ms_aDefaultCopModel = reinterpret_cast<int*>(0x8A5AA0);
int& CStreaming::ms_DefaultCopBikerModel = *reinterpret_cast<int*>(0x8A5AB0);
std::uint32_t& CStreaming::ms_nTimePassedSinceLastCopBikeStreamedIn = *reinterpret_cast<std::uint32_t*>(0x9654C0);
signed int* CStreaming::ms_aDefaultAmbulanceModel = reinterpret_cast<signed int*>(0x8A5AB4);
signed int* CStreaming::ms_aDefaultMedicModel = reinterpret_cast<signed int*>(0x8A5AC4);
signed int* CStreaming::ms_aDefaultFireEngineModel = reinterpret_cast<signed int*>(0x8A5AD4);
signed int* CStreaming::ms_aDefaultFiremanModel = reinterpret_cast<signed int*>(0x8A5AE4);
CDirectory*& CStreaming::ms_pExtraObjectsDir = *reinterpret_cast<CDirectory**>(0x8E48D0);
tStreamingFileDesc* CStreaming::ms_files = reinterpret_cast<tStreamingFileDesc*>(0x8E48D8);
bool& CStreaming::ms_bLoadingBigModel = *reinterpret_cast<bool*>(0x8E4A58);
// There are only two channels within CStreaming::ms_channel
tStreamingChannel* CStreaming::ms_channel = reinterpret_cast<tStreamingChannel*>(0x8E4A60);
signed int& CStreaming::ms_channelError = *reinterpret_cast<signed int*>(0x8E4B90);
bool& CStreaming::m_bHarvesterModelsRequested = *reinterpret_cast<bool*>(0x8E4B9C);
bool& CStreaming::m_bStreamHarvesterModelsThisFrame = *reinterpret_cast<bool*>(0x8E4B9D);
unsigned int& CStreaming::ms_numPriorityRequests = *reinterpret_cast<unsigned int*>(0x8E4BA0);
int& CStreaming::ms_lastCullZone = *reinterpret_cast<int*>(0x8E4BA4);
unsigned short& CStreaming::ms_loadedGangCars = *reinterpret_cast<unsigned short*>(0x8E4BA8);
unsigned short& CStreaming::ms_loadedGangs = *reinterpret_cast<unsigned short*>(0x8E4BAC);
int& CStreaming::ms_numPedsLoaded = *reinterpret_cast<int*>(0x8E4BB0);
int* CStreaming::ms_pedsLoaded = reinterpret_cast<int*>(0x8E4C00);
std::int32_t* CStreaming::ms_NextPedToLoadFromGroup = reinterpret_cast<std::int32_t*>(0x8E4BB8);
int& CStreaming::ms_currentZoneType = *reinterpret_cast<int*>(0x8E4C20);
CLoadedCarGroup& CStreaming::ms_vehiclesLoaded = *reinterpret_cast<CLoadedCarGroup*>(0x8E4C24);
CStreamingInfo*& CStreaming::ms_pEndRequestedList = *reinterpret_cast<CStreamingInfo**>(0x8E4C54);
CStreamingInfo*& CStreaming::ms_pStartRequestedList = *reinterpret_cast<CStreamingInfo**>(0x8E4C58);
CStreamingInfo*& CStreaming::ms_pEndLoadedList = *reinterpret_cast<CStreamingInfo**>(0x8E4C5C);
CStreamingInfo*& CStreaming::ms_startLoadedList = *reinterpret_cast<CStreamingInfo**>(0x8E4C60);
int& CStreaming::ms_lastImageRead = *reinterpret_cast<int*>(0x8E4C64);
signed int* CStreaming::ms_imageOffsets = reinterpret_cast<signed int*>(0x8E4C8C);
bool& CStreaming::ms_bEnableRequestListPurge = *reinterpret_cast<bool*>(0x8E4CA4);
unsigned int& CStreaming::ms_streamingBufferSize = *reinterpret_cast<unsigned int*>(0x8E4CA8);
std::uint8_t** CStreaming::ms_pStreamingBuffer = reinterpret_cast<std::uint8_t**>(0x8E4CAC);
unsigned int& CStreaming::ms_memoryUsed = *reinterpret_cast<unsigned int*>(0x8E4CB4);
int& CStreaming::ms_numModelsRequested = *reinterpret_cast<int*>(0x8E4CB8);
CStreamingInfo* CStreaming::ms_aInfoForModel = reinterpret_cast<CStreamingInfo*>(0x8E4CC0);
bool& CStreaming::ms_disableStreaming = *reinterpret_cast<bool*>(0x9654B0);
int& CStreaming::ms_bIsInitialised = *reinterpret_cast<int*>(0x9654B8);
bool& CStreaming::m_bBoatsNeeded = *reinterpret_cast<bool*>(0x9654BC);
bool& CStreaming::ms_bLoadingScene = *reinterpret_cast<bool*>(0x9654BD);
bool& CStreaming::m_bCopBikeLoaded = *reinterpret_cast<bool*>(0x9654BE);
bool& CStreaming::m_bDisableCopBikes = *reinterpret_cast<bool*>(0x9654BF);
CLinkList<CEntity*>& CStreaming::ms_rwObjectInstances = *reinterpret_cast<CLinkList<CEntity*>*>(0x9654F0);
CLink<CEntity*>*& CStreaming::ms_renderEntityLink = *reinterpret_cast<CLink<CEntity*>**>(0x8E48A0);
RwStream& gRwStream = *reinterpret_cast<RwStream*>(0x8E48AC);
bool& CStreaming::m_bLoadingAllRequestedModels = *reinterpret_cast<bool*>(0x965538);
bool& CStreaming::m_bModelStreamNotLoaded = *reinterpret_cast<bool*>(0x9654C4);
static std::int32_t& CurrentGangMemberToLoad = *(std::int32_t*)0x9654D4;

void CStreaming::InjectHooks()
{
    //CStreamingInfo::InjectHooks(); 
    HookInstall(0x409650, &CStreaming::AddEntity);
    HookInstall(0x407610, &CStreaming::AddImageToList);
    HookInstall(0x40C520, &CStreaming::AddLodsToRequestList);
    HookInstall(0x40D3F0, &CStreaming::AddModelsToRequestList);
    HookInstall(0x407AD0, &CStreaming::AreAnimsUsedByRequestedModels);
    HookInstall(0x409A90, &CStreaming::AreTexturesUsedByRequestedModels);
    HookInstall(0x407A40, &CStreaming::ClearFlagForAll);
    HookInstall(0x40BAA0, &CStreaming::ClearSlots);
    HookInstall(0x408E20, &CStreaming::GetNextFileOnCd);
    HookInstall(0x407F00, &CStreaming::HasSpecialCharLoaded);
    HookInstall(0x407820, &CStreaming::HasVehicleUpgradeLoaded);
    HookInstall(0x40C6B0, &CStreaming::ConvertBufferToObject);
    HookInstall(0x4090A0, &CStreaming::DeleteAllRwObjects);
    HookInstall(0x409760, &CStreaming::DeleteLeastUsedEntityRwObject);
    HookInstall(0x409210, &CStreaming::DeleteRwObjectsAfterDeath);
    HookInstall(0x40D7C0, &CStreaming::DeleteRwObjectsBehindCamera);
    HookInstall(0x409940, &CStreaming::DeleteRwObjectsBehindCameraInSectorList);
    HookInstall(0x407A70, &CStreaming::DeleteRwObjectsInSectorList);
    HookInstall(0x4099E0, &CStreaming::DeleteRwObjectsNotInFrustumInSectorList);
    HookInstall(0x40D2F0, &CStreaming::RemoveReferencedTxds);
    HookInstall(0x407D10, &CStreaming::DisableCopBikes);
    HookInstall(0x4076A0, &CStreaming::IsVeryBusy);
    HookInstall(0x5D29E0, &CStreaming::Load);
    HookInstall(0x40EA10, &CStreaming::LoadAllRequestedModels);
    HookInstall(0x5B6170, (void(*)(const char*, std::int32_t)) & CStreaming::LoadCdDirectory);
    HookInstall(0x5B82C0, (void(*)()) & CStreaming::LoadCdDirectory);
    HookInstall(0x40D3D0, &CStreaming::LoadInitialPeds);
    HookInstall(0x40A120, &CStreaming::LoadInitialWeapons);
    HookInstall(0x40EB70, &CStreaming::LoadScene);
    HookInstall(0x40ED80, &CStreaming::LoadSceneCollision);
    HookInstall(0x40B4B0, &CStreaming::LoadZoneVehicle);
    HookInstall(0x40BA70, &CStreaming::PossiblyStreamCarOutAfterCreation);
    HookInstall(0x4096D0, &CStreaming::RenderEntity);
    HookInstall(0x409430, &CStreaming::RequestBigBuildings);
    HookInstall(0x40A080, &CStreaming::RequestFile);
    HookInstall(0x409050, &CStreaming::RequestFilesInChannel);
    HookInstall(0x4087E0, &CStreaming::RequestModel);
    HookInstall(0x407100, &CStreaming::RequestTxdModel);
    HookInstall(0x408C70, &CStreaming::RequestVehicleUpgrade);
    HookInstall(0x407FB0, &CStreaming::FindMIPedSlotForInterior);
    HookInstall(0x408CB0, &CStreaming::FinishLoadingLargeFile);
    HookInstall(0x40E460, &CStreaming::FlushChannels);
    HookInstall(0x40CBA0, &CStreaming::RequestModelStream);
    HookInstall(0x40B450, &CStreaming::RequestSpecialChar);
    HookInstall(0x409D10, &CStreaming::RequestSpecialModel);
    HookInstall(0x40E170, &CStreaming::ProcessLoadingChannel);
    HookInstall(0x40C1E0, &CStreaming::PurgeRequestList);
    HookInstall(0x40E560, &CStreaming::ReInit);
    HookInstall(0x5BCCD0, &CStreaming::ReadIniFile);
    HookInstall(0x40AFA0, &CStreaming::ReclassifyLoadedCars);
    HookInstall(0x40CF80, &CStreaming::RemoveAllUnusedModels);
    HookInstall(0x4093B0, &CStreaming::RemoveBigBuildings);
    HookInstall(0x4094B0, &CStreaming::RemoveBuildingsNotInArea);
    HookInstall(0x4080F0, &CStreaming::RemoveCarModel);
    HookInstall(0x40B080, &CStreaming::RemoveCurrentZonesModels);
    HookInstall(0x40BE60, &CStreaming::RemoveDodgyPedsFromRandomSlots);
    HookInstall(0x409710, &CStreaming::RemoveEntity);
    HookInstall(0x40B3A0, &CStreaming::RemoveInappropriatePedModels);
    HookInstall(0x40CFD0, &CStreaming::RemoveLeastUsedModel);
    HookInstall(0x40C020, &CStreaming::RemoveLoadedVehicle);
    HookInstall(0x40B340, &CStreaming::RemoveLoadedZoneModel);
    HookInstall(0x4089A0, &CStreaming::RemoveModel);
    HookInstall(0x40C180, &CStreaming::RemoveTxdModel);
    HookInstall(0x40E120, &CStreaming::MakeSpaceFor);
    HookInstall(0x40C270, (void(*)(CPtrList&, float, float, float, float, float, float, float, std::int32_t)) & CStreaming::ProcessEntitiesInSectorList);
    HookInstall(0x4076C0, &CStreaming::RetryLoadFile);
    HookInstall(0x40E3A0, &CStreaming::LoadRequestedModels);
    HookInstall(0x40E4E0, &CStreaming::FlushRequestList);
    HookInstall(0x408000, &CStreaming::AddToLoadedVehiclesList);
    HookInstall(0x407D50, &CStreaming::GetDefaultCabDriverModel);
    HookInstall(0x407D40, &CStreaming::GetDefaultFiremanModel);
    HookInstall(0x407D20, &CStreaming::GetDefaultMedicModel);
    HookInstall(0x407C50, &CStreaming::GetDefaultCopCarModel);
    HookInstall(0x407C00, &CStreaming::GetDefaultCopModel);
    HookInstall(0x5B8AD0, &CStreaming::Init2);
    HookInstall(0x4083C0, &CStreaming::InitImageList);
    HookInstall(0x4084F0, &CStreaming::InstanceLoadedModels);
    HookInstall(0x407DD0, &CStreaming::IsCarModelNeededInCurrentZone);
    HookInstall(0x409C90, &CStreaming::SetMissionDoesntRequireModel);
    HookInstall(0x409C10, &CStreaming::SetModelIsDeletable);
    HookInstall(0x4084B0, &CStreaming::Shutdown);
    HookInstall(0x40A2A0, &CStreaming::StreamAmbulanceAndMedic);
    HookInstall(0x40A150, &CStreaming::StreamCopModels);
    HookInstall(0x40A400, &CStreaming::StreamFireEngineAndFireman);
    HookInstall(0x40B4F0, &CStreaming::StreamOneNewCar);
    HookInstall(0x40BBB0, &CStreaming::StreamPedsForInterior);
    HookInstall(0x40BDA0, &CStreaming::StreamPedsIntoRandomSlots);
    HookInstall(0x40B700, &CStreaming::StreamVehiclesAndPeds);
    HookInstall(0x40B650, &CStreaming::StreamVehiclesAndPeds_Always);
    HookInstall(0x40A560, &CStreaming::StreamZoneModels);
    HookInstall(0x40AA10, &CStreaming::StreamZoneModels_Gangs);
    HookInstall(0x40E670, &CStreaming::Update);
    HookInstall(0x407F80, &CStreaming::WeAreTryingToPhaseVehicleOut);
}

void* CStreaming::AddEntity(CEntity* pEntity) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<void*, CEntity*>(0x409650, pEntity);
#else
    if (pEntity->m_nType == ENTITY_TYPE_PED || pEntity->m_nType == ENTITY_TYPE_VEHICLE)
        return nullptr;
    CLink<CEntity*>* link = ms_rwObjectInstances.Insert(pEntity);
    if (!link) {
        CLink<CEntity*>* previousLink = ms_rwObjectInstances.usedListTail.prev;
        for (; previousLink != &ms_rwObjectInstances.usedListHead; previousLink = previousLink->prev) {
            CEntity* entity = previousLink->data;
            if (!entity->m_bImBeingRendered && !entity->m_bStreamingDontDelete)
                break;
        }
        if (previousLink == &ms_rwObjectInstances.usedListHead)
            return ms_rwObjectInstances.Insert(pEntity);
        previousLink->data->DeleteRwObject();
        link = ms_rwObjectInstances.Insert(pEntity);
    }
    return link;
#endif
}

int CStreaming::AddImageToList(char const* pFileName, bool bNotPlayerImg) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int, char const*, bool>(0x407610, pFileName, bNotPlayerImg);
#else
    // find a free slot
    std::int32_t fileIndex = 0;
    for (; fileIndex < TOTAL_IMG_ARCHIVES; fileIndex++) {
        if (!ms_files[fileIndex].m_szName[0])
            break;
    }
    if (fileIndex == TOTAL_IMG_ARCHIVES)
        return 0;
    // free slot found, load the IMG file
    strcpy(ms_files[fileIndex].m_szName, pFileName);
    ms_files[fileIndex].m_StreamHandle = CdStreamOpen(pFileName);
    ms_files[fileIndex].m_bNotPlayerImg = bNotPlayerImg;
    return fileIndex;
#endif
}

void CStreaming::AddLodsToRequestList(CVector const& point, unsigned int streamingFlags) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&, unsigned int>(0x40C520, point, streamingFlags);
#else
    CWorld::IncrementCurrentScanCode();
    float minX = point.x - CRenderer::ms_fFarClipPlane;
    float maxX = point.x + CRenderer::ms_fFarClipPlane;
    float minY = point.y - CRenderer::ms_fFarClipPlane;
    float maxY = point.y + CRenderer::ms_fFarClipPlane;
    std::int32_t startSectorX = std::max(CWorld::GetLodSectorX(minX), 0);
    std::int32_t startSectorY = std::max(CWorld::GetLodSectorY(minY), 0);
    std::int32_t endSectorX = std::min(CWorld::GetLodSectorX(maxX), MAX_LOD_PTR_LISTS_X - 1);
    std::int32_t endSectorY = std::min(CWorld::GetLodSectorY(maxY), MAX_LOD_PTR_LISTS_Y - 1);
    for (std::int32_t sectorY = startSectorY; sectorY <= endSectorY; ++sectorY) {
        for (std::int32_t sectorX = startSectorX; sectorX <= endSectorX; ++sectorX) {
            CPtrList& lodList = CWorld::GetLodPtrList(sectorX, sectorY);
            ProcessEntitiesInSectorList(lodList, point.x, point.y, minX, minY, maxX, maxY, CRenderer::ms_fFarClipPlane, streamingFlags);
        }
    }
#endif
}

void CStreaming::AddModelsToRequestList(CVector const& point, unsigned int streamingFlags) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&, unsigned int>(0x40D3F0, point, streamingFlags);
#else
    float fRadius = 80.0f;
    if (CGame::currArea)
        fRadius = 40.0f;
    CWorld::IncrementCurrentScanCode();
    const float minX = point.x - fRadius;
    const float maxX = point.x + fRadius;
    const float minY = point.y - fRadius;
    const float maxY = point.y + fRadius;
    const std::int32_t radius = static_cast<std::int32_t>(CWorld::GetHalfMapSectorX(fRadius));
    const std::int32_t squaredRadius1 = (radius - 1) * (radius - 1);
    const std::int32_t squaredRadius2 = (radius + 2) * (radius + 2);
    const std::int32_t pointX = CWorld::GetSectorX(point.x);
    const std::int32_t pointY = CWorld::GetSectorY(point.y);
    std::int32_t startSectorX = std::max(CWorld::GetSectorX(minX), 0);
    std::int32_t startSectorY = std::max(CWorld::GetSectorY(minY), 0);
    std::int32_t endSectorX = std::min(CWorld::GetSectorX(maxX), MAX_SECTORS_X - 1);
    std::int32_t endSectorY = std::min(CWorld::GetSectorY(maxY), MAX_SECTORS_Y - 1);
    for (std::int32_t sectorY = startSectorY; sectorY <= endSectorY; ++sectorY) {
        const std::int32_t distanceY = sectorY - pointY;
        const std::int32_t squaredDistanceY = distanceY * distanceY;
        for (std::int32_t sectorX = startSectorX; sectorX <= endSectorX; ++sectorX) {
            CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
            CSector* pSector = GetSector(sectorX, sectorY);
            const std::int32_t distanceX = sectorX - pointX;
            const std::int32_t dotProduct = distanceX * distanceX + squaredDistanceY;
            if (dotProduct > squaredRadius1) {
                if (dotProduct <= squaredRadius2) {
                    ProcessEntitiesInSectorList(pSector->m_buildings, point.x, point.y, minX, minY, maxX, maxY, fRadius, streamingFlags);
                    ProcessEntitiesInSectorList(pRepeatSector->m_lists[REPEATSECTOR_PEDS], point.x, point.y, minX, minY, maxX, maxY, fRadius, streamingFlags);
                    ProcessEntitiesInSectorList(pSector->m_dummies, point.x, point.y, minX, minY, maxX, maxY, fRadius, streamingFlags);
                }
            }
            else {
                ProcessEntitiesInSectorList(pSector->m_buildings, streamingFlags);
                ProcessEntitiesInSectorList(pRepeatSector->m_lists[REPEATSECTOR_PEDS], streamingFlags);
                ProcessEntitiesInSectorList(pSector->m_dummies, streamingFlags);
            }
        }
    }
#endif
}

bool CStreaming::AreAnimsUsedByRequestedModels(int animModelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, int>(0x407AD0, animModelId);
#else
    auto pStreamingInfo = ms_pStartRequestedList->GetNext();
    for (; pStreamingInfo != ms_pEndRequestedList; pStreamingInfo = pStreamingInfo->GetNext()) {
        int modelId = pStreamingInfo - ms_aInfoForModel;
        if (modelId < RESOURCE_ID_TXD && CModelInfo::ms_modelInfoPtrs[modelId]->GetAnimFileIndex() == animModelId)
            return true;
    }
    if (pStreamingInfo == ms_pEndRequestedList) {
        for (int i = 0; i < 16; i++) {
            for (int channelId = 0; channelId < 2; channelId++) {
                int modelId = ms_channel[channelId].modelIds[i];
                if (modelId != -1 && modelId < RESOURCE_ID_TXD &&
                    CModelInfo::ms_modelInfoPtrs[modelId]->GetAnimFileIndex() == animModelId)
                {
                    return true;
                }
            }
        }
    }
    return false;
#endif
}

bool CStreaming::AreTexturesUsedByRequestedModels(int txdModelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, int>(0x409A90, txdModelId);
#else
    auto pStreamingInfo = ms_pStartRequestedList->GetNext();
    for (; pStreamingInfo != ms_pEndRequestedList; pStreamingInfo = pStreamingInfo->GetNext()) {
        int modelId = pStreamingInfo - ms_aInfoForModel;
        if (modelId < RESOURCE_ID_TXD) {
            if (CModelInfo::ms_modelInfoPtrs[modelId]->m_nTxdIndex == txdModelId)
                return true;
        }
        else if (modelId < RESOURCE_ID_COL) {
            if (CTxdStore::GetParentTxdSlot(modelId - RESOURCE_ID_TXD) == txdModelId)
                return true;
        }
    }
    if (pStreamingInfo == ms_pEndRequestedList) {
        for (int i = 0; i < 16; i++) {
            for (int channelId = 0; channelId < 2; channelId++) {
                int modelId = ms_channel[channelId].modelIds[i];
                if (modelId != -1) {
                    if (modelId < RESOURCE_ID_TXD) {
                        if (CModelInfo::ms_modelInfoPtrs[modelId]->m_nTxdIndex == txdModelId)
                            return true;
                    }
                    else if (modelId < RESOURCE_ID_COL) {
                        if (CTxdStore::GetParentTxdSlot(modelId - RESOURCE_ID_TXD) == txdModelId)
                            return true;
                    }
                }
            }
        }
    }
    return false;
#endif
}

void CStreaming::ClearFlagForAll(unsigned int streamingFlag) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<unsigned int>(0x407A40, streamingFlag);
#else
    for (std::int32_t i = 0; i < RESOURCE_ID_TOTAL; i++) {
        CStreamingInfo& streamingInfo = ms_aInfoForModel[i];
        streamingInfo.m_nFlags &= ~streamingFlag;
    }
#endif
}

void CStreaming::ClearSlots(int totalSlots) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40BAA0, totalSlots);
#else
    for (std::int32_t i = 0; i < totalSlots; ++i) {
        std::int32_t modelId = ms_pedsLoaded[i];
        if (modelId >= 0) {
            SetModelIsDeletable(modelId);
            SetModelTxdIsDeletable(modelId);
            ms_pedsLoaded[i] = -1;
            ms_numPedsLoaded--;
        }
    }
#endif
}

int CStreaming::GetNextFileOnCd(unsigned int streamLastPosn, bool bNotPriority) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int, int, bool>(0x408E20, streamLastPosn, bNotPriority);
#else
    unsigned int nextRequestModelPos = UINT_MAX;
    unsigned int firstRequestModelPos = UINT_MAX;
    int firstRequestModelId = -1;
    int nextRequestModelId = -1;
    auto pStreamingInfo = ms_pStartRequestedList->GetNext();
    for (; pStreamingInfo != ms_pEndRequestedList; pStreamingInfo = pStreamingInfo->GetNext())
    {
        int modelId = pStreamingInfo - ms_aInfoForModel;
        if (!bNotPriority || !ms_numPriorityRequests || pStreamingInfo->m_nFlags & STREAMING_PRIORITY_REQUEST) {
            if (modelId < RESOURCE_ID_TXD) {
                CBaseModelInfo* pModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
                short txdIndex = pModelInfo->m_nTxdIndex;
                unsigned char txdLoadState = ms_aInfoForModel[txdIndex + RESOURCE_ID_TXD].m_nLoadState;
                if (txdLoadState != LOADSTATE_LOADED && txdLoadState != LOADSTATE_CHANNELED) {
                    RequestModel(txdIndex + RESOURCE_ID_TXD, ms_aInfoForModel[modelId].m_nFlags);
                    continue;
                }
                int animFileIndex = pModelInfo->GetAnimFileIndex();
                if (animFileIndex != -1) {
                    int animModelId = animFileIndex + RESOURCE_ID_IFP;
                    unsigned char animLoadState = ms_aInfoForModel[animModelId].m_nLoadState;
                    if (animLoadState != LOADSTATE_LOADED && animLoadState != LOADSTATE_CHANNELED) {
                        RequestModel(animModelId, STREAMING_KEEP_IN_MEMORY);
                        continue;
                    }
                }
            }
            else if (modelId < RESOURCE_ID_COL) {
                TxdDef* pTexDictionary = CTxdStore::ms_pTxdPool->GetAt(modelId - RESOURCE_ID_TXD);
                short parentIndex = pTexDictionary->m_wParentIndex;
                if (parentIndex != -1) {
                    int txdModelId = parentIndex + RESOURCE_ID_TXD;
                    unsigned char loadState = ms_aInfoForModel[txdModelId].m_nLoadState;
                    if (loadState != LOADSTATE_LOADED && loadState != LOADSTATE_CHANNELED) {
                        RequestModel(txdModelId, STREAMING_KEEP_IN_MEMORY);
                        continue;
                    }
                }
            }
            else if ((modelId >= RESOURCE_ID_IFP && modelId < RESOURCE_ID_RRR)
                && (CCutsceneMgr::ms_cutsceneProcessing || ms_aInfoForModel[MODEL_MALE01].m_nLoadState != LOADSTATE_LOADED))
            {
                continue;
            }
            const unsigned int modelPos = ms_aInfoForModel[modelId].GetCdPosn();
            if (modelPos < firstRequestModelPos) {
                firstRequestModelPos = modelPos;
                firstRequestModelId = pStreamingInfo - ms_aInfoForModel;
            }
            if (modelPos < nextRequestModelPos && modelPos >= streamLastPosn) {
                nextRequestModelPos = modelPos;
                nextRequestModelId = pStreamingInfo - ms_aInfoForModel;
            }
        }
    }
    int nextModelId = nextRequestModelId;
    if (nextModelId == -1)
        nextModelId = firstRequestModelId;
    if (nextModelId != -1 || !ms_numPriorityRequests)
        return nextModelId;
    ms_numPriorityRequests = 0;
    return nextModelId;
#endif
}

bool CStreaming::HasSpecialCharLoaded(std::int32_t slot)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, std::int32_t>(0x407F00, slot);
#else
    return ms_aInfoForModel[slot + SPECIAL_MODELS_RESOURCE_ID].m_nLoadState == LOADSTATE_LOADED;
#endif
}

bool CStreaming::HasVehicleUpgradeLoaded(std::int32_t modelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, std::int32_t>(0x407820, modelId);
#else
    if (ms_aInfoForModel[modelId].m_nLoadState != LOADSTATE_LOADED)
        return false;
    std::int16_t otherUpgradeModelId = CVehicleModelInfo::ms_linkedUpgrades.FindOtherUpgrade(modelId);
    if(otherUpgradeModelId == -1)
        return false;
    return ms_aInfoForModel[otherUpgradeModelId].m_nLoadState == LOADSTATE_LOADED;
#endif
}

bool CStreaming::ConvertBufferToObject(unsigned char* pFileBuffer, int modelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, unsigned char*, int >(0x40C6B0, pFileBuffer, modelId);
#else
    CStreamingInfo* pStartLoadedListStreamingInfo = ms_startLoadedList;;
    CBaseModelInfo* pBaseModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
    CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];

    unsigned int bufferSize = streamingInfo.m_nCdSize * STREAMING_SECTOR_SIZE;
    tRwStreamInitializeData rwStreamInitializationData = { pFileBuffer, bufferSize };

    RwStream* pRwStream = _rwStreamInitialize(&gRwStream, 0, rwSTREAMMEMORY, rwSTREAMREAD, &rwStreamInitializationData);

    if (modelId >= RESOURCE_ID_DFF && modelId < RESOURCE_ID_TXD) {
        int animFileIndex = pBaseModelInfo->GetAnimFileIndex();
        short wTxdIndex = pBaseModelInfo->m_nTxdIndex;
        TxdDef* pTxdDef = CTxdStore::ms_pTxdPool->GetAt(wTxdIndex);
        if ((pTxdDef && !pTxdDef->m_pRwDictionary) || animFileIndex != -1 && !CAnimManager::ms_aAnimBlocks[animFileIndex].bLoaded)
        {
            RemoveModel(modelId);
            RequestModel(modelId, streamingInfo.m_nFlags);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }

        CTxdStore::AddRef(wTxdIndex);
        if (animFileIndex != -1)
            CAnimManager::AddAnimBlockRef(animFileIndex);
        CTxdStore::SetCurrentTxd(pBaseModelInfo->m_nTxdIndex);

        bool bFileLoaded = false;
        if (pBaseModelInfo->GetRwModelType() == RWMODEL_INFO_ATOMIC) {
            RtDict* pRtDictionary = nullptr;
            RwChunkHeaderInfo chunkHeaderInfo;
            RwStreamReadChunkHeaderInfo(pRwStream, &chunkHeaderInfo);
            if (chunkHeaderInfo.type == rwID_UVANIMDICT) {
                pRtDictionary = RtDictSchemaStreamReadDict(&RpUVAnimDictSchema, pRwStream);
                RtDictSchemaSetCurrentDict(&RpUVAnimDictSchema, pRtDictionary);
            }
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            RwStream* pRwStream2 = _rwStreamInitialize(&gRwStream, 0, rwSTREAMMEMORY, rwSTREAMREAD, &rwStreamInitializationData);
            bFileLoaded = CFileLoader::LoadAtomicFile(pRwStream2, modelId);
            if (pRtDictionary)
            {
                RtDictDestroy(pRtDictionary);
            }
        }
        else
        {
            bFileLoaded = CFileLoader::LoadClumpFile(pRwStream, modelId);
        }
        if (streamingInfo.m_nLoadState != LOADSTATE_FINISHING)
        {
            CTxdStore::RemoveRefWithoutDelete(pBaseModelInfo->m_nTxdIndex);
            if (animFileIndex != -1)
            {
                CAnimManager::RemoveAnimBlockRefWithoutDelete(animFileIndex);
            }

            if (bFileLoaded && pBaseModelInfo->GetModelType() == MODEL_INFO_VEHICLE)
            {
                if (!AddToLoadedVehiclesList(modelId))
                {
                    RemoveModel(modelId);
                    RequestModel(modelId, streamingInfo.m_nFlags);
                    RwStreamClose(pRwStream, &rwStreamInitializationData);
                    return false;
                }
            }
        }
        if (!bFileLoaded)
        {
            RemoveModel(modelId);
            RequestModel(modelId, streamingInfo.m_nFlags);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }
       
    }
    else if (modelId >= RESOURCE_ID_TXD && modelId < RESOURCE_ID_COL) {
        int modelTxdIndex = modelId - RESOURCE_ID_TXD;
        TxdDef* pTxdDef = CTxdStore::ms_pTxdPool->GetAt(modelTxdIndex);
        if (pTxdDef) {
            int txdIndex = pTxdDef->m_wParentIndex;
            if (txdIndex != -1 && !CTxdStore::GetTxd(txdIndex)) {
                RemoveModel(modelId);
                RequestModel(modelId, streamingInfo.m_nFlags);
                RwStreamClose(pRwStream, &rwStreamInitializationData);
                return false;
            }
        }

        if (!(streamingInfo.m_nFlags & (STREAMING_KEEP_IN_MEMORY | STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))
            && !AreTexturesUsedByRequestedModels(modelTxdIndex))
        {
            RemoveModel(modelId);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }

        bool bTxdLoaded = false;
        if (ms_bLoadingBigModel) {
            bTxdLoaded = CTxdStore::StartLoadTxd(modelTxdIndex, pRwStream);
            if (bTxdLoaded)
                streamingInfo.m_nLoadState = LOADSTATE_FINISHING;
        }
        else {
            bTxdLoaded = CTxdStore::LoadTxd(modelTxdIndex, pRwStream);
        }
        if (!bTxdLoaded) {
            RemoveModel(modelId);
            RequestModel(modelId, streamingInfo.m_nFlags);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }
    }
    else if (modelId >= RESOURCE_ID_COL && modelId < RESOURCE_ID_IPL) {
        if (!CColStore::LoadCol(modelId - RESOURCE_ID_COL, pFileBuffer, bufferSize)) {
            RemoveModel(modelId);
            RequestModel(modelId, streamingInfo.m_nFlags);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }
    }
    else if (modelId >= RESOURCE_ID_IPL && modelId < RESOURCE_ID_DAT) {
        if (!CIplStore::LoadIpl(modelId - RESOURCE_ID_IPL, pFileBuffer, bufferSize)) {
            RemoveModel(modelId);
            RequestModel(modelId, streamingInfo.m_nFlags);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }
    }
    else if (modelId >= RESOURCE_ID_DAT && modelId < RESOURCE_ID_IFP) {
        ThePaths.LoadPathFindData(pRwStream, modelId - RESOURCE_ID_DAT);
    }
    else if (modelId >= RESOURCE_ID_IFP && modelId < RESOURCE_ID_RRR) {
        if (!(streamingInfo.m_nFlags & (STREAMING_KEEP_IN_MEMORY | STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))
            && !AreAnimsUsedByRequestedModels(modelId - RESOURCE_ID_IFP))
        {
            RemoveModel(modelId);
            RwStreamClose(pRwStream, &rwStreamInitializationData);
            return false;
        }
        CAnimManager::LoadAnimFile(pRwStream, true, 0);
        CAnimManager::CreateAnimAssocGroups();
    }
    else if (modelId >= RESOURCE_ID_RRR && modelId < RESOURCE_ID_SCM) {
        CVehicleRecording::Load(pRwStream, modelId - RESOURCE_ID_RRR, bufferSize);
    }
    else if (modelId >= RESOURCE_ID_SCM) {
        CStreamedScripts& pStreamedScripts = CTheScripts::StreamedScripts;
        pStreamedScripts.LoadStreamedScript(pRwStream, modelId - RESOURCE_ID_SCM);
    }
    RwStreamClose(pRwStream, &rwStreamInitializationData);
    if (modelId >= RESOURCE_ID_TXD) {
        if (!(modelId >= RESOURCE_ID_COL && (modelId < RESOURCE_ID_IFP || modelId >= RESOURCE_ID_RRR)
            && modelId < RESOURCE_ID_SCM || streamingInfo.m_nFlags & (STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))) {
            streamingInfo.AddToList(pStartLoadedListStreamingInfo);
        }
    }
    else {
        if (pBaseModelInfo->GetModelType() != MODEL_INFO_VEHICLE && pBaseModelInfo->GetModelType() != MODEL_INFO_PED) {
            CBaseModelInfo* pAsAtomicModelInfo = pBaseModelInfo->AsAtomicModelInfoPtr();
            if (pAsAtomicModelInfo)
                pAsAtomicModelInfo->m_nAlpha = -(streamingInfo.m_nFlags & (STREAMING_LOADING_SCENE | STREAMING_MISSION_REQUIRED));
            if (!(streamingInfo.m_nFlags & (STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED)))
                streamingInfo.AddToList(pStartLoadedListStreamingInfo);
        }
    }

    if (streamingInfo.m_nLoadState != LOADSTATE_FINISHING) {
        streamingInfo.m_nLoadState = LOADSTATE_LOADED;
        ms_memoryUsed += bufferSize;
    }
    return true;
#endif
}

void CStreaming::DeleteAllRwObjects() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x4090A0);
#else
    for (std::int32_t sectorX = 0; sectorX < MAX_SECTORS_X; ++sectorX) {
        for (std::int32_t sectorY = 0; sectorY < MAX_SECTORS_Y; ++sectorY) {
            CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
            CSector* pSector = GetSector(sectorX, sectorY);
            DeleteRwObjectsInSectorList(pSector->m_buildings, -1, -1);
            DeleteRwObjectsInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], -1, -1);
            DeleteRwObjectsInSectorList(pSector->m_dummies, -1, -1);
        }
    }
#endif
}

bool CStreaming::DeleteLeastUsedEntityRwObject(bool bNotOnScreen, unsigned int streamingFlags) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, bool, unsigned int>(0x409760, bNotOnScreen, streamingFlags);
#else
    const float fCameraFarPlane = TheCamera.m_pRwCamera->farPlane;
    CPlayerPed* pPlayer = FindPlayerPed(-1);
    auto previousLink = ms_rwObjectInstances.usedListTail.prev;
    while (previousLink != &ms_rwObjectInstances.usedListHead) {
        CEntity* pEntity = previousLink->data;
        previousLink = previousLink->prev;
        if (!pEntity->m_bImBeingRendered && !pEntity->m_bStreamingDontDelete) {
            const std::int32_t modelId = pEntity->m_nModelIndex;
            auto pBaseModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
            float drawDistanceRadius = TheCamera.m_fLODDistMultiplier * pBaseModelInfo->m_fDrawDistance;
            if (pEntity->m_bIsBIGBuilding)
                drawDistanceRadius *= CRenderer::ms_lowLodDistScale;
            CVector entityPos = pEntity->GetPosition();
            if (pEntity->m_pLod)
                entityPos = pEntity->m_pLod->GetPosition();
            const float fMagnitude = (entityPos - TheCamera.GetPosition()).Magnitude();
            CEntity* pEntityLastLod = pEntity;
            for (CEntity* pEntityLod = pEntity->m_pLod; pEntityLod; pEntityLod = pEntityLod->m_pLod) {
                pEntityLastLod = pEntityLod;
            }
            float fModelRadius = pBaseModelInfo->m_pColModel->m_boundSphere.m_fRadius;
            if (ms_bLoadingScene
                || bNotOnScreen && !pEntityLastLod->GetIsOnScreen()
                || pEntity->m_nAreaCode != CGame::currArea && pEntity->m_nAreaCode != 13
                || drawDistanceRadius + 50.0f < fMagnitude
                || fModelRadius + fCameraFarPlane < fMagnitude)
            {
                CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
                if (streamingInfo.InList() && !(streamingFlags & streamingInfo.m_nFlags)) {
                    if (!pPlayer || pPlayer->bInVehicle || pPlayer->m_pContactEntity != pEntity) {
                        pEntity->DeleteRwObject();
                        if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount) {
                            RemoveModel(modelId);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
#endif
}

void CStreaming::DeleteRwObjectsAfterDeath(CVector const& point) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x409210, point);
#else
    std::int32_t pointX = CWorld::GetSectorX(point.x);
    std::int32_t pointY = CWorld::GetSectorY(point.y);
    for (std::int32_t sectorX = 0; sectorX < MAX_SECTORS_X; ++sectorX) {
        if (fabs(pointX - sectorX) > 3.0f) {
            for (std::int32_t sectorY = 0; sectorY < MAX_SECTORS_Y; ++sectorY) {
                if (fabs(pointY - sectorY) > 3.0f) {
                    CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                    CSector* pSector = GetSector(sectorX, sectorY);
                    DeleteRwObjectsInSectorList(pSector->m_buildings, -1, -1);
                    DeleteRwObjectsInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], -1, -1);
                    DeleteRwObjectsInSectorList(pSector->m_dummies, -1, -1);
                }
            }
        }
    }
#endif
}

void CStreaming::DeleteRwObjectsBehindCamera(std::int32_t memoryToCleanInBytes) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<std::int32_t>(0x40D7C0, memoryToCleanInBytes);
#else
    if (static_cast<std::int32_t>(CStreaming::ms_memoryUsed) < memoryToCleanInBytes)
        return;
    const CVector& cameraPos = TheCamera.GetPosition();
    std::int32_t pointX = CWorld::GetSectorX(cameraPos.x);
    std::int32_t pointY = CWorld::GetSectorY(cameraPos.y);
    const CVector2D& cameraForward = TheCamera.GetForward();
    if (fabs(cameraForward.y) < fabs(cameraForward.x)) {
        std::int32_t sectorStartY = std::max(pointY - 10, 0);
        std::int32_t sectorEndY = std::min(pointY + 10, MAX_SECTORS_Y - 1);
        std::int32_t sectorStartX = 0;
        std::int32_t sectorEndX = 0;
        std::int32_t factorX = 0;
        if (cameraForward.x <= 0.0f) {
            sectorStartX = std::min(pointX + 10, MAX_SECTORS_X - 1);
            sectorEndX = std::min(pointX + 2, MAX_SECTORS_X - 1);
            factorX = -1;
        }
        else {
            sectorStartX = std::max(pointX - 10, 0);
            sectorEndX = std::max(pointX - 2, 0);
            factorX = 1;
        }
        CWorld::IncrementCurrentScanCode();
        for (std::int32_t sectorX = sectorStartX; sectorX != sectorEndX; sectorX += factorX) {
            for (std::int32_t sectorY = sectorStartY; sectorY <= sectorEndY; sectorY++) {
                CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                CSector* pSector = GetSector(sectorX, sectorY);
                if (DeleteRwObjectsBehindCameraInSectorList(pSector->m_buildings, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pSector->m_dummies, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], memoryToCleanInBytes))
                {
                    return;
                }
            }
        }
        if (cameraForward.x <= 0.0f) {
            sectorEndX = std::min(pointX + 2, MAX_SECTORS_X - 1);
            sectorStartX = std::max(pointX - 10, 0);
            factorX = -1;
        }
        else {
            sectorEndX = std::max(pointX - 2, 0);
            sectorStartX = std::min(pointX + 10, MAX_SECTORS_X - 1);
            factorX = 1;
        }
        CWorld::IncrementCurrentScanCode();
        for (std::int32_t sectorX = sectorStartX; sectorX != sectorEndX; sectorX -= factorX) {
            for (std::int32_t sectorY = sectorStartY; sectorY <= sectorEndY; sectorY++) {
                CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                CSector* pSector = GetSector(sectorX, sectorY);
                if (DeleteRwObjectsNotInFrustumInSectorList(pSector->m_buildings, memoryToCleanInBytes) ||
                    DeleteRwObjectsNotInFrustumInSectorList(pSector->m_dummies, memoryToCleanInBytes) ||
                    DeleteRwObjectsNotInFrustumInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], memoryToCleanInBytes))
                {
                    return;
                }
            }
        }
        CWorld::IncrementCurrentScanCode();
        for (std::int32_t sectorX = sectorStartX; sectorX != sectorEndX; sectorX -= factorX) {
            for (std::int32_t sectorY = sectorStartY; sectorY <= sectorEndY; sectorY++) {
                CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                CSector* pSector = GetSector(sectorX, sectorY);
                if (DeleteRwObjectsBehindCameraInSectorList(pSector->m_buildings, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pSector->m_dummies, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], memoryToCleanInBytes))
                {
                    return;
                }
            }
        }
    }
    else {
        std::int32_t sectorStartX = std::max(pointX - 10, 0);
        std::int32_t sectorEndX = std::min(pointX + 10, MAX_SECTORS_X - 1);
        std::int32_t sectorStartY = 0;
        std::int32_t sectorEndY = 0;
        std::int32_t factorY = 0;
        if (cameraForward.y <= 0.0f) {
            sectorEndY = std::min(pointY + 2, MAX_SECTORS_Y - 1);
            sectorStartY = std::min(pointY + 10, MAX_SECTORS_Y - 1);
            factorY = -1;
        }
        else  {
            factorY = 1;
            sectorStartY = std::max(pointY - 10, 0);
            sectorEndY = std::max(pointY - 2, 0);
        }
        CWorld::IncrementCurrentScanCode();
        for (std::int32_t sectorY = sectorStartY; sectorY != sectorEndY; sectorY += factorY) {
            for (std::int32_t sectorX = sectorStartX; sectorX <= sectorEndX; sectorX++) {
                CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                CSector* pSector = GetSector(sectorX, sectorY);
                if (DeleteRwObjectsBehindCameraInSectorList(pSector->m_buildings, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pSector->m_dummies, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], memoryToCleanInBytes))
                {
                    return;
                }
            }
        }
        if (cameraForward.y <= 0.0f) {
            sectorEndY = std::min(pointY + 2, MAX_SECTORS_Y - 1);
            sectorStartY = std::max(pointY - 10, 0);
            factorY = -1;
        }
        else {
            sectorEndY = std::max(pointY - 2, 0);
            sectorStartY = std::min(pointY + 10, MAX_SECTORS_Y - 1);
            factorY = 1;
        }
        CWorld::IncrementCurrentScanCode();
        for (std::int32_t sectorY = sectorStartY; sectorY != sectorEndY; sectorY -= factorY) {
            for (std::int32_t sectorX = sectorStartX; sectorX <= sectorEndX; sectorX++) {
                CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                CSector* pSector = GetSector(sectorX, sectorY);
                if (DeleteRwObjectsNotInFrustumInSectorList(pSector->m_buildings, memoryToCleanInBytes) ||
                    DeleteRwObjectsNotInFrustumInSectorList(pSector->m_dummies, memoryToCleanInBytes) ||
                    DeleteRwObjectsNotInFrustumInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], memoryToCleanInBytes))
                {
                    return;
                }
            }
        }
        if (RemoveReferencedTxds(memoryToCleanInBytes))
            return;
        // BUG: possibly missing CWorld::IncrementCurrentScanCode() here?
        for (std::int32_t sectorY = sectorStartY; sectorY != sectorEndY; sectorY -= factorY) {
            for (std::int32_t sectorX = sectorStartX; sectorX <= sectorEndX; sectorX++) {
                CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
                CSector* pSector = GetSector(sectorX, sectorY);
                if (DeleteRwObjectsBehindCameraInSectorList(pSector->m_buildings, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pSector->m_dummies, memoryToCleanInBytes) ||
                    DeleteRwObjectsBehindCameraInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS], memoryToCleanInBytes))
                {
                    return;
                }
            }
        }
    }
    while ((static_cast<std::int32_t>(ms_memoryUsed) >= memoryToCleanInBytes)) {
        if (!RemoveLeastUsedModel(0))
            break;
    }
#endif
}

bool CStreaming::DeleteRwObjectsBehindCameraInSectorList(CPtrList& list, std::int32_t memoryToCleanInBytes) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, CPtrList&, std::int32_t>(0x409940, list, memoryToCleanInBytes);
#else
    for (CPtrNode* pNode = list.GetNode(); pNode; pNode = pNode->pNext) {
        CEntity* pEntity = reinterpret_cast<CEntity*>(pNode->pItem);
        if (pEntity->m_nScanCode != CWorld::ms_nCurrentScanCode) {
            pEntity->m_nScanCode = CWorld::ms_nCurrentScanCode;
            const std::int32_t modelId = pEntity->m_nModelIndex;
            if (!pEntity->m_bImBeingRendered && !pEntity->m_bStreamingDontDelete
                && pEntity->m_pRwObject
                && ms_aInfoForModel[modelId].InList()
                && FindPlayerPed(-1)->m_pContactEntity != pEntity)
            {
                pEntity->DeleteRwObject();
                if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount) {
                    RemoveModel(modelId);
                    if (static_cast<std::int32_t>(ms_memoryUsed) < memoryToCleanInBytes)
                        return true;
                }
            }
        }
    }
    return false;
#endif
}

void CStreaming::DeleteRwObjectsInSectorList(CPtrList& list, std::int32_t sectorX, std::int32_t sectorY) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CPtrList&, std::int32_t, std::int32_t>(0x407A70, list, sectorX, sectorY);
#else
    for (CPtrNode* pNode = list.GetNode(); pNode; pNode = pNode->pNext) {
        CEntity* pEntity = reinterpret_cast<CEntity*>(pNode->pItem);
        if (sectorX < 0 || pEntity->LivesInThisNonOverlapSector(sectorX, sectorY)) {
            if (!pEntity->m_bImBeingRendered && !pEntity->m_bStreamingDontDelete)
                pEntity->DeleteRwObject();
        }
    }
#endif
}

bool CStreaming::DeleteRwObjectsNotInFrustumInSectorList(CPtrList& list, std::int32_t memoryToCleanInBytes) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, CPtrList&, std::int32_t>(0x4099E0, list, memoryToCleanInBytes);
#else
    for (CPtrNode* pNode = list.GetNode(); pNode; pNode = pNode->pNext) {
        CEntity* pEntity = reinterpret_cast<CEntity*>(pNode->pItem);
        if (pEntity->m_nScanCode != CWorld::ms_nCurrentScanCode) {
            pEntity->m_nScanCode = CWorld::ms_nCurrentScanCode;
            const std::int32_t modelId = pEntity->m_nModelIndex;
            if (!pEntity->m_bImBeingRendered && !pEntity->m_bStreamingDontDelete
                && pEntity->m_pRwObject
                && (!pEntity->IsVisible() || pEntity->m_bOffscreen)
                && ms_aInfoForModel[modelId].InList())
            {
                pEntity->DeleteRwObject();
                if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount) {
                    RemoveModel(modelId);
                    if (static_cast<std::int32_t>(ms_memoryUsed) < memoryToCleanInBytes)
                        return true;
                }
            }
        }
    }
    return false;
#endif
}

bool CStreaming::RemoveReferencedTxds(std::int32_t memoryToCleanInBytes)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturn<bool, 0x40D2F0, std::int32_t>(memoryToCleanInBytes);
#else
    auto streamingInfo = ms_pEndLoadedList->GetPrev();
    while (streamingInfo != CStreaming::ms_startLoadedList) {
        auto previousStreamingInfo = streamingInfo->GetPrev();
        const std::int32_t modelId = streamingInfo - CStreaming::ms_aInfoForModel;
        if (modelId >= RESOURCE_ID_TXD && modelId < RESOURCE_ID_COL && !(streamingInfo->m_nFlags & STREAMING_LOADING_SCENE)) {
            if (!CTxdStore::GetNumRefs(modelId - RESOURCE_ID_TXD)) {
                CStreaming::RemoveModel(modelId);
                if (static_cast<std::int32_t>(CStreaming::ms_memoryUsed) < memoryToCleanInBytes)
                    return true;
            }
        }
        streamingInfo = previousStreamingInfo;
    }
    return false;
#endif
}

void CStreaming::DisableCopBikes(bool bDisable) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<bool>(0x407D10, bDisable);
#else
    m_bDisableCopBikes = bDisable;
#endif
}

bool CStreaming::IsVeryBusy() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool>(0x4076A0);
#else
    return CRenderer::m_loadingPriority || ms_numModelsRequested > 5;
#endif
}

void CStreaming::Load()
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x5D29E0);
#else
    std::uint8_t data;
    for (std::int32_t i = 0; i < RESOURCE_ID_TOTAL; i++) {
        CStreamingInfo& streamingInfo = ms_aInfoForModel[i];
        CGenericGameStorage::LoadDataFromWorkBuffer(&data, 1u);
        if (streamingInfo.m_nLoadState == LOADSTATE_LOADED && data != 0xFFu)
            streamingInfo.m_nFlags |= data;
    }
#endif
}

//////////////////////////////////////////////////////////////////////////////////////////
// CStreaming::LoadAllRequestedModels
//
// There are only 2 streaming channels within CStreaming::ms_channel. In this function, 
// if your current channelIndex is zero then "1 - channelIndex" will give you the other 
// streaming channel within CStreaming::ms_channel which is 1 (second streaming channel). 
//////////////////////////////////////////////////////////////////////////////////////////
void CStreaming::LoadAllRequestedModels(bool bOnlyPriorityRequests)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<bool>(0x40EA10, bOnlyPriorityRequests);
#else
    if (!m_bLoadingAllRequestedModels)
    {
        m_bLoadingAllRequestedModels = true;
        FlushChannels();
        int numModelsToLoad = 10;
        if (2 * ms_numModelsRequested >= 10)
            numModelsToLoad = 2 * ms_numModelsRequested;

        int channelId = 0;
        while (1)
        {
            const tStreamingChannel& firstChannel = ms_channel[0];
            const tStreamingChannel& secondChannel = ms_channel[1];
            if (ms_pEndRequestedList->GetPrev() == ms_pStartRequestedList
                && firstChannel.LoadStatus == LOADSTATE_NOT_LOADED
                && secondChannel.LoadStatus == LOADSTATE_NOT_LOADED
                || numModelsToLoad <= 0)
            {
                break;
            }

            if (ms_bLoadingBigModel)
            {
                channelId = 0;
            }

            tStreamingChannel& channel = ms_channel[channelId];
            if (channel.LoadStatus != LOADSTATE_NOT_LOADED) {
                CdStreamSync(channelId);
                channel.iLoadingLevel = 100;
            }
            if (channel.LoadStatus == LOADSTATE_LOADED) {
                ProcessLoadingChannel(channelId);
                if (channel.LoadStatus == LOADSTATE_REQUESTED)
                    ProcessLoadingChannel(channelId);
            }

            if (bOnlyPriorityRequests && !ms_numPriorityRequests)
            {
                break;
            }

            if (!ms_bLoadingBigModel) {
                tStreamingChannel& otherChannel = ms_channel[1 - channelId];
                if (otherChannel.LoadStatus == LOADSTATE_NOT_LOADED)
                    RequestModelStream(1 - channelId);
                if (channel.LoadStatus == LOADSTATE_NOT_LOADED && !ms_bLoadingBigModel)
                    RequestModelStream(channelId);
            }
            if (firstChannel.LoadStatus == LOADSTATE_NOT_LOADED && secondChannel.LoadStatus == LOADSTATE_NOT_LOADED)
                break;
            channelId = 1 - channelId;
            --numModelsToLoad;
        }
        FlushChannels();
        m_bLoadingAllRequestedModels = false;
    }
#endif
}

void CStreaming::LoadCdDirectory(const char* filename, std::int32_t archiveId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<char const*, std::int32_t>(0x5B6170, filename, archiveId);
#else
    FILE* file = CFileMgr::OpenFile(filename, "rb");
    if (!file)
        return;
    std::int32_t previousModelId = -1;
    char version[4];
    std::int32_t entryCount;
    CFileMgr::Read(file, &version, 4u);
    CFileMgr::Read(file, &entryCount, 4u);
    for (std::int32_t i = 0; i < entryCount; i++) {
        CDirectory::DirectoryInfo entryInfo;
        CFileMgr::Read(file, &entryInfo, sizeof(CDirectory::DirectoryInfo));
        if (entryInfo.m_nStreamingSize > ms_streamingBufferSize)
            ms_streamingBufferSize = entryInfo.m_nStreamingSize;
        const std::int32_t nameSize = sizeof(CDirectory::DirectoryInfo::m_szName);
        entryInfo.m_szName[nameSize - 1] = 0;
        char* pExtension = strchr(entryInfo.m_szName, '.');
        if (!pExtension || pExtension - entryInfo.m_szName > 20) {
            entryInfo.m_szName[nameSize - 1] = 0;
            previousModelId = -1;
            continue;
        }
        *pExtension = 0;
        std::int32_t modelId = -1;
        if (!memicmp(pExtension + 1, "DFF", 3u)) {
            if (!CModelInfo::GetModelInfo(entryInfo.m_szName, &modelId)) {
                entryInfo.m_nOffset |= archiveId << 24;
                CStreaming::ms_pExtraObjectsDir->AddItem(entryInfo);
                previousModelId = -1;
                continue;
            }
        }
        else if (!memicmp(pExtension + 1, "TXD", 3u)) {
            std::int32_t txdSlot = CTxdStore::FindTxdSlot(entryInfo.m_szName);
            if (txdSlot == -1) {
                txdSlot = CTxdStore::AddTxdSlot(entryInfo.m_szName);
                CVehicleModelInfo::AssignRemapTxd(entryInfo.m_szName, txdSlot);
            }
            modelId = txdSlot + RESOURCE_ID_TXD;
        }
        else if (!memicmp(pExtension + 1, "COL", 3u)) {
            std::int32_t colSlot = CColStore::FindColSlot();
            if (colSlot == -1)
                colSlot = CColStore::AddColSlot(entryInfo.m_szName);
            modelId = colSlot + RESOURCE_ID_COL;
        }
        else if (!memicmp(pExtension + 1, "IPL", 3u)) {
            std::int32_t iplSlot = CIplStore::FindIplSlot(entryInfo.m_szName);
            if (iplSlot == -1)
                iplSlot = CIplStore::AddIplSlot(entryInfo.m_szName);
            modelId = iplSlot + RESOURCE_ID_IPL;
        }
        else if (!memicmp(pExtension + 1, "DAT", 3u)) {
            sscanf(&entryInfo.m_szName[5], "%d", &modelId);
            modelId += RESOURCE_ID_DAT;
        }
        else if (!memicmp(pExtension + 1, "IFP", 3u)) {
            modelId = CAnimManager::RegisterAnimBlock(entryInfo.m_szName) + RESOURCE_ID_IFP;
        }
        else if (!memicmp(pExtension + 1, "RRR", 3u)) {
            modelId = CVehicleRecording::RegisterRecordingFile(entryInfo.m_szName) + RESOURCE_ID_RRR;
        }
        else if (!memicmp(pExtension + 1, "SCM", 3u)) {
            modelId = CTheScripts::StreamedScripts.RegisterScript(entryInfo.m_szName) + RESOURCE_ID_SCM;
        }
        else {
            *pExtension = '.';
            previousModelId = -1;
            continue;
        }
        std::uint32_t cdPos, cdSize;
        CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
        if (!streamingInfo.GetCdPosnAndSize(&cdPos, &cdSize)) {
            streamingInfo.m_nImgId = archiveId;
            if (entryInfo.m_nSizeInArchive)
                entryInfo.m_nStreamingSize = entryInfo.m_nSizeInArchive;
            streamingInfo.SetCdPosnAndSize(entryInfo.m_nOffset, entryInfo.m_nStreamingSize);
            streamingInfo.m_nFlags = 0;
            if (previousModelId != -1)
                ms_aInfoForModel[previousModelId].m_nNextIndexOnCd = modelId;
            previousModelId = modelId;
        }
    }
    CFileMgr::CloseFile(file);
#endif
}

void CStreaming::LoadCdDirectory()
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x5B82C0);
#else
    ////////////// unused///////////////
    ms_imageOffsets[0] = 0;
    ms_imageOffsets[1] = -1;
    ms_imageOffsets[2] = -1;
    ms_imageOffsets[3] = -1;
    ms_imageOffsets[4] = -1;
    ms_imageOffsets[5] = -1;
    ////////////////////////////////////
    for (std::int32_t archiveId = 0; archiveId < TOTAL_IMG_ARCHIVES; archiveId++) {
        tStreamingFileDesc& streamingFile = ms_files[archiveId];
        if (!streamingFile.m_szName[0])
            break;
        if (streamingFile.m_bNotPlayerImg)
            LoadCdDirectory(streamingFile.m_szName, archiveId);
    }
    // more unused code, so let's stop here
#endif
}

void CStreaming::LoadInitialPeds() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40D3D0);
#else
    RequestModel(MODEL_MALE01, STREAMING_GAME_REQUIRED);
    StreamCopModels(LEVEL_NAME_LOS_SANTOS);
#endif
}

void CStreaming::LoadInitialVehicles() {
    // empty function
}

void CStreaming::LoadInitialWeapons() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40A120);
#else
    RequestModel(MODEL_COLT45, STREAMING_GAME_REQUIRED);
    RequestModel(MODEL_NITESTICK, STREAMING_GAME_REQUIRED);
    RequestModel(MODEL_MISSILE, STREAMING_GAME_REQUIRED);
#endif
}

void CStreaming::LoadScene(CVector const& point) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x40EB70, point);
#else
    eLevelName level = CTheZones::GetLevelFromPosition(point);
    CVector playerPosition;
    ms_bLoadingScene = true;
    if (CWorld::Players[0].m_pPed)
        playerPosition = FindPlayerCoors(-1);
    auto streamingInfo = ms_pEndRequestedList->GetPrev();
    while (streamingInfo != ms_pStartRequestedList) {
        auto previousStreamingInfo = streamingInfo->GetPrev();
        if (!(streamingInfo->m_nFlags & STREAMING_DONTREMOVE_IN_LOADSCENE))
            RemoveModel(streamingInfo - ms_aInfoForModel);
        streamingInfo = previousStreamingInfo;
    }
    CRenderer::m_loadingPriority = 0;
    DeleteAllRwObjects();
    RequestBigBuildings(point);
    CIplStore::LoadIpls(point, true);
    LoadAllRequestedModels(false);
    AddModelsToRequestList(point, STREAMING_LOADING_SCENE);
    CRadar::StreamRadarSections(point);
    ThePaths.LoadSceneForPathNodes(point);
    if (!CGame::currArea) {
        if (ms_bLoadVehiclesInLoadScene) {
            if (CTheZones::GetZoneInfo(point, nullptr) != CTheZones::GetZoneInfo(playerPosition, nullptr)) {
                for (std::int32_t i = 0; i < 5; i++) {
                    LoadZoneVehicle(point);
                }
            }
        }
        StreamCopModels(level);
    }
    LoadAllRequestedModels(false);
    InstanceLoadedModels(point);
    ClearFlagForAll(STREAMING_LOADING_SCENE);
    ms_bLoadingScene = false;
    if (CWorld::Players[0].m_pPed)
        CPopulation::ManageAllPopulation();
#endif
}

void CStreaming::LoadSceneCollision(CVector const& point) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x40ED80, point);
#else
    CColStore::LoadCollision(point);
    CIplStore::LoadIpls(point, true);
    LoadAllRequestedModels(false);
#endif
}

void CStreaming::LoadZoneVehicle(const CVector& point) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<const CVector&>(0x40B4B0, point);
#else
    if (CPopCycle::m_pCurrZoneInfo) {
        CTheZones::GetZoneInfo(point, 0); // called but return value is ignored
        std::int32_t carGroupId = CPopCycle::PickARandomGroupOfOtherPeds();
        std::int32_t modelId = CCarCtrl::ChooseCarModelToLoad(carGroupId);
        if (modelId >= 0)
            RequestModel(modelId, STREAMING_KEEP_IN_MEMORY);
    }
#endif

}

void CStreaming::PossiblyStreamCarOutAfterCreation(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40BA70, modelId);
#else
    if (CModelInfo::ms_modelInfoPtrs[modelId]->m_nFlags & STREAMING_UNKNOWN_1) {
        if (rand() & 1)
            SetModelIsDeletable(modelId);
    }
#endif
}

void CStreaming::RenderEntity(CLink<CEntity*>* streamingLink)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x4096D0, CLink<CEntity*>*>(streamingLink);
#else
    if (streamingLink && streamingLink != ms_renderEntityLink) {
        streamingLink->Remove();
        ms_renderEntityLink->Insert(streamingLink);
        ms_renderEntityLink = streamingLink;
    }
#endif
}

void CStreaming::RequestBigBuildings(CVector const& point) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x409430, point);
#else
    for (std::int32_t i = CPools::ms_pBuildingPool->GetSize() - 1; i >= 0; i--) {
        CBuilding* pBuilding = CPools::ms_pBuildingPool->GetAt(i);
        if (pBuilding && pBuilding->m_bIsBIGBuilding) {
            if (CRenderer::ShouldModelBeStreamed(pBuilding, point, TheCamera.m_pRwCamera->farPlane))
                RequestModel(pBuilding->m_nModelIndex, 0);
        }
    }
#endif
}

void CStreaming::RequestFile(int modelId, int posn, int size, int imgId, int streamingFlags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x40A080, int, int, int, int, int>(modelId, posn, size, imgId, streamingFlags);
#else
    auto& streamingInfo = ms_aInfoForModel[modelId];
    const unsigned int blockOffset = (imgId << 24) | posn;
    if (streamingInfo.m_nCdSize && streamingInfo.GetCdPosn() == blockOffset && streamingInfo.m_nCdSize == size) {
        RequestModel(modelId, streamingFlags);
    }
    else {
        RemoveModel(modelId);
        streamingInfo.m_nCdPosn = blockOffset & 0xFFFFFF;
        streamingInfo.m_nCdSize = size;
        streamingInfo.m_nImgId = imgId;
        RequestModel(modelId, streamingFlags);
    }
#endif
}

void CStreaming::RequestFilesInChannel(int channelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x409050, channelId);
#else
    const tStreamingChannel& channel = ms_channel[channelId];
    for (int i = 0; i < 16; i++) {
        const int modelId = channel.modelIds[i];
        if (modelId != -1) {
            int flags = ms_aInfoForModel[modelId].m_nFlags;
            RemoveModel(modelId);
            RequestModel(modelId, flags);
        }
    }
#endif
}

void CStreaming::RequestModel(int modelId, unsigned int streamingFlags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int, unsigned int>(0x4087E0, modelId, streamingFlags);
#else
    CStreamingInfo& modelStreamingInfo = ms_aInfoForModel[modelId];
    char loadState = modelStreamingInfo.m_nLoadState;
    if (loadState == LOADSTATE_REQUESTED)
    {
        if ((streamingFlags & STREAMING_PRIORITY_REQUEST) && !(modelStreamingInfo.m_nFlags & STREAMING_PRIORITY_REQUEST))
        {
            ++ms_numPriorityRequests;
            modelStreamingInfo.m_nFlags |= STREAMING_PRIORITY_REQUEST;
        }
    }
    else if (loadState)
    {
        streamingFlags &= ~STREAMING_PRIORITY_REQUEST;
    }

    modelStreamingInfo.m_nFlags |= streamingFlags;
    if (loadState == LOADSTATE_LOADED) {
        if (modelStreamingInfo.InList()) {
            modelStreamingInfo.RemoveFromList();
            if (modelId < RESOURCE_ID_TXD) {
                CBaseModelInfo* modelInfo = CModelInfo::GetModelInfo(modelId);
                size_t modelType = modelInfo->GetModelType();
                if (modelType == MODEL_INFO_TYPE_PED || modelType == MODEL_INFO_TYPE_VEHICLE)
                {
                    return;
                }
            }

            if (!(modelStreamingInfo.m_nFlags & (STREAMING_GAME_REQUIRED | STREAMING_MISSION_REQUIRED)))
                modelStreamingInfo.AddToList(ms_startLoadedList);
        }
    }
    else if (loadState != LOADSTATE_CHANNELED && loadState != LOADSTATE_REQUESTED && loadState != LOADSTATE_FINISHING) {
        if (loadState == LOADSTATE_NOT_LOADED) {
            if (modelId >= RESOURCE_ID_TXD) {
                if (modelId < RESOURCE_ID_COL) {
                    int txdEntryParentIndex = CTxdStore::GetParentTxdSlot(modelId - RESOURCE_ID_TXD);
                    if (txdEntryParentIndex != -1)
                        RequestTxdModel(txdEntryParentIndex, streamingFlags);
                }
            }
            else
            {
                CBaseModelInfo* modelInfo = CModelInfo::GetModelInfo(modelId);
                RequestTxdModel(modelInfo->m_nTxdIndex, streamingFlags);
                int animFileIndex = modelInfo->GetAnimFileIndex();
                if (animFileIndex != -1)
                    RequestModel(animFileIndex + RESOURCE_ID_IFP, STREAMING_KEEP_IN_MEMORY);
            }
            modelStreamingInfo.AddToList(ms_pStartRequestedList);
            ++ms_numModelsRequested;
            if (streamingFlags & STREAMING_PRIORITY_REQUEST)
                ++ms_numPriorityRequests;
        }
        modelStreamingInfo.m_nFlags = streamingFlags;
        modelStreamingInfo.m_nLoadState = LOADSTATE_REQUESTED;// requested, loading
    }
#endif
}

void CStreaming::RequestTxdModel(int slot, int streamingFlags) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int, int>(0x407100, slot, streamingFlags);
#else
    RequestModel(slot + RESOURCE_ID_TXD, streamingFlags);
#endif
}

void CStreaming::RequestVehicleUpgrade(std::int32_t modelId, std::uint32_t streamingFlags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<std::int32_t, std::uint32_t>(0x408C70, modelId, streamingFlags);
#else
    RequestModel(modelId, streamingFlags);
    std::int16_t otherUpgradeModelId = CVehicleModelInfo::ms_linkedUpgrades.FindOtherUpgrade(modelId);
    if (otherUpgradeModelId != -1)
        RequestModel(otherUpgradeModelId, streamingFlags);
#endif
}

std::int32_t CStreaming::FindMIPedSlotForInterior(std::int32_t randFactor)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturn<std::int32_t, 0x407FB0, std::int32_t>(randFactor);
#else
    for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
        std::int32_t modelId = ms_pedsLoaded[(i + randFactor) % TOTAL_LOADED_PEDS];
        if (modelId >= 0 && ms_aInfoForModel[modelId].m_nLoadState == LOADSTATE_LOADED)
            return modelId;
    }
    return MODEL_MALE01;
#endif
}

void CStreaming::FinishLoadingLargeFile(unsigned char* pFileBuffer, int modelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x408CB0, unsigned char*, int>(pFileBuffer, modelId);
#else
    bool bFinishedLoadingLargeFile = 0;
    CBaseModelInfo* pBaseModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
    CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
    if (streamingInfo.m_nLoadState == LOADSTATE_FINISHING) {
        unsigned int bufferSize = streamingInfo.m_nCdSize * STREAMING_SECTOR_SIZE;
        tRwStreamInitializeData rwStreamInitializationData = { pFileBuffer, bufferSize };
        RwStream* pRwStream = _rwStreamInitialize(&gRwStream, 0, rwSTREAMMEMORY, rwSTREAMREAD, &rwStreamInitializationData);
        bool bLoaded = false;
        if (modelId >= RESOURCE_ID_DFF && modelId < RESOURCE_ID_TXD) {
            CTxdStore::SetCurrentTxd(pBaseModelInfo->m_nTxdIndex);
            bLoaded = CFileLoader::FinishLoadClumpFile(pRwStream, modelId);
            if (bLoaded)
                bLoaded = AddToLoadedVehiclesList(modelId);
            pBaseModelInfo->RemoveRef();
            CTxdStore::RemoveRefWithoutDelete(pBaseModelInfo->m_nTxdIndex);
            int animFileIndex = pBaseModelInfo->GetAnimFileIndex();
            if (animFileIndex != -1) {
                CAnimManager::RemoveAnimBlockRefWithoutDelete(animFileIndex);
            }
        }
        else if (modelId >= RESOURCE_ID_TXD && modelId < RESOURCE_ID_COL) {
            CTxdStore::AddRef(modelId - RESOURCE_ID_TXD);
            bLoaded = CTxdStore::FinishLoadTxd(modelId - RESOURCE_ID_TXD, pRwStream);
            CTxdStore::RemoveRefWithoutDelete(modelId - RESOURCE_ID_TXD);
        }
        else
            assert(modelId < RESOURCE_ID_COL && "FinishLoadingLargeFile: model id is out of range");
        RwStreamClose(pRwStream, &pFileBuffer);
        streamingInfo.m_nLoadState = LOADSTATE_LOADED;
        ms_memoryUsed += bufferSize;
        if (!bLoaded) {
            RemoveModel(modelId);
            RequestModel(modelId, streamingInfo.m_nFlags);
        }
    }
    else {
        if (modelId < RESOURCE_ID_TXD)
            pBaseModelInfo->RemoveRef();
    }
#endif
}

void CStreaming::FlushChannels()
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x40E460>();
#else
    if (ms_channel[1].LoadStatus == LOADSTATE_REQUESTED)
        ProcessLoadingChannel(1);
    if (ms_channel[0].LoadStatus == LOADSTATE_LOADED)
    {
        CdStreamSync(0);
        ms_channel[0].iLoadingLevel = 100;
        ProcessLoadingChannel(0);
    }
    if (ms_channel[0].LoadStatus == LOADSTATE_REQUESTED)
        ProcessLoadingChannel(0);
    if (ms_channel[1].LoadStatus == LOADSTATE_LOADED)
    {
        CdStreamSync(1u);
        ms_channel[1].iLoadingLevel = 100;
        ProcessLoadingChannel(1);
    }
    if (ms_channel[1].LoadStatus == LOADSTATE_REQUESTED)
        ProcessLoadingChannel(1);;
#endif
}

void CStreaming::RequestModelStream(int channelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40CBA0, channelId);
#else
    int CdStreamLastPosn = CdStreamGetLastPosn();
    int modelId = GetNextFileOnCd(CdStreamLastPosn, 1);
    if (modelId == -1)
        return;

    tStreamingChannel& channel = ms_channel[channelId];
    int32_t offsetAndHandle = 0;
    unsigned int sectorcount = 0;
    CStreamingInfo* streamingInfo = &ms_aInfoForModel[modelId];
    while (!(streamingInfo->m_nFlags & (STREAMING_KEEP_IN_MEMORY | STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED)))
    {
        if (modelId < RESOURCE_ID_TXD || modelId >= RESOURCE_ID_COL || AreTexturesUsedByRequestedModels(modelId - RESOURCE_ID_TXD))
        {
            if (modelId < RESOURCE_ID_IFP || modelId >= RESOURCE_ID_RRR || AreAnimsUsedByRequestedModels(modelId - RESOURCE_ID_IFP))
                break;
        }
        RemoveModel(modelId);
        if (streamingInfo->m_nCdSize)
        {
            offsetAndHandle = streamingInfo->m_nCdPosn + ms_files[streamingInfo->m_nImgId].m_StreamHandle;
            sectorcount = streamingInfo->m_nCdSize;
        }

        modelId = GetNextFileOnCd(sectorcount + offsetAndHandle, 1);
        if (modelId == -1)
        {
            return;
        }
        streamingInfo = &ms_aInfoForModel[modelId];
    }
    if (modelId == -1)
    {
        return;
    }
    if (streamingInfo->m_nCdSize)
    {
        offsetAndHandle = streamingInfo->m_nCdPosn + ms_files[streamingInfo->m_nImgId].m_StreamHandle;
        sectorcount = streamingInfo->m_nCdSize;
    }
    if (sectorcount > ms_streamingBufferSize)
    {
        if (channelId == 1 || ms_channel[1].LoadStatus)
        {
            return;
        }
        ms_bLoadingBigModel = 1;
    }

    unsigned int sectorCountSum = 0;
    bool isPreviousModelBig = false;
    bool isPreviousModelPed = false;
    const int numberOfModelIds = sizeof(tStreamingChannel::modelIds) / sizeof(tStreamingChannel::modelIds[0]);
    std::int32_t modelIndex = 0;
    for (; modelIndex < numberOfModelIds; modelIndex++) {
        streamingInfo = &ms_aInfoForModel[modelId];
        if (streamingInfo->m_nLoadState != LOADSTATE_REQUESTED)
            break;
        if (streamingInfo->m_nCdSize)
            sectorcount = streamingInfo->m_nCdSize;
        if (ms_numPriorityRequests && !(streamingInfo->m_nFlags & STREAMING_PRIORITY_REQUEST))
            break;
        if (modelId >= RESOURCE_ID_TXD) {
            if (modelId < RESOURCE_ID_IFP || modelId >= RESOURCE_ID_RRR) {
                if (isPreviousModelBig && sectorcount > 200)
                    break;
            }
            else if (CCutsceneMgr::ms_cutsceneProcessing || ms_aInfoForModel[MODEL_MALE01].m_nLoadState != LOADSTATE_LOADED)
            {
                break;
            }
        }
        else
        {
            CBaseModelInfo* pBaseModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
            ModelInfoType modelType = pBaseModelInfo->GetModelType();
            if (isPreviousModelPed && modelType == MODEL_INFO_PED)
                break;
            if (isPreviousModelBig && modelType == MODEL_INFO_VEHICLE)
                break;
            unsigned char loadState = ms_aInfoForModel[pBaseModelInfo->m_nTxdIndex + RESOURCE_ID_TXD].m_nLoadState;
            if (loadState != LOADSTATE_LOADED && loadState != LOADSTATE_CHANNELED)
            {
                break;
            }
            int animFileIndex = pBaseModelInfo->GetAnimFileIndex();
            if (animFileIndex != -1)
            {
                unsigned char loadState = ms_aInfoForModel[animFileIndex + RESOURCE_ID_IFP].m_nLoadState;
                if (loadState != LOADSTATE_LOADED && loadState != LOADSTATE_CHANNELED)
                    break;
            }
        }
        channel.modelStreamingBufferOffsets[modelIndex] = sectorCountSum;
        channel.modelIds[modelIndex] = modelId;

        sectorCountSum += sectorcount;
        if (sectorCountSum > ms_streamingBufferSize&& modelIndex > 0) {
            sectorCountSum -= sectorcount;
            break;
        }
        CBaseModelInfo* pBaseModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
        if (modelId >= RESOURCE_ID_TXD) {
            if (sectorcount > 200)
                isPreviousModelBig = true;
        }
        else {
            if (pBaseModelInfo->GetModelType() == MODEL_INFO_PED)
                isPreviousModelPed = true;
            if (pBaseModelInfo->GetModelType() == MODEL_INFO_VEHICLE)
                isPreviousModelBig = true;
        }
        streamingInfo->m_nLoadState = LOADSTATE_CHANNELED;
        streamingInfo->RemoveFromList();
        ms_numModelsRequested--;
        if (streamingInfo->m_nFlags & STREAMING_PRIORITY_REQUEST) {
            streamingInfo->m_nFlags &= ~STREAMING_PRIORITY_REQUEST;
            ms_numPriorityRequests--;
        }
        modelId = streamingInfo->m_nNextIndexOnCd;
    }
    for (std::int32_t i = modelIndex; i < numberOfModelIds; i++) {
        channel.modelIds[i] = -1;
    }
    CdStreamRead(channelId, ms_pStreamingBuffer[channelId], offsetAndHandle, sectorCountSum);
    channel.LoadStatus = LOADSTATE_LOADED;
    channel.iLoadingLevel = 0;
    channel.sectorCount = sectorCountSum;
    channel.offsetAndHandle = offsetAndHandle;
    channel.totalTries = 0;
    if (m_bModelStreamNotLoaded)
        m_bModelStreamNotLoaded = false;
#endif
}

void CStreaming::RequestSpecialChar(int modelId, char const* name, int flags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int, char const*, int>(0x40B450, modelId, name, flags);
#else
    return RequestSpecialModel(modelId + SPECIAL_MODELS_RESOURCE_ID, name, flags);
#endif
}

void CStreaming::RequestSpecialModel(int modelId, char const* name, int flags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int, char const*, int>(0x409D10, modelId, name, flags);
#else
    CBaseModelInfo* pModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
    CStreamingInfo& streamingInfo = CStreaming::ms_aInfoForModel[modelId];
    unsigned int CdPosn, CdSize;
    if (CKeyGen::GetUppercaseKey(name) == pModelInfo->m_nKey && streamingInfo.GetCdPosnAndSize(&CdPosn, &CdSize)) {
        RequestModel(modelId, flags);
        return;
    }
    if (pModelInfo->m_nRefCount > 0) {
        for (int i = CPools::ms_pPedPool->GetSize() - 1; i >= 0; i--) {
            if (pModelInfo->m_nRefCount <= 0)
                break;
            CPed* pPed = CPools::ms_pPedPool->GetAt(i);
            if (pPed && pPed->m_nModelIndex == modelId && !pPed->IsPlayer() && pPed->CanBeDeletedEvenInVehicle()) {
                CTheScripts::RemoveThisPed(pPed);
            }
        }
        for (int i = CPools::ms_pObjectPool->GetSize() - 1; i >= 0; i--) {
            if (pModelInfo->m_nRefCount <= 0)
                break;
            CObject* pObject = CPools::ms_pObjectPool->GetAt(i);
            if (pObject && pObject->m_nModelIndex == modelId && pObject->CanBeDeleted()) {
                CWorld::Remove(pObject);
                CWorld::RemoveReferencesToDeletedObject(pObject);
                pObject->DeletingDestructor(1); // TODO: Use delete
            }
        }
    }
    const unsigned int modelNameKey = pModelInfo->m_nKey;
    pModelInfo->m_nKey = CKeyGen::GetUppercaseKey(name);
    CBaseModelInfo* pFoundModelInfo = nullptr;
    for (int i = 0; i < 1001; i++) {
        CBaseModelInfo* pTheModelInfo = CModelInfo::ms_modelInfoPtrs[i];
        if (pTheModelInfo && modelNameKey == pTheModelInfo->m_nKey) {
            pFoundModelInfo = pTheModelInfo;
        }
    }
    if (pFoundModelInfo && pFoundModelInfo->m_nTxdIndex != -1 && CTxdStore::ms_pTxdPool->GetAt(pFoundModelInfo->m_nTxdIndex)) {
        CTxdStore::AddRef(pFoundModelInfo->m_nTxdIndex);
        RemoveModel(modelId);
        CTxdStore::RemoveRefWithoutDelete(pFoundModelInfo->m_nTxdIndex);
    }
    else {
        RemoveModel(modelId);
    }
    unsigned int outOffset, outStreamingSize;
    CStreaming::ms_pExtraObjectsDir->FindItem(name, outOffset, outStreamingSize);
    pModelInfo->ClearTexDictionary();
    if (CTxdStore::FindTxdSlot(name) == -1)
        pModelInfo->SetTexDictionary("generic");
    else
        pModelInfo->SetTexDictionary(name);
    // The first 3 bytes of outOffset is used for m_nCdPosn and 
    // the remaining 1 byte is used for m_nImgId
    // outOffset & 0xFFFFF = returns the first 3 bytes and ignores the last one
    // outOffset >> 24 = Ignores the first 3 bytes and returns the last byte
    streamingInfo.m_nCdPosn = outOffset & 0xFFFFFF;
    streamingInfo.m_nCdSize = outStreamingSize;
    streamingInfo.m_nImgId = outOffset >> 24;
    streamingInfo.m_nNextIndexOnCd = -1;
    RequestModel(modelId, flags);
#endif
}

bool CStreaming::ProcessLoadingChannel(int channelIndex)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, int>(0x40E170, channelIndex);
#else
    tStreamingChannel& streamingChannel = ms_channel[channelIndex];
    const eCdStreamStatus streamStatus = CdStreamGetStatus(channelIndex);
    if (streamStatus != eCdStreamStatus::READING_SUCCESS) {
        if (streamStatus == eCdStreamStatus::READING)
            return false;
        if (streamStatus == eCdStreamStatus::WAITING_TO_READ)
            return false;
        streamingChannel.m_nCdStreamStatus = streamStatus;
        streamingChannel.LoadStatus = LOADSTATE_CHANNELED;

        bool isChannelErrorFree = ms_channelError == -1;
        if (!isChannelErrorFree)
            return false;
        ms_channelError = channelIndex;
        RetryLoadFile(channelIndex);
        return true;
    }

    bool isRequested = streamingChannel.LoadStatus == LOADSTATE_REQUESTED;
    streamingChannel.LoadStatus = LOADSTATE_NOT_LOADED; // 0;
    if (!isRequested) {
        int numberOfModelIds = sizeof(tStreamingChannel::modelIds) / sizeof(tStreamingChannel::modelIds[0]);
        for (int modelIndex = 0; modelIndex < numberOfModelIds; modelIndex++) {
            int modelId = streamingChannel.modelIds[modelIndex];
            if (modelId != -1) {
                CBaseModelInfo* baseModelInfo = CModelInfo::GetModelInfo(modelId);
                CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
                int nCdSize = streamingInfo.m_nCdSize;

                if (modelId >= RESOURCE_ID_TXD
                    || baseModelInfo->GetModelType() != MODEL_INFO_VEHICLE
                    || ms_vehiclesLoaded.CountMembers() < desiredNumVehiclesLoaded
                    || RemoveLoadedVehicle()
                    || streamingInfo.m_nFlags & (STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))
                {
                    if (modelId < RESOURCE_ID_IPL || modelId >= RESOURCE_ID_DAT)
                        MakeSpaceFor(nCdSize * STREAMING_SECTOR_SIZE);

                    int bufferOffset = streamingChannel.modelStreamingBufferOffsets[modelIndex];
                    unsigned char* pFileBuffer = reinterpret_cast <unsigned char*> (&ms_pStreamingBuffer[channelIndex][STREAMING_SECTOR_SIZE * bufferOffset]);

                    ConvertBufferToObject(pFileBuffer, modelId);

                    if (streamingInfo.m_nLoadState == LOADSTATE_FINISHING) {
                        streamingChannel.LoadStatus = LOADSTATE_REQUESTED;
                        streamingChannel.modelStreamingBufferOffsets[modelIndex] = bufferOffset;
                        streamingChannel.modelIds[modelIndex] = modelId;
                        if (modelIndex == 0)
                            continue;
                    }
                    streamingChannel.modelIds[modelIndex] = -1;
                }
                else {
                    int modelTxdIndex = baseModelInfo->m_nTxdIndex;
                    RemoveModel(modelId);
                    if (streamingInfo.m_nFlags & (STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))
                        RequestModel(modelId, streamingInfo.m_nFlags);
                    else if (!CTxdStore::GetNumRefs(modelTxdIndex))
                        RemoveTxdModel(modelTxdIndex);
                }
            }
        }
    }
    else {
        int bufferOffset = streamingChannel.modelStreamingBufferOffsets[0];
        unsigned char* pFileContents = reinterpret_cast<unsigned char*>(&ms_pStreamingBuffer[channelIndex][STREAMING_SECTOR_SIZE * bufferOffset]);
        FinishLoadingLargeFile(pFileContents, streamingChannel.modelIds[0]);
        streamingChannel.modelIds[0] = -1;
    }
    if (ms_bLoadingBigModel) {
        if (streamingChannel.LoadStatus != LOADSTATE_REQUESTED) {
            ms_bLoadingBigModel = false;
            for (int i = 0; i < 16; i++) {
                ms_channel[1].modelIds[i] = -1;
            }
        }
    }
    return true;
#endif
}

void CStreaming::PurgeRequestList() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40C1E0);
#else
    auto streamingInfo = ms_pEndRequestedList->GetPrev();
    while (streamingInfo != ms_pStartRequestedList) {
        auto previousStreamingInfo = streamingInfo->GetPrev();
        if (!(streamingInfo->m_nFlags & (STREAMING_PRIORITY_REQUEST | STREAMING_KEEP_IN_MEMORY | STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED)))
            RemoveModel(streamingInfo - ms_aInfoForModel);
        streamingInfo = previousStreamingInfo;
    }
#endif
}

void CStreaming::ReInit() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::Call<0x40E560>();
#else
    CTheScripts::StreamedScripts.ReInitialise();
    FlushRequestList();
    DeleteAllRwObjects();
    RemoveAllUnusedModels();
    for (std::int32_t modelId = 0; modelId < RESOURCE_ID_TOTAL; modelId++)
    {
        CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
        if (streamingInfo.m_nFlags & STREAMING_MISSION_REQUIRED)
            SetMissionDoesntRequireModel(modelId);
    }

    for (std::int32_t scmId = 0; scmId < TOTAL_SCM_MODEL_IDS; scmId++) {
        RemoveModel(scmId + RESOURCE_ID_SCM);
    }
    ms_disableStreaming = false;
    ms_currentZoneType = -1;
    m_bBoatsNeeded = false;
    m_bCopBikeLoaded = false;
    m_bDisableCopBikes = false;
    ms_nTimePassedSinceLastCopBikeStreamedIn = 0;
    for (std::int32_t i = 0; i < TOTAL_SPECIAL_MODELS; i++) {
        const std::int32_t modelId = i + SPECIAL_MODELS_RESOURCE_ID;
        RemoveModel(modelId);
        CModelInfo::ms_modelInfoPtrs[modelId]->m_nKey = CKeyGen::GetUppercaseKey(gta_empty_string);
    }
    for (std::int32_t i = 0; i < TOTAL_CLOTHES_MODELS; i++) {
        const std::int32_t modelId = i + CLOTHES_MODELS_RESOURCE_ID;
        RemoveModel(modelId);
        CModelInfo::ms_modelInfoPtrs[modelId]->m_nKey = CKeyGen::GetUppercaseKey(gta_empty_string);
    }
    for (std::int32_t i = 0; i < TOTAL_CUTSCENE_MODELS; i++) {
        const std::int32_t modelId = i + CUTSCENE_MODELS_RESOURCE_ID;
        RemoveModel(modelId);
        CModelInfo::ms_modelInfoPtrs[modelId]->m_nKey = CKeyGen::GetUppercaseKey(gta_empty_string);
    }
#endif
}

void CStreaming::ReadIniFile() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<>(0x5BCCD0);
#else
    bool bHasDevkitMemory = false;
    FILE* file = CFileMgr::OpenFile("stream.ini", "r");
    for (char* line = CFileLoader::LoadLine(file); line; line = CFileLoader::LoadLine(file))
    {
        if (*line != '#' && *line)
        {
            char* attribute = strtok(line, " ,\t");
            char* value = strtok(0, " ,\t");
            if (stricmp(attribute, "memory") || bHasDevkitMemory)
            {
                if (!stricmp(attribute, "devkit_memory"))
                {
                    CStreaming::ms_memoryAvailable = atoi(value) << 10;
                    bHasDevkitMemory = true;
                }
                else if (!stricmp(attribute, "vehicles"))
                {
                    CStreaming::desiredNumVehiclesLoaded = atoi(value);
                }
                else if (!stricmp(attribute, "dontbuildpaths"))
                {
                    //bDontBuildPaths = 1; // unused
                }
                else if (!stricmp(attribute, "pe_lightchangerate"))
                {
                    CPostEffects::SCREEN_EXTRA_MULT_CHANGE_RATE = static_cast<float>(atof(value));
                }
                else if (!stricmp(attribute, "pe_lightingbasecap"))
                {
                    CPostEffects::SCREEN_EXTRA_MULT_BASE_CAP = static_cast<float>(atof(value));
                }
                else if (!stricmp(attribute, "pe_lightingbasemult"))
                {
                    CPostEffects::SCREEN_EXTRA_MULT_BASE_MULT = static_cast<float>(atof(value));
                }
                else if (!stricmp(attribute, "pe_leftx"))
                {
                    CPostEffects::m_colourLeftUOffset = atoi(value);
                }
                else if (!stricmp(attribute, "pe_rightx"))
                {
                    CPostEffects::m_colourRightUOffset = atoi(value);
                }
                else if (!stricmp(attribute, "pe_topy"))
                {
                    CPostEffects::m_colourTopVOffset = atoi(value);
                }
                else if (!stricmp(attribute, "pe_bottomy"))
                {
                    CPostEffects::m_colourBottomVOffset = atoi(value);
                }
                else if (!stricmp(attribute, "pe_bRadiosity"))
                {
                    CPostEffects::m_bRadiosity = atoi(value) != 0;
                }
                else if (!stricmp(attribute, "def_brightness_pal"))
                {
                    FrontEndMenuManager.m_nBrightness = atoi(value);
                }
            }
            else
            {
                CStreaming::ms_memoryAvailable = atoi(value) << 10;
            }
        }
    }
    CFileMgr::CloseFile(file);
#endif
}

void CStreaming::ReclassifyLoadedCars() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40AFA0);
#else
    CLoadedCarGroup appropriateCarGroup;
    CLoadedCarGroup inAppropriateCarGroup;
    memcpy(&appropriateCarGroup, &CPopulation::m_AppropriateLoadedCars, sizeof(CLoadedCarGroup));
    memcpy(&inAppropriateCarGroup, &CPopulation::m_InAppropriateLoadedCars, sizeof(CLoadedCarGroup));
    CPopulation::m_AppropriateLoadedCars.Clear();
    CPopulation::m_InAppropriateLoadedCars.Clear();
    for (int i = 0; i < appropriateCarGroup.CountMembers(); i++) {
        int modelId = appropriateCarGroup.GetMember(i);
        CLoadedCarGroup* carGroup = &CPopulation::m_AppropriateLoadedCars;
        if (!IsCarModelNeededInCurrentZone(modelId))
            carGroup = &CPopulation::m_InAppropriateLoadedCars;
        carGroup->AddMember(modelId);
    }
    for (int i = 0; i < inAppropriateCarGroup.CountMembers(); i++) {
        int modelId = inAppropriateCarGroup.GetMember(i);
        CLoadedCarGroup* carGroup = &CPopulation::m_AppropriateLoadedCars;
        if (!IsCarModelNeededInCurrentZone(modelId))
            carGroup = &CPopulation::m_InAppropriateLoadedCars;
        carGroup->AddMember(modelId);
    }
#endif
}

void CStreaming::RemoveAllUnusedModels() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40CF80);
#else
    for (int i = 0; i < 50; i++) {
        RemoveLoadedVehicle();
    }
    for (int modelId = 1000; modelId < RESOURCE_ID_TXD; modelId++) {
        CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
        if (streamingInfo.m_nLoadState == LOADSTATE_LOADED && !CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount) {
            RemoveModel(modelId);
            streamingInfo.m_nFlags = 0;
        }
    }
#endif
}

void CStreaming::RemoveBigBuildings() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x4093B0);
#else
    for (std::int32_t i = CPools::ms_pBuildingPool->GetSize() - 1; i >= 0; i--) {
        CBuilding* pBuilding = CPools::ms_pBuildingPool->GetAt(i);
        if (pBuilding && pBuilding->m_bIsBIGBuilding && !pBuilding->m_bImBeingRendered) {
            pBuilding->DeleteRwObject();
            if (!CModelInfo::ms_modelInfoPtrs[pBuilding->m_nModelIndex]->m_nRefCount)
                RemoveModel(pBuilding->m_nModelIndex);
        }
    }
#endif
}

void CStreaming::RemoveBuildingsNotInArea(int areaCode) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x4094B0, areaCode);
#else
    for (std::int32_t i = CPools::ms_pBuildingPool->GetSize() - 1; i >= 0; i--) {
        CBuilding* pBuilding = CPools::ms_pBuildingPool->GetAt(i);
        if (pBuilding && pBuilding->m_pRwObject) {
            if (pBuilding->m_nAreaCode != areaCode && pBuilding->m_nAreaCode != 13) {
                if (!pBuilding->m_bImBeingRendered && !pBuilding->m_bIsBIGBuilding)
                    pBuilding->DeleteRwObject();
            }
        }
    }
    for (std::int32_t i = CPools::ms_pObjectPool->GetSize() - 1; i >= 0; i--) {
        CObject* pObject = CPools::ms_pObjectPool->GetAt(i);
        if (pObject && pObject->m_pRwObject) {
            if (pObject->m_nAreaCode != areaCode && pObject->m_nAreaCode != 13) {
                if (!pObject->m_bImBeingRendered && pObject->m_nObjectType == eObjectType::OBJECT_GAME)
                    pObject->DeleteRwObject();
            }
        }
    }
    for (std::int32_t i = CPools::ms_pDummyPool->GetSize() - 1; i >= 0; i--) {
        CDummy* pDummy = CPools::ms_pDummyPool->GetAt(i);
        if (pDummy && pDummy->m_pRwObject) {
            if (pDummy->m_nAreaCode != areaCode && pDummy->m_nAreaCode != 13) {
                if (!pDummy->m_bImBeingRendered)
                    pDummy->DeleteRwObject();
            }
        }
    }
#endif
}
void CStreaming::RemoveCarModel(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x4080F0, modelId);
#else
    CPopulation::m_AppropriateLoadedCars.RemoveMember(modelId);
    CPopulation::m_InAppropriateLoadedCars.RemoveMember(modelId);
    CPopulation::m_LoadedBoats.RemoveMember(modelId);
    for (std::int32_t i = 0; i < 11; i++) {
        CLoadedCarGroup& carGroup = CPopulation::m_LoadedGangCars[i];
        carGroup.RemoveMember(modelId);
    }
    ms_vehiclesLoaded.RemoveMember(modelId);
    CPopulation::RemoveSpecificDriverModelsForCar(modelId);
#endif
}

void CStreaming::RemoveCurrentZonesModels() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40B080);
#else
    for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
        std::int32_t modelId = ms_pedsLoaded[i];
        if (modelId >= 0) {
            SetModelIsDeletable(modelId);
            SetModelTxdIsDeletable(modelId);
            ms_pedsLoaded[i] = -1;
        }
    }
    ms_numPedsLoaded = 0;
    RequestModel(MODEL_MALE01, STREAMING_GAME_REQUIRED);
    for (std::int32_t groupId = 0; groupId < TOTAL_GANGS; groupId++) {
        ePopcycleGroup popcycleGroup = static_cast<ePopcycleGroup>(groupId + POPCYCLE_GROUP_BALLAS);
        ePopcyclePedGroup pedGroupId = CPopulation::GetPedGroupId(popcycleGroup, 0);
        for (std::int32_t i = 0; i < 5; i++) {
            std::int32_t modelId = CPopulation::GetPedGroupModelId(pedGroupId, i);
            if (modelId != CPopulation::m_defaultCarGroupModelId) {
                SetModelIsDeletable(modelId);
                SetModelTxdIsDeletable(modelId);
            }
        }
    }
    ms_currentZoneType = -1;
    ms_loadedGangs = 0;
    ms_loadedGangCars = 0;
#endif
}

void CStreaming::RemoveDodgyPedsFromRandomSlots() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40BE60);
#else
    for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
        std::int32_t modelId = ms_pedsLoaded[i];
        switch (modelId)
        {
        case MODEL_VWFYST1:
        case MODEL_VBFYST2:
        case MODEL_VHFYST3:
        case MODEL_SBFYSTR:
        case MODEL_SWFYSTR:
            SetModelIsDeletable(modelId);
            SetModelTxdIsDeletable(modelId);
            ms_pedsLoaded[i] = -1;
            ms_numPedsLoaded--;
            break;
        }
    }
#endif
}

void CStreaming::RemoveEntity(CLink<CEntity*>* streamingLink)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CLink<CEntity*>*>(0x409710, streamingLink);
#else
    if (streamingLink) {
        if (streamingLink == ms_renderEntityLink)
            ms_renderEntityLink = ms_renderEntityLink->prev;
        ms_rwObjectInstances.Remove(streamingLink);
    }
#endif
}

void CStreaming::RemoveInappropriatePedModels() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40B3A0);
#else
    if (CPopCycle::m_pCurrZoneInfo) {
        for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
            std::int32_t modelId = ms_pedsLoaded[i];
            if (modelId >= 0 && !CPopCycle::IsPedAppropriateForCurrentZone(modelId)) {
                SetModelIsDeletable(modelId);
                SetModelTxdIsDeletable(modelId);
                ms_pedsLoaded[i] = -1;
                ms_numPedsLoaded--;
            }
        }
    }
    else {
        for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
            std::int32_t modelId = ms_pedsLoaded[i];
            if (modelId >= 0) {
                SetModelIsDeletable(modelId);
                SetModelTxdIsDeletable(modelId);
                ms_pedsLoaded[i] = -1;
            }
        }
        ms_numPedsLoaded = 0;
    }
#endif
}

bool CStreaming::RemoveLeastUsedModel(unsigned int streamingFlags) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, unsigned int>(0x40CFD0, streamingFlags);
#else
    auto streamingInfo = ms_pEndLoadedList->GetPrev();
    for (; streamingInfo != ms_startLoadedList; streamingInfo = streamingInfo->GetPrev()) {
        const std::int32_t modelId = streamingInfo - ms_aInfoForModel;
        if (!(streamingFlags & streamingInfo->m_nFlags)) {
            if (modelId >= RESOURCE_ID_DFF && modelId < RESOURCE_ID_TXD) {
                if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount) {
                    RemoveModel(modelId);
                    return true;
                }
            }
            else if (modelId >= RESOURCE_ID_TXD && modelId < RESOURCE_ID_COL) {
                const std::int32_t txdId = modelId - RESOURCE_ID_TXD;
                if (!CTxdStore::GetNumRefs(txdId) && !AreTexturesUsedByRequestedModels(txdId)) {
                    RemoveModel(modelId);
                    return true;
                }
            }
            else if (modelId >= RESOURCE_ID_IFP && modelId < RESOURCE_ID_RRR) {
                const std::int32_t animBlockId = modelId - RESOURCE_ID_IFP;
                if (!CAnimManager::GetNumRefsToAnimBlock(animBlockId) && !AreAnimsUsedByRequestedModels(animBlockId)) {
                    RemoveModel(modelId);
                    return true;
                }
            }
            else if (modelId >= RESOURCE_ID_SCM) {
                const std::int32_t scmId = modelId - RESOURCE_ID_SCM;
                if (!CTheScripts::StreamedScripts.m_aScripts[scmId].m_nStatus) {
                    RemoveModel(modelId);
                    return true;
                }
            }
        }
    }
    if (TheCamera.GetPosition().z - TheCamera.CalculateGroundHeight(eGroundHeightType::ENTITY_BOUNDINGBOX_BOTTOM) > 50.0f
        && (ms_numPedsLoaded > 4 && RemoveLoadedZoneModel() || ms_vehiclesLoaded.CountMembers() > 4 && RemoveLoadedVehicle())
        || !ms_bLoadingScene
        && (DeleteLeastUsedEntityRwObject(false, streamingFlags)
            || ms_numPedsLoaded > 4 && RemoveLoadedZoneModel()
            || (ms_vehiclesLoaded.CountMembers() > 7 || CGame::currArea && ms_vehiclesLoaded.CountMembers() > 4)
            && RemoveLoadedVehicle())
        || DeleteLeastUsedEntityRwObject(true, streamingFlags)
        || (ms_vehiclesLoaded.CountMembers() > 7 || CGame::currArea && ms_vehiclesLoaded.CountMembers() > 4)
        && RemoveLoadedVehicle() || ms_numPedsLoaded > 4 && RemoveLoadedZoneModel())
    {
        return true;
    }
    return false;
#endif
}

bool CStreaming::CarIsCandateForRemoval(std::int32_t modelId) {
    CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
    if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount
        && !(streamingInfo.m_nFlags & (STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))
        && streamingInfo.m_nLoadState == LOADSTATE_LOADED)
    {
        return true;
    }
    return false;
}

bool CStreaming::RemoveLoadedVehicle() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool>(0x40C020);
#else
    for (std::int32_t i = 0; i < CPopulation::m_InAppropriateLoadedCars.CountMembers(); i++) {
        std::int32_t modelId = CPopulation::m_InAppropriateLoadedCars.GetMember(i);
        if (CarIsCandateForRemoval(modelId)) {
            RemoveModel(modelId);
            return true;
        }
    }
    std::int32_t numBoatsNeeded = 0;
    if (CStreaming::m_bBoatsNeeded)
        numBoatsNeeded = 2;
    if (numBoatsNeeded < CPopulation::m_LoadedBoats.CountMembers()) {
        for (std::int32_t i = 0; i < CPopulation::m_LoadedBoats.CountMembers(); i++) {
            std::int32_t modelId = CPopulation::m_LoadedBoats.GetMember(i);
            if (CarIsCandateForRemoval(modelId)) {
                RemoveModel(modelId);
                return true;
            }
        }
    }
    CLoadedCarGroup appropriateLoadedCars;
    memcpy(&appropriateLoadedCars, &CPopulation::m_AppropriateLoadedCars, sizeof(CLoadedCarGroup));
    appropriateLoadedCars.SortBasedOnUsage();
    for (std::int32_t i = 0; i < appropriateLoadedCars.CountMembers(); i++) {
        std::int32_t modelId = appropriateLoadedCars.GetMember(i);
        if (CarIsCandateForRemoval(modelId)) {
            RemoveModel(modelId);
            return true;
        }
    }
    return false;
#endif
}

bool CStreaming::ZoneModelIsCandateForRemoval(std::int32_t modelId) {
    CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
    if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount
        && !(streamingInfo.m_nFlags & (STREAMING_MISSION_REQUIRED | STREAMING_GAME_REQUIRED))
        && streamingInfo.m_nLoadState == LOADSTATE_LOADED)
    {
        return true;
    }
    return false;
}

bool CStreaming::RemoveLoadedZoneModel() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool>(0x40B340);
#else
    if (CStreaming::ms_currentZoneType == -1 || CCheat::IsZoneStreamingAllowed())
        return false;
    for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
        std::int32_t modelId = ms_pedsLoaded[i];
        if (modelId >= 0 && ZoneModelIsCandateForRemoval(modelId)) {
            RemoveModel(modelId);
            return true;
        }
    }
    return false;
#endif
}

void CStreaming::RemoveModel(int modelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x4089A0, modelId);
#else
    CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];;
    if (streamingInfo.m_nLoadState == LOADSTATE_NOT_LOADED)
        return;
    if (streamingInfo.m_nLoadState == LOADSTATE_LOADED) {
        if (modelId >= RESOURCE_ID_DFF && modelId < RESOURCE_ID_TXD) {
            CBaseModelInfo* pModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
            pModelInfo->DeleteRwObject();
            if (pModelInfo->GetModelType() == MODEL_INFO_PED) {
                int numPedsLoaded = ms_numPedsLoaded;
                for (int i = 0; i < TOTAL_LOADED_PEDS; i++) {
                    if (ms_pedsLoaded[i] == modelId) {
                        ms_pedsLoaded[i] = -1;
                        numPedsLoaded--;
                    }
                }
                ms_numPedsLoaded = numPedsLoaded;
            }
            else if (pModelInfo->GetModelType() == MODEL_INFO_VEHICLE) {
                RemoveCarModel(modelId);
            }
        }
        else if (modelId >= RESOURCE_ID_TXD && modelId < RESOURCE_ID_COL) {
            CTxdStore::RemoveTxd(modelId - RESOURCE_ID_TXD);
        }
        else if (modelId >= RESOURCE_ID_COL && modelId < RESOURCE_ID_IPL) {
            CColStore::RemoveCol(modelId - RESOURCE_ID_COL);
        }
        else if (modelId >= RESOURCE_ID_IPL && modelId < RESOURCE_ID_DAT) {
            CIplStore::RemoveIpl(modelId - RESOURCE_ID_IPL);
        }
        else if (modelId >= RESOURCE_ID_DAT && modelId < RESOURCE_ID_IFP) {
            ThePaths.UnLoadPathFindData(modelId - RESOURCE_ID_DAT);
        }
        else if (modelId >= RESOURCE_ID_IFP && modelId < RESOURCE_ID_RRR) {
            CAnimManager::RemoveAnimBlock(modelId - RESOURCE_ID_IFP);
        }
        else if (modelId >= RESOURCE_ID_SCM) {
            CTheScripts::StreamedScripts.RemoveStreamedScriptFromMemory(modelId - RESOURCE_ID_SCM);
        }
        ms_memoryUsed -= STREAMING_SECTOR_SIZE * streamingInfo.m_nCdSize;
    }
    if (streamingInfo.m_nNextIndex == -1) {
        if (streamingInfo.m_nLoadState == LOADSTATE_CHANNELED) {
            for (int i = 0; i < 16; i++) {
                for (int channelId = 0; channelId < 2; channelId++) {
                    if (ms_channel[channelId].modelIds[i] == modelId)
                        ms_channel[channelId].modelIds[i] = -1;
                }
            }
        }
    }
    else {
        if (streamingInfo.m_nLoadState == LOADSTATE_REQUESTED) {
            ms_numModelsRequested--;
            if (streamingInfo.m_nFlags & STREAMING_PRIORITY_REQUEST) {
                streamingInfo.m_nFlags &= ~STREAMING_PRIORITY_REQUEST;
                ms_numPriorityRequests--;
            }
        }
        streamingInfo.RemoveFromList();
    }
    if (streamingInfo.m_nLoadState == LOADSTATE_FINISHING) {
        if (modelId < RESOURCE_ID_TXD)
            RpClumpGtaCancelStream();
        else if (modelId < RESOURCE_ID_COL)
            CTxdStore::RemoveTxd(modelId - RESOURCE_ID_TXD);
        else if (modelId < RESOURCE_ID_IPL)
            CColStore::RemoveCol(modelId - RESOURCE_ID_COL);
        else if (modelId < RESOURCE_ID_DAT)
            CIplStore::RemoveIpl(modelId - RESOURCE_ID_IPL);
        else if (modelId >= RESOURCE_ID_IFP && modelId < RESOURCE_ID_RRR)
            CAnimManager::RemoveAnimBlock(modelId - RESOURCE_ID_IFP);
        else if (modelId >= RESOURCE_ID_SCM)
            CTheScripts::StreamedScripts.RemoveStreamedScriptFromMemory(modelId - RESOURCE_ID_SCM);
    }
    streamingInfo.m_nLoadState = LOADSTATE_NOT_LOADED;
#endif
}

void CStreaming::RemoveUnusedModelsInLoadedList() {
    // empty function
}

void CStreaming::RemoveTxdModel(int modelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40C180, modelId);
#else
    RemoveModel(modelId + RESOURCE_ID_TXD);
#endif
}

void CStreaming::MakeSpaceFor(int memoryToCleanInBytes)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40E120, memoryToCleanInBytes);
#else
    if (ms_memoryUsed >= (ms_memoryAvailable - memoryToCleanInBytes)) {
        while (RemoveLeastUsedModel(0x20u))
        {
            if (ms_memoryUsed < (ms_memoryAvailable - memoryToCleanInBytes))
                return;
        }
        DeleteRwObjectsBehindCamera(ms_memoryAvailable - memoryToCleanInBytes);
    }
#endif
}

void CStreaming::ProcessEntitiesInSectorList(CPtrList& list, float posX, float posY, float minX, float minY, float maxX, float maxY, float radius, std::int32_t streamingflags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallDynGlobal<CPtrList&, float, float, float, float, float, float, float, std::int32_t>(0x40C270, list, posX, posY, minX, minY, maxX, maxY, radius, streamingflags);
#else
    CVector2D position(posX, posY);
    float squaredRadius = radius * radius;
    for (CPtrNode* pNode = list.GetNode(); pNode; pNode = pNode->pNext) {
        CEntity* pEntity = reinterpret_cast<CEntity*>(pNode->pItem);
        if (pEntity->m_nScanCode != CWorld::ms_nCurrentScanCode) {
            pEntity->m_nScanCode = CWorld::ms_nCurrentScanCode;
            std::uint16_t modelId = pEntity->m_nModelIndex;
            if (ms_aInfoForModel[modelId].m_nLoadState != LOADSTATE_LOADED && !pEntity->m_bStreamingDontDelete) {
                if ((pEntity->m_nAreaCode == CGame::currArea || pEntity->m_nAreaCode == 13)
                    && !pEntity->m_bDontStream && pEntity->m_bIsVisible)
                {
                    CBaseModelInfo* pModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
                    tTimeInfo* timeInfo = pModelInfo->GetTimeInfo();
                    if (!timeInfo || CClock::GetIsTimeInRange(timeInfo->m_nTimeOn, timeInfo->m_nTimeOff)) {
                        float drawDistanceRadius = TheCamera.m_fLODDistMultiplier * pModelInfo->m_fDrawDistance;
                        float squaredDrawDistanceRadius = drawDistanceRadius * drawDistanceRadius;
                        if (squaredRadius >= squaredDrawDistanceRadius)
                            squaredRadius = squaredDrawDistanceRadius;
                        const CVector& entityPos = pEntity->GetPosition();
                        if (entityPos.x > minX&& entityPos.x < maxX && entityPos.y > minY&& entityPos.y < maxY) {
                            CVector2D distance = position - entityPos;
                            if (distance.SquaredMagnitude() < squaredRadius) {
                                if (pModelInfo->m_pRwObject && !pEntity->m_pRwObject)
                                    pEntity->CreateRwObject();
                                RequestModel(pEntity->m_nModelIndex, streamingflags);
                            }
                        }
                    }
                }
            }
        }
    }
#endif
}

void CStreaming::ProcessEntitiesInSectorList(CPtrList& list, std::int32_t streamingFlags)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CPtrList&, std::int32_t>(0x40C450, list, streamingFlags);
#else
    for (CPtrNode* pNode = list.GetNode(); pNode; pNode = pNode->pNext) {
        CEntity* pEntity = reinterpret_cast<CEntity*>(pNode->pItem);
        if (pEntity->m_nScanCode != CWorld::ms_nCurrentScanCode) {
            pEntity->m_nScanCode = CWorld::ms_nCurrentScanCode;
            std::uint16_t modelId = pEntity->m_nModelIndex;
            if (CStreaming::ms_aInfoForModel[modelId].m_nLoadState != LOADSTATE_LOADED && !pEntity->m_bStreamingDontDelete) {
                if ((pEntity->m_nAreaCode == CGame::currArea || pEntity->m_nAreaCode == 13)
                    && !pEntity->m_bDontStream && pEntity->m_bIsVisible)
                {
                    CBaseModelInfo* pModelInfo = CModelInfo::ms_modelInfoPtrs[modelId];
                    tTimeInfo* pTimeInfo = pModelInfo->GetTimeInfo();
                    if (!pTimeInfo || CClock::GetIsTimeInRange(pTimeInfo->m_nTimeOn, pTimeInfo->m_nTimeOff))
                    {
                        if (pModelInfo->m_pRwObject && !pEntity->m_pRwObject)
                            pEntity->CreateRwObject();
                        RequestModel(pEntity->m_nModelIndex, streamingFlags);
                    }
                }
            }
        }
    }
#endif
}


void CStreaming::RetryLoadFile(int channelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x4076C0, channelId);
#else
    printf("CStreaming::RetryLoadFile called!\n");
    if (CStreaming::ms_channelError == -1)
        return CLoadingScreen::Continue();
    // CLoadingScreen::Pause(); // empty function
    if (CStreaming::ms_channelError == -1)
        return;
    tStreamingChannel& streamingChannel = CStreaming::ms_channel[channelId];
    while (true) {
        bool bStreamRead = false;
        const eStreamingLoadState loadState = streamingChannel.LoadStatus;
        if (loadState == LOADSTATE_NOT_LOADED) {
            bStreamRead = true;
        }
        else if (loadState == LOADSTATE_LOADED) {
            if (CStreaming::ProcessLoadingChannel(channelId)) {
                if (streamingChannel.LoadStatus == LOADSTATE_REQUESTED)
                    CStreaming::ProcessLoadingChannel(channelId);
                CStreaming::ms_channelError = -1;
                return CLoadingScreen::Continue();
            }
        }
        else if (loadState == LOADSTATE_CHANNELED) {
            streamingChannel.totalTries++;
            eCdStreamStatus streamStatus = CdStreamGetStatus(channelId);
            if (streamStatus != eCdStreamStatus::READING && streamStatus != eCdStreamStatus::WAITING_TO_READ)
                bStreamRead = true;
            else if (streamStatus == eCdStreamStatus::READING && CdStreamGetStatus(channelId) != eCdStreamStatus::READING)
                bStreamRead = true;
        }
        if (bStreamRead) {
            std::uint8_t* pBuffer = CStreaming::ms_pStreamingBuffer[channelId];
            CdStreamRead(channelId, pBuffer, streamingChannel.offsetAndHandle, streamingChannel.sectorCount);
            streamingChannel.LoadStatus = LOADSTATE_LOADED;
            streamingChannel.iLoadingLevel = -600;
        }
        if (CStreaming::ms_channelError == -1)
            return CLoadingScreen::Continue();
    }
#endif
}


void CStreaming::LoadRequestedModels()
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::Call<0x40E3A0>();
#else
    static std::int32_t currentChannel = 0;
    if (ms_bLoadingBigModel)
        currentChannel = 0;
    const tStreamingChannel& channel = ms_channel[currentChannel];
    if (channel.LoadStatus != LOADSTATE_NOT_LOADED)
        ProcessLoadingChannel(currentChannel);
    if (!ms_bLoadingBigModel) {
        const std::int32_t otherChannelId = 1 - currentChannel;
        if (ms_channel[otherChannelId].LoadStatus == LOADSTATE_NOT_LOADED)
            RequestModelStream(otherChannelId);
        if (channel.LoadStatus == LOADSTATE_NOT_LOADED && !ms_bLoadingBigModel)
            RequestModelStream(currentChannel);
    }
    if (channel.LoadStatus != LOADSTATE_REQUESTED)
        currentChannel = 1 - currentChannel;
#endif
}

void CStreaming::FlushRequestList()
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x40E4E0>();
#else
    auto streamingInfo = ms_pStartRequestedList->GetNext();
    while (streamingInfo != ms_pEndRequestedList) {
        auto nextStreamingInfo = streamingInfo->GetNext();
        RemoveModel(streamingInfo - ms_aInfoForModel);
        streamingInfo = nextStreamingInfo;
    }
    FlushChannels();
#endif
}

bool CStreaming::AddToLoadedVehiclesList(std::int32_t modelId)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, std::int32_t>(0x408000, modelId);
#else
    auto pVehicleModelInfo = reinterpret_cast<CVehicleModelInfo*>(CModelInfo::ms_modelInfoPtrs[modelId]);
    pVehicleModelInfo->m_nTimesUsed = 0;
    CLoadedCarGroup* pLoadedCarGroup = nullptr;
    const std::int32_t numBoats = CPopulation::m_nNumCarsInGroup[POPCYCLE_CARGROUP_BOATS];
    for (std::int32_t i = 0; i < numBoats; i++) {
        if (CPopulation::m_CarGroups[POPCYCLE_CARGROUP_BOATS][i] == modelId) {
            pLoadedCarGroup = &CPopulation::m_LoadedBoats;
            break;
        }
    }
    if (!pLoadedCarGroup) {
        pLoadedCarGroup = &CPopulation::m_AppropriateLoadedCars;
        if (!IsCarModelNeededInCurrentZone(modelId))
            pLoadedCarGroup = &CPopulation::m_InAppropriateLoadedCars;
    }
    pLoadedCarGroup->AddMember(modelId);
    for (std::int32_t gangId = 0; gangId < TOTAL_GANGS; gangId++) {
        const std::int32_t groupId = gangId + POPCYCLE_CARGROUP_BALLAS;
        const std::uint16_t numCarsInGroup = CPopulation::m_nNumCarsInGroup[groupId];
        for (std::int32_t i = 0; i < numCarsInGroup; i++) {
            const std::int32_t vehicleModelId = CPopulation::m_CarGroups[groupId][i];
            if (vehicleModelId == modelId) {
                CPopulation::m_LoadedGangCars[gangId].AddMember(modelId);
                break;
            }
        }
    }
    ms_vehiclesLoaded.AddMember(modelId);
    return true;
#endif
}

std::int32_t CStreaming::GetDefaultCabDriverModel()
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int>(0x407D50);
#else
    static std::int32_t randomIndex = 0;
    const std::int32_t defaultCabDriverModels[7] = { MODEL_BMOCD, MODEL_WMYCD1, MODEL_SBMOCD,
        MODEL_SWMOCD, MODEL_VBMOCD , MODEL_VWMYCD, -1 };
    const std::int32_t modelId = defaultCabDriverModels[randomIndex];
    if (!CStreaming::ms_aInfoForModel[modelId].m_nLoadState) {
        if (CTheZones::m_CurrLevel) {
            // Original code:
            // randomIndex = CGeneral::GetRandomNumberInRange(0, 2 * CTheZones::m_CurrLevel);
            // This can actually cause a crash since CStreaming::ms_aDefaultCabDriverModel[6] is always -1
            // so, let's fix it 
            randomIndex = CGeneral::GetRandomNumberInRange(0, std::min(5, 2 * CTheZones::m_CurrLevel));
        }
        return defaultCabDriverModels[randomIndex];
    }
    return modelId;
#endif
}

int CStreaming::GetDefaultCopCarModel(int ignoreLvpd1Model) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int, unsigned int>(0x407C50, ignoreLvpd1Model);
#else
    int carModelId = ms_DefaultCopBikeModel;
    if (!m_bCopBikeLoaded || ignoreLvpd1Model ||
        ms_aInfoForModel[ms_DefaultCopBikerModel].m_nLoadState != LOADSTATE_LOADED ||
        ms_aInfoForModel[ms_DefaultCopBikeModel].m_nLoadState != LOADSTATE_LOADED)
    {
        carModelId = ms_aDefaultCopCarModel[CTheZones::m_CurrLevel];
        if (ms_aInfoForModel[ms_aDefaultCopModel[CTheZones::m_CurrLevel]].m_nLoadState != LOADSTATE_LOADED
            || ms_aInfoForModel[carModelId].m_nLoadState != LOADSTATE_LOADED)
        {
            int elementCount = 4;
            if (ignoreLvpd1Model)
                elementCount = 3;
            for (int i = 0; i < elementCount; i++) {
                unsigned char copModelLoadState = ms_aInfoForModel[ms_aDefaultCopModel[i]].m_nLoadState;
                unsigned char copCarModelLoadState = ms_aInfoForModel[ms_aDefaultCopCarModel[i]].m_nLoadState;
                if (copModelLoadState == LOADSTATE_LOADED && copCarModelLoadState == LOADSTATE_LOADED) {
                    return ms_aDefaultCopCarModel[i];
                }
            }
            return -1;
        }
    }
    return carModelId;
#endif
}

std::int32_t CStreaming::GetDefaultCopModel()
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int>(0x407C00);
#else
    const std::int32_t modelId = ms_aDefaultCopModel[CTheZones::m_CurrLevel];
    if (ms_aInfoForModel[modelId].m_nLoadState == LOADSTATE_LOADED)
        return modelId;
    for (std::int32_t i = 0; i < 4; i++) {
        const std::int32_t copModelId = ms_aDefaultCopModel[i];
        if (ms_aInfoForModel[copModelId].m_nLoadState == LOADSTATE_LOADED)
            return copModelId;
    }
    return -1;
#endif
}

int CStreaming::GetDefaultFiremanModel() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int>(0x407D40);
#else
    return ms_aDefaultFiremanModel[CTheZones::m_CurrLevel];
#endif
}

int CStreaming::GetDefaultMedicModel() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<int>(0x407D20);
#else
    return ms_aDefaultMedicModel[CTheZones::m_CurrLevel];
#endif
}

void CStreaming::Init()
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x5B9020>();
#else
    Init2();
#endif
}

void CStreaming::Init2()
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x5B8AD0>();
#else
    for (std::int32_t modelId = 0; modelId < RESOURCE_ID_TOTAL; modelId++) {
        ms_aInfoForModel[modelId].Init();
    }
    CStreamingInfo::ms_pArrayBase = &ms_aInfoForModel[0];
    ms_startLoadedList = &ms_aInfoForModel[RESOURCE_ID_INTERNAL_1];
    ms_pEndLoadedList = &ms_aInfoForModel[RESOURCE_ID_INTERNAL_2];
    ms_pStartRequestedList = &ms_aInfoForModel[RESOURCE_ID_INTERNAL_3];
    ms_pEndRequestedList = &ms_aInfoForModel[RESOURCE_ID_INTERNAL_4];
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_1].m_nNextIndex = RESOURCE_ID_INTERNAL_2;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_1].m_nPrevIndex = -1;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_2].m_nNextIndex = -1;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_2].m_nPrevIndex = RESOURCE_ID_INTERNAL_1;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_3].m_nNextIndex = RESOURCE_ID_INTERNAL_4;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_3].m_nPrevIndex = -1;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_4].m_nNextIndex = -1;
    ms_aInfoForModel[RESOURCE_ID_INTERNAL_4].m_nPrevIndex = RESOURCE_ID_INTERNAL_3;
    //ms_oldSectorX = 0; // Unused
    //ms_oldSectorY = 0; // Unused
    ms_aInfoForModel[374].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[375].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[376].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[377].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[378].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[379].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[380].m_nLoadState = LOADSTATE_LOADED;
    ms_aInfoForModel[381].m_nLoadState = LOADSTATE_LOADED;
    ms_streamingBufferSize = 0;
    ms_disableStreaming = false;
    ms_memoryUsed = 0;
    ms_channelError = -1;
    ms_bLoadingBigModel = false;
    ms_bEnableRequestListPurge = true;
    m_bStreamHarvesterModelsThisFrame = false;
    m_bHarvesterModelsRequested = false;
    for (int channelId = 0; channelId < 2; channelId++) {
        tStreamingChannel& streamingChannel = ms_channel[channelId];
        streamingChannel.LoadStatus = LOADSTATE_NOT_LOADED;
        for (std::int32_t i = 0; i < 16; i++) {
            streamingChannel.modelIds[i] = -1;
        }
    }
    for (std::int32_t i = 0; i < TOTAL_DFF_MODEL_IDS; i++) {
        const std::int32_t modelId = i + RESOURCE_ID_DFF;
        auto pBaseModelnfo = CModelInfo::ms_modelInfoPtrs[modelId];
        CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
        if (pBaseModelnfo && pBaseModelnfo->m_pRwObject) {
            auto pAtomicModelInfo = pBaseModelnfo->AsAtomicModelInfoPtr();
            streamingInfo.m_nFlags = 0;
            streamingInfo.m_nFlags |= STREAMING_GAME_REQUIRED;
            streamingInfo.m_nLoadState = LOADSTATE_LOADED;
            if (pAtomicModelInfo)
                pAtomicModelInfo->m_nAlpha = 255;
        }
    }
    for (std::int32_t i = 0; i < TOTAL_TXD_MODEL_IDS; i++) {
        const std::int32_t modelId = i + RESOURCE_ID_TXD;
        CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
        TxdDef* pTxd = CTxdStore::ms_pTxdPool->GetAt(i);
        if (pTxd && pTxd->m_pRwDictionary) {
            streamingInfo.m_nLoadState = LOADSTATE_LOADED;
        }
    }
    ms_vehiclesLoaded.Clear();
    for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
        ms_pedsLoaded[i] = -1;
    }
    ms_numPedsLoaded = 0;
    for (std::int32_t i = 0; i < 18; i++) {
        ms_NextPedToLoadFromGroup[i] = 0;
    }
    ms_pExtraObjectsDir = new CDirectory(550);
    ms_currentZoneType = -1;
    ms_loadedGangs = 0;
    ms_lastCullZone = -1;
    ms_numPriorityRequests = 0;
    CTheScripts::StreamedScripts.Initialise();
    // ms_streamingBufferSize is 0 at this point.
    // After calling LoadCdDirectory, ms_streamingBufferSize will contain the maximum number 
    // of memory blocks/sectors used for a streaming model, like txd, dff, col, ipl, scm, etc.
    // The size of one streaming sector is STREAMING_BLOCK_SIZE by default.
    LoadCdDirectory();
    if (ms_streamingBufferSize & 1) // check if the value of ms_streamingBufferSize is odd 
        ms_streamingBufferSize++; // make it even by adding 1

    // Since gta sa streamer runs on a secondary thread, if two models can fit
    // inside this one big buffer (one model goes in the 1st half of the buffer, the other
    // model goes in the second half), it will load the two models together.
    // Hence ms_pStreamingBuffer[0] is used by 1st channel and ms_pStreamingBuffer[1] is used by the 2nd channel.
    // If a model is big, and it cannot fit in half of the buffer, then the entire buffer is used,
    // and the model is loaded alone.

    // Here, ms_streamingBufferSize * STREAMING_BLOCK_SIZE = maximum size in bytes that a streaming model can possibly have.
    const std::uint32_t maximumModelSizeInBytes = ms_streamingBufferSize * STREAMING_SECTOR_SIZE;
    ms_pStreamingBuffer[0] = CMemoryMgr::MallocAlign(maximumModelSizeInBytes, STREAMING_SECTOR_SIZE);
    ms_streamingBufferSize /= 2;
    ms_pStreamingBuffer[1] = &ms_pStreamingBuffer[0][STREAMING_SECTOR_SIZE * ms_streamingBufferSize];
    ms_memoryAvailable = 52428800;
    desiredNumVehiclesLoaded = 22;
    ms_rwObjectInstances.Init(12000);
    ms_bIsInitialised = true;
#endif
}

void CStreaming::InitImageList() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x4083C0);
#else
    for (std::int32_t i = 0; i < TOTAL_IMG_ARCHIVES; i++) {
        ms_files[i].m_szName[0] = 0;
        ms_files[i].m_StreamHandle = 0;
    }
    AddImageToList("MODELS\\GTA3.IMG", true);
    AddImageToList("MODELS\\GTA_INT.IMG", true);
#endif
}

void CStreaming::InstanceLoadedModels(CVector const& point) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x4084F0, point);
#else
    float fRadius = 80.0f;
    if (CGame::currArea)
        fRadius = 40.0f;
    const float minX = point.x - fRadius;
    const float maxX = point.x + fRadius;
    const float minY = point.y - fRadius;
    const float maxY = point.y + fRadius;
    std::int32_t startSectorX = std::max(CWorld::GetSectorX(minX), 0);
    std::int32_t startSectorY = std::max(CWorld::GetSectorY(minY), 0);
    std::int32_t endSectorX = std::min(CWorld::GetSectorX(maxX), MAX_SECTORS_X - 1);
    std::int32_t endSectorY = std::min(CWorld::GetSectorY(maxY), MAX_SECTORS_Y - 1);
    for (std::int32_t sectorY = startSectorY; sectorY <= endSectorY; ++sectorY) {
        for (std::int32_t sectorX = startSectorX; sectorX <= endSectorX; ++sectorX) {
            CRepeatSector* pRepeatSector = GetRepeatSector(sectorX, sectorY);
            CSector* pSector = GetSector(sectorX, sectorY);
            InstanceLoadedModelsInSectorList(pSector->m_buildings);
            InstanceLoadedModelsInSectorList(pRepeatSector->m_lists[REPEATSECTOR_OBJECTS]);
            InstanceLoadedModelsInSectorList(pSector->m_dummies);
        }
    }
#endif
}

void CStreaming::InstanceLoadedModelsInSectorList(CPtrList& list)
{
    for (CPtrNode* pNode = list.GetNode(); pNode; pNode = pNode->pNext) {
        CEntity* pEntity = reinterpret_cast<CEntity*>(pNode->pItem);
        if ((pEntity->m_nAreaCode == CGame::currArea || pEntity->m_nAreaCode == 13) && !pEntity->m_pRwObject)
            pEntity->CreateRwObject();
    }
}

bool CStreaming::IsCarModelNeededInCurrentZone(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, int>(0x407DD0, modelId);
#else
    CZoneInfo* pCurrentZoneInfo = CPopCycle::m_pCurrZoneInfo;
    if (!CPopCycle::m_pCurrZoneInfo)
        return false;
    if (CCheat::m_aCheatsActive[CHEAT_BEACH_PARTY])
        return CPopulation::DoesCarGroupHaveModelId(POPCYCLE_CARGROUP_BEACHFOLK, modelId);
    if (CCheat::m_aCheatsActive[CHEAT_COUNTRY_TRAFFIC])
        return CPopulation::DoesCarGroupHaveModelId(POPCYCLE_CARGROUP_FARMERS, modelId);
    if (CCheat::m_aCheatsActive[CHEAT_CHEAP_TRAFFIC])
        return CPopulation::DoesCarGroupHaveModelId(POPCYCLE_CARGROUP_CHEAT1, modelId);
    if (CCheat::m_aCheatsActive[CHEAT_FAST_TRAFFIC])
        return CPopulation::DoesCarGroupHaveModelId(POPCYCLE_CARGROUP_CHEAT2, modelId);
    if (CCheat::m_aCheatsActive[CHEAT_NINJA_THEME])
        return CPopulation::DoesCarGroupHaveModelId(POPCYCLE_CARGROUP_CHEAT3, modelId);
    if (CCheat::m_aCheatsActive[CHEAT_FUNHOUSE_THEME])
        return CPopulation::DoesCarGroupHaveModelId(POPCYCLE_CARGROUP_CHEAT4, modelId);
    for (std::int32_t groupId = 0; groupId < POPCYCLE_TOTAL_GROUP_PERCS; groupId++) {
        if (CPopCycle::GetCurrentPercTypeGroup(groupId, pCurrentZoneInfo->zonePopulationType) &&
            CPopulation::DoesCarGroupHaveModelId(groupId, modelId)) {
            return true;
        }
    }
    for (std::int32_t groupId = 0; groupId < TOTAL_GANGS; groupId++) {
        if (pCurrentZoneInfo->GangDensity[groupId] && CPopulation::DoesCarGroupHaveModelId(groupId, modelId))
            return true;
    }
    return false;
#endif
}

bool CStreaming::IsInitialised() {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool>(0x407600);
#else
    return ms_bIsInitialised;
#endif
}

bool CStreaming::IsObjectInCdImage(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, int>(0x407800, modelId);
#else
    return ms_aInfoForModel[modelId].m_nCdSize != 0;
#endif
}

void CStreaming::Save() {
    plugin::CallDynGlobal(0x5D29A0);
}

void CStreaming::SetLoadVehiclesInLoadScene(bool bEnable) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<bool>(0x407A30, bEnable);
#else
    ms_bLoadVehiclesInLoadScene = bEnable;
#endif
}

void CStreaming::SetMissionDoesntRequireAnim(int slot) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x48B570, slot);
#else
    SetMissionDoesntRequireModel(slot + RESOURCE_ID_IFP);
#endif
}

void CStreaming::SetMissionDoesntRequireModel(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x409C90, modelId);
#else
    for (std::int32_t i = modelId; ; i = CModelInfo::ms_modelInfoPtrs[i]->m_nTxdIndex + RESOURCE_ID_TXD) {
        CStreamingInfo& streamingInfo = CStreaming::ms_aInfoForModel[i];
        streamingInfo.m_nFlags &= ~STREAMING_MISSION_REQUIRED;
        if (!(streamingInfo.m_nFlags & STREAMING_GAME_REQUIRED)) {
            if (streamingInfo.m_nLoadState == LOADSTATE_LOADED) {
                if (!streamingInfo.InList())
                    streamingInfo.AddToList(ms_startLoadedList);
            }
            else if (!(streamingInfo.m_nFlags & STREAMING_KEEP_IN_MEMORY)) {
                RemoveModel(i);
            }
        }
        if (i >= RESOURCE_ID_TXD)
            break;
    }
#endif
}

void CStreaming::SetMissionDoesntRequireSpecialChar(int slot) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40B490, slot);
#else
    SetMissionDoesntRequireModel(slot + SPECIAL_MODELS_RESOURCE_ID);
#endif
}

void CStreaming::SetModelIsDeletable(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x409C10, modelId);
#else
    CStreamingInfo& streamingInfo = ms_aInfoForModel[modelId];
    streamingInfo.m_nFlags &= ~STREAMING_GAME_REQUIRED;
    if (!(streamingInfo.m_nFlags & STREAMING_MISSION_REQUIRED)) {
        if (streamingInfo.m_nLoadState == LOADSTATE_LOADED) {
            if (!streamingInfo.InList())
                streamingInfo.AddToList(ms_startLoadedList);
        }
        else if (!(streamingInfo.m_nFlags & STREAMING_KEEP_IN_MEMORY)) {
            RemoveModel(modelId);
        }
    }
#endif
}

void CStreaming::SetModelTxdIsDeletable(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x409C70, modelId);
#else
    SetModelIsDeletable(CModelInfo::ms_modelInfoPtrs[modelId]->m_nTxdIndex + RESOURCE_ID_TXD);
#endif
}

void CStreaming::SetSpecialCharIsDeletable(int slot) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40B470, slot);
#else
    SetModelIsDeletable(slot + SPECIAL_MODELS_RESOURCE_ID);
#endif
}

void CStreaming::Shutdown() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x4084B0);
#else
    CMemoryMgr::FreeAlign(ms_pStreamingBuffer[0]);
    ms_streamingBufferSize = 0;
    if (ms_pExtraObjectsDir)
        delete ms_pExtraObjectsDir;
#endif
}

void CStreaming::StartRenderEntities() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x4096C0);
#else
    ms_renderEntityLink = &ms_rwObjectInstances.usedListHead;
#endif
}

bool CStreaming::StreamAmbulanceAndMedic(bool bStreamForAccident) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, bool>(0x40A2A0, bStreamForAccident);
#else
    for (std::int32_t i = 1; i < 4; i++) {
        SetModelIsDeletable(ms_aDefaultMedicModel[i]);
        SetModelTxdIsDeletable(ms_aDefaultMedicModel[i]);
    }
    for (std::int32_t i = 1; i < 4; i++) {
        SetModelIsDeletable(ms_aDefaultAmbulanceModel[i]);
        SetModelTxdIsDeletable(ms_aDefaultAmbulanceModel[i]);
    }
    if (!CTheZones::m_CurrLevel || !bStreamForAccident)
        return false;
    std::int32_t medicModel = ms_aDefaultMedicModel[CTheZones::m_CurrLevel];
    std::int32_t ambulanceModel = ms_aDefaultAmbulanceModel[CTheZones::m_CurrLevel];
    RequestModel(medicModel, STREAMING_KEEP_IN_MEMORY);
    RequestModel(ambulanceModel, STREAMING_KEEP_IN_MEMORY);
    const CStreamingInfo& medicInfo = ms_aInfoForModel[medicModel];
    const CStreamingInfo& ambulanceInfo = ms_aInfoForModel[ambulanceModel];
    if (medicInfo.m_nLoadState != LOADSTATE_LOADED || ambulanceInfo.m_nLoadState != LOADSTATE_LOADED)
        return false;
    return true;
#endif
}

void CStreaming::StreamCopModels(int level) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40A150, level);
#else
    if (CGame::currArea)
        return;
    if (FindPlayerWanted(-1) && FindPlayerWanted(-1)->m_nWantedLevel < 3 && level && !m_bDisableCopBikes) {
        const std::uint32_t timeInMs = CTimer::m_snTimeInMilliseconds;
        if (ms_nTimePassedSinceLastCopBikeStreamedIn < timeInMs) {
            m_bCopBikeLoaded = !m_bCopBikeLoaded;
            ms_nTimePassedSinceLastCopBikeStreamedIn = timeInMs + CGeneral::GetRandomNumberInRange(30000, 50000);
        }
        if (m_bCopBikeLoaded)
            level = 4;
    }
    else {
        m_bCopBikeLoaded = false;
    }
    const CStreamingInfo& copModelInfo = ms_aInfoForModel[ms_aDefaultCopModel[level]];
    const CStreamingInfo& copCarModelInfo = ms_aInfoForModel[ms_aDefaultCopCarModel[level]];
    if (copModelInfo.m_nLoadState == LOADSTATE_LOADED && copCarModelInfo.m_nLoadState == LOADSTATE_LOADED) {
        for (std::int32_t i = 0; i < 4; i++) {
            if (i != level) {
                if (level != 4) {
                    SetModelIsDeletable(ms_aDefaultCopModel[i]);
                    SetModelTxdIsDeletable(ms_aDefaultCopModel[i]);
                }
                SetModelIsDeletable(ms_aDefaultCopCarModel[i]);
                SetModelTxdIsDeletable(ms_aDefaultCopCarModel[i]);
            }
        }
    }
    RequestModel(ms_aDefaultCopModel[level], STREAMING_GAME_REQUIRED);
    RequestModel(ms_aDefaultCopCarModel[level], STREAMING_GAME_REQUIRED);
#endif
}

bool CStreaming::StreamFireEngineAndFireman(bool bStreamForFire) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, bool>(0x40A400, bStreamForFire);
#else
    for (std::int32_t i = 1; i < 4; i++) {
        SetModelIsDeletable(ms_aDefaultFiremanModel[i]);
        SetModelTxdIsDeletable(ms_aDefaultFiremanModel[i]);
    }
    for (std::int32_t i = 1; i < 4; i++) {
        SetModelIsDeletable(ms_aDefaultFireEngineModel[i]);
        SetModelTxdIsDeletable(ms_aDefaultFireEngineModel[i]);
    }
    if (!CTheZones::m_CurrLevel || !bStreamForFire)
        return false;
    std::int32_t firemanModel = ms_aDefaultFiremanModel[CTheZones::m_CurrLevel];
    std::int32_t fireTruckModel = ms_aDefaultFireEngineModel[CTheZones::m_CurrLevel];
    RequestModel(firemanModel, STREAMING_KEEP_IN_MEMORY);
    RequestModel(fireTruckModel, STREAMING_KEEP_IN_MEMORY);
    const CStreamingInfo& firemanInfo = ms_aInfoForModel[firemanModel];
    const CStreamingInfo& fireTruckInfo = ms_aInfoForModel[fireTruckModel];
    if (firemanInfo.m_nLoadState != LOADSTATE_LOADED || fireTruckInfo.m_nLoadState != LOADSTATE_LOADED)
        return false;
    return true;
#endif
}

void CStreaming::StreamOneNewCar() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40B4F0);
#else
    if (!CPopCycle::m_pCurrZoneInfo)
        return;
    bool bCheatActive = false;
    std::int32_t carGroupId = 0;
    if (CCheat::m_aCheatsActive[CHEAT_BEACH_PARTY]) {
        carGroupId = POPCYCLE_CARGROUP_BEACHFOLK;
        bCheatActive = true;
    }
    if (CCheat::m_aCheatsActive[CHEAT_COUNTRY_TRAFFIC]) {
        carGroupId = POPCYCLE_CARGROUP_FARMERS;
        bCheatActive = true;
    }
    if (CCheat::m_aCheatsActive[CHEAT_CHEAP_TRAFFIC]) {
        carGroupId = POPCYCLE_CARGROUP_CHEAT1;
        bCheatActive = true;
    }
    if (CCheat::m_aCheatsActive[CHEAT_FAST_TRAFFIC]) {
        carGroupId = POPCYCLE_CARGROUP_CHEAT2;
        bCheatActive = true;
    }
    if (CCheat::m_aCheatsActive[CHEAT_NINJA_THEME]) {
        carGroupId = POPCYCLE_CARGROUP_CHEAT3;
        bCheatActive = true;
    }
    if (CCheat::m_aCheatsActive[CHEAT_FUNHOUSE_THEME]) {
        carGroupId = POPCYCLE_CARGROUP_CHEAT4;
        bCheatActive = true;
    }
    if (bCheatActive) {
        std::int32_t carModelId = CCarCtrl::ChooseCarModelToLoad(carGroupId);
        if (carModelId < 0)
            return;
        RequestModel(carModelId, STREAMING_KEEP_IN_MEMORY);
        CPopulation::LoadSpecificDriverModelsForCar(carModelId);
        return;
    }
    if (m_bBoatsNeeded && (CPopulation::m_LoadedBoats.CountMembers() < 2 ||
        CPopulation::m_LoadedBoats.CountMembers() <= 2 && (rand() & 7) == 3)) {
        std::int32_t carModelId = CCarCtrl::ChooseCarModelToLoad(POPCYCLE_CARGROUP_BOATS);
        if (carModelId >= 0) {
            RequestModel(carModelId, STREAMING_KEEP_IN_MEMORY);
            CPopulation::LoadSpecificDriverModelsForCar(carModelId);
            return;
        }
    }
    std::int32_t carModelId = -1;
    if (ms_aInfoForModel[MODEL_TAXI].m_nLoadState != LOADSTATE_LOADED
        && ms_aInfoForModel[MODEL_CABBIE].m_nLoadState != LOADSTATE_LOADED) {
        static std::int32_t lastCarModelStreamedIn = MODEL_TAXI;
        if (lastCarModelStreamedIn == MODEL_TAXI) {
            if (!IsCarModelNeededInCurrentZone(MODEL_CABBIE)) {
                if (IsCarModelNeededInCurrentZone(MODEL_TAXI)) {
                    carModelId = MODEL_TAXI;
                    lastCarModelStreamedIn = carModelId;
                }
            }
        }
        else {
            if (IsCarModelNeededInCurrentZone(MODEL_TAXI)) {
                carModelId = MODEL_TAXI;
                lastCarModelStreamedIn = carModelId;
            }
            else if (IsCarModelNeededInCurrentZone(MODEL_CABBIE)) {
                carModelId = MODEL_CABBIE;
                lastCarModelStreamedIn = carModelId;
            }
        }
    }
    if (carModelId < 0) {
        std::int32_t carGroupId = CPopCycle::PickARandomGroupOfOtherPeds();
        carModelId = CCarCtrl::ChooseCarModelToLoad(carGroupId);
        if (carModelId < 0)
            return;
    }
    RequestModel(carModelId, STREAMING_KEEP_IN_MEMORY);
    CPopulation::LoadSpecificDriverModelsForCar(carModelId);
    return;
#endif
}

void CStreaming::StreamPedsForInterior(int interiorType) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int>(0x40BBB0, interiorType);
#else
    if (interiorType == 0) {
        std::int32_t numHusbands = CPopulation::GetNumPedsInGroup(POPCYCLE_GROUP_HUSBANDS, 0);
        std::int32_t randomHusband = rand() % numHusbands;
        std::int32_t random = CGeneral::GetRandomNumberInRange(3, 9);
        std::int32_t randomWife = std::max(0, randomHusband - random);
        std::int32_t numWives = CPopulation::GetNumPedsInGroup(POPCYCLE_GROUP_WIVES, 0);
        if (numWives - 1 < randomWife)
            randomWife = numWives - 1;
        ePopcyclePedGroup husbandGroupId = CPopulation::GetPedGroupId(POPCYCLE_GROUP_HUSBANDS, CPopulation::CurrentWorldZone);
        std::int32_t husbandModelId = CPopulation::GetPedGroupModelId(husbandGroupId, randomHusband);
        ePopcyclePedGroup wifeGroupId = CPopulation::GetPedGroupId(POPCYCLE_GROUP_WIVES, CPopulation::CurrentWorldZone);
        std::int32_t wifeModelId = CPopulation::GetPedGroupModelId(wifeGroupId, randomWife);
        ClearSlots(2);
        RequestModel(husbandModelId, STREAMING_KEEP_IN_MEMORY);
        ms_pedsLoaded[0] = husbandModelId;
        ms_numPedsLoaded++;
        RequestModel(wifeModelId, STREAMING_KEEP_IN_MEMORY);
        ms_pedsLoaded[1] = wifeModelId;
        ms_numPedsLoaded++;
    }
    else if (interiorType == 1) {
        std::int32_t numPeds = CPopulation::GetNumPedsInGroup(POPCYCLE_GROUP_SHOPKEEPERS, 0);
        ePopcyclePedGroup groupId = CPopulation::GetPedGroupId(POPCYCLE_GROUP_SHOPKEEPERS, CPopulation::CurrentWorldZone);
        std::int32_t modelId = CPopulation::GetPedGroupModelId(groupId, rand() % numPeds);
        ClearSlots(1);
        RequestModel(modelId, STREAMING_KEEP_IN_MEMORY);
        ms_pedsLoaded[0] = modelId;
        ms_numPedsLoaded++;
    }
    else if (interiorType == 2) {
        ClearSlots(TOTAL_LOADED_PEDS);
        std::int32_t numPeds = CPopulation::GetNumPedsInGroup(POPCYCLE_GROUP_OFFICE_WORKERS, 0);
        std::int32_t random = CGeneral::GetRandomNumberInRange(0, numPeds);
        ePopcyclePedGroup groupId = CPopulation::GetPedGroupId(POPCYCLE_GROUP_OFFICE_WORKERS, CPopulation::CurrentWorldZone);
        for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
            std::int32_t modelId = CPopulation::GetPedGroupModelId(groupId, (i + random) % numPeds);
            RequestModel(modelId, STREAMING_KEEP_IN_MEMORY);
            ms_pedsLoaded[i] = modelId;
            ms_numPedsLoaded++;
        }
    }
#endif
}

void CStreaming::StreamPedsIntoRandomSlots(int* modelArray) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<int*>(0x40BDA0, modelArray);
#else
    for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
        std::int32_t modelId = ms_pedsLoaded[i];
        std::int32_t pedModelId = modelArray[i];
        if (pedModelId >= 0) {
            if (modelId >= 0) {
                SetModelIsDeletable(modelId);
                SetModelTxdIsDeletable(modelId);
                ms_pedsLoaded[i] = -1;
                ms_numPedsLoaded--;
            }
            RequestModel(pedModelId, STREAMING_KEEP_IN_MEMORY);
            ms_pedsLoaded[i] = pedModelId;
            ms_numPedsLoaded++;
        }
        else if (pedModelId == -2) {
            if (modelId >= 0) {
                SetModelIsDeletable(modelId);
                SetModelTxdIsDeletable(modelId);
                ms_pedsLoaded[i] = -1;
                ms_numPedsLoaded--;
            }
        }
    }
#endif
}

void CStreaming::StreamVehiclesAndPeds() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40B700);
#else
    StreamCopModels(CTheZones::m_CurrLevel);
    CWanted* pWanted = FindPlayerWanted(-1);
    if (pWanted->AreSwatRequired()) {
        RequestModel(MODEL_ENFORCER, STREAMING_GAME_REQUIRED);
        RequestModel(MODEL_SWAT, STREAMING_GAME_REQUIRED);
    }
    else {
        SetModelIsDeletable(MODEL_ENFORCER);
        if (ms_aInfoForModel[MODEL_ENFORCER].m_nLoadState != LOADSTATE_LOADED)
            SetModelIsDeletable(MODEL_SWAT);
    }
    pWanted = FindPlayerWanted(-1);
    if (pWanted->AreFbiRequired()) {
        RequestModel(MODEL_FBIRANCH, STREAMING_GAME_REQUIRED);
        RequestModel(MODEL_FBI, STREAMING_GAME_REQUIRED);
    }
    else {
        SetModelIsDeletable(MODEL_FBIRANCH);
        if (ms_aInfoForModel[MODEL_FBIRANCH].m_nLoadState != LOADSTATE_LOADED)
            SetModelIsDeletable(MODEL_FBI);
    }
    pWanted = FindPlayerWanted(-1);
    if (pWanted->AreArmyRequired()) {
        RequestModel(MODEL_RHINO, STREAMING_GAME_REQUIRED);
        RequestModel(MODEL_BARRACKS, STREAMING_GAME_REQUIRED);
        RequestModel(MODEL_ARMY, STREAMING_GAME_REQUIRED);
    }
    else {
        SetModelIsDeletable(MODEL_BARRACKS);
        SetModelIsDeletable(MODEL_RHINO);
        if (ms_aInfoForModel[MODEL_BARRACKS].m_nLoadState != LOADSTATE_LOADED
            && ms_aInfoForModel[MODEL_RHINO].m_nLoadState != LOADSTATE_LOADED)
        {
            SetModelIsDeletable(MODEL_ARMY);
        }
    }
    pWanted = FindPlayerWanted(-1);
    if (pWanted->NumOfHelisRequired() <= 0) {
        SetModelIsDeletable(MODEL_VCNMAV);
        SetModelIsDeletable(MODEL_POLMAV);
    }
    else {
        RequestModel(MODEL_POLMAV, STREAMING_GAME_REQUIRED);
        pWanted = FindPlayerWanted(-1);
        if (pWanted->NumOfHelisRequired() > 1 && CWanted::bUseNewsHeliInAdditionToPolice)
            RequestModel(MODEL_VCNMAV, STREAMING_GAME_REQUIRED);
        else
            SetModelIsDeletable(MODEL_VCNMAV);
    }
    std::int32_t pedGroupId = -1;
    if (CPopCycle::m_NumDealers_Peds > 0.03f) {
        if (CWeather::WeatherRegion == WEATHER_REGION_SF) {
            pedGroupId = POPCYCLE_PEDGROUP_BUSINESS_LA;
        }
        else if (CPopCycle::m_pCurrZoneInfo)
        {
            std::uint8_t currenZoneFlags = CPopCycle::m_pCurrZoneInfo->Flags2;
            if (currenZoneFlags & 1)
                pedGroupId = 0;
            else
                pedGroupId = POPCYCLE_PEDGROUP_WORKERS_VG - ((currenZoneFlags & 2) != 0);
        }
    }
    ePopcyclePedGroup dealerGroupId = CPopulation::GetPedGroupId(POPCYCLE_GROUP_DEALERS, 0);
    for (std::int32_t i = 0; i < CPopulation::GetNumPedsInGroup(POPCYCLE_GROUP_DEALERS, 0); i++) {
        if (i == pedGroupId) {
            RequestModel(CPopulation::GetPedGroupModelId(dealerGroupId, i), STREAMING_GAME_REQUIRED);
        }
        else {
            std::int32_t modelId = CPopulation::GetPedGroupModelId(dealerGroupId, i);
            SetModelIsDeletable(modelId);
        }
        dealerGroupId = CPopulation::GetPedGroupId(POPCYCLE_GROUP_DEALERS, 0);
    }
    static std::int32_t framesBeforeStreamingNextNewCar = 0;
    if (framesBeforeStreamingNextNewCar >= 0) {
        --framesBeforeStreamingNextNewCar;
    }
    else if (ms_vehiclesLoaded.CountMembers() <= desiredNumVehiclesLoaded && CPopCycle::m_pCurrZoneInfo) {
        StreamOneNewCar();
        framesBeforeStreamingNextNewCar = 350;
    }
    if (m_bStreamHarvesterModelsThisFrame) {
        RequestModel(MI_HARVESTERBODYPART1, STREAMING_GAME_REQUIRED);
        RequestModel(MI_HARVESTERBODYPART2, STREAMING_GAME_REQUIRED);
        RequestModel(MI_HARVESTERBODYPART3, STREAMING_GAME_REQUIRED);
        RequestModel(MI_HARVESTERBODYPART4, STREAMING_GAME_REQUIRED);
        m_bHarvesterModelsRequested = true;
        m_bStreamHarvesterModelsThisFrame = 0;
    }
    else {
        if (m_bHarvesterModelsRequested) {
            RemoveModel(MI_HARVESTERBODYPART1);
            RemoveModel(MI_HARVESTERBODYPART2);
            RemoveModel(MI_HARVESTERBODYPART3);
            RemoveModel(MI_HARVESTERBODYPART4);
            m_bHarvesterModelsRequested = false;
        }
        m_bStreamHarvesterModelsThisFrame = false;
    }
#endif
}

void CStreaming::StreamVehiclesAndPeds_Always(CVector const& unused) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x40B650, unused);
#else
    bool bStream = false;
    CVehicle* pVehicle = FindPlayerVehicle(-1, 0);
    if (!pVehicle) {
        bStream = true;
    }
    else if (pVehicle->m_nVehicleSubClass != VEHICLE_PLANE) {
        if (pVehicle->m_nVehicleSubClass != VEHICLE_HELI || pVehicle->m_vecMoveSpeed.Magnitude2D() <= 0.1f) {
            bStream = true;
        }
    }
    if (bStream) {
        if (!(CTimer::m_FrameCounter & 0x3F) && CPopulation::m_AppropriateLoadedCars.CountMembers() < 3)
            StreamOneNewCar();
        StreamZoneModels_Gangs(CVector());
        if (CPopCycle::m_pCurrZoneInfo) {
            static std::int32_t lastZonePopulationType = 0;
            if (CPopCycle::m_pCurrZoneInfo->zonePopulationType != lastZonePopulationType) {
                ReclassifyLoadedCars();
                lastZonePopulationType = CPopCycle::m_pCurrZoneInfo->zonePopulationType;
            }
        }
    }
#endif
}

void CStreaming::StreamZoneModels(CVector const& unused) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x40A560, unused);
#else
    if (!CPopCycle::m_pCurrZoneInfo || CCheat::IsZoneStreamingAllowed())
        return;
    static std::int32_t timeBeforeNextLoad = 0;
    if (CPopCycle::m_pCurrZoneInfo->zonePopulationType == ms_currentZoneType) {
        if (timeBeforeNextLoad >= 0) {
            timeBeforeNextLoad--;
        }
        else {
            std::int32_t pedId = 0;
            std::int32_t modelId = 0;
            for (; pedId < TOTAL_LOADED_PEDS; pedId++) {
                modelId = ms_pedsLoaded[pedId];
                if (modelId == -1)
                    break;
                if (!CModelInfo::ms_modelInfoPtrs[modelId]->m_nRefCount)
                    break;
            }
            if (pedId != TOTAL_LOADED_PEDS) {
                std::int32_t pedModelId = CPopCycle::PickPedMIToStreamInForCurrentZone();
                if (pedModelId != modelId && pedModelId >= 0) {
                    RequestModel(pedModelId, STREAMING_KEEP_IN_MEMORY | STREAMING_GAME_REQUIRED);
                    ms_aInfoForModel[pedModelId].m_nFlags &= ~STREAMING_GAME_REQUIRED;
                    if (ms_numPedsLoaded == TOTAL_LOADED_PEDS) {
                        SetModelIsDeletable(modelId);
                        SetModelTxdIsDeletable(modelId);
                        ms_pedsLoaded[pedId] = -1;
                    }
                    else {
                        ++ms_numPedsLoaded;
                    }
                    std::int32_t freeSlot = 0;
                    for (; ms_pedsLoaded[freeSlot] >= 0; freeSlot++) {
                    }
                    ms_pedsLoaded[freeSlot] = pedModelId;
                    timeBeforeNextLoad = 300;
                }
            }
        }
    }
    else {
        std::int32_t numPedsToLoad = ms_numPedsLoaded;
        for (std::int32_t i = 0; i < TOTAL_LOADED_PEDS; i++) {
            std::int32_t modelId = ms_pedsLoaded[i];
            if (modelId >= 0) {
                SetModelIsDeletable(modelId);
                SetModelTxdIsDeletable(modelId);
                ms_pedsLoaded[i] = -1;
            }
        }
        ms_numPedsLoaded = 0;
        ms_currentZoneType = CPopCycle::m_pCurrZoneInfo->zonePopulationType;
        if (numPedsToLoad < 4)
            numPedsToLoad = 4;
        if (numPedsToLoad > 0) {
            for (std::int32_t i = 0; i < numPedsToLoad; i++) {
                std::int32_t pedModelId = CPopCycle::PickPedMIToStreamInForCurrentZone();
                if (pedModelId < 0) {
                    ms_pedsLoaded[i] = -1;
                }
                else {
                    RequestModel(pedModelId, STREAMING_KEEP_IN_MEMORY | STREAMING_GAME_REQUIRED);
                    ms_aInfoForModel[pedModelId].m_nFlags &= ~STREAMING_GAME_REQUIRED;
                    ms_pedsLoaded[i] = pedModelId;
                    ms_numPedsLoaded++;
                }
            }
        }
        timeBeforeNextLoad = 300;
    }
    static std::int32_t timeBeforeNextGangLoad = 0;
    if (timeBeforeNextGangLoad >= 0) {
        timeBeforeNextGangLoad--;
    }
    else if (timeBeforeNextGangLoad < 0) {
        timeBeforeNextGangLoad = 550;
        const std::int32_t currentGangMemberToLoadSlot = CurrentGangMemberToLoad;
        const std::int32_t nextGangMemberToLoadSlot = CurrentGangMemberToLoad + 1;
        const std::int32_t nextGangMemberToLoadAnySlot = (CurrentGangMemberToLoad + 1) % 21;
        CurrentGangMemberToLoad = nextGangMemberToLoadAnySlot;
        for (std::int32_t groupId = 0; groupId < TOTAL_GANGS; groupId++) {
            const ePopcycleGroup popcycleGroup = static_cast<ePopcycleGroup>(groupId + POPCYCLE_GROUP_BALLAS);
            const ePopcyclePedGroup pedGroupId = CPopulation::GetPedGroupId(popcycleGroup, 0);
            const std::uint16_t gang = 1 << groupId;
            if (gang & ms_loadedGangs) {
                const std::int32_t numPedsInGroup = CPopulation::GetNumPedsInGroup(pedGroupId);
                const std::int32_t currentGangMemberSlot = currentGangMemberToLoadSlot % numPedsInGroup;
                const std::int32_t nextGangMemberSlot = nextGangMemberToLoadSlot % numPedsInGroup;
                const std::int32_t nextGangMemberSlot1 = nextGangMemberToLoadAnySlot % numPedsInGroup;
                const std::int32_t nextGangMemberSlot2 = (nextGangMemberToLoadAnySlot + 1) % numPedsInGroup;
                for (std::int32_t slot = 0; slot < numPedsInGroup; slot++) {
                    bool bRequestModel = false;
                    if (slot == currentGangMemberSlot || slot == nextGangMemberSlot) {
                        if (slot == nextGangMemberSlot1) {
                            if (slot != currentGangMemberSlot && slot != nextGangMemberSlot) {
                                const std::int32_t modelId = CPopulation::GetPedGroupModelId(pedGroupId, slot);
                                RequestModel(modelId, STREAMING_GAME_REQUIRED);
                            }
                        }
                        else if (slot == nextGangMemberSlot2) {
                            bRequestModel = true;
                        }
                        else {
                            const std::int32_t modelId = CPopulation::GetPedGroupModelId(pedGroupId, slot);
                            SetModelIsDeletable(modelId);
                            SetModelTxdIsDeletable(modelId);
                        }
                    }
                    else {
                        bRequestModel = true;
                    }
                    if (bRequestModel) {
                        if (slot == nextGangMemberSlot1 || slot == nextGangMemberSlot2) {
                            if (slot != currentGangMemberSlot && slot != nextGangMemberSlot) {
                                const std::int32_t modelId = CPopulation::GetPedGroupModelId(pedGroupId, slot);
                                RequestModel(modelId, STREAMING_GAME_REQUIRED);
                            }
                        }
                    }
                }
            }
        }
    }
#endif
}

void CStreaming::StreamZoneModels_Gangs(CVector const& unused) {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal<CVector const&>(0x40AA10, unused);
#else
    if (!CPopCycle::m_pCurrZoneInfo)
        return;
    std::int32_t gangsNeeded = 0;
    for (std::int32_t i = 0; i < TOTAL_GANGS; i++) {
        if (CPopCycle::m_pCurrZoneInfo->GangDensity[i])
            gangsNeeded |= (1 << i);
    }
    if (CCheat::m_aCheatsActive[CHEAT_GANGS_CONTROLS_THE_STREETS])
        gangsNeeded |= 0xFF;
    CGangWars::TellStreamingWhichGangsAreNeeded(&gangsNeeded);
    if (gangsNeeded == ms_loadedGangs && gangsNeeded == ms_loadedGangCars)
        return;
    for (std::int32_t groupId = 0; groupId < TOTAL_GANGS; groupId++) {
        const ePopcycleGroup popcycleGroup = static_cast<ePopcycleGroup>(groupId + POPCYCLE_GROUP_BALLAS);
        const ePopcyclePedGroup pedGroupId = CPopulation::GetPedGroupId(popcycleGroup, 0);
        const std::uint16_t gang = 1 << groupId;
        if (!(gangsNeeded & gang) || ms_loadedGangs & gang) {
            if (!(gangsNeeded & gang) && ms_loadedGangs & gang) {
                for (int32_t i = 0; i < CPopulation::GetNumPedsInGroup(pedGroupId); ++i) {
                    std::int32_t modelId = CPopulation::GetPedGroupModelId(pedGroupId, i);
                    SetModelIsDeletable(modelId);
                    SetModelTxdIsDeletable(modelId);
                }
                ms_loadedGangs &= ~gang;
            }
        }
        else {
            std::int32_t slot1 = CurrentGangMemberToLoad % CPopulation::GetNumPedsInGroup(pedGroupId);
            std::int32_t modelId1 = CPopulation::GetPedGroupModelId(pedGroupId, slot1);
            std::int32_t slot2 = (CurrentGangMemberToLoad + 1) % CPopulation::GetNumPedsInGroup(pedGroupId);
            std::int32_t modelId2 = CPopulation::GetPedGroupModelId(pedGroupId, slot2);
            RequestModel(modelId1, STREAMING_KEEP_IN_MEMORY);
            RequestModel(modelId2, STREAMING_KEEP_IN_MEMORY);
            ms_loadedGangs |= gang;
        }
        CLoadedCarGroup& loadedGangCarGroup = CPopulation::m_LoadedGangCars[groupId];
        if (loadedGangCarGroup.CountMembers() < 1) {
            if (!(gangsNeeded & gang) || ms_loadedGangCars & gang) {
                if (!(gangsNeeded & gang) && (ms_loadedGangCars & gang)) {
                    CLoadedCarGroup loadedCarGroup;
                    memcpy(&loadedCarGroup, &loadedGangCarGroup, sizeof(loadedCarGroup));
                    for (std::int32_t memberId = 0; memberId < loadedCarGroup.CountMembers(); memberId++) {
                        std::int32_t gangCarModelId = loadedCarGroup.GetMember(memberId);
                        bool bGangHasModelId = false;
                        for (std::int32_t i = 0; i < CPopulation::m_AppropriateLoadedCars.CountMembers(); ++i) {
                            if (gangCarModelId == CPopulation::m_AppropriateLoadedCars.GetMember(i))
                                bGangHasModelId = true;
                        }
                        for (std::int32_t index = 0; index < TOTAL_GANGS; index++) {
                            const std::int32_t carGroupId = index + POPCYCLE_CARGROUP_BALLAS;
                            const std::uint16_t theGang = (1 << index);
                            if (index != groupId && (theGang & ms_loadedGangs)) {
                                for (std::int32_t i = 0; i < 23; i++) {
                                    std::int32_t modelId = CPopulation::m_CarGroups[carGroupId][i];
                                    if (modelId != CPopulation::m_defaultCarGroupModelId && modelId == gangCarModelId)
                                        bGangHasModelId = true;
                                }
                            }
                        }
                        if (!bGangHasModelId) {
                            SetModelIsDeletable(gangCarModelId);
                            SetModelTxdIsDeletable(gangCarModelId);
                        }
                    }
                }
            }
            else {
                const std::int32_t carGroupId = groupId + POPCYCLE_CARGROUP_BALLAS;
                const std::uint16_t numCars = CPopulation::m_nNumCarsInGroup[carGroupId];
                const std::int32_t modelId = CPopulation::m_CarGroups[carGroupId][rand() % numCars];
                if (ms_aInfoForModel[modelId].m_nLoadState != LOADSTATE_LOADED)
                    RequestModel(modelId, STREAMING_KEEP_IN_MEMORY);
            }
        }
    }
    ms_loadedGangCars = gangsNeeded;
#endif
}

void CStreaming::Update() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40E670);
#else
    g_LoadMonitor.m_numModelsRequest = ms_numModelsRequested;
    if (CTimer::m_UserPause || CTimer::m_CodePause)
        return;
    float fDistanceZ = TheCamera.GetPosition().z - TheCamera.CalculateGroundHeight(eGroundHeightType::ENTITY_BOUNDINGBOX_BOTTOM);
    if (!ms_disableStreaming && !CRenderer::m_loadingPriority) {
        if (fDistanceZ >= 50.0) {
            if (!CGame::currArea)
                AddLodsToRequestList(TheCamera.GetPosition(), 0);
        }
        else if (CRenderer::ms_bRenderOutsideTunnels) {
            AddModelsToRequestList(TheCamera.GetPosition(), 0);
        }
    }
    if ((CTimer::m_FrameCounter & 0x7F) == 106) {
        m_bBoatsNeeded = false;
        if (TheCamera.GetPosition().z < 500.0f)
            m_bBoatsNeeded = ThePaths.IsWaterNodeNearby(TheCamera.GetPosition(), 80.0f);
    }
    if (!ms_disableStreaming && !CCutsceneMgr::ms_cutsceneProcessing && !CGame::currArea
        && CReplay::Mode != 1 && fDistanceZ < 50.0f)
    {
        StreamVehiclesAndPeds_Always(FindPlayerCoors(-1));
        if (!IsVeryBusy()) {
            StreamVehiclesAndPeds();
            StreamZoneModels(FindPlayerCoors(-1));
        }
    }
    LoadRequestedModels();
    CVector playerPos = FindPlayerCoors(-1);
    CVehicle* pRemoveVehicle = CWorld::Players[0].m_pRemoteVehicle;
    if (pRemoveVehicle) {
        CColStore::AddCollisionNeededAtPosn(playerPos);
        CColStore::LoadCollision(pRemoveVehicle->GetPosition());
        CColStore::EnsureCollisionIsInMemory(pRemoveVehicle->GetPosition());
        CIplStore::AddIplsNeededAtPosn(playerPos);
        CIplStore::LoadIpls(pRemoveVehicle->GetPosition(), false);
        CIplStore::EnsureIplsAreInMemory(pRemoveVehicle->GetPosition());
    }
    else {
        CColStore::LoadCollision(playerPos);
        CColStore::EnsureCollisionIsInMemory(playerPos);
        CIplStore::LoadIpls(playerPos, false);
        CIplStore::EnsureIplsAreInMemory(playerPos);
    }
    if (ms_bEnableRequestListPurge)
        PurgeRequestList();
#endif
}

// unused
void CStreaming::UpdateForAnimViewer() {
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::CallDynGlobal(0x40E960);
#else
    CVector position;
    AddModelsToRequestList(position, 0);
    LoadRequestedModels();
    sprintf(gString, "Requested %d, memory size %dK\n", ms_numModelsRequested, 2 * ms_memoryUsed);
#endif
}

bool CStreaming::WeAreTryingToPhaseVehicleOut(int modelId) {
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallAndReturnDynGlobal<bool, int>(0x407F80, modelId);
#else
    CStreamingInfo& streamingInfo = CStreaming::ms_aInfoForModel[modelId];
    if (streamingInfo.m_nLoadState == LOADSTATE_LOADED)
        return streamingInfo.m_nNextIndex >= 0 || streamingInfo.m_nPrevIndex >= 0;
    return false;
#endif
}
