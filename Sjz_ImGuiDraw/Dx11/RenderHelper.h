#pragma once
#include"../Utils/Utils.hpp"
#include"../Class.h"

#include"Texture.h"
namespace RenderHelper {


	inline ImU32 红色 = ImGui::ColorConvertFloat4ToU32(ImColor(255, 0, 0, 255));
	inline ImU32 紫色 = ImGui::ColorConvertFloat4ToU32(ImColor(128, 0, 128, 255));
	inline ImU32 黄色 = ImGui::ColorConvertFloat4ToU32(ImColor(255, 255, 0, 255));
	inline ImU32 白色 = ImGui::ColorConvertFloat4ToU32(ImColor(255, 255, 255, 255));
	inline ImU32 天蓝 = ImGui::ColorConvertFloat4ToU32(ImColor(135, 206, 250, 255));
	inline ImU32 深青 = ImGui::ColorConvertFloat4ToU32(ImColor(0, 139, 139, 255));
	inline ImU32 绿色 = ImGui::ColorConvertFloat4ToU32(ImColor(0, 255, 0, 255));
	inline ImU32 橙黄 = ImGui::ColorConvertFloat4ToU32(ImColor(255, 165, 0, 255));

	inline ImColor GetColorByGrade(int Grade)
	{
		switch (Grade)
		{
		case 1:  
			return ImColor(150, 150, 150, 255);  // 中性灰

		case 2:   // 良好
			return ImColor(65, 175, 255, 255);   // 亮蓝色

		case 3:   // 优质
			return ImColor(100, 230, 90, 255);   // 鲜绿色

		case 4:   // 稀有
			return ImColor(180, 80, 220, 255);   // 紫罗兰色

		case 5:   // 史诗
			return ImColor(255, 170, 40, 255);   // 琥珀金

		case 6:   // 传说
			return ImColor(255, 70, 90, 255);    // 火焰红

		default:  // 默认
			return ImColor(245, 245, 245, 255);  // 暖白色
		}
	}
	inline ImU32 GetColorForNumber(int number) {
		switch (number) {
		case 1:  return IM_COL32(247, 248, 19, 255);    // Yellow
		case 2:  return IM_COL32(250, 127, 73, 255);    // Orange
		case 3:  return IM_COL32(90, 198, 227, 255);    // Light Blue
		case 4:  return IM_COL32(90, 189, 77, 255);     // Green
		case 5:  return IM_COL32(225, 99, 120, 255);    // Pink
		case 6:  return IM_COL32(115, 129, 168, 255);   // Purple
		case 7:  return IM_COL32(159, 126, 105, 255);   // Indigo
		case 8:  return IM_COL32(255, 134, 200, 255);   // Light Cyan
		case 9:  return IM_COL32(210, 224, 191, 255);   // Pale Green
		case 10: return IM_COL32(154, 52, 142, 255);    // Violet
		case 11: return IM_COL32(98, 146, 158, 255);       // Red
		case 12: return IM_COL32(226, 214, 239, 255);       // Green
		case 13: return IM_COL32(4, 167, 119, 255);       // Blue
		case 14: return IM_COL32(115, 113, 252, 255);     // Yellow
		case 15: return IM_COL32(255, 0, 255, 255);     // Magenta
		case 16: return IM_COL32(93, 46, 140, 255);     // Cyan
		case 17: return IM_COL32(0, 255, 0, 255);       // Lime
		case 18: return IM_COL32(0, 0, 255, 255);       // Blue
		case 19: return IM_COL32(255, 165, 0, 255);     // Orange
		case 20: return IM_COL32(128, 0, 128, 255);     // Purple
		case 21: return IM_COL32(255, 192, 203, 255);   // Pink
		case 22: return IM_COL32(128, 128, 0, 255);     // Olive
		case 23: return IM_COL32(255, 215, 0, 255);     // Gold
		case 24: return IM_COL32(75, 0, 130, 255);      // Indigo
		case 25: return IM_COL32(0, 191, 255, 255);     // Deep Sky Blue
		case 26: return IM_COL32(255, 105, 180, 255);   // Hot Pink
		case 27: return IM_COL32(139, 69, 19, 255);     // Saddle Brown
		case 28: return IM_COL32(220, 20, 60, 255);     // Crimson
		case 29: return IM_COL32(0, 255, 127, 255);     // Spring Green
		case 30: return IM_COL32(0, 250, 154, 255);     // Medium Spring Green
		case 31: return IM_COL32(72, 61, 139, 255);     // Dark Slate Blue
		case 32: return IM_COL32(143, 188, 143, 255);   // Dark Sea Green
		case 33: return IM_COL32(178, 34, 34, 255);     // Firebrick
		case 34: return IM_COL32(153, 50, 204, 255);    // Dark Orchid
		case 35: return IM_COL32(233, 150, 122, 255);   // Dark Salmon
		case 36: return IM_COL32(148, 0, 211, 255);     // Dark Violet
		case 37: return IM_COL32(95, 158, 160, 255);    // Cadet Blue
		case 38: return IM_COL32(127, 255, 212, 255);   // Aquamarine
		case 39: return IM_COL32(218, 112, 214, 255);   // Orchid
		case 40: return IM_COL32(244, 164, 96, 255);    // Sandy Brown
		case 41: return IM_COL32(210, 105, 30, 255);    // Chocolate
		case 42: return IM_COL32(222, 184, 135, 255);   // Burlywood
		case 43: return IM_COL32(255, 228, 181, 255);   // Moccasin
		case 44: return IM_COL32(255, 239, 213, 255);   // Papaya Whip
		case 45: return IM_COL32(175, 238, 238, 255);   // Pale Turquoise
		case 46: return IM_COL32(100, 149, 237, 255);   // Cornflower Blue
		case 47: return IM_COL32(219, 112, 147, 255);   // Pale Violet Red
		case 48: return IM_COL32(173, 216, 230, 255);   // Light Blue
		case 49: return IM_COL32(240, 128, 128, 255);   // Light Coral
		case 50: return IM_COL32(255, 248, 220, 255);   // Cornsilk
		default: return IM_COL32(102, 102, 102, 255);   // Gray
		}
	}

	ImColor GetTeamColor(int TeamID)
	{
		switch (TeamID)
		{
		case 0:
			return ImColor(247, 174, 9);
		case 1:
			return ImColor(5, 179, 250);
		case 2:
			return ImColor(124, 4, 251);
		case 3:
			return ImColor(252, 61, 250);
		case 4:
			return ImColor(252, 63, 38);
		}
		return ImColor(0, 229, 255);
	}

	struct PlayerColor {
		ImColor infoUseColor;
		ImColor skeletonUseColor;
		bool isUseTeamNumberColor;
		ImColor teamNumberColor;
	};


	void GetDBMapScreenPos(Mapinfo Map, ImVec2 DisplaySize, FVector Pos, float Pitch, FVector2D& ScreenPos, FVector2D& Direction) {
		ImVec2 MapPos = { float(Map.MapX) + Pos.X - Map.X ,float(Map.MapY) + Pos.Y - Map.Y };
		ScreenPos = { MapPos.x / Map.W * DisplaySize.x,MapPos.y / Map.H * DisplaySize.y };
		Direction = FVector2D(ScreenPos.X + cos(Pitch * M_PI / 180) * 22, ScreenPos.Y + sin(Pitch * M_PI / 180) * 22);
	}

	void GetCGMapScreenPos(Mapinfo Map, ImVec2 DisplaySize, FVector Pos, float Pitch, FVector2D& ScreenPos, FVector2D& Direction) {
		ImVec2 MapPos = { float(Map.MapX) * 1.00675f - Pos.Y - Map.X  ,float(Map.MapY) * 0.99805f + Pos.X - Map.Y };
		ScreenPos = { MapPos.x / Map.W * DisplaySize.x,MapPos.y / Map.H * DisplaySize.y };
		Direction = FVector2D(ScreenPos.X + cos(Pitch * M_PI / 180) * 22, ScreenPos.Y + sin(Pitch * M_PI / 180) * 22);
	}

	inline void DrawDashboardProgress(ImVec2 center, float radius, float thickness, int num_ticks, float tick_length, float progress, ImColor color)
	{
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		auto CursorScreenPos = ImGui::GetCursorScreenPos();

		center.x += CursorScreenPos.x;
		center.y += CursorScreenPos.y;

		float radiu_num = 5.0f;
		float min_angle = -PI / radiu_num; // 起始角度（弧度）
		float max_angle = PI / radiu_num; // 结束角度（弧度）

		// 调整进度条半径，使其在视觉上更接近于刻度线
		float progress_radius = radius - tick_length / 2;

		// 计算进度条覆盖的弧度范围，基于进度
		float progress_min_angle = PI / radiu_num; // 进度条起始角度保持不变
		float progress_max_angle = progress_min_angle + (-PI / (radiu_num / 2)) * progress; // 根据进度调整结束角度

		// 绘制进度条
		draw_list->PathArcTo(center, progress_radius, progress_min_angle, progress_max_angle, 100); // 使用100个分段来平滑圆弧
		draw_list->PathStroke(color, 0, tick_length - 2); // 绘制进度条，颜色为红色

		// 大刻度的长度和厚度
		float major_tick_length = tick_length; // 大刻度的长度
		float major_tick_thickness = thickness; // 大刻度的厚度

		// 计算每个大刻度的位置
		int ticks_per_major_tick = num_ticks / 4; // 因为需要在起始和结束位置之间均匀分布4个大刻度，所以我们将总刻度数分成3段

		for (int i = 0; i <= num_ticks; ++i) {
			float fraction = (float)i / (float)num_ticks;
			float angle = min_angle + (max_angle - min_angle) * fraction;

			// 判断当前刻度是否为大刻度的位置
			bool is_major_tick = i % ticks_per_major_tick == 0 || i == num_ticks;
			float current_tick_length = is_major_tick ? major_tick_length : tick_length;
			float current_thickness = is_major_tick ? major_tick_thickness : thickness;

			// 刻度的起点和终点
			ImVec2 tick_start(
				center.x + cos(angle) * (radius - current_tick_length),
				center.y + sin(angle) * (radius - current_tick_length)
			);
			ImVec2 tick_end(
				center.x + cos(angle) * radius,
				center.y + sin(angle) * radius
			);

			// 绘制刻度线
			draw_list->AddLine(tick_start, tick_end, is_major_tick ? IM_COL32(255, 255, 255, 255) : IM_COL32(255, 255, 255, 0), current_thickness);
		}

		// 绘制右半圆形的外围轮廓
		draw_list->PathArcTo(center, radius, min_angle, max_angle, num_ticks);
		draw_list->PathStroke(IM_COL32(255, 255, 255, 255), 0, thickness);
	}

	static ULONGLONG prevTick = 0;
	static float currentHue = 0.0f;
	inline void DrawFov(float FovSize, FVector2D Possize) {
		ImVec2 center = { Possize.X, Possize.Y };
		float radius = FovSize;

		ULONGLONG currentTick = GetTickCount64();
		float deltaTime = (currentTick - prevTick) / 1000.0f;
		prevTick = currentTick;


		currentHue += deltaTime * 0.5f;
		if (currentHue > 1.0f) currentHue -= 1.0f;


		const int segments = 64;
		const float thickness = 2.0f;

		for (int i = 0; i < segments; ++i) {
			float segmentHue = currentHue + static_cast<float>(i) / segments;
			if (segmentHue > 1.0f) segmentHue -= 1.0f;

			ImColor color = ImColor::HSV(segmentHue, 0.9f, 1.0f);

			float angle = 2.0f * IM_PI * i / segments;
			ImVec2 p1 = {
				center.x + cosf(angle) * radius,
				center.y + sinf(angle) * radius
			};
			ImVec2 p2 = {
				center.x + cosf(angle + 2.0f * IM_PI / segments) * radius,
				center.y + sinf(angle + 2.0f * IM_PI / segments) * radius
			};


			ImGui::GetForegroundDrawList()->AddLine(p1, p2, IM_COL32(static_cast<int>(color.Value.x * 255),
				static_cast<int>(color.Value.y * 255), static_cast<int>(color.Value.z * 255), 255), thickness);
		}



		ImGui::GetForegroundDrawList()->AddCircleFilled(center, 4.0f, IM_COL32(255, 255, 255, 255));
	}

	inline void DrawInvertedTriangle(ImVec2 position, float size, ImColor color) {
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		auto DrawList = ImGui::GetWindowDrawList();

		auto CursorScreenPos = ImGui::GetCursorScreenPos();
		//CursorScreenPos.x -= 8;
		//CursorScreenPos.y -= 8;

		ImVec2 p1 = ImVec2(position.x, position.y + size / 2);
		ImVec2 p2 = ImVec2(position.x + size / 2, position.y - size / 2);
		ImVec2 p3 = ImVec2(position.x - size / 2, position.y - size / 2);


		draw_list->AddTriangle(p1, p2, p3, ImColor(45, 45, 45, 220), 1.0f);

		draw_list->AddTriangleFilled(p1, p2, p3, color);
	};

	inline void Line(ImVec2 Pos1, ImVec2 Pos2, ImU32 Color, float Thickness)
	{
		

		ImGui::GetForegroundDrawList()->AddLine({ Pos1.x, Pos1.y }, { Pos2.x, Pos2.y }, Color, Thickness);
	
	}

	inline void PolyLine(std::vector<ImVec2> Points, ImU32 Color, float Thickness)
	{
		if (Points.empty()) {
			return;
		}

		auto DrawList = ImGui::GetWindowDrawList();
		//DrawList->PathClear();

		auto CursorScreenPos = ImGui::GetCursorScreenPos();
		//CursorScreenPos.x -= 8;
		//CursorScreenPos.y -= 8;

		for (auto& Point : Points)
		{
			Point.x += CursorScreenPos.x;
			Point.y += CursorScreenPos.y;

			//DrawList->PathLineTo(Point);
		}

		//DrawList->PathStroke(Color, true, Thickness);
		DrawList->AddPolyline(Points.data(), Points.size(), Color, ImDrawFlags_None, Thickness);
	}


	inline void AddImageRotated(ImTextureID tex_id, ImVec2 center, ImVec2 size, float angle, bool isWindowDrawList = true) {
		ImDrawList* DrawList;

		if (!isWindowDrawList)
		{
			DrawList = ImGui::GetBackgroundDrawList();
		}
		else {
			DrawList = ImGui::GetWindowDrawList();
			auto CursorScreenPos = ImGui::GetCursorScreenPos();
			center = {
				CursorScreenPos.x + center.x,
				CursorScreenPos.y + center.y
			};
		}

		float sin_a = sinf(angle), cos_a = cosf(angle);
		

		//DrawList->AddImageQuad(tex_id, pos[0], pos[1], pos[2], pos[3]);
	};

	inline void window_filled_rect_multicolor_horizontal(const ImVec2& position, const ImVec2& size, const ImColor& color1, const ImColor& color2)
	{
		auto DrawList = ImGui::GetBackgroundDrawList();

		DrawList->AddRectFilledMultiColor({ position.x, position.y }, { position.x + size.x, position.y + size.y }, color1, color2, color2, color1);
	}

	inline void window_filled_rect(const ImVec2& position, const ImVec2& size, const ImColor& color, const float& rounding = 0.0f, const ImDrawFlags_& flags = ImDrawFlags_None)
	{
		auto DrawList = ImGui::GetBackgroundDrawList();

		DrawList->AddRectFilled({ position.x, position.y }, { position.x + size.x, position.y + size.y }, color, rounding, flags);
	}

	inline void Image(const ImTextureID& Texture, ImVec2 Pos, ImVec2 Size, bool UseColorOverlay = false, const ImU32& Color = IM_COL32(255, 255, 255, 255), bool isWindowDrawList = true)
	{
		ImDrawList* DrawList;

		if (!isWindowDrawList)
		{
			DrawList = ImGui::GetBackgroundDrawList();
		}
		else {
			DrawList = ImGui::GetWindowDrawList();
			auto CursorScreenPos = ImGui::GetCursorScreenPos();

			Pos = {
				CursorScreenPos.x + Pos.x,
				CursorScreenPos.y + Pos.y
			};
		}

		Size = ImVec2(Pos.x + Size.x, Pos.y + Size.y);
		if (UseColorOverlay)
		{
			DrawList->AddImage((void*)Texture, Pos, Size, ImVec2(0, 0), ImVec2(1, 1), Color);
		}
		else {
			DrawList->AddImage((void*)Texture, Pos, Size);
		}
	}

	inline void Circle(ImVec2 Pos, float Radius, ImColor Color, float Thickness, int Num)
	{
		auto DrawList = ImGui::GetForegroundDrawList();
		//auto CursorScreenPos = ImGui::GetCursorScreenPos();
		////CursorScreenPos.x -= 8;
		////CursorScreenPos.y -= 8;

		//Pos = {
		//	CursorScreenPos.x + Pos.x,
		//	CursorScreenPos.y + Pos.y
		//};

		DrawList->AddCircle(Pos, Radius, Color, Num, Thickness);
	}

	inline void CircleFilled(ImVec2 Pos, float Radius, ImColor Color, int Num)
	{
		auto DrawList = ImGui::GetForegroundDrawList();
		auto CursorScreenPos = ImGui::GetCursorScreenPos();
		//CursorScreenPos.x -= 8;
		//CursorScreenPos.y -= 8;

		Pos = {
			CursorScreenPos.x + Pos.x,
			CursorScreenPos.y + Pos.y
		};

		DrawList->AddCircleFilled(Pos, Radius, Color, Num);
	}

	inline ImVec2 OSText(const char* Text, ImVec2 Pos, ImColor Color, float FontSize, bool Centered, bool AdjustHeight)
	{
		auto DrawList = ImGui::GetForegroundDrawList();
		
		if (!Centered && !AdjustHeight)
		{
			const ImVec2 TextSize = ImGui::GetFont()->CalcTextSizeA(FontSize, FLT_MAX, 0.f, Text);
			DrawList->AddText(ImGui::GetFont(), FontSize, {Pos.x, Pos.y}, Color, Text);
			return TextSize;
		}
		else
		{
			float TextWidth = ImGui::GetFont()->CalcTextSizeA(FontSize, FLT_MAX, 0.f, Text).x;
			const ImVec2 TextSize = ImGui::GetFont()->CalcTextSizeA(FontSize, FLT_MAX, 0.f, Text);

			const auto HorizontalOffset = Centered ? TextSize.x / 2 : 0.0f;
			const auto VerticalOffset = AdjustHeight ? TextSize.y : 0.0f;

			ImVec2 Pos_ = { Pos.x - HorizontalOffset, Pos.y - VerticalOffset };
			DrawList->AddText(ImGui::GetFont(), FontSize, Pos_, Color, Text);
			return TextSize;
		}
	}

	inline ImVec2 StrokeText(const char* Text, ImVec2 Pos, ImColor Color, float FontSize, bool Centered = true, bool AdjustHeight = true,bool isStrke=false)
	{


			OSText(Text, ImVec2(Pos.x + 1, Pos.y), IM_COL32_BLACK, FontSize, Centered, AdjustHeight);
			OSText(Text, ImVec2(Pos.x - 1, Pos.y), IM_COL32_BLACK, FontSize, Centered, AdjustHeight);
			OSText(Text, ImVec2(Pos.x, Pos.y + 1), IM_COL32_BLACK, FontSize, Centered, AdjustHeight);
			OSText(Text, ImVec2(Pos.x, Pos.y - 1), IM_COL32_BLACK, FontSize, Centered, AdjustHeight);

		
		
		return OSText(Text, Pos, Color, FontSize, Centered, AdjustHeight);
	}

	inline void DrawTriangle(ImVec2& p1, ImVec2& p2, ImVec2& p3, ImU32 col, bool filled = false) {
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		auto CursorScreenPos = ImGui::GetCursorScreenPos();

		p1.x += CursorScreenPos.x;
		p1.y += CursorScreenPos.y;

		p2.x += CursorScreenPos.x;
		p2.y += CursorScreenPos.y;

		p3.x += CursorScreenPos.x;
		p3.y += CursorScreenPos.y;

		if (filled) {
			draw_list->AddTriangleFilled(p1, p2, p3, col);
		}
		else {
			draw_list->AddTriangle(p1, p2, p3, col);
		}
	}



	inline void DrawRadarPlayerCircleWithText(const char* text, ImU32 circle_col, float radius, ImVec2 position, float angle) {
		ImDrawList* draw_list = ImGui::GetBackgroundDrawList();

		const float fontSize = radius * 1.5f;

		const ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(fontSize, FLT_MAX, 0.f, text);

		ImVec2 textPos = ImVec2(
			position.x - textSize.x / 2,
			position.y - textSize.y / 2
		);

		std::string IconUrl = "Assets/image/arrow.png";
		if (GImGuiTextureMap[IconUrl].Width > 0) {
			ImVec2 IconPos = ImVec2(
				position.x,
				position.y
			);
			float IconSize = radius * 7.0f;
			RenderHelper::AddImageRotated(GImGuiTextureMap[IconUrl].Texture, IconPos, ImVec2(IconSize, IconSize), angle);
		}

		draw_list->AddCircleFilled(position, radius, circle_col, radius * 2);
		draw_list->AddText(ImGui::GetFont(), fontSize, ImVec2(textPos.x - 1, textPos.y + 1), ImColor(45, 45, 45, 220), text);
		draw_list->AddText(ImGui::GetFont(), fontSize, ImVec2(textPos.x - 1, textPos.y - 1), ImColor(45, 45, 45, 220), text);
		draw_list->AddText(ImGui::GetFont(), fontSize, ImVec2(textPos.x + 1, textPos.y + 1), ImColor(45, 45, 45, 220), text);
		draw_list->AddText(ImGui::GetFont(), fontSize, ImVec2(textPos.x + 1, textPos.y - 1), ImColor(45, 45, 45, 220), text);
		draw_list->AddText(ImGui::GetFont(), fontSize, textPos, IM_COL32_WHITE, text);
	}


    inline ImVec2 Text(const char* text, ImVec2 pos, ImU32 color = IM_COL32(255, 255, 255, 255), int size = 14, bool centered = true, bool adjustHeight = true, bool isWindowDrawList = true) noexcept
    {
        //const auto textSize = ImGui::CalcTextSize(text);
		const ImVec2 textSize = ImGui::GetFont()->CalcTextSizeA(size, FLT_MAX, 0.f, text);

        const auto horizontalOffset = centered ? textSize.x / 2 : 0.0f;
        const auto verticalOffset = adjustHeight ? textSize.y : 0.0f;

        unsigned int uintColor = color;
        unsigned int alphaOnlyColor = uintColor & IM_COL32_A_MASK;

		ImDrawList* DrawList;
		if (!isWindowDrawList)
		{
			DrawList = ImGui::GetBackgroundDrawList();
		}
		else {
			DrawList = ImGui::GetWindowDrawList();
			auto CursorScreenPos = ImGui::GetCursorScreenPos();
			//CursorScreenPos.x -= 8;
			//CursorScreenPos.y -= 8;

			pos = {
				CursorScreenPos.x + pos.x,
				CursorScreenPos.y + pos.y,
			};
		}

		DrawList->AddText(ImGui::GetFont(), size, { pos.x - horizontalOffset + 1.0f, pos.y - verticalOffset + 1.0f }, uintColor & IM_COL32_A_MASK, text);
		DrawList->AddText(ImGui::GetFont(), size, { pos.x - horizontalOffset, pos.y - verticalOffset }, color, text);

        return textSize;
    }


	inline void showInfo(std::vector<DrawItemListS>& ItemList, int size) {
		std::sort(ItemList.begin(), ItemList.end(), [](const DrawItemListS& a, const DrawItemListS& b) {
			return a.price > b.price;
			});
		size = 5;

		ImVec2 itemSize(220, 60);         // 每个条目大小
		ImVec2 imageSize(40, 40);         // 图标大小
		float textSpacing = 8.0f;         // 图标和文本的间距
		float itemSpacingY = 5.0f;        // 条目之间的垂直间距
		float marginRight = 10.0f;        // 距离屏幕右侧的边距

		ImVec2 screenSize = ImGui::GetIO().DisplaySize;

		// 起始位置：屏幕右侧 + 垂直1/3高度
		ImVec2 startPos;
		startPos.x = screenSize.x - itemSize.x - marginRight;
		startPos.y = screenSize.y * (1.0f / 3.0f);



		// 添加标题文本
		const char* titleText = U8("高价值物资列表");
		ImVec2 titleSize = ImGui::CalcTextSize(titleText);
		ImVec2 titlePos;
		titlePos.x = startPos.x + (itemSize.x - titleSize.x) * 0.5f; // 居中
		titlePos.y = startPos.y - titleSize.y - 10.0f;               // 位于第一个条目上方 10 像素



		// 计算标题框的位置和大小（与下面条目宽度一致）
		float padding = 10.0f; // 增加一些内边距
		ImVec2 titleBoxMin = ImVec2(startPos.x, startPos.y - titleSize.y - padding * 2 - itemSpacingY);
		ImVec2 titleBoxMax = ImVec2(startPos.x + itemSize.x, startPos.y - itemSpacingY);

		// 绘制标题背景框（与条目样式一致）
		ImGui::GetForegroundDrawList()->AddRect(
			titleBoxMin,
			titleBoxMax,
			IM_COL32(30, 30, 30, 200),
			6.0f
		);


		StrokeText(titleText, titlePos, IM_COL32(255, 255, 255, 255), 14, true, false);

		for (int i = 0; i < size && i < ItemList.size(); ++i)
		{
			auto& item = ItemList[i];

			// 当前条目左上角位置
			ImVec2 itemPos = ImVec2(startPos.x, startPos.y + i * (itemSize.y + itemSpacingY));

			// 背景绘制
			ImGui::GetForegroundDrawList()->AddRect(
				itemPos,
				ImVec2(itemPos.x + itemSize.x, itemPos.y + itemSize.y),
				IM_COL32(30, 30, 30, 200),
				6.0f
			);

			// 图标位置
			ImVec2 imagePos = ImVec2(itemPos.x + 5, itemPos.y + (itemSize.y - imageSize.y) * 0.5f);
			Image(item.OverlayTexture, imagePos, imageSize, true, IM_COL32(255, 255, 255, 255), false); // 图标绘制

			// 文字基准位置
			ImVec2 textBase = ImVec2(imagePos.x + imageSize.x + textSpacing, imagePos.y);

			// 名称文字
			ImGui::GetForegroundDrawList()->AddText(textBase, item.drawcol, Utils::StringToUTF8(item.DisPlayName).c_str());

			// 第二行：价格 和 数值
			std::string priceStr = std::to_string(item.price / 1000) + "K";
			std::string disStr = std::to_string((int)item.dis) + "M";

			ImVec2 pricePos = ImVec2(textBase.x, textBase.y + 18);
			ImVec2 disPos = ImVec2(textBase.x + 100, textBase.y + 18); // 可调整对齐
			
			ImGui::GetForegroundDrawList()->AddText(pricePos, IM_COL32(255, 215, 0, 255), Utils::StringToUTF8(priceStr).c_str());   // 金黄色
			ImGui::GetForegroundDrawList()->AddText(disPos, IM_COL32(50, 200, 255, 255), Utils::StringToUTF8(disStr).c_str());      // 蓝色
		}



	}

};

