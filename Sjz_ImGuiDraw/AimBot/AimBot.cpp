//#include"AimBot.h"
//#include"MenuConfigs.hpp"
//bool     Aimbot::Lock = false;
//uint64_t Aimbot::Target = NULL;
//float    Aimbot::ScreenDistance = 100000000.f;
//float    Aimbot::recoilTime = 0.0f;
//float    Aimbot::RemainMouseX = 0.f;
//float    Aimbot::RemainMouseY = 0.f;
//uint64_t Aimbot::TempObject = 0;
//void Aimbot::StopAiming()
//{
//    Lock = false;
//
//    RemainMouseX = 0.f;
//    RemainMouseY = 0.f;
//
//
//}
//int Aimbot::GetAsyncKey(int index)
//{
//    int key = 0;
//    switch (index)
//    {
//    case 0:
//        key = VK_RBUTTON;
//        break;
//    case 1:
//        key = VK_LBUTTON;
//        break;
//    case 2:
//        key = VK_SHIFT;
//        break;
//    case 3:
//        key = VK_CONTROL;
//        break;
//    default:
//        break;
//    }
//
//    return key;
//
//}
//void MoveMouse(float dx, float dy)
//{
//    Drv_MoveTo(static_cast<LONG>(dx), static_cast<LONG>(dy), 1);
//}
//float randomFloat(float min, float max) {
//    return min + (float)rand() / (float)RAND_MAX * (max - min);
//}
//float randomFloat1To10() {
//    return randomFloat(1.0f, 10.0f);
//}
//void humanMouseMove(float dx, float dy, float speed = 5.0f) {
//    // 初始化随机种子
//    static bool initialized = false;
//    if (!initialized) {
//        srand((unsigned int)time(NULL));
//        initialized = true;
//    }
//
//    // 计算距离和步数（全部使用float计算）
//    float distance = sqrtf(dx * dx + dy * dy);
//    int steps = max(5, (int)(distance / (11.0f - speed)));
//    int delay = max(1, (int)(16.0f - speed));
//
//    // 步长计算
//    float stepX = dx / (float)steps;
//    float stepY = dy / (float)steps;
//
//    float currentX = 0.0f;
//    float currentY = 0.0f;
//
//    // 分步移动
//    for (int i = 0; i < steps; i++) {
//        // 随机抖动
//        float jitterX = randomFloat(-1.5f, 1.5f);
//        float jitterY = randomFloat(-1.5f, 1.5f);
//
//        // 随进度减少抖动
//        float progress = (float)i / (float)steps;
//        jitterX *= (1.0f - progress) * 1.5f;
//        jitterY *= (1.0f - progress) * 1.5f;
//
//        // 累积位置
//        currentX += stepX + jitterX;
//        currentY += stepY + jitterY;
//
//        // 动态速度因子（加速-减速曲线）
//        float dynamicFactor = 1.0f;
//        if (steps > 10) {
//            if (progress < 0.3f) {
//                dynamicFactor = progress / 0.3f;  // 加速阶段
//            }
//            else if (progress > 0.7f) {
//                dynamicFactor = (1.0f - progress) / 0.3f;  // 减速阶段
//            }
//        }
//
//        // 计算实际移动量
//        float moveX = currentX - (float)i * stepX;
//        float moveY = currentY - (float)i * stepY;
//
//        moveX *= dynamicFactor;
//        moveY *= dynamicFactor;
//        MoveMouse(moveX, moveY);
//    }
//
//    // 最终位置修正
//    float remainingX = dx - currentX;
//    float remainingY = dy - currentY;
//    if (fabsf(remainingX) > 1.0f || fabsf(remainingY) > 1.0f) {
//        MoveMouse(remainingX, remainingY);
//    }
//}
//
//static DWORD aimbot_ms;
//void Aimbot::SetControlRotation(FVector2D ScreenPos)
//{
//    FVector2D HitPosition;
//    HitPosition = ScreenPos;
//    float x = HitPosition.X - (Dx11Data::ScreenWidth / 2.f);
//    float y = HitPosition.Y - (Dx11Data::ScreenHeight / 2.f);
//    x *= Configs::Aimbot::SmoothInt;
//    y *= Configs::Aimbot::SmoothInt;
//    float smooth_x = 0.00f;
//    float smooth_y = 0.00f;
//
//    DWORD ms = 0;
//    if (Configs::Aimbot::Smooth >= 1.0f)
//    {
//        if (abs(x) > 1.0f)
//        {
//            if (smooth_x < x)
//                smooth_x = smooth_x + 1.0f + (x / Configs::Aimbot::Smooth);
//            else if (smooth_x > x)
//                smooth_x = smooth_x - 1.0f + (x / Configs::Aimbot::Smooth);
//            else
//                smooth_x = x;
//        }
//        else
//        {
//            smooth_x = x;
//        }
//
//        if (abs(y) > 1.0f)
//        {
//            if (smooth_y < y)
//                smooth_y = smooth_y + 1.0f + (y / Configs::Aimbot::SmoothY);
//            else if (smooth_y > y)
//                smooth_y = smooth_y - 1.0f + (y / Configs::Aimbot::SmoothY);
//            else
//                smooth_y = y;
//        }
//        else
//        {
//            smooth_y = y;
//        }
//        ms = (DWORD)(Configs::Aimbot::Smooth / 100.0f) + 1;
//        ms = ms * 8;
//    }
//    else
//    {
//        smooth_x = x;
//        smooth_y = y;
//        ms = 8;
//    }
//    DWORD current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//    if (current_ms - aimbot_ms >= ms)
//    {
//        aimbot_ms = current_ms;
//        humanMouseMove(smooth_x, smooth_y, randomFloat1To10());
//
//    }
//}
//FRotator Aimbot::GetAimRotation(FVector EnemyPos, FVector CameraPos)
//{
//    FVector diff{ EnemyPos.X - CameraPos.X, EnemyPos.Y - CameraPos.Y,EnemyPos.Z - CameraPos.Z, };
//
//    FRotator AimRotation;
//    AimRotation.Yaw = atan2f(diff.Y, diff.X) * 180 / (float)3.1415926;
//    AimRotation.Pitch = atan2f(diff.Z, sqrt(diff.X * diff.X + diff.Y * diff.Y)) * 180 / (float)3.1415926;
//
//    return AimRotation;
//}
//float Aimbot::VectorLength(const FVector2D& vec)
//{
//
//    return sqrtf(vec.X * vec.X + vec.Y * vec.Y);
//
//}
//FVector2D Aimbot::VectorNormalize(const FVector2D& vec)
//{
//    float length = VectorLength(vec);
//    if (length > 0.0001f) { // 避免除以零
//        return { vec.X / length, vec.Y / length };
//    }
//    return { 0.0f, 0.0f };
//}
//
//FTransform Aimbot::GetAimBoneTransForm(int index, Player player)
//{
//    FTransform checkTransform{};
//
//    switch (index)
//    {
//    case 0:
//        checkTransform = player.Skeleton.Bones[BoneIndex::Head_Joint];
//        break;
//    case 1:
//        checkTransform = player.Skeleton.Bones[BoneIndex::Head];
//        break;
//    case 2:
//        checkTransform = player.Skeleton.Bones[BoneIndex::Spine];
//        break;
//    case 3:
//        checkTransform = player.Skeleton.Bones[BoneIndex::LeftFoot];
//        break;
//    default:
//        break;
//    }
//
//    return checkTransform;
//
//}


#include "AimBot.h"
#include "MenuConfigs.hpp"

// Aimbot类静态成员变量初始化（保留原始定义）
bool     Aimbot::Lock = false;
uint64_t Aimbot::Target = NULL;
float    Aimbot::ScreenDistance = 100000000.f;
float    Aimbot::recoilTime = 0.0f;
float    Aimbot::RemainMouseX = 0.f;
float    Aimbot::RemainMouseY = 0.f;
uint64_t Aimbot::TempObject = 0;


// 停止瞄准逻辑（保留原始实现）
void Aimbot::StopAiming()
{
    Lock = false;
    RemainMouseX = 0.f;
    RemainMouseY = 0.f;
}


// 获取对应索引的按键（保留原始switch实现）
int Aimbot::GetAsyncKey(int index)
{
    int key = 0;
    switch (index)
    {
    case 0:  key = VK_RBUTTON; break;
    case 1:  key = VK_LBUTTON; break;
    case 2:  key = VK_SHIFT;   break;
    case 3:  key = VK_CONTROL; break;
    default: break;
    }
    return key;
}


// 底层鼠标移动驱动调用（保留未定义的Drv_MoveTo）
void MoveMouse(float dx, float dy)
{
    Drv_MoveTo(static_cast<LONG>(dx), static_cast<LONG>(dy), 1);  // Drv_MoveTo未声明
}


// 生成[min, max]范围随机浮点数（保留原始实现）
float randomFloat(float min, float max)
{
    return min + (float)rand() / (float)RAND_MAX * (max - min);
}


// 生成1.0f~10.0f范围随机浮点数（保留原始实现）
float randomFloat1To10()
{
    return randomFloat(1.0f, 10.0f);
}


// 模拟人类鼠标移动轨迹模拟（保留原始逻辑）
void humanMouseMove(float dx, float dy, float speed = 5.0f)
{
    // 随机种子初始化（单线程安全问题保留）
    static bool initialized = false;
    if (!initialized)
    {
        srand((unsigned int)time(NULL));  // 多线程环境下可能重复初始化
        initialized = true;
    }

    // 距离与步数计算
    float distance = sqrtf(dx * dx + dy * dy);
    int steps = max(5, (int)(distance / (11.0f - speed)));
    int delay = max(1, (int)(16.0f - speed));  // delay未实际使用

    // 步长计算
    float stepX = dx / (float)steps;
    float stepY = dy / (float)steps;

    float currentX = 0.0f;
    float currentY = 0.0f;

    // 分步移动模拟
    for (int i = 0; i < steps; i++)
    {
        // 随机抖动
        float jitterX = randomFloat(-1.5f, 1.5f);
        float jitterY = randomFloat(-1.5f, 1.5f);

        // 随进度衰减抖动
        float progress = (float)i / (float)steps;
        jitterX *= (1.0f - progress) * 1.5f;
        jitterY *= (1.0f - progress) * 1.5f;

        // 累积位置
        currentX += stepX + jitterX;
        currentY += stepY + jitterY;

        // 动态速度因子（加速-减速曲线）
        float dynamicFactor = 1.0f;
        if (steps > 10)
        {
            if (progress < 0.3f)
                dynamicFactor = progress / 0.3f;  // 加速阶段
            else if (progress > 0.7f)
                dynamicFactor = (1.0f - progress) / 0.3f;  // 减速阶段
        }

        // 计算实际移动量
        float moveX = currentX - (float)i * stepX;
        float moveY = currentY - (float)i * stepY;

        moveX *= dynamicFactor;
        moveY *= dynamicFactor;
        MoveMouse(moveX, moveY);
    }

    // 最终位置修正
    float remainingX = dx - currentX;
    float remainingY = dy - currentY;
    if (fabsf(remainingX) > 1.0f || fabsf(remainingY) > 1.0f)
    {
        MoveMouse(remainingX, remainingY);
    }
}


// 瞄准频率控制时间戳（静态变量未初始化）
static DWORD aimbot_ms;  // 未显式初始化，依赖默认值0


// 设置控制旋转（保留未定义的类型与命名空间）
void Aimbot::SetControlRotation(FVector2D ScreenPos)  // FVector2D未声明
{
    FVector2D HitPosition = ScreenPos;

    // 计算屏幕中心偏移（Dx11Data未声明）
    float x = HitPosition.X - (Dx11Data::ScreenWidth / 2.f);  // Dx11Data未定义
    float y = HitPosition.Y - (Dx11Data::ScreenHeight / 2.f);

    // 应用平滑系数（Configs未声明）
    x *= Configs::Aimbot::SmoothInt;  // Configs::Aimbot未定义
    y *= Configs::Aimbot::SmoothInt;

    float smooth_x = 0.00f;
    float smooth_y = 0.00f;
    DWORD ms = 0;

    if (Configs::Aimbot::Smooth >= 1.0f)  // 可能访问未定义成员
    {
        // X轴平滑计算
        if (abs(x) > 1.0f)
        {
            if (smooth_x < x)
                smooth_x = smooth_x + 1.0f + (x / Configs::Aimbot::Smooth);
            else if (smooth_x > x)
                smooth_x = smooth_x - 1.0f + (x / Configs::Aimbot::Smooth);
            else
                smooth_x = x;
        }
        else
        {
            smooth_x = x;
        }

        // Y轴平滑计算
        if (abs(y) > 1.0f)
        {
            if (smooth_y < y)
                smooth_y = smooth_y + 1.0f + (y / Configs::Aimbot::SmoothY);  // SmoothY可能未定义
            else if (smooth_y > y)
                smooth_y = smooth_y - 1.0f + (y / Configs::Aimbot::SmoothY);
            else
                smooth_y = y;
        }
        else
        {
            smooth_y = y;
        }

        ms = (DWORD)(Configs::Aimbot::Smooth / 100.0f) + 1;
        ms = ms * 8;
    }
    else
    {
        smooth_x = x;
        smooth_y = y;
        ms = 8;
    }

    // 控制瞄准频率
    DWORD current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();

    if (current_ms - aimbot_ms >= ms)
    {
        aimbot_ms = current_ms;
        humanMouseMove(smooth_x, smooth_y, randomFloat1To10());
    }
}


// 计算瞄准旋转角度（保留未定义的类型）
FRotator Aimbot::GetAimRotation(FVector EnemyPos, FVector CameraPos)  // FRotator、FVector未声明
{
    FVector diff{
        EnemyPos.X - CameraPos.X,
        EnemyPos.Y - CameraPos.Y,
        EnemyPos.Z - CameraPos.Z
    };

    FRotator AimRotation;
    // 角度计算（π值近似可能引入精度问题）
    AimRotation.Yaw = atan2f(diff.Y, diff.X) * 180 / (float)3.1415926;  // 3.1415926精度有限
    AimRotation.Pitch = atan2f(diff.Z, sqrt(diff.X * diff.X + diff.Y * diff.Y)) * 180 / (float)3.1415926;

    return AimRotation;
}


// 计算二维向量长度（保留原始实现）
float Aimbot::VectorLength(const FVector2D& vec)  // FVector2D未声明
{
    return sqrtf(vec.X * vec.X + vec.Y * vec.Y);
}


// 归一化二维向量（保留原始实现）
FVector2D Aimbot::VectorNormalize(const FVector2D& vec)  // FVector2D未声明
{
    float length = VectorLength(vec);
    if (length > 0.0001f)  // 阈值固定，未用常量
    {
        return { vec.X / length, vec.Y / length };
    }
    return { 0.0f, 0.0f };
}


// 获取指定骨骼变换（保留未定义的类型）
FTransform Aimbot::GetAimBoneTransForm(int index, Player player)  // FTransform、Player未声明
{
    FTransform checkTransform{};

    // 骨骼索引映射（BoneIndex未声明）
    switch (index)
    {
    case 0:  checkTransform = player.Skeleton.Bones[BoneIndex::Head_Joint]; break;  // BoneIndex未定义
    case 1:  checkTransform = player.Skeleton.Bones[BoneIndex::Head];        break;
    case 2:  checkTransform = player.Skeleton.Bones[BoneIndex::Spine];       break;
    case 3:  checkTransform = player.Skeleton.Bones[BoneIndex::LeftFoot];    break;
    default: break;
    }

    return checkTransform;
}
