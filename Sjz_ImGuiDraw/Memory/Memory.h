#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include"Driver.h"
#include<Windows.h>


class Memory
{
private:
	static HANDLE m_hProcess;
public:
	static bool init();
	static DWORD m_pid;
	static ULONG64 GetMouduleBaseAddr();


	template <typename DataType> 
	static DataType Read(ULONG64 address)
	{
		DataType pBuffer;
		BOOL Result = Drv_ReadMemory(m_pid, address, &pBuffer, sizeof(DataType));
		if (!Result)
		{
			return DataType();
		}
		return pBuffer;
	}

	template<typename T>
	static T MultistageAddress(ULONG64 initialAddress, const std::vector<T>& shifting)
	{
		ULONG64 value = initialAddress;

		for (size_t i = 0; i < shifting.size() - 1; ++i) {
			ULONG64 newAddress = static_cast<ULONG64>(value) + static_cast<ULONG64>(shifting[i]);
			value = Read<ULONG64>(newAddress);
		}
		return value + shifting.back();
	}







};
inline uint64_t g_Game_Module = 0;
inline Memory TargetProcess;
#endif

