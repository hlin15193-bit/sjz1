#pragma once
#include <Windows.h>
#pragma comment(lib, "../x64_MT_143.lib")
#include"../base.h"
#include"Utils/Utils.hpp"
#pragma warning(disable:4996)
EXTERN_C INT WINAPI Drv_Regist(IN const char* appId, IN const char* cryptAppId);
/// <summary>
/// 驱动初始化,包括下载驱动，加载驱动 过程,正式发布用这个
/// </summary>
/// <returns>返回值</returns>
/// 返回值说明：
///					-1：系统错误或者网络错
///					 0：初始化失败，一般是被保护，杀软等拦截
///					 1：初始化成功
/// 				 4: 安装j驱动失败
///					 5：安装r驱动失败 
///					 9: 没有认证，请先运行	Drv_Regist进行认证
EXTERN_C INT WINAPI Drv_Init();

/// <summary>
/// 选择版本初始化驱动，Drv_Init()等于Drv_InitByVersion(1)效果
/// </summary>
/// <param name="ver">初始化驱动版本号</param>
/// <returns>返回值</returns>
/// 返回值说明：
///					-1：系统错误或者网络错
///					 0：初始化失败，一般是被保护，杀软等拦截
///					 1：初始化成功
///					 4: 安装j驱动失败
///					 5：安装r驱动失败 	
///					 9: 没有认证，请先运行	Drv_Regist进行认证
EXTERN_C INT WINAPI Drv_InitByVersion(IN ULONG ver);


/// <summary>
/// 判断驱动是否安装成功
/// </summary>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_IsInstall();



/// <summary>
/// CR3保护,修复各种保护有CR3保护，没有保护CR3，也需要使用，加快速度
/// </summary>
/// <param name="pid">进程PID</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_FixCr3(IN ULONG64 pid);

/// <summary>
/// 获取进程模块信息
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="moduleName">模块名字</param>
/// <param name="size">模块大小</param>
/// <param name="entryFuncAddress">入口函数地址</param>
/// <returns>模块地址</returns>
EXTERN_C ULONG64 WINAPI Drv_GetModule(IN ULONG64 pid, const char* moduleName, OUT PULONG64 size, OUT PULONG64 entryFuncAddress);

/// <summary>
/// 获取进程主模块信息
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="size">模块大小</param>
/// <param name="entryFuncAddress">入口函数地址</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_GetMainModule(ULONG64 pid, OUT PULONG64 size, OUT PULONG64 entryFuncAddress);


EXTERN_C ULONG64 WINAPI Drv_GetR0Module(const char* moduleName, OUT PULONG64 size);

/// <summary>
/// 特征码搜寻
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="startAddress">开始地址</param>
/// <param name="endAddress">结束地址</param>
/// <param name="patternCode">特征码：45*887766****E8</param>
/// <returns>根据特征码搜寻的地址</returns>
EXTERN_C ULONG64 WINAPI Drv_SearchCode(ULONG64 pid, IN ULONG64 startAddress, IN ULONG64 endAddress, const char* patternCode);

/// <summary>
/// 读内存，无附加，物理读，无视内存属性
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="BaseAddress">要读内存地址</param>
/// <param name="Buffer">R3定义的接受数据地址</param>
/// <param name="size">读写数据长度</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ReadMemory(IN ULONG64 pid, IN ULONG64 address, IN OUT PVOID buffer, IN ULONG64 size);

/// <summary>
/// 读内存，无附加，映射读
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="BaseAddress">要读内存地址</param>
/// <param name="Buffer">R3定义的接受数据地址</param>
/// <param name="size">读写数据长度</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ReadMemory2(IN ULONG64 pid, IN ULONG64 address, IN OUT PVOID buffer, IN ULONG64 size);



/// <summary>
/// 读内存，无附加，物理读，不支持动态进行DTB，支持多开读，无需Drv_FixCr3函数。
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="BaseAddress">要读内存地址</param>
/// <param name="Buffer">R3定义的接受数据地址</param>
/// <param name="size">读写数据长度</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ReadMemory3(IN ULONG64 pid, IN ULONG64 address, IN OUT PVOID buffer, IN ULONG64 size);





/// <summary>
/// 写内存，无附加，物理写，无视内存读写属性
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="BaseAddress">要写入数据地址</param>
/// <param name="Buffer">R3定义的写入数据地址</param>
/// <param name="size">数据长度</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_WriteMemory(IN ULONG64 pid, IN ULONG64 address, IN PVOID buffer, IN ULONG64 size);


/// <summary>
/// 写内存，无附加，映射写
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="BaseAddress">要写入数据地址</param>
/// <param name="Buffer">R3定义的写入数据地址</param>
/// <param name="size">数据长度</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_WriteMemory2(IN ULONG64 pid, IN ULONG64 address, IN PVOID buffer, IN ULONG64 size);

/// <summary>
/// 写内存，无附加，物理写，不支持动态进行DTB，支持多开读，无需Drv_FixCr3函数。
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="BaseAddress">要写入数据地址</param>
/// <param name="Buffer">R3定义的写入数据地址</param>
/// <param name="size">数据长度</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_WriteMemory3(IN ULONG64 pid, IN ULONG64 address, IN PVOID buffer, IN ULONG64 size);

/// <summary>
/// 远程申请普通底位内存
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="size">IN 申请大小,OUT 实际大小</param>
/// <param name="protect">内存属性：PAGE_EXECUTE_WRITEREAD等</param>
/// <returns>申请地址</returns>
EXTERN_C ULONG64 WINAPI Drv_AllocaMemory(IN ULONG64 pid, IN OUT PULONG64 size, IN ULONG64 protect);



/// <summary>
/// 远程释放普通内存
/// </summary>
/// <param name="pid"></param>
/// <param name="BaseAddress"></param>
/// <param name="size"></param>
/// <returns></returns>
/// 
EXTERN_C BOOLEAN WINAPI Drv_FreeMemory(IN ULONG64 pid, IN ULONG64 BaseAddress, IN ULONG64 size);




/// <summary>
/// 远程申请高位内存
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="size">IN 申请大小,OUT 实际大小</param>
/// <param name="protect">内存属性</param>
/// <returns>申请的内存地址</returns>
EXTERN_C ULONG64 WINAPI Drv_AllocaHighMemory(IN ULONG64 pid, IN OUT PULONG64 size, IN ULONG64 protect);



/// <summary>
/// 远程释放高位内存
/// </summary>
/// <param name="pid"></param>
/// <param name="BaseAddress"></param>
/// <param name="size"></param>
/// <returns></returns>
/// 
EXTERN_C BOOLEAN WINAPI Drv_FreeHighMemory(IN ULONG64 pid, IN ULONG64 BaseAddress, IN ULONG64 size);





/// 进程内存属性
/// 读写执行：PAGE_EXECUTE_READWRITE
/// 只读：PAGE_READONLY 
/// 读写：PAGE_READWRITE  
/// 读执行：PAGE_EXECUTE_READ
/// </returns>
EXTERN_C ULONG64 WINAPI Drv_QueryMemory(IN ULONG64 pid, IN ULONG64 address);
/// <summary>
/// 设置内存属性。
/// </summary>
/// <param name="pid">进程id</param>
/// <param name="address">进程内存地址</param>
/// <param name="protect">
/// 进程内存属性
/// 读写执行：PAGE_EXECUTE_READWRITE
/// 只读：PAGE_READONLY 
/// 读写：PAGE_READWRITE  
/// 读执行：PAGE_EXECUTE_READ
/// </param>
/// <param name="size">内存大小</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_SetMemoryProtect(IN ULONG64 pid, IN ULONG64 address, IN ULONG64 protect, IN ULONG64 size);
/// <summary>
/// 远程Call
/// </summary>
/// <param name="pid">进程</param>
/// <param name="shellcode">ShellCode代码</param>
/// <param name="shellcodeSize">ShellCode字节大小</param>
/// <param name="type">
/// 1：劫持线程   2：远程线程   3：Apc
/// </param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_RemoteCall(ULONG64 pid, PVOID shellcode, ULONG64 shellcodeSize, ULONG type);


/// <summary>
/// 内核无痕无模块注入dll，只支持64
/// </summary>
/// <param name="pid">进程id</param>
/// <param name="dllFullPath">dll文件完整路径</param>
/// <param name="type">注入类型，1：线程劫持2：远程线程3：apc</param>
/// <param name="memType">dll内存类型，0：低位普通1：高位挂页</param>
/// 
/// <returns></returns>
/// 返回值：-1：获取私钥失败
///				  9：pid错误
///				  0：驱动注入遇到错误
///				  1：成功
///				  4: dll文件路径错误或者不可用
EXTERN_C ULONG64 WINAPI Drv_InjectDll(IN ULONG64 pid, IN const char* dllFullPath, IN ULONG type, IN ULONG memType);


/// <summary>
/// 内核无痕无模块注入dll 数据，只支持64
/// </summary>
/// <param name="pid">进程id</param>
/// <param name="dllData">dll数据指针</param>
/// <param name="size">大小</param>
/// <param name="type">注入类型，1：线程劫持2：远程线程3：apc</param>
/// <param name="memType">dll内存类型，0：低位普通1：高位挂页</param>
/// <returns></returns>
///  返回值：-1：获取私钥失败
///				  9：pid错误
///				  0：驱动注入遇到错误
///				  1：成功
EXTERN_C ULONG64 WINAPI Drv_InjectDllData(IN ULONG64 pid, IN PVOID dllData, IN ULONG64 size, IN ULONG type, IN ULONG memType);


/// <summary>
/// 通用无模块注入
/// </summary>
/// <param name="pid">进程ID</param>
/// <param name="dllFullPath">dll路径</param>
/// <returns></returns>
EXTERN_C ULONG64 Drv_GeneralInjectDll(IN ULONG64 pid, IN const char* dllFullPath, IN BOOLEAN isX64);
/// <summary>
/// 通用无模块注入
/// </summary>
/// <param name="pid">进程ID</param>
/// <param name="dllData">dll数据指针</param>
/// <param name="dllSize">dll数据大小</param>
/// <returns></returns>
EXTERN_C ULONG64 Drv_GeneralInjectDllData(IN ULONG64 pid, IN PVOID dllData, IN LONG dllSize, IN BOOLEAN isX64);

/// <summary>
/// 进程保护
/// </summary>
/// <param name="pid">进程PID</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ProtectProcess(IN ULONG64 pid);
/// <summary>
/// 进程伪装
/// </summary>
/// <param name="pid">要伪装进程PID</param>
/// <param name="fakePid">伪装成为进程的PID</param>
/// <returns></returns>
/// 参数fakePid：0的时候，会自动伪装成为smss.exe进程，最好x32伪装x32，x64伪装x64
EXTERN_C BOOLEAN WINAPI Drv_FakeProcess(IN ULONG64 pid, IN ULONG64 fakePid);

/// <summary>
/// 保护窗窗口
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_HideWnd(IN ULONG64 hWnd);

/// <summary>
/// 开启、关闭内核监控。一般保护会在内核开启比如进程，线程创建和关闭监控，一般我们比如创建线程前关闭，创建好后打开。
/// </summary>
/// <param name="state">TRUE:打开，FALSE：关闭</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_SetNotificationState(IN BOOLEAN state);

/// <summary>
/// 创建安全线程
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="threadCallbackAddress">线程回调函数地址</param>
/// <param name="parm">线程回调参数</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_CreateSafeThread(IN ULONG64 pid, IN ULONG64 threadCallbackAddress, ULONG64 parm);


/// <summary>
/// 线程断链
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="hThread">线程句柄</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_ThreadBreakList(IN ULONG64 pid, IN ULONG64 hThread);


/// <summary>
/// 映射内存到指定进程
/// </summary>
/// <param name="pid">被映射 进程PID</param>
/// <param name="address">被映射 内存地址</param>
/// <param name="size">被映射 内存大小</param>
/// <param name="targetPid">映射到 进程PID</param>
/// <param name="isX64">映射到 进程是否64位</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_MappingAddress(IN ULONG64 pid, IN ULONG64 address, IN ULONG size, IN ULONG64 targetPid, IN BOOLEAN isX64);
/// <summary>
/// 清除所有进程映射，一般是“映射到” 进程退出后调用该函数
/// </summary>
/// <param name="pid">映射到 进程PID</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_CleanMapping(IN ULONG64 pid);




/// <summary>
/// 强删文件
/// </summary>
/// <param name="fileFullPath">文件路径</param>
/// <returns></returns>
EXTERN_C BOOLEAN WINAPI Drv_DeleteFile(IN char* fileFullPath);

/// <summary>
/// 按键：按下后会随机毫秒数自动抬起
/// </summary>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_Key(IN USHORT VirtualKey);

/// <summary>
/// 按键-按下
/// </summary>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_KeyDwon(IN USHORT VirtualKey);
/// <summary>
/// 按键-抬起
/// </summary>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_KeyUp(IN USHORT VirtualKey);

/// <summary>
/// 组合键
/// </summary>
/// <param name="ControlVirtualKey"></param>
/// <param name="VirtualKey"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_Shortcut(IN USHORT ControlVirtualKey, IN USHORT VirtualKey);
/// <summary>
/// 鼠标点击,在按下和抬起自动加随机延迟
/// </summary>
/// <param name="type">1:左键2:右键4：中键</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseButton(IN USHORT type);

/// <summary>
/// 鼠标键按下
/// </summary>
/// <param name="type">1:左键2:右键4：中键</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseButtonDwon(IN USHORT type);
/// <summary>
/// 鼠标键抬起
/// </summary>
/// <param name="type">1:左键2:右键4：中键</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseButtonUp(IN USHORT type);

/// <summary>
/// 滚轮
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MouseWheel(IN int data);


/// <summary>
/// 鼠标移动
/// </summary>
/// <param name="dx">x坐标</param>
/// <param name="dy">y坐标</param>
/// <param name="type">0：绝对，1：相对</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_MoveTo(IN LONG dx, IN LONG dy, IN LONG type);





/// <summary>,基本库不包含
/// 本函数功能是本系统扣点时，明细会标明这两个信息，方便对账。这两个参数，可以只填写一个，也可以都填写，
/// 如果一个都不填写，或者不调用函数设置，将来核对扣点明细以本系统为准。
/// 【注意】：这个函数在驱动初始化之前调用才有效果，推荐第一个先设置此函数。
/// </summary>
/// <param name="cardId">对外销售的卡密，标识客户端唯一标志</param>
/// <param name="thirdId">在第三方计费平台，标识客户端唯一标志ID</param>
/// <returns></returns>
EXTERN_C VOID WINAPI Drv_SetClientInfo(IN const char* cardId, IN const char* thirdId);


/// <summary>
/// 加载定制驱动
/// </summary>
/// <param name="ver">版本号</param>
/// <param name="custom">
/// 0：只加载读写
/// 1：加载读写和注入
/// 3：加载读写、注入和窗口保护
/// </param>
/// <returns>返回值</returns>
/// 返回值说明：
///					-1：系统错误或者网络错
///					 0：初始化失败，一般是被保护，杀软等拦截
///					 1：初始化成功
EXTERN_C INT WINAPI Drv_InitCustom(IN ULONG ver, IN ULONG custom);

/// <summary>
/// 获取模块函数地址（导出函数）
/// </summary>
/// <param name="pid">进程PID</param>
/// <param name="modName">模块名字</param>
/// <param name="funcName">函数名字</param>
/// <returns></returns>
EXTERN_C ULONG64 WINAPI Drv_GetFuncAddrByName(IN ULONG64 pid, IN PCHAR modName, IN PCHAR funcName);

//
//EXTERN_C BOOLEAN WINAPI Drv_GetApiIp(IN OUT char* ip);
//EXTERN_C BOOLEAN WINAPI Drv_GetDownloadIp(IN OUT char* ip);




