//#pragma once
//
//#include<inttypes.h>
//#define OFFSET_LocalPawn_Func								0x12642720
//#define OFFSET_RootComponent_Func							0x12634880
////
//#define OFFSET_FuncEnc_Param								0x12F4C3C0
////No WorldSettings�����һ��call  if (!repair_GetULevel1(v10, 0, 1u))
//#define OFFSET_Ulevel_Func									0x1264AEB0
////CallHandleDisconnectForFailure
////if(a1) �������
//#define OFFSET_GameInstance_Func							0x11C51700
////InteractionStrength������ļ����Լ����õ�,����GameStateƫ�ƿ�
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
//	//��Ϸ����
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
//	//�������
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
//	//����
//	constexpr uint64_t Mesh = 0x03D0;
//	constexpr uint64_t ComponentToWorld = 0x210;
//	constexpr uint64_t StaticMesh = 0x728;
//	constexpr uint64_t StaticMeshCache = StaticMesh + 0x10;
//
//
//
//
//	//PlayerState���
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
//	//------------------------------------������Щƫ���Լ����� �������� �һ����� ������Щȫ�������滻����
//	constexpr uint64_t fLastSubmit = 0x02E8;
//	//CameraCachePrivate+0x10 = FMinimalViewInfo POV; // 0x10(0x9e0)
//	//Ѫ��
//	constexpr uint64_t   HealthComp = 0x0F68;   // Class Engine.GPCharacterBase ->UGPHealthDataComponent* HealthComp; 
//	constexpr uint64_t   HealthSet = 0x0248;   // UGPAttributeSetHealth * HealthSet;
//	constexpr uint64_t   Health = 0x0030 + 0x14;      // FGPGameplayAttributeData                      Health;     float CurrentValue; // 0x10(0x04)
//	constexpr uint64_t   IsAlive = 0x0100 + 0x14;
//	constexpr uint64_t   MaxHealth = 0x48 + 0x14;
//	//����
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
//	//����ͷ��
//	//ADFMPlayerCharacter ->UDFMCharacterAttributeCenterComponent*        DFMAttributesCenter;                                          // 0x1F18(0x0008)
//	//�ȼ�FEquipmentInfo->ArmorLevel;
//
//	constexpr uint64_t UCharacterEquipComponent = 0x2048;//class ADFMCharacter - > CharacterEquipComponentCache
//	constexpr uint64_t EquipmentInfoArray = 0x01D8;
//	constexpr uint64_t HelmetArmorLevel = 0x30;//ͷ
//	constexpr uint64_t HelmetArmorHp = 0x48;//
//	constexpr uint64_t ArmorLevel = 0x18;//OFFSET_FArmorInfo_ArmorLevel
//	constexpr uint64_t ArmorHp = 0x48;//OFFSET_FArmorInfo_ArmorHP
//
//
//
//	//��������
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
//	//�������� ���� 
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
//	//��բ�� &����� &������
//
//	constexpr uint64_t bExitActive = 0x0A70;//SDK����û��
//	constexpr uint64_t NameText = 0x0370;//APlayerExitBase->FText           NameText;                     
//	constexpr uint64_t ExitConditionConfig = 0x0440;//APlayerExitBase->FExitConditionConfig ExitConditionConfig;   
//	constexpr uint64_t PwdSum = 0x0E28;//AInteractor_CodedLock-> int32 PwdSum  
//
//
//
//	//���ͼ�״�����
//	constexpr uint64_t  MyHUD = 0x400;
//	constexpr uint64_t  Controllers = 0x0468;
//	constexpr uint64_t  ChildControllers = 0x00B0;
//	constexpr uint64_t  View = 0x0088;//class UBaseUIView 98
//	constexpr uint64_t  preShouldDraw = 0x092C;//class UBigMapHUDView->char preShouldDraw
//	// struct UBigMapHUDView : UMapBaseHUDView -> �� [0x0020]��ƫ��
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
//// ���ͱ�����ǿ�ɶ���
//using uint64 = uint64_t;
//using int32 = int32_t;
//
//// ============================ ԭʼ����ƫ�ƣ�#define OFFSET_ ϵ�У�============================
//// ���Ĺ��ܺ����ڴ��ַƫ��
//#define OFFSET_LocalPawn_Func								0x12642720		// ��ȡ���ؽ�ɫ��Pawn���ĺ���
//#define OFFSET_RootComponent_Func							0x12634880		// ��ȡ������ĺ���
//#define OFFSET_FuncEnc_Param								0x12F4C3C0		// ���ܲ���������
//#define OFFSET_Ulevel_Func									0x1264AEB0		// ��ȡULevel�ĺ�����No WorldSettings�Ϸ���call��
//#define OFFSET_GameInstance_Func							0x11C51700		// ��Ϸʵ����������CallHandleDisconnectForFailure�·���
//#define OFFSET_GameState_Func								0x11CB88D0		// ��ȡGameState�ĺ��������InteractionStrength������أ�
//
//// �����غ���ƫ��
//#define OFFSET_PlayerCamera_Func							0x12642720		// ��ȡ���λ�ã�GetCameraLocation��
//#define OFFSET_PlayerCamera_Open							0x130AE668		// �����������
//#define OFFSET_PlayerCamera_Param							0x12642704		// �����������
//#define OFFSET_PlayerCamera_Core							0x2F2E0			// �������ƫ��
//#define OFFSET_PlayerCamera_Mul								0x9E0			// ����˷�����
//#define OFFSET_PlayerCamera_offset							0x2F2E0			// ���ƫ����
//#define OFFSET_PlayerCameraManager							0x0408			// ���������ƫ��
//#define OFFSET_CameraCache									0x2F2E0			// �������
//#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10	// ��С��ͼ��Ϣ�������������Cache + 0x10��
//
//// ============================ �ṹ������ƫ�ƣ������ռ����������============================
//namespace Offsets
//{
//	// ---------------------------- ȫ�ֺ��Ķ��� ----------------------------
//	constexpr uint64 UWorld = 0x138A5CC8;					// ȫ����Ϸ���磨UWorld��ָ��
//	constexpr uint64 GName = 0x14225A40;					// ȫ���ַ�����ϣ��GName��ָ��
//	constexpr uint64 NameId = 0x1C;							// GName���е�ObjectIdƫ�ƣ�����ID��
//
//	// ---------------------------- �ؿ��볡�� ----------------------------
//	constexpr uint64 decActors = 0x0448;					// ��Ϸ������Actor���ƫ��
//	constexpr uint64 ULevels = 0x158;						// UWorld�еĹؿ�������
//	constexpr uint64 AActors = 0x98;						// �ؿ��е�Actor����
//	constexpr uint64 NetDriver = 0x30;						// ����������NetDriver��
//	constexpr uint64 PersistentLevel = 0xF8;				// �־û��ؿ�������ǰ��Ծ�ؿ���
//
//	// ---------------------------- ��Ϸ״̬��ģʽ ----------------------------
//	constexpr uint64 GameState = 0x0140;					// ��Ϸ״̬��GameState��
//	constexpr uint64 DFMGamePlayerMode = 0x0659;			// ���ģʽ��ֵΪ0x1��
//
//	// ---------------------------- ��Һ�����Ϣ������Ϣ ----------------------------
//	constexpr uint64 UGameInstance = 0x0190;				// ��Ϸʵ����UGameInstance��
//	constexpr uint64 LocalPlayers = 0x38;					// �����������
//	constexpr uint64 PlayerController = 0x030;				// ��ҿ���������
//	constexpr uint64 AcknowledgedPawn = 0x3F0;				// ��ȷ�ϵı��ؽ�ɫ����ҲٿصĽ�ɫ��
//
//	// ---------------------------- �����λ����Ϣ ----------------------------
//	constexpr uint64 RootComponent = 0x0180;				// �����������λ�ü��㣩
//	constexpr uint64 RelativeLocation = 0x148;				// ���λ�ã�����ڸ������
//	constexpr uint64 ComponentLocation = 0x220;				// ����ռ�λ��
//	constexpr uint64 Pitch = 0x208;							// �����ǽǣ���ת�Ƕȣ�
//
//	// ---------------------------- ������ģ�� ----------------------------
//	constexpr uint64 Mesh = 0x03D0;							// �����������
//	constexpr uint64 ComponentToWorld = 0x210;				// ģ�͵�����ı任����
//	constexpr uint64 StaticMesh = 0x728;					// ��̬ģ��
//	constexpr uint64 StaticMeshCache = StaticMesh + 0x10;	// ��̬ģ�ͻ��棨StaticMesh + 0x10��
//
//	// ---------------------------- ���״̬��PlayerState�� ----------------------------
//	constexpr uint64 PlayerState = 0x0390;					// ���״̬����
//	constexpr uint64 teamId = 0x066C;						// ����ID
//	constexpr uint64 campId = 0x0670;						// ��ӪID
//	constexpr uint64 bDead = 0x04B4;						// ����״̬��ǣ�����ֵ��
//	constexpr uint64 bIsPlayerAI = 0x0D19;					// �Ƿ�ΪAI��ң�����ֵ��
//	constexpr uint64 bFinishGame = 0x04C8;					// ��Ϸ�������
//	constexpr uint64 HeroId = 0x09B8;						// Ӣ��ID����СΪ0x2��
//	constexpr uint64 PlayerNamePrivate = 0x488;				// ���˽������
//	constexpr uint64 ExitState = 0x0D60;					// �˳�״̬
//
//	// ---------------------------- Ѫ��ϵͳ ----------------------------
//	constexpr uint64 HealthComp = 0x0F68;					// ���������UGPHealthDataComponent��
//	constexpr uint64 HealthSet = 0x0248;					// �������Լ���UGPAttributeSetHealth��
//	constexpr uint64 Health = 0x0030 + 0x14;				// ��ǰѪ����FGPGameplayAttributeData.CurrentValue��
//	constexpr uint64 IsAlive = 0x0100 + 0x14;				// ���״̬���
//	constexpr uint64 MaxHealth = 0x50;				// ���Ѫ��
//
//	// ---------------------------- ����ϵͳ ----------------------------
//	constexpr uint64 CacheCurWeapon = 0x15E8;				// ��ǰ������������
//	constexpr uint64 WeaponID = 0x0820;						// ����ID
//	constexpr uint64 WeaponID1 = 0x0820;					// ��������ID��ͬWeaponID��
//
//	// ---------------------------- װ��ϵͳ��ͷ�ף� ----------------------------
//	constexpr uint64 UCharacterEquipComponent = 0x2048;		// ��ɫװ���������
//	constexpr uint64 EquipmentInfoArray = 0x01D8;			// װ����Ϣ����
//	constexpr uint64 HelmetArmorLevel = 0x30;				// ͷ���ȼ�
//	constexpr uint64 HelmetArmorHp = 0x48;					// ͷ��Ѫ��
//	constexpr uint64 ArmorLevel = 0x18;						// ���׵ȼ���OFFSET_FArmorInfo_ArmorLevel��
//	constexpr uint64 ArmorHp = 0x48;						// ����Ѫ����OFFSET_FArmorInfo_ArmorHP��
//
//	// ---------------------------- ������������Ʒ ----------------------------
//	constexpr uint64 PickupItemInfo = 0x0CF0;				// ʰȡ����Ϣ��ԭ0xC68��
//	constexpr uint64 PickupItemSize = 0x538;				// ʰȡ���С��ԭ0x538-2��
//	constexpr uint64 ItemID = 0x10;							// ��ƷID��FInventoryItemInfo->ItemID��
//	constexpr uint64 NamePtr = 0x18;						// ����ָ��1
//	constexpr uint64 NamePtr1 = 0x18;						// ����ָ��2
//	constexpr uint64 NamePtr2 = 0x30;						// ����ָ��3
//	constexpr uint64 NamePtr3 = 0x10;						// ����ָ��4
//	constexpr uint64 Quality = 0x68;						// ��ƷƷ��
//	constexpr uint64 InitialGuidePrice = 0xD8;				// ��ʼ�����۸�
//
//	// ---------------------------- �������������� ----------------------------
//	constexpr uint64 bHasOpened = 0x1D54;					// �Ƿ��Ѵ򿪣����䣬AInventoryPickup_OpenBox��
//	constexpr uint64 RepItemArray = 0x18C0;					// ��Ʒ���飨������ԭ0x17C8��
//	constexpr uint64 Items = 0x108;							// ��Ʒ�б�FItemArray->Items��
//	constexpr uint64 SizeOfFInventoryItemInfo = 0x0378;		// FInventoryItemInfo�ṹ���С
//	constexpr uint64 CurrencyGID = 0x1F08;					// ����GID��ʬ��ʰȡ�
//	constexpr uint64 computerPassWord = 0x0DCC;				// �������루AInteractor_HackPC��
//
//	// ---------------------------- �������բ��/�����/�����ţ� ----------------------------
//	constexpr uint64 bExitActive = 0x0A70;					// ����㼤��״̬��SDKδ���壩
//	constexpr uint64 NameText = 0x0370;						// �����ı���APlayerExitBase->NameText��
//	constexpr uint64 ExitConditionConfig = 0x0440;			// �����������ã�APlayerExitBase��
//	constexpr uint64 PwdSum = 0x0E28;						// �����ܺͣ�AInteractor_CodedLock��
//
//	// ---------------------------- ���ͼ���״����� ----------------------------
//	constexpr uint64 MyHUD = 0x400;							// HUD����
//	constexpr uint64 Controllers = 0x0468;					// ����������
//	constexpr uint64 ChildControllers = 0x00B0;				// �ӿ�����
//	constexpr uint64 View = 0x0088;							// UI��ͼ��UBaseUIView��
//	constexpr uint64 preShouldDraw = 0x092C;				// ���ͼ���Ʊ�ǣ�UBigMapHUDView��
//	constexpr uint64 pa_0840 = 0x838;						// ����ֶΣ�0x0840ƫ�ƣ���С0x20��
//
//	// ����ԭʼע�����ᵽ��ƫ��
//	constexpr uint64 fLastSubmit = 0x02E8;					// ����ύʱ��
//};
//
//
//

//#pragma once
//#include <inttypes.h>
//
//// ���ͱ�����ǿ�ɶ���
//using uint64 = uint64_t;
//using int32 = int32_t;
//
//// ============================ ԭʼ����ƫ�ƣ�#define OFFSET_ ϵ�У�============================
//// ���Ĺ��ܺ����ڴ��ַƫ��
//#define OFFSET_LocalPawn_Func								0x12642720		// ��ȡ���ؽ�ɫ��Pawn���ĺ���
//#define OFFSET_RootComponent_Func							0x12634880		// ��ȡ������ĺ���
//#define OFFSET_FuncEnc_Param								0x12F4C3C0		// ���ܲ���������
//#define OFFSET_Ulevel_Func									0x1264AEB0		// ��ȡULevel�ĺ�����No WorldSettings�Ϸ���call��
//#define OFFSET_GameInstance_Func							0x11C51700		// ��Ϸʵ����������CallHandleDisconnectForFailure�·���
//#define OFFSET_GameState_Func								0x11CB88D0		// ��ȡGameState�ĺ��������InteractionStrength������أ�
//
//// �����غ���ƫ��
//#define OFFSET_PlayerCamera_Func							0x12642720		// ��ȡ���λ�ã�GetCameraLocation��
//#define OFFSET_PlayerCamera_Open							0x130AE668		// �����������
//#define OFFSET_PlayerCamera_Param							0x12642704		// �����������
//#define OFFSET_PlayerCamera_Core							0x2F2E0			// �������ƫ��
//#define OFFSET_PlayerCamera_Mul								0x9E0			// ����˷�����
//#define OFFSET_PlayerCamera_offset							0x2F2E0			// ���ƫ����
//#define OFFSET_PlayerCameraManager							0x0408			// ���������ƫ��
//#define OFFSET_CameraCache									0x2F2E0			// �������
//#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10	// ��С��ͼ��Ϣ�������������Cache + 0x10��
//
//// ============================ �ṹ������ƫ�ƣ������ռ����������============================
//namespace Offsets
//{
//	// ---------------------------- ȫ�ֺ��Ķ��� ----------------------------
//	constexpr uint64 UWorld = 0x138A5CC8;					// ȫ����Ϸ���磨UWorld��ָ��
//	constexpr uint64 GName = 0x14225A40;					// ȫ���ַ�����ϣ��GName��ָ��
//	constexpr uint64 NameId = 0x1C;							// GName���е�ObjectIdƫ�ƣ�����ID��
//
//	// ---------------------------- �ؿ��볡�� ----------------------------
//	constexpr uint64 decActors = 0x0448;					// ��Ϸ������Actor���ƫ��
//	constexpr uint64 ULevels = 0x158;						// UWorld�еĹؿ�������
//	constexpr uint64 AActors = 0x98;						// �ؿ��е�Actor����
//	constexpr uint64 NetDriver = 0x30;						// ����������NetDriver��
//	constexpr uint64 PersistentLevel = 0xF8;				// �־û��ؿ�������ǰ��Ծ�ؿ���
//
//	// ---------------------------- ��Ϸ״̬��ģʽ ----------------------------
//	constexpr uint64 GameState = 0x0140;					// ��Ϸ״̬��GameState��
//	constexpr uint64 DFMGamePlayerMode = 0x0659;			// ���ģʽ��ֵΪ0x1��
//
//	// ---------------------------- ��Һ�����Ϣ������Ϣ ----------------------------
//	constexpr uint64 UGameInstance = 0x0190;				// ��Ϸʵ����UGameInstance��
//	constexpr uint64 LocalPlayers = 0x38;					// �����������
//	constexpr uint64 PlayerController = 0x030;				// ��ҿ���������
//	constexpr uint64 AcknowledgedPawn = 0x3B0;				// ��ȷ�ϵı��ؽ�ɫ����ҲٿصĽ�ɫ��
//
//	// ---------------------------- �����λ����Ϣ ----------------------------
//	constexpr uint64 RootComponent = 0x0180;				// �����������λ�ü��㣩
//	constexpr uint64 RelativeLocation = 0x148;				// ���λ�ã�����ڸ������
//	constexpr uint64 ComponentLocation = 0x220;				// ����ռ�λ��
//	constexpr uint64 Pitch = 0x208;							// �����ǽǣ���ת�Ƕȣ�
//
//	// ---------------------------- ������ģ�� ----------------------------
//	constexpr uint64 Mesh = 0x03D0;							// �����������
//	constexpr uint64 ComponentToWorld = 0x210;				// ģ�͵�����ı任����
//	constexpr uint64 StaticMesh = 0x728;					// ��̬ģ��
//	constexpr uint64 StaticMeshCache = StaticMesh + 0x10;	// ��̬ģ�ͻ��棨StaticMesh + 0x10��
//
//	// ---------------------------- ���״̬��PlayerState�� ----------------------------
//	constexpr uint64 PlayerState = 0x0390;					// ���״̬����
//	constexpr uint64 teamId = 0x108;						// ����ID
//	constexpr uint64 campId = 0x10C;						// ��ӪID
//	constexpr uint64 bDead = 0x04C4;						// ����״̬��ǣ�����ֵ��
//	constexpr uint64 bIsPlayerAI = 0x0D19;					// �Ƿ�ΪAI��ң�����ֵ��
//	constexpr uint64 bFinishGame = 0x04C8;					// ��Ϸ�������
//	constexpr uint64 HeroId = 0x09B8;						// Ӣ��ID����СΪ0x2��
//	constexpr uint64 PlayerNamePrivate = 0x488;				// ���˽������
//	constexpr uint64 ExitState = 0x0D60;					// �˳�״̬
//
//	// ---------------------------- Ѫ��ϵͳ ----------------------------
//	constexpr uint64 HealthComp = 0x0F68;					// ���������UGPHealthDataComponent��
//	constexpr uint64 HealthSet = 0x0248;					// �������Լ���UGPAttributeSetHealth��
//	constexpr uint64 Health = 0x60;				// ��ǰѪ����FGPGameplayAttributeData.CurrentValue��
//	constexpr uint64 IsAlive = 0x0100;				// ���״̬���
//	constexpr uint64 MaxHealth = 0x48;				// ���Ѫ��
//
//	// ---------------------------- ����ϵͳ ----------------------------
//	constexpr uint64 CacheCurWeapon = 0x15E8;				// ��ǰ������������
//	constexpr uint64 WeaponID = 0x0820;						// ����ID
//	constexpr uint64 WeaponID1 = 0x0820;					// ��������ID��ͬWeaponID��
//
//	// ---------------------------- װ��ϵͳ��ͷ�ף� ----------------------------
//	constexpr uint64 UCharacterEquipComponent = 0x2048;		// ��ɫװ���������
//	constexpr uint64 EquipmentInfoArray = 0x01E0;			// װ����Ϣ����
//	constexpr uint64 HelmetArmorLevel = 0x30;				// ͷ���ȼ�
//	constexpr uint64 HelmetArmorHp = 0x48;					// ͷ��Ѫ��
//	constexpr uint64 ArmorLevel = 0x18;						// ���׵ȼ���OFFSET_FArmorInfo_ArmorLevel��
//	constexpr uint64 ArmorHp = 0x48;						// ����Ѫ����OFFSET_FArmorInfo_ArmorHP��
//
//	// ---------------------------- ������������Ʒ ----------------------------
//	constexpr uint64 PickupItemInfo = 0xE80;				// ʰȡ����Ϣ��ԭ0xC68��
//	constexpr uint64 PickupItemSize = 0x538;				// ʰȡ���С��ԭ0x538-2��
//	constexpr uint64 ItemID = 0x10;							// ��ƷID��FInventoryItemInfo->ItemID��
//	constexpr uint64 NamePtr = 0x18;						// ����ָ��1
//	constexpr uint64 NamePtr1 = 0x18;						// ����ָ��2
//	constexpr uint64 NamePtr2 = 0x30;						// ����ָ��3
//	constexpr uint64 NamePtr3 = 0x10;						// ����ָ��4
//	constexpr uint64 Quality = 0x68;						// ��ƷƷ��
//	constexpr uint64 InitialGuidePrice = 0xD8;				// ��ʼ�����۸�
//
//	// ---------------------------- �������������� ----------------------------
//	constexpr uint64 bHasOpened = 0x1D54;					// �Ƿ��Ѵ򿪣����䣬AInventoryPickup_OpenBox��
//	constexpr uint64 RepItemArray = 0x18C0;					// ��Ʒ���飨������ԭ0x17C8��
//	constexpr uint64 Items = 0x108;							// ��Ʒ�б�FItemArray->Items��
//	constexpr uint64 SizeOfFInventoryItemInfo = 0x0378;		// FInventoryItemInfo�ṹ���С
//	constexpr uint64 CurrencyGID = 0x1F08;					// ����GID��ʬ��ʰȡ�
//	constexpr uint64 computerPassWord = 0x0DCC;				// �������루AInteractor_HackPC��
//
//	// ---------------------------- �������բ��/�����/�����ţ� ----------------------------
//	constexpr uint64 bExitActive = 0x0A70;					// ����㼤��״̬��SDKδ���壩
//	constexpr uint64 NameText = 0x0370;						// �����ı���APlayerExitBase->NameText��
//	constexpr uint64 ExitConditionConfig = 0x0440;			// �����������ã�APlayerExitBase��
//	constexpr uint64 PwdSum = 0x0E28;						// �����ܺͣ�AInteractor_CodedLock��
//
//	// ---------------------------- ���ͼ���״����� ----------------------------
//	constexpr uint64 MyHUD = 0x400;							// HUD����
//	constexpr uint64 Controllers = 0x0468;					// ����������
//	constexpr uint64 ChildControllers = 0x00B0;				// �ӿ�����
//	constexpr uint64 View = 0x0088;							// UI��ͼ��UBaseUIView��
//	constexpr uint64 preShouldDraw = 0x092C;				// ���ͼ���Ʊ�ǣ�UBigMapHUDView��
//	constexpr uint64 pa_0840 = 0x838;						// ����ֶΣ�0x0840ƫ�ƣ���С0x20��
//
//	// ����ԭʼע�����ᵽ��ƫ��
//	constexpr uint64 fLastSubmit = 0x02E8;					// ����ύʱ��
//};
//

#pragma once
#include <inttypes.h>

// ���ͱ�����ǿ�ɶ���
using uint64 = uint64_t;
using int32 = int32_t;

// ============================ ԭʼ����ƫ�ƣ�#define OFFSET_ ϵ�У�============================
// ���Ĺ��ܺ����ڴ��ַƫ��
#define OFFSET_LocalPawn_Func								0x12642720		// ��ȡ���ؽ�ɫ��Pawn���ĺ���
#define OFFSET_RootComponent_Func							0x12634880		// ��ȡ������ĺ���
#define OFFSET_FuncEnc_Param								0x12F4C3C0		// ���ܲ���������
#define OFFSET_Ulevel_Func									0x1264AEB0		// ��ȡULevel�ĺ�����No WorldSettings�Ϸ���call��
#define OFFSET_GameInstance_Func							0x11C51700		// ��Ϸʵ����������CallHandleDisconnectForFailure�·���
#define OFFSET_GameState_Func								0x11CB88D0		// ��ȡGameState�ĺ��������InteractionStrength������أ�

// �����غ���ƫ��
#define OFFSET_PlayerCamera_Func							0x12642720		// ��ȡ���λ�ã�GetCameraLocation��
#define OFFSET_PlayerCamera_Open							0x14389C10		// �����������
#define OFFSET_PlayerCamera_Param							0x1389FD64		// �����������
#define OFFSET_PlayerCamera_Core							0x2F2C0			// �������ƫ��
#define OFFSET_PlayerCamera_Mul								0x9E0			// ����˷�����
#define OFFSET_PlayerCamera_offset							0x2F2C0			// ���ƫ����
#define OFFSET_PlayerCameraManager							0x0408			// ���������ƫ��
#define OFFSET_CameraCache									0x2F2E0			// �������
#define OFFSET_FMinimalViewInfo								OFFSET_CameraCache + 0x10	// ��С��ͼ��Ϣ�������������Cache + 0x10��

// ============================ �ṹ������ƫ�ƣ������ռ����������============================
namespace Offsets
{
	// ---------------------------- ȫ�ֺ��Ķ��� ----------------------------
	constexpr uint64 UWorld = 0x138A5CC8;					// ȫ����Ϸ���磨UWorld��ָ��
	constexpr uint64 GName = 0x14225A40;					// ȫ���ַ�����ϣ��GName��ָ��
	constexpr uint64 NameId = 0x1C;							// GName���е�ObjectIdƫ�ƣ�����ID��

	// ---------------------------- �ؿ��볡�� ----------------------------
	constexpr uint64 decActors = 0x0440;					// ��Ϸ������Actor���ƫ��
	constexpr uint64 ULevels = 0x158;						// UWorld�еĹؿ�������
	constexpr uint64 AActors = 0x98;						// �ؿ��е�Actor����
	constexpr uint64 NetDriver = 0x30;						// ����������NetDriver��
	constexpr uint64 PersistentLevel = 0xF8;				// �־û��ؿ�������ǰ��Ծ�ؿ���

	// ---------------------------- ��Ϸ״̬��ģʽ ----------------------------
	constexpr uint64 GameState = 0x0140;					// ��Ϸ״̬��GameState��
	constexpr uint64 DFMGamePlayerMode = 0x0659;			// ���ģʽ��ֵΪ0x1��

	// ---------------------------- ��Һ�����Ϣ������Ϣ ----------------------------
	constexpr uint64 UGameInstance = 0x0190;				// ��Ϸʵ����OwningGameInstance��
	constexpr uint64 LocalPlayers = 0x38;					// �����������
	constexpr uint64 PlayerController = 0x030;				// ��ҿ���������
	constexpr uint64 AcknowledgedPawn = 0x03F0;				// ��ȷ�ϵı��ؽ�ɫ����ҲٿصĽ�ɫ��

	// ---------------------------- �����λ����Ϣ ----------------------------
	constexpr uint64 RootComponent = 0x0180;				// �����������λ�ü��㣩
	constexpr uint64 RelativeLocation = 0x0168;				// ���λ�ã�����ڸ������
	constexpr uint64 ComponentLocation = 0x220;				// ����ռ�λ��
	constexpr uint64 Pitch = 0x208;//							// �����ǽǣ���ת�Ƕȣ�

	// ---------------------------- ������ģ�� ----------------------------
	constexpr uint64 Mesh = 0x03D0;							// �����������
	constexpr uint64 ComponentToWorld = 0x210;				// ģ�͵�����ı任����
	constexpr uint64 StaticMesh = 0x728;					// ��̬ģ��
	constexpr uint64 StaticMeshCache = StaticMesh + 0x10;	// ��̬ģ�ͻ��棨StaticMesh + 0x10��

	// ---------------------------- ���״̬��PlayerState�� ----------------------------
	constexpr uint64 PlayerState = 0x0390;					// ���״̬����
	constexpr uint64 teamId = 0x66C;						// ����ID
	constexpr uint64 campId = 0x670;						// ��ӪID
	constexpr uint64 bDead = 0x04B4;						// ����״̬��ǣ�����ֵ��
	constexpr uint64 bIsPlayerAI = 0x518;					// �Ƿ�ΪAI��ң�����ֵ��
	constexpr uint64 bFinishGame = 0x04C8;					// ��Ϸ�������
	constexpr uint64 HeroId = 0x09B8;						// Ӣ��ID����СΪ0x2��
	constexpr uint64 PlayerNamePrivate = 0x0478;				// ���˽������
	constexpr uint64 ExitState = 0x0D90;					// �˳�״̬

	// ---------------------------- Ѫ��ϵͳ ----------------------------
	constexpr uint64 HealthComp = 0x0F68;					// ���������UGPHealthDataComponent��
	constexpr uint64 HealthSet = 0x0248;					// �������Լ���UGPAttributeSetHealth��
	constexpr uint64 Health = 0x3C;				// ��ǰѪ����FGPGameplayAttributeData.CurrentValue��
	constexpr uint64 IsAlive = 0x0100 + 0xC;				// ���״̬���
	constexpr uint64 MaxHealth = 0x54;				// ���Ѫ��

	// ---------------------------- ����ϵͳ ----------------------------
	constexpr uint64 CacheCurWeapon = 0x15E8;				// ��ǰ������������
	constexpr uint64 WeaponID = 0x0820;						// ����ID
	constexpr uint64 WeaponID1 = 0x0820;					// ��������ID��ͬWeaponID��

	// ---------------------------- װ��ϵͳ��ͷ�ף� ----------------------------
	constexpr uint64 UCharacterEquipComponent = 0x2048;		// ��ɫװ���������
	constexpr uint64 EquipmentInfoArray = 0x01D8;			// װ����Ϣ����
	constexpr uint64 HelmetArmorLevel = 0x30;//				// ͷ���ȼ�
	constexpr uint64 HelmetArmorHp = 0x48;//					// ͷ��Ѫ��
	constexpr uint64 ArmorLevel = 0xF0;//						// ���׵ȼ���OFFSET_FArmorInfo_ArmorLevel��
	constexpr uint64 ArmorHp = 0x48;//						// ����Ѫ����OFFSET_FArmorInfo_ArmorHP��

	// ---------------------------- ������������Ʒ ----------------------------
	constexpr uint64 PickupItemInfo = 0x0F10;				// ʰȡ����Ϣ��ԭ0xC68��
	constexpr uint64 PickupItemSize = 0x578;				// ʰȡ���С��ԭ0x538-2��
	constexpr uint64 ItemID = 0x10;							// ��ƷID��FInventoryItemInfo->ItemID��
	constexpr uint64 NamePtr = 0x18;//						// ����ָ��1
	constexpr uint64 NamePtr1 = 0x18;//						// ����ָ��2
	constexpr uint64 NamePtr2 = 0x30;//						// ����ָ��3
	constexpr uint64 NamePtr3 = 0x10;//						// ����ָ��4
	constexpr uint64 Quality = 0x68;						// ��ƷƷ��
	constexpr uint64 InitialGuidePrice = 0xD8;				// ��ʼ�����۸�

	// ---------------------------- �������������� ----------------------------
	constexpr uint64 bHasOpened = 0x1D54;					// �Ƿ��Ѵ򿪣����䣬AInventoryPickup_OpenBox��
	constexpr uint64 RepItemArray = 0x18C0;					// ��Ʒ���飨������ԭ0x17C8��
	constexpr uint64 Items = 0x108;							// ��Ʒ�б�FItemArray->Items��
	constexpr uint64 SizeOfFInventoryItemInfo = 0x5F0;		// FInventoryItemInfo�ṹ���С
	constexpr uint64 CurrencyGID = 0x1F08;					// ����GID��ʬ��ʰȡ�
	constexpr uint64 computerPassWord = 0x0DCC;				// �������루AInteractor_HackPC��

	// ---------------------------- �������բ��/�����/�����ţ� ----------------------------
	constexpr uint64 bExitActive = 0x0A70;					// ����㼤��״̬��SDKδ���壩
	constexpr uint64 NameText = 0x0370;						// �����ı���APlayerExitBase->NameText��
	constexpr uint64 ExitConditionConfig = 0x0440;			// �����������ã�APlayerExitBase��
	constexpr uint64 PwdSum = 0x0E28;						// �����ܺͣ�AInteractor_CodedLock��

	// ---------------------------- ���ͼ���״����� ----------------------------
	constexpr uint64 MyHUD = 0x400;							// HUD����
	constexpr uint64 Controllers = 0x0468;					// ����������
	constexpr uint64 ChildControllers = 0x00B0;				// �ӿ�����
	constexpr uint64 View = 0x0088;							// UI��ͼ��UBaseUIView��
	constexpr uint64 preShouldDraw = 0x092C;				// ���ͼ���Ʊ�ǣ�UBigMapHUDView��
	constexpr uint64 pa_0840 = 0x820;						// ����ֶΣ�0x0840ƫ�ƣ���С0x20��

	// ����ԭʼע�����ᵽ��ƫ��
	constexpr uint64 fLastSubmit = 0x02F8;					// ����ύʱ�� ������ҿ����ǲ���Ҳ������
};



