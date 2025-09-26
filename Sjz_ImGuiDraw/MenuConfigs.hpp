//#pragma once
//
//#include<Windows.h>
//#include"imgui.h"
//namespace Configs
//{
//	//总控制
//	inline bool isMenu = true;
//	inline bool isFireMode = false;//战斗模式
//	inline bool isEnd = false;
//
//	inline int FireModeKey = VK_OEM_3;		// 战斗模式热键
//	inline int ShowMenuKey = VK_F12;	// 开关菜单热键
//	inline int ForceFreshKey = VK_F5;	// 强制刷新
//	inline int EndKey = VK_END;	// 退出
//	namespace Aimbot
//	{
//		inline	float Smooth = 100.f; //平滑 1-20
//		inline float SmoothInt = 50.f;
//		inline	float XSpeed = 2.5f;//1-5
//		inline float YSpeed = 2.5f;//1-5
//
//		inline float Fovsize = 200.0f;
//
//		inline bool DrawAimFov = true;
//
//		inline bool DoAimbot = true;
//
//		inline bool AimLine = false;
//
//		inline float SmoothY = 100.f;
//
//		inline	const char* AimBith[4] = { U8("头部"), U8("脊部"), U8("胸部"), U8("脚部") };
//
//
//
//		inline	const char* KeyBad[4] = { U8("右键"), U8("左键"), U8("shift"), U8("ctrl") };
//
//		inline	const char* ValueBadd[5] = { U8("二级"), U8("三级"), U8("四级"), U8("五级"),U8("六级") };
//
//
//		inline	const char* AimMod[1] = { U8("平滑自瞄")};
//
//		inline	const char* HealthStr[2] = { U8("单色"), U8("彩虹色") };
//		inline int AimIndex = 1;
//
//		inline int ModIndex = 1;
//		inline int KeyIndex = 0;
//		inline int AimModIndex = 0;
//
//		inline int ValueIndex = 0;
//
//
//		inline int HealthBarIndex = 1;
//	}
//	namespace Player
//	{
//		inline float ShowMaxDistance = 400.f;
//		inline int playerdis = 100;
//		inline int AIDis = 100;
//
//		inline bool DrawAI = true;//是否绘制人机
//		inline bool DrawDrawMap = true;//是否地图雷达
//		inline bool DrawBoss = true;//是否绘制人机
//		inline bool DrawBox2D = false;
//		inline bool DrawBone=true;
//		inline bool DrawHealth = true;;
//		inline bool Dituradar = true;
//		inline bool DrawDistance = true;;
//		inline bool DrawPlayerName = true;;
//		inline bool DrawTeam=true;
//		inline bool DrawEquipment=true;//头家
//		inline bool DrawWeapon=false;//手持
//		inline bool DrawWeaponICO = true;//手持
//		inline bool BotName = true;
//		inline bool	DrawEquipmentIco = false;
//
//		inline bool BotBone = true;
//
//		inline bool ShowDistance = true;
//
//		inline bool isShowOutSight = true;
//
//		inline bool displayNPCName = true;      // 显示NPC名称
//		inline bool displayNPCWeapon = false;    // 显示NPC手持武器
//		inline bool displayNPCDistance = true;  // 显示与NPC的距离
//		inline bool displayNPCSkeleton = true;  // 显示NPC骨骼
//		inline bool displayNPCBox = false;       // 显示NPC方框
//		inline bool displayNPCHealthBar = true; // 显示NPC血条
//		inline bool DrawEyu = true; // 显示NPC血条
//		inline	const char* Mod[2] = { U8("战场模式"), U8("烽火模式")};
//
//		class PlayerColor {
//
//		public:
//
//		    ImColor NameColor = ImColor(255, 255, 255, 255);
//			ImColor WeaponColor = ImColor(255, 255, 255, 255);
//		
//			ImColor SkeletonColor = ImColor(255, 255, 255, 255);
//
//			ImColor Box2DColor = ImColor(90, 189, 77, 255);
//
//			ImColor DistanceColor = ImColor(255, 215, 0, 255);
//
//
//
//		};
//		
//		inline PlayerColor colors;
//
//
//	}
//	namespace Item
//	{
//		inline float FontSize = 14.f;
//		inline bool DrawItem = true;//总开关
//
//		inline int ShowItemMaxDistance = 200;//地面物资最大距离
//		inline int ShowInteractorInnerMaxDistance = 30;//容器内物资
//		inline int ShowInteractorMaxDistance = 100;//容器
//		inline int ShowDeadBoxMaxDistance = 100;//盒子
//		inline int ShowDeadBoxInnerMaxDistance = 30;//盒子内物资
//		inline int ShowExitMaxDistance = 300;//撤离点
//		inline int ShowTriggerExitMaxDistance = 300;//拉闸点
//		inline int ShowDoorMaxDistance = 300;//密码们
//		inline bool DrawInteractor = true;
//		inline bool		DrawAiBox = true;
//		inline bool DrawExit = true;//撤离点
//		inline bool DrawTriggerExit = true;//拉闸点
//
//		inline bool DrawItemValueList = true;//拉闸点
//		inline bool DrawDoor = true;//密码门
//		inline bool DrawItemsIco = true;
//		inline bool DrawItems = true;
//		inline bool ShowInteractorInner = true;
//		inline bool ShowInteractor = true;
//		inline int32_t Valuefilter = 5000;
//		inline bool DrawPlayerBox = true;
//
//		// 物品类型存在性检查（根据当前上下文）
//		inline bool IsToolCabinet = true;        // 工具柜
//		inline bool IsBirdNest = true;           // 鸟窝
//		inline bool IsAmmoBox = true;            // 弹药箱
//		inline bool IsBigSnakeBag = true;        // 大蛇皮口袋
//		inline bool IsBigWeaponBox = true;       // 大武器箱
//		inline bool IsComputer = true;           // 电脑
//		inline bool IsDrawerCabinet = true;      // 抽屉柜
//		inline bool IsAviationLocker = true;     // 航空储物箱
//		inline bool IsClothes = true;            // 衣服
//		inline bool IsTrashBin = true;           // 垃圾箱
//		inline bool IsMedicalSupplies = true;    // 医疗物资箱
//		inline bool IsPremiumLuggage = true;     // 高级旅行箱
//		inline bool IsServer = true;             // 服务器
//		inline bool IsOfficeOrganizer = true;    // 办公室收纳盒
//		inline bool IsHudsonClothes = true;      // 哈德森衣服
//		inline bool IsPremiumStorageBox = true;  // 高级储物箱
//		inline bool IsExpressBox = true;         // 快递箱
//		inline bool IsSmallSafe = true;          // 小保险箱
//		inline bool IsHikingBackpack = true;     // 登山包
//		inline bool IsCementTruck = true;        // 水泥车
//		inline bool IsMedicalKit = true;         // 医疗包
//		inline bool IsHiddenStash = true;        // 藏匿物
//		inline bool IsLowGradeLocker = true;     // 低级个人储物箱
//
//		inline bool BaoXianGUI = true;
//		inline bool IsHackerComputer = true;
//
//
//		inline bool IsSuitcase = true;               // U8("手提箱")
//		inline bool IsBlackTideWeaponCase = true;     // U8("黑色潮汐武器箱")
//		inline bool IsFieldSupplyBox = true;          // U8("野外战备箱")
//		inline bool IsLargeToolBox = true;            // U8("大工具盒")
//		inline bool IsDianNaoBao = true;
//		inline bool IsShouNahe = true;
//
//		inline bool DrawDeadBox = true;
//		
//
//		inline int Gradevalves = 2;
//	}
//
//
//
//
//}





#pragma once

#include <Windows.h>
#include "imgui.h"

// 修复UTF-8宏定义，确保中文正常显示
#ifndef U8
#define U8(str) u8##str
#endif

namespace Configs
{
	//总控制
	inline bool isMenu = true;
	inline bool isFireMode = false;//战斗模式
	inline bool DZT = false;//战斗模式
	inline bool isEnd = false;

	inline int FireModeKey = VK_OEM_3;		// 战斗模式热键
	inline int ShowMenuKey = VK_F12;	// 开关菜单热键
	inline int ForceFreshKey = VK_F5;	// 强制刷新
	inline int EndKey = VK_END;	// 退出

	namespace Aimbot
	{
		inline	float Smooth = 100.f; //平滑 1-20
		inline float SmoothInt = 50.f;
		inline	float XSpeed = 2.5f;//1-5
		inline float YSpeed = 2.5f;//1-5

		inline float Fovsize = 200.0f;

		inline bool DrawAimFov = true;

		inline bool DoAimbot = true;

		inline bool AimLine = false;

		inline float SmoothY = 100.f;

		// 修复数组初始化格式，确保中文正常
		inline const char* AimBith[4] = { U8("头部"), U8("脊部"), U8("胸部"), U8("脚部") };

		inline const char* KeyBad[4] = { U8("右键"), U8("左键"), U8("shift"), U8("ctrl") };

		inline const char* ValueBadd[5] = { U8("二级"), U8("三级"), U8("四级"), U8("五级"), U8("六级") };

		// 保留原始数组大小，修复语法格式
		inline const char* AimMod[1] = { U8("平滑自瞄") };

		inline const char* HealthStr[2] = { U8("单色"), U8("彩虹色") };
		inline int AimIndex = 1;

		inline int ModIndex = 1;
		inline int KeyIndex = 0;
		inline int AimModIndex = 0;

		inline int ValueIndex = 0;

		inline int HealthBarIndex = 1;
	}

	namespace Player
	{
		inline float ShowMaxDistance = 400.f;
		inline int playerdis = 100;
		inline int AIDis = 100;

		inline bool DrawAI = true;//是否绘制人机
		inline bool DrawDrawMap = true;//是否地图雷达
		inline bool DrawBoss = true;//是否绘制人机
		inline bool DrawBox2D = false;
		inline bool DrawBone = true;
		inline bool DrawHealth = true;;
		inline bool Dituradar = true;
		inline bool DrawDistance = true;;
		inline bool DrawPlayerName = true;;
		inline bool DrawTeam = true;
		inline bool DrawEquipment = true;//头家
		inline bool DrawWeapon = false;//手持
		inline bool DrawWeaponICO = true;//手持
		inline bool BotName = true;
		inline bool DrawEquipmentIco = false;

		inline bool BotBone = true;

		inline bool ShowDistance = true;

		inline bool isShowOutSight = true;

		inline bool displayNPCName = true;      // 显示NPC名称
		inline bool displayNPCWeapon = false;    // 显示NPC手持武器
		inline bool displayNPCDistance = true;  // 显示与NPC的距离
		inline bool displayNPCSkeleton = true;  // 显示NPC骨骼
		inline bool displayNPCBox = false;       // 显示NPC方框
		inline bool displayNPCHealthBar = true; // 显示NPC血条
		inline bool DrawEyu = true; // 显示NPC血条

		inline const char* Mod[2] = { U8("战场模式"), U8("烽火模式") };

		class PlayerColor {
		public:
			ImColor NameColor = ImColor(255, 255, 255, 255);
			ImColor WeaponColor = ImColor(255, 255, 255, 255);
			ImColor SkeletonColor = ImColor(255, 255, 255, 255);
			ImColor Box2DColor = ImColor(90, 189, 77, 255);
			ImColor DistanceColor = ImColor(255, 215, 0, 255);
		};

		inline PlayerColor colors;
	}

	namespace Item
	{
		inline float FontSize = 14.f;
		inline bool DrawItem = true;//总开关

		inline int ShowItemMaxDistance = 200;//地面物资最大距离
		inline int ShowInteractorInnerMaxDistance = 30;//容器内物资
		inline int ShowInteractorMaxDistance = 100;//容器
		inline int ShowDeadBoxMaxDistance = 100;//盒子
		inline int ShowDeadBoxInnerMaxDistance = 30;//盒子内物资
		inline int ShowExitMaxDistance = 300;//撤离点
		inline int ShowTriggerExitMaxDistance = 300;//拉闸点
		inline int ShowDoorMaxDistance = 300;//密码们
		inline bool DrawInteractor = true;
		inline bool DrawAiBox = true;
		inline bool DrawExit = true;//撤离点
		inline bool DrawTriggerExit = true;//拉闸点

		inline bool DrawItemValueList = true;//拉闸点
		inline bool DrawDoor = true;//密码门
		inline bool DrawItemsIco = true;
		inline bool DrawItems = true;
		inline bool ShowInteractorInner = true;
		inline bool ShowInteractor = true;
		inline int32_t Valuefilter = 5000;
		inline bool DrawPlayerBox = true;

		// 物品类型存在性检查（保留原始命名）
		inline bool IsToolCabinet = true;        // 工具柜
		inline bool IsBirdNest = true;           // 鸟窝
		inline bool IsAmmoBox = true;            // 弹药箱
		inline bool IsBigSnakeBag = true;        // 大蛇皮口袋
		inline bool IsBigWeaponBox = true;       // 大武器箱
		inline bool IsComputer = true;           // 电脑
		inline bool IsDrawerCabinet = true;      // 抽屉柜
		inline bool IsAviationLocker = true;     // 航空储物箱
		inline bool IsClothes = true;            // 衣服
		inline bool IsTrashBin = true;           // 垃圾箱
		inline bool IsMedicalSupplies = true;    // 医疗物资箱
		inline bool IsPremiumLuggage = true;     // 高级旅行箱
		inline bool IsServer = true;             // 服务器
		inline bool IsOfficeOrganizer = true;    // 办公室收纳盒
		inline bool IsHudsonClothes = true;      // 哈德森衣服
		inline bool IsPremiumStorageBox = true;  // 高级储物箱
		inline bool IsExpressBox = true;         // 快递箱
		inline bool IsSmallSafe = true;          // 小保险箱
		inline bool IsHikingBackpack = true;     // 登山包
		inline bool IsCementTruck = true;        // 水泥车
		inline bool IsMedicalKit = true;         // 医疗包
		inline bool IsHiddenStash = true;        // 藏匿物
		inline bool IsLowGradeLocker = true;     // 低级个人储物箱

		inline bool BaoXianGUI = true;
		inline bool IsHackerComputer = true;

		inline bool IsSuitcase = true;               // 手提箱
		inline bool IsBlackTideWeaponCase = true;     // 黑色潮汐武器箱
		inline bool IsFieldSupplyBox = true;          // 野外战备箱
		inline bool IsLargeToolBox = true;            // 大工具盒
		inline bool IsDianNaoBao = true;
		inline bool IsShouNahe = true;

		inline bool DrawDeadBox = true;

		inline int Gradevalves = 2;
	}
}
