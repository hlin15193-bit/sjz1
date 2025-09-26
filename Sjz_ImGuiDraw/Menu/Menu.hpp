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
//    // �߿Ƽ�ǳ��ɫ�����ʽ����
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
//    // �߿Ƽ�ǳ��ɫ��ɫ���� - �������������ɫ��
//    ImVec4* colors = style->Colors;
//    colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.08f, 0.12f, 0.95f);       // ������ɫ����
//    colors[ImGuiCol_ChildBg] = ImVec4(0.07f, 0.11f, 0.16f, 0.85f);       // �Ӵ��ڱ���
//    colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.18f, 0.25f, 0.50f);       // ��ܱ���
//    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.18f, 0.30f, 0.45f, 0.70f); // �����ͣ
//    colors[ImGuiCol_FrameBgActive] = ImVec4(0.22f, 0.40f, 0.60f, 0.80f);  // ��ܼ���
//    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.15f, 0.22f, 1.00f);        // ���ⱳ��
//    colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.25f, 0.38f, 1.00f);  // ���⼤��
//    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.08f, 0.12f, 0.18f, 0.60f);    // ����������
//    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.25f, 0.45f, 0.75f, 0.60f);  // ����������
//    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.30f, 0.50f, 0.80f, 0.70f); // ������ͣ
//    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.35f, 0.55f, 0.85f, 0.80f);  // ���鼤��
//    colors[ImGuiCol_CheckMark] = ImVec4(0.40f, 0.70f, 1.00f, 1.00f);      // ��ѡ���
//    colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.60f, 0.95f, 0.80f);     // ����
//    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.40f, 0.65f, 1.00f, 1.00f); // ���鼤��
//    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.35f, 0.55f, 0.40f);         // ��ť
//    colors[ImGuiCol_ButtonHovered] = ImVec4(0.25f, 0.45f, 0.70f, 0.60f);  // ��ť��ͣ
//    colors[ImGuiCol_ButtonActive] = ImVec4(0.30f, 0.50f, 0.80f, 0.80f);   // ��ť����
//    colors[ImGuiCol_Text] = ImVec4(0.85f, 0.90f, 0.95f, 0.95f);           // �ı�
//    colors[ImGuiCol_TextDisabled] = ImVec4(0.40f, 0.50f, 0.60f, 0.70f);   // �����ı�
//    colors[ImGuiCol_Border] = ImVec4(0.30f, 0.50f, 0.80f, 0.50f);         // �߿�
//    colors[ImGuiCol_BorderShadow] = ImVec4(0.10f, 0.20f, 0.35f, 0.30f);   // �߿���Ӱ
//    colors[ImGuiCol_Header] = ImVec4(0.18f, 0.30f, 0.45f, 0.50f);         // ������
//    colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.40f, 0.60f, 0.70f);  // ��������ͣ
//    colors[ImGuiCol_HeaderActive] = ImVec4(0.30f, 0.50f, 0.75f, 0.80f);   // ����������
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
//            // �߿Ƽ�ǳ��ɫ��񱳾����� - ����͹�Ч
//            drawList.AddRectFilledMultiColor(pos, pos + region,
//                ImColor(245, 248, 252, 250), ImColor(240, 245, 250, 250),
//                ImColor(235, 242, 248, 250), ImColor(242, 246, 251, 250),
//                c::bg::rounding);
//
//            // ������ɫ�߿�
//            drawList.AddRect(pos, pos + region, ImColor(150, 200, 250, 100), c::bg::rounding, 0, 2.0f);
//            drawList.AddRect(pos + ImVec2(1, 1), pos + region - ImVec2(1, 1), ImColor(100, 180, 255, 80), c::bg::rounding, 0, 1.0f);
//
//            // ������ʱ��
//            static float anim_timer = 0.0f;
//            anim_timer += dt;
//
//            // �߿Ƽ�װ��Ԫ�� - ��̬����͹���Ч��
//            if (fmod(anim_timer, 0.07f) < dt) {
//                // ������ָ�
//                drawList.AddRectFilled(pos + ImVec2(145, 60), pos + region,
//                    ImColor(230, 240, 250, 240), c::bg::rounding, ImDrawFlags_RoundCornersBottomRight);
//                drawList.AddRectFilled(pos + ImVec2(145, 0), pos + ImVec2(region.x, 60),
//                    ImColor(220, 235, 250, 240), c::bg::rounding, ImDrawFlags_RoundCornersTopRight);
//
//                // ��ɫ�ָ���
//                drawList.AddLine(pos + ImVec2(0, 60), pos + ImVec2(region.x, 60),
//                    ImColor(100, 160, 255, 150), 1.5f);
//
//                // ��̬����Բ��
//                drawList.AddCircle(pos + ImVec2(region.x - 30, 30), 12,
//                    ImColor(120, 180, 255, 180), 32, 1.5f);
//                drawList.AddCircleFilled(pos + ImVec2(region.x - 30, 30), 3,
//                    ImColor(80, 160, 255, 200), 32);
//            }
//
//            // ���񱳾�Ч��
//            drawList.PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(region), true);
//            if (fmod(anim_timer, 0.12f) < dt) {
//                // ��������Ч��
//                drawList.AddShadowCircle(pos + ImVec2(145, 160), 80,
//                    ImColor(150, 200, 255, 20), 128, ImVec2(0, 0), 0);
//                drawList.AddShadowCircle(pos + ImVec2(region.x, 160), 80,
//                    ImColor(180, 200, 255, 20), 128, ImVec2(0, 0), 0);
//            }
//            drawList.PopClipRect();
//
//            // ���� - �߿Ƽ�ǳ��ɫ���
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
//                        edited::BeginChild(U8("�Ӿ�ѡ��"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            if (edited::CheckboxWithPopup(false, U8("���Ʒ���"), description_test.c_str(), &Configs::Player::DrawBox2D, &var::key[0], &var::m[0], &var::value[0], true, true, var::col0, picker_flags))
//                            {
//                                if (Configs::Player::DrawBox2D) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("����͸�ӿ����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            };
//
//
//                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::DrawBone, &var::key[1], &var::m[1], &var::value[1], true, true, (float*)&Configs::Player::colors.SkeletonColor, picker_flags | ImGuiColorEditFlags_NoAlpha)) {
//
//                                if (Configs::Player::DrawBone) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("����͸�ӿ����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��ʾѪ��"), "", &Configs::Player::DrawHealth, NULL, NULL, NULL, true, true, var::col2, picker_flags))
//                            {
//                                if (Configs::Player::DrawHealth) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("Ѫ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("����ͷ��"), "", &Configs::Player::DrawEquipment, NULL, NULL, NULL, true, true, var::col11, picker_flags))
//                            {
//                                if (Configs::Player::DrawEquipment) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("ͷ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("ͼ��ͷ��"), "", &Configs::Player::DrawEquipmentIco, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawEquipmentIco) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�ֳ�ͼ����ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::DrawPlayerName, NULL, NULL, NULL, true, true, var::col0, picker_flags))
//                            {
//                                if (Configs::Player::DrawPlayerName) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
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
//                        edited::BeginChild(U8("ѡ�����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("�����ֳ�"), "", &Configs::Player::DrawWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawWeapon) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�ֳ���ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//                            if (edited::CheckboxWithPopup(false, U8("ͼ���ֳ�"), "", &Configs::Player::DrawWeaponICO, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawWeaponICO) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�ֳ�ͼ����ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��ʾ�Ŷ�"), "", &Configs::Player::DrawTeam, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawTeam) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�Ŷ���ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::ShowDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::ShowDistance) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//
//                            if (edited::CheckboxWithPopup(false, U8("��Ұָʾ"), "", &Configs::Player::isShowOutSight, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::isShowOutSight) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��Ұָʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��ͼ�״�"), "", &Configs::Player::Dituradar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::Dituradar) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��ͼ�״￪���ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            edited::SliderInt(U8("�����ʾ����"), &Configs::Player::playerdis, 10, 1000, "%d\xC2\xB0");
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
//                        edited::BeginChild(U8("NPC����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("NPC�ܿ���"), "", &Configs::Player::DrawAI, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawAI) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("AI��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            // ������ʾ
//                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCSkeleton, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCSkeleton) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻����������ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // ������ʾ
//                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCName, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCName) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻����ƿ����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // �ֳ�������ʾ
//                            if (edited::CheckboxWithPopup(false, U8("�˻��ֳ�"), "", &Configs::Player::displayNPCWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCWeapon) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻��ֳ�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // ������ʾ
//                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCDistance) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
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
//                        edited::BeginChild(U8("NPCѡ��2"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            // ������ʾ
//                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCBox, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCBox) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // Ѫ����ʾ
//                            if (edited::CheckboxWithPopup(false, U8("�˻�Ѫ��"), "", &Configs::Player::displayNPCHealthBar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::displayNPCHealthBar) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻�Ѫ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            // ��ʾ����
//                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::DrawEyu, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Player::DrawEyu) {
//                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
//                                }
//                            }
//
//                            edited::SliderInt(U8("�˻���ʾ����"), &Configs::Player::AIDis, 10, 1000, "%d\xC2\xB0");
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
//                            edited::CheckboxWithPopup(true, U8("��������"), "-", &Configs::Aimbot::DoAimbot, NULL, NULL, NULL, false, true, var::col2, picker_flags);
//
//                            edited::Combo(U8("���鲿λ"), &Configs::Aimbot::AimIndex, Configs::Aimbot::AimBith, IM_ARRAYSIZE(Configs::Aimbot::AimBith), 4);
//
//                            edited::Combo(U8("�����ȼ�"), &Configs::Aimbot::KeyIndex, Configs::Aimbot::KeyBad, IM_ARRAYSIZE(Configs::Aimbot::KeyBad), 4);
//
//
//                            edited::Combo(U8("��������"), &Configs::Aimbot::AimModIndex, Configs::Aimbot::AimMod, IM_ARRAYSIZE(Configs::Aimbot::AimMod), 1);
//
//
//                            edited::SliderFloat(U8("���X����"), &Configs::Aimbot::Smooth, 0, 100.f, "%0.2f\xC2\xB0");
//
//                            edited::SliderFloat(U8("���Y����"), &Configs::Aimbot::SmoothY, 0.f, 100.f, "%0.2f\xC2\xB0");
//
//                            edited::SliderFloat(U8("����ǿ��"), &Configs::Aimbot::SmoothInt, 0.f, 100.f, "%0.2f\xC2\xB0");
//                        }
//                        edited::EndChild();
//                        ImGui::SameLine();
//                        edited::BeginChild(U8("�����Ӿ�"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            edited::CheckboxWithPopup(true, U8("FOV"), "-", &Configs::Aimbot::DrawAimFov, NULL, NULL, NULL, false, true, var::col2, picker_flags);
//
//                            edited::CheckboxWithPopup(true, U8("��������"), "-", &Configs::Aimbot::AimLine, NULL, NULL, NULL, false, true, var::col2, picker_flags);
//
//
//                            edited::SliderFloat(U8("FOV��С"), &Configs::Aimbot::Fovsize, 10.f, 500.f, "%0.2f\xC2\xB0");
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
//                        edited::BeginChild(U8("����ѡ��"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("��������"), "", &Configs::Item::DrawItems, NULL, NULL, NULL, true, true, var::col12, picker_flags))
//                            {
//                                if (Configs::Item::DrawItems) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Item::DrawAiBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
//                            {
//                                if (Configs::Item::DrawAiBox) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��Һ���"), "", &Configs::Item::DrawPlayerBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
//                            {
//                                if (Configs::Item::DrawPlayerBox) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Item::DrawInteractor, NULL, NULL, NULL, true, true, var::col9, picker_flags))
//                            {
//                                if (Configs::Item::DrawInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("����������"), "", &Configs::Item::ShowInteractorInner, NULL, NULL, NULL, true, true, var::col9, picker_flags))
//                            {
//                                if (Configs::Item::ShowInteractorInner) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("���һ�κ���"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//
//                            if (edited::CheckboxWithPopup(false, U8("����������"), "", &Configs::Item::ShowInteractor, NULL, NULL, NULL, true, true, var::col8, picker_flags))
//                            {
//                                if (Configs::Item::ShowInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("���һ������"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                        }
//                        edited::EndChild();
//
//                        edited::BeginChild(U8("����ѡ��"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//                            edited::SliderInt(U8("���ʾ���"), &Configs::Item::ShowItemMaxDistance, 50, 500, "%d\xC2\xB0");
//                            edited::SliderInt(U8("���Ӿ���"), &Configs::Item::ShowDeadBoxMaxDistance, 50, 500, "%d\xC2\xB0");
//                            edited::SliderInt(U8("��������"), &Configs::Item::ShowInteractorMaxDistance, 50, 500, "%d\xC2\xB0");
//                            edited::SliderInt(U8("��ֵ����"), &Configs::Item::Valuefilter, 1000, 50000, "%d\xC2\xB0");
//                            edited::Combo(U8("��ֵ����"), &Configs::Aimbot::ValueIndex, Configs::Aimbot::ValueBadd,
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
//                        edited::BeginChild(U8("��������"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            if (edited::CheckboxWithPopup(false, U8("����ͼ��"), "", &Configs::Item::DrawItemsIco, NULL, NULL, NULL, true, true, var::col12, picker_flags))
//                            {
//                                if (Configs::Item::DrawItemsIco) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("ͼ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("������"), "", &Configs::Item::DrawDoor, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawDoor) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("�����"), "", &Configs::Item::DrawExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawExit) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("��բ��"), "", &Configs::Item::DrawTriggerExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawTriggerExit) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��բ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
//                            }
//
//                            if (edited::CheckboxWithPopup(false, U8("�߼�ֵ�����б�"), "", &Configs::Item::DrawItemValueList, NULL, NULL, NULL, true, true, var::col5, picker_flags))
//                            {
//                                if (Configs::Item::DrawItemValueList) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�߼�ֵ�����б���ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
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
//                        edited::BeginChild(U8("�����б�"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::CheckboxWithPopup(true, U8("���߹�"), "", &Configs::Item::IsToolCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("����"), "", &Configs::Item::IsBirdNest, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("��ҩ��"), "", &Configs::Item::IsAmmoBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("����Ƥ�ڴ�"), "", &Configs::Item::IsBigSnakeBag, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("��������"), "", &Configs::Item::IsBigWeaponBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("����"), "", &Configs::Item::IsComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�����"), "", &Configs::Item::IsDrawerCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("���մ�����"), "", &Configs::Item::IsAviationLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�·�"), "", &Configs::Item::IsClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsTrashBin, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("ҽ��������"), "", &Configs::Item::IsMedicalSupplies, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("���չ�"), "", &Configs::Item::BaoXianGUI, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsSuitcase, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("���ɺ�"), "", &Configs::Item::IsShouNahe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("��ɫ��ϫ������"), "", &Configs::Item::IsBlackTideWeaponCase, NULL, NULL, NULL, true, true, var::col12, picker_flags);
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
//                        edited::BeginChild(U8("�б����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::CheckboxWithPopup(true, U8("�߼�������"), "", &Configs::Item::IsPremiumLuggage, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsServer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�칫�����ɺ�"), "", &Configs::Item::IsOfficeOrganizer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//
//                            edited::CheckboxWithPopup(true, U8("����ɭ�·�"), "", &Configs::Item::IsHudsonClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�߼�������"), "", &Configs::Item::IsPremiumStorageBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�����"), "", &Configs::Item::IsExpressBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("С������"), "", &Configs::Item::IsSmallSafe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("��ɽ��"), "", &Configs::Item::IsHikingBackpack, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("ˮ�೵"), "", &Configs::Item::IsCementTruck, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("ҽ�ư�"), "", &Configs::Item::IsMedicalKit, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsHiddenStash, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�ͼ����˴����"), "", &Configs::Item::IsLowGradeLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("���͵���"), "", &Configs::Item::IsHackerComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("Ұ��ս����"), "", &Configs::Item::IsFieldSupplyBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("�󹤾ߺ�"), "", &Configs::Item::IsLargeToolBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
//                            edited::CheckboxWithPopup(true, U8("���԰�"), "", &Configs::Item::IsDianNaoBao, NULL, NULL, NULL, true, true, var::col12, picker_flags);
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
//                        edited::BeginChild(U8("ģʽ"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::Combo(U8("ģʽѡ��"), &Configs::Aimbot::ModIndex, Configs::Player::Mod, IM_ARRAYSIZE(Configs::Player::Mod), 2);
//                        }
//                        edited::EndChild();
//
//                        edited::BeginChild(U8("��ɫ����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//
//
//                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.NameColor, picker_flags);
//                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.Box2DColor, picker_flags);
//                            edited::ColorEdit4(U8("�ֳ���ɫ"), (float*)&Configs::Player::colors.WeaponColor, picker_flags);
//                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.SkeletonColor, picker_flags);
//                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.DistanceColor, picker_flags);
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
//                        edited::BeginChild(U8("Ѫ����ʽ"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
//                        {
//                            edited::Combo(U8("Ѫ����ʽ"), &Configs::Aimbot::HealthBarIndex, Configs::Aimbot::HealthStr, IM_ARRAYSIZE(Configs::Aimbot::HealthStr), 2);
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
#include <iomanip>  // ����������ʱ���ʽ��
#include <sstream>  // �����������ַ�����
#include <ctime>    // ����������ʱ�䴦��

inline void InitMenuStyle() {
    static bool initialized = false;
    if (initialized) return;
    initialized = true;

    ImGui::SetNextWindowSize(c::bg::size);
    ImGuiStyle* style = &ImGui::GetStyle();

    // �߿Ƽ�ǳ��ɫ�����ʽ���ã�������ɫ���������䣩
    style->WindowPadding = ImVec2(10, 10);
    style->ItemSpacing = ImVec2(8, 12);
    style->WindowBorderSize = 1;
    style->ScrollbarSize = 8.f;
    style->FrameRounding = 4.f;
    style->GrabRounding = 4.f;
    style->WindowRounding = 6.f;
    style->FrameBorderSize = 1;
    style->ItemInnerSpacing = ImVec2(8, 8);

    // �߿Ƽ�ǳ��ɫ��ɫ���� - ����������Ϸ�ɫ�������滻��ɫΪ��ɫ��
    ImVec4* colors = style->Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.08f, 0.10f, 0.95f);       // ��ۺ�ɫ�������滻ԭ�����ڣ�
    colors[ImGuiCol_ChildBg] = ImVec4(0.16f, 0.11f, 0.13f, 0.85f);       // �Ӵ��ڱ������滻ԭ�����ң�
    colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.18f, 0.22f, 0.50f);       // ��ܱ������滻ԭ���ң�
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.45f, 0.30f, 0.38f, 0.70f); // �����ͣ���滻ԭǳ����
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.60f, 0.40f, 0.48f, 0.80f);  // ��ܼ���滻ԭ������
    colors[ImGuiCol_TitleBg] = ImVec4(0.22f, 0.15f, 0.18f, 1.00f);        // ���ⱳ�����滻ԭ���ң�
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.38f, 0.25f, 0.32f, 1.00f);  // ���⼤��滻ԭ������
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.18f, 0.12f, 0.15f, 0.60f);    // �������������滻ԭ���ң�
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.75f, 0.45f, 0.58f, 0.60f);  // ���������飨�滻ԭǳ����
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.80f, 0.50f, 0.65f, 0.70f); // ������ͣ���滻ԭ������
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.85f, 0.55f, 0.70f, 0.80f);  // ���鼤��滻ԭ������
    colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.70f, 0.85f, 1.00f);      // ��ѡ��ǣ��滻ԭ������
    colors[ImGuiCol_SliderGrab] = ImVec4(0.95f, 0.60f, 0.78f, 0.80f);     // ���飨�滻ԭǳ����
    colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.65f, 0.82f, 1.00f); // ���鼤��滻ԭ������
    colors[ImGuiCol_Button] = ImVec4(0.55f, 0.35f, 0.45f, 0.40f);         // ��ť���滻ԭ���ϣ�
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.70f, 0.45f, 0.58f, 0.60f);  // ��ť��ͣ���滻ԭ������
    colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.65f, 0.80f);   // ��ť����滻ԭ������
    colors[ImGuiCol_Text] = ImVec4(0.95f, 0.85f, 0.90f, 0.95f);           // �ı���΢�������ɫ������
    colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.50f, 0.55f, 0.70f);   // �����ı����滻ԭ���ң�
    colors[ImGuiCol_Border] = ImVec4(0.80f, 0.50f, 0.65f, 0.50f);         // �߿��滻ԭ������
    colors[ImGuiCol_BorderShadow] = ImVec4(0.35f, 0.20f, 0.28f, 0.30f);   // �߿���Ӱ���滻ԭ������
    colors[ImGuiCol_Header] = ImVec4(0.45f, 0.30f, 0.38f, 0.50f);         // ���������滻ԭǳ����
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.60f, 0.40f, 0.48f, 0.70f);  // ��������ͣ���滻ԭ������
    colors[ImGuiCol_HeaderActive] = ImVec4(0.75f, 0.50f, 0.63f, 0.80f);   // ����������滻ԭ������
}

// ��������ȡ��ʽ���ĵ�ǰʱ���ַ�����ʱ:��:�룩
std::string GetFormattedCurrentTime() {
    // ��ȡ��ǰϵͳʱ��
    auto now = std::chrono::system_clock::now();
    std::time_t current_time = std::chrono::system_clock::to_time_t(now);

    // ת��Ϊ����ʱ�䣨Windows���ݣ�
    std::tm local_time{};
    localtime_s(&local_time, &current_time); // Windowsר�ð�ȫ����

    // ��ʽ��ʱ��Ϊ "HH:MM:SS"
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
            const ImVec2& pos = ImGui::GetWindowPos(); // �޸�������ImGui::�����ռ�
            const ImVec2& region = ImGui::GetContentRegionMax(); // �޸�������ImGui::�����ռ�
            const ImVec2& spacing = style->ItemSpacing;
            auto& drawList = *ImGui::GetBackgroundDrawList();
            const float dt = ImGui::GetIO().DeltaTime;

            // �߿Ƽ�ǳ��ɫ��񱳾����� - ����͹�Ч��������ɫ��
            drawList.AddRectFilledMultiColor(pos, pos + region,
                ImColor(252, 245, 248, 250), ImColor(250, 240, 245, 250),
                ImColor(248, 235, 242, 250), ImColor(251, 242, 246, 250),
                c::bg::rounding);


            // ���Ʒ�ɫ�߿��滻ԭ��ɫ�߿�
            drawList.AddRect(pos, pos + region, ImColor(250, 150, 180, 100), c::bg::rounding, 0, 2.0f);
            drawList.AddRect(pos + ImVec2(1, 1), pos + region - ImVec2(1, 1), ImColor(255, 100, 150, 80), c::bg::rounding, 0, 1.0f);

            // ������ʱ��
            static float anim_timer = 0.0f;
            anim_timer += dt;

            // �߿Ƽ�װ��Ԫ�� - ��̬����͹���Ч����������ɫ��
            if (fmod(anim_timer, 0.07f) < dt) {
                // ������ָ�
                drawList.AddRectFilled(pos + ImVec2(145, 60), pos + region,
                    ImColor(250, 230, 240, 240), c::bg::rounding, ImDrawFlags_RoundCornersBottomRight);
                drawList.AddRectFilled(pos + ImVec2(145, 0), pos + ImVec2(region.x, 60),
                    ImColor(250, 220, 235, 240), c::bg::rounding, ImDrawFlags_RoundCornersTopRight);

                // ��ɫ�ָ��ߣ��滻ԭ��ɫ�ָ��ߣ�
                drawList.AddLine(pos + ImVec2(0, 60), pos + ImVec2(region.x, 60),
                    ImColor(255, 100, 160, 150), 1.5f);

                // ��̬����Բ�㣨�滻ԭ��ɫԲ�㣩
                drawList.AddCircle(pos + ImVec2(region.x - 30, 30), 12,
                    ImColor(255, 120, 180, 180), 32, 1.5f);
                drawList.AddCircleFilled(pos + ImVec2(region.x - 30, 30), 3,
                    ImColor(255, 80, 160, 200), 32);
            }

            // ���񱳾�Ч����������ɫ��
            drawList.PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(region), true);
            if (fmod(anim_timer, 0.12f) < dt) {
                // ��������Ч�����滻ԭ��ɫ���Σ�
                drawList.AddShadowCircle(pos + ImVec2(145, 160), 80,
                    ImColor(255, 150, 200, 20), 128, ImVec2(0, 0), 0);
                drawList.AddShadowCircle(pos + ImVec2(region.x, 160), 80,
                    ImColor(255, 180, 200, 20), 128, ImVec2(0, 0), 0);
            }
            drawList.PopClipRect();

            // ���� - �ʺ�ɫ��̬Ч��
            float time = ImGui::GetTime(); // ��ȡ��ǰʱ�����ڶ���
            float hue = (sin(time * 0.5f) + 1.0f) * 0.5f; // ����0-1��Χ��ɫ��ֵ����ʱ��仯

            // ʹ��HSV��ɫ�ռ䴴���ʺ�ɫ��Hue��0��1ѭ����Saturation��Value���ֽϸ�ֵ��
            ImColor rainbowColor = ImColor::HSV(hue, 0.8f, 0.9f, 240); // ���һ��������alphaֵ

            edited::RenderTextColor(font::inter_medium_big, pos, pos + ImVec2(145, 60),
                rainbowColor, "M S", ImVec2(0.5, 0.5));

            // ��������"M S"�����·���ʾ��ǰʱ��
            static std::string current_time_str;
            static float time_update_timer = 0.0f;
            // ÿ0.5�����һ��ʱ�䣨ƽ��ʵʱ�Ժ����ܣ�
            time_update_timer += dt;
            if (time_update_timer >= 0.5f) {
                current_time_str = GetFormattedCurrentTime();
                time_update_timer = 0.0f;
            }
            // ����ʱ�䣨λ�ڱ����·�10���أ�ˮƽ���У�ǳ��ɫ�ı���
            edited::RenderTextColor(
                font::inter_medium_big,  // ʹ���������ͬ������
                pos + ImVec2(0, 30),     // Y��ƫ��30���أ������·���
                pos + ImVec2(145, 60),   // �����ͬ���ײ�����ָ���
                ImColor(255, 180, 200, 240), // ǳ��ɫ�ı�������UI
                current_time_str.c_str(),
                ImVec2(0.5, 0.5)         // ˮƽ����
            );

            ImGui::SetCursorPos(ImVec2(10, 70));
            ImGui::BeginGroup(); // �������������ռ�

            {
                ID3D11ShaderResourceView* pageShortcuts[6] = { texture::ragebot, texture::legitbot, texture::visuals, texture::misc, texture::world, texture::settings };
                for (int i = 0; i < 5; i++) if (edited::Pages(i == var::page, var::pageNames[i], pageShortcuts[i], var::buttonSize)) var::page = i;
            }
            ImGui::EndGroup(); // ����ImGui::�����ռ�
            ImGui::SetCursorPos(ImVec2(region.x - (145 / 2), 60 - 35) / 2);
            var::tab_alpha = ImClamp(var::tab_alpha + (15.f * ImGui::GetIO().DeltaTime * (var::page == var::active_tab ? 1.f : -1.f)), 0.f, 1.f);
            if (var::tab_alpha == 0.f && var::tab_add == 0.f) var::active_tab = var::page;

            var::tab_right = ImLerp(var::tab_right, var::page == var::active_tab ? 0.f : c::bg::size.x, ImGui::GetIO().DeltaTime * 13.f);
            var::tab_left = ImLerp(var::tab_left, var::interactive ? c::bg::size.x : 0.f, ImGui::GetIO().DeltaTime * 13.f);

            if (var::tab_alpha == 0.f) var::interactive = true;
            if (var::interactive && var::tab_left >= (c::bg::size.x - 0.6f)) var::interactive = false;

            ImGui::SetCursorPos(!var::interactive ? ImVec2(145.f + var::tab_right, 60.f) : ImVec2(-c::bg::size.x + (145.f + var::tab_left), 60.f));

            ImGui::PushClipRect(pos + ImVec2(145, 60), pos + ImVec2(c::bg::size.x, c::bg::size.y), true); // ����ImGui::�����ռ�

            ImGui::BeginChild("MENU", ImVec2(region.x - 145, region.y - 60));
            {

                if (var::active_tab == 0)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("�Ӿ�ѡ��"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            if (edited::CheckboxWithPopup(false, U8("���Ʒ���"), description_test.c_str(), &Configs::Player::DrawBox2D, &var::key[0], &var::m[0], &var::value[0], true, true, var::col0, picker_flags))
                            {
                                if (Configs::Player::DrawBox2D) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("����͸�ӿ����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            };


                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::DrawBone, &var::key[1], &var::m[1], &var::value[1], true, true, (float*)&Configs::Player::colors.SkeletonColor, picker_flags | ImGuiColorEditFlags_NoAlpha)) {

                                if (Configs::Player::DrawBone) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("����͸�ӿ����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��ʾѪ��"), "", &Configs::Player::DrawHealth, NULL, NULL, NULL, true, true, var::col2, picker_flags))
                            {
                                if (Configs::Player::DrawHealth) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("Ѫ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("����ͷ��"), "", &Configs::Player::DrawEquipment, NULL, NULL, NULL, true, true, var::col11, picker_flags))
                            {
                                if (Configs::Player::DrawEquipment) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("ͷ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("ͼ��ͷ��"), "", &Configs::Player::DrawEquipmentIco, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawEquipmentIco) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�ֳ�ͼ����ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::DrawPlayerName, NULL, NULL, NULL, true, true, var::col0, picker_flags))
                            {
                                if (Configs::Player::DrawPlayerName) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();

                    ImGui::SameLine();

                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("ѡ�����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("�����ֳ�"), "", &Configs::Player::DrawWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawWeapon) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�ֳ���ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }
                            if (edited::CheckboxWithPopup(false, U8("ͼ���ֳ�"), "", &Configs::Player::DrawWeaponICO, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawWeaponICO) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�ֳ�ͼ����ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��ʾ�Ŷ�"), "", &Configs::Player::DrawTeam, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawTeam) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�Ŷ���ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::ShowDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::ShowDistance) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }


                            if (edited::CheckboxWithPopup(false, U8("��Ұָʾ"), "", &Configs::Player::isShowOutSight, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::isShowOutSight) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��Ұָʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��ͼ�״�"), "", &Configs::Player::Dituradar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::Dituradar) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��ͼ�״￪���ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            edited::SliderInt(U8("�����ʾ����"), &Configs::Player::playerdis, 10, 1000, "%d\xC2\xB0");
                        }
                        edited::EndChild();



                    }

                    ImGui::EndGroup();

                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("NPC����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("NPC�ܿ���"), "", &Configs::Player::DrawAI, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawAI) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("AI��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            // ������ʾ
                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCSkeleton, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCSkeleton) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻����������ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // ������ʾ
                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCName, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCName) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻����ƿ����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // �ֳ�������ʾ
                            if (edited::CheckboxWithPopup(false, U8("�˻��ֳ�"), "", &Configs::Player::displayNPCWeapon, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCWeapon) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻��ֳ�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // ������ʾ
                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCDistance, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCDistance) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }


                        }
                        edited::EndChild();
                    }

                    ImGui::EndGroup();

                    ImGui::SameLine();

                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("NPCѡ��2"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            // ������ʾ
                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Player::displayNPCBox, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCBox) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // Ѫ����ʾ
                            if (edited::CheckboxWithPopup(false, U8("�˻�Ѫ��"), "", &Configs::Player::displayNPCHealthBar, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::displayNPCHealthBar) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�˻�Ѫ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            // ��ʾ����
                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Player::DrawEyu, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Player::DrawEyu) {
                                    notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ��ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status));
                                }
                            }

                            edited::SliderInt(U8("�˻���ʾ����"), &Configs::Player::AIDis, 10, 1000, "%d\xC2\xB0");
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

                            edited::CheckboxWithPopup(true, U8("��������"), "-", &Configs::Aimbot::DoAimbot, NULL, NULL, NULL, false, true, var::col2, picker_flags);

                            edited::Combo(U8("���鲿λ"), &Configs::Aimbot::AimIndex, Configs::Aimbot::AimBith, IM_ARRAYSIZE(Configs::Aimbot::AimBith), 4);

                            edited::Combo(U8("�����ȼ�"), &Configs::Aimbot::KeyIndex, Configs::Aimbot::KeyBad, IM_ARRAYSIZE(Configs::Aimbot::KeyBad), 4);


                            edited::Combo(U8("��������"), &Configs::Aimbot::AimModIndex, Configs::Aimbot::AimMod, IM_ARRAYSIZE(Configs::Aimbot::AimMod), 1);


                            edited::SliderFloat(U8("���X����"), &Configs::Aimbot::Smooth, 0, 100.f, "%0.2f\xC2\xB0");

                            edited::SliderFloat(U8("���Y����"), &Configs::Aimbot::SmoothY, 0.f, 100.f, "%0.2f\xC2\xB0");

                            edited::SliderFloat(U8("����ǿ��"), &Configs::Aimbot::SmoothInt, 0.f, 100.f, "%0.2f\xC2\xB0");
                        }
                        edited::EndChild();
                        ImGui::SameLine();
                        edited::BeginChild(U8("�����Ӿ�"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            edited::CheckboxWithPopup(true, U8("FOV"), "-", &Configs::Aimbot::DrawAimFov, NULL, NULL, NULL, false, true, var::col2, picker_flags);

                            edited::CheckboxWithPopup(true, U8("��������"), "-", &Configs::Aimbot::AimLine, NULL, NULL, NULL, false, true, var::col2, picker_flags);


                            edited::SliderFloat(U8("FOV��С"), &Configs::Aimbot::Fovsize, 10.f, 500.f, "%0.2f\xC2\xB0");

                        }
                        edited::EndChild();
                    }
                    ImGui::EndGroup();
                }
                else if (var::active_tab == 1)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("����ѡ��"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("��������"), "", &Configs::Item::DrawItems, NULL, NULL, NULL, true, true, var::col12, picker_flags))
                            {
                                if (Configs::Item::DrawItems) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("�˻�����"), "", &Configs::Item::DrawAiBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
                            {
                                if (Configs::Item::DrawAiBox) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��Һ���"), "", &Configs::Item::DrawPlayerBox, NULL, NULL, NULL, true, true, var::col11, picker_flags))
                            {
                                if (Configs::Item::DrawPlayerBox) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��ʾ����"), "", &Configs::Item::DrawInteractor, NULL, NULL, NULL, true, true, var::col9, picker_flags))
                            {
                                if (Configs::Item::DrawInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("����������"), "", &Configs::Item::ShowInteractorInner, NULL, NULL, NULL, true, true, var::col9, picker_flags))
                            {
                                if (Configs::Item::ShowInteractorInner) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("���һ�κ���"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }


                            if (edited::CheckboxWithPopup(false, U8("����������"), "", &Configs::Item::ShowInteractor, NULL, NULL, NULL, true, true, var::col8, picker_flags))
                            {
                                if (Configs::Item::ShowInteractor) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("���һ������"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                        }
                        edited::EndChild();

                        edited::BeginChild(U8("����ѡ��"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {

                            edited::SliderInt(U8("���ʾ���"), &Configs::Item::ShowItemMaxDistance, 50, 500, "%d\xC2\xB0");
                            edited::SliderInt(U8("���Ӿ���"), &Configs::Item::ShowDeadBoxMaxDistance, 50, 500, "%d\xC2\xB0");
                            edited::SliderInt(U8("��������"), &Configs::Item::ShowInteractorMaxDistance, 50, 500, "%d\xC2\xB0");
                            edited::SliderInt(U8("��ֵ����"), &Configs::Item::Valuefilter, 1000, 50000, "%d\xC2\xB0");
                            edited::Combo(U8("��ֵ����"), &Configs::Aimbot::ValueIndex, Configs::Aimbot::ValueBadd,
                                IM_ARRAYSIZE(Configs::Aimbot::ValueBadd), 5);

                        }
                        edited::EndChild();
                    }
                    ImGui::EndGroup();
                    ImGui::SameLine();


                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("��������"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            if (edited::CheckboxWithPopup(false, U8("����ͼ��"), "", &Configs::Item::DrawItemsIco, NULL, NULL, NULL, true, true, var::col12, picker_flags))
                            {
                                if (Configs::Item::DrawItemsIco) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("ͼ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("������"), "", &Configs::Item::DrawDoor, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawDoor) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("�����"), "", &Configs::Item::DrawExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawExit) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�������ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("��բ��"), "", &Configs::Item::DrawTriggerExit, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawTriggerExit) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("��բ����ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
                            }

                            if (edited::CheckboxWithPopup(false, U8("�߼�ֵ�����б�"), "", &Configs::Item::DrawItemValueList, NULL, NULL, NULL, true, true, var::col5, picker_flags))
                            {
                                if (Configs::Item::DrawItemValueList) { notificationSystem.AddNotification(ICON_WARNING, U8("�����ɹ�"), U8("�߼�ֵ�����б���ʾ�����ɹ�"), 2000, GetColorU32(c::element::notify::green_status)); }
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

                        edited::BeginChild(U8("�����б�"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::CheckboxWithPopup(true, U8("���߹�"), "", &Configs::Item::IsToolCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("����"), "", &Configs::Item::IsBirdNest, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("��ҩ��"), "", &Configs::Item::IsAmmoBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("����Ƥ�ڴ�"), "", &Configs::Item::IsBigSnakeBag, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("��������"), "", &Configs::Item::IsBigWeaponBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("����"), "", &Configs::Item::IsComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�����"), "", &Configs::Item::IsDrawerCabinet, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("���մ�����"), "", &Configs::Item::IsAviationLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�·�"), "", &Configs::Item::IsClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsTrashBin, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("ҽ��������"), "", &Configs::Item::IsMedicalSupplies, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("���չ�"), "", &Configs::Item::BaoXianGUI, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsSuitcase, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("���ɺ�"), "", &Configs::Item::IsShouNahe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("��ɫ��ϫ������"), "", &Configs::Item::IsBlackTideWeaponCase, NULL, NULL, NULL, true, true, var::col12, picker_flags);

                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();
                    ImGui::SameLine();


                    ImGui::BeginGroup();
                    {
                        edited::BeginChild(U8("�б����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::CheckboxWithPopup(true, U8("�߼�������"), "", &Configs::Item::IsPremiumLuggage, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsServer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�칫�����ɺ�"), "", &Configs::Item::IsOfficeOrganizer, NULL, NULL, NULL, true, true, var::col12, picker_flags);

                            edited::CheckboxWithPopup(true, U8("����ɭ�·�"), "", &Configs::Item::IsHudsonClothes, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�߼�������"), "", &Configs::Item::IsPremiumStorageBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�����"), "", &Configs::Item::IsExpressBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("С������"), "", &Configs::Item::IsSmallSafe, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("��ɽ��"), "", &Configs::Item::IsHikingBackpack, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("ˮ�೵"), "", &Configs::Item::IsCementTruck, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("ҽ�ư�"), "", &Configs::Item::IsMedicalKit, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("������"), "", &Configs::Item::IsHiddenStash, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�ͼ����˴����"), "", &Configs::Item::IsLowGradeLocker, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("���͵���"), "", &Configs::Item::IsHackerComputer, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("Ұ��ս����"), "", &Configs::Item::IsFieldSupplyBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("�󹤾ߺ�"), "", &Configs::Item::IsLargeToolBox, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                            edited::CheckboxWithPopup(true, U8("���԰�"), "", &Configs::Item::IsDianNaoBao, NULL, NULL, NULL, true, true, var::col12, picker_flags);
                        }
                        edited::EndChild();

                    }
                    ImGui::EndGroup();

                }
                else if (var::active_tab == 4)
                {
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("ģʽ"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::Combo(U8("ģʽѡ��"), &Configs::Aimbot::ModIndex, Configs::Player::Mod, IM_ARRAYSIZE(Configs::Player::Mod), 2);
                        }
                        edited::EndChild();

                        edited::BeginChild(U8("��ɫ����"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {


                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.NameColor, picker_flags);
                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.Box2DColor, picker_flags);
                            edited::ColorEdit4(U8("�ֳ���ɫ"), (float*)&Configs::Player::colors.WeaponColor, picker_flags);
                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.SkeletonColor, picker_flags);
                            edited::ColorEdit4(U8("������ɫ"), (float*)&Configs::Player::colors.DistanceColor, picker_flags);


                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();

                    ImGui::SameLine();
                    ImGui::BeginGroup();
                    {

                        edited::BeginChild(U8("Ѫ����ʽ"), ImVec2((region.x - (145 + spacing.x * 3)) / 2, 0));
                        {
                            edited::Combo(U8("Ѫ����ʽ"), &Configs::Aimbot::HealthBarIndex, Configs::Aimbot::HealthStr, IM_ARRAYSIZE(Configs::Aimbot::HealthStr), 2);

                        }
                        edited::EndChild();


                    }
                    ImGui::EndGroup();

                }
                ImGui::EndChild();
            }
            ImGui::PopClipRect(); // ����ImGui::�����ռ�
        }

        ImGui::End();

    }
}
#endif