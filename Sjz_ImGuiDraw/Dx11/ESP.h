#pragma once

#include"HealthBar.h"
#include"../Engine.h"
#include"RenderHelper.h"
#include "../Utils/VectorHelper.h"
#include"../base.h"
#include"Menu/Menu.hpp"
#include"AimBot/AimBot.h"
std::vector<DrawItemListS> globalHighValueItems;
static bool* const configMap[] = {
&Configs::Item::IsToolCabinet,         // 0
&Configs::Item::IsBirdNest,             // 1
&Configs::Item::IsAmmoBox,              // 2
&Configs::Item::IsBigSnakeBag,          // 3
&Configs::Item::IsBigWeaponBox,         // 4
&Configs::Item::IsComputer,             // 5
&Configs::Item::IsDrawerCabinet,        // 6
&Configs::Item::IsAviationLocker,       // 7
&Configs::Item::IsClothes,              // 8
&Configs::Item::IsTrashBin,             // 9
&Configs::Item::IsMedicalSupplies,      // 10
&Configs::Item::IsPremiumLuggage,       // 11
&Configs::Item::IsServer,               // 12
&Configs::Item::IsOfficeOrganizer,      // 13
&Configs::Item::IsHudsonClothes,        // 14
&Configs::Item::IsPremiumStorageBox,    // 15
&Configs::Item::IsExpressBox,           // 16
&Configs::Item::IsSmallSafe,            // 17
&Configs::Item::IsHikingBackpack,       // 18
&Configs::Item::IsCementTruck,          // 19
&Configs::Item::IsMedicalKit,           // 20
&Configs::Item::IsHiddenStash,          // 21
&Configs::Item::IsLowGradeLocker,       // 22
&Configs::Item::IsSuitcase,             // 23
&Configs::Item::IsBlackTideWeaponCase,  // 24
&Configs::Item::IsFieldSupplyBox,       // 25
&Configs::Item::IsLargeToolBox,         // 26
&Configs::Item::IsDianNaoBao,           // 27
&Configs::Item::IsShouNahe              // 28
};
class ESP
{
public:
	static void DrawSkeleton(Player Player, const ImU32 SkeletonUseColor, const float Thickness)
	{
		FVector2D neckpos = Player.Skeleton.ScreenBones[BoneIndex::Neck];
		FVector2D pelvispos = Player.Skeleton.ScreenBones[BoneIndex::Hips];
		std::vector<std::pair<ImVec2, ImVec2>> Bones;
		bool failed = false;

		for (const auto& a : SkeletonLists::Skeleton)
		{
			FVector2D previous = FVector2D(0, 0);
			FVector2D current, p1, c1;



			for (BoneIndex bone : a)
			{
				current = (bone == BoneIndex::Neck) ? neckpos : (bone == BoneIndex::Hips) ? pelvispos : Player.Skeleton.ScreenBones[bone];

				if (previous.X != 0.f && previous.Y != 0.f)
				{
					p1 = previous;
					c1 = current;

					Bones.emplace_back(std::make_pair(ImVec2(p1.X, p1.Y), ImVec2(c1.X, c1.Y)));

					if (p1.X == INFINITY || p1.Y == INFINITY || c1.X == INFINITY || c1.Y == INFINITY) {
						failed = true;
						Bones.clear();
						break;
					}

				}
				previous = current;
			}

			if (failed)
				break;
		}
		for (auto& line : Bones)
		{
			RenderHelper::Line(line.first, line.second, SkeletonUseColor, Thickness);
		}
	}
	static void DrawHealthBar(DWORD Sign, float MaxHealth, float CurrentHealth, ImVec2 Pos, ImVec2 Size, ImColor Color, bool Horizontal, bool ShowBackupHealth = true)
	{
		static std::map<DWORD, HealthBar> HealthBarMap;
		if (!HealthBarMap.count(Sign))
		{
			HealthBarMap.insert({ Sign,HealthBar() });
		}
		if (HealthBarMap.count(Sign))
		{
			if (Horizontal)
				HealthBarMap[Sign].DrawHealthBar_Horizontal(MaxHealth, CurrentHealth, Pos, Size, Color, ShowBackupHealth);
			else
				HealthBarMap[Sign].DrawHealthBar_Vertical(MaxHealth, CurrentHealth, Pos, Size, Color, ShowBackupHealth);
		}
	}
	static ImVec4 Get2DBox(const Player& Player)
	{
		FVector2D Head = Player.Skeleton.ScreenBones.at(BoneIndex::Head_Joint);
		FVector2D Root = Player.Skeleton.ScreenBones.at(BoneIndex::root);

		ImVec2 Size, Pos;
		Size.y = (Root.Y - Head.Y) * 1.09;
		Size.x = Size.y * 0.6;

		Pos = ImVec2(Root.X - Size.x / 2, Head.Y - Size.y * 0.08);

		return ImVec4{ Pos.x,Pos.y,Size.x,Size.y };
	}
	static void DrawPlayers(std::unordered_map<uint64_t, Player>& Players)
	{
		int FontSize = 14.f;
		for (auto& item : Players)
		{
			Player player = item.second;
			if (player.isPlayerDead || player.IsMe)
			{

				continue;
			}
			if (Configs::Aimbot::ModIndex == 0) {

				if (player.isMycamp)
				{

					continue;
				}

			}
			else if (Configs::Aimbot::ModIndex == 1) {

				if (player.IsMyTeam)
				{

					continue;
				}
			}



			//Ai & ����ģʽ����
			if (!Configs::Player::DrawAI && player.isPlayerAi == true) continue;

			FVector2D Screen = VectorHelper::WorldToScreen(player.Location);

			bool IsScreen = VectorHelper::IsInScreen(Screen);

			float Distance = LocalData::LocalCameraData.Location.Distance(player.Location);

			const auto& bones = SkeletonLists::Bones;
			for (BoneIndex Bone : bones)
			{
				player.Skeleton.LocationBones[Bone] = VectorHelper::GetBoneWithRotation(player.Skeleton.Bones[Bone], player.ComponentToWorld);
				player.Skeleton.ScreenBones[Bone] = VectorHelper::WorldToScreen(player.Skeleton.LocationBones[Bone]);

			}

			FVector root_Position = player.Skeleton.LocationBones[BoneIndex::root];
			FVector head_Position = player.Skeleton.LocationBones[BoneIndex::Head];

			if (root_Position.IsNearlyZero() || head_Position.IsNearlyZero())
			{
				continue;
			}


			ImVec2 Pos = {
				static_cast<float>(static_cast<int>(player.Skeleton.ScreenBones[BoneIndex::root].X)),
				static_cast<float>(static_cast<int>(player.Skeleton.ScreenBones[BoneIndex::Head].Y) - 4.f)
			};
			const float Scale = (float)FontSize / 14.f;

			auto Rect = Get2DBox(player);

			float Health = player.CurrentHealthValue;
			float MaxHealth = player.MaxHealth;

			ImVec2 HealthBarPos, HealthBarSize;

			const auto h = (float)(int)player.Skeleton.ScreenBones[BoneIndex::LeftFoot].Y
				- (float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].Y,
				w = (h / 4.0f) * 2.5f,
				x = (float)(int)player.Skeleton.ScreenBones[BoneIndex::root].X - (w / 2.0f);

			const auto high = (float)(int)player.Skeleton.ScreenBones[BoneIndex::root].Y - (float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].Y;
			const auto y = (float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].Y - high / 10.f;

			ImVec2 HealthPos{};

			constexpr auto health_bar_width = 30.f; // Ѫ���Ĺ̶����
			constexpr auto health_bar_height = 4.0f;  // Ѫ���Ĺ̶��߶�
			constexpr auto example_health_max_value = 100.0f;
			const auto color_3 = ImColor{ 0, 255, 0 };
			const auto health_x = x + (w - health_bar_width) / 2.0f;
			HealthPos.x = health_x;
			HealthPos.y = y;

			if (!player.isPlayerAi)
			{
				if (player.Distance > Configs::Player::playerdis) continue;

				if (player.ExitState == 3)
				{
					continue;
				}

				if (player.IsAlive == 2.f) { continue; }

				if (Configs::Player::isShowOutSight)
				{

					FVector EnemyLocation = player.Location;
					FVector CameraLocation = LocalData::LocalCameraData.Location;
					FRotator CameraRotation = LocalData::LocalCameraData.Rotation;

					EnemyLocation = EnemyLocation - FVector(CameraLocation.X, CameraLocation.Y, 0.0f);

					float angle = RAD2DEG(atan2(EnemyLocation.Y, EnemyLocation.X));
					angle = CameraRotation.Yaw - angle;
					angle = DEG2RAD(angle);

					ImVec2 Point, Point2, Point3;
					float Width = ImGui::GetIO().DisplaySize.x / 2;
					float Height = ImGui::GetIO().DisplaySize.y / 2;
					Point.x = Width + (float)(-(100 * sin(angle)));
					Point.y = Height + (float)(-(100 * cos(angle)));//������Ƶĵ�




					Point2.x = Width + (float)(-(80 * sin(angle + 0.0625)));
					Point2.y = Height + (float)(-(80 * cos(angle + 0.0625)));//������Ƶĵ�

					Point3.x = Width + (float)(-(80 * sin(angle - 0.0625)));
					Point3.y = Height + (float)(-(80 * cos(angle - 0.0625)));//������Ƶĵ�

					ImGui::GetForegroundDrawList()->AddTriangleFilled(Point, Point2, Point3, IsScreen ? ImColor(0, 255, 0, 255) : ImColor(255, 0, 0, 255));

				}

				if (Configs::Player::Dituradar && GlobalData::preShouldDraw)
				{
					ImColor TeamColor = RenderHelper::GetColorForNumber(player.teamId);

					FVector2D ScreenPos, DirectionPos;
					ImVec2 DisplaySize = { (float)Dx11Data::ScreenWidth,(float)Dx11Data::ScreenHeight };


					if (GlobalData::radar.MapX == 330062)
					{
						RenderHelper::GetCGMapScreenPos(GlobalData::radar, DisplaySize, player.Location, player.Pitch, ScreenPos, DirectionPos);
					}
					else
					{
						RenderHelper::GetDBMapScreenPos(GlobalData::radar, DisplaySize, player.Location, player.Pitch, ScreenPos, DirectionPos);
					}

					ImGui::GetForegroundDrawList()->AddCircleFilled(ImVec2(ScreenPos.X, ScreenPos.Y), 9, TeamColor);
					ImGui::GetForegroundDrawList()->AddCircle(ImVec2(ScreenPos.X, ScreenPos.Y), 10, ImColor{ 0, 0, 0, 1 }, 0, 2);

					char name_buff[64]{ 0 };
					sprintf(name_buff, "%d", player.teamId);
					ImVec2 text_size = ImGui::CalcTextSize(name_buff);
					ImVec2 text_pos = ImVec2(ScreenPos.X - text_size.x * 0.5f, ScreenPos.Y - text_size.y * 0.5f);
					RenderHelper::StrokeText(name_buff, text_pos, ImColor{ 255, 255, 255, 255 }, 14, true, true);

					ImGui::GetForegroundDrawList()->AddLine({ ScreenPos.X, ScreenPos.Y }, { DirectionPos.X, DirectionPos.Y }, TeamColor, 5.f);

				}
				if (!IsScreen) continue;



				//���Ʒ���
				if (Configs::Player::DrawBox2D)
				{

					RenderHelper::Line(ImVec2(Rect.x, Rect.y), ImVec2(Rect.x + Rect.z, Rect.y), Configs::Player::colors.Box2DColor, 2.0f);// �Ϻ�
					RenderHelper::Line(ImVec2(Rect.x, Rect.y), ImVec2(Rect.x, Rect.y + Rect.z * 1.6), Configs::Player::colors.Box2DColor, 2.0f);// ����
					RenderHelper::Line(ImVec2(Rect.x + Rect.z, Rect.y), ImVec2(Rect.x + Rect.z, Rect.y + Rect.z * 1.6), Configs::Player::colors.Box2DColor, 2.0f);// ����
					RenderHelper::Line(ImVec2(Rect.x, Rect.y + Rect.z * 1.6), ImVec2(Rect.x + Rect.z, Rect.y + Rect.z * 1.6), Configs::Player::colors.Box2DColor, 2.0f);// ����

				}

				//���ƹ���
				if (Configs::Player::DrawBone)
				{
					ImColor BoneColor = Configs::Player::colors.SkeletonColor;

					ImVec2 Headpos = { (float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].X,
						(float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].Y };

					RenderHelper::Circle(ImVec2(Headpos.x, Headpos.y), Rect.w / 12, BoneColor, 1, 32);;
					DrawSkeleton(player, BoneColor, 1);
				}

				//ֻ��������������Ѫ��ʱ�Ż���Ѫ��
				if (Configs::Player::DrawHealth) {


					const auto rainbow_bar = [](const ImVec2& position, const ImVec2& size, const ImColor& color_1, const ImColor& color_2, const ImColor& color3, const ImColor& color4) {
						RenderHelper::window_filled_rect_multicolor_horizontal(position, { size.x / 2.0f, size.y }, color_1, color_2);
						RenderHelper::window_filled_rect_multicolor_horizontal({ position.x + size.x / 2.0f, position.y }, { size.x / 2.0f, size.y }, color3, color4);
						};

					if (Configs::Aimbot::HealthBarIndex == 0)
					{
						RenderHelper::window_filled_rect({ health_x, y - 4.f - 5.0f }, { health_bar_width, health_bar_height }, { 30, 30, 30 });

						const auto health_fill_width = (health_bar_width * Health) / MaxHealth;


						rainbow_bar
						(
							{ health_x + 1.0f, y - 4.f - 6.0f },
							{ health_fill_width - 2.0f, health_bar_height - 1.0f },
							color_3,
							Health < 30.0f ? color_3 : color_3,
							Health < 30.0f ? color_3 : color_3,
							Health < 60.0f ? color_3 : color_3
						);
					}
					else if (Configs::Aimbot::HealthBarIndex == 1)
					{
						const auto color_1 = ImColor{ 255, 0, 0 };
						const auto color_2 = ImColor{ 255, 128, 0 };
						const auto color_3 = ImColor{ 0, 255, 0 };
						//����Ѫ������
						RenderHelper::window_filled_rect({ health_x, y - 5.0f - 4.f }, { health_bar_width,health_bar_height }, { 30, 30, 30 }, 4);
						const auto health_fill_width = (health_bar_width * Health) / MaxHealth;

						rainbow_bar
						(
							{ health_x + 1.0f, y - 4.0f - 6.0f }, { (health_fill_width - 2.0f),health_bar_height - 1.0f },
							color_1,
							Health < 30.0f ? color_1 : color_2,
							Health < 30.0f ? color_1 : color_2,
							Health < 60.0f ? color_2 : color_3
						);
					}
				}

				std::string infoText = "";


				//����
				auto teamNumberColor = RenderHelper::GetColorForNumber(player.teamId);

				ImVec2 teamPos{};
				std::string TeamID = std::to_string(player.teamId);
				std::string name = player.playerName;

				if (Configs::Player::DrawTeam)
				{

					//���ƶ���
					RenderHelper::DrawRadarPlayerCircleWithText(
						TeamID.c_str(),
						teamNumberColor,
						7 * (14 / 12.f),
						{ (float)HealthPos.x - 15.f  ,  HealthPos.y - 10.f },
						0);
				}




				//Ӣ��
				if (!player.isPlayerAi)
					infoText += std::format("[{}]", player.heroName.c_str());

				infoText += name;
				Utils::Trim(infoText);


				const float originalY = y - 15.f;
				float offsetY = 0.f;
				ImVec2 HeadInfoSize1;
				ImVec2 weaponTextSize;



				if (infoText != "" && Configs::Player::DrawPlayerName)
				{
					HeadInfoSize1 = RenderHelper::StrokeText(Utils::StringToUTF8(infoText).c_str(),
						{ Pos.x, originalY - offsetY },
						Configs::Player::colors.NameColor,
						FontSize, true, true
					);
					offsetY += HeadInfoSize1.y;
				}


				if (Configs::Player::DrawWeapon && !player.weaponName.empty())
				{
					weaponTextSize = RenderHelper::StrokeText(Utils::StringToUTF8(player.weaponName).c_str(),
						{ Pos.x, originalY - offsetY },
						Configs::Player::colors.WeaponColor,
						FontSize, true, true
					);
					offsetY += weaponTextSize.y;
				}


				if (DrawWeaponList[player.WeaponID1].OVerlaycon != nullptr
					&& Configs::Player::DrawWeaponICO)
				{
					float Scale = (FontSize / 14.f);
					float TargetHeight = 14.f * Scale;
					float HeightZoom = TargetHeight / DrawWeaponList[player.WeaponID1].Height;
					float IconWidth = DrawWeaponList[player.WeaponID1].Width * HeightZoom;
					float IconHeight = TargetHeight;

					// �������λ��
					float iconX = Pos.x - IconWidth / 2;
					float iconY = originalY - offsetY - IconHeight;

					RenderHelper::Image(
						DrawWeaponList[player.WeaponID1].OVerlaycon,
						{ iconX, iconY },
						ImVec2(IconWidth, IconHeight),
						true, IM_COL32(255, 255, 255, 255), false);

					offsetY += IconHeight + 2.f;  // ����ͼ��߶�+���
				}



				Pos.y = originalY - offsetY;


				//���ǻ����������
				ImVec2 BottomPos = {
					static_cast<float>(static_cast<int>(player.Skeleton.ScreenBones[BoneIndex::root].X)),
					static_cast<float>(static_cast<int>(player.Skeleton.ScreenBones[BoneIndex::root].Y) + 2.f)
				};

				// ���ƾ�����Ϣ
				if (Configs::Player::ShowDistance)
				{
					infoText.clear();
					infoText += std::format("{}M", (int)player.Distance);

					// ���ƾ����ı�����ȡ�ߴ�
					ImVec2 distanceSize = RenderHelper::StrokeText(
						Utils::StringToUTF8(infoText).c_str(),
						{ BottomPos.x, BottomPos.y },
						Configs::Player::colors.DistanceColor,
						FontSize, true, false
					);

					// ����λ�ã������ı��·�
					BottomPos.y += distanceSize.y;
				}

				ImColor color = RenderHelper::GetColorByGrade(player.HelmeArmorLevel);
				ImColor color1 = RenderHelper::GetColorByGrade(player.ArmorLevel);
				// ����װ����Ϣ
				if (Configs::Player::DrawEquipment)
				{
					// ���װ����Ϣ�Ϸ��ļ�ࣨ���������Ϣ���ڣ�
					if (Configs::Player::ShowDistance) {
						BottomPos.y += 12.f;  // ������Ϣ��װ����Ϣ֮��ļ��
					}

					// ׼��װ���ı�
					char buf[50];


					sprintf(buf, "%dͷ(%.0f) %d��(%0.f)",
						player.HelmeArmorLevel, player.HelmetArmorHp,
						player.ArmorLevel, player.ArmorHp);
					infoText = buf;

					// ����װ���ı�����ȡ�ߴ�
					ImVec2 textSize = RenderHelper::StrokeText(
						Utils::StringToUTF8(infoText).c_str(),
						{ BottomPos.x, BottomPos.y },
						color, FontSize, true, true
					);

					// ����λ�ã�װ���ı��·�
					BottomPos.y += textSize.y;

					// ����װ��ͼ�꣨������ã�



				}
				if (Configs::Player::DrawEquipmentIco)
				{
					std::string IconUrlArmor = "Assets/Armor.png";
					std::string IconUrlHelmet = "Assets/Helmet.png";
					auto textureArmor = GImGuiTextureMap[IconUrlArmor];
					auto textureHelmet = GImGuiTextureMap[IconUrlHelmet];

					if (textureArmor.Width > 0 && textureHelmet.Width > 0)
					{
						// ��װ���ı��·���Ӽ��
						BottomPos.y -= 12.f;  // �ı���ͼ��֮��ļ��

						// �������ű���
						const float TargetHeight = 14.f;  // ͼ��߶�
						float HelmetZoom = TargetHeight / textureHelmet.Height;
						float ArmorZoom = TargetHeight / textureArmor.Height;

						// ����ͼ��ߴ�
						float HelmetWidth = textureHelmet.Width * HelmetZoom;
						float ArmorWidth = textureArmor.Width * ArmorZoom;

						// ���������Ȳ�����
						float totalWidth = HelmetWidth + ArmorWidth;
						float startX = BottomPos.x - totalWidth / 2;

						// ����ͷ��ͼ�꣨��ࣩ
						RenderHelper::Image(
							textureHelmet.Texture,
							{ startX, BottomPos.y },
							{ HelmetWidth, TargetHeight },
							true, color1, false
						);

						// ���ƻ���ͼ�꣨�Ҳࣩ
						RenderHelper::Image(
							textureArmor.Texture,
							{ startX + HelmetWidth, BottomPos.y },
							{ ArmorWidth, TargetHeight },
							true, color, false
						);

					}
				}

			}

			//�˻�ѡ��
			if (player.isPlayerAi)
			{

				if (player.Distance > Configs::Player::AIDis) continue;

				const float Scale = (float)FontSize / 14.f;
				if (player.IsAlive > 1) { continue; }
				//���������
				if (player.playerType == ECharacterType::Animal)
				{
					if (Configs::Player::DrawEyu)
					{
						std::string name = player.playerTypeInfo.name + " [";
						name = name + std::to_string((int)player.Distance) + "M]";

						RenderHelper::StrokeText(Utils::StringToUTF8(name).c_str(), { Screen.X,Screen.Y }, RenderHelper::��ɫ,
							FontSize, true, true);


						ImVec2 textPos = ImGui::CalcTextSize(name.c_str());

						name = "Boss";
						auto teamNumberColor1 = RenderHelper::GetColorForNumber(player.teamId);
						//���ƶ���
						RenderHelper::DrawRadarPlayerCircleWithText(
							name.c_str(),
							teamNumberColor1,
							7 * (14 / 12.f),
							{ (float)Screen.X  ,  Screen.Y - textPos.y - 5.f },
							0);

						continue;

					}

				}

				if (!IsScreen) continue;

				//���Ʒ���
				if (Configs::Player::displayNPCBox)
				{

					RenderHelper::Line(ImVec2(Rect.x, Rect.y), ImVec2(Rect.x + Rect.z, Rect.y), Configs::Player::colors.Box2DColor, 2.0f);// �Ϻ�
					RenderHelper::Line(ImVec2(Rect.x, Rect.y), ImVec2(Rect.x, Rect.y + Rect.z * 1.6), Configs::Player::colors.Box2DColor, 2.0f);// ����
					RenderHelper::Line(ImVec2(Rect.x + Rect.z, Rect.y), ImVec2(Rect.x + Rect.z, Rect.y + Rect.z * 1.6), Configs::Player::colors.Box2DColor, 2.0f);// ����
					RenderHelper::Line(ImVec2(Rect.x, Rect.y + Rect.z * 1.6), ImVec2(Rect.x + Rect.z, Rect.y + Rect.z * 1.6), Configs::Player::colors.Box2DColor, 2.0f);// ����

				}

				//���ƹ���
				if (Configs::Player::displayNPCSkeleton)
				{
					ImColor BoneColor = player.IsViews ? ImColor(255, 0, 0) : Configs::Player::colors.SkeletonColor;

					ImVec2 Headpos = { (float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].X,
						(float)(int)player.Skeleton.ScreenBones[BoneIndex::Head].Y };

					RenderHelper::Circle(ImVec2(Headpos.x, Headpos.y), Rect.w / 12, BoneColor, 1, 32);;
					DrawSkeleton(player, BoneColor, 1);
				}

				//ֻ��������������Ѫ��ʱ�Ż���Ѫ��
				if (Configs::Player::displayNPCHealthBar) {
					const auto rainbow_bar = [](const ImVec2& position, const ImVec2& size, const ImColor& color_1, const ImColor& color_2, const ImColor& color3, const ImColor& color4) {
						RenderHelper::window_filled_rect_multicolor_horizontal(position, { size.x / 2.0f, size.y }, color_1, color_2);
						RenderHelper::window_filled_rect_multicolor_horizontal({ position.x + size.x / 2.0f, position.y }, { size.x / 2.0f, size.y }, color3, color4);
						};

					if (Configs::Aimbot::HealthBarIndex == 0)
					{
						RenderHelper::window_filled_rect({ health_x, y - 4.f - 5.0f }, { health_bar_width, health_bar_height }, { 30, 30, 30 });

						const auto health_fill_width = (health_bar_width * Health) / MaxHealth;


						rainbow_bar
						(
							{ health_x + 1.0f, y - 4.f - 6.0f },
							{ health_fill_width - 2.0f, health_bar_height - 1.0f },
							color_3,
							Health < 30.0f ? color_3 : color_3,
							Health < 30.0f ? color_3 : color_3,
							Health < 60.0f ? color_3 : color_3
						);
					}
					else if (Configs::Aimbot::HealthBarIndex == 1)
					{
						const auto color_1 = ImColor{ 255, 0, 0 };
						const auto color_2 = ImColor{ 255, 128, 0 };
						const auto color_3 = ImColor{ 0, 255, 0 };
						//����Ѫ������
						RenderHelper::window_filled_rect({ health_x, y - 5.0f - 4.0f }, { health_bar_width,health_bar_height }, { 30, 30, 30 }, 4);
						const auto health_fill_width = (health_bar_width * Health) / MaxHealth;

						rainbow_bar
						(
							{ health_x + 1.0f, y - 4.0f - 6.0f }, { (health_fill_width - 2.0f),health_bar_height - 1.0f },
							color_1,
							Health < 30.0f ? color_1 : color_2,
							Health < 30.0f ? color_1 : color_2,
							Health < 60.0f ? color_2 : color_3
						);
					}


				}


				std::string infoText = "";


				//����
				auto teamNumberColor = RenderHelper::GetColorForNumber(player.teamId);

				ImVec2 teamPos{};
				std::string TeamID = std::to_string(player.teamId);
				std::string name = player.playerName;
				TeamID = player.playerType == ECharacterType::Boss ? "Boss" : "BOT";
				name = player.playerTypeInfo.name;

				if (Configs::Player::DrawAI)
				{

					//���ƶ���
					RenderHelper::DrawRadarPlayerCircleWithText(
						TeamID.c_str(),
						teamNumberColor,
						7 * (14 / 12.f),
						{ (float)HealthPos.x - 15.f  ,  HealthPos.y - 10.f },
						0);
				}



				infoText += name;
				Utils::Trim(infoText);

				// ����ԭʼYλ��
				const float originalY = y - 15.f;
				ImVec2 HeadInfoSize1;
				if (infoText != "" && Configs::Player::displayNPCName)
				{

					HeadInfoSize1 = RenderHelper::StrokeText(Utils::StringToUTF8(infoText).c_str(),
						{ Pos.x, originalY },
						Configs::Player::colors.NameColor,
						FontSize, true, true
					);

					Pos.y -= HeadInfoSize1.y;
				}

				if (Configs::Player::displayNPCWeapon)
				{

					float weaponY = originalY;

					if (Configs::Player::DrawPlayerName && infoText != "") {
						weaponY -= HeadInfoSize1.y;
					}

					infoText.clear();
					infoText += player.weaponName;
					RenderHelper::StrokeText(
						Utils::StringToUTF8(infoText).c_str(),
						{ Pos.x, weaponY },
						Configs::Player::colors.WeaponColor,
						FontSize, true, true
					);
				}


				//���ǻ����������
				ImVec2 BottomPos = {
					static_cast<float>(static_cast<int>(player.Skeleton.ScreenBones[BoneIndex::root].X)),
					static_cast<float>(static_cast<int>(player.Skeleton.ScreenBones[BoneIndex::root].Y) + 2.f)
				};

				if (Configs::Player::displayNPCDistance)
				{

					//���ƾ���
					infoText.clear();
					infoText += std::format("{}M", (int)player.Distance);
					ImVec2 HeadInfoSize = RenderHelper::StrokeText(Utils::StringToUTF8(infoText).c_str(), { BottomPos.x, BottomPos.y }, Configs::Player::colors.DistanceColor, FontSize, true, false);
				}

			}


			FVector2D AimScreen = Aimbot::GetInstance().screenLocation;
			if (Configs::Aimbot::DoAimbot && Configs::Aimbot::AimLine && Aimbot::GetInstance().Distance < Configs::Aimbot::Fovsize) {

				RenderHelper::Line({ Dx11Data::ScreenWidth / 2.f, Dx11Data::ScreenHeight / 2.f }, { Aimbot::GetInstance().screenLocation.X,Aimbot::GetInstance().screenLocation.Y }, ImColor(255, 255, 255), 1);
			}
			if (Configs::Aimbot::DoAimbot && Configs::Aimbot::DrawAimFov) {

				RenderHelper::DrawFov(Configs::Aimbot::Fovsize, { Dx11Data::ScreenWidth / 2.f, Dx11Data::ScreenHeight / 2.f });
			}

		}


	}
	static void DrawTitle()
	{

		std::string Scene = "Unknown";
		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			Scene = "�Ȳ���";
		}
		else
		{
			Scene = "������";
		}

		auto TextPosition = ImVec2(2, 1);
		std::string res;
		std::string temp;

		TextPosition.y += 24;

		//֡��
		char fps[0x100]{};
		sprintf(fps, "FPS:%.2f %s", ImGui::GetIO().Framerate, Scene.c_str());
		res = Utils::StringToUTF8(fps);

		RenderHelper::StrokeText(res.c_str(), TextPosition, RenderHelper::��ɫ, 16, false, false);
		TextPosition.y += 24;

		//�˺�״̬
		res = "";
		temp = GlobalData::Encrypted ? "�Ͳ���" : "������";//���Encrypted������ �˺ż���
		res = "�˺�״̬:" + temp;
		RenderHelper::StrokeText(Utils::StringToUTF8(res.c_str()).c_str(), TextPosition, RenderHelper::��ɫ, 16, false, false);
		TextPosition.y += 24;

		//ս��ģʽ
		res = "";
		temp = Configs::isFireMode ? "��" : "����";
		res = "ս��ģʽ(~):" + temp;
		RenderHelper::StrokeText(Utils::StringToUTF8(res.c_str()).c_str(), TextPosition, RenderHelper::��ɫ, 16, false, false);
		//ս��ģʽ
		TextPosition.y += 24;
		res = "";
		temp = Configs::DZT ? "��" : "����";
		res = "��ը��(~):" + temp;
		RenderHelper::StrokeText(Utils::StringToUTF8(res.c_str()).c_str(), TextPosition, RenderHelper::��ɫ, 16, false, false);


	}
	static void DrawItems(std::unordered_map<uint64_t, Item>& ItemList)
	{
		if (!Configs::Item::DrawItem) return;

		if (Configs::isFireMode) return;


		globalHighValueItems.clear();
		for (auto& entry : ItemList)
		{

			ImColor ���� = ImColor(0, 255, 0, 255);

			Item& item = entry.second;

			//�������
			item.Distance = LocalData::LocalCameraData.Location.Distance(item.Location) / 100.0f; // ���¾���

			// ����Ʒλ��ת��Ϊ��Ļ����
			item.ScreenLocation = VectorHelper::WorldToScreen(item.Location);


			if (item.itemType == ECharacterType::Item && item.disPlayItem.Grade >= Configs::Item::Gradevalves)
			{
				float distance = item.Distance;
				std::string displayName = item.disPlayItem.DisPlayName;

				ImU32 itemColor = IM_COL32(255, 255, 255, 255); // Ĭ�ϰ�ɫ
				switch (item.disPlayItem.Grade) {
				case 1: itemColor = IM_COL32(0, 255, 0, 255); break;   // ��ɫ
				case 2: itemColor = IM_COL32(0, 100, 255, 255); break; // ��ɫ
				case 3: itemColor = IM_COL32(255, 0, 255, 255); break; // ��ɫ
				case 4: itemColor = IM_COL32(255, 215, 0, 255); break; // ��ɫ
				}

				// ��ӵ�ȫ���б�
				globalHighValueItems.emplace_back(
					displayName,
					itemColor,
					distance,
					item.disPlayItem.Value,
					item.disPlayItem.OVerlaycon,
					item.disPlayItem.Width,
					item.disPlayItem.Height
				);



			}

			// �����Ʒ�Ƿ�����Ļ��
			if (!VectorHelper::IsInScreen(item.ScreenLocation)) continue;
			int FontSize = 14.f;
			switch (item.itemType)
			{
			case ECharacterType::Item:
			{


				if (!Configs::Item::DrawItem) continue;

				if (item.Distance > Configs::Item::ShowItemMaxDistance) continue;

				if (Configs::Item::DrawItems) {

					if (item.disPlayItem.Value < Configs::Item::Valuefilter) { continue; }

					if (item.disPlayItem.Grade == 99) { continue; }//���˵���Ʒ���������Ʒ������˵������Э����
					char ShowText[128];
					sprintf(ShowText, "Lv%d.%s [��:%d][%dM]",
						item.disPlayItem.Grade,
						item.disPlayItem.DisPlayName.c_str(),
						item.disPlayItem.Value,
						(int)item.Distance);

					ImColor color = RenderHelper::GetColorByGrade(item.disPlayItem.Grade);

					float Scale = (FontSize / 14.f);
					if (item.disPlayItem.OVerlaycon != nullptr && Configs::Item::DrawItemsIco)
					{
						float TargetHeight = 14.f * Scale;
						float HeightZoom = TargetHeight / item.disPlayItem.Height;
						float IconWidth = item.disPlayItem.Width * HeightZoom + 5.0f;
						float IconHeight = TargetHeight + 5.0f;

						item.ScreenLocation.X -= (FontSize + 4);
						RenderHelper::Image(
							item.disPlayItem.OVerlaycon,
							{ item.ScreenLocation.X, item.ScreenLocation.Y },
							ImVec2(IconWidth, IconHeight),
							true, IM_COL32(255, 255, 255, 255), false);


					}

					RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(),
						{ item.ScreenLocation.X,item.ScreenLocation.Y }, color, 15, true, true);



				}


				break;
			}

			case ECharacterType::DeadBox:
			{

				if (!Configs::Item::DrawDeadBox) continue;

				if (item.Distance > Configs::Item::ShowDeadBoxMaxDistance) continue;

				std::string DeadBoxName;
				if (!item.CurrentyGid)
				{
					DeadBoxName = "�˻�������";
				}
				else
				{
					DeadBoxName = "���������";

				}

				char ShowText[50];
				sprintf(ShowText, "%s [%dM]", DeadBoxName.c_str(), (int)item.Distance);

				if (Configs::Item::DrawAiBox && !item.CurrentyGid)
				{
					RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::��ɫ, 15, false, false);

				}

				if (Configs::Item::DrawPlayerBox && item.CurrentyGid)
				{
					RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::��ɫ, 15, false, false);

				}

				if (Configs::Item::ShowInteractorInner) {

					item.ScreenLocation.Y -= 15.f;
					if (item.Distance > Configs::Item::ShowDeadBoxInnerMaxDistance) continue;
					if (item.DeadBoxDisPlayItemList.size() > 0)
					{
						auto& DataList = item.DeadBoxDisPlayItemList;
						for (auto& info : DataList)
						{

							if (info.Grade == 99) { continue; }

							ImColor color = RenderHelper::GetColorByGrade(info.Grade);

							if (info.Value < Configs::Item::Valuefilter) { continue; }


							std::string DrawItemStr = "|" + info.DisPlayName;
							DrawItemStr += "[" + std::to_string(info.Value) + "��]";

							float Scale = (FontSize / 14.f);
							if (info.OVerlaycon != nullptr)
							{
								float TargetHeight = 14.f * Scale;
								float HeightZoom = TargetHeight / info.Height;
								float IconWidth = info.Width * HeightZoom;
								float IconHeight = TargetHeight;

								// ����ͼ��λ�ã��ı���ࣩ
								float iconX = item.ScreenLocation.X - IconWidth - 5.0f;  // ͼ�����ı���࣬���5����
								float iconY = item.ScreenLocation.Y + (15.0f - IconHeight) / 2;  // ��ֱ�������ı���

								RenderHelper::Image(
									info.OVerlaycon,
									{ iconX, iconY },
									ImVec2(IconWidth, IconHeight),
									true,
									IM_COL32(255, 255, 255, 255),
									false
								);
							}

							// ��ԭʼλ�û����ı�������ͼ��λ��Ӱ�죩
							RenderHelper::StrokeText(
								Utils::StringToUTF8(DrawItemStr).c_str(),
								{ item.ScreenLocation.X, item.ScreenLocation.Y },
								color,
								15,
								false,
								false
							);

							item.ScreenLocation.Y -= 15.f;
						}
					}
				}



				break;
			}

			case ECharacterType::Interactor:
			{

				if (!Configs::Item::DrawInteractor) continue;

				if (item.Distance > Configs::Item::ShowInteractorMaxDistance) continue;


				std::string InteractorName = item.InteractorName;

				bool OpenDraw = item.isOpened == 1 ? true : false;

				if (item.IsComputer && Configs::Item::IsHackerComputer)
				{
					char ShowText[128];

					string Interactorname = "���͵��� [PWD:" + std::to_string(item.ComputerPwd) + "]";
					sprintf(ShowText, "%s [%dM]", Interactorname.c_str(), (int)item.Distance);
					RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::�Ȼ�, 15, false, false);

				}


				char ShowText[128];
				sprintf(ShowText, "%s [%dM]", InteractorName.c_str(), (int)item.Distance);

				if (item.isBaoXian && Configs::Item::BaoXianGUI)
				{
					RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::����, 15, false, true);
				}


				const int index = item.InterInfo.first;
				if (index >= 0 && index < static_cast<int>(std::size(configMap))) {
					if (*configMap[index]) {
						RenderHelper::StrokeText(
							ShowText,
							{ item.ScreenLocation.X, item.ScreenLocation.Y },
							item.InterInfo.second,
							15, false, true
						);
					}
				}

				if (!OpenDraw)
				{
					continue;
				}


				if (Configs::Item::ShowInteractor) {


					item.ScreenLocation.Y -= 15.f;
					if (item.Distance > Configs::Item::ShowDeadBoxInnerMaxDistance) continue;
					//������
					if (item.InteractorDisPlayItemList.size() > 0)
					{
						auto& DataList = item.InteractorDisPlayItemList;
						for (auto& info : DataList)
						{
							if (info.Value < Configs::Item::Valuefilter) { continue; }
							if (info.Grade == 99) { continue; }
							ImColor color = RenderHelper::GetColorByGrade(info.Grade);

							std::string DrawItemStr = "|" + info.DisPlayName;
							DrawItemStr += "[" + std::to_string(info.Value) + "��]";

							float Scale = (FontSize / 14.f);
							if (info.OVerlaycon != nullptr)
							{
								float TargetHeight = 14.f * Scale;
								float HeightZoom = TargetHeight / info.Height;
								float IconWidth = info.Width * HeightZoom;
								float IconHeight = TargetHeight;

								// ����ͼ��λ�ã��ı���ࣩ
								float iconX = item.ScreenLocation.X - IconWidth - 5.0f;  // ͼ�����ı���࣬���5����
								float iconY = item.ScreenLocation.Y + (15.0f - IconHeight) / 2;  // ��ֱ�������ı���

								RenderHelper::Image(
									info.OVerlaycon,
									{ iconX, iconY },
									ImVec2(IconWidth, IconHeight),
									true,
									IM_COL32(255, 255, 255, 255),
									false
								);
							}
							RenderHelper::StrokeText(Utils::StringToUTF8(DrawItemStr).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, color, 15, false, false);

							item.ScreenLocation.Y -= 15.f;
						}

					}
				}



				break;
			}
			//�����
			case ECharacterType::Exit:
			{
				if (!Configs::Item::DrawExit) continue;
				if (item.Distance > Configs::Item::ShowExitMaxDistance) continue;
				int ExitState = (int)item.ExitState;
				if ((int)ExitState != 2)
				{
					continue;
				}

				char ShowText[128];
				sprintf(ShowText, "%s [%dM]", "�����", (int)item.Distance);

				RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::����, 15, true, false);

				break;
			}

			case ECharacterType::TriggerExit:
			{
				if (!Configs::Item::DrawTriggerExit) continue;
				if (item.Distance > Configs::Item::ShowTriggerExitMaxDistance) continue;


				char ShowText[128];
				sprintf(ShowText, "%s [%dM]", "��բ��", (int)item.Distance);

				RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::����, 17, true, false);

				break;
			}

			case ECharacterType::Door:
			{
				if (!Configs::Item::DrawDoor) continue;
				if (item.Distance > Configs::Item::ShowDoorMaxDistance) continue;

				if (item.DoorPwd < 100 || item.DoorPwd>9999) continue;
				char ShowText[128];
				sprintf(ShowText, "%s [PWD:%d] [%dM]", "������", (int)item.DoorPwd, (int)item.Distance);

				RenderHelper::StrokeText(Utils::StringToUTF8(ShowText).c_str(), { item.ScreenLocation.X,item.ScreenLocation.Y }, RenderHelper::����, 17, true, false);

				break;


			}
			default:
				break;
			}

		}

		if (Configs::Item::DrawItemValueList)
		{
			if (!globalHighValueItems.empty()) {

				std::sort(globalHighValueItems.begin(), globalHighValueItems.end(),
					[](const DrawItemListS& a, const DrawItemListS& b) {
						return a.price > b.price;
					});

				RenderHelper::showInfo(globalHighValueItems, 5);
			}
		}


	}
	static void DrawESP()
	{
		DrawTitle();

		if (GlobalData::PlayMode == EDFMGamePlayMode::GamePlayMode_SafeHouse)
		{
			return;
		}
		std::unordered_map<uint64_t, Player>PlayerList = GlobalData::GetPlayers();//������ָ��Ļ�������0����Ӱ��
		std::unordered_map<uint64_t, Item> ItemList = GlobalData::GetItems();
		DrawPlayers(PlayerList);
		DrawItems(ItemList);
	}

};