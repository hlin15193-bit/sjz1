
#define IMGUI_DEFINE_MATH_OPERATORS

#include"base.h"
#include"MainThread.h"
#include"Utils/Utils.hpp"
#include"Menu/Gui.h"
#include"Dx11/ESP.h"
#include"Menu/Menu.hpp"
#include<d3dkmthk.h>
#include <conio.h>
//#include "HTTP/HttpRequest.h"
char Key[33] = { 0 };
BOOL WINAPI ConsoleHandler(DWORD event) {
	if (event == CTRL_CLOSE_EVENT) {
		HWND Progman = FindWindowA("Progman", NULL);
		HWND TrayWnd = FindWindowA("Shell_TrayWnd", NULL);
		ShowWindow(Progman, SW_SHOW);
		ShowWindow(TrayWnd, SW_SHOW);
		return TRUE;
	}
	return FALSE;
}
void SetConsoleStyle()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	if (!(dwMode & ENABLE_VIRTUAL_TERMINAL_PROCESSING))
	{
		dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(hOut, dwMode);
	}
}
ULONG FindGamePid()
{
	ULONG pid = 0;
	HWND hwnd = FindWindowA("UnrealWindow", NULL);
	if (!hwnd) return pid;
	GetWindowThreadProcessId(hwnd, &pid);
	return pid;
}
void SetThreadHighPriority(std::thread& t) {
	// 获取线程句柄
	HANDLE threadHandle = t.native_handle();
	SetThreadPriority(threadHandle, THREAD_PRIORITY_TIME_CRITICAL);
}
void update_window_pos()
{
	Dx11Data::g_game_hwnd = FindWindowA("UnrealWindow", NULL);

	while (true)
	{
		GetWindowRect(Dx11Data::g_game_hwnd, &Dx11Data::g_rect);
		auto style = GetWindowLong(Dx11Data::g_game_hwnd, GWL_STYLE);

		if (style & WS_CAPTION)
		{
			Width = Dx11Data::g_rect.right - Dx11Data::g_rect.left;
			Height = Dx11Data::g_rect.bottom - Dx11Data::g_rect.top;

			Dx11Data::g_rect.top += 32;
			Height -= 39;

		}
		else
		{
			Width = Dx11Data::g_rect.right - Dx11Data::g_rect.left;
			Height = Dx11Data::g_rect.bottom - Dx11Data::g_rect.top;
		}

		Dx11Data::ScreenWidth = Width;
		Dx11Data::ScreenHeight = Height;

	}
}
//void ChuShiHua()
//{
//	string server = "http://154.222.18.12/";//服务器地址
//	INTERNET_PORT port = 6666;//端口号
//	string CSH = "Initializing?";
//	string token = "token=WYZHDQ";
//	string duankou = "&duankou=6666";
//	server = server + CSH + token + "&Version=1" + duankou;
//	string res = GetHtml(server, port);
//	if (res.find("200") == string::npos) {
//		cout << "验证初始化失败：" << res << "\n\n";
//		system("pause");
//		exit(0);
//	}
//}
//void DengLu()
//{
//	string server = "http://154.222.18.12/"; // 服务器地址
//	INTERNET_PORT port = 6666; // 端口号
//	string CSH = "Landing?";
//	string token = "token=WYZHDQ";
//	printf("Login Key：");
//	if (!fgets(Key, sizeof(Key), stdin)) {
//		cerr << "输入错误\n";
//		exit(1);
//	}
//	Key[strcspn(Key, "\n")] = 0; // 移除换行符
//	string JQM;
//	GetCpuByCmd(JQM, 32);
//	server = server + CSH + token + "&ka=" + Key + "&pc=" + JQM;
//	string res = GetHtml(server, port);
//	if (res.find("验证成功") == string::npos) {
//		cout << "登录失败：" << res << "\n\n";
//		system("pause");
//		exit(0);
//	}
//}
//std::string extractTime(const std::string& res) {
//	size_t start = res.find("\"Success\": \"") + 12;
//	size_t end = res.find("\"", start);
//	if (start != std::string::npos && end != std::string::npos) {
//		return res.substr(start, end - start);
//	}
//	return "";
//}
//// 将时间字符串转换为时间戳
//time_t stringToTime(const std::string& timeStr) {
//	struct tm tm = { 0 };
//	// 解析格式: yyyy-MM-dd HH:mm:ss
//	if (sscanf(timeStr.c_str(), "%d-%d-%d %d:%d:%d",
//		&tm.tm_year, &tm.tm_mon, &tm.tm_mday,
//		&tm.tm_hour, &tm.tm_min, &tm.tm_sec) == 6) {
//		tm.tm_year -= 1900; // 年份需要减去1900
//		tm.tm_mon -= 1;     // 月份从0开始
//		return mktime(&tm);
//	}
//	return -1;
//}
//// 将时间戳格式化为yyyy-MM-dd HH:mm:ss
//std::string formatTime(time_t time) {
//	struct tm* localTime = localtime(&time);
//	char buffer[20];
//	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
//	return std::string(buffer);
//}
//void YZHF()
//{
//	string server = "http://154.222.18.12/"; // 服务器地址
//	INTERNET_PORT port = 6666; // 端口号
//	string HFX = "Merger?";
//	string token = "token=WYZHDQ";
//	server = server + HFX + token + "&ka=" + Key + "&Number=3";
//	while (true) {
//		string res = GetHtml(server, port);
//		// 提取时间部分
//		std::string timeStr = extractTime(res);
//		// 转换为时间戳
//		time_t targetTime = stringToTime(timeStr);
//		// 循环检查时间，每分钟一次
//		// 获取当前时间
//		time_t now = time(nullptr);
//		// 检查是否到达目标时间
//		if (now >= targetTime) {
//			exit(0);  // 正常退出程序
//		}
//		// 每分钟检查一次（60秒）
//		std::this_thread::sleep_for(std::chrono::seconds(60));
//	}
//}
int main()
{

	if (!SetConsoleCtrlHandler(ConsoleHandler, TRUE))//注册控制台关闭事件
	{
		system("pause");
		return -1;
	}
	SetConsoleStyle();//设置控制台样式	
	Utils::Log(1, ("------->正在施展魔术V1.35 总负责樱桃<----------"));
	Utils::Log(1, ("------->系统版本V1.35<----------"));
	Utils::Log(1, ("1Max开发组 感谢各位任何意见采纳就送卡"));
	if (!Memory::init())
	{
		Utils::Log(1, ("魔术展示失败 驱动注入失败 请联系您的上级\r\n"));
		Utils::Log(1, ("驱动加载失败 或者非正品 卡密等等\r\n"));
		system("pause");
		return 0;
	}
	if (!Drv_FakeProcess(GetProcessId(GetCurrentProcess()), 0))
	{
		Utils::Log(1, ("FakeProcess失败\r\n"));
		system("pause");
		exit(0);
	}
	if (!Drv_ProtectProcess(GetProcessId(GetCurrentProcess())))
	{
		Utils::Log(1,("ProtectProcess失败\r\n"));
		system("pause");
		exit(0);
	}
	Utils::Log(1, ("------->魔术表演成功<----------"));
	Utils::Log(1, "------->魔术辅助 注入成功 请上游戏<----------");
	Utils::Log(1, "------->请上游戏 注意演技<----------");
	ULONG PID = 0;
	HWND Game_Window;
	while (PID == 0)
	{
		Game_Window = FindWindowA("UnrealWindow", nullptr);
		if (Game_Window) {
			if (!GetWindowThreadProcessId(Game_Window, &PID)) {
				Utils::Log(1, "错误：未找到游戏进程，程序即将退出");
				system("pause");
				return 0;
			}
			else {
				Memory::m_pid = PID;
				break;
			}
		}
		Sleep(2000); // 降低CPU占用
	}
	Sleep(5000);
	Drv_FixCr3(Memory::m_pid);
	g_Game_Module = Memory::GetMouduleBaseAddr();
	FreeConsole();//关闭控制台
	D3DKMTSetProcessSchedulingPriorityClass(GetCurrentProcess(), D3DKMT_SCHEDULINGPRIORITYCLASS_REALTIME);
    std::thread thread1(MainThread::UpdataGlobalData);
    std::thread thread2(MainThread::UpdataLocalCameraData);
    std::thread thread3(MainThread::UpdataActorsData);
    std::thread thread4(MainThread::UpdataPlayersData);
    std::thread thread5(MainThread::UpdataItemsData);
    std::thread thread6(MainThread::RunAimBot);
    std::thread thread7(MainThread::UpdateLocalPlayer);
    std::thread thread8(MainThread::UpdataMapRadar);
    std::thread thread9(update_window_pos);
    std::thread thread10(MainThread::UpdateKeyState);

	thread1.detach();
	thread2.detach();
	thread3.detach();
	thread4.detach();
	thread5.detach();
	thread6.detach();
	thread7.detach();
	thread8.detach();
	thread9.detach();
	thread10.detach();

	CreateWindow_Violet("UnrealWindow", &ESP::DrawESP, &MenuInit);

}

