#include"Engine.h"

#include"Memory/Memory.h"
#include <codecvt> 



void xor_string(char* buf, uint32_t len) {
	uint32_t length = len;
	BYTE xor_key;

	switch (length % 9) {
	case 0:
		xor_key = static_cast<BYTE>(length + (length & 0x1F) + 0x80) | 0x7F;
		break;
	case 1:
		xor_key = static_cast<BYTE>(length + (length ^ 0xDF) + 0x80) | 0x7F;
		break;
	case 2:
		xor_key = static_cast<BYTE>(length + (length | 0xCF) + 0x80) | 0x7F;
		break;
	case 3:
		xor_key = static_cast<BYTE>(33 * length + 0x80) | 0x7F;
		break;
	case 4:
		xor_key = static_cast<BYTE>(length + (length >> 2) + 0x80) | 0x7F;
		break;
	case 5:
		xor_key = static_cast<BYTE>(3 * (length - 41)) | 0x7F;
		break;
	case 6:
		xor_key = static_cast<BYTE>(length + ((4 * length) | 5) + 0x80) | 0x7F;
		break;
	case 7:
		xor_key = static_cast<BYTE>(length + ((length >> 4) | 7) + 0x80) | 0x7F;
		break;
	case 8:
		xor_key = static_cast<BYTE>(length + (length ^ 0x0C) + 0x80) | 0x7F;
		break;
	default:
		xor_key = static_cast<BYTE>(length + (length ^ 0x40) + 0x80) | 0x7F;
		break;
	}

	for (size_t i = 0; i < len; i++) {
		buf[i] ^= xor_key;
	}


}


void xor_Wstring(wchar_t* buf, uint32_t len) {
	uint32_t length = len;
	BYTE xor_key;

	switch (length % 9) {
	case 0:
		xor_key = static_cast<BYTE>(length + (length & 0x1F) + 0x80) | 0x7F;
		break;
	case 1:
		xor_key = static_cast<BYTE>(length + (length ^ 0xDF) + 0x80) | 0x7F;
		break;
	case 2:
		xor_key = static_cast<BYTE>(length + (length | 0xCF) + 0x80) | 0x7F;
		break;
	case 3:
		xor_key = static_cast<BYTE>(33 * length + 0x80) | 0x7F;
		break;
	case 4:
		xor_key = static_cast<BYTE>(length + (length >> 2) + 0x80) | 0x7F;
		break;
	case 5:
		xor_key = static_cast<BYTE>(3 * (length - 41)) | 0x7F;
		break;
	case 6:
		xor_key = static_cast<BYTE>(length + ((4 * length) | 5) + 0x80) | 0x7F;
		break;
	case 7:
		xor_key = static_cast<BYTE>(length + ((length >> 4) | 7) + 0x80) | 0x7F;
		break;
	case 8:
		xor_key = static_cast<BYTE>(length + (length ^ 0x0C) + 0x80) | 0x7F;
		break;
	default:
		xor_key = static_cast<BYTE>(length + (length ^ 0x40) + 0x80) | 0x7F;
		break;
	}

	for (size_t i = 0; i < len; i=i+2) {
		buf[i] ^= xor_key;
	}


}
std::string wstring_to_string(const std::wstring& wstr) {
	// 使用 UTF-8 编码进行转换
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
	return convert.to_bytes(wstr);
}
std::string Engine::GetName(uint32_t index)
{
	static std::unordered_map<uint32_t, std::string> idMap = {};
	//如果idMap中key存在
	if (idMap.find(index) != idMap.end())
	{
		return idMap[index];
	}

	uint32_t chunkOffset = (uint32_t)((int)(index) >> 18);
	uint32_t nameOffset = (uint32_t)index & 0x3ffff;

	uint64_t namePoolChunk = Memory::Read<uint64_t>(g_Game_Module + Offsets::GName + chunkOffset * 8 + 8) + (int)(2 * nameOffset);
	uint16_t nameEntry = Memory::Read<uint16_t>(namePoolChunk + 0);

	uint64_t len = nameEntry >> 6;
	bool wide = (nameEntry & 1) != 0;
	if (len > 0 && len < 251)
	{
		if (wide)
		{
			wchar_t name[1024];
			Drv_ReadMemory(Memory::m_pid, namePoolChunk + 2, (uint8_t*)&name, len * sizeof(wchar_t));
			name[len] = L'\0';
			xor_Wstring(name, len);
			std::wstring WnameF(name, len);
			std::string nameF = wstring_to_string(WnameF);
			
			idMap[index] = nameF;
			return nameF;
		}
		else
		{
			char name[1024];
			Drv_ReadMemory(Memory::m_pid, namePoolChunk + 2, (uint8_t*)&name, len);
		
			xor_string(name, len);

			std::string nameF(name, len);
			idMap[index] = nameF;
			return nameF;
		}
	}
	return std::string(("N/A"));

}

bool Engine::Getinvisible(uint64_t Mesh)
{
	float fvisionTick = 0.04f;
	float fLastSubmitTime = Memory::Read<float>(Mesh + Offsets::fLastSubmit);
	float fLastRenderTimeOnScreen = Memory::Read<float>(Mesh + Offsets::fLastSubmit + 0x4);

	return fLastRenderTimeOnScreen + fvisionTick >= fLastSubmitTime;
}



namespace GlobalData
{
	std::unordered_map<uint64_t, Player> GetCachePlayers()
	{
		std::shared_lock<std::shared_mutex> lock(CachePlayersMutex);
		return CachePlayers;
	}
	void SetCachePlayers(std::unordered_map<uint64_t, Player>& value)
	{
		std::unique_lock<std::shared_mutex> lock(CachePlayersMutex);

		CachePlayers.swap(value);

	}

	void ClearCachePlayers()
	{

		std::unique_lock<std::shared_mutex> lock(CachePlayersMutex);

		CachePlayers.clear();

	}




	std::unordered_map<uint64_t, Player> GetPlayers()
	{
		std::shared_lock<std::shared_mutex> lock(PlayersMutex);
		if (PlayersList.empty())
		{
			return {};
		}
		return PlayersList;
	}

	void SetPlayers(std::unordered_map<uint64_t, Player>& value)
	{
		std::unique_lock<std::shared_mutex> lock(PlayersMutex);

		PlayersList.swap(value);

	}
	void ClearPlayers()
	{
		std::unique_lock<std::shared_mutex> lock(PlayersMutex);
		PlayersList.clear();
	}

	Player GetPlayerByKey(uint64_t key)
	{
		std::shared_lock<std::shared_mutex> lock(PlayersMutex);
		if (PlayersList.empty())
		{
			return {};
		}
		return PlayersList[key];
	}

	std::unordered_map<uint64_t, Item> GetCacheItems()
	{
		std::shared_lock<std::shared_mutex> lock(CacheItemsMutex);
		if (CacheItems.empty())
		{
			return {};
		}
		return CacheItems;//直接返回结构  会拷贝大量数据 影响效率 建议用指针

	}

	void SetCacheItems(std::unordered_map<uint64_t, Item>& value)
	{

		std::unique_lock<std::shared_mutex> lock(CacheItemsMutex);
		CacheItems.swap(value);
	}
	void ClearCacheItems()
	{
		std::unique_lock<std::shared_mutex> lock(CacheItemsMutex);
		CacheItems.clear();
	}



	std::unordered_map<uint64_t, Item> GetItems()
	{
		std::shared_lock<std::shared_mutex> lock(ItemMutex);
		if (ItemsList.empty())
		{
			return {};
		}
		return ItemsList;//也可以直接去设置指针的值  不进行数据的整体拷贝

	}

	void SetItems(std::unordered_map<uint64_t, Item>& value)
	{
		std::unique_lock<std::shared_mutex> lock(ItemMutex);

		ItemsList.swap(value);


	}

	void ClearItems()
	{
		std::unique_lock<std::shared_mutex> lock(ItemMutex);
		ItemsList.clear();
	}

}