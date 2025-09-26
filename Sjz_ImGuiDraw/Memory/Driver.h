#pragma once
#include <Windows.h>
#pragma comment(lib, "../x64_MT_143.lib")
#include"../base.h"
#include"Utils/Utils.hpp"
#pragma warning(disable:4996)
EXTERN_C INT WINAPI Drv_Regist(IN const char* appId, IN const char* cryptAppId);
/// <summary>
/// ������ʼ��,���������������������� ����,��ʽ���������
/// </summary>
/// <returns>����ֵ</returns>
/// ����ֵ˵����
///					-1��ϵͳ������������
///					 0����ʼ��ʧ�ܣ�һ���Ǳ�������ɱ�������
///					 1����ʼ���ɹ�
/// 				 4: ��װj����ʧ��
///					 5����װr����ʧ�� 
///					 9: û����֤����������	Drv_Regist������֤
EXTERN_C INT WINAPI Drv_Init();

/// <summary>
/// ѡ��汾��ʼ��������Drv_Init()����Drv_InitByVersion(1)Ч��
/// </summary>
/// <param name="ver">��ʼ�������汾��</param>
/// <returns>����ֵ</returns>
/// ����ֵ˵����
///					-1��ϵͳ������������
///					 0����ʼ��ʧ�ܣ�һ���Ǳ�������ɱ�������
///					 1����ʼ���ɹ�
///					 4: ��װj����ʧ��
///					 5����װr����ʧ�� 	
///					 9: û����֤����������	Drv_Regist������֤
EXTERN_C INT WINAPI Drv_InitByVersion(IN ULONG ver);


/// <summary>
/// �ж������Ƿ�װ�ɹ�
/// </summary>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_IsInstall();



/// <summary>
/// CR3����,�޸����ֱ�����CR3������û�б���CR3��Ҳ��Ҫʹ�ã��ӿ��ٶ�
/// </summary>
/// <param name="pid">����PID</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_FixCr3(IN ULONG64 pid);

/// <summary>
/// ��ȡ����ģ����Ϣ
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="moduleName">ģ������</param>
/// <param name="size">ģ���С</param>
/// <param name="entryFuncAddress">��ں�����ַ</param>
/// <returns>ģ���ַ</returns>
EXTERN_C ULONG64 WINAPI Drv_GetModule(IN ULONG64 pid, const char* moduleName, OUT PULONG64 size, OUT PULONG64 entryFuncAddress);

/// <summary>
/// ��ȡ������ģ����Ϣ
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="size">ģ���С</param>
/// <param name="entryFuncAddress">��ں�����ַ</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_GetMainModule(ULONG64 pid, OUT PULONG64 size, OUT PULONG64 entryFuncAddress);


EXTERN_C ULONG64 WINAPI Drv_GetR0Module(const char* moduleName, OUT PULONG64 size);

/// <summary>
/// ��������Ѱ
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="startAddress">��ʼ��ַ</param>
/// <param name="endAddress">������ַ</param>
/// <param name="patternCode">�����룺45*887766****E8</param>
/// <returns>������������Ѱ�ĵ�ַ</returns>
EXTERN_C ULONG64 WINAPI Drv_SearchCode(ULONG64 pid, IN ULONG64 startAddress, IN ULONG64 endAddress, const char* patternCode);

/// <summary>
/// ���ڴ棬�޸��ӣ�������������ڴ�����
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="BaseAddress">Ҫ���ڴ��ַ</param>
/// <param name="Buffer">R3����Ľ������ݵ�ַ</param>
/// <param name="size">��д���ݳ���</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ReadMemory(IN ULONG64 pid, IN ULONG64 address, IN OUT PVOID buffer, IN ULONG64 size);

/// <summary>
/// ���ڴ棬�޸��ӣ�ӳ���
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="BaseAddress">Ҫ���ڴ��ַ</param>
/// <param name="Buffer">R3����Ľ������ݵ�ַ</param>
/// <param name="size">��д���ݳ���</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ReadMemory2(IN ULONG64 pid, IN ULONG64 address, IN OUT PVOID buffer, IN ULONG64 size);



/// <summary>
/// ���ڴ棬�޸��ӣ����������֧�ֶ�̬����DTB��֧�ֶ࿪��������Drv_FixCr3������
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="BaseAddress">Ҫ���ڴ��ַ</param>
/// <param name="Buffer">R3����Ľ������ݵ�ַ</param>
/// <param name="size">��д���ݳ���</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ReadMemory3(IN ULONG64 pid, IN ULONG64 address, IN OUT PVOID buffer, IN ULONG64 size);





/// <summary>
/// д�ڴ棬�޸��ӣ�����д�������ڴ��д����
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="BaseAddress">Ҫд�����ݵ�ַ</param>
/// <param name="Buffer">R3�����д�����ݵ�ַ</param>
/// <param name="size">���ݳ���</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_WriteMemory(IN ULONG64 pid, IN ULONG64 address, IN PVOID buffer, IN ULONG64 size);


/// <summary>
/// д�ڴ棬�޸��ӣ�ӳ��д
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="BaseAddress">Ҫд�����ݵ�ַ</param>
/// <param name="Buffer">R3�����д�����ݵ�ַ</param>
/// <param name="size">���ݳ���</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_WriteMemory2(IN ULONG64 pid, IN ULONG64 address, IN PVOID buffer, IN ULONG64 size);

/// <summary>
/// д�ڴ棬�޸��ӣ�����д����֧�ֶ�̬����DTB��֧�ֶ࿪��������Drv_FixCr3������
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="BaseAddress">Ҫд�����ݵ�ַ</param>
/// <param name="Buffer">R3�����д�����ݵ�ַ</param>
/// <param name="size">���ݳ���</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_WriteMemory3(IN ULONG64 pid, IN ULONG64 address, IN PVOID buffer, IN ULONG64 size);

/// <summary>
/// Զ��������ͨ��λ�ڴ�
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="size">IN �����С,OUT ʵ�ʴ�С</param>
/// <param name="protect">�ڴ����ԣ�PAGE_EXECUTE_WRITEREAD��</param>
/// <returns>�����ַ</returns>
EXTERN_C ULONG64 WINAPI Drv_AllocaMemory(IN ULONG64 pid, IN OUT PULONG64 size, IN ULONG64 protect);



/// <summary>
/// Զ���ͷ���ͨ�ڴ�
/// </summary>
/// <param name="pid"></param>
/// <param name="BaseAddress"></param>
/// <param name="size"></param>
/// <returns></returns>
/// 
EXTERN_C BOOLEAN WINAPI Drv_FreeMemory(IN ULONG64 pid, IN ULONG64 BaseAddress, IN ULONG64 size);




/// <summary>
/// Զ�������λ�ڴ�
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="size">IN �����С,OUT ʵ�ʴ�С</param>
/// <param name="protect">�ڴ�����</param>
/// <returns>������ڴ��ַ</returns>
EXTERN_C ULONG64 WINAPI Drv_AllocaHighMemory(IN ULONG64 pid, IN OUT PULONG64 size, IN ULONG64 protect);



/// <summary>
/// Զ���ͷŸ�λ�ڴ�
/// </summary>
/// <param name="pid"></param>
/// <param name="BaseAddress"></param>
/// <param name="size"></param>
/// <returns></returns>
/// 
EXTERN_C BOOLEAN WINAPI Drv_FreeHighMemory(IN ULONG64 pid, IN ULONG64 BaseAddress, IN ULONG64 size);





/// �����ڴ�����
/// ��дִ�У�PAGE_EXECUTE_READWRITE
/// ֻ����PAGE_READONLY 
/// ��д��PAGE_READWRITE  
/// ��ִ�У�PAGE_EXECUTE_READ
/// </returns>
EXTERN_C ULONG64 WINAPI Drv_QueryMemory(IN ULONG64 pid, IN ULONG64 address);
/// <summary>
/// �����ڴ����ԡ�
/// </summary>
/// <param name="pid">����id</param>
/// <param name="address">�����ڴ��ַ</param>
/// <param name="protect">
/// �����ڴ�����
/// ��дִ�У�PAGE_EXECUTE_READWRITE
/// ֻ����PAGE_READONLY 
/// ��д��PAGE_READWRITE  
/// ��ִ�У�PAGE_EXECUTE_READ
/// </param>
/// <param name="size">�ڴ��С</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_SetMemoryProtect(IN ULONG64 pid, IN ULONG64 address, IN ULONG64 protect, IN ULONG64 size);
/// <summary>
/// Զ��Call
/// </summary>
/// <param name="pid">����</param>
/// <param name="shellcode">ShellCode����</param>
/// <param name="shellcodeSize">ShellCode�ֽڴ�С</param>
/// <param name="type">
/// 1���ٳ��߳�   2��Զ���߳�   3��Apc
/// </param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_RemoteCall(ULONG64 pid, PVOID shellcode, ULONG64 shellcodeSize, ULONG type);


/// <summary>
/// �ں��޺���ģ��ע��dll��ֻ֧��64
/// </summary>
/// <param name="pid">����id</param>
/// <param name="dllFullPath">dll�ļ�����·��</param>
/// <param name="type">ע�����ͣ�1���߳̽ٳ�2��Զ���߳�3��apc</param>
/// <param name="memType">dll�ڴ����ͣ�0����λ��ͨ1����λ��ҳ</param>
/// 
/// <returns></returns>
/// ����ֵ��-1����ȡ˽Կʧ��
///				  9��pid����
///				  0������ע����������
///				  1���ɹ�
///				  4: dll�ļ�·��������߲�����
EXTERN_C ULONG64 WINAPI Drv_InjectDll(IN ULONG64 pid, IN const char* dllFullPath, IN ULONG type, IN ULONG memType);


/// <summary>
/// �ں��޺���ģ��ע��dll ���ݣ�ֻ֧��64
/// </summary>
/// <param name="pid">����id</param>
/// <param name="dllData">dll����ָ��</param>
/// <param name="size">��С</param>
/// <param name="type">ע�����ͣ�1���߳̽ٳ�2��Զ���߳�3��apc</param>
/// <param name="memType">dll�ڴ����ͣ�0����λ��ͨ1����λ��ҳ</param>
/// <returns></returns>
///  ����ֵ��-1����ȡ˽Կʧ��
///				  9��pid����
///				  0������ע����������
///				  1���ɹ�
EXTERN_C ULONG64 WINAPI Drv_InjectDllData(IN ULONG64 pid, IN PVOID dllData, IN ULONG64 size, IN ULONG type, IN ULONG memType);


/// <summary>
/// ͨ����ģ��ע��
/// </summary>
/// <param name="pid">����ID</param>
/// <param name="dllFullPath">dll·��</param>
/// <returns></returns>
EXTERN_C ULONG64 Drv_GeneralInjectDll(IN ULONG64 pid, IN const char* dllFullPath, IN BOOLEAN isX64);
/// <summary>
/// ͨ����ģ��ע��
/// </summary>
/// <param name="pid">����ID</param>
/// <param name="dllData">dll����ָ��</param>
/// <param name="dllSize">dll���ݴ�С</param>
/// <returns></returns>
EXTERN_C ULONG64 Drv_GeneralInjectDllData(IN ULONG64 pid, IN PVOID dllData, IN LONG dllSize, IN BOOLEAN isX64);

/// <summary>
/// ���̱���
/// </summary>
/// <param name="pid">����PID</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ProtectProcess(IN ULONG64 pid);
/// <summary>
/// ����αװ
/// </summary>
/// <param name="pid">Ҫαװ����PID</param>
/// <param name="fakePid">αװ��Ϊ���̵�PID</param>
/// <returns></returns>
/// ����fakePid��0��ʱ�򣬻��Զ�αװ��Ϊsmss.exe���̣����x32αװx32��x64αװx64
EXTERN_C BOOLEAN WINAPI Drv_FakeProcess(IN ULONG64 pid, IN ULONG64 fakePid);

/// <summary>
/// ����������
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_HideWnd(IN ULONG64 hWnd);

/// <summary>
/// �������ر��ں˼�ء�һ�㱣�������ں˿���������̣��̴߳����͹رռ�أ�һ�����Ǳ��紴���߳�ǰ�رգ������ú�򿪡�
/// </summary>
/// <param name="state">TRUE:�򿪣�FALSE���ر�</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_SetNotificationState(IN BOOLEAN state);

/// <summary>
/// ������ȫ�߳�
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="threadCallbackAddress">�̻߳ص�������ַ</param>
/// <param name="parm">�̻߳ص�����</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_CreateSafeThread(IN ULONG64 pid, IN ULONG64 threadCallbackAddress, ULONG64 parm);


/// <summary>
/// �̶߳���
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="hThread">�߳̾��</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ThreadBreakList(IN ULONG64 pid, IN ULONG64 hThread);


/// <summary>
/// ӳ���ڴ浽ָ������
/// </summary>
/// <param name="pid">��ӳ�� ����PID</param>
/// <param name="address">��ӳ�� �ڴ��ַ</param>
/// <param name="size">��ӳ�� �ڴ��С</param>
/// <param name="targetPid">ӳ�䵽 ����PID</param>
/// <param name="isX64">ӳ�䵽 �����Ƿ�64λ</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_MappingAddress(IN ULONG64 pid, IN ULONG64 address, IN ULONG size, IN ULONG64 targetPid, IN BOOLEAN isX64);
/// <summary>
/// ������н���ӳ�䣬һ���ǡ�ӳ�䵽�� �����˳�����øú���
/// </summary>
/// <param name="pid">ӳ�䵽 ����PID</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_CleanMapping(IN ULONG64 pid);




/// <summary>
/// ǿɾ�ļ�
/// </summary>
/// <param name="fileFullPath">�ļ�·��</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_DeleteFile(IN char* fileFullPath);

/// <summary>
/// ���������º������������Զ�̧��
/// </summary>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_Key(IN USHORT VirtualKey);

/// <summary>
/// ����-����
/// </summary>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_KeyDwon(IN USHORT VirtualKey);
/// <summary>
/// ����-̧��
/// </summary>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_KeyUp(IN USHORT VirtualKey);

/// <summary>
/// ��ϼ�
/// </summary>
/// <param name="ControlVirtualKey"></param>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_Shortcut(IN USHORT ControlVirtualKey, IN USHORT VirtualKey);
/// <summary>
/// �����,�ڰ��º�̧���Զ�������ӳ�
/// </summary>
/// <param name="type">1:���2:�Ҽ�4���м�</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseButton(IN USHORT type);

/// <summary>
/// ��������
/// </summary>
/// <param name="type">1:���2:�Ҽ�4���м�</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseButtonDwon(IN USHORT type);
/// <summary>
/// ����̧��
/// </summary>
/// <param name="type">1:���2:�Ҽ�4���м�</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseButtonUp(IN USHORT type);

/// <summary>
/// ����
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseWheel(IN int data);


/// <summary>
/// ����ƶ�
/// </summary>
/// <param name="dx">x����</param>
/// <param name="dy">y����</param>
/// <param name="type">0�����ԣ�1�����</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MoveTo(IN LONG dx, IN LONG dy, IN LONG type);





/// <summary>,�����ⲻ����
/// �����������Ǳ�ϵͳ�۵�ʱ����ϸ�������������Ϣ��������ˡ�����������������ֻ��дһ����Ҳ���Զ���д��
/// ���һ��������д�����߲����ú������ã������˶Կ۵���ϸ�Ա�ϵͳΪ׼��
/// ��ע�⡿�����������������ʼ��֮ǰ���ò���Ч�����Ƽ���һ�������ô˺�����
/// </summary>
/// <param name="cardId">�������۵Ŀ��ܣ���ʶ�ͻ���Ψһ��־</param>
/// <param name="thirdId">�ڵ������Ʒ�ƽ̨����ʶ�ͻ���Ψһ��־ID</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_SetClientInfo(IN const char* cardId, IN const char* thirdId);


/// <summary>
/// ���ض�������
/// </summary>
/// <param name="ver">�汾��</param>
/// <param name="custom">
/// 0��ֻ���ض�д
/// 1�����ض�д��ע��
/// 3�����ض�д��ע��ʹ��ڱ���
/// </param>
/// <returns>����ֵ</returns>
/// ����ֵ˵����
///					-1��ϵͳ������������
///					 0����ʼ��ʧ�ܣ�һ���Ǳ�������ɱ�������
///					 1����ʼ���ɹ�
EXTERN_C INT WINAPI Drv_InitCustom(IN ULONG ver, IN ULONG custom);

/// <summary>
/// ��ȡģ�麯����ַ������������
/// </summary>
/// <param name="pid">����PID</param>
/// <param name="modName">ģ������</param>
/// <param name="funcName">��������</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_GetFuncAddrByName(IN ULONG64 pid, IN PCHAR modName, IN PCHAR funcName);

//
//EXTERN_C BOOLEAN WINAPI Drv_GetApiIp(IN OUT char* ip);
//EXTERN_C BOOLEAN WINAPI Drv_GetDownloadIp(IN OUT char* ip);




