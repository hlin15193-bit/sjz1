//#pragma once
//
//#include<inttypes.h>
//#define OFFSET_LocalPawn_Func								0x12642720
//#define OFFSET_RootComponent_Func							0x12634880
////
//#define OFFSET_FuncEnc_Param								0x12F4C3C0
////No WorldSettings上面的一个call  if (!repair_GetULevel1(v10, 0, 1u))
//#define OFFSET_Ulevel_Func									0x1264AEB0
////CallHandleDisconnectForFailure
////if(a1) 下面就是
//#define OFFSET_GameInstance_Func							0x11C51700
////InteractionStrength最上面的加密自己看得到,根据GameState偏移看
//#define OFFSET_GameState_Func								0x11CB88D0
////GetCameraLocation
//#define OFFSET_PlayerCamera_Func							0x12642720
//#define OFFSET_PlayerCamera_Open							0x130AE668
//#define OFFSET_PlayerCamera_Param							0x12642704
//#define OFFSET_PlayerCamera_Core							0x2F2E0
//#define OFFSET_PlayerCamera_Mul								0x9E0
//#define OFFSET_PlayerCamera_offset							0x2F2E0
//#define OFFSET_PlayerCameraManager							0x0408
//#define OFFSET_CameraCache									0x2F2E0
//#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10
//namespace Offsets
//{
//	//constexpr uint64_t netActors = 0x570;  //   FGameplayAbilitySpecContainer                 ActivatableAbilities;                                         // 0x0448(0x0120)
//	//char                                          pa_0578[0x0030]                                               // 0x0578(0x0030)
//	//游戏场景
//	constexpr uint64_t decActors = 0x0448;     
//
//
//	constexpr uint64_t UWorld = 0x138A5CC8;
//	constexpr uint64_t GName = 0x14225A40;
//	constexpr uint64_t NameId = 0x1C;//objectid
//	constexpr uint64_t ULevels = 0x158;
//	constexpr uint64_t AActors = 0x98;
//
//	constexpr uint64_t NetDriver = 0x30; 
//	constexpr uint64_t PersistentLevel = 0xF8;
//	 
//
//	constexpr uint64_t GameState = 0x0140;   
//	constexpr uint64_t DFMGamePlayerMode = 0x0659;//0x1
//
//	//本人相关
//	constexpr uint64_t UGameInstance = 0x0190; 
//	constexpr uint64_t LocalPlayers = 0x38;
//	constexpr uint64_t PlayerController = 0x030;
//	constexpr uint64_t AcknowledgedPawn = 0x3F0;
//
//	//RootComponent
//	constexpr uint64_t RootComponent = 0x0180;
//	constexpr uint64_t RelativeLocation = 0x148;
//	constexpr uint64_t ComponentLocation = 0x220;//0x230;//
//
//	constexpr uint64_t Pitch = 0x208;
//
//
//
//	//骨骼
//	constexpr uint64_t Mesh = 0x03D0;
//	constexpr uint64_t ComponentToWorld = 0x210;
//	constexpr uint64_t StaticMesh = 0x728;
//	constexpr uint64_t StaticMeshCache = StaticMesh + 0x10;
//
//
//
//
//	//PlayerState相关
//	constexpr uint64_t PlayerState = 0x0390;
//	constexpr uint64_t teamId = 0x066C;
//	constexpr uint64_t campId = 0x0670;
//	constexpr uint64_t bDead = 0x04B4;
//	constexpr uint64_t bIsPlayerAI = 0x0D19;
//	constexpr uint64_t bFinishGame = 0x04C8;
//	constexpr uint64_t HeroId = 0x09B8;//size:0x2
//	constexpr uint64_t PlayerNamePrivate = 0x488;
//	constexpr uint64_t ExitState = 0x0D60;
//
//
//	//------------------------------------以下这些偏移自己更新 都有里面 我还有事 解密这些全部给你替换好了
//	constexpr uint64_t fLastSubmit = 0x02E8;
//	//CameraCachePrivate+0x10 = FMinimalViewInfo POV; // 0x10(0x9e0)
//	//血量
//	constexpr uint64_t   HealthComp = 0x0F68;   // Class Engine.GPCharacterBase ->UGPHealthDataComponent* HealthComp; 
//	constexpr uint64_t   HealthSet = 0x0248;   // UGPAttributeSetHealth * HealthSet;
//	constexpr uint64_t   Health = 0x0030 + 0x14;      // FGPGameplayAttributeData                      Health;     float CurrentValue; // 0x10(0x04)
//	constexpr uint64_t   IsAlive = 0x0100 + 0x14;
//	constexpr uint64_t   MaxHealth = 0x48 + 0x14;
//	//武器
//	//AGPCharacterBase -> struct AWeaponBase* CacheCurWeapon; // 0x14d8(0x08)-> uint16_t WeaponID; // 0x820(0x02)
//	constexpr uint64_t  CacheCurWeapon = 0x15E8;
//	constexpr uint64_t  WeaponID = 0x0820;
//
//
//	//constexpr uint64_t AGPCharacterBase = 0x0E48; //AGPCharacterBase->BlackBoard
//	//constexpr uint64_t CurrentWeapon = 0x04A8; //UGPBlackboardComponent->
//	constexpr uint64_t WeaponID1 = 0x0820;
//
//
//
//	//人物头甲
//	//ADFMPlayerCharacter ->UDFMCharacterAttributeCenterComponent*        DFMAttributesCenter;                                          // 0x1F18(0x0008)
//	//等级FEquipmentInfo->ArmorLevel;
//
//	constexpr uint64_t UCharacterEquipComponent = 0x2048;//class ADFMCharacter - > CharacterEquipComponentCache
//	constexpr uint64_t EquipmentInfoArray = 0x01D8;
//	constexpr uint64_t HelmetArmorLevel = 0x30;//头
//	constexpr uint64_t HelmetArmorHp = 0x48;//
//	constexpr uint64_t ArmorLevel = 0x18;//OFFSET_FArmorInfo_ArmorLevel
//	constexpr uint64_t ArmorHp = 0x48;//OFFSET_FArmorInfo_ArmorHP
//
//
//
//	//地面物资
//	//AInventoryPickup->struct FInventoryItemInfo PickupItemInfo; // 0xe00(0x5b8)
//
//	constexpr uint64_t PickupItemInfo = 0x0CF0;//0xC68;
//	constexpr uint64_t PickupItemSize = 0x538;//0x538-2;//char pad[0x538];
//	constexpr uint64_t ItemID = 0x10;   // (0x0018)FInventoryItemInfo->  FItemID    ItemID;   
//
//
//
//	constexpr uint64_t NamePtr = 0x18;
//	constexpr uint64_t NamePtr1 = 0x18;
//	constexpr uint64_t NamePtr2 = 0x30;
//	constexpr uint64_t NamePtr3 = 0x10;
//	constexpr uint64_t Quality = 0x68;
//	constexpr uint64_t InitialGuidePrice = 0xD8;
//
//
//
//	//死亡盒子 容器 
//	constexpr uint64_t bHasOpened = 0x1D54; // AInventoryPickup_OpenBox-> char bHasOpened : 0; // 0x1bac(0x01)
//
//	constexpr uint64_t RepItemArray = 0x18C0;//0x17C8; // AInventoryPickup_Container->struct FItemArray RepItemArray; // 0x1728(0x120)
//
//	constexpr uint64_t Items = 0x108; // FItemArray->struct TArray<struct FInventoryItemInfo> Items; // 0x108(0x10)	
//	constexpr uint64_t SizeOfFInventoryItemInfo = 0x0378; // FItemArray->struct TArray<struct FInventoryItemInfo> Items; // 0x108(0x10)	
//	constexpr uint64_t CurrencyGID = 0x1F08; // AInventoryPickup_DeadBody->uint64_t              CurrencyGID; 	
//	constexpr uint64_t computerPassWord = 0x0DCC; // AInteractor_HackPC-> int32_t      Password; 
//
//
//	//拉闸点 &撤离点 &密码门
//
//	constexpr uint64_t bExitActive = 0x0A70;//SDK里面没有
//	constexpr uint64_t NameText = 0x0370;//APlayerExitBase->FText           NameText;                     
//	constexpr uint64_t ExitConditionConfig = 0x0440;//APlayerExitBase->FExitConditionConfig ExitConditionConfig;   
//	constexpr uint64_t PwdSum = 0x0E28;//AInteractor_CodedLock-> int32 PwdSum  
//
//
//
//	//大地图雷达数据
//	constexpr uint64_t  MyHUD = 0x400;
//	constexpr uint64_t  Controllers = 0x0468;
//	constexpr uint64_t  ChildControllers = 0x00B0;
//	constexpr uint64_t  View = 0x0088;//class UBaseUIView 98
//	constexpr uint64_t  preShouldDraw = 0x092C;//class UBigMapHUDView->char preShouldDraw
//	// struct UBigMapHUDView : UMapBaseHUDView -> 找 [0x0020]的偏移
//	constexpr uint64_t pa_0840 = 0x838;   // 0x0840(0x0020)
//
//};
//
//
//
//
//
//#pragma once
//#include <inttypes.h>
//
//// 类型别名增强可读性
//using uint64 = uint64_t;
//using int32 = int32_t;
//
//// ============================ 原始函数偏移（#define OFFSET_ 系列）============================
//// 核心功能函数内存地址偏移
//#define OFFSET_LocalPawn_Func								0x12642720		// 获取本地角色（Pawn）的函数
//#define OFFSET_RootComponent_Func							0x12634880		// 获取根组件的函数
//#define OFFSET_FuncEnc_Param								0x12F4C3C0		// 加密参数处理函数
//#define OFFSET_Ulevel_Func									0x1264AEB0		// 获取ULevel的函数（No WorldSettings上方的call）
//#define OFFSET_GameInstance_Func							0x11C51700		// 游戏实例处理函数（CallHandleDisconnectForFailure下方）
//#define OFFSET_GameState_Func								0x11CB88D0		// 获取GameState的函数（结合InteractionStrength加密相关）
//
//// 相机相关函数偏移
//#define OFFSET_PlayerCamera_Func							0x12642720		// 获取相机位置（GetCameraLocation）
//#define OFFSET_PlayerCamera_Open							0x130AE668		// 相机开启函数
//#define OFFSET_PlayerCamera_Param							0x12642704		// 相机参数函数
//#define OFFSET_PlayerCamera_Core							0x2F2E0			// 相机核心偏移
//#define OFFSET_PlayerCamera_Mul								0x9E0			// 相机乘法因子
//#define OFFSET_PlayerCamera_offset							0x2F2E0			// 相机偏移量
//#define OFFSET_PlayerCameraManager							0x0408			// 相机管理器偏移
//#define OFFSET_CameraCache									0x2F2E0			// 相机缓存
//#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10	// 最小视图信息（基于相机缓存Cache + 0x10）
//
//// ============================ 结构化对象偏移（命名空间分类整理理）============================
//namespace Offsets
//{
//	// ---------------------------- 全局核心对象 ----------------------------
//	constexpr uint64 UWorld = 0x138A5CC8;					// 全局游戏世界（UWorld）指针
//	constexpr uint64 GName = 0x14225A40;					// 全局字符串哈希表（GName）指针
//	constexpr uint64 NameId = 0x1C;							// GName表中的ObjectId偏移（对象ID）
//
//	// ---------------------------- 关卡与场景 ----------------------------
//	constexpr uint64 decActors = 0x0448;					// 游戏场景景Actor相关偏移
//	constexpr uint64 ULevels = 0x158;						// UWorld中的关卡卡数组
//	constexpr uint64 AActors = 0x98;						// 关卡中的Actor数组
//	constexpr uint64 NetDriver = 0x30;						// 网络驱动（NetDriver）
//	constexpr uint64 PersistentLevel = 0xF8;				// 持久化关卡卡（当前活跃关卡）
//
//	// ---------------------------- 游戏状态与模式 ----------------------------
//	constexpr uint64 GameState = 0x0140;					// 游戏状态（GameState）
//	constexpr uint64 DFMGamePlayerMode = 0x0659;			// 玩家模式（值为0x1）
//
//	// ---------------------------- 玩家核心信息核心信息 ----------------------------
//	constexpr uint64 UGameInstance = 0x0190;				// 游戏实例（UGameInstance）
//	constexpr uint64 LocalPlayers = 0x38;					// 本地玩家数组
//	constexpr uint64 PlayerController = 0x030;				// 玩家控制器制器
//	constexpr uint64 AcknowledgedPawn = 0x3F0;				// 已确认的本地角色（玩家操控的角色）
//
//	// ---------------------------- 组件与位置信息 ----------------------------
//	constexpr uint64 RootComponent = 0x0180;				// 根组件（用于位置计算）
//	constexpr uint64 RelativeLocation = 0x148;				// 相对位置（相对于父组件）
//	constexpr uint64 ComponentLocation = 0x220;				// 世界空间位置
//	constexpr uint64 Pitch = 0x208;							// 俯仰角角（旋转角度）
//
//	// ---------------------------- 骨骼与模型 ----------------------------
//	constexpr uint64 Mesh = 0x03D0;							// 骨骼网格组件
//	constexpr uint64 ComponentToWorld = 0x210;				// 模型到世界的变换矩阵
//	constexpr uint64 StaticMesh = 0x728;					// 静态模型
//	constexpr uint64 StaticMeshCache = StaticMesh + 0x10;	// 静态模型缓存（StaticMesh + 0x10）
//
//	// ---------------------------- 玩家状态（PlayerState） ----------------------------
//	constexpr uint64 PlayerState = 0x0390;					// 玩家状态对象
//	constexpr uint64 teamId = 0x066C;						// 队伍ID
//	constexpr uint64 campId = 0x0670;						// 阵营ID
//	constexpr uint64 bDead = 0x04B4;						// 死亡状态标记（布尔值）
//	constexpr uint64 bIsPlayerAI = 0x0D19;					// 是否为AI玩家（布尔值）
//	constexpr uint64 bFinishGame = 0x04C8;					// 游戏结束标记
//	constexpr uint64 HeroId = 0x09B8;						// 英雄ID（大小为0x2）
//	constexpr uint64 PlayerNamePrivate = 0x488;				// 玩家私有名称
//	constexpr uint64 ExitState = 0x0D60;					// 退出状态
//
//	// ---------------------------- 血量系统 ----------------------------
//	constexpr uint64 HealthComp = 0x0F68;					// 健康组件（UGPHealthDataComponent）
//	constexpr uint64 HealthSet = 0x0248;					// 健康属性集（UGPAttributeSetHealth）
//	constexpr uint64 Health = 0x0030 + 0x14;				// 当前血量（FGPGameplayAttributeData.CurrentValue）
//	constexpr uint64 IsAlive = 0x0100 + 0x14;				// 存活状态标记
//	constexpr uint64 MaxHealth = 0x50;				// 最大血量
//
//	// ---------------------------- 武器系统 ----------------------------
//	constexpr uint64 CacheCurWeapon = 0x15E8;				// 当前持有武器缓存
//	constexpr uint64 WeaponID = 0x0820;						// 武器ID
//	constexpr uint64 WeaponID1 = 0x0820;					// 备用武器ID（同WeaponID）
//
//	// ---------------------------- 装备系统（头甲） ----------------------------
//	constexpr uint64 UCharacterEquipComponent = 0x2048;		// 角色装备组件缓存
//	constexpr uint64 EquipmentInfoArray = 0x01D8;			// 装备信息数组
//	constexpr uint64 HelmetArmorLevel = 0x30;				// 头盔等级
//	constexpr uint64 HelmetArmorHp = 0x48;					// 头盔血量
//	constexpr uint64 ArmorLevel = 0x18;						// 护甲等级（OFFSET_FArmorInfo_ArmorLevel）
//	constexpr uint64 ArmorHp = 0x48;						// 护甲血量（OFFSET_FArmorInfo_ArmorHP）
//
//	// ---------------------------- 地面物资与物品 ----------------------------
//	constexpr uint64 PickupItemInfo = 0x0CF0;				// 拾取物信息（原0xC68）
//	constexpr uint64 PickupItemSize = 0x538;				// 拾取物大小（原0x538-2）
//	constexpr uint64 ItemID = 0x10;							// 物品ID（FInventoryItemInfo->ItemID）
//	constexpr uint64 NamePtr = 0x18;						// 名称指针1
//	constexpr uint64 NamePtr1 = 0x18;						// 名称指针2
//	constexpr uint64 NamePtr2 = 0x30;						// 名称指针3
//	constexpr uint64 NamePtr3 = 0x10;						// 名称指针4
//	constexpr uint64 Quality = 0x68;						// 物品品质
//	constexpr uint64 InitialGuidePrice = 0xD8;				// 初始引导价格
//
//	// ---------------------------- 死亡盒子与容器 ----------------------------
//	constexpr uint64 bHasOpened = 0x1D54;					// 是否已打开（宝箱，AInventoryPickup_OpenBox）
//	constexpr uint64 RepItemArray = 0x18C0;					// 物品数组（容器，原0x17C8）
//	constexpr uint64 Items = 0x108;							// 物品列表（FItemArray->Items）
//	constexpr uint64 SizeOfFInventoryItemInfo = 0x0378;		// FInventoryItemInfo结构体大小
//	constexpr uint64 CurrencyGID = 0x1F08;					// 货币GID（尸体拾取物）
//	constexpr uint64 computerPassWord = 0x0DCC;				// 电脑密码（AInteractor_HackPC）
//
//	// ---------------------------- 交互物（拉闸点/撤离点/密码门） ----------------------------
//	constexpr uint64 bExitActive = 0x0A70;					// 撤离点激活状态（SDK未定义）
//	constexpr uint64 NameText = 0x0370;						// 名称文本（APlayerExitBase->NameText）
//	constexpr uint64 ExitConditionConfig = 0x0440;			// 撤离条件配置（APlayerExitBase）
//	constexpr uint64 PwdSum = 0x0E28;						// 密码总和（AInteractor_CodedLock）
//
//	// ---------------------------- 大地图与雷达数据 ----------------------------
//	constexpr uint64 MyHUD = 0x400;							// HUD对象
//	constexpr uint64 Controllers = 0x0468;					// 控制器数组
//	constexpr uint64 ChildControllers = 0x00B0;				// 子控制器
//	constexpr uint64 View = 0x0088;							// UI视图（UBaseUIView）
//	constexpr uint64 preShouldDraw = 0x092C;				// 大地图绘制标记（UBigMapHUDView）
//	constexpr uint64 pa_0840 = 0x838;						// 填充字段（0x0840偏移，大小0x20）
//
//	// 补充原始注释中提到的偏移
//	constexpr uint64 fLastSubmit = 0x02E8;					// 最后提交时间
//};
//
//
//

//#pragma once
//#include <inttypes.h>
//
//// 类型别名增强可读性
//using uint64 = uint64_t;
//using int32 = int32_t;
//
//// ============================ 原始函数偏移（#define OFFSET_ 系列）============================
//// 核心功能函数内存地址偏移
//#define OFFSET_LocalPawn_Func								0x12642720		// 获取本地角色（Pawn）的函数
//#define OFFSET_RootComponent_Func							0x12634880		// 获取根组件的函数
//#define OFFSET_FuncEnc_Param								0x12F4C3C0		// 加密参数处理函数
//#define OFFSET_Ulevel_Func									0x1264AEB0		// 获取ULevel的函数（No WorldSettings上方的call）
//#define OFFSET_GameInstance_Func							0x11C51700		// 游戏实例处理函数（CallHandleDisconnectForFailure下方）
//#define OFFSET_GameState_Func								0x11CB88D0		// 获取GameState的函数（结合InteractionStrength加密相关）
//
//// 相机相关函数偏移
//#define OFFSET_PlayerCamera_Func							0x12642720		// 获取相机位置（GetCameraLocation）
//#define OFFSET_PlayerCamera_Open							0x130AE668		// 相机开启函数
//#define OFFSET_PlayerCamera_Param							0x12642704		// 相机参数函数
//#define OFFSET_PlayerCamera_Core							0x2F2E0			// 相机核心偏移
//#define OFFSET_PlayerCamera_Mul								0x9E0			// 相机乘法因子
//#define OFFSET_PlayerCamera_offset							0x2F2E0			// 相机偏移量
//#define OFFSET_PlayerCameraManager							0x0408			// 相机管理器偏移
//#define OFFSET_CameraCache									0x2F2E0			// 相机缓存
//#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10	// 最小视图信息（基于相机缓存Cache + 0x10）
//
//// ============================ 结构化对象偏移（命名空间分类整理理）============================
//namespace Offsets
//{
//	// ---------------------------- 全局核心对象 ----------------------------
//	constexpr uint64 UWorld = 0x138A5CC8;					// 全局游戏世界（UWorld）指针
//	constexpr uint64 GName = 0x14225A40;					// 全局字符串哈希表（GName）指针
//	constexpr uint64 NameId = 0x1C;							// GName表中的ObjectId偏移（对象ID）
//
//	// ---------------------------- 关卡与场景 ----------------------------
//	constexpr uint64 decActors = 0x0448;					// 游戏场景景Actor相关偏移
//	constexpr uint64 ULevels = 0x158;						// UWorld中的关卡卡数组
//	constexpr uint64 AActors = 0x98;						// 关卡中的Actor数组
//	constexpr uint64 NetDriver = 0x30;						// 网络驱动（NetDriver）
//	constexpr uint64 PersistentLevel = 0xF8;				// 持久化关卡卡（当前活跃关卡）
//
//	// ---------------------------- 游戏状态与模式 ----------------------------
//	constexpr uint64 GameState = 0x0140;					// 游戏状态（GameState）
//	constexpr uint64 DFMGamePlayerMode = 0x0659;			// 玩家模式（值为0x1）
//
//	// ---------------------------- 玩家核心信息核心信息 ----------------------------
//	constexpr uint64 UGameInstance = 0x0190;				// 游戏实例（UGameInstance）
//	constexpr uint64 LocalPlayers = 0x38;					// 本地玩家数组
//	constexpr uint64 PlayerController = 0x030;				// 玩家控制器制器
//	constexpr uint64 AcknowledgedPawn = 0x3B0;				// 已确认的本地角色（玩家操控的角色）
//
//	// ---------------------------- 组件与位置信息 ----------------------------
//	constexpr uint64 RootComponent = 0x0180;				// 根组件（用于位置计算）
//	constexpr uint64 RelativeLocation = 0x148;				// 相对位置（相对于父组件）
//	constexpr uint64 ComponentLocation = 0x220;				// 世界空间位置
//	constexpr uint64 Pitch = 0x208;							// 俯仰角角（旋转角度）
//
//	// ---------------------------- 骨骼与模型 ----------------------------
//	constexpr uint64 Mesh = 0x03D0;							// 骨骼网格组件
//	constexpr uint64 ComponentToWorld = 0x210;				// 模型到世界的变换矩阵
//	constexpr uint64 StaticMesh = 0x728;					// 静态模型
//	constexpr uint64 StaticMeshCache = StaticMesh + 0x10;	// 静态模型缓存（StaticMesh + 0x10）
//
//	// ---------------------------- 玩家状态（PlayerState） ----------------------------
//	constexpr uint64 PlayerState = 0x0390;					// 玩家状态对象
//	constexpr uint64 teamId = 0x108;						// 队伍ID
//	constexpr uint64 campId = 0x10C;						// 阵营ID
//	constexpr uint64 bDead = 0x04C4;						// 死亡状态标记（布尔值）
//	constexpr uint64 bIsPlayerAI = 0x0D19;					// 是否为AI玩家（布尔值）
//	constexpr uint64 bFinishGame = 0x04C8;					// 游戏结束标记
//	constexpr uint64 HeroId = 0x09B8;						// 英雄ID（大小为0x2）
//	constexpr uint64 PlayerNamePrivate = 0x488;				// 玩家私有名称
//	constexpr uint64 ExitState = 0x0D60;					// 退出状态
//
//	// ---------------------------- 血量系统 ----------------------------
//	constexpr uint64 HealthComp = 0x0F68;					// 健康组件（UGPHealthDataComponent）
//	constexpr uint64 HealthSet = 0x0248;					// 健康属性集（UGPAttributeSetHealth）
//	constexpr uint64 Health = 0x60;				// 当前血量（FGPGameplayAttributeData.CurrentValue）
//	constexpr uint64 IsAlive = 0x0100;				// 存活状态标记
//	constexpr uint64 MaxHealth = 0x48;				// 最大血量
//
//	// ---------------------------- 武器系统 ----------------------------
//	constexpr uint64 CacheCurWeapon = 0x15E8;				// 当前持有武器缓存
//	constexpr uint64 WeaponID = 0x0820;						// 武器ID
//	constexpr uint64 WeaponID1 = 0x0820;					// 备用武器ID（同WeaponID）
//
//	// ---------------------------- 装备系统（头甲） ----------------------------
//	constexpr uint64 UCharacterEquipComponent = 0x2048;		// 角色装备组件缓存
//	constexpr uint64 EquipmentInfoArray = 0x01E0;			// 装备信息数组
//	constexpr uint64 HelmetArmorLevel = 0x30;				// 头盔等级
//	constexpr uint64 HelmetArmorHp = 0x48;					// 头盔血量
//	constexpr uint64 ArmorLevel = 0x18;						// 护甲等级（OFFSET_FArmorInfo_ArmorLevel）
//	constexpr uint64 ArmorHp = 0x48;						// 护甲血量（OFFSET_FArmorInfo_ArmorHP）
//
//	// ---------------------------- 地面物资与物品 ----------------------------
//	constexpr uint64 PickupItemInfo = 0xE80;				// 拾取物信息（原0xC68）
//	constexpr uint64 PickupItemSize = 0x538;				// 拾取物大小（原0x538-2）
//	constexpr uint64 ItemID = 0x10;							// 物品ID（FInventoryItemInfo->ItemID）
//	constexpr uint64 NamePtr = 0x18;						// 名称指针1
//	constexpr uint64 NamePtr1 = 0x18;						// 名称指针2
//	constexpr uint64 NamePtr2 = 0x30;						// 名称指针3
//	constexpr uint64 NamePtr3 = 0x10;						// 名称指针4
//	constexpr uint64 Quality = 0x68;						// 物品品质
//	constexpr uint64 InitialGuidePrice = 0xD8;				// 初始引导价格
//
//	// ---------------------------- 死亡盒子与容器 ----------------------------
//	constexpr uint64 bHasOpened = 0x1D54;					// 是否已打开（宝箱，AInventoryPickup_OpenBox）
//	constexpr uint64 RepItemArray = 0x18C0;					// 物品数组（容器，原0x17C8）
//	constexpr uint64 Items = 0x108;							// 物品列表（FItemArray->Items）
//	constexpr uint64 SizeOfFInventoryItemInfo = 0x0378;		// FInventoryItemInfo结构体大小
//	constexpr uint64 CurrencyGID = 0x1F08;					// 货币GID（尸体拾取物）
//	constexpr uint64 computerPassWord = 0x0DCC;				// 电脑密码（AInteractor_HackPC）
//
//	// ---------------------------- 交互物（拉闸点/撤离点/密码门） ----------------------------
//	constexpr uint64 bExitActive = 0x0A70;					// 撤离点激活状态（SDK未定义）
//	constexpr uint64 NameText = 0x0370;						// 名称文本（APlayerExitBase->NameText）
//	constexpr uint64 ExitConditionConfig = 0x0440;			// 撤离条件配置（APlayerExitBase）
//	constexpr uint64 PwdSum = 0x0E28;						// 密码总和（AInteractor_CodedLock）
//
//	// ---------------------------- 大地图与雷达数据 ----------------------------
//	constexpr uint64 MyHUD = 0x400;							// HUD对象
//	constexpr uint64 Controllers = 0x0468;					// 控制器数组
//	constexpr uint64 ChildControllers = 0x00B0;				// 子控制器
//	constexpr uint64 View = 0x0088;							// UI视图（UBaseUIView）
//	constexpr uint64 preShouldDraw = 0x092C;				// 大地图绘制标记（UBigMapHUDView）
//	constexpr uint64 pa_0840 = 0x838;						// 填充字段（0x0840偏移，大小0x20）
//
//	// 补充原始注释中提到的偏移
//	constexpr uint64 fLastSubmit = 0x02E8;					// 最后提交时间
//};
//

#pragma once
#include <inttypes.h>

// 类型别名增强可读性
using uint64 = uint64_t;
using int32 = int32_t;

// ============================ 原始函数偏移（#define OFFSET_ 系列）============================
// 核心功能函数内存地址偏移
#define OFFSET_LocalPawn_Func								0x12642720		// 获取本地角色（Pawn）的函数
#define OFFSET_RootComponent_Func							0x12634880		// 获取根组件的函数
#define OFFSET_FuncEnc_Param								0x12F4C3C0		// 加密参数处理函数
#define OFFSET_Ulevel_Func									0x1264AEB0		// 获取ULevel的函数（No WorldSettings上方的call）
#define OFFSET_GameInstance_Func							0x11C51700		// 游戏实例处理函数（CallHandleDisconnectForFailure下方）
#define OFFSET_GameState_Func								0x11CB88D0		// 获取GameState的函数（结合InteractionStrength加密相关）

// 相机相关函数偏移
#define OFFSET_PlayerCamera_Func							0x12642720		// 获取相机位置（GetCameraLocation）
#define OFFSET_PlayerCamera_Open							0x14389C10		// 相机开启函数
#define OFFSET_PlayerCamera_Param							0x1389FD64		// 相机参数函数
#define OFFSET_PlayerCamera_Core							0x2F2C0			// 相机核心偏移
#define OFFSET_PlayerCamera_Mul								0x9E0			// 相机乘法因子
#define OFFSET_PlayerCamera_offset							0x2F2C0			// 相机偏移量
#define OFFSET_PlayerCameraManager							0x0408			// 相机管理器偏移
#define OFFSET_CameraCache									0x2F2E0			// 相机缓存
#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10	// 最小视图信息（基于相机缓存Cache + 0x10）

// ============================ 结构化对象偏移（命名空间分类整理理）============================
namespace Offsets
{
	// ---------------------------- 全局核心对象 ----------------------------
	constexpr uint64 UWorld = 0x138A5CC8;					// 全局游戏世界（UWorld）指针
	constexpr uint64 GName = 0x14225A40;					// 全局字符串哈希表（GName）指针
	constexpr uint64 NameId = 0x1C;							// GName表中的ObjectId偏移（对象ID）

	// ---------------------------- 关卡与场景 ----------------------------
	constexpr uint64 decActors = 0x0440;					// 游戏场景景Actor相关偏移
	constexpr uint64 ULevels = 0x158;						// UWorld中的关卡卡数组
	constexpr uint64 AActors = 0x98;						// 关卡中的Actor数组
	constexpr uint64 NetDriver = 0x30;						// 网络驱动（NetDriver）
	constexpr uint64 PersistentLevel = 0xF8;				// 持久化关卡卡（当前活跃关卡）

	// ---------------------------- 游戏状态与模式 ----------------------------
	constexpr uint64 GameState = 0x0140;					// 游戏状态（GameState）
	constexpr uint64 DFMGamePlayerMode = 0x0659;			// 玩家模式（值为0x1）

	// ---------------------------- 玩家核心信息核心信息 ----------------------------
	constexpr uint64 UGameInstance = 0x0190;				// 游戏实例（OwningGameInstance）
	constexpr uint64 LocalPlayers = 0x38;					// 本地玩家数组
	constexpr uint64 PlayerController = 0x030;				// 玩家控制器制器
	constexpr uint64 AcknowledgedPawn = 0x03F0;				// 已确认的本地角色（玩家操控的角色）

	// ---------------------------- 组件与位置信息 ----------------------------
	constexpr uint64 RootComponent = 0x0180;				// 根组件（用于位置计算）
	constexpr uint64 RelativeLocation = 0x0168;				// 相对位置（相对于父组件）
	constexpr uint64 ComponentLocation = 0x220;				// 世界空间位置
	constexpr uint64 Pitch = 0x208;//							// 俯仰角角（旋转角度）

	// ---------------------------- 骨骼与模型 ----------------------------
	constexpr uint64 Mesh = 0x03D0;							// 骨骼网格组件
	constexpr uint64 ComponentToWorld = 0x210;				// 模型到世界的变换矩阵
	constexpr uint64 StaticMesh = 0x728;					// 静态模型
	constexpr uint64 StaticMeshCache = StaticMesh + 0x10;	// 静态模型缓存（StaticMesh + 0x10）

	// ---------------------------- 玩家状态（PlayerState） ----------------------------
	constexpr uint64 PlayerState = 0x0390;					// 玩家状态对象
	constexpr uint64 teamId = 0x66C;						// 队伍ID
	constexpr uint64 campId = 0x670;						// 阵营ID
	constexpr uint64 bDead = 0x04B4;						// 死亡状态标记（布尔值）
	constexpr uint64 bIsPlayerAI = 0x518;					// 是否为AI玩家（布尔值）
	constexpr uint64 bFinishGame = 0x04C8;					// 游戏结束标记
	constexpr uint64 HeroId = 0x09B8;						// 英雄ID（大小为0x2）
	constexpr uint64 PlayerNamePrivate = 0x0478;				// 玩家私有名称
	constexpr uint64 ExitState = 0x0D90;					// 退出状态

	// ---------------------------- 血量系统 ----------------------------
	constexpr uint64 HealthComp = 0x0F68;					// 健康组件（UGPHealthDataComponent）
	constexpr uint64 HealthSet = 0x0248;					// 健康属性集（UGPAttributeSetHealth）
	constexpr uint64 Health = 0x3C;				// 当前血量（FGPGameplayAttributeData.CurrentValue）
	constexpr uint64 IsAlive = 0x0100 + 0xC;				// 存活状态标记
	constexpr uint64 MaxHealth = 0x54;				// 最大血量

	// ---------------------------- 武器系统 ----------------------------
	constexpr uint64 CacheCurWeapon = 0x15E8;				// 当前持有武器缓存
	constexpr uint64 WeaponID = 0x0820;						// 武器ID
	constexpr uint64 WeaponID1 = 0x0820;					// 备用武器ID（同WeaponID）

	// ---------------------------- 装备系统（头甲） ----------------------------
	constexpr uint64 UCharacterEquipComponent = 0x2048;		// 角色装备组件缓存
	constexpr uint64 EquipmentInfoArray = 0x01D8;			// 装备信息数组
	constexpr uint64 HelmetArmorLevel = 0x30;//				// 头盔等级
	constexpr uint64 HelmetArmorHp = 0x48;//					// 头盔血量
	constexpr uint64 ArmorLevel = 0xF0;//						// 护甲等级（OFFSET_FArmorInfo_ArmorLevel）
	constexpr uint64 ArmorHp = 0x48;//						// 护甲血量（OFFSET_FArmorInfo_ArmorHP）

	// ---------------------------- 地面物资与物品 ----------------------------
	constexpr uint64 PickupItemInfo = 0x0F10;				// 拾取物信息（原0xC68）
	constexpr uint64 PickupItemSize = 0x578;				// 拾取物大小（原0x538-2）
	constexpr uint64 ItemID = 0x10;							// 物品ID（FInventoryItemInfo->ItemID）
	constexpr uint64 NamePtr = 0x18;//						// 名称指针1
	constexpr uint64 NamePtr1 = 0x18;//						// 名称指针2
	constexpr uint64 NamePtr2 = 0x30;//						// 名称指针3
	constexpr uint64 NamePtr3 = 0x10;//						// 名称指针4
	constexpr uint64 Quality = 0x68;						// 物品品质
	constexpr uint64 InitialGuidePrice = 0xD8;				// 初始引导价格

	// ---------------------------- 死亡盒子与容器 ----------------------------
	constexpr uint64 bHasOpened = 0x1D54;					// 是否已打开（宝箱，AInventoryPickup_OpenBox）
	constexpr uint64 RepItemArray = 0x18C0;					// 物品数组（容器，原0x17C8）
	constexpr uint64 Items = 0x108;							// 物品列表（FItemArray->Items）
	constexpr uint64 SizeOfFInventoryItemInfo = 0x5F0;		// FInventoryItemInfo结构体大小
	constexpr uint64 CurrencyGID = 0x1F08;					// 货币GID（尸体拾取物）
	constexpr uint64 computerPassWord = 0x0DCC;				// 电脑密码（AInteractor_HackPC）

	// ---------------------------- 交互物（拉闸点/撤离点/密码门） ----------------------------
	constexpr uint64 bExitActive = 0x0A70;					// 撤离点激活状态（SDK未定义）
	constexpr uint64 NameText = 0x0370;						// 名称文本（APlayerExitBase->NameText）
	constexpr uint64 ExitConditionConfig = 0x0440;			// 撤离条件配置（APlayerExitBase）
	constexpr uint64 PwdSum = 0x0E28;						// 密码总和（AInteractor_CodedLock）

	// ---------------------------- 大地图与雷达数据 ----------------------------
	constexpr uint64 MyHUD = 0x400;							// HUD对象
	constexpr uint64 Controllers = 0x0468;					// 控制器数组
	constexpr uint64 ChildControllers = 0x00B0;				// 子控制器
	constexpr uint64 View = 0x0088;							// UI视图（UBaseUIView）
	constexpr uint64 preShouldDraw = 0x092C;				// 大地图绘制标记（UBigMapHUDView）
	constexpr uint64 pa_0840 = 0x820;						// 填充字段（0x0840偏移，大小0x20）

	// 补充原始注释中提到的偏移
	constexpr uint64 fLastSubmit = 0x02F8;					// 最后提交时间 这个帮我看看是不是也有问题
};



