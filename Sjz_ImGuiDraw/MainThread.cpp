
#include"MainThread.h"
//δ֪
#include"Utils/Utils.hpp"
#include"Constants.h"
#include"Memory/Memory.h"
//δ֪
#include"MenuConfigs.hpp"
#include"Utils/VectorHelper.h"
#include"AimBot/AimBot.h"
struct SF_int3
{
	int a; int b; int c;
	SF_int3() {
		a = b = c = 0;
	}
};
char DecULevelFunction[64] = { 0x90, 0x90, 0xCC };
uint64_t DecFuncCall(uint64_t object_ptr, uint64_t func_param, uint64_t func_off) {

	bool open = false;
	if (open == false) {
		return (Memory::Read<uint64_t>(object_ptr) >> 4) & 0xFFFFFFFFFFFFFFFLL;
	}

	return  Memory::Read<uint64_t>(object_ptr);
}
uint64_t GetPOVPtr(uint64_t PlayerCamera) {
	const uint64_t offset1 = OFFSET_PlayerCamera_offset;
	const int64_t multiplier = OFFSET_PlayerCamera_Mul;
	uint32_t flag = Memory::Read<uint32_t>(g_Game_Module + OFFSET_PlayerCamera_Open);
	SF_int3 sf_int3 = Memory::Read<SF_int3>(g_Game_Module + OFFSET_PlayerCamera_Param);
	uint32_t var_B4 = sf_int3.a;
	uint32_t var_B8 = sf_int3.b;
	uint32_t switch_case = sf_int3.c;

	if (!flag) {
		return PlayerCamera + OFFSET_PlayerCamera_Core;
	}

	using CalcFunc = uint64_t(*)(uint64_t, int64_t, uint64_t, uint32_t, uint32_t);
	static const CalcFunc calcTable[] = {
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 + b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 ^ (b4 + b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 ^ (b4 - b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + (b4 ^ b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 + (b4 ^ b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 - b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 * (b8 + b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + b8 * (b4 - 1)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * ((b4 + b8) ^ (b4 * b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 ^ (b4 - b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + b8 * b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 * (b4 + b8 * b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * b8 + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (2 * b4 - b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + b8 * (1 - b4)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 ^ (b4 * b4)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 ^ (b4 + b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 + b4 * b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 - b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 + (b4 ^ b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 - (b4 ^ b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b8 + 1) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 ^ (b4 + b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 ^ b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 * (1 - b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + 2 * b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b8 - b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 + b8 * b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 * (b4 ^ b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 + b4) * (b4 - b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 ^ (b4 * b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 ^ (b8 + b4)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 * b8 + 1) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * b8 * (b8 + 1) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 - b8 * b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (2 * b4 - b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 - b4 * b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b8 - b4 * b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 * (b8 + b4 * b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + (b4 ^ b8)) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 + b8) * (b8 - b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 ^ b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b8 * (b4 * b4 + 1) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b4 - b4 * b8 * b8) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * (b8 + b4 * b8 - b4) + o; },
		[](uint64_t pc, int64_t m, uint64_t o, uint32_t b4, uint32_t b8) { return pc + m * b4 * (b4 * b8 + 1) + o; }
	};

	if (switch_case < sizeof(calcTable) / sizeof(calcTable[0])) {
		return calcTable[switch_case](PlayerCamera, multiplier, offset1, var_B4, var_B8);
	}
	else {
		return PlayerCamera + offset1;
	}
}
#include <cstdio>  // ȷ������printf�����ͷ�ļ�





void MainThread::UpdataGlobalData()
{
	while (true)
	{
		uint64_t UWorld = Memory::Read<uint64_t>(g_Game_Module + Offsets::UWorld);
		printf("UWorld: 0x%llX\n", UWorld);  // ��ӡUWorld

		if (!Utils::ValidPtr(UWorld))
		{
			Utils::Log(3, U8("UpdataGlobalData...."));
			GlobalData::PlayMode = EDFMGamePlayMode::GamePlayMode_SafeHouse;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;
		}

		uint64_t PersistentLevel = DecFuncCall(UWorld + Offsets::PersistentLevel, OFFSET_FuncEnc_Param, OFFSET_Ulevel_Func);
		printf("PersistentLevel: 0x%llX\n", PersistentLevel);  // ��ӡPersistentLevel

		uint64_t ActorsPtr_A = Memory::Read<uint64_t>(PersistentLevel + Offsets::AActors);
		printf("ActorsPtr_A: 0x%llX\n", ActorsPtr_A);  // ��ӡActorsPtr_A

		if (ActorsPtr_A > 0x7FFFFFF00000)
		{
			GlobalData::Encrypted = true;
		}
		else
		{
			GlobalData::Encrypted = false;
		}
		printf("GlobalData::Encrypted: %s\n", GlobalData::Encrypted ? "true" : "false");  // ��ӡ����״̬

		uint64_t GameState = DecFuncCall(UWorld + Offsets::GameState, OFFSET_FuncEnc_Param, OFFSET_GameState_Func);
		printf("GameState: 0x%llX\n", GameState);  // ��ӡGameState

		EDFMGamePlayMode playMode = Memory::Read<EDFMGamePlayMode>(GameState + Offsets::DFMGamePlayerMode);
		GlobalData::PlayMode = playMode;
		printf("GlobalData::PlayMode: %d\n", static_cast<int>(GlobalData::PlayMode));  // ��ӡ��Ϸģʽ

		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("UpdataGlobalData.... "));
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;
		}

		uint64_t UGameInstance = DecFuncCall(UWorld + Offsets::UGameInstance, OFFSET_FuncEnc_Param, OFFSET_GameInstance_Func);
		printf("UGameInstance: 0x%llX\n", UGameInstance);  // ��ӡUGameInstance

		uint64_t LocalPlayer = Memory::Read<uint64_t>(UGameInstance + Offsets::LocalPlayers);
		printf("LocalPlayer (after first read): 0x%llX\n", LocalPlayer);  // ��ӡ��һ�ζ�ȡ��LocalPlayer

		LocalPlayer = Memory::Read<uint64_t>(LocalPlayer + 0);
		printf("LocalPlayer (after second read): 0x%llX\n", LocalPlayer);  // ��ӡ�ڶ��ζ�ȡ��LocalPlayer

		uint64_t PlayerController = Memory::Read<uint64_t>(LocalPlayer + Offsets::PlayerController);
		printf("PlayerController: 0x%llX\n", PlayerController);  // ��ӡPlayerController

		uint64_t PlayerCameraManager = DecFuncCall(PlayerController + OFFSET_PlayerCameraManager, OFFSET_FuncEnc_Param, OFFSET_PlayerCamera_Func);
		printf("PlayerCameraManager: 0x%llX\n", PlayerCameraManager);  // ��ӡPlayerCameraManager

		


		uint64_t Pawn = DecFuncCall(PlayerController + Offsets::AcknowledgedPawn, OFFSET_FuncEnc_Param, OFFSET_LocalPawn_Func);
		printf("Pawn: 0x%llX\n", Pawn);  // ��ӡPawn

		uint64_t UnetDriver = Memory::Read<uintptr_t>(UWorld + Offsets::NetDriver);
		printf("UnetDriver: 0x%llX\n", UnetDriver);  // ��ӡUnetDriver

		uint64_t PlayerState = Memory::Read<uint64_t>(Pawn + Offsets::PlayerState);
		printf("PlayerState: 0x%llX\n", PlayerState);  // ��ӡPlayerState

		int32_t teamId = 0;
		int32_t CampId = 0;
		CampId = Memory::Read<uint32_t>(PlayerState + Offsets::campId);
		teamId = Memory::Read<uint32_t>(PlayerState + Offsets::teamId);
		printf("CampId: %d\n", CampId);  // ��ӡCampId
		printf("teamId: %d\n", teamId);  // ��ӡteamId

		// ���Ƶ�ȫ������
		LocalData::LocalPlayerPawn = Pawn;
		LocalData::PlayerContoller = PlayerController;
		LocalData::PlayerCameraManager = PlayerCameraManager;
		LocalData::TeamId = teamId;
		LocalData::CampId = CampId;
		LocalData::PlayerState = PlayerState;
		GlobalData::UWorld = UWorld;
		LocalData::UnetDriver = UnetDriver;

		// ��ӡȫ������
		printf("LocalData::LocalPlayerPawn: 0x%llX\n", LocalData::LocalPlayerPawn);
		printf("LocalData::PlayerContoller: 0x%llX\n", LocalData::PlayerContoller);
		printf("LocalData::PlayerCameraManager: 0x%llX\n", LocalData::PlayerCameraManager);
		printf("LocalData::TeamId: %d\n", LocalData::TeamId);
		printf("LocalData::CampId: %d\n", LocalData::CampId);
		printf("LocalData::PlayerState: 0x%llX\n", LocalData::PlayerState);
		printf("GlobalData::UWorld: 0x%llX\n", GlobalData::UWorld);
		printf("LocalData::UnetDriver: 0x%llX\n", LocalData::UnetDriver);

		std::this_thread::sleep_for(std::chrono::milliseconds(300));
	}
}
void MainThread::UpdataActorsData()
{
	printf("=== ����UpdataActorsData��ѭ�� ===\n");
	while (true)
	{
		// ��ӡѭ����ʼʱ��������ڷ���ִ��Ƶ��
		auto now = std::chrono::system_clock::now();
		auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
		printf("\n[ѭ����ʼ] ʱ���: %lldms\n", timestamp);

		// �����ǰ��Ϸģʽ
		printf("��ǰ��Ϸģʽ: %d (��ȫ��ģʽ: %d)\n",
			static_cast<int>(GlobalData::PlayMode),
			static_cast<int>(EDFMGamePlayMode::GamePlayMode_SafeHouse));

		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("UpdataActorsData...."));
			printf("����ȫ��ģʽ������ReflashData()������2000ms\n");
			ReflashData();
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;
		}

		// ��ʼ�����沢���״̬
		std::unordered_map<uint64_t, Player> CachePlayers;
		std::unordered_map<uint64_t, Item> CacheItems;
		printf("����Ϸģʽ����ʼ������ - ׼����ȡ��ɫ����\n");

		// ��ȡUWorld��ULevels��Ϣ
		uint64_t Uworld = GlobalData::UWorld;
		printf("UWorld��ַ: 0x%llX\n", Uworld);

		TArray<uint64_t> ULevels = Memory::Read<TArray<uint64_t>>(Uworld + Offsets::ULevels);
		printf("��ȡULevels - ����: %d, ���ݵ�ַ: 0x%llX\n",
			ULevels.Count);

		// ���ULevels��Ч��
		if (ULevels.Count <= 0 || !Utils::ValidPtr(ULevels.Data))
		{
			printf("�����桿ULevels��Ч��Ϊ�գ�����2000ms\n");
			Utils::Log(3, "UpdataActorsData....");
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;
		}

		// ��ȡNetActors_1
		TArray<uint64_t> NetActors_1 = Memory::Read<TArray<uint64_t>>(LocalData::UnetDriver + Offsets::decActors);
		printf("��ȡNetActors_1 - ����: %d, ���ݵ�ַ: 0x%llX\n",
			NetActors_1.Count
			);

		// ����ULevels
		printf("��ʼ����ULevels (��%d��Level)\n", ULevels.Count);
		for (size_t i = 0; i < ULevels.Count; i++)
		{
			printf("\n--- �����%d��Level ---\n", i);
			uint64_t Level = Memory::Read<uint64_t>(ULevels.Data + i * 8);
			printf("Level��ַ: 0x%llX\n", Level);

			uint64_t AActor = Memory::Read<uint64_t>(Level + Offsets::AActors);
			uint32_t AActorCount = Memory::Read<uint32_t>(Level + (Offsets::AActors + 0x8));
			printf("AActors��ַ: 0x%llX, ����: %d\n", AActor, AActorCount);

			// ���Actor�����Ƿ񳬹�����
			if (AActorCount > 5000)
			{
				printf("�����桿AActorCount(%d)����5000������ѭ��\n", AActorCount);
				break;
			}

			// ȷ��ʵ��Ҫ���������
			uint32_t Count = GlobalData::Encrypted ? NetActors_1.Count : AActorCount;
			printf("ʹ�ü���ģʽ: %s, ʵ�ʴ�������: %d\n",
				GlobalData::Encrypted ? "��" : "��",
				Count);

			// ����Actors
			for (size_t i = 0; i < Count; i++)
			{
				if (Count <= 0)
				{
					printf("��������CountΪ0��������ǰѭ��\n");
					continue;
				}

				// ����Actorsָ��
				size_t offset = i * (GlobalData::Encrypted ? 0x10 : 0x8);
				uintptr_t basePtr = GlobalData::Encrypted ? NetActors_1.Data : AActor;
				uintptr_t ActorsPtr = Memory::Read<uintptr_t>(basePtr + offset);
				printf("\n�����%d��Actor - ָ���ַ: 0x%llX (ƫ��: 0x%llX)\n",
					i, ActorsPtr, offset);

				if (!Utils::ValidPtr(ActorsPtr))
				{
					printf("����Чָ�롿ActorsPtr(0x%llX)��Ч������\n", ActorsPtr);
					continue;
				}

				// ��ȡBaseAddress
				uintptr_t BaseAddress = GlobalData::Encrypted
					? Memory::Read<uintptr_t>(ActorsPtr + 0x58)
					: ActorsPtr;
				printf("BaseAddress: 0x%llX (��Դ: %s)\n",
					BaseAddress,
					GlobalData::Encrypted ? "ActorsPtr + 0x58" : "ֱ��ʹ��ActorsPtr");
				
				if (!Utils::ValidPtr(BaseAddress))
				{
					printf("����Чָ�롿BaseAddress(0x%llX)��Ч������\n", BaseAddress);
					continue;
				}

				// ����Actorʵ��
				uintptr_t Actorsptr = BaseAddress;
				std::vector<ActorEntity> ActorEntityVec{};

				uint64_t entity = Actorsptr;
				if (!Utils::ValidPtr(entity))
				{
					printf("����Чָ�롿entity(0x%llX)��Ч������\n", entity);
					continue;
				}

				// ��ӵ�ʵ���б�
				ActorEntity actorEntity;
				actorEntity.Entity = entity;
				actorEntity.FNameId = 0;
				ActorEntityVec.emplace_back(actorEntity);
				printf("���ʵ�嵽�б� - Entity: 0x%llX\n", entity);

				// ��ȡFNameId
				for (auto& actor : ActorEntityVec)
				{
					auto Class = Memory::Read<uintptr_t>(actor.Entity + 0x8);
					
					if (Class <= 0)
						continue;

					auto ClassID = Memory::Read<uint32_t>(actor.Entity + Offsets::NameId);

					if (ClassID <= 0)
						continue;


					actor.FNameId =  ClassID;

					printf("��ȡFNameId - Entity: 0x%llX, FNameId: %u\n",actor.Entity, actor.FNameId);
				}

				// ����ÿ��Actor
				for (auto& actor : ActorEntityVec)
				{
					std::string className = Engine::GetName(actor.FNameId);
					ECharacterTypeInfo typeInfo = FindEntityTypeInfo(className);
					ECharacterType type = typeInfo.ActorType;

					printf("\n===== ����Actor =====\n");
					printf("Entity��ַ: 0x%llX\n", actor.Entity);
					printf("FNameId: %u, ����: %s\n", actor.FNameId, className.c_str());
					printf("��ɫ����: %d (typeInfo.ActorType)\n", static_cast<int>(type));

					// ���ദ�����/����
					if (type >= ECharacterType::Player && type <= ECharacterType::Animal)
					{
						printf("�����ࡿ���/�������� (type: %d)\n", static_cast<int>(type));
						Player player{};
						player.Entity = actor.Entity;
						player.FNameId = actor.FNameId;
						player.playerType = type;
						player.playerTypeInfo = typeInfo;
						player.ClassName = className;

						CachePlayers[actor.Entity] = player;
						printf("����ӵ�CachePlayers - ��ǰ��������: %zu\n", CachePlayers.size());
					}
					// ���ദ����Ʒ/��
					else if (type >= ECharacterType::Item && type <= ECharacterType::Door)
					{
						printf("�����ࡿ��Ʒ/������ (type: %d)\n", static_cast<int>(type));
						Item item{};
						item.Entity = actor.Entity;
						item.FNameId = actor.FNameId;
						item.itemType = type;
						item.ClassName = className;

						// ������������
						if (item.itemType == ECharacterType::Interactor)
						{
							int start = 0, end = 0, flag = 0;
							for (size_t j = item.ClassName.size(); j > 0; j--)
							{
								if (item.ClassName[j] == '-')
									flag = 1;
								if (flag && item.ClassName[j] == '_')
								{
									if (end == 0)
										end = j;
									else
									{
										start = j;
										break;
									}
								}
							}

							item.InteractorName = flag ? item.ClassName.substr(start + 1, end - start - 1) : "���չ�";
							item.InterInfo = getItemInfo(item.InteractorName);

							// ���������ж�
							if (item.ClassName.find("BP_Interact_Computer_C") != std::string::npos)
							{
								item.InteractorName = "���͵���";
								item.IsComputer = true;
								printf("��������Ʒ��ʶ��Ϊ���͵���\n");
							}
							else if (item.ClassName.find("BP_Interactor_Container_SafeBox_C") != std::string::npos)
							{
								item.InteractorName = "���չ�";
								item.isBaoXian = true;
								printf("��������Ʒ��ʶ��Ϊ���չ�\n");
							}
							printf("����������: %s\n", item.InteractorName.c_str());
						}

						CacheItems[actor.Entity] = item;
						printf("����ӵ�CacheItems - ��ǰ��������: %zu\n", CacheItems.size());
					}
					else
					{
						printf("�����ࡿδʶ������ (type: %d)\n", static_cast<int>(type));
					}
				}
			}
		}

		// ����ȫ������
		printf("\n=== ѭ������ ===\n");
		printf("����CachePlayers����: %zu, CacheItems����: %zu\n",
			CachePlayers.size(), CacheItems.size());

		GlobalData::SetCachePlayers(CachePlayers);
		GlobalData::SetCacheItems(CacheItems);
		printf("�Ѹ���ȫ�ֻ������ݣ�����88ms\n");
		printf("=========================================\n");

		std::this_thread::sleep_for(std::chrono::milliseconds(88));
	}
}
void MainThread::UpdataPlayersData()
{
	while (true)
	{




		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("->UpdataPlayersData...."));

			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			ReflashData();
			continue;

		}
		//��ȡ��������
		std::unordered_map<uint64_t, Player>CachePlayers = GlobalData::GetCachePlayers();


		if (CachePlayers.size() <= 0)
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			continue;
		}

		for (auto& entry : CachePlayers)
		{
			Player& player = entry.second;

			//�Ǳ���
			if (player.Entity == LocalData::LocalPlayerPawn)
			{
				player.IsMe = true;
				continue;
			}

			player.RootComponent = DecFuncCall(player.Entity + Offsets::RootComponent, OFFSET_FuncEnc_Param, OFFSET_RootComponent_Func);//Memory::Read<uint64_t>(player.Entity + Offsets::RootComponent);

			player.MeshComponent = Memory::Read<uint64_t>(player.Entity + Offsets::Mesh);



			player.PlayerState = Memory::Read<uint64_t>(player.Entity + Offsets::PlayerState);
			player.HealthComp = Memory::Read<uint64_t>(player.Entity + Offsets::HealthComp);
			player.UCharacterEquipComponent = DecFuncCall(player.Entity + Offsets::UCharacterEquipComponent, 0, 0);
			player.CacheCurWeapon = Memory::Read<uint64_t>(player.Entity + Offsets::CacheCurWeapon);



		}


		for (auto& entry : CachePlayers)
		{
			Player& player = entry.second;


			player.WeaponID = -1;

			player.WeaponID = Memory::Read<uint16_t>(player.CacheCurWeapon + Offsets::WeaponID);
			player.WeaponID1 = Memory::Read<uint64_t>(player.CacheCurWeapon + Offsets::WeaponID1);




			if (Utils::ValidPtr(player.UCharacterEquipComponent))
			{
				player.EquipmentInfoArray = Memory::Read<uint64_t>(player.UCharacterEquipComponent + Offsets::EquipmentInfoArray);
				player.EquipmentInfoArray_Count = Memory::Read<uint32_t>(player.UCharacterEquipComponent + Offsets::EquipmentInfoArray + 0x8);
			}


			player.Location = Memory::Read<FVector>(player.RootComponent + Offsets::RelativeLocation);
			player.Pitch = Memory::Read<float>(player.RootComponent + Offsets::Pitch);


			if (!Utils::ValidPtr(player.PlayerState))
			{

				continue;
			}

			player.isDead = Memory::Read<BYTE>(player.PlayerState + Offsets::bDead);

			player.campId = Memory::Read<int32>(player.PlayerState + Offsets::campId);
			player.teamId = Memory::Read<int32>(player.PlayerState + Offsets::teamId);

			
			player.pCharacterName = Memory::Read<uint64_t>(player.PlayerState + Offsets::PlayerNamePrivate);
			player.HeroId = Memory::Read<int16_t>(player.PlayerState + Offsets::HeroId);
			player.ExitState = Memory::Read<BYTE>(player.PlayerState + Offsets::ExitState);


		}


		//����Ѫ������ ǹе ��������                             
		for (auto& entry : CachePlayers)
		{
			Player& player = entry.second;
			player.HealthSet = Memory::Read<uint64_t>(player.HealthComp + Offsets::HealthSet);
			//��������
			player.ComponentToWorld = Memory::Read<FTransform>(player.MeshComponent + Offsets::ComponentToWorld);
			player.StaticMeshTemp = Memory::Read<uint64_t>(player.MeshComponent + Offsets::StaticMesh);

			player.StaticMeshTemp1 = Memory::Read<uint64_t>(player.MeshComponent + Offsets::StaticMeshCache);
			player.IsViews = Engine::Getinvisible(player.MeshComponent);//�Ƿ���� BUG


			//����ͷ��
			if (player.EquipmentInfoArray_Count > 0 && player.EquipmentInfoArray_Count < 99)
			{
				player.ArmorID = Memory::Read<uint64_t>(player.EquipmentInfoArray + Offsets::ArmorLevel);

				player.ArmorHp = Memory::Read<float>(player.EquipmentInfoArray + Offsets::ArmorHp);

				player.HelmetArmorId = Memory::Read<uint64_t>(player.EquipmentInfoArray + Offsets::HelmetArmorLevel);
				player.HelmetArmorHp = Memory::Read<float>(player.EquipmentInfoArray + Offsets::HelmetArmorHp);

			}

			//��������
			auto it = WeaponIndexMap.find(player.WeaponID1);
			std::string WeaponName = "";
			if (it != WeaponIndexMap.end())
			{
				WeaponName = it->second;

			}
			else
			{
				WeaponName = "δ֪����";
			}
			player.weaponName = WeaponName;
			player.CurrentHealthValue = Memory::Read<float>(player.HealthSet + Offsets::Health);
			player.MaxHealth = Memory::Read<float>(player.HealthSet + Offsets::MaxHealth);
			player.IsAlive = Memory::Read<float>(player.HealthSet + Offsets::IsAlive);


			if (player.playerTypeInfo.ActorType >= ECharacterType::AI && player.playerTypeInfo.ActorType <= ECharacterType::Animal)
			{
				player.isPlayerAi = true;
			}
			else
			{
				player.isPlayerAi = false;
			}



			if (player.isPlayerAi)
			{

				player.IsMyTeam = false;
				player.isMycamp = false;

			}
			else
			{
				//��������


				player.CharacterName = Memory::Read<FText>(player.pCharacterName);
			}



			//����Ӣ��Id
			auto it2 = HeroIndexMap.find(player.HeroId);
			std::string tempheroName;
			if (it2 != HeroIndexMap.end())
			{
				tempheroName = it2->second;
			}
			else
			{
				tempheroName = "δ֪";
			}
			player.heroName = tempheroName;
		}


		if (!Aimbot::Lock)
		{
			Aimbot::ScreenDistance = 1000.0f;

		}
		for (auto& entry : CachePlayers)
		{
			Player& player = entry.second;


			player.isPlayerDead = player.CurrentHealthValue <= 0;
			if (player.isPlayerDead) { continue; }

			if (player.isPlayerAi)
			{


				player.IsMyTeam = false;
				player.isMycamp = false;
			}
			else
				player.IsMyTeam = player.teamId == LocalData::TeamId;
			player.isMycamp = player.isMycamp == LocalData::CampId;




			//����ͷ��
			if (player.EquipmentInfoArray_Count > 0 && player.EquipmentInfoArray_Count < 99)
			{
				//����id��ͷ��
				auto it1 = ArmorsMap.find(player.ArmorID);
				auto it2 = ArmorsMap.find(player.HelmetArmorId);
				if (it1 != ArmorsMap.end())
				{
					player.ArmorLevel = it1->second.Grade;
				}
				else
				{
					player.ArmorLevel = 0;
					player.ArmorHp = 0;
				}
				if (it2 != ArmorsMap.end())
				{
					player.HelmeArmorLevel = it2->second.Grade;
				}
				else
				{
					player.HelmeArmorLevel = 0;
					player.HelmetArmorHp = 0;
				}
			}


			player.isPlayerDead = player.CurrentHealthValue <= 0;
			if (player.isPlayerAi)
			{
				player.IsMyTeam = false;
				player.isMycamp = false;
			}
			else
				player.IsMyTeam = player.teamId == LocalData::TeamId;
			player.isMycamp = player.campId == LocalData::CampId;

			//�ж��Ƿ�����Ļ
			FVector2D screen = VectorHelper::WorldToScreen(player.Location);

			player.InScreen = VectorHelper::IsInScreen(screen);

			if (!player.InScreen || player.IsMe || player.isPlayerDead || player.ExitState == 3)
			{
				continue;
			}
			if (Configs::Aimbot::ModIndex == 0) {

				if (player.isMycamp)
				{
					continue;
				}

			}
			else {

				if (player.IsMyTeam)
				{
					continue;
				}
			}

			//��������
			if (!player.isPlayerAi)
			{
				player.playerName = Utils::RemoveBracketsAndTrim(Utils::UnicodeToAnsi(player.CharacterName.buffer));

			}


			//�������
			player.Distance = LocalData::LocalCameraData.Location.Distance(player.Location) / 100.f;


		

			//player.StaticMesh = player.StaticMeshTemp1;



			//�����������
			for (BoneIndex Bone : SkeletonLists::Bones)
			{

				int BoneIndex = Bone;
				uintptr_t BaseAddr = (player.StaticMesh == NULL)
					? player.StaticMeshTemp1
					: player.StaticMesh;

				player.Skeleton.Bones[Bone] = Memory::Read<FTransform>(BaseAddr + BoneIndex * 0x30);


			}






		}

		for (auto& entry : CachePlayers)

		{
			Player& player = entry.second;

			for (BoneIndex Bone : SkeletonLists::Bones)
			{

				int BoneIndex = Bone;
				uintptr_t BaseAddr = (player.StaticMesh == NULL)
					? player.StaticMeshTemp1
					: player.StaticMesh;

				player.Skeleton.Bones[Bone] = Memory::Read<FTransform>(BaseAddr + BoneIndex * 0x30);



			}

		}
		for (auto& entry : CachePlayers)
		{
			Player& player = entry.second;

			if (!Aimbot::Lock || ValidPtr(Aimbot::Target))
			{
				FTransform checkTransform = player.Skeleton.Bones[BoneIndex::Head];


				FVector checkPos = VectorHelper::GetBoneWithRotation(checkTransform, player.ComponentToWorld);
				FVector2D checkScreen = VectorHelper::WorldToScreen(checkPos);


				float  dis = Utils::CalculateDistance(Dx11Data::ScreenWidth / 2.f, Dx11Data::ScreenHeight / 2.f, checkScreen.X, checkScreen.Y);

				if (dis < Aimbot::ScreenDistance && dis < Configs::Aimbot::Fovsize)
				{
					Aimbot::ScreenDistance = dis;

					Aimbot::TempObject = player.Entity;



				}

			}
		}
		Aimbot::Target = Aimbot::TempObject;
		GlobalData::SetPlayers(CachePlayers);
	}
}
void MainThread::UpdataLocalCameraData()
{

	while (true)
	{
		// �����ǰѭ����ʼ��Ϣ������ʱ������ڷ���ִ��Ƶ��
		printf("[ѭ����ʼ] ʱ���: %lld\n", std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now().time_since_epoch()).count());

		// �����ǰ��Ϸģʽ
		printf("��ǰ��Ϸģʽ: %d (��ȫ��ģʽ: %d)\n",
			static_cast<int>(GlobalData::PlayMode),
			static_cast<int>(EDFMGamePlayMode::GamePlayMode_SafeHouse));

		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("->UpdataLocalCameraData...."));
			printf("���밲ȫ��ģʽ - ����ReflashData()\n");

			ReflashData();

			printf("��ȫ��ģʽ - ����2000ms\n");
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;
		}

		printf("������Ϸģʽ - ��ʼ�����������\n");

		// ���PlayerCameraManagerԭʼ��ַ
		printf("LocalData::PlayerCameraManager ��ַ: 0x%llX\n",
			LocalData::PlayerCameraManager);

		uint64_t PlayerCameraManager = LocalData::PlayerCameraManager;
		
		CameraData camera;

		camera = Memory::Read<CameraData>(PlayerCameraManager + OFFSET_FMinimalViewInfo);
		printf("��ȡ��������� - ��С: %zu�ֽ�\n", sizeof(camera));

		 //���λ����Ϣ
		FVector location = camera.Location;
		printf("���λ��: X=%.2f, Y=%.2f, Z=%.2f\n",
			location.X, location.Y, location.Z);

		// ������ݸ�����Ϣ
		LocalData::LocalCameraData = camera;
		printf("�Ѹ���LocalData::LocalCameraData\n");

		// ѭ���ָ��ߣ��������ֲ�ͬѭ������
		printf("-----------------------------------------\n");

		// �ɸ�����Ҫ��Ӷ���ʱ�������������
		// std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
void MainThread::UpdataItemsData()
{

	while (true)
	{
		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("->UpdataItemsData...."));
			ReflashData();
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;

		}

		//��ȡ��������
		std::unordered_map<uint64_t, Item>CacheItems = GlobalData::GetCacheItems();
		if (CacheItems.size() <= 0)
		{

			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			continue;
		}



		for (auto& entry : CacheItems)
		{
			Item& item = entry.second;


			item.RootComponent = DecFuncCall(item.Entity + Offsets::RootComponent, OFFSET_FuncEnc_Param, OFFSET_RootComponent_Func);//Memory::Read<uint64>(item.Entity + Offsets::RootComponent);
			if (item.itemType == ECharacterType::Item)
			{
				item.AttachInfo = Memory::Read<uint64>(item.Entity + Offsets::PickupItemInfo + Offsets::PickupItemSize);
			}
			else if (item.itemType == ECharacterType::Interactor)
			{
				item.InteractorPackPtr = Memory::Read<uint64>(item.Entity + Offsets::RepItemArray + Offsets::Items);

				item.InteractorCount = Memory::Read<uint64>(item.Entity + Offsets::RepItemArray + Offsets::Items + 8);
			}
			else if (item.itemType == ECharacterType::DeadBox)
			{
				item.DeadBoxPackPtr = Memory::Read<uint64>(item.Entity + Offsets::RepItemArray + Offsets::Items);

				item.DeadBoxCount = Memory::Read<int32>(item.Entity + Offsets::RepItemArray + Offsets::Items + 8);

				item.CurrentyGid = Memory::Read<uint8_t>(item.Entity + Offsets::CurrencyGID);

			}
		}




		for (auto& entry : CacheItems)
		{
			Item& item = entry.second;

			item.Location = Memory::Read<FVector>(item.RootComponent + Offsets::ComponentLocation);


			if (item.itemType == ECharacterType::Interactor && item.InteractorCount > 0 && item.InteractorCount < 99)
			{


				item.InteractorPawnList.resize(item.InteractorCount);
				item.InteractorPawnItemIDList.resize(item.InteractorCount);

				for (size_t j = 0; j < item.InteractorCount; j++)
				{

					item.InteractorPawnList[j] = Memory::Read<uint64_t>(item.InteractorPackPtr +
						Offsets::PickupItemSize + j * Offsets::SizeOfFInventoryItemInfo);


				}

			}


			else if (item.itemType == ECharacterType::DeadBox && item.DeadBoxCount > 0 && item.DeadBoxCount < 99)
			{
				item.DeadBoxPawnList.resize(item.DeadBoxCount);
				item.DeadBoxPawnItemIDList.resize(item.DeadBoxCount);

				for (size_t j = 0; j < item.DeadBoxCount; j++)
				{


					item.DeadBoxPawnList[j] = Memory::Read<uint64_t>(item.DeadBoxPackPtr + Offsets::PickupItemSize + j * Offsets::SizeOfFInventoryItemInfo);

				}

			}


		}



		for (auto& entry : CacheItems)
		{
			Item& item = entry.second;

			if (item.itemType == ECharacterType::Item)
			{

				item.itemID = Memory::Read<uint64_t>(item.AttachInfo + Offsets::ItemID);
				printf("item.AttachInfo:%llX\n", item.AttachInfo);
			}
			else if (item.itemType == ECharacterType::Interactor)
			{
				item.isOpened = Memory::Read<char>(item.Entity + Offsets::bHasOpened);


				if (item.IsComputer)
				{
					item.ComputerPwd = Memory::Read<int>(item.Entity + Offsets::computerPassWord);

				}

				if (item.InteractorCount > 0 && item.InteractorCount < 99)
				{
					for (int i = 0; i < item.InteractorCount; i++)
					{
						item.InteractorPawnItemIDList[i] = Memory::Read<uint64_t>(item.InteractorPawnList[i] + Offsets::ItemID);




					}

				}


			}


			else if (item.itemType == ECharacterType::DeadBox)
			{



				if (item.DeadBoxCount > 0 && item.DeadBoxCount < 99)
				{
					for (int i = 0; i < item.DeadBoxCount; i++)
					{
						item.DeadBoxPawnItemIDList[i] = Memory::Read<uint64_t>(item.DeadBoxPawnList[i] + Offsets::ItemID);

					}

				}


			}
			else if (item.itemType == ECharacterType::Exit)
			{


				item.ExitState = Memory::Read<char>(item.Entity + Offsets::bExitActive);


			}
			else if (item.itemType == ECharacterType::Door)
			{

				item.DoorPwd = Memory::Read<int>(item.Entity + Offsets::PwdSum);

			}


		}



		//ͳһ������ItemId
		for (auto& entry : CacheItems)
		{
			Item& item = entry.second;
			uint64_t Temp = 0;
			if (item.itemType == ECharacterType::Item)
			{

				std::string TempID = Engine::GetName(item.itemID);

				uint64_t temp;
				Utils::safeStringToUint64(TempID, temp);
				item.itemID = temp;
				DisPlayItem itemData;
				auto It = g_items.find(item.itemID);
				if (It != g_items.end()) {
					itemData = It->second;
					item.disPlayItem = itemData;

				}

				switch (Configs::Aimbot::ValueIndex)
				{
				case 0:  // ����0
					Configs::Item::Gradevalves = 2;
					break;
				case 1:  // ����1
					Configs::Item::Gradevalves = 3;
					break;
				case 2:  // ����2
					Configs::Item::Gradevalves = 4;
					break;
				case 3:  // ����3
					Configs::Item::Gradevalves = 5;
					break;
				case 4:  // ����4
					Configs::Item::Gradevalves = 6;
					break;
				default:
					break;
				}

				/*	FText shortName = Memory::Read<FText>(Memory::Read<uint64_t>(Memory::MultistageAddress<uint64_t>(item.AttachInfo, { 0x18,0x18,0x30,0x10 })));
					std::string nameStr = Utils::RemoveBracketsAndTrim(Utils::UnicodeToAnsi(shortName.buffer));
					item.disPlayItem.DisPlayName = nameStr;
					item.disPlayItem.Grade = Memory::Read <uint32_t>(item.AttachInfo + Offsets::Quality);
					item.disPlayItem.Value = Memory::Read <uint32_t>(item.AttachInfo + Offsets::InitialGuidePrice);*/


			}
			else if (item.itemType == ECharacterType::Interactor && item.InteractorCount > 0 && item.InteractorCount < 99)
			{

				for (int i = 0; i < item.InteractorPawnItemIDList.size(); i++)
				{


					uint64_t temp;

					std::string TempID = Engine::GetName(item.InteractorPawnItemIDList[i]);
					Utils::safeStringToUint64(TempID, temp);
					item.InteractorPawnItemIDList[i] = temp;
					DisPlayItem itemData;
					auto It = g_items.find(item.InteractorPawnItemIDList[i]); //��Map���У�Ѱ����������
					if (It != g_items.end()) {
						itemData = It->second;
						item.InteractorDisPlayItemList.push_back(itemData);
					}



				}


			}

			else if (item.itemType == ECharacterType::DeadBox)
			{
				for (int i = 0; i < item.DeadBoxPawnItemIDList.size(); i++)
				{

					uint64_t temp;
					std::string TempID = Engine::GetName(item.DeadBoxPawnItemIDList[i]);
					Utils::safeStringToUint64(TempID, temp);


					item.DeadBoxPawnItemIDList[i] = temp;
					DisPlayItem itemData;
					auto It = g_items.find(temp); //��Map���У�Ѱ����������
					if (It != g_items.end()) {
						itemData = It->second;
						item.DeadBoxDisPlayItemList.push_back(itemData);
					}

				}


			}



		}




		//����ȫ�ֱ���
		GlobalData::SetItems(CacheItems);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}





}
void MainThread::UpdateLocalPlayer()
{


	while (true)
	{
		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("->UpdataMapRadar...."));

			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;

		}

		uint64_t MapObjPtr = GlobalData::MapObjPtr;

		char preShouldDraw;

		Mapinfo radar;
		preShouldDraw = Memory::Read<char>(MapObjPtr + Offsets::preShouldDraw);
		radar = Memory::Read<Mapinfo>(MapObjPtr + Offsets::pa_0840);

		GlobalData::preShouldDraw = preShouldDraw;
		GlobalData::radar = radar;


	}

}

void MainThread::UpdateKeyState()
{
	while (true)
	{
		static DWORD KEYTIME = 0;
		if (GetTickCount64() - KEYTIME > 100)
		{
			if (GetAsyncKeyState(Configs::FireModeKey) & 0x8000)
			{
				Configs::isFireMode = !Configs::isFireMode;
				Configs::Player::DrawAI = !Configs::Player::DrawAI;
			}
			if (GetAsyncKeyState(Configs::EndKey) & 0x8000)
			{
				ExitProcess(0);
			}

			if (GetAsyncKeyState(Configs::ForceFreshKey) & 0x8000)
			{
				ReflashData();
			}
			//��Χ����F6
			if (GetAsyncKeyState(VK_F6) & 0x8000) {
				static bool bIsOpen = false;
				bIsOpen = !bIsOpen;

				unsigned char writebytes[] = { 0xF3, 0x0F, 0x10, 0x40, 0x3C };
				unsigned char oldbytes[] = { 0xF3, 0x0F, 0x10, 0x40, 0x48 };

				if (Drv_WriteMemory(Memory::m_pid, g_Game_Module + 0x19C8FD5, bIsOpen ? writebytes : oldbytes, sizeof(writebytes)))
					Configs::DZT = bIsOpen;
				else
					MessageBoxA(NULL, "�ڴ�д��ʧ�ܣ�������3����Զ��˳�", "����ʧ��", MB_ICONERROR | MB_OK);
			}

			HWND DFHwnd = FindWindowA("UnrealWindow", NULL);
			if (!DFHwnd)
			{
				MessageBoxA(NULL, "�Զ��˳���������", "ϵͳ��ʾ", MB_OK | MB_ICONINFORMATION);
				ExitProcess(0);
			}
			KEYTIME = GetTickCount64();

		}
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
void MainThread::RunAimBot()
{
	while (true)
	{
		//�ж��ǲ�������Ϸ
		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;

		}
		if (!ValidPtr(LocalData::LocalPlayerPawn))
		{
			Aimbot::StopAiming();
			continue;
		}

		//�жϰ���
		bool IsFirstKey = GetAsyncKeyState(Aimbot::GetAsyncKey(Configs::Aimbot::KeyIndex));

		bool isCanAim = IsFirstKey;


		uint64_t target = Aimbot::Target;
		if (!target)
		{
			Aimbot::StopAiming();
			continue;
		}


		//��ȡĿ�����
		Player player = GlobalData::GetPlayerByKey(target);
		if (player.isPlayerDead || player.IsMe)
		{
			Aimbot::StopAiming();
			continue;
		}

		if (Configs::Aimbot::ModIndex == 0) {

			if (player.isMycamp)
			{
				Aimbot::StopAiming();
				continue;
			}

		}
		else {

			if (player.IsMyTeam)
			{
				Aimbot::StopAiming();
				continue;
			}
		}

		if (!Configs::Player::DrawAI && player.isPlayerAi == true) continue;



		//��ȡ����λ��

		FTransform checkTransform = Aimbot::GetAimBoneTransForm(Configs::Aimbot::AimIndex, player);


		FVector checkPos = VectorHelper::GetBoneWithRotation(checkTransform, player.ComponentToWorld);
		if (checkPos.X == 0 || checkPos.Y == 0 || checkPos.Z == 0)
		{
			Aimbot::StopAiming();
			continue;
		}
		Aimbot::GetInstance().screenLocation = VectorHelper::WorldToScreen(checkPos);
		FVector2D Screen = Aimbot::GetInstance().screenLocation;
		if (!VectorHelper::IsInScreen(Screen)) { Aimbot::StopAiming(); continue; }

		float Distance = Utils::CalculateDistance(Dx11Data::ScreenWidth / 2.f, Dx11Data::ScreenHeight / 2.f, Aimbot::GetInstance().screenLocation.X, Aimbot::GetInstance().screenLocation.Y);
		Aimbot::GetInstance().Distance = Distance;


		if (Configs::Aimbot::DoAimbot) {

			if (isCanAim)
			{

				//�����������
				Aimbot::Lock = true;


				if (Distance < 0 || Distance > Configs::Aimbot::Fovsize) {
					Aimbot::StopAiming();
					continue;
				}


				if (Configs::Aimbot::AimModIndex == 0)
				{
					if (player.IsViews)
					{
						//FRotator rotator = Aimbot::GetAimRotation(checkPos, LocalData::LocalCameraData.Location);

						Aimbot::SetControlRotation(Screen);

					}


				}


			}
			else
			{
				Aimbot::StopAiming();
				continue;
			}
		}
		else
		{
			continue;

		}

	}
}
void MainThread::ReflashData()
{

	GlobalData::ClearCacheItems();
	GlobalData::ClearCachePlayers();
	GlobalData::ClearItems();
	GlobalData::ClearPlayers();

}
void MainThread::UpdataMapRadar()
{

	while (true)
	{
		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Utils::Log(3, U8("->UpdataMapRadar...."));
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			continue;

		}

		uintptr_t MyHUD = Memory::Read<uintptr_t>(LocalData::PlayerContoller + Offsets::MyHUD);

		if (MyHUD)
		{
			uintptr_t HUDarray = Memory::Read<uintptr_t>(MyHUD + Offsets::Controllers);

			uint32_t Count = Memory::Read<uint32_t>(MyHUD + Offsets::Controllers + 8);

			if (Count < 9900)
			{
				for (size_t i = 0; i < Count; i++)
				{
					uintptr_t Obj = Memory::Read<uintptr_t>(HUDarray + i * 8);

					if (!Obj) continue;
					uintptr_t ChildControllersArray = Memory::Read<uintptr_t>(Obj + Offsets::ChildControllers);
					uint32_t TCount = Memory::Read<uint32_t>(Obj + Offsets::ChildControllers + 8);

					if (TCount < 9900)
					{
						for (size_t j = 0; j < TCount; j++)
						{
							uintptr_t UBaseUIController = Memory::Read<uintptr_t>(ChildControllersArray + 8 * j);

							if (!UBaseUIController) continue;
							uintptr_t View = Memory::Read<uintptr_t>(UBaseUIController + Offsets::View);
							if (!View) continue;

							std::string MapFname = Engine::GetName(Memory::Read<int>(View + Offsets::NameId));
							if (MapFname.find("WBP_Map_Main_PC_C") != MapFname.npos) {
								GlobalData::MapObjPtr = View;
								continue;
							}
						}

					}

				}

			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}