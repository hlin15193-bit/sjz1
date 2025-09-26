#pragma once

#include<Windows.h>
#include"ue4math/ue4math.h"
#include"ue4math/quat.h"
#include"ue4math/vector.h"
#include"ue4math/rotator.h"
#include"ue4math/matrix.h"
#include"ue4math/transform.h"
#include<list>
#include<vector>
#include"Memory/Memory.h"

using MYFLOAT = float;


enum class EEquipmentType : uint8_t
{
	None = 0,
	Helmet = 1,
	Headset = 2,
	FaceMask = 3,
	Armband = 4,
	BreastPlate = 5,
	Glasses = 6,
	ChestHanging = 7,
	Bag = 8,
	SafeBox = 9,
	Tool = 10,
	Shoes = 11,
	KeyChain = 12,
	Max = 13

};



enum class EDFMGamePlayMode : uint8_t
{
	None = 0,
	GamePlayMode_SOL = 1,//solo模式
	GamePlayMode_Raid = 2,//raid模式
	GamePlayMode_IrisDiscovery = 3,//虹发现模式
	GamePlayMode_Conquest = 4,//征服模式
	GamePlayMode_Breakthrough = 5,//突破模式
	GamePlayMode_SafeHouse = 6,//保险房
	GamePlayMode_Intro = 7,//开场动画
	EDFMGamePlayMode_MAX = 8//最大值
};

struct FArmorInfo
{
	enum class EEquipmentType                     EquipmentType;                                                // 0x0000(0x0001)
	char                                          pa_0001[0x0007];                                              // 0x0001(0x0007)
	uint64_t                                      ItemID;                                                       // 0x0008(0x0008)
	uint64_t                                      gid;                                                          // 0x0010(0x0008)
	float                                         ArmorHP;                                                      // 0x0018(0x0004)
	float                                         MaxArmorHP;                                                   // 0x001C(0x0004)
	uint64_t                                        ProtecetName;                                                 // 0x0020(0x0008)
	float                                         Durability;                                                   // 0x0028(0x0004)
	float                                         MaxDurability;                                                // 0x002C(0x0004)
	float                                         SrcMaxDurability;                                             // 0x0030(0x0004)
	char                                          pa_0034[0x0004];                                              // 0x0034(0x0004)
	int64_t                                       LastEquipTimeStamp;                                           // 0x0038(0x0008)
	float                                         TotalEquipSeconds;                                            // 0x0040(0x0004)
	float                                         TotalDamage;                                                  // 0x0044(0x0004)
	int32_t                                       ArmorLevel;                                                   // 0x0048(0x0004)
	float                                         DamagesReduction;                                             // 0x004C(0x0004)
	float                                         Ricochet;                                                     // 0x0050(0x0004)
	float                                         RicochetDamage;                                               // 0x0054(0x0004)
	char                                          bDamageFunctionOnly;                                          // 0x0058(0x0001)
	char                                          bEnableDamageFunction;                                        // 0x0059(0x0001)
	char                                          pa_005A[0x0006];                                              // 0x005A(0x0006)
};


template<class T>
class TArray {
public:
	T Data;
	int32_t Count;
	int32_t Max;


public:
	size_t size(size_t MaxSize = 0x2000) const {
		return Count < MaxSize ? Count : MaxSize;
	}

	bool GetValue(int i, T& value) const {
		if (i < 0 || i >= size(0x2000)) return false;
		//return memcpy(&value, (PVOID)(Data + sizeof(T) * i), sizeof(T));
		return Memory::ReadMemory(reinterpret_cast<uintptr_t>((Data + sizeof(T) * i)), &value, sizeof(T));
	}

	bool GetValues(T& value, size_t MaxSize = 0x2000) const {
		return  Memory::ReadMemory(reinterpret_cast<uintptr_t>(Data), &value, sizeof(T) * size(MaxSize));
		//return memcpy(&value, (PVOID)Data, sizeof(T) * size(MaxSize));
	}

	std::vector<T> GetVector(size_t MaxSize = 0x2000) const {
		std::vector<T> v(size(MaxSize));
		if (!GetValues(v[0], MaxSize))
			v.clear();

		return v;
	}

	operator std::vector<T>() const { return GetVector(); }

	T operator [](int i) const {
		T Value;
		if (!GetValue(i, Value))
			ZeroMemory(&Value, sizeof(Value));
		return Value;
	}
};


struct FText
{
	char buffer[256];
};


struct  CameraData
{
	struct FVector Location;
	char pad_4[0x4];
	struct FRotator Rotation;
	float FOV;
};
struct FString
{
	wchar_t* Data;
	int Count;
	int Max;


	FString() = default;

	explicit FString(const wchar_t* other)
	{
		Max = Count = *other ? wcslen(other) + 1 : 0;

		if (Count)
		{
			Data = const_cast<wchar_t*>(other);
		}
	};

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline const wchar_t* c_str() const
	{
		return Data;
	}

	std::string ToString() const
	{

		int length = static_cast<int>(wcslen(Data));  // 计算长度
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, Data, length, NULL, 0, NULL, NULL);
		std::string narrow_str(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, Data, length, &narrow_str[0], size_needed, NULL, NULL);

		return narrow_str;
	}
};
enum class Scene
{
	FindProcess = 0,
	Lobby = 1,//大厅
	Gaming = 2,//游戏
};




//0x5b8
struct FInventoryItemInfo
{
	char pad[0x540];
	uint64_t DFMCommonItemRowPtr;

};


// ScriptStruct DFMGlobalDefines.DFMCommonItemRow
// Size: 0x218 (Inherited: 0x10)
struct DFMCommonItemRow {
	char pad[0x18];

	uint64_t NamePtr;//0x18
	char pad1[0x10];
	char pad2[0x18];
	
	int32_t GameItemType; // 0x48(0x04)
	char pad_4C[0x4]; // 0x4c(0x04)
	char pad3[0x18];
	int32_t Quality; // 0x68(0x04)//品质

	int32_t InitialGuidePrice; // 0xd8(0x04)//价值
};


enum BoneIndex :uint8_t
{
	root = 0,
	Hips = 1,
	Spine = 2,
	Spine1 = 3,
	Spine2 = 4,
	RightShoulder = 5,
	RightArm = 6,
	RightForeArm = 7,
	//RightForeArmTwist = 8,
	//RightForeArmTwist = 9,
	RightHand = 10,
	RightHandThumb1 = 11,
	RightHandThumb2 = 12,
	RightHandThumb3 = 13,
	Weapon_RightHand_Joint = 14,
	RightInHandRing = 15,
	RightHandRing1 = 16,
	RightHandRing2 = 17,
	RightHandRing3 = 18,
	RightInHandPinky = 19,
	RightHandPinky1 = 20,
	RightHandPinky2 = 21,
	RightHandPinky3 = 22,
	RightHandMiddle1 = 23,
	RightHandMiddle2 = 24,
	RightHandMiddle3 = 25,
	RightHandIndex1 = 26,
	RightHandIndex2 = 27,
	RightHandIndex3 = 28,
	RightArmTwist = 29,
	Neck = 30,
	Head = 31,
	Head_Joint = 32,
	LeftShoulder = 33,
	LeftArm = 34,
	LeftForeArm = 35,
	//LeftForeArmTwist = 36,
	//LeftForeArmTwist = 37,
	LeftHand = 38,
	LeftHandThumb1 = 39,
	LeftHandThumb2 = 40,
	LeftHandThumb3 = 41,
	Weapon_LeftHand_Joint = 42,
	LeftInHandRing = 43,
	LeftHandRing1 = 44,
	LeftHandRing2 = 45,
	LeftHandRing3 = 46,
	LeftInHandPinky = 47,
	LeftHandPinky1 = 48,
	LeftHandPinky2 = 49,
	LeftHandPinky3 = 50,
	LeftHandMiddle1 = 51,
	LeftHandMiddle2 = 52,
	LeftHandMiddle3 = 53,
	LeftHandIndex1 = 54,
	LeftHandIndex2 = 55,
	LeftHandIndex3 = 56,
	LeftArmTwist = 57,
	LeftUpLeg = 58,
	LeftLeg = 59,
	LeftFoot = 60,
	LeftToeBase = 61,
	RightUpLeg = 62,
	RightLeg = 63,
	RightFoot = 64,
	RightToeBase = 65,
	b_IK_Hand_Root = 66,
	b_IK_Gun = 67,
	b_IK_Hand_R = 68,
	b_IK_Hand_L = 69,
	Camera_Root = 70,
	Camera_Joint = 71,
	b_IK_Foot_Root = 72,
	b_IK_Foot_L = 73,
	b_IK_Foot_R = 74,
};

namespace SkeletonLists {
	static std::list<BoneIndex> Spine = { BoneIndex::Head,BoneIndex::Neck, BoneIndex::Spine,BoneIndex::Hips };
	static std::list<BoneIndex> Right_Arm = { BoneIndex::Neck, BoneIndex::RightArm, BoneIndex::RightForeArm, BoneIndex::RightHand };
	static std::list<BoneIndex> Left_Arm = { BoneIndex::Neck, BoneIndex::LeftArm, BoneIndex::LeftForeArm, BoneIndex::LeftHand };
	static std::list<BoneIndex> Lower_Right = { BoneIndex::Hips, BoneIndex::RightUpLeg, BoneIndex::RightLeg, BoneIndex::RightFoot };
	static std::list<BoneIndex> Lower_Left = { BoneIndex::Hips, BoneIndex::LeftUpLeg, BoneIndex::LeftLeg, BoneIndex::LeftFoot };
	static std::list<std::list<BoneIndex>> Skeleton = { Spine,Right_Arm, Left_Arm, Lower_Right, Lower_Left };

	static std::list<BoneIndex> Bones = {
		BoneIndex::root,
		BoneIndex::Head_Joint,
		BoneIndex::Head,
		BoneIndex::Neck,
		BoneIndex::Spine,
		BoneIndex::RightArm, BoneIndex::RightForeArm, BoneIndex::RightHand,
		BoneIndex::LeftArm, BoneIndex::LeftForeArm, BoneIndex::LeftHand,
		BoneIndex::Hips,
		BoneIndex::RightUpLeg, BoneIndex::RightLeg, BoneIndex::RightFoot,
		BoneIndex::LeftUpLeg, BoneIndex::LeftLeg, BoneIndex::LeftFoot,
	};
};