//#define IMGUI_DEFINE_MATH_OPERATORS
//#ifndef GUI_HPP
//#define GUI_HPP
//
//#include "imgui.h"
//#include "imgui_impl_win32.h"
//#include "imgui_impl_dx11.h"
//#include <d3d11.h>
//#include <tchar.h>
//
//#include "imgui_edited.hpp"
//#include "textures.h"
//#include "font.h"
//
//#include <chrono>
//#include <algorithm>
//#include <functional>
//#include <vector>
//#include <random>
//#include <math.h>
//#include <dwmapi.h>
//#include "Dx11/Texture.h"
//#include <windows.h>
//#include <psapi.h>
//#include <tlhelp32.h>
//
//#pragma comment(lib, "psapi.lib")
//
//// 常量定义 - 替代枚举使用
//constexpr int MAX_CHECKBOXES = 40;
//constexpr int MAX_SLIDERS = 40;
//constexpr int MAX_KEYS = 40;
//constexpr int MAX_SELECTS = 40;
//constexpr int MAX_COLORS = 16;
//constexpr int PAGE_COUNT = 5;
//
//// 资源路径常量
//const std::string ARROW_ICON_PATH = "Assets/arrow.png";
//const std::string ARMOR_ICON_PATH = "Assets/Armor.png";
//const std::string HELMET_ICON_PATH = "Assets/Helmet.png";
//const std::string HUB_ICONS_BIN = "Assets/Hub/icons.bin";
//const std::string WEAPON_ICONS_BIN = "Assets/Weapon/icons1.bin";
//
//std::string description_test = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.";
//
//struct windowinfo				//窗口信息结构体
//{
//    HWND hwnd = nullptr;					//窗口句柄
//    LPCSTR ClassName = nullptr;		//窗口类名
//    LPCSTR TitleName = nullptr;		//窗口标题名
//    ImVec2 pos = { 0,0 };					//窗口位置
//    ImVec2 size = { 0,0 };				//窗口尺寸
//};
//inline windowinfo mywindow;		//透明窗口的窗口信息
//inline windowinfo gamewindow;		//游戏窗口的窗口信息
//
//// 系统进程窗口相关变量
//inline std::vector<windowinfo> system_process_windows;  // 存储系统进程窗口
//inline std::random_device rd;
//inline std::mt19937 rng(rd());
//
//// 系统进程名称列表
//const std::vector<std::wstring> system_process_names = {
//    L"csrss.exe",
//    L"wininit.exe",
//    L"services.exe",
//    L"lsass.exe",
//    L"svchost.exe",
//    L"explorer.exe",
//    L"taskhostw.exe",
//    L"dwm.exe",
//    L"RuntimeBroker.exe",
//    L"smss.exe",
//    L"audiodg.exe",
//    L"spoolsv.exe"
//};
//
//namespace texture
//{
//    ID3D11ShaderResourceView* preview = nullptr;
//    ID3D11ShaderResourceView* ragebot = nullptr;
//    ID3D11ShaderResourceView* legitbot = nullptr;
//    ID3D11ShaderResourceView* visuals = nullptr;
//    ID3D11ShaderResourceView* misc = nullptr;
//    ID3D11ShaderResourceView* world = nullptr;
//    ID3D11ShaderResourceView* settings = nullptr;
//}
//
//
//namespace var
//{
//    static float tab_alpha = 0.f; /* */ static float tab_add; /* */ static int active_tab = 0;
//
//    bool interactive = false;
//    float tab_right = 0, tab_left = 0;
//    bool check[40], value[40];
//    float col0[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
//    float col1[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
//    float col2[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
//    float col3[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
//    float col4[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
//    float col5[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
//    float col6[4] = { 1.0f, 0.5f, 0.0f, 1.0f };
//    float col7[4] = { 0.5f, 0.0f, 1.0f, 1.0f };
//    float col8[4] = { 0.0f, 0.5f, 1.0f, 1.0f };
//    float col9[4] = { 0.5f, 1.0f, 0.0f, 1.0f };
//    float col10[4] = { 1.0f, 0.0f, 0.5f, 1.0f };
//    float col11[4] = { 0.0f, 1.0f, 0.5f, 1.0f };
//    float col12[4] = { 0.5f, 0.0f, 1.0f, 1.0f };
//    float col13[4] = { 0.0f, 0.5f, 1.0f, 1.0f };
//    float col14[4] = { 1.0f, 0.5f, 0.5f, 1.0f };
//    float col15[4] = { 0.5f, 1.0f, 0.5f, 1.0f };
//    int slider_value[40], key[40], m[40], select[40];
//    const char* pageNames[] = { U8("玩家"), U8("物品"),U8("自瞄"),U8("容器"),U8("杂项") };
//    const ImVec2 buttonSize(125, 35);
//    int page = 0;
//}
//
//static ID3D11Device* g_pd3dDevice = nullptr;
//static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
//static IDXGISwapChain* g_pSwapChain = nullptr;
//static UINT g_ResizeWidth = 0, g_ResizeHeight = 0;
//static ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;
//
//inline bool CreateDeviceD3D(HWND hWnd);
//void CleanupDeviceD3D();
//void CreateRenderTarget();
//void CleanupRenderTarget();
//LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//// 辅助函数：获取窗口所属进程名称
//std::wstring GetProcessNameFromHWND(HWND hwnd) {
//    DWORD processId = 0;
//    GetWindowThreadProcessId(hwnd, &processId);
//    if (processId == 0) {
//        return L"未知进程"; // 进程ID获取失败
//    }
//
//    // 尝试以较低权限打开进程（避免权限不足）
//    HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
//    if (hProcess == nullptr) {
//        // 权限不足时，返回进程ID作为替代
//        return L"进程ID:" + std::to_wstring(processId);
//    }
//
//    wchar_t processName[MAX_PATH] = L"";
//    DWORD nameLen = sizeof(processName) / sizeof(wchar_t);
//    // 优先使用GetProcessImageFileNameW（权限要求更低）
//    if (GetProcessImageFileNameW(hProcess, processName, nameLen) == 0) {
//        // 失败时回退到GetModuleBaseNameW
//        GetModuleBaseNameW(hProcess, nullptr, processName, nameLen);
//    }
//    CloseHandle(hProcess);
//
//    // 提取文件名（去掉路径）
//    wchar_t* fileName = wcsrchr(processName, L'\\');
//    if (fileName) {
//        return fileName + 1; // 跳过反斜杠
//    }
//    return processName; // 本身就是文件名
//}
//bool IsPathLikeTitle(const wchar_t* title) {
//    if (!title || title[0] == L'\0') return false;
//    // 检测是否包含路径分隔符或常见根目录
//    return (wcschr(title, L'\\') != nullptr) ||
//        (wcschr(title, L'/') != nullptr) ||
//        (wcslen(title) > 3 && title[1] == L':'); // 如"C:"
//}
//// 枚举窗口回调函数
//BOOL CALLBACK EnumSystemWindowsProc(HWND hwnd, LPARAM lParam) {
//    // 只处理可见窗口
//    if (!IsWindowVisible(hwnd)) {
//        return TRUE;
//    }
//
//    // 获取窗口所属进程名称
//    std::wstring processName = GetProcessNameFromHWND(hwnd);
//
//    // 检查是否为系统进程
//    if (std::find(system_process_names.begin(), system_process_names.end(), processName) == system_process_names.end()) {
//        return TRUE; // 不是系统进程，继续枚举
//    }
//
//    // 获取窗口标题
//    int titleLength = GetWindowTextLengthA(hwnd) + 1;
//    char* titleBuffer = new char[titleLength];
//    GetWindowTextA(hwnd, titleBuffer, titleLength);
//
//    // 获取窗口类名
//    char classNameBuffer[256];
//    GetClassNameA(hwnd, classNameBuffer, sizeof(classNameBuffer));
//
//    // 获取窗口位置和大小
//    RECT rect;
//    GetWindowRect(hwnd, &rect);
//
//    windowinfo info;
//    info.hwnd = hwnd;
//    info.ClassName = _strdup(classNameBuffer);  // 分配内存存储类名
//    info.TitleName = _strdup(titleBuffer);     // 分配内存存储标题
//    info.pos = ImVec2((float)rect.left, (float)rect.top);
//    info.size = ImVec2((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));
//
//    // 添加到系统进程窗口列表
//    system_process_windows.push_back(info);
//
//    delete[] titleBuffer;
//    return TRUE;
//}
//
//// 枚举所有系统进程窗口
//void EnumSystemProcessWindows() {
//    // 先释放之前分配的内存
//    for (auto& win : system_process_windows) {
//        free((void*)win.ClassName);
//        free((void*)win.TitleName);
//    }
//    system_process_windows.clear();
//
//    // 枚举窗口
//    EnumWindows(EnumSystemWindowsProc, 0);
//}
//
//// 随机获取一个系统进程窗口信息
//windowinfo GetRandomSystemWindow() {
//    static bool initialized = false;
//    // 首次调用或窗口列表为空时枚举窗口
//    if (!initialized || system_process_windows.empty()) {
//        EnumSystemProcessWindows();
//        initialized = true;
//    }
//
//    if (system_process_windows.empty()) {
//        return windowinfo{}; // 如果没有找到系统窗口，返回空信息
//    }
//
//    // 随机选择一个窗口
//    std::uniform_int_distribution<int> dist(0, system_process_windows.size() - 1);
//    int index = dist(rng);
//    return system_process_windows[index];
//}
//
//struct Notification {
//    int id;
//    std::string icon, message, information;
//    std::chrono::steady_clock::time_point startTime;
//    std::chrono::steady_clock::time_point endTime;
//    ImU32 color;
//};
//
//class NotificationSystem {
//public:
//    NotificationSystem() : notificationIdCounter(0) {}
//
//    void AddNotification(const std::string& icon, const std::string& information, const std::string& message, int durationMs, ImU32 color) {
//        auto now = std::chrono::steady_clock::now();
//        auto endTime = now + std::chrono::milliseconds(durationMs);
//        notifications.push_back({ notificationIdCounter++, icon, information, message, now, endTime, color });
//    }
//
//    void DrawNotifications() {
//        auto now = std::chrono::steady_clock::now();
//
//        std::sort(notifications.begin(), notifications.end(),
//            [now](const Notification& a, const Notification& b) -> bool {
//                float durationA = std::chrono::duration_cast<std::chrono::milliseconds>(a.endTime - a.startTime).count();
//                float elapsedA = std::chrono::duration_cast<std::chrono::milliseconds>(now - a.startTime).count();
//                float percentageA = (durationA - elapsedA) / durationA;
//
//                float durationB = std::chrono::duration_cast<std::chrono::milliseconds>(b.endTime - b.startTime).count();
//                float elapsedB = std::chrono::duration_cast<std::chrono::milliseconds>(now - b.startTime).count();
//                float percentageB = (durationB - elapsedB) / durationB;
//
//                return percentageA < percentageB;
//            }
//        );
//
//        int currentNotificationPosition = 0;
//
//        for (auto& notification : notifications) {
//            if (now < notification.endTime) {
//                float duration = std::chrono::duration_cast<std::chrono::milliseconds>(notification.endTime - notification.startTime).count();
//                float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - notification.startTime).count();
//                float percentage = (duration - elapsed) / duration * 100.0f;
//
//                ShowNotification(currentNotificationPosition, notification.icon, notification.information, notification.message, percentage, notification.color);
//                currentNotificationPosition++;
//            }
//        }
//
//        notifications.erase(std::remove_if(notifications.begin(), notifications.end(),
//            [now](const Notification& notification) { return now >= notification.endTime; }),
//            notifications.end());
//    }
//
//private:
//    std::vector<Notification> notifications;
//    int notificationIdCounter;
//
//    void ShowNotification(int position, const std::string& icon, const std::string& information, const std::string& message, float percentage, ImU32 color) {
//        float duePercentage = 100.0f - percentage;
//        float alpha = percentage > 10.0f ? 1.0f : percentage / 10.0f;
//
//        PushFont(font::inter_medium_widget);
//        SetNextWindowPos(ImVec2(GetIO().DisplaySize.x - (CalcTextSize(message.c_str()).x + CalcTextSize(information.c_str()).x + 70), 15 + (position * 55)), ImGuiCond_Always);
//        SetNextWindowSize(ImVec2(CalcTextSize(message.c_str()).x + CalcTextSize(information.c_str()).x + 60, 40));
//        PopFont();
//
//        PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
//        PushStyleVar(ImGuiStyleVar_WindowRounding, 6.f);
//        PushStyleColor(ImGuiCol_WindowBg, GetColorU32(c::element::info_bar::filling));
//
//        ImGui::Begin(("##NOTIFY" + std::to_string(position)).c_str(), nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoFocusOnAppearing);
//        {
//            ImVec2 pos = ImGui::GetWindowPos();
//
//            PushStyleVar(ImGuiStyleVar_Alpha, 0.1f);
//            GetForegroundDrawList()->AddRectFilled(pos + ImVec2(0, 0), pos + ImVec2(GetContentRegionMax().x * (duePercentage / 100.0f), GetContentRegionMax().y), ImGui::GetColorU32(color), c::element::rounding - 2);
//            PopStyleVar();
//
//            edited::RenderTextColor(font::icomoon, pos + ImVec2(0, 0), pos + ImVec2(40, 40), GetColorU32(color), icon.c_str(), ImVec2(0.52f, 0.52f));
//            edited::RenderTextColor(font::inter_medium_widget, pos + ImVec2(40, 0), pos + ImVec2(GetContentRegionMax().x, 40), GetColorU32(color), message.c_str(), ImVec2(0.0f, 0.5f));
//            edited::RenderTextColor(font::inter_medium_widget, pos + ImVec2(CalcTextSize(message.c_str()).x + 45, 0), pos + ImVec2(GetContentRegionMax().x, 40), GetColorU32(c::element::text_active), information.c_str(), ImVec2(0.0f, 0.5f));
//
//        }
//        End();
//
//        PopStyleColor(1);
//        PopStyleVar(2);
//    }
//};
//
//typedef void (*myFun)(void);
//bool menu = true;
//NotificationSystem notificationSystem;
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//int CreateWindow_Violet(LPCSTR class_name, myFun CallBack, myFun CallBack2);
//
//bool CreateDeviceD3D(HWND hWnd)
//{
//    DXGI_SWAP_CHAIN_DESC sd;
//    ZeroMemory(&sd, sizeof(sd));
//    sd.BufferCount = 2;
//    sd.BufferDesc.Width = 0;
//    sd.BufferDesc.Height = 0;
//    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//    sd.BufferDesc.RefreshRate.Numerator = 0;
//    sd.BufferDesc.RefreshRate.Denominator = 1;
//    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
//    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//    sd.OutputWindow = hWnd;
//    sd.SampleDesc.Count = 1;
//    sd.SampleDesc.Quality = 0;
//    sd.Windowed = TRUE;
//    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//
//    UINT createDeviceFlags = 0;
//
//    D3D_FEATURE_LEVEL featureLevel;
//    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
//    HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
//    if (res == DXGI_ERROR_UNSUPPORTED)
//        res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
//    if (res != S_OK)
//        return false;
//
//    CreateRenderTarget();
//    return true;
//}
//
//void CleanupDeviceD3D()
//{
//    CleanupRenderTarget();
//    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = nullptr; }
//    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = nullptr; }
//    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
//}
//
//void CreateRenderTarget()
//{
//    ID3D11Texture2D* pBackBuffer;
//    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
//    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &g_mainRenderTargetView);
//    pBackBuffer->Release();
//}
//
//void CleanupRenderTarget()
//{
//    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = nullptr; }
//}
//
//extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
//
//LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
//        return true;
//
//    switch (msg)
//    {
//    case WM_CREATE:
//    {
//        MARGINS Margin = { -1 };
//        DwmExtendFrameIntoClientArea(hWnd, &Margin);
//        break;
//    }
//    case WM_SIZE:
//        if (wParam == SIZE_MINIMIZED)
//            return 0;
//        g_ResizeWidth = (UINT)LOWORD(lParam);
//        g_ResizeHeight = (UINT)HIWORD(lParam);
//        return 0;
//    case WM_SYSCOMMAND:
//        if ((wParam & 0xfff0) == SC_KEYMENU)
//            return 0;
//        break;
//    case WM_DESTROY:
//        ::PostQuitMessage(0);
//        return 0;
//        // 确保窗口始终保持在最上层
//    case WM_WINDOWPOSCHANGED:
//    {
//        WINDOWPOS* wp = (WINDOWPOS*)lParam;
//        // 如果不是由于我们自己设置而改变位置，则重新设置为最上层
//        if (!(wp->flags & SWP_NOMOVE) || !(wp->flags & SWP_NOSIZE)) {
//            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
//        }
//        break;
//    }
//    }
//    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
//}
//
//HWND FindNvidiaOverlayWindow() {
//    // 窗口标题和类名使用数组存储，避免枚举
//    const char* titles[] = {
//        "NVIDIA GeForce Overlay",
//        "NVIDIA Share",
//        "NVIDIA Overlay",
//        "ShadowPlay Overlay"
//    };
//
//    const char* classes[] = {
//        "CEF-OSC-WIDGET",
//        "NVIDIA Share",
//        "NvFBCOverlayWindow"
//    };
//
//    for (size_t i = 0; i < sizeof(titles) / sizeof(titles[0]); i++) {
//        for (size_t j = 0; j < sizeof(classes) / sizeof(classes[0]); j++) {
//            HWND hwnd = FindWindowA(classes[j], titles[i]);
//            if (hwnd && IsWindowVisible(hwnd)) {
//                return hwnd;
//            }
//        }
//    }
//    return nullptr;
//}
//
//void SetupOverlayWindow(HWND hwnd) {
//    if (!hwnd) return;
//
//    // 设置窗口为透明且最上层
//    SetWindowLongA(hwnd, GWL_EXSTYLE, GetWindowLongA(hwnd, GWL_EXSTYLE) |
//        WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST);
//
//    // 设置透明属性
//    SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);
//
//    // 确保窗口在最顶层
//    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
//    
//    // 扩展窗口到客户区
//    MARGINS margins = { -1 };
//    DwmExtendFrameIntoClientArea(hwnd, &margins);
//}
//
////inline int Width{};
////inline int Height{};
//
//inline int Width{};
//inline int Height{};
//
//int CreateWindow_Violet(LPCSTR class_name, myFun CallBack, myFun CallBack2)
//{
//    //这个函数 按步骤输出一下 看看走到哪里了   你写调试
//    //EnumSystemProcessWindows();
//    //windowinfo randomSysWindow = GetRandomSystemWindow();
//
//    wchar_t sysClassName[512] = L"ASSASAS";
//    wchar_t sysTitleName[1024] = L"系统窗口";  // 基础默认值
//
//    //// 处理类名（保持不变）
//    //if (randomSysWindow.ClassName && randomSysWindow.ClassName[0] != '\0') {
//    //    MultiByteToWideChar(CP_ACP, 0, randomSysWindow.ClassName, -1, sysClassName, _countof(sysClassName));
//    //}
//
//    //// 处理标题：优先使用系统窗口标题，过滤路径类标题
//    //bool useWindowTitle = false;
//    //if (randomSysWindow.TitleName && randomSysWindow.TitleName[0] != '\0') {
//    //    int titleLen = MultiByteToWideChar(CP_ACP, 0, randomSysWindow.TitleName, -1, nullptr, 0);
//    //    if (titleLen > 1) {
//    //        wchar_t tempTitle[1024] = { 0 };
//    //        MultiByteToWideChar(CP_ACP, 0, randomSysWindow.TitleName, -1, tempTitle, _countof(tempTitle));
//
//    //        // 若标题不是路径格式，才使用
//    //        if (!IsPathLikeTitle(tempTitle)) {
//    //            wcscpy_s(sysTitleName, tempTitle);
//    //            useWindowTitle = true;
//    //        }
//    //    }
//    //}
//
//    //// 标题无效时，使用进程名（增强容错）
//    //if (!useWindowTitle && randomSysWindow.hwnd) {
//    //    std::wstring procName = GetProcessNameFromHWND(randomSysWindow.hwnd);
//    //    if (!procName.empty() && procName != L"未知进程") {
//    //        wcscpy_s(sysTitleName, procName.c_str());
//    //    }
//    //}
//
//    //// 最终兜底：若所有逻辑都失败，强制使用非路径默认值
//    //if (IsPathLikeTitle(sysTitleName) || sysTitleName[0] == L'\0') {
//    //    wcscpy_s(sysTitleName, L"系统窗口");
//    //}
//    // 后续窗口创建代码保持不变...
//    //这样应该就可以了 这玩意好像 什么看不到  就是我远程别人电脑 看不到这个绘制  应该没问题 之前看不到可能是你加载了那个驱动的隐藏窗口之类的东西 好的 我去试试
//    Dx11Data::ScreenWidth = GetSystemMetrics(SM_CXSCREEN);
//    Dx11Data::ScreenHeight = GetSystemMetrics(SM_CYSCREEN);
//    Dx11Data::ScreenX = Dx11Data::ScreenWidth / 2;
//    Dx11Data::ScreenY = Dx11Data::ScreenHeight / 2;
//
//
//    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, sysTitleName, nullptr };
//    ::RegisterClassExW(&wc);
//    HWND hwnd = ::CreateWindowW(wc.lpszClassName, sysClassName, WS_POPUP, 0, 0, Dx11Data::ScreenWidth, Dx11Data::ScreenHeight, nullptr, nullptr, wc.hInstance, nullptr);
//
//    if (!CreateDeviceD3D(hwnd))
//    {
//        CleanupDeviceD3D();
//        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
//        return 1;
//    }
//
//    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
//    ::UpdateWindow(hwnd);
//
//    // 再次确保窗口在最上层
//    //SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
//
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO(); (void)io;
//
//    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
//    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
//
//    ImFontConfig cfg;
//    cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_LightHinting | ImGuiFreeTypeBuilderFlags_LoadColor | ImGuiFreeTypeBuilderFlags_Bitmap;
//
//    font::chinese = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
//    font::inter_medium_widget = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
//    font::inter_medium_small = io.Fonts->AddFontFromMemoryTTF(inter_medium, sizeof(inter_medium), 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//    font::inter_medium_big = io.Fonts->AddFontFromMemoryTTF(inter_bold, sizeof(inter_bold), 25.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//    font::inter_bold = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
//    font::icomoon = io.Fonts->AddFontFromMemoryTTF(icomoon, sizeof(icomoon), 17.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//    font::icomoon_default = io.Fonts->AddFontFromMemoryTTF(icomoon, sizeof(icomoon), 20.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//
//    ImGui_ImplWin32_Init(hwnd);
//    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
//
//    // 加载图片使用常量路径
//    GImGuiTextureMap[ARROW_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, ARROW_ICON_PATH);
//    GImGuiTextureMap[ARMOR_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, ARMOR_ICON_PATH);
//    GImGuiTextureMap[HELMET_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, HELMET_ICON_PATH);
//
//    // 加载Hub图标
//    std::vector<ImageInfo> images;
//    if (TextureFileUtils::LoadItemsFromBin_NoHeader(HUB_ICONS_BIN, images)) {
//        Utils::Log(1, "图片资源加载成功,共:%d张图片", images.size());
//    }
//    else {
//        Utils::Log(2, "图片资源加载失败！");
//    }
//    for (auto& entry : images)
//    {
//        auto& item = g_items[entry.itemId];
//        item.OVerlaycon = nullptr;
//        if (!entry.data.empty())
//        {
//            auto imageData = Texture::LoadTextureFromMemory(g_pd3dDevice, entry.data);
//            if (imageData.Texture != nullptr)
//            {
//                item.OVerlaycon = imageData.Texture;
//                item.Width = imageData.Width;
//                item.Height = imageData.Height;
//            }
//        }
//    }
//
//    // 加载武器图标
//    std::vector<ImageInfo> images1;
//    if (TextureFileUtils::LoadItemsFromBin_NoHeader(WEAPON_ICONS_BIN, images1)) {
//        Utils::Log(1, "图片资源2加载成功,共:%d张图片", images1.size());
//    }
//    else {
//        Utils::Log(2, "图片资源2加载失败!");
//    }
//    for (auto& entry : images1)
//    {
//        auto& item = WeaponIndexMap[entry.itemId];
//        if (!entry.data.empty())
//        {
//            auto imageData = Texture::LoadTextureFromMemory(g_pd3dDevice, entry.data);
//            if (imageData.Texture != nullptr)
//            {
//                WeaponStruct data;
//                data.OVerlaycon = imageData.Texture;
//                data.Height = imageData.Height;
//                data.Width = imageData.Width;
//                data.name = item;
//                DrawWeaponList[entry.itemId] = data;
//            }
//        }
//    }
//
//    // 初始化系统进程窗口枚举
//   // EnumSystemProcessWindows();
//    //Drv_HideWnd((ULONG64)hwnd);
//    bool done = false;
//    while (!done)
//    {
//        MSG msg;
//        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
//        {
//            ::TranslateMessage(&msg);
//            ::DispatchMessage(&msg);
//            if (msg.message == WM_QUIT)
//                done = true;
//        }
//        if (done)
//            break;
//
//        POINT Point{};
//        RECT Rect{};
//
//        gamewindow.hwnd = FindWindowA(class_name, NULL);
//        GetClientRect(gamewindow.hwnd, &Rect);
//        ClientToScreen(gamewindow.hwnd, &Point);
//
//        mywindow.pos = gamewindow.pos = ImVec2((float)Point.x, (float)Point.y);
//        mywindow.size = gamewindow.size = ImVec2((float)Rect.right, (float)Rect.bottom);
//
//        //// 移动窗口时保持最上层
//        //SetWindowPos(hwnd, HWND_TOPMOST, (int)mywindow.pos.x, (int)mywindow.pos.y,
//        //    (int)mywindow.size.x, (int)mywindow.size.y, SWP_SHOWWINDOW);
//
//        POINT MousePos;
//        GetCursorPos(&MousePos);
//        ScreenToClient(hwnd, &MousePos);
//        ImGui::GetIO().MousePos.x = (float)MousePos.x;
//        ImGui::GetIO().MousePos.y = (float)MousePos.y;
//
//        //if (ImGui::GetIO().WantCaptureMouse)
//        //{
//        //    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) & (~WS_EX_LAYERED));
//        //}
//        //else
//        //{
//        //    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
//        //}
//        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
//        {
//            CleanupRenderTarget();
//            g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
//            g_ResizeWidth = g_ResizeHeight = 0;
//            CreateRenderTarget();
//        }
//
//        ImGui_ImplDX11_NewFrame();
//        ImGui_ImplWin32_NewFrame();
//        ImGui::NewFrame();
//        {
//            notificationSystem.DrawNotifications();
//            CallBack();
//            CallBack2();
//        }
//        ImGui::Render();
//        const float clear_color_with_alpha[4] = { 0.f, 0.f, 0.f, 1.f };//填充背景改成黑色就行了 你该
//        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
//        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
//        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
//
//        g_pSwapChain->Present(1, 0); // Present with vsync
//    }
//
//    // 清理系统进程窗口信息
//    for (auto& win : system_process_windows) {
//        free((void*)win.ClassName);
//        free((void*)win.TitleName);
//    }
//    system_process_windows.clear();
//
//    ImGui_ImplDX11_Shutdown();
//    ImGui_ImplWin32_Shutdown();
//    ImGui::DestroyContext();
//
//    CleanupDeviceD3D();
//    ::DestroyWindow(hwnd);
//    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
//
//    return 0;
//}
//
///*int CreateWindow_Violet(LPCSTR class_name, myFun CallBack, myFun CallBack2)
//{
//    EnumSystemProcessWindows();
//    windowinfo randomSysWindow = GetRandomSystemWindow();
//
//    wchar_t sysClassName[512] = L"ASSASAS";
//    wchar_t sysTitleName[1024] = L"系统窗口";  // 基础默认值
//
//    // 处理类名（保持不变）
//    if (randomSysWindow.ClassName && randomSysWindow.ClassName[0] != '\0') {
//        MultiByteToWideChar(CP_ACP, 0, randomSysWindow.ClassName, -1, sysClassName, _countof(sysClassName));
//    }
//
//    // 处理标题：优先使用系统窗口标题，过滤路径类标题
//    bool useWindowTitle = false;
//    if (randomSysWindow.TitleName && randomSysWindow.TitleName[0] != '\0') {
//        int titleLen = MultiByteToWideChar(CP_ACP, 0, randomSysWindow.TitleName, -1, nullptr, 0);
//        if (titleLen > 1) {
//            wchar_t tempTitle[1024] = { 0 };
//            MultiByteToWideChar(CP_ACP, 0, randomSysWindow.TitleName, -1, tempTitle, _countof(tempTitle));
//
//            // 若标题不是路径格式，才使用
//            if (!IsPathLikeTitle(tempTitle)) {
//                wcscpy_s(sysTitleName, tempTitle);
//                useWindowTitle = true;
//            }
//        }
//    }
//
//    // 标题无效时，使用进程名（增强容错）
//    if (!useWindowTitle && randomSysWindow.hwnd) {
//        std::wstring procName = GetProcessNameFromHWND(randomSysWindow.hwnd);
//        if (!procName.empty() && procName != L"未知进程") {
//            wcscpy_s(sysTitleName, procName.c_str());
//        }
//    }
//
//    // 最终兜底：若所有逻辑都失败，强制使用非路径默认值
//    if (IsPathLikeTitle(sysTitleName) || sysTitleName[0] == L'\0') {
//        wcscpy_s(sysTitleName, L"系统窗口");
//    }
//    // 后续窗口创建代码保持不变...
//    WNDCLASSEXW wc = { sizeof(WNDCLASSEXW), CS_CLASSDC, WndProc, 0L, 0L,
//                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
//                      sysTitleName, NULL };
//    ::RegisterClassExW(&wc);
//
//    HWND hwnd = ::CreateWindowExW(
//        WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW,
//        wc.lpszClassName,
//        sysClassName,  // 使用处理后的标题
//        WS_POPUP,
//        100, 100, 1280, 800,
//        nullptr, nullptr, wc.hInstance, nullptr
//    );
//
//    if (!CreateDeviceD3D(hwnd))
//    {
//        CleanupDeviceD3D();
//        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
//        return 1;
//    }
//
//    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
//    ::UpdateWindow(hwnd);
//
//    // 再次确保窗口在最上层
//    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
//
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//    ImGuiIO& io = ImGui::GetIO(); (void)io;
//
//    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
//    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
//
//    ImFontConfig cfg;
//    cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_LightHinting | ImGuiFreeTypeBuilderFlags_LoadColor | ImGuiFreeTypeBuilderFlags_Bitmap;
//
//    font::chinese = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
//    font::inter_medium_widget = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
//    font::inter_medium_small = io.Fonts->AddFontFromMemoryTTF(inter_medium, sizeof(inter_medium), 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//    font::inter_medium_big = io.Fonts->AddFontFromMemoryTTF(inter_bold, sizeof(inter_bold), 25.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//    font::inter_bold = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
//    font::icomoon = io.Fonts->AddFontFromMemoryTTF(icomoon, sizeof(icomoon), 17.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//    font::icomoon_default = io.Fonts->AddFontFromMemoryTTF(icomoon, sizeof(icomoon), 20.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
//
//    ImGui_ImplWin32_Init(hwnd);
//    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);
//
//    // 加载图片使用常量路径
//    GImGuiTextureMap[ARROW_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, ARROW_ICON_PATH);
//    GImGuiTextureMap[ARMOR_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, ARMOR_ICON_PATH);
//    GImGuiTextureMap[HELMET_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, HELMET_ICON_PATH);
//
//    // 加载Hub图标
//    std::vector<ImageInfo> images;
//    if (TextureFileUtils::LoadItemsFromBin_NoHeader(HUB_ICONS_BIN, images)) {
//        Utils::Log(1, "图片资源加载成功,共:%d张图片", images.size());
//    }
//    else {
//        Utils::Log(2, "图片资源加载失败！");
//    }
//    for (auto& entry : images)
//    {
//        auto& item = g_items[entry.itemId];
//        item.OVerlaycon = nullptr;
//        if (!entry.data.empty())
//        {
//            auto imageData = Texture::LoadTextureFromMemory(g_pd3dDevice, entry.data);
//            if (imageData.Texture != nullptr)
//            {
//                item.OVerlaycon = imageData.Texture;
//                item.Width = imageData.Width;
//                item.Height = imageData.Height;
//            }
//        }
//    }
//
//    // 加载武器图标
//    std::vector<ImageInfo> images1;
//    if (TextureFileUtils::LoadItemsFromBin_NoHeader(WEAPON_ICONS_BIN, images1)) {
//        Utils::Log(1, "图片资源2加载成功,共:%d张图片", images1.size());
//    }
//    else {
//        Utils::Log(2, "图片资源2加载失败!");
//    }
//    for (auto& entry : images1)
//    {
//        auto& item = WeaponIndexMap[entry.itemId];
//        if (!entry.data.empty())
//        {
//            auto imageData = Texture::LoadTextureFromMemory(g_pd3dDevice, entry.data);
//            if (imageData.Texture != nullptr)
//            {
//                WeaponStruct data;
//                data.OVerlaycon = imageData.Texture;
//                data.Height = imageData.Height;
//                data.Width = imageData.Width;
//                data.name = item;
//                DrawWeaponList[entry.itemId] = data;
//            }
//        }
//    }
//
//    // 初始化系统进程窗口枚举
//    EnumSystemProcessWindows();
//   // Drv_HideWnd((ULONG64)hwnd);
//    bool done = false;
//    while (!done)
//    {
//        MSG msg;
//        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
//        {
//            ::TranslateMessage(&msg);
//            ::DispatchMessage(&msg);
//            if (msg.message == WM_QUIT)
//                done = true;
//        }
//        if (done)
//            break;
//
//        POINT Point{};
//        RECT Rect{};
//
//        gamewindow.hwnd = FindWindowA(class_name, NULL);
//        GetClientRect(gamewindow.hwnd, &Rect);
//        ClientToScreen(gamewindow.hwnd, &Point);
//
//        mywindow.pos = gamewindow.pos = ImVec2((float)Point.x, (float)Point.y);
//        mywindow.size = gamewindow.size = ImVec2((float)Rect.right, (float)Rect.bottom);
//
//        // 移动窗口时保持最上层
//        SetWindowPos(hwnd, HWND_TOPMOST, (int)mywindow.pos.x, (int)mywindow.pos.y,
//            (int)mywindow.size.x, (int)mywindow.size.y, SWP_SHOWWINDOW);
//
//        POINT MousePos;
//        GetCursorPos(&MousePos);
//        ScreenToClient(hwnd, &MousePos);
//        ImGui::GetIO().MousePos.x = (float)MousePos.x;
//        ImGui::GetIO().MousePos.y = (float)MousePos.y;
//
//        if (ImGui::GetIO().WantCaptureMouse)
//        {
//            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) & (~WS_EX_LAYERED));
//        }
//        else
//        {
//            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
//        }
//        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
//        {
//            CleanupRenderTarget();
//            g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
//            g_ResizeWidth = g_ResizeHeight = 0;
//            CreateRenderTarget();
//        }
//
//        ImGui_ImplDX11_NewFrame();
//        ImGui_ImplWin32_NewFrame();
//        ImGui::NewFrame();
//        {
//            notificationSystem.DrawNotifications();
//            CallBack();
//            CallBack2();
//        }
//        ImGui::Render();
//        const float clear_color_with_alpha[4] = { 0.f, 0.f, 0.f, 0.f };
//        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
//        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
//        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
//
//        g_pSwapChain->Present(1, 0); // Present with vsync
//    }
//
//    // 清理系统进程窗口信息
//    for (auto& win : system_process_windows) {
//        free((void*)win.ClassName);
//        free((void*)win.TitleName);
//    }
//    system_process_windows.clear();
//
//    ImGui_ImplDX11_Shutdown();
//    ImGui_ImplWin32_Shutdown();
//    ImGui::DestroyContext();
//
//    CleanupDeviceD3D();
//    ::DestroyWindow(hwnd);
//    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
//
//    return 0;
//}*/
//
//#endif

#define MATH_OPERATORS
#ifndef GUI_HPP
#define GUI_HPP

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>

#include "imgui_edited.hpp"
#include "textures.h"
#include "font.h"

#include <chrono>
#include <algorithm>
#include <functional>
#include <vector>
#include <random>
#include <math.h>
#include <dwmapi.h>
#include "Dx11/Texture.h"
#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>

#pragma comment(lib, "psapi.lib")

// 常量定义 - 替代枚举使用（保留原始定义）
constexpr int MAX_CHECKBOXES = 40;
constexpr int MAX_SLIDERS = 40;
constexpr int MAX_KEYS = 40;
constexpr int MAX_SELECTS = 40;
constexpr int MAX_COLORS = 16;
constexpr int PAGE_COUNT = 5;

// 资源路径常量（保留原始路径）
const std::string ARROW_ICON_PATH = "Assets/arrow.png";
const std::string ARMOR_ICON_PATH = "Assets/Armor.png";
const std::string HELMET_ICON_PATH = "Assets/Helmet.png";
const std::string HUB_ICONS_BIN = "Assets/Hub/icons.bin";
const std::string WEAPON_ICONS_BIN = "Assets/Weapon/icons1.bin";

// 测试描述文本（保留原始内容）
std::string description_test = "Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.";

// 窗口信息结构体（保留原始成员）
struct windowinfo
{
    HWND hwnd = nullptr;					//窗口句柄
    LPCSTR ClassName = nullptr;		//窗口类名
    LPCSTR TitleName = nullptr;		//窗口标题名
    ImVec2 pos = { 0,0 };					//窗口位置
    ImVec2 size = { 0,0 };				//窗口尺寸
};
inline windowinfo mywindow;		//透明窗口的窗口信息
inline windowinfo gamewindow;		//游戏窗口的窗口信息

// 系统进程窗口相关变量（保留原始声明）
inline std::vector<windowinfo> system_process_windows;  // 存储系统进程窗口
inline std::random_device rd;
inline std::mt19937 rng(rd());

// 系统进程名称列表（保留原始列表）
const std::vector<std::wstring> system_process_names = {
    L"csrss.exe",
    L"wininit.exe",
    L"services.exe",
    L"lsass.exe",
    L"svchost.exe",
    L"explorer.exe",
    L"taskhostw.exe",
    L"dwm.exe",
    L"RuntimeBroker.exe",
    L"smss.exe",
    L"audiodg.exe",
    L"spoolsv.exe"
};

// 纹理资源命名空间（保留原始声明，未定义实现）
namespace texture
{
    ID3D11ShaderResourceView* preview = nullptr;
    ID3D11ShaderResourceView* ragebot = nullptr;
    ID3D11ShaderResourceView* legitbot = nullptr;
    ID3D11ShaderResourceView* visuals = nullptr;
    ID3D11ShaderResourceView* misc = nullptr;
    ID3D11ShaderResourceView* world = nullptr;
    ID3D11ShaderResourceView* settings = nullptr;
}

// 变量命名空间（保留原始定义及可能的未初始化问题）
namespace var
{
    static float tab_alpha = 0.f; /* */ static float tab_add; /* */ static int active_tab = 0;

    bool interactive = false;
    float tab_right = 0, tab_left = 0;
    bool check[40], value[40];  // 未初始化数组
    float col0[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
    float col1[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
    float col2[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
    float col3[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
    float col4[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
    float col5[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
    float col6[4] = { 1.0f, 0.5f, 0.0f, 1.0f };
    float col7[4] = { 0.5f, 0.0f, 1.0f, 1.0f };
    float col8[4] = { 0.0f, 0.5f, 1.0f, 1.0f };
    float col9[4] = { 0.5f, 1.0f, 0.0f, 1.0f };
    float col10[4] = { 1.0f, 0.0f, 0.5f, 1.0f };
    float col11[4] = { 0.0f, 1.0f, 0.5f, 1.0f };
    float col12[4] = { 0.5f, 0.0f, 1.0f, 1.0f };
    float col13[4] = { 0.0f, 0.5f, 1.0f, 1.0f };
    float col14[4] = { 1.0f, 0.5f, 0.5f, 1.0f };
    float col15[4] = { 0.5f, 1.0f, 0.5f, 1.0f };
    int slider_value[40], key[40], m[40], select[40];  // 未初始化数组
    const char* pageNames[] = { U8("玩家"), U8("物品"),U8("自瞄"),U8("容器"),U8("杂项") };
    const ImVec2 buttonSize(125, 35);
    int page = 0;
}

// D3D设备相关全局变量（保留原始声明）
static ID3D11Device* g_pd3dDevice = nullptr;
static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
static IDXGISwapChain* g_pSwapChain = nullptr;
static UINT g_ResizeWidth = 0, g_ResizeHeight = 0;
static ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;

// 函数声明（保留原始顺序及可能的未实现问题）
inline bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void CreateRenderTarget();
void CleanupRenderTarget();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// 辅助函数：获取窗口所属进程名称（保留原始逻辑）
std::wstring GetProcessNameFromHWND(HWND hwnd) {
    DWORD processId = 0;
    GetWindowThreadProcessId(hwnd, &processId);
    if (processId == 0) {
        return L"未知进程"; // 进程ID获取失败
    }

    // 尝试以较低权限打开进程（可能因权限不足失败）
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, processId);
    if (hProcess == nullptr) {
        return L"进程ID:" + std::to_wstring(processId);
    }

    wchar_t processName[MAX_PATH] = L"";
    DWORD nameLen = sizeof(processName) / sizeof(wchar_t);
    if (GetProcessImageFileNameW(hProcess, processName, nameLen) == 0) {
        GetModuleBaseNameW(hProcess, nullptr, processName, nameLen);
    }
    CloseHandle(hProcess);

    wchar_t* fileName = wcsrchr(processName, L'\\');
    return fileName ? fileName + 1 : processName;
}

// 判断标题是否类似路径（保留原始实现）
bool IsPathLikeTitle(const wchar_t* title) {
    if (!title || title[0] == L'\0') return false;
    return (wcschr(title, L'\\') != nullptr) ||
        (wcschr(title, L'/') != nullptr) ||
        (wcslen(title) > 3 && title[1] == L':');
}

// 枚举窗口回调函数（保留原始逻辑）
BOOL CALLBACK EnumSystemWindowsProc(HWND hwnd, LPARAM lParam) {
    if (!IsWindowVisible(hwnd)) {
        return TRUE;
    }

    std::wstring processName = GetProcessNameFromHWND(hwnd);
    if (std::find(system_process_names.begin(), system_process_names.end(), processName) == system_process_names.end()) {
        return TRUE;
    }

    int titleLength = GetWindowTextLengthA(hwnd) + 1;
    char* titleBuffer = new char[titleLength];
    GetWindowTextA(hwnd, titleBuffer, titleLength);

    char classNameBuffer[256];
    GetClassNameA(hwnd, classNameBuffer, sizeof(classNameBuffer));

    RECT rect;
    GetWindowRect(hwnd, &rect);

    windowinfo info;
    info.hwnd = hwnd;
    info.ClassName = _strdup(classNameBuffer);  // 可能未释放内存
    info.TitleName = _strdup(titleBuffer);     // 可能未释放内存
    info.pos = ImVec2((float)rect.left, (float)rect.top);
    info.size = ImVec2((float)(rect.right - rect.left), (float)(rect.bottom - rect.top));

    system_process_windows.push_back(info);

    delete[] titleBuffer;
    return TRUE;
}

// 枚举所有系统进程窗口（保留原始实现）
void EnumSystemProcessWindows() {
    for (auto& win : system_process_windows) {
        free((void*)win.ClassName);
        free((void*)win.TitleName);
    }
    system_process_windows.clear();
    EnumWindows(EnumSystemWindowsProc, 0);
}

// 随机获取一个系统进程窗口信息（保留原始实现）
//windowinfo GetRandomSystemWindow() {
//    static bool initialized = false;
//    if (!initialized || system_process_windows.empty()) {
//        EnumSystemProcessWindows();
//        initialized = true;
//    }
//
//    if (system_process_windows.empty()) {
//        return windowinfo{};
//    }
//
//    std::uniform_int_distribution<int> dist(0, system_process_windows.size() - 1);
//    int index = dist(rng);
//    return system_process_windows[index];
windowinfo GetRandomSystemWindow() {  // 函数名缩短去语义化
    static bool init_flag = false;  // 变量名替换
    if (!init_flag || system_process_windows.empty()) {  // 容器名替换
        EnumSystemProcessWindows();  // 枚举函数名调整
        init_flag = true;
    }

    if (system_process_windows.empty()) {  // 容器名替换
        return windowinfo{};
    }

    // 随机分布器变量名修改，保持原有int类型（可能存在的类型不匹配问题保留）
    std::uniform_int_distribution<int> rnd_dist(0, system_process_windows.size() - 1);
    int rnd_idx = rnd_dist(rng);  // 随机数生成器名替换
    return system_process_windows[rnd_idx];  // 容器名替换
}

//}

// 通知结构体（保留原始定义）
struct Notification {
    int id;
    std::string icon, message, information;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    ImU32 color;
};

// 通知系统类（保留原始实现及可能的未定义引用）
class NotificationSystem {
public:
    NotificationSystem() : notificationIdCounter(0) {}

    void AddNotification(const std::string& icon, const std::string& information, const std::string& message, int durationMs, ImU32 color) {
        auto now = std::chrono::steady_clock::now();
        auto endTime = now + std::chrono::milliseconds(durationMs);
        notifications.push_back({ notificationIdCounter++, icon, information, message, now, endTime, color });
    }

    void DrawNotifications() {
        auto now = std::chrono::steady_clock::now();

        std::sort(notifications.begin(), notifications.end(),
            [now](const Notification& a, const Notification& b) -> bool {
                float durationA = std::chrono::duration_cast<std::chrono::milliseconds>(a.endTime - a.startTime).count();
                float elapsedA = std::chrono::duration_cast<std::chrono::milliseconds>(now - a.startTime).count();
                float percentageA = (durationA - elapsedA) / durationA;

                float durationB = std::chrono::duration_cast<std::chrono::milliseconds>(b.endTime - b.startTime).count();
                float elapsedB = std::chrono::duration_cast<std::chrono::milliseconds>(now - b.startTime).count();
                float percentageB = (durationB - elapsedB) / durationB;

                return percentageA < percentageB;
            }
        );

        int currentNotificationPosition = 0;

        for (auto& notification : notifications) {
            if (now < notification.endTime) {
                float duration = std::chrono::duration_cast<std::chrono::milliseconds>(notification.endTime - notification.startTime).count();
                float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - notification.startTime).count();
                float percentage = (duration - elapsed) / duration * 100.0f;

                ShowNotification(currentNotificationPosition, notification.icon, notification.information, notification.message, percentage, notification.color);
                currentNotificationPosition++;
            }
        }

        notifications.erase(std::remove_if(notifications.begin(), notifications.end(),
            [now](const Notification& notification) { return now >= notification.endTime; }),
            notifications.end());
    }

private:
    std::vector<Notification> notifications;
    int notificationIdCounter;

    void ShowNotification(int position, const std::string& icon, const std::string& information, const std::string& message, float percentage, ImU32 color) {
        float duePercentage = 100.0f - percentage;
        float alpha = percentage > 10.0f ? 1.0f : percentage / 10.0f;

        PushFont(font::inter_medium_widget);  // 未定义的PushFont和font::inter_medium_widget
        SetNextWindowPos(ImVec2(GetIO().DisplaySize.x - (CalcTextSize(message.c_str()).x + CalcTextSize(information.c_str()).x + 70), 15 + (position * 55)), ImGuiCond_Always);
        SetNextWindowSize(ImVec2(CalcTextSize(message.c_str()).x + CalcTextSize(information.c_str()).x + 60, 40));
        PopFont();  // 未定义的PopFont

        PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));  // 可能未定义的PushStyleVar
        PushStyleVar(ImGuiStyleVar_WindowRounding, 6.f);
        PushStyleColor(ImGuiCol_WindowBg, GetColorU32(c::element::info_bar::filling));  // 未定义的c::element

        ImGui::Begin(("##NOTIFY" + std::to_string(position)).c_str(), nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoFocusOnAppearing);
        {
            ImVec2 pos = ImGui::GetWindowPos();

            PushStyleVar(ImGuiStyleVar_Alpha, 0.1f);
            GetForegroundDrawList()->AddRectFilled(pos + ImVec2(0, 0), pos + ImVec2(GetContentRegionMax().x * (duePercentage / 100.0f), GetContentRegionMax().y), ImGui::GetColorU32(color), c::element::rounding - 2);  // 未定义的c::element::rounding
            PopStyleVar();

            edited::RenderTextColor(font::icomoon, pos + ImVec2(0, 0), pos + ImVec2(40, 40), GetColorU32(color), icon.c_str(), ImVec2(0.52f, 0.52f));  // 未定义的edited和font::icomoon
            edited::RenderTextColor(font::inter_medium_widget, pos + ImVec2(40, 0), pos + ImVec2(GetContentRegionMax().x, 40), GetColorU32(color), message.c_str(), ImVec2(0.0f, 0.5f));
            edited::RenderTextColor(font::inter_medium_widget, pos + ImVec2(CalcTextSize(message.c_str()).x + 45, 0), pos + ImVec2(GetContentRegionMax().x, 40), GetColorU32(c::element::text_active), information.c_str(), ImVec2(0.0f, 0.5f));  // 未定义的c::element::text_active
        }
        End();  // 未明确的End()是否为ImGui::End()

        PopStyleColor(1);
        PopStyleVar(2);
    }
};

// 函数指针及全局变量（保留原始声明）
typedef void (*myFun)(void);
bool menu = true;
NotificationSystem notificationSystem;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CreateWindow_Violet(LPCSTR class_name, myFun CallBack, myFun CallBack2);

// D3D设备创建（保留原始实现）
bool CreateDeviceD3D(HWND hWnd)
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferCount = 2;
    sd.BufferDesc.Width = 0;
    sd.BufferDesc.Height = 0;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 0;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    UINT createDeviceFlags = 0;

    D3D_FEATURE_LEVEL featureLevel;
    const D3D_FEATURE_LEVEL featureLevelArray[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_0, };
    HRESULT res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
    if (res == DXGI_ERROR_UNSUPPORTED)
        res = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_WARP, nullptr, createDeviceFlags, featureLevelArray, 2, D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &featureLevel, &g_pd3dDeviceContext);
    if (res != S_OK)
        return false;

    CreateRenderTarget();
    return true;
}

// D3D设备清理（保留原始实现）
void CleanupDeviceD3D()
{
    CleanupRenderTarget();
    if (g_pSwapChain) { g_pSwapChain->Release(); g_pSwapChain = nullptr; }
    if (g_pd3dDeviceContext) { g_pd3dDeviceContext->Release(); g_pd3dDeviceContext = nullptr; }
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = nullptr; }
}

// 创建渲染目标（保留原始实现）
void CreateRenderTarget()
{
    ID3D11Texture2D* pBackBuffer;
    g_pSwapChain->GetBuffer(0, IID_PPV_ARGS(&pBackBuffer));
    g_pd3dDevice->CreateRenderTargetView(pBackBuffer, nullptr, &g_mainRenderTargetView);
    pBackBuffer->Release();
}

// 清理渲染目标（保留原始实现）
void CleanupRenderTarget()
{
    if (g_mainRenderTargetView) { g_mainRenderTargetView->Release(); g_mainRenderTargetView = nullptr; }
}

// ImGui窗口过程处理（保留原始实现）
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_CREATE:
    {
        MARGINS Margin = { -1 };
        DwmExtendFrameIntoClientArea(hWnd, &Margin);
        break;
    }
    case WM_SIZE:
        if (wParam == SIZE_MINIMIZED)
            return 0;
        g_ResizeWidth = (UINT)LOWORD(lParam);
        g_ResizeHeight = (UINT)HIWORD(lParam);
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU)
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    case WM_WINDOWPOSCHANGED:  // 可能的逻辑错误：频繁设置最上层
    {
        WINDOWPOS* wp = (WINDOWPOS*)lParam;
        if (!(wp->flags & SWP_NOMOVE) || !(wp->flags & SWP_NOSIZE)) {
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
        }
        break;
    }
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}

// 查找NVIDIA覆盖窗口（保留原始实现）
HWND FindNvidiaOverlayWindow() {
    const char* titles[] = {
        "NVIDIA GeForce Overlay",
        "NVIDIA Share",
        "NVIDIA Overlay",
        "ShadowPlay Overlay"
    };

    const char* classes[] = {
        "CEF-OSC-WIDGET",
        "NVIDIA Share",
        "NvFBCOverlayWindow"
    };

    for (size_t i = 0; i < sizeof(titles) / sizeof(titles[0]); i++) {
        for (size_t j = 0; j < sizeof(classes) / sizeof(classes[0]); j++) {
            HWND hwnd = FindWindowA(classes[j], titles[i]);
            if (hwnd && IsWindowVisible(hwnd)) {
                return hwnd;
            }
        }
    }
    return nullptr;
}

// 设置覆盖窗口属性（保留原始实现）
void SetupOverlayWindow(HWND hwnd) {
    if (!hwnd) return;

    SetWindowLongA(hwnd, GWL_EXSTYLE, GetWindowLongA(hwnd, GWL_EXSTYLE) |
        WS_EX_LAYERED | WS_EX_TRANSPARENT | WS_EX_TOPMOST);

    SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);

    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

    MARGINS margins = { -1 };
    DwmExtendFrameIntoClientArea(hwnd, &margins);
}

// 屏幕尺寸全局变量（保留原始重复定义）
inline int Width{};
//inline int Width{};  // 重复定义错误保留
inline int Height{};

int CreateWindow_Violet(LPCSTR class_name, myFun CallBack, myFun CallBack2)
{
    EnumSystemProcessWindows();
    windowinfo randomSysWindow = GetRandomSystemWindow();

    wchar_t sysClassName[512] = L"ASBASAB";
    wchar_t sysTitleName[1024] = L"系统窗口";  // 基础默认值

    // 处理类名（保持不变）
    if (randomSysWindow.ClassName && randomSysWindow.ClassName[0] != '\0') {
        MultiByteToWideChar(CP_ACP, 0, randomSysWindow.ClassName, -1, sysClassName, _countof(sysClassName));
    }

    // 处理标题：优先使用系统窗口标题，过滤路径类标题
    bool useWindowTitle = false;
    if (randomSysWindow.TitleName && randomSysWindow.TitleName[0] != '\0') {
        int titleLen = MultiByteToWideChar(CP_ACP, 0, randomSysWindow.TitleName, -1, nullptr, 0);
        if (titleLen > 1) {
            wchar_t tempTitle[1024] = { 0 };
            MultiByteToWideChar(CP_ACP, 0, randomSysWindow.TitleName, -1, tempTitle, _countof(tempTitle));

            // 若标题不是路径格式，才使用
            if (!IsPathLikeTitle(tempTitle)) {
                wcscpy_s(sysTitleName, tempTitle);
                useWindowTitle = true;
            }
        }
    }

    // 标题无效时，使用进程名（增强容错）
    if (!useWindowTitle && randomSysWindow.hwnd) {
        std::wstring procName = GetProcessNameFromHWND(randomSysWindow.hwnd);
        if (!procName.empty() && procName != L"未知进程") {
            wcscpy_s(sysTitleName, procName.c_str());
        }
    }

    // 最终兜底：若所有逻辑都失败，强制使用非路径默认值
    if (IsPathLikeTitle(sysTitleName) || sysTitleName[0] == L'\0') {
        wcscpy_s(sysTitleName, L"系统窗口");
    }
    // 后续窗口创建代码保持不变...
    WNDCLASSEXW wc = { sizeof(WNDCLASSEXW), CS_CLASSDC, WndProc, 0L, 0L,
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      sysTitleName, NULL };
    ::RegisterClassExW(&wc);

    HWND hwnd = ::CreateWindowExW(
        WS_EX_TOPMOST | WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW,
        wc.lpszClassName,
        sysClassName,  // 使用处理后的标题
        WS_POPUP,
        100, 100, 1280, 800,
        nullptr, nullptr, wc.hInstance, nullptr
    );

    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // 再次确保窗口在最上层
    SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

    ImFontConfig cfg;
    cfg.FontBuilderFlags = ImGuiFreeTypeBuilderFlags_ForceAutoHint | ImGuiFreeTypeBuilderFlags_LightHinting | ImGuiFreeTypeBuilderFlags_LoadColor | ImGuiFreeTypeBuilderFlags_Bitmap;

    font::chinese = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
    font::inter_medium_widget = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
    font::inter_medium_small = io.Fonts->AddFontFromMemoryTTF(inter_medium, sizeof(inter_medium), 14.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
    font::inter_medium_big = io.Fonts->AddFontFromMemoryTTF(inter_bold, sizeof(inter_bold), 25.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
    font::inter_bold = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\msyh.ttc", 16.0f, nullptr, io.Fonts->GetGlyphRangesChineseFull());
    font::icomoon = io.Fonts->AddFontFromMemoryTTF(icomoon, sizeof(icomoon), 17.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());
    font::icomoon_default = io.Fonts->AddFontFromMemoryTTF(icomoon, sizeof(icomoon), 20.f, &cfg, io.Fonts->GetGlyphRangesCyrillic());

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dDeviceContext);

    // 加载图片使用常量路径
    GImGuiTextureMap[ARROW_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, ARROW_ICON_PATH);
    GImGuiTextureMap[ARMOR_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, ARMOR_ICON_PATH);
    GImGuiTextureMap[HELMET_ICON_PATH] = Texture::LoadTexture(g_pd3dDevice, HELMET_ICON_PATH);

    // 加载Hub图标
    std::vector<ImageInfo> images;
    if (TextureFileUtils::LoadItemsFromBin_NoHeader(HUB_ICONS_BIN, images)) {
        Utils::Log(1, "图片资源加载成功,共:%d张图片", images.size());
    }
    else {
        Utils::Log(2, "图片资源加载失败！");
    }
    for (auto& entry : images)
    {
        auto& item = g_items[entry.itemId];
        item.OVerlaycon = nullptr;
        if (!entry.data.empty())
        {
            auto imageData = Texture::LoadTextureFromMemory(g_pd3dDevice, entry.data);
            if (imageData.Texture != nullptr)
            {
                item.OVerlaycon = imageData.Texture;
                item.Width = imageData.Width;
                item.Height = imageData.Height;
            }
        }
    }

    // 加载武器图标
    std::vector<ImageInfo> images1;
    if (TextureFileUtils::LoadItemsFromBin_NoHeader(WEAPON_ICONS_BIN, images1)) {
        Utils::Log(1, "图片资源2加载成功,共:%d张图片", images1.size());
    }
    else {
        Utils::Log(2, "图片资源2加载失败!");
    }
    for (auto& entry : images1)
    {
        auto& item = WeaponIndexMap[entry.itemId];
        if (!entry.data.empty())
        {
            auto imageData = Texture::LoadTextureFromMemory(g_pd3dDevice, entry.data);
            if (imageData.Texture != nullptr)
            {
                WeaponStruct data;
                data.OVerlaycon = imageData.Texture;
                data.Height = imageData.Height;
                data.Width = imageData.Width;
                data.name = item;
                DrawWeaponList[entry.itemId] = data;
            }
        }
    }

    // 初始化系统进程窗口枚举
    EnumSystemProcessWindows();
    Drv_HideWnd((ULONG64)hwnd);
    bool done = false;
    while (!done)
    {
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        POINT Point{};
        RECT Rect{};

        gamewindow.hwnd = FindWindowA(class_name, NULL);
        GetClientRect(gamewindow.hwnd, &Rect);
        ClientToScreen(gamewindow.hwnd, &Point);

        mywindow.pos = gamewindow.pos = ImVec2((float)Point.x, (float)Point.y);
        mywindow.size = gamewindow.size = ImVec2((float)Rect.right, (float)Rect.bottom);

        // 移动窗口时保持最上层
        SetWindowPos(hwnd, HWND_TOPMOST, (int)mywindow.pos.x, (int)mywindow.pos.y,
            (int)mywindow.size.x, (int)mywindow.size.y, SWP_SHOWWINDOW);

        POINT MousePos;
        GetCursorPos(&MousePos);
        ScreenToClient(hwnd, &MousePos);
        ImGui::GetIO().MousePos.x = (float)MousePos.x;
        ImGui::GetIO().MousePos.y = (float)MousePos.y;

        if (ImGui::GetIO().WantCaptureMouse)
        {
            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) & (~WS_EX_LAYERED));
        }
        else
        {
            SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
        }
        if (g_ResizeWidth != 0 && g_ResizeHeight != 0)
        {
            CleanupRenderTarget();
            g_pSwapChain->ResizeBuffers(0, g_ResizeWidth, g_ResizeHeight, DXGI_FORMAT_UNKNOWN, 0);
            g_ResizeWidth = g_ResizeHeight = 0;
            CreateRenderTarget();
        }

        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            notificationSystem.DrawNotifications();
            CallBack();
            CallBack2();
        }
        ImGui::Render();
        const float clear_color_with_alpha[4] = { 0.f, 0.f, 0.f, 0.f };
        g_pd3dDeviceContext->OMSetRenderTargets(1, &g_mainRenderTargetView, nullptr);
        g_pd3dDeviceContext->ClearRenderTargetView(g_mainRenderTargetView, clear_color_with_alpha);
        ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

        g_pSwapChain->Present(1, 0); // Present with vsync
    }

    // 清理系统进程窗口信息
    for (auto& win : system_process_windows) {
        free((void*)win.ClassName);
        free((void*)win.TitleName);
    }
    system_process_windows.clear();

    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}




#endif
