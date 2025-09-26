//#ifndef MENU_HPP
//#define MENU_HPP
//#include"Gui.h"
//#include"../MenuConfigs.hpp"
//inline void InitMenuStyle() {
//    static bool initialized = false;
//    if (initialized) return;
//    initialized = true;
//
//    ImGui::SetNextWindowSize(c::bg::size);
//    ImGuiStyle* style = &ImGui::GetStyle();
//
//    // 高科技浅蓝色风格样式设置
//    style->WindowPadding = ImVec2(10, 10);
//    style->ItemSpacing = ImVec2(8, 12);
//    style->WindowBorderSize = 1;
//    style->ScrollbarSize = 8.f;
//    style->FrameRounding = 4.f;
//    style->GrabRounding = 4.f;
//    style->WindowRounding = 6.f;
//    style->FrameBorderSize = 1;
//    style->ItemInnerSpacing = ImVec2(8, 8);
//
//    // 高科技浅蓝色颜色方案 - 明亮背景配合蓝色调
//    ImVec4* colors = style->Colors;
//    colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.08f, 0.12f, 0.95f);       // 深蓝黑色背景
//    colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.11f, 0.16f, 0.85f);       // 子窗口背景
//    colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.18f, 0.25f, 0.50f);       // 框架背景
//    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.18f, 0.30f, 0.45f, 0.70f); // 框架悬停
//    colors[ImGuiCol_FrameBgActive] = ImVec4(0.22f, 0.40f, 0.60f, 0.80f);  // 框架激活
//    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.15f, 0.22f, 1.00f);        // 标题背景
//    colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.25f, 0.38f, 1.00f);  // 标题激活
//    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.08f, 0.12f, 0.18f, 0.60f);    // 滚动条背景
//    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.45f, 0.75f, 0.60f);  // 滚动条滑块
//    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.30f, 0.50f, 0.80f, 0.70f); // 滑块悬停
//    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.35f, 0.55f, 0.85f, 0.80f);  // 滑块激活
//    colors[ImGuiCol_CheckMark] = ImVec4(0.40f, 0.70f, 1.00f, 1.00f);      // 勾选标记
//    colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.60f, 0.95f, 0.80f);     // 滑块
//    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.40f, 0.65f, 1.00f, 1.00f); // 滑块激活
//    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.35f, 0.55f, 0.40f);         // 按钮
//    colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.45f, 0.70f, 0.60f);  // 按钮悬停
//    colors[ImGuiCol_ButtonActive] = ImVec4(0.30f, 0.50f, 0.80f, 0.80f);   // 按钮激活
//    colors[ImGuiCol_Text] = ImVec4(0.85f, 0.90f, 0.95f, 0.95f);           // 文本
//    colors[ImGuiCol_TextDisabled] = ImVec4(0.40f, 0.50f, 0.60f, 0.70f);   // 禁用文本
//    colors[ImGuiCol_Border] = ImVec4(0.30f, 0.50f, 0.80f, 0.50f);         // 边框
//    colors[ImGuiCol_BorderShadow] = ImVec4(0.10f, 0.20f, 0.35f, 0.30f);   // 边框阴影
//    colors[ImGuiCol_Header] = ImVec4(0.18f, 0.30f, 0.45f, 0.50f);         // 标题栏
//    colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.40f, 0.60f, 0.70f);  // 标题栏悬停
//    colors[ImGuiCol_HeaderActive] = ImVec4(0.30f, 0.50f, 0.75f, 0.80f);   // 标题栏激活
//}
//
//inline void MenuInit() {
//    InitMenuStyle();
//    ImGui::SetNextWindowSize(c::bg::size);
//
//    ImGuiStyle* style = &ImGui::GetStyle();
//
//    style->WindowPadding = ImVec2(10, 10);
//    style->ItemSpacing = ImVec2(20, 20);
//    style->WindowBorderSize = 0;
//    style->ScrollbarSize = 10.f;
//
//
//    static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
//    auto CurTimePoint = std::chrono::steady_clock::now();
//    if (GetAsyncKeyState(VK_HOME) &&
//        (CurTimePoint - LastTimePoint >= std::chrono::milliseconds(200)))
//    {
//        menu = !menu;
//        LastTimePoint = CurTimePoint;
//    }
//
//    if (menu) {
//
//
//        ImGui::Begin("MENU", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);
//        {
//            const ImVec2& pos = GetWindowPos();
//            const ImVec2& region = GetContentRegionMax();
//            const ImVec2& spacing = style->ItemSpacing;
//            auto& drawList = *ImGui::GetBackgroundDrawList();
//            const float dt = ImGui::GetIO().DeltaTime;
//
//            // 高科技浅蓝色风格背景绘制 - 渐变和光效
//            drawList.AddRectFilledMultiColor(pos, pos + region,
//                ImColor(245, 248, 252, 250), ImColor(240, 245, 250, 250),
//                ImColor(235, 242, 248, 250), ImColor(242, 246, 251, 250),
//                c::bg::rounding);
//
//            // 绘制蓝色边框
//            drawList.AddRect(pos, pos + region, ImColor(150, 200, 250, 100), c::bg::rounding, 0, 2.0f);
//            drawList.AddRect(pos + ImVec2(1, 1), pos + region - ImVec2(1, 1), ImColor(100, 180, 255, 80), c::bg::rounding, 0, 1.0f);
//
//            // 动画计时器
//            static float anim_timer = 0.0f;
//            anim_timer += dt;
//
//            // 高科技装饰元素 - 动态网格和光晕效果
//            if (fmod(anim_timer, 0.07f) < dt) {
//                // 左侧面板分隔
//                drawList.AddRectFilled(pos + ImVec2(145, 60), pos + region,
//                    ImColor(230, 240, 250, 240), c::bg::rounding, ImDrawFlags_RoundCornersBottomRight);
//                drawList.AddRectFilled(pos + ImVec2(145, 0), pos + ImVec2(region.x, 60),
//                    ImColor(220, 235, 250, 240), c::bg::rounding, ImDrawFlags_RoundCornersTopRight);
//
//                // 蓝色分隔线
//                drawList.AddLine(pos + ImVec2(0, 60), pos + ImVec2(region.x, 60),
//                    ImColor(100, 160, 255, 150), 1.5f);
//
//                // 动态发光圆点
//                drawList.AddCircle(pos + ImVec2(region.x - 30, 30), 12,
//                    ImColor(120, 180, 255, 180), 32, 1.5f);
//                drawList.AddCircleFilled(pos + ImVec2(region.x - 30, 30), 3,
//                    ImColor(80, 160, 255, 200), 32);
//            }
//
//            // 网格背景效果
//            drawList.PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(region), true);
//            if (fmod(anim_timer, 0.12f) < dt) {
//                // 发光区域效果
//                drawList.AddShadowCircle(pos + ImVec2(145, 160), 80,
//                    ImColor(150, 200, 255, 20), 128, ImVec2(0, 0), 0);
//                drawList.AddShadowCircle(pos + ImVec2(region.x, 160), 80,
//                    ImColor(180, 200, 255, 20), 128, ImVec2(0, 0), 0);
//            }
//            drawList.PopClipRect();
//
//            // 标题 - 高科技浅蓝色风格
//            edited::RenderTextColor(font::inter_medium_big, pos, pos + ImVec2(145, 60),
//                ImColor(50, 100, 200, 240), "M S", ImVec2(0.5, 0.5));
//            ImGui::SetCursorPos(ImVec2(10, 70));
//            BeginGroup();
//            {
//                ID3D11ShaderResourceView* pageShortcuts[6] = { texture::ragebot, texture::legitbot, texture::visuals, texture::misc, texture::world, texture::settings };
//                for (int i = 0; i < 5; i++) if (edited::Pages(i == var::page, var::pageNames[i], pageShortcuts[i], var::buttonSize)) var::page = i;
//            }
//            EndGroup();
//            ImGui::SetCursorPos(ImVec2(region.x - (145 / 2), 60 - 35) / 2);
//            var::tab_alpha = ImClamp(var::tab_alpha + (15.f * ImGui::GetIO().DeltaTime * (var::page == var::active_tab ? 1.f : -1.f)), 0.f, 1.f);
//            if (var::tab_alpha == 0.f && var::tab_add == 0.f) var::active_tab = var::page;
//
//            var::tab_right = ImLerp(var::tab_right, var::page == var::active_tab ? 0.f : c::bg::size.x, ImGui::GetIO().DeltaTime * 13.f);
//            var::tab_left = ImLerp(var::tab_left, var::interactive ? c::bg::size.x : 0.f, ImGui::GetIO().DeltaTime * 13.f);
//
//            if (var::tab_alpha == 0.f) var::interactive = true;
//            if (var::interactive && var::tab_left >= (c::bg::size.x - 0.6f)) var::interactive = false;
//
//            ImGui::SetCursorPos(!var::interactive ? ImVec2(145.f + var::tab_right, 60.f) : ImVec2(-c::bg::size.x + (145.f + var::tab_left), 60.f));
//
//            PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(c::bg::size.x, c::bg::size.y), true);
//
//            ImGui::BeginChild("MENU", ImVec2(region.x - 145, region.y - 60));
//            {
//
//                if (var::active_tab == 0)
//                {
//                    ImGui::BeginGroup();
//                    {
//
//                        edited::BeginChild(U8("视觉选项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            if (edited::CheckboxWithPopup(false, U8("绘制方框"), description_test.c_str(), &Configs::Player::DrawBox2D, &var::key[0], &var::m[0], &var::value[0], true, true, var::col0, picker_flags))
//                            {
//                                if (Configs::Player::DrawBox2D) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("方框透视开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            };
//
//
//                            if (edited::CheckboxWithPopup(false, U8("显示骨骼"), "", &Configs::Player::DrawBone, &var::key[1], &var::m[1], &var::value[1], true, true, (float*)&Configs::Player::colors.SkeletonColor, picker_flags | ImGuiColorEditFlags_NoAlpha)) {
//
//                                if (Configs::Player::DrawBone) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("骨骼透视开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("显示血条"), "", &Configs::Player::DrawHealth, NULL, NULL, NULL, true, true, var::col2, picker_flags))
//                            {
//                                if (Configs::Player::DrawHealth) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("血条显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("文字头甲"), "", &Configs::Player::DrawEquipment, NULL, NULL, NULL, true, true, var::col11, picker_flags))
//                            {
//                                if (Configs::Player::DrawEquipment) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("头甲显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("图标头甲"), "", &Configs::Player::DrawEquipmentIco, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawEquipmentIco) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("手持图标显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("显示名称"), "", &Configs::Player::DrawPlayerName, NULL, NULL, NULL, true, true, var::col0, picker_flags))
//                            {
//                                if (Configs::Player::DrawPlayerName) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("名称显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                        }
//                        edited::EndChild();
//
//
//                    }
//                    ImGui::EndGroup();
//
//                    ImGui::SameLine();
//
//                    ImGui::BeginGroup();
//                    {
//                        edited::BeginChild(U8("选项二区"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("文字手持"), "", &Configs::Player::DrawWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawWeapon) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("手持显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//                            if (edited::CheckboxWithPopup(false, U8("图标手持"), "", &Configs::Player::DrawWeaponICO, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawWeaponICO) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("手持图标显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("显示团队"), "", &Configs::Player::DrawTeam, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawTeam) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("团队显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("显示距离"), "", &Configs::Player::ShowDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::ShowDistance) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("距离显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//
//                            if (edited::CheckboxWithPopup(false, U8("视野指示"), "", &Configs::Player::isShowOutSight, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::isShowOutSight) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("视野指示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("地图雷达"), "", &Configs::Player::Dituradar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::Dituradar) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("地图雷达开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            edited::SliderInt(U8("玩家显示距离"), &Configs::Player::playerdis, 10, 1000, "%d\xC2\xB0");
//                        }
//                        edited::EndChild();
//
//
//
//                    }
//
//                    ImGui::EndGroup();
//
//                    ImGui::BeginGroup();
//                    {
//                        edited::BeginChild(U8("NPC配置"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("NPC总开关"), "", &Configs::Player::DrawAI, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawAI) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("AI显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            // 骨骼显示
//                            if (edited::CheckboxWithPopup(false, U8("人机骨骼"), "", &Configs::Player::displayNPCSkeleton, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCSkeleton) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机骨骼开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // 名称显示
//                            if (edited::CheckboxWithPopup(false, U8("人机名称"), "", &Configs::Player::displayNPCName, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCName) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机名称开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // 手持武器显示
//                            if (edited::CheckboxWithPopup(false, U8("人机手持"), "", &Configs::Player::displayNPCWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCWeapon) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机手持武器显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // 距离显示
//                            if (edited::CheckboxWithPopup(false, U8("人机距离"), "", &Configs::Player::displayNPCDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCDistance) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机距离显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//
//                        }
//                        edited::EndChild();
//                    }
//
//                    ImGui::EndGroup();
//
//                    ImGui::SameLine();
//
//                    ImGui::BeginGroup();
//                    {
//                        edited::BeginChild(U8("NPC选项2"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            // 方框显示
//                            if (edited::CheckboxWithPopup(false, U8("人机方框"), "", &Configs::Player::displayNPCBox, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCBox) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机方框显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // 血条显示
//                            if (edited::CheckboxWithPopup(false, U8("人机血条"), "", &Configs::Player::displayNPCHealthBar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCHealthBar) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机血条显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // 显示鳄鱼
//                            if (edited::CheckboxWithPopup(false, U8("显示鳄鱼"), "", &Configs::Player::DrawEyu, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawEyu) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("鳄鱼显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            edited::SliderInt(U8("人机显示距离"), &Configs::Player::AIDis, 10, 1000, "%d\xC2\xB0");
//                        }
//                        edited::EndChild();
//                    }
//
//                    ImGui::EndGroup();
//
//
//
//
//                }
//                else if (var::active_tab == 2)
//                {
//                    ImGui::BeginGroup();
//                    {
//                        edited::BeginChild(U8("AimBot"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            edited::CheckboxWithPopup(true, U8("启用自瞄"), "-", &Configs::Aimbot::DoAimbot, NULL, NULL, NULL, false, true, var::col2, picker_flags);
//
//                            edited::Combo(U8("自瞄部位"), &Configs::Aimbot::AimIndex, Configs::Aimbot::AimBith, IM_ARRAYSIZE(Configs::Aimbot::AimBith), 4);
//
//                            edited::Combo(U8("自瞄热键"), &Configs::Aimbot::KeyIndex, Configs::Aimbot::KeyBad, IM_ARRAYSIZE(Configs::Aimbot::KeyBad), 4);
//
//
//                            edited::Combo(U8("自瞄类型"), &Configs::Aimbot::AimModIndex, Configs::Aimbot::AimMod, IM_ARRAYSIZE(Configs::Aimbot::AimMod), 1);
//
//
//                            edited::SliderFloat(U8("鼠标X速率"), &Configs::Aimbot::Smooth, 0, 100.f, "%0.2f\xC2\xB0");
//
//                            edited::SliderFloat(U8("鼠标Y速率"), &Configs::Aimbot::SmoothY, 0.f, 100.f, "%0.2f\xC2\xB0");
//
//                            edited::SliderFloat(U8("吸附强度"), &Configs::Aimbot::SmoothInt, 0.f, 100.f, "%0.2f\xC2\xB0");
//                        }
//                        edited::EndChild();
//                        ImGui::SameLine();
//                        edited::BeginChild(U8("自瞄视觉"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            edited::CheckboxWithPopup(true, U8("FOV"), "-", &Configs::Aimbot::DrawAimFov, NULL, NULL, NULL, false, true, var::col2, picker_flags);
//
//                            edited::CheckboxWithPopup(true, U8("自瞄射线"), "-", &Configs::Aimbot::AimLine, NULL, NULL, NULL, false, true, var::col2, picker_flags);
//
//
//                            edited::SliderFloat(U8("FOV大小"), &Configs::Aimbot::Fovsize, 10.f, 500.f, "%0.2f\xC2\xB0");
//
//                        }
//                        edited::EndChild();
//                    }
//                    ImGui::EndGroup();
//                }
//                else if (var::active_tab == 1)
//                {
//                    ImGui::BeginGroup();
//                    {
//
//                        edited::BeginChild(U8("物资选项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("地面物资"), "", &Configs::Item::DrawItems, NULL, NULL, NULL, true, true, var::col12, picker_flags))
//                            {
//                                if (Configs::Item::DrawItems) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("物资显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("人机盒子"), "", &Configs::Item::DrawAiBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
//                            {
//                                if (Configs::Item::DrawAiBox) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("盒子显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("玩家盒子"), "", &Configs::Item::DrawPlayerBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
//                            {
//                                if (Configs::Item::DrawPlayerBox) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("盒子显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("显示容器"), "", &Configs::Item::DrawInteractor, NULL, NULL, NULL, true, true, var::col9, picker_flags))
//                            {
//                                if (Configs::Item::DrawInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("容器显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("盒子内物资"), "", &Configs::Item::ShowInteractorInner, NULL, NULL, NULL, true, true, var::col9, picker_flags))
//                            {
//                                if (Configs::Item::ShowInteractorInner) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("需打开一次盒子"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//
//                            if (edited::CheckboxWithPopup(false, U8("容器内物资"), "", &Configs::Item::ShowInteractor, NULL, NULL, NULL, true, true, var::col8, picker_flags))
//                            {
//                                if (Configs::Item::ShowInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("需打开一次容器"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                        }
//                        edited::EndChild();
//
//                        edited::BeginChild(U8("其他选项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            edited::SliderInt(U8("物资距离"), &Configs::Item::ShowItemMaxDistance, 50, 500, "%d\xC2\xB0");
//                            edited::SliderInt(U8("盒子距离"), &Configs::Item::ShowDeadBoxMaxDistance, 50, 500, "%d\xC2\xB0");
//                            edited::SliderInt(U8("容器距离"), &Configs::Item::ShowInteractorMaxDistance, 50, 500, "%d\xC2\xB0");
//                            edited::SliderInt(U8("价值过滤"), &Configs::Item::Valuefilter, 1000, 50000, "%d\xC2\xB0");
//                            edited::Combo(U8("价值阀门"), &Configs::Aimbot::ValueIndex, Configs::Aimbot::ValueBadd,
//                                IM_ARRAYSIZE(Configs::Aimbot::ValueBadd), 5);
//
//                        }
//                        edited::EndChild();
//                    }
//                    ImGui::EndGroup();
//                    ImGui::SameLine();
//
//
//                    ImGui::BeginGroup();
//                    {
//                        edited::BeginChild(U8("其他杂项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("物资图标"), "", &Configs::Item::DrawItemsIco, NULL, NULL, NULL, true, true, var::col12, picker_flags))
//                            {
//                                if (Configs::Item::DrawItemsIco) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("图标显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("密码门"), "", &Configs::Item::DrawDoor, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawDoor) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("密码门显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("撤离点"), "", &Configs::Item::DrawExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawExit) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("撤离点显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("拉闸点"), "", &Configs::Item::DrawTriggerExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawTriggerExit) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("拉闸点显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("高价值物资列表"), "", &Configs::Item::DrawItemValueList, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawItemValueList) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("高价值物资列表显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                        }
//                        edited::EndChild();
//
//                    }
//                    ImGui::EndGroup();
//                }
//                else if (var::active_tab == 3)
//                {
//                    ImGui::BeginGroup();
//                    {
//
//                        edited::BeginChild(U8("容器列表"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::CheckboxWithPopup(true, U8("工具柜"), "", &Configs::Item::IsToolCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("鸟窝"), "", &Configs::Item::IsBirdNest, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("弹药箱"), "", &Configs::Item::IsAmmoBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("大蛇皮口袋"), "", &Configs::Item::IsBigSnakeBag, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("大武器箱"), "", &Configs::Item::IsBigWeaponBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("电脑"), "", &Configs::Item::IsComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("抽屉柜"), "", &Configs::Item::IsDrawerCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("航空储物箱"), "", &Configs::Item::IsAviationLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("衣服"), "", &Configs::Item::IsClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("垃圾箱"), "", &Configs::Item::IsTrashBin, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("医疗物资箱"), "", &Configs::Item::IsMedicalSupplies, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("保险柜"), "", &Configs::Item::BaoXianGUI, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("手提箱"), "", &Configs::Item::IsSuitcase, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("收纳盒"), "", &Configs::Item::IsShouNahe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("黑色潮汐武器箱"), "", &Configs::Item::IsBlackTideWeaponCase, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//
//                        }
//                        edited::EndChild();
//
//
//                    }
//                    ImGui::EndGroup();
//                    ImGui::SameLine();
//
//
//                    ImGui::BeginGroup();
//                    {
//                        edited::BeginChild(U8("列表二区"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::CheckboxWithPopup(true, U8("高级旅行箱"), "", &Configs::Item::IsPremiumLuggage, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("服务器"), "", &Configs::Item::IsServer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("办公室收纳盒"), "", &Configs::Item::IsOfficeOrganizer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//
//                            edited::CheckboxWithPopup(true, U8("哈德森衣服"), "", &Configs::Item::IsHudsonClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("高级储物箱"), "", &Configs::Item::IsPremiumStorageBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("快递箱"), "", &Configs::Item::IsExpressBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("小保险箱"), "", &Configs::Item::IsSmallSafe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("登山包"), "", &Configs::Item::IsHikingBackpack, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("水泥车"), "", &Configs::Item::IsCementTruck, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("医疗包"), "", &Configs::Item::IsMedicalKit, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("藏匿物"), "", &Configs::Item::IsHiddenStash, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("低级个人储物柜"), "", &Configs::Item::IsLowGradeLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("骇客电脑"), "", &Configs::Item::IsHackerComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("野外战备箱"), "", &Configs::Item::IsFieldSupplyBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("大工具盒"), "", &Configs::Item::IsLargeToolBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("电脑包"), "", &Configs::Item::IsDianNaoBao, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                        }
//                        edited::EndChild();
//
//                    }
//                    ImGui::EndGroup();
//
//                }
//                else if (var::active_tab == 4)
//                {
//                    ImGui::BeginGroup();
//                    {
//
//                        edited::BeginChild(U8("模式"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::Combo(U8("模式选择"), &Configs::Aimbot::ModIndex, Configs::Player::Mod, IM_ARRAYSIZE(Configs::Player::Mod), 2);
//                        }
//                        edited::EndChild();
//
//                        edited::BeginChild(U8("颜色配置"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//
//                            edited::ColorEdit4(U8("名称颜色"), (float*)&Configs::Player::colors.NameColor, picker_flags);
//                            edited::ColorEdit4(U8("方框颜色"), (float*)&Configs::Player::colors.Box2DColor, picker_flags);
//                            edited::ColorEdit4(U8("手持颜色"), (float*)&Configs::Player::colors.WeaponColor, picker_flags);
//                            edited::ColorEdit4(U8("骨骼颜色"), (float*)&Configs::Player::colors.SkeletonColor, picker_flags);
//                            edited::ColorEdit4(U8("距离颜色"), (float*)&Configs::Player::colors.DistanceColor, picker_flags);
//
//
//                        }
//                        edited::EndChild();
//
//
//                    }
//                    ImGui::EndGroup();
//
//                    ImGui::SameLine();
//                    ImGui::BeginGroup();
//                    {
//
//                        edited::BeginChild(U8("血条样式"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::Combo(U8("血条样式"), &Configs::Aimbot::HealthBarIndex, Configs::Aimbot::HealthStr, IM_ARRAYSIZE(Configs::Aimbot::HealthStr), 2);
//
//                        }
//                        edited::EndChild();
//
//
//                    }
//                    ImGui::EndGroup();
//
//                }
//                ImGui::EndChild();
//            }
//            PopClipRect();
//        }
//
//        ImGui::End();
//
//    }
//}
//#endif

#ifndef MENU_HPP
#define MENU_HPP
#include"Gui.h"
#include"../MenuConfigs.hpp"
#include <iomanip>  // 新增：用于时间格式化
#include <sstream>  // 新增：用于字符串流
#include <ctime>    // 新增：用于时间处理

inline void InitMenuStyle() {
    static bool initialized = false;
    if (initialized) return;
    initialized = true;

    ImGui::SetNextWindowSize(c::bg::size);
    ImGuiStyle* style = &ImGui::GetStyle();

    // 高科技浅粉色风格样式设置（仅改颜色，参数不变）
    style->WindowPadding = ImVec2(10, 10);
    style->ItemSpacing = ImVec2(8, 12);
    style->WindowBorderSize = 1;
    style->ScrollbarSize = 8.f;
    style->FrameRounding = 4.f;
    style->GrabRounding = 4.f;
    style->WindowRounding = 6.f;
    style->FrameBorderSize = 1;
    style->ItemInnerSpacing = ImVec2(8, 8);

    // 高科技浅粉色颜色方案 - 明亮背景配合粉色调（仅替换蓝色为粉色）
    ImVec4* colors = style->Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.08f, 0.10f, 0.95f);       // 深粉黑色背景（替换原深蓝黑）
    colors[ImGuiCol_ChildBg] = ImVec4(0.16f, 0.11f, 0.13f, 0.85f);       // 子窗口背景（替换原深蓝灰）
    colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.18f, 0.22f, 0.50f);       // 框架背景（替换原蓝灰）
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.45f, 0.30f, 0.38f, 0.70f); // 框架悬停（替换原浅蓝）
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.60f, 0.40f, 0.48f, 0.80f);  // 框架激活（替换原深蓝）
    colors[ImGuiCol_TitleBg] = ImVec4(0.22f, 0.15f, 0.18f, 1.00f);        // 标题背景（替换原蓝灰）
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.38f, 0.25f, 0.32f, 1.00f);  // 标题激活（替换原深蓝）
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.18f, 0.12f, 0.15f, 0.60f);    // 滚动条背景（替换原蓝灰）
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.75f, 0.45f, 0.58f, 0.60f);  // 滚动条滑块（替换原浅蓝）
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.80f, 0.50f, 0.65f, 0.70f); // 滑块悬停（替换原中蓝）
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.85f, 0.55f, 0.70f, 0.80f);  // 滑块激活（替换原深蓝）
    colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.70f, 0.85f, 1.00f);      // 勾选标记（替换原亮蓝）
    colors[ImGuiCol_SliderGrab] = ImVec4(0.95f, 0.60f, 0.78f, 0.80f);     // 滑块（替换原浅蓝）
    colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.65f, 0.82f, 1.00f); // 滑块激活（替换原亮蓝）
    colors[ImGuiCol_Button] = ImVec4(0.55f, 0.35f, 0.45f, 0.40f);         // 按钮（替换原蓝紫）
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.70f, 0.45f, 0.58f, 0.60f);  // 按钮悬停（替换原中蓝）
    colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.65f, 0.80f);   // 按钮激活（替换原深蓝）
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.85f, 0.90f, 0.95f);           // 文本（微调适配粉色背景）
    colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.50f, 0.55f, 0.70f);   // 禁用文本（替换原蓝灰）
    colors[ImGuiCol_Border] = ImVec4(0.80f, 0.50f, 0.65f, 0.50f);         // 边框（替换原中蓝）
    colors[ImGuiCol_BorderShadow] = ImVec4(0.35f, 0.20f, 0.28f, 0.30f);   // 边框阴影（替换原深蓝）
    colors[ImGuiCol_Header] = ImVec4(0.45f, 0.30f, 0.38f, 0.50f);         // 标题栏（替换原浅蓝）
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.60f, 0.40f, 0.48f, 0.70f);  // 标题栏悬停（替换原中蓝）
    colors[ImGuiCol_HeaderActive] = ImVec4(0.75f, 0.50f, 0.63f, 0.80f);   // 标题栏激活（替换原深蓝）
}

// 新增：获取格式化的当前时间字符串（时:分:秒）
std::string GetFormattedCurrentTime() {
    // 获取当前系统时间
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    // 转换为本地时间（Windows兼容）
    std::tm local_time{};
    localtime_s(&local_time, &current_time); // Windows专用安全函数

    // 格式化时间为 "HH:MM:SS"
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << local_time.tm_hour << ":"
        << std::setw(2) << std::setfill('0') << local_time.tm_min << ":"
        << std::setw(2) << std::setfill('0') << local_time.tm_sec;
    return ss.str();
}

inline void MenuInit() {
    InitMenuStyle();
    ImGui::SetNextWindowSize(c::bg::size);

    ImGuiStyle* style = &ImGui::GetStyle();

    style->WindowPadding = ImVec2(10, 10);
    style->ItemSpacing = ImVec2(20, 20);
    style->WindowBorderSize = 0;
    style->ScrollbarSize = 10.f;


    static std::chrono::time_point LastTimePoint = std::chrono::steady_clock::now();
    auto CurTimePoint = std::chrono::steady_clock::now();
    if (GetAsyncKeyState(VK_HOME) &&
        (CurTimePoint - LastTimePoint >= std::chrono::milliseconds(200)))
    {
        menu = !menu;
        LastTimePoint = CurTimePoint;
    }

    if (menu) {


        ImGui::Begin("MENU", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus);
        {
            const ImVec2& pos = ImGui::GetWindowPos(); // 修复：补充ImGui::命名空间
            const ImVec2& region = ImGui::GetContentRegionMax(); // 修复：补充ImGui::命名空间
            const ImVec2& spacing = style->ItemSpacing;
            auto& drawList = *ImGui::GetBackgroundDrawList();
            const float dt = ImGui::GetIO().DeltaTime;

            // 高科技浅粉色风格背景绘制 - 渐变和光效（仅改颜色）
            drawList.AddRectFilledMultiColor(pos, pos + region,
                ImColor(252, 245, 248, 250), ImColor(250, 240, 245, 250),
                ImColor(248, 235, 242, 250), ImColor(251, 242, 246, 250),
                c::bg::rounding);


            // 绘制粉色边框（替换原蓝色边框）
            drawList.AddRect(pos, pos + region, ImColor(250, 150, 180, 100), c::bg::rounding, 0, 2.0f);
            drawList.AddRect(pos + ImVec2(1, 1), pos + region - ImVec2(1, 1), ImColor(255, 100, 150, 80), c::bg::rounding, 0, 1.0f);

            // 动画计时器
            static float anim_timer = 0.0f;
            anim_timer += dt;

            // 高科技装饰元素 - 动态网格和光晕效果（仅改颜色）
            if (fmod(anim_timer, 0.07f) < dt) {
                // 左侧面板分隔
                drawList.AddRectFilled(pos + ImVec2(145, 60), pos + region,
                    ImColor(250, 230, 240, 240), c::bg::rounding, ImDrawFlags_RoundCornersBottomRight);
                drawList.AddRectFilled(pos + ImVec2(145, 0), pos + ImVec2(region.x, 60),
                    ImColor(250, 220, 235, 240), c::bg::rounding, ImDrawFlags_RoundCornersTopRight);

                // 粉色分隔线（替换原蓝色分隔线）
                drawList.AddLine(pos + ImVec2(0, 60), pos + ImVec2(region.x, 60),
                    ImColor(255, 100, 160, 150), 1.5f);

                // 动态发光圆点（替换原蓝色圆点）
                drawList.AddCircle(pos + ImVec2(region.x - 30, 30), 12,
                    ImColor(255, 120, 180, 180), 32, 1.5f);
                drawList.AddCircleFilled(pos + ImVec2(region.x - 30, 30), 3,
                    ImColor(255, 80, 160, 200), 32);
            }

            // 网格背景效果（仅改颜色）
            drawList.PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(region), true);
            if (fmod(anim_timer, 0.12f) < dt) {
                // 发光区域效果（替换原蓝色光晕）
                drawList.AddShadowCircle(pos + ImVec2(145, 160), 80,
                    ImColor(255, 150, 200, 20), 128, ImVec2(0, 0), 0);
                drawList.AddShadowCircle(pos + ImVec2(region.x, 160), 80,
                    ImColor(255, 180, 200, 20), 128, ImVec2(0, 0), 0);
            }
            drawList.PopClipRect();

            // 标题 - 彩虹色动态效果
            float time = ImGui::GetTime(); // 获取当前时间用于动画
            float hue = (sin(time * 0.5f) + 1.0f) * 0.5f; // 计算0-1范围的色相值，随时间变化

            // 使用HSV颜色空间创建彩虹色（Hue从0到1循环，Saturation和Value保持较高值）
            ImColor rainbowColor = ImColor::HSV(hue, 0.8f, 0.9f, 240); // 最后一个参数是alpha值

            edited::RenderTextColor(font::inter_medium_big, pos, pos + ImVec2(145, 60),
                rainbowColor, "M S", ImVec2(0.5, 0.5));

            // 新增：在"M S"标题下方显示当前时间
            static std::string current_time_str;
            static float time_update_timer = 0.0f;
            // 每0.5秒更新一次时间（平衡实时性和性能）
            time_update_timer += dt;
            if (time_update_timer >= 0.5f) {
                current_time_str = GetFormattedCurrentTime();
                time_update_timer = 0.0f;
            }
            // 绘制时间（位于标题下方10像素，水平居中，浅粉色文本）
            edited::RenderTextColor(
                font::inter_medium_big,  // 使用与标题相同的字体
                pos + ImVec2(0, 30),     // Y轴偏移30像素（标题下方）
                pos + ImVec2(145, 60),   // 与标题同宽，底部对齐分隔线
                ImColor(255, 180, 200, 240), // 浅粉色文本，适配UI
                current_time_str.c_str(),
                ImVec2(0.5, 0.5)         // 水平居中
            );

            ImGui::SetCursorPos(ImVec2(10, 70));
            ImGui::BeginGroup(); // 补充完整命名空间

            {
                ID3D11ShaderResourceView* pageShortcuts[6] = { texture::ragebot, texture::legitbot, texture::visuals, texture::misc, texture::world, texture::settings };
                for (int i = 0; i < 5; i++) if (edited::Pages(i == var::page, var::pageNames[i], pageShortcuts[i], var::buttonSize)) var::page = i;
            }
            ImGui::EndGroup(); // 补充ImGui::命名空间
            ImGui::SetCursorPos(ImVec2(region.x - (145 / 2), 60 - 35) / 2);
            var::tab_alpha = ImClamp(var::tab_alpha + (15.f * ImGui::GetIO().DeltaTime * (var::page == var::active_tab ? 1.f : -1.f)), 0.f, 1.f);
            if (var::tab_alpha == 0.f && var::tab_add == 0.f) var::active_tab = var::page;

            var::tab_right = ImLerp(var::tab_right, var::page == var::active_tab ? 0.f : c::bg::size.x, ImGui::GetIO().DeltaTime * 13.f);
            var::tab_left = ImLerp(var::tab_left, var::interactive ? c::bg::size.x : 0.f, ImGui::GetIO().DeltaTime * 13.f);

            if (var::tab_alpha == 0.f) var::interactive = true;
            if (var::interactive && var::tab_left >= (c::bg::size.x - 0.6f)) var::interactive = false;

            ImGui::SetCursorPos(!var::interactive ? ImVec2(145.f + var::tab_right, 60.f) : ImVec2(-c::bg::size.x + (145.f + var::tab_left), 60.f));

            ImGui::PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(c::bg::size.x, c::bg::size.y), true); // 补充ImGui::命名空间

            ImGui::BeginChild("MENU", ImVec2(region.x - 145, region.y - 60));
            {

                if (var::active_tab == 0)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("视觉选项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            if (edited::CheckboxWithPopup(false, U8("绘制方框"), description_test.c_str(), &Configs::Player::DrawBox2D, &var::key[0], &var::m[0], &var::value[0], true, true, var::col0, picker_flags))
                            {
                                if (Configs::Player::DrawBox2D) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("方框透视开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            };


                            if (edited::CheckboxWithPopup(false, U8("显示骨骼"), "", &Configs::Player::DrawBone, &var::key[1], &var::m[1], &var::value[1], true, true, (float*)&Configs::Player::colors.SkeletonColor, picker_flags | ImGuiColorEditFlags_NoAlpha)) {

                                if (Configs::Player::DrawBone) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("骨骼透视开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("显示血条"), "", &Configs::Player::DrawHealth, NULL, NULL, NULL, true, true, var::col2, picker_flags))
                            {
                                if (Configs::Player::DrawHealth) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("血条显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("文字头甲"), "", &Configs::Player::DrawEquipment, NULL, NULL, NULL, true, true, var::col11, picker_flags))
                            {
                                if (Configs::Player::DrawEquipment) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("头甲显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("图标头甲"), "", &Configs::Player::DrawEquipmentIco, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawEquipmentIco) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("手持图标显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("显示名称"), "", &Configs::Player::DrawPlayerName, NULL, NULL, NULL, true, true, var::col0, picker_flags))
                            {
                                if (Configs::Player::DrawPlayerName) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("名称显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();

                    ImGui::SameLine();

                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("选项二区"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("文字手持"), "", &Configs::Player::DrawWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawWeapon) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("手持显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }
                            if (edited::CheckboxWithPopup(false, U8("图标手持"), "", &Configs::Player::DrawWeaponICO, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawWeaponICO) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("手持图标显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("显示团队"), "", &Configs::Player::DrawTeam, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawTeam) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("团队显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("显示距离"), "", &Configs::Player::ShowDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::ShowDistance) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("距离显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }


                            if (edited::CheckboxWithPopup(false, U8("视野指示"), "", &Configs::Player::isShowOutSight, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::isShowOutSight) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("视野指示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("地图雷达"), "", &Configs::Player::Dituradar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::Dituradar) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("地图雷达开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            edited::SliderInt(U8("玩家显示距离"), &Configs::Player::playerdis, 10, 1000, "%d\xC2\xB0");
                        }
                        edited::EndChild();



                    }

                    ImGui::EndGroup();

                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("NPC配置"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("NPC总开关"), "", &Configs::Player::DrawAI, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawAI) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("AI显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            // 骨骼显示
                            if (edited::CheckboxWithPopup(false, U8("人机骨骼"), "", &Configs::Player::displayNPCSkeleton, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCSkeleton) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机骨骼开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // 名称显示
                            if (edited::CheckboxWithPopup(false, U8("人机名称"), "", &Configs::Player::displayNPCName, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCName) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机名称开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // 手持武器显示
                            if (edited::CheckboxWithPopup(false, U8("人机手持"), "", &Configs::Player::displayNPCWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCWeapon) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机手持武器显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // 距离显示
                            if (edited::CheckboxWithPopup(false, U8("人机距离"), "", &Configs::Player::displayNPCDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCDistance) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机距离显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }


                        }
                        edited::EndChild();
                    }

                    ImGui::EndGroup();

                    ImGui::SameLine();

                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("NPC选项2"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            // 方框显示
                            if (edited::CheckboxWithPopup(false, U8("人机方框"), "", &Configs::Player::displayNPCBox, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCBox) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机方框显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // 血条显示
                            if (edited::CheckboxWithPopup(false, U8("人机血条"), "", &Configs::Player::displayNPCHealthBar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCHealthBar) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("人机血条显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // 显示鳄鱼
                            if (edited::CheckboxWithPopup(false, U8("显示鳄鱼"), "", &Configs::Player::DrawEyu, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawEyu) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("鳄鱼显示显示开启成功"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            edited::SliderInt(U8("人机显示距离"), &Configs::Player::AIDis, 10, 1000, "%d\xC2\xB0");
                        }
                        edited::EndChild();
                    }

                    ImGui::EndGroup();




                }
                else if (var::active_tab == 2)
                {
                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("AimBot"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            edited::CheckboxWithPopup(true, U8("启用自瞄"), "-", &Configs::Aimbot::DoAimbot, NULL, NULL, NULL, false, true, var::col2, picker_flags);

                            edited::Combo(U8("自瞄部位"), &Configs::Aimbot::AimIndex, Configs::Aimbot::AimBith, IM_ARRAYSIZE(Configs::Aimbot::AimBith), 4);

                            edited::Combo(U8("自瞄热键"), &Configs::Aimbot::KeyIndex, Configs::Aimbot::KeyBad, IM_ARRAYSIZE(Configs::Aimbot::KeyBad), 4);


                            edited::Combo(U8("自瞄类型"), &Configs::Aimbot::AimModIndex, Configs::Aimbot::AimMod, IM_ARRAYSIZE(Configs::Aimbot::AimMod), 1);


                            edited::SliderFloat(U8("鼠标X速率"), &Configs::Aimbot::Smooth, 0, 100.f, "%0.2f\xC2\xB0");

                            edited::SliderFloat(U8("鼠标Y速率"), &Configs::Aimbot::SmoothY, 0.f, 100.f, "%0.2f\xC2\xB0");

                            edited::SliderFloat(U8("吸附强度"), &Configs::Aimbot::SmoothInt, 0.f, 100.f, "%0.2f\xC2\xB0");
                        }
                        edited::EndChild();
                        ImGui::SameLine();
                        edited::BeginChild(U8("自瞄视觉"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            edited::CheckboxWithPopup(true, U8("FOV"), "-", &Configs::Aimbot::DrawAimFov, NULL, NULL, NULL, false, true, var::col2, picker_flags);

                            edited::CheckboxWithPopup(true, U8("自瞄射线"), "-", &Configs::Aimbot::AimLine, NULL, NULL, NULL, false, true, var::col2, picker_flags);


                            edited::SliderFloat(U8("FOV大小"), &Configs::Aimbot::Fovsize, 10.f, 500.f, "%0.2f\xC2\xB0");

                        }
                        edited::EndChild();
                    }
                    ImGui::EndGroup();
                }
                else if (var::active_tab == 1)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("物资选项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("地面物资"), "", &Configs::Item::DrawItems, NULL, NULL, NULL, true, true, var::col12, picker_flags))
                            {
                                if (Configs::Item::DrawItems) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("物资显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("人机盒子"), "", &Configs::Item::DrawAiBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
                            {
                                if (Configs::Item::DrawAiBox) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("盒子显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("玩家盒子"), "", &Configs::Item::DrawPlayerBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
                            {
                                if (Configs::Item::DrawPlayerBox) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("盒子显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("显示容器"), "", &Configs::Item::DrawInteractor, NULL, NULL, NULL, true, true, var::col9, picker_flags))
                            {
                                if (Configs::Item::DrawInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("容器显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("盒子内物资"), "", &Configs::Item::ShowInteractorInner, NULL, NULL, NULL, true, true, var::col9, picker_flags))
                            {
                                if (Configs::Item::ShowInteractorInner) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("需打开一次盒子"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }


                            if (edited::CheckboxWithPopup(false, U8("容器内物资"), "", &Configs::Item::ShowInteractor, NULL, NULL, NULL, true, true, var::col8, picker_flags))
                            {
                                if (Configs::Item::ShowInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("需打开一次容器"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                        }
                        edited::EndChild();

                        edited::BeginChild(U8("其他选项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            edited::SliderInt(U8("物资距离"), &Configs::Item::ShowItemMaxDistance, 50, 500, "%d\xC2\xB0");
                            edited::SliderInt(U8("盒子距离"), &Configs::Item::ShowDeadBoxMaxDistance, 50, 500, "%d\xC2\xB0");
                            edited::SliderInt(U8("容器距离"), &Configs::Item::ShowInteractorMaxDistance, 50, 500, "%d\xC2\xB0");
                            edited::SliderInt(U8("价值过滤"), &Configs::Item::Valuefilter, 1000, 50000, "%d\xC2\xB0");
                            edited::Combo(U8("价值阀门"), &Configs::Aimbot::ValueIndex, Configs::Aimbot::ValueBadd,
                                IM_ARRAYSIZE(Configs::Aimbot::ValueBadd), 5);

                        }
                        edited::EndChild();
                    }
                    ImGui::EndGroup();
                    ImGui::SameLine();


                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("其他杂项"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("物资图标"), "", &Configs::Item::DrawItemsIco, NULL, NULL, NULL, true, true, var::col12, picker_flags))
                            {
                                if (Configs::Item::DrawItemsIco) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("图标显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("密码门"), "", &Configs::Item::DrawDoor, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawDoor) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("密码门显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("撤离点"), "", &Configs::Item::DrawExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawExit) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("撤离点显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("拉闸点"), "", &Configs::Item::DrawTriggerExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawTriggerExit) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("拉闸点显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("高价值物资列表"), "", &Configs::Item::DrawItemValueList, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawItemValueList) { notificationSystem.AddNotification(ICON_WARNING, U8("开启成功"), U8("高价值物资列表显示开启成功"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                        }
                        edited::EndChild();

                    }
                    ImGui::EndGroup();
                }
                else if (var::active_tab == 3)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("容器列表"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::CheckboxWithPopup(true, U8("工具柜"), "", &Configs::Item::IsToolCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("鸟窝"), "", &Configs::Item::IsBirdNest, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("弹药箱"), "", &Configs::Item::IsAmmoBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("大蛇皮口袋"), "", &Configs::Item::IsBigSnakeBag, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("大武器箱"), "", &Configs::Item::IsBigWeaponBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("电脑"), "", &Configs::Item::IsComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("抽屉柜"), "", &Configs::Item::IsDrawerCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("航空储物箱"), "", &Configs::Item::IsAviationLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("衣服"), "", &Configs::Item::IsClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("垃圾箱"), "", &Configs::Item::IsTrashBin, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("医疗物资箱"), "", &Configs::Item::IsMedicalSupplies, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("保险柜"), "", &Configs::Item::BaoXianGUI, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("手提箱"), "", &Configs::Item::IsSuitcase, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("收纳盒"), "", &Configs::Item::IsShouNahe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("黑色潮汐武器箱"), "", &Configs::Item::IsBlackTideWeaponCase, NULL, NULL, NULL, true, true, var::col12, picker_flags);

                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();
                    ImGui::SameLine();


                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("列表二区"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::CheckboxWithPopup(true, U8("高级旅行箱"), "", &Configs::Item::IsPremiumLuggage, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("服务器"), "", &Configs::Item::IsServer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("办公室收纳盒"), "", &Configs::Item::IsOfficeOrganizer, NULL, NULL, NULL, true, true, var::col12, picker_flags);

                            edited::CheckboxWithPopup(true, U8("哈德森衣服"), "", &Configs::Item::IsHudsonClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("高级储物箱"), "", &Configs::Item::IsPremiumStorageBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("快递箱"), "", &Configs::Item::IsExpressBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("小保险箱"), "", &Configs::Item::IsSmallSafe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("登山包"), "", &Configs::Item::IsHikingBackpack, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("水泥车"), "", &Configs::Item::IsCementTruck, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("医疗包"), "", &Configs::Item::IsMedicalKit, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("藏匿物"), "", &Configs::Item::IsHiddenStash, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("低级个人储物柜"), "", &Configs::Item::IsLowGradeLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("骇客电脑"), "", &Configs::Item::IsHackerComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("野外战备箱"), "", &Configs::Item::IsFieldSupplyBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("大工具盒"), "", &Configs::Item::IsLargeToolBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("电脑包"), "", &Configs::Item::IsDianNaoBao, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                        }
                        edited::EndChild();

                    }
                    ImGui::EndGroup();

                }
                else if (var::active_tab == 4)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("模式"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::Combo(U8("模式选择"), &Configs::Aimbot::ModIndex, Configs::Player::Mod, IM_ARRAYSIZE(Configs::Player::Mod), 2);
                        }
                        edited::EndChild();

                        edited::BeginChild(U8("颜色配置"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {


                            edited::ColorEdit4(U8("名称颜色"), (float*)&Configs::Player::colors.NameColor, picker_flags);
                            edited::ColorEdit4(U8("方框颜色"), (float*)&Configs::Player::colors.Box2DColor, picker_flags);
                            edited::ColorEdit4(U8("手持颜色"), (float*)&Configs::Player::colors.WeaponColor, picker_flags);
                            edited::ColorEdit4(U8("骨骼颜色"), (float*)&Configs::Player::colors.SkeletonColor, picker_flags);
                            edited::ColorEdit4(U8("距离颜色"), (float*)&Configs::Player::colors.DistanceColor, picker_flags);


                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();

                    ImGui::SameLine();
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("血条样式"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::Combo(U8("血条样式"), &Configs::Aimbot::HealthBarIndex, Configs::Aimbot::HealthStr, IM_ARRAYSIZE(Configs::Aimbot::HealthStr), 2);

                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();

                }
                ImGui::EndChild();
            }
            ImGui::PopClipRect(); // 补充ImGui::命名空间
        }

        ImGui::End();

    }
}
#endif