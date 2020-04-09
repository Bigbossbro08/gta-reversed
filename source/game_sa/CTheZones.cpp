#include "StdInc.h"

/*
	Plugin-SDK (Grand Theft Auto San Andreas) source file
	Authors: GTA Community. See more here
	https://github.com/DK22Pac/plugin-sdk
	Do not delete this comment block. Respect others' work!
*/

#define VAR_CTheZones__m_CurrLevel 0xBA6718
#define VAR_CTheZones__ExploredTerritoriesArray 0xBA3730
#define VAR_CTheZones__TotalNumberExploredTerritories 0xBA372C
#define VAR_CTheZones__TotalNumberOfInfoZones 0x572A5A
#define VAR_CTheZones__ZoneInfoArray 0xBA3798
#define VAR_CTheZones__TotalNumberOfMapZones 0xBA3794
#define VAR_CTheZones__MapZoneArray 0xBA1908
#define VAR_CTheZones__TotalNumberOfZoneInfos 0xBA1DE8

#define FUNC_CTheZones__InitZonesPopulationSettings 0x5720D0
#define FUNC_CTheZones__ResetZonesRevealed 0x572110
#define FUNC_CTheZones__GetCurrentZoneLockedOrUnlocked 0x572130
#define FUNC_CTheZones__AssignZoneInfoForThisZone 0x572180
#define FUNC_CTheZones__ZoneIsEntirelyContainedWithinOtherZone 0x572220
#define FUNC_CTheZones__PointLiesWithinZone 0x572270
#define FUNC_CTheZones__GetLevelFromPosition 0x572300
#define FUNC_CTheZones__FindSmallestZoneForPosition 0x572360
#define FUNC_CTheZones__GetZoneInfo 0x572400
#define FUNC_CTheZones__FillZonesWithGangColours 0x572440
#define FUNC_CTheZones__GetInfoZone 0x572590
#define FUNC_CTheZones__GetMapZone 0x5725A0
#define FUNC_CTheZones__Calc2DDistanceBetween2Zones 0x5725b0
#define FUNC_CTheZones__Init 0x572670
#define FUNC_CTheZones__SetCurrentZoneAsUnlocked 0x572800
#define FUNC_CTheZones__CreateZone 0x5728A0
#define FUNC_CTheZones__FindZone 0x572B80
#define FUNC_CTheZones__FindZoneByLabel 0x572C40
#define FUNC_CTheZones__SetZoneRadarColours 0x572cc0
#define FUNC_CTheZones__Update 0x572D10
#define FUNC_CTheZones__Save 0x5D2E60 
#define FUNC_CTheZones__Load 0x5D2F40

// Variables
eLevelName& CTheZones::m_CurrLevel = *(eLevelName*)VAR_CTheZones__m_CurrLevel;

char* CTheZones::ExploredTerritoriesArray = (char*)VAR_CTheZones__ExploredTerritoriesArray;
int& CTheZones::TotalNumberExploredTerritories = *(int*)VAR_CTheZones__TotalNumberExploredTerritories;

short& CTheZones::TotalNumberOfMapZones = *(short*)VAR_CTheZones__TotalNumberOfInfoZones;
CZone* CTheZones::ZoneInfoArray = (CZone*)VAR_CTheZones__ZoneInfoArray;

short& CTheZones::TotalNumberOfInfoZones = *(short*)VAR_CTheZones__TotalNumberOfMapZones;
CZone* CTheZones::MapZoneArray = (CZone*)VAR_CTheZones__MapZoneArray;

short& CTheZones::TotalNumberOfZoneInfos = *(short*)VAR_CTheZones__TotalNumberOfZoneInfos;
short& CTheZones::TotalNumberOfNavigationZones = *(short*)0xBA1900;

// Unknowns

unsigned int* CTheZones::dword_BA379C = (unsigned int*)0xBA379C; // Probably an array
unsigned int& CTheZones::dword_BA37A0 = *(unsigned int*)0xBA37A0;
unsigned int& CTheZones::dword_BA37A4 = *(unsigned int*)0xBA37A4;
unsigned short& CTheZones::word_BA37A8 = *(unsigned short*)0xBA37A8;
unsigned short& CTheZones::word_BA37AA = *(unsigned short*)0xBA37AA;
unsigned short& CTheZones::word_BA37AC = *(unsigned short*)0xBA37AC;
unsigned short& CTheZones::word_BA37AE = *(unsigned short*)0xBA37AE;
unsigned short& CTheZones::word_BA37B0 = *(unsigned short*)0xBA37B0;
unsigned short& CTheZones::word_BA37B2 = *(unsigned short*)0xBA37B2;
unsigned short* CTheZones::word_BA37B4 = (unsigned short*)0xBA37B4; // Probably an array
unsigned char& CTheZones::byte_BA37B7 = *(unsigned char*)0xBA37B7;
unsigned char& CTheZones::byte_BA37B6 = *(unsigned char*)0xBA37B6;
signed short& CTheZones::unk_BA37CA = *(signed short*)0xBA37CA;


void CTheZones::InjectHooks()
{
	HookInstall(FUNC_CTheZones__ResetZonesRevealed, &CTheZones::ResetZonesRevealed, 7);
	HookInstall(FUNC_CTheZones__GetCurrentZoneLockedOrUnlocked, &CTheZones::GetCurrentZoneLockedOrUnlocked, 7);
	HookInstall(FUNC_CTheZones__PointLiesWithinZone, &CTheZones::PointLiesWithinZone, 7);
	HookInstall(FUNC_CTheZones__GetZoneInfo, &CTheZones::GetZoneInfo, 7); 
	HookInstall(FUNC_CTheZones__GetInfoZone, &CTheZones::GetNavigationZone, 7);
	HookInstall(FUNC_CTheZones__GetMapZone, &CTheZones::GetMapZone, 7);
	//HookInstall(FUNC_CTheZones__Save, &CTheZones::Save, 7);
	//HookInstall(FUNC_CTheZones__Load, &CTheZones::Load, 7);
}
// Functions
void CTheZones::InitZonesPopulationSettings()
{
	((void(__cdecl*)()) FUNC_CTheZones__InitZonesPopulationSettings) ();
}

void CTheZones::ResetZonesRevealed()
{
#ifdef USE_DEFAULT_FUNCTIONS
	((void(__cdecl*)()) FUNC_CTheZones__ResetZonesRevealed) ();
#else
	memset(ExploredTerritoriesArray, 0, 100); // TODO: sizeof(CTheZones::ExploredTerritoriesArray)
	TotalNumberExploredTerritories = 0;
#endif
}

bool CTheZones::GetCurrentZoneLockedOrUnlocked(float posx, float posy)
{
#ifdef USE_DEFAULT_FUNCTIONS
	return ((bool(__cdecl*)(float, float)) FUNC_CTheZones__GetCurrentZoneLockedOrUnlocked) (posx, posy);
#else
	return CTheZones::ExploredTerritoriesArray[10 * (unsigned int)((posx + 3000.0f) * 0.0016666667f) - (unsigned int)((posy + 3000.0f) * 0.0016666667f) + 9] != 0;
#endif
}

void CTheZones::AssignZoneInfoForThisZone(short index)
{
	((void(__cdecl*)(short)) FUNC_CTheZones__AssignZoneInfoForThisZone) (index);
}

bool CTheZones::ZoneIsEntirelyContainedWithinOtherZone(CZone* pZone1, CZone* pZone2)
{
	return ((bool(__cdecl*)(CZone*, CZone*)) FUNC_CTheZones__ZoneIsEntirelyContainedWithinOtherZone) (pZone1, pZone2);
}

// Returns true if point lies within zone
bool CTheZones::PointLiesWithinZone(CVector const* pPoint, CZone* pZone)
{
#ifdef USE_DEFAULT_FUNCTIONS
	return ((bool(__cdecl*)(CVector const*, CZone*)) FUNC_CTheZones__PointLiesWithinZone)(pPoint, pZone);
#else
	return 
		pZone->m_fX1 <= pPoint->x &&
		pZone->m_fX2 >= pPoint->x && 
		pZone->m_fY1 <= pPoint->y && 
		pZone->m_fY2 >= pPoint->y && 
		pZone->m_fZ1 <= pPoint->z && 
		pZone->m_fZ2 >= pPoint->z;
#endif
}

// Returns eLevelName from position
eLevelName CTheZones::GetLevelFromPosition(CVector const* pPoint)
{
//#ifdef USE_DEFAULT_FUNCTIONS
	return ((eLevelName(__cdecl*)(CVector const*)) FUNC_CTheZones__GetLevelFromPosition)(pPoint);
//#else
//	if ( (unsigned __int16)TotalNumberOfMapZones <= 1u )
//		return eLevelName(MapZoneArray[7]);
//
//	int i = 1;
//	while ( !CTheZones::PointLiesWithinZone(pPoint, &MapZoneArray[8 * i]) )
//	{
//		if ( ++i >= TotalNumberOfMapZones )
//			return HIBYTE(MapZoneArray[7]);
//	}
//	return eLevelName(MapZoneArray[8 * i + 7]);
//#endif
}

// Returns pointer to zone by a point
CZone* CTheZones::FindSmallestZoneForPosition(const CVector& point, bool FindOnlyZonesType0)
{
	return ((CZone * (__cdecl*)(const CVector&, bool)) FUNC_CTheZones__FindSmallestZoneForPosition)(point, FindOnlyZonesType0);
}

// 572400
CZoneExtraInfo* CTheZones::GetZoneInfo(CVector* point, CZone** outzone)
{
#ifdef USE_DEFAULT_FUNCTIONS
	return ((CZoneExtraInfo * (__cdecl*)(CVector*, CZone**)) FUNC_CTheZones__GetZoneInfo) (point, outzone);
#else
	CZone* findSmallestZoneForPosition = (CZone*)CTheZones::FindSmallestZoneForPosition(*point, 0);
	if (findSmallestZoneForPosition)
	{
		if (outzone)
			*outzone = findSmallestZoneForPosition;
		return (CZoneExtraInfo*)&ZoneInfoArray[17 * (unsigned)findSmallestZoneForPosition->m_nZoneExtraIndexInfo];
	}
	else
	{
		if (outzone)
			*outzone = (CZone*)ZoneInfoArray;
		return (CZoneExtraInfo*)ZoneInfoArray;
	}
#endif
}

void CTheZones::FillZonesWithGangColours(bool DisableRadarGangColors)
{
	((void(__cdecl*)(bool)) FUNC_CTheZones__FillZonesWithGangColours) (DisableRadarGangColors);
}

// Returns pointer to zone by index
// 572590
CZone* CTheZones::GetNavigationZone(short index)
{
#ifdef USE_DEFAULT_FUNCTIONS
	return ((CZone * (__cdecl*)(short)) FUNC_CTheZones__GetInfoZone)(index);
#else
	return &CTheZones::ZoneInfoArray[8 * index];
#endif
}

// Returns pointer to zone by index
CZone* CTheZones::GetMapZone(short index)
{
#ifdef USE_DEFAULT_FUNCTIONS
	return ((CZone * (__cdecl*)(short)) FUNC_CTheZones__GetMapZone)(index);
#else
	return &CTheZones::MapZoneArray[8 * (unsigned __int16)index];
#endif
}

long double CTheZones::Calc2DDistanceBetween2Zones(CZone* Zone1, CZone* Zone2)
{
	return ((long double(__cdecl*)(CZone*, CZone*)) FUNC_CTheZones__Calc2DDistanceBetween2Zones) (Zone1, Zone2);
}

// Initializes CTheZones
void CTheZones::Init()
{
	((void(__cdecl*)()) FUNC_CTheZones__Init)();
}

// Unlock the current zone
void CTheZones::SetCurrentZoneAsUnlocked()
{
	((void(__cdecl*)()) FUNC_CTheZones__SetCurrentZoneAsUnlocked)();
}

// Creates a zone
void CTheZones::CreateZone(const char* name, eZoneType type, float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2, eLevelName island, const char* GXT_key)
{
	((void(__cdecl*)(const char*, eZoneType, float, float, float, float, float, float, eLevelName island, const char*)) FUNC_CTheZones__CreateZone)
		(name, type, posX1, posY1, posZ1, posX2, posY2, posZ2, island, GXT_key);
}

// Returns 1 if point lies within the specified zonename otherwise return 0
bool CTheZones::FindZone(CVector* point, int zonename_part1, int zonename_part2, eZoneType type)
{
	return ((bool(__cdecl*)(CVector*, int, int, eZoneType)) FUNC_CTheZones__FindZone)(point, zonename_part1, zonename_part2, type);
}

// Returns pointer to zone by index
short CTheZones::FindZoneByLabel(const char* name, eZoneType type)
{
	return ((short(__cdecl*)(const char*, eZoneType)) FUNC_CTheZones__FindZoneByLabel)(name, type);
}

void CTheZones::SetZoneRadarColours(short index, char flag, unsigned char red, unsigned char green, unsigned char blue)
{
//#ifdef USE_DEFAULT_FUNCTIONS
	((void(__cdecl*)(short, char, unsigned char, unsigned char, unsigned char)) FUNC_CTheZones__SetZoneRadarColours) (index, flag, red, green, blue);
//#else
//	CZoneExtraInfo* result = &CTheZones::ZoneInfoArray[CTheZones::ZoneInfoArray[index].m_nZoneExtraIndexInfo];
//	result->m_nFlags ^= (result->m_nFlags ^ 32 * flag) & 0x60;
//	result->ZoneColor.red = red;
//	result->ZoneColor.green = green;
//	result->ZoneColor.blue = blue;
//#endif
}

// Updates CTheZones info
void CTheZones::Update()
{
	((void(__cdecl*)()) FUNC_CTheZones__Update)();
}

// Save CTheZones info
void CTheZones::Save()
{
////#ifdef USE_DEFAULT_FUNCTIONS
	((void(__cdecl*)()) FUNC_CTheZones__Save) ();
//#else
//	CGenericGameStorage::SaveDataToWorkBuffer(&m_CurrLevel, 4);
//	CGenericGameStorage::SaveDataToWorkBuffer(&TotalNumberOfMapZones, 2);
//	CGenericGameStorage::SaveDataToWorkBuffer(&TotalNumberOfZoneInfos, 2);
//	CGenericGameStorage::SaveDataToWorkBuffer(&TotalNumberOfNavigationZones, 2);
//	int i = 0;
//	if (TotalNumberOfMapZones)
//	{
//		do
//			CGenericGameStorage::SaveDataToWorkBuffer(&CTheZones::ZoneInfoArray[8 * i++], 32);
//		while (i < TotalNumberOfMapZones);
//	}
//	i = 0;
//	if (TotalNumberOfZoneInfos)
//	{
//		do
//			CGenericGameStorage::SaveDataToWorkBuffer(&CTheZones::ZoneInfoArray[17 * i++], 17);
//		while (i < TotalNumberOfZoneInfos);
//	}
//	i = 0;
//	if (TotalNumberOfMapZones)
//	{
//		do
//			CGenericGameStorage::SaveDataToWorkBuffer(&MapZoneArray[8 * i++], 32);
//		while (i < TotalNumberOfMapZones);
//	}
//	CGenericGameStorage::SaveDataToWorkBuffer(CTheZones::ExploredTerritoriesArray, 100);
//	CGenericGameStorage::SaveDataToWorkBuffer(&CTheZones::TotalNumberExploredTerritories, 4);
//#endif
}

// Load CTheZones info
void CTheZones::Load()
{
//#ifdef USE_DEFAULT_FUNCTIONS
	((void(__cdecl*)()) FUNC_CTheZones__Load) ();
//#else
//	Init(); 
//	CGenericGameStorage::LoadDataFromWorkBuffer(&m_CurrLevel, 4);
//	CGenericGameStorage::LoadDataFromWorkBuffer(&TotalNumberOfMapZones, 2);
//	CGenericGameStorage::LoadDataFromWorkBuffer(&TotalNumberOfZoneInfos, 2);
//	CGenericGameStorage::LoadDataFromWorkBuffer(&TotalNumberOfNavigationZones, 2);
//	int i = 0;
//	if (TotalNumberOfMapZones)
//	{
//		do
//			CGenericGameStorage::LoadDataFromWorkBuffer(&ZoneInfoArray[8 * i++], 32);
//		while (i < TotalNumberOfMapZones);
//	}
//
//	i = 0;
//	if (TotalNumberOfZoneInfos)
//	{
//		do
//			CGenericGameStorage::LoadDataFromWorkBuffer(&ZoneInfoArray[17 * i++], 17);
//		while (i < TotalNumberOfZoneInfos);
//	}
//
//	i = 0;
//	if (TotalNumberOfMapZones)
//	{
//		do
//			CGenericGameStorage::LoadDataFromWorkBuffer(&MapZoneArray[8 * i++], 32);
//		while (i < TotalNumberOfMapZones);
//	}
//	CGenericGameStorage::LoadDataFromWorkBuffer(ExploredTerritoriesArray, 100);
//	CGenericGameStorage::LoadDataFromWorkBuffer(&TotalNumberExploredTerritories, 4u);
//#endif
}