#pragma once
#include"Memory.h"
#include<winternl.h>
#include <stdio.h>
#include"../base.h"
#pragma comment(lib,"ntdll.lib")

HANDLE Memory::m_hProcess = NULL;
DWORD Memory::m_pid = 0;
bool Memory::init()
{
    char appId[] = { 98,100,52,50,97,48,48,100,48,49,99,52,52,101,50,97,57,49,56,101,52,53,51,48,100,55,48,52,49,101,50,50, };
    char cryptAppId[] = { 91,6,12,84,4,0,1,1,5,0,6,87,0,83,10,84,1,8,15,87,82,84,4,3,92,81,5,12,84,85,86,86, };
    int ret = Drv_Regist(appId, cryptAppId);
    if (ret != 1) {
        return false;
        Utils::Log(1, ("Drv_验证注册失败\r\n"));
        system("pause");
        exit(0);
    }
    ret = Drv_InitByVersion(2);
    if (ret != 1) {
        return false;
        Utils::Log(1, ("Drv_初始初始化失败\r\n"));
        system("pause");
        exit(0);
    }
    if (!Drv_IsInstall()) {
        return false;
        Utils::Log(1, ("Drv_通信失败\r\n"));
        system("pause");
        exit(0);
    }
	return true;
}
ULONG64 Memory::GetMouduleBaseAddr()
{
    ULONG64 module_size;
	ULONG64 module_adr;
    ULONG64 module_end_adr;
    module_end_adr = Drv_GetModule(m_pid, "DeltaForceClient-Win64-Shipping.exe", &module_size, &module_adr);
	printf("[X] module adr:%llx \n", module_end_adr);
	return module_end_adr;
}