//#pragma once
//
//#include<Windows.h>
//#include"imgui.h"
//namespace Configs
//{
//	//�ܿ���
//	inline bool isMenu = true;
//	inline bool isFireMode = false;//ս��ģʽ
//	inline bool isEnd = false;
//
//	inline int FireModeKey = VK_OEM_3;		// ս��ģʽ�ȼ�
//	inline int ShowMenuKey = VK_F12;	// ���ز˵��ȼ�
//	inline int ForceFreshKey = VK_F5;	// ǿ��ˢ��
//	inline int EndKey = VK_END;	// �˳�
//	namespace Aimbot
//	{
//		inline	float Smooth = 100.f; //ƽ�� 1-20
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
//		inline	const char* AimBith[4] = { U8("ͷ��"), U8("����"), U8("�ز�"), U8("�Ų�") };
//
//
//
//		inline	const char* KeyBad[4] = { U8("�Ҽ�"), U8("���"), U8("shift"), U8("ctrl") };
//
//		inline	const char* ValueBadd[5] = { U8("����"), U8("����"), U8("�ļ�"), U8("�弶"),U8("����") };
//
//
//		inline	const char* AimMod[1] = { U8("ƽ������")};
//
//		inline	const char* HealthStr[2] = { U8("��ɫ"), U8("�ʺ�ɫ") };
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
//		inline bool DrawAI = true;//�Ƿ�����˻�
//		inline bool DrawDrawMap = true;//�Ƿ��ͼ�״�
//		inline bool DrawBoss = true;//�Ƿ�����˻�
//		inline bool DrawBox2D = false;
//		inline bool DrawBone=true;
//		inline bool DrawHealth = true;;
//		inline bool Dituradar = true;
//		inline bool DrawDistance = true;;
//		inline bool DrawPlayerName = true;;
//		inline bool DrawTeam=true;
//		inline bool DrawEquipment=true;//ͷ��
//		inline bool DrawWeapon=false;//�ֳ�
//		inline bool DrawWeaponICO = true;//�ֳ�
//		inline bool BotName = true;
//		inline bool	DrawEquipmentIco = false;
//
//		inline bool BotBone = true;
//
//		inline bool ShowDistance = true;
//
//		inline bool isShowOutSight = true;
//
//		inline bool displayNPCName = true;      // ��ʾNPC����
//		inline bool displayNPCWeapon = false;    // ��ʾNPC�ֳ�����
//		inline bool displayNPCDistance = true;  // ��ʾ��NPC�ľ���
//		inline bool displayNPCSkeleton = true;  // ��ʾNPC����
//		inline bool displayNPCBox = false;       // ��ʾNPC����
//		inline bool displayNPCHealthBar = true; // ��ʾNPCѪ��
//		inline bool DrawEyu = true; // ��ʾNPCѪ��
//		inline	const char* Mod[2] = { U8("ս��ģʽ"), U8("���ģʽ")};
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
//		inline bool DrawItem = true;//�ܿ���
//
//		inline int ShowItemMaxDistance = 200;//��������������
//		inline int ShowInteractorInnerMaxDistance = 30;//����������
//		inline int ShowInteractorMaxDistance = 100;//����
//		inline int ShowDeadBoxMaxDistance = 100;//����
//		inline int ShowDeadBoxInnerMaxDistance = 30;//����������
//		inline int ShowExitMaxDistance = 300;//�����
//		inline int ShowTriggerExitMaxDistance = 300;//��բ��
//		inline int ShowDoorMaxDistance = 300;//������
//		inline bool DrawInteractor = true;
//		inline bool		DrawAiBox = true;
//		inline bool DrawExit = true;//�����
//		inline bool DrawTriggerExit = true;//��բ��
//
//		inline bool DrawItemValueList = true;//��բ��
//		inline bool DrawDoor = true;//������
//		inline bool DrawItemsIco = true;
//		inline bool DrawItems = true;
//		inline bool ShowInteractorInner = true;
//		inline bool ShowInteractor = true;
//		inline int32_t Valuefilter = 5000;
//		inline bool DrawPlayerBox = true;
//
//		// ��Ʒ���ʹ����Լ�飨���ݵ�ǰ�����ģ�
//		inline bool IsToolCabinet = true;        // ���߹�
//		inline bool IsBirdNest = true;           // ����
//		inline bool IsAmmoBox = true;            // ��ҩ��
//		inline bool IsBigSnakeBag = true;        // ����Ƥ�ڴ�
//		inline bool IsBigWeaponBox = true;       // ��������
//		inline bool IsComputer = true;           // ����
//		inline bool IsDrawerCabinet = true;      // �����
//		inline bool IsAviationLocker = true;     // ���մ�����
//		inline bool IsClothes = true;            // �·�
//		inline bool IsTrashBin = true;           // ������
//		inline bool IsMedicalSupplies = true;    // ҽ��������
//		inline bool IsPremiumLuggage = true;     // �߼�������
//		inline bool IsServer = true;             // ������
//		inline bool IsOfficeOrganizer = true;    // �칫�����ɺ�
//		inline bool IsHudsonClothes = true;      // ����ɭ�·�
//		inline bool IsPremiumStorageBox = true;  // �߼�������
//		inline bool IsExpressBox = true;         // �����
//		inline bool IsSmallSafe = true;          // С������
//		inline bool IsHikingBackpack = true;     // ��ɽ��
//		inline bool IsCementTruck = true;        // ˮ�೵
//		inline bool IsMedicalKit = true;         // ҽ�ư�
//		inline bool IsHiddenStash = true;        // ������
//		inline bool IsLowGradeLocker = true;     // �ͼ����˴�����
//
//		inline bool BaoXianGUI = true;
//		inline bool IsHackerComputer = true;
//
//
//		inline bool IsSuitcase = true;               // U8("������")
//		inline bool IsBlackTideWeaponCase = true;     // U8("��ɫ��ϫ������")
//		inline bool IsFieldSupplyBox = true;          // U8("Ұ��ս����")
//		inline bool IsLargeToolBox = true;            // U8("�󹤾ߺ�")
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

// �޸�UTF-8�궨�壬ȷ������������ʾ
#ifndef U8
#define U8(str) u8##str
#endif

namespace Configs
{
	//�ܿ���
	inline bool isMenu = true;
	inline bool isFireMode = false;//ս��ģʽ
	inline bool DZT = false;//ս��ģʽ
	inline bool isEnd = false;

	inline int FireModeKey = VK_OEM_3;		// ս��ģʽ�ȼ�
	inline int ShowMenuKey = VK_F12;	// ���ز˵��ȼ�
	inline int ForceFreshKey = VK_F5;	// ǿ��ˢ��
	inline int EndKey = VK_END;	// �˳�

	namespace Aimbot
	{
		inline	float Smooth = 100.f; //ƽ�� 1-20
		inline float SmoothInt = 50.f;
		inline	float XSpeed = 2.5f;//1-5
		inline float YSpeed = 2.5f;//1-5

		inline float Fovsize = 200.0f;

		inline bool DrawAimFov = true;

		inline bool DoAimbot = true;

		inline bool AimLine = false;

		inline float SmoothY = 100.f;

		// �޸������ʼ����ʽ��ȷ����������
		inline const char* AimBith[4] = { U8("ͷ��"), U8("����"), U8("�ز�"), U8("�Ų�") };

		inline const char* KeyBad[4] = { U8("�Ҽ�"), U8("���"), U8("shift"), U8("ctrl") };

		inline const char* ValueBadd[5] = { U8("����"), U8("����"), U8("�ļ�"), U8("�弶"), U8("����") };

		// ����ԭʼ�����С���޸��﷨��ʽ
		inline const char* AimMod[1] = { U8("ƽ������") };

		inline const char* HealthStr[2] = { U8("��ɫ"), U8("�ʺ�ɫ") };
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

		inline bool DrawAI = true;//�Ƿ�����˻�
		inline bool DrawDrawMap = true;//�Ƿ��ͼ�״�
		inline bool DrawBoss = true;//�Ƿ�����˻�
		inline bool DrawBox2D = false;
		inline bool DrawBone = true;
		inline bool DrawHealth = true;;
		inline bool Dituradar = true;
		inline bool DrawDistance = true;;
		inline bool DrawPlayerName = true;;
		inline bool DrawTeam = true;
		inline bool DrawEquipment = true;//ͷ��
		inline bool DrawWeapon = false;//�ֳ�
		inline bool DrawWeaponICO = true;//�ֳ�
		inline bool BotName = true;
		inline bool DrawEquipmentIco = false;

		inline bool BotBone = true;

		inline bool ShowDistance = true;

		inline bool isShowOutSight = true;

		inline bool displayNPCName = true;      // ��ʾNPC����
		inline bool displayNPCWeapon = false;    // ��ʾNPC�ֳ�����
		inline bool displayNPCDistance = true;  // ��ʾ��NPC�ľ���
		inline bool displayNPCSkeleton = true;  // ��ʾNPC����
		inline bool displayNPCBox = false;       // ��ʾNPC����
		inline bool displayNPCHealthBar = true; // ��ʾNPCѪ��
		inline bool DrawEyu = true; // ��ʾNPCѪ��

		inline const char* Mod[2] = { U8("ս��ģʽ"), U8("���ģʽ") };

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
		inline bool DrawItem = true;//�ܿ���

		inline int ShowItemMaxDistance = 200;//��������������
		inline int ShowInteractorInnerMaxDistance = 30;//����������
		inline int ShowInteractorMaxDistance = 100;//����
		inline int ShowDeadBoxMaxDistance = 100;//����
		inline int ShowDeadBoxInnerMaxDistance = 30;//����������
		inline int ShowExitMaxDistance = 300;//�����
		inline int ShowTriggerExitMaxDistance = 300;//��բ��
		inline int ShowDoorMaxDistance = 300;//������
		inline bool DrawInteractor = true;
		inline bool DrawAiBox = true;
		inline bool DrawExit = true;//�����
		inline bool DrawTriggerExit = true;//��բ��

		inline bool DrawItemValueList = true;//��բ��
		inline bool DrawDoor = true;//������
		inline bool DrawItemsIco = true;
		inline bool DrawItems = true;
		inline bool ShowInteractorInner = true;
		inline bool ShowInteractor = true;
		inline int32_t Valuefilter = 5000;
		inline bool DrawPlayerBox = true;

		// ��Ʒ���ʹ����Լ�飨����ԭʼ������
		inline bool IsToolCabinet = true;        // ���߹�
		inline bool IsBirdNest = true;           // ����
		inline bool IsAmmoBox = true;            // ��ҩ��
		inline bool IsBigSnakeBag = true;        // ����Ƥ�ڴ�
		inline bool IsBigWeaponBox = true;       // ��������
		inline bool IsComputer = true;           // ����
		inline bool IsDrawerCabinet = true;      // �����
		inline bool IsAviationLocker = true;     // ���մ�����
		inline bool IsClothes = true;            // �·�
		inline bool IsTrashBin = true;           // ������
		inline bool IsMedicalSupplies = true;    // ҽ��������
		inline bool IsPremiumLuggage = true;     // �߼�������
		inline bool IsServer = true;             // ������
		inline bool IsOfficeOrganizer = true;    // �칫�����ɺ�
		inline bool IsHudsonClothes = true;      // ����ɭ�·�
		inline bool IsPremiumStorageBox = true;  // �߼�������
		inline bool IsExpressBox = true;         // �����
		inline bool IsSmallSafe = true;          // С������
		inline bool IsHikingBackpack = true;     // ��ɽ��
		inline bool IsCementTruck = true;        // ˮ�೵
		inline bool IsMedicalKit = true;         // ҽ�ư�
		inline bool IsHiddenStash = true;        // ������
		inline bool IsLowGradeLocker = true;     // �ͼ����˴�����

		inline bool BaoXianGUI = true;
		inline bool IsHackerComputer = true;

		inline bool IsSuitcase = true;               // ������
		inline bool IsBlackTideWeaponCase = true;     // ��ɫ��ϫ������
		inline bool IsFieldSupplyBox = true;          // Ұ��ս����
		inline bool IsLargeToolBox = true;            // �󹤾ߺ�
		inline bool IsDianNaoBao = true;
		inline bool IsShouNahe = true;

		inline bool DrawDeadBox = true;

		inline int Gradevalves = 2;
	}
}
