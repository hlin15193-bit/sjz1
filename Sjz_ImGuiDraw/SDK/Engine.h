#pragma once
#include"base.h"
#include"Class.h"
#include"Constants.h"
#include<mutex>
#include<shared_mutex>
struct ActorEntity
{
	uint64_t Entity;
	int FNameId;
	std::string ClassName;

};

struct Player
{
	uint64_t Entity;
	int FNameId;
	std::string ClassName;
	ECharacterType playerType;
	ECharacterTypeInfo playerTypeInfo;

	bool IsMe = false;
	bool IsMyTeam = false;
	bool isMycamp = false;
	bool InScreen = true;
	bool isPlayerDead = true;
	bool isPlayerAi = true;


	uint64_t RootComponent;
	FVector Location;
	float Pitch;

	//PlayerState相关
	uint64_t PlayerState;
	int32 teamId;
	int32 campId;

	BYTE isDead;
	int16_t HeroId;
	std::string heroName;
	BYTE ExitState;
	uint64_t pCharacterName;
	FText CharacterName;
	std::string playerName;

	float Distance;


	//头甲相关

	uint64_t UCharacterEquipComponent;
	uint64_t EquipmentInfoArray;
	int EquipmentInfoArray_Count;
	uint64_t ArmorID; //护甲
	float ArmorHp; //护甲
	uint64_t HelmetArmorId;//头盔护甲
	float HelmetArmorHp;//头盔护甲
	int ArmorLevel;
	int HelmeArmorLevel;

	//武器相关
	uint64_t CacheCurWeapon;
	int16_t WeaponID;
	uint64_t WeaponID1;
	std::string weaponName;


	//血量相关
	uint64_t HealthComp;
	uint64_t HealthSet;
	float CurrentHealthValue;
	float MaxHealth;

	//骨骼
	uint64_t MeshComponent;
	FTransform ComponentToWorld;
	uint64_t StaticMesh;
	uint64_t StaticMeshTemp;
	uint64_t StaticMeshTemp1;
	bool IsViews;
	uint32_t IsAlive;


	struct {
		std::unordered_map<int, FTransform> Bones = {
			{BoneIndex::root, FTransform()},
			{BoneIndex::Head_Joint, FTransform()},
			{BoneIndex::Head, FTransform()},
			{BoneIndex::Neck, FTransform()},
			{BoneIndex::Spine, FTransform()},
			{BoneIndex::RightArm, FTransform()},
			{BoneIndex::RightForeArm, FTransform()},
			{BoneIndex::RightHand, FTransform()},
			{BoneIndex::LeftArm, FTransform()},
			{BoneIndex::LeftForeArm, FTransform()},
			{BoneIndex::LeftHand, FTransform()},
			{BoneIndex::Hips, FTransform()},
			{BoneIndex::RightUpLeg, FTransform()},
			{BoneIndex::RightLeg, FTransform()},
			{BoneIndex::RightFoot, FTransform()},
			{BoneIndex::LeftUpLeg, FTransform()},
			{BoneIndex::LeftLeg, FTransform()},
			{BoneIndex::LeftFoot, FTransform()}
		};

		std::unordered_map<int, FVector> LocationBones = {
			{BoneIndex::root, FVector()},
			{BoneIndex::Head_Joint, FVector()},
			{BoneIndex::Head, FVector()},
			{BoneIndex::Neck, FVector()},
			{BoneIndex::Spine, FVector()},
			{BoneIndex::RightArm, FVector()},
			{BoneIndex::RightForeArm, FVector()},
			{BoneIndex::RightHand, FVector()},
			{BoneIndex::LeftArm, FVector()},
			{BoneIndex::LeftForeArm, FVector()},
			{BoneIndex::LeftHand, FVector()},
			{BoneIndex::Hips, FVector()},
			{BoneIndex::RightUpLeg, FVector()},
			{BoneIndex::RightLeg, FVector()},
			{BoneIndex::RightFoot, FVector()},
			{BoneIndex::LeftUpLeg, FVector()},
			{BoneIndex::LeftLeg, FVector()},
			{BoneIndex::LeftFoot, FVector()}
		};
		std::unordered_map<int, FVector2D> ScreenBones = {
			{BoneIndex::root, FVector2D()},
			{BoneIndex::Head_Joint, FVector2D()},
			{BoneIndex::Head, FVector2D()},
			{BoneIndex::Neck, FVector2D()},
			{BoneIndex::Spine, FVector2D()},
			{BoneIndex::RightArm, FVector2D()},
			{BoneIndex::RightForeArm, FVector2D()},
			{BoneIndex::RightHand, FVector2D()},
			{BoneIndex::LeftArm, FVector2D()},
			{BoneIndex::LeftForeArm, FVector2D()},
			{BoneIndex::LeftHand, FVector2D()},
			{BoneIndex::Hips, FVector2D()},
			{BoneIndex::RightUpLeg, FVector2D()},
			{BoneIndex::RightLeg, FVector2D()},
			{BoneIndex::RightFoot, FVector2D()},
			{BoneIndex::LeftUpLeg, FVector2D()},
			{BoneIndex::LeftLeg, FVector2D()},
			{BoneIndex::LeftFoot, FVector2D()}
		};
	} Skeleton;

};
struct ContainerItemRow
{
	uint64_t DFMCommonItemRowPtr;

	uint64_t NamePtr;
	std::string DisPlayName;
	int32 InitialGuidePrice;
};




struct Item
{
	uint64_t Entity;
	int FNameId;
	std::string ClassName;
	ECharacterType itemType;



	bool InScreen = true;
	uint64_t RootComponent;
	FVector2D ScreenLocation;
	FVector Location;
	float Distance;
	//item
	uint64_t PickUpItemInfo;
	uint64_t AttachInfo;
	uint64_t itemID;
	DisPlayItem disPlayItem;
	std::vector<DrawItemListS> highValueItems;
	//DeadBox
	uint64_t DeadBoxPackPtr;
	int DeadBoxCount;
	std::vector<uint64_t>DeadBoxPawnList;
	std::vector<uint64_t>DeadBoxPawnItemIDList;
	std::vector<DisPlayItem>DeadBoxDisPlayItemList;
	uint8_t CurrentyGid;
	
	//Interactor
	uint32_t InteractorIndex;
	std::string InteractorName;
	bool isBaoXian = false;
	std::pair<int, ImColor> InterInfo;
	uint64_t InteractorPackPtr;
	int InteractorCount;
	std::vector<uint64_t>InteractorPawnList;
	std::vector<uint64_t>InteractorPawnItemIDList;
	std::vector<DisPlayItem>InteractorDisPlayItemList;
	bool IsComputer;
	char isOpened;
	int ComputerPwd;

	//Exit & ExitTrigger &Door
	std::string ExitNamePtr;
	FText ExitNameText;
	std::string ExitName;

	char ExitState;
	int DoorPwd;






	
	
	
	

};

struct Mapinfo
{
	float X = 0.f;
	float Y = 0.f;
	float W = 0.f;
	float H = 0.f;
	int MapX = 0;
	int MapY = 0;
};

//本人数据
namespace LocalData
{
	inline uintptr_t LocalPlayerPawn;

	inline uintptr_t PlayerContoller;

	inline uintptr_t PlayerState;

	inline uintptr_t PlayerCameraManager;
	//本人阵营
	inline int32 TeamId;
	inline int32 CampId;

	inline uint64_t UnetDriver;

	inline CameraData LocalCameraData;



}

namespace Dx11Data
{
	inline HWND g_game_hwnd{};
	inline RECT g_rect{};
	inline HWND hwnd;
	inline int ScreenWidth;
	inline int ScreenHeight;
	inline int ScreenX;
	inline int ScreenY;

}


namespace GlobalData
{



	inline uintptr_t UWorld;
	inline uintptr_t PersistentLevel;

	inline TArray<uint64_t> ULevels;
	inline uintptr_t ActorsPtr;
	inline uint32_t ActorsCount;

	inline EDFMGamePlayMode PlayMode;

	
	// 大地图雷达
	inline char preShouldDraw;
	inline uintptr_t MapObjPtr;
	inline Mapinfo radar;



	inline bool Encrypted = false;

	//缓存玩家对象list
	inline std::shared_mutex CachePlayersMutex;
	inline std::unordered_map<uint64_t, Player>CachePlayers;
	std::unordered_map<uint64_t, Player> GetCachePlayers();
	void SetCachePlayers(std::unordered_map<uint64_t, Player>& value);
	void ClearCachePlayers();


	//处理好的玩家对象list
	inline std::shared_mutex PlayersMutex;
	inline std::unordered_map<uint64_t, Player>PlayersList;
	std::unordered_map<uint64_t, Player> GetPlayers();
	void SetPlayers(std::unordered_map<uint64_t, Player>& value);
	Player GetPlayerByKey(uint64_t key);
	void ClearPlayers();

	//缓存的物资对象
	inline std::shared_mutex CacheItemsMutex;
	inline std::unordered_map<uint64_t, Item>CacheItems;
	std::unordered_map<uint64_t, Item> GetCacheItems();
	void SetCacheItems(std::unordered_map<uint64_t, Item>& value);
	void ClearCacheItems();


	//处理好的物资对象
	inline std::shared_mutex ItemMutex;
	inline std::unordered_map<uint64_t, Item>ItemsList;
	std::unordered_map<uint64_t, Item> GetItems();
	void SetItems(std::unordered_map<uint64_t, Item>& value);
	void ClearItems();




}
class Engine
{
public:
	static std::string GetName(uint32_t index);

	static bool Getinvisible(uint64_t Mesh);

	static bool init();

};