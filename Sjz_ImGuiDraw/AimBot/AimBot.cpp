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
//    // ��ʼ���������
//    static bool initialized = false;
//    if (!initialized) {
//        srand((unsigned int)time(NULL));
//        initialized = true;
//    }
//
//    // �������Ͳ�����ȫ��ʹ��float���㣩
//    float distance = sqrtf(dx * dx + dy * dy);
//    int steps = max(5, (int)(distance / (11.0f - speed)));
//    int delay = max(1, (int)(16.0f - speed));
//
//    // ��������
//    float stepX = dx / (float)steps;
//    float stepY = dy / (float)steps;
//
//    float currentX = 0.0f;
//    float currentY = 0.0f;
//
//    // �ֲ��ƶ�
//    for (int i = 0; i < steps; i++) {
//        // �������
//        float jitterX = randomFloat(-1.5f, 1.5f);
//        float jitterY = randomFloat(-1.5f, 1.5f);
//
//        // ����ȼ��ٶ���
//        float progress = (float)i / (float)steps;
//        jitterX *= (1.0f - progress) * 1.5f;
//        jitterY *= (1.0f - progress) * 1.5f;
//
//        // �ۻ�λ��
//        currentX += stepX + jitterX;
//        currentY += stepY + jitterY;
//
//        // ��̬�ٶ����ӣ�����-�������ߣ�
//        float dynamicFactor = 1.0f;
//        if (steps > 10) {
//            if (progress < 0.3f) {
//                dynamicFactor = progress / 0.3f;  // ���ٽ׶�
//            }
//            else if (progress > 0.7f) {
//                dynamicFactor = (1.0f - progress) / 0.3f;  // ���ٽ׶�
//            }
//        }
//
//        // ����ʵ���ƶ���
//        float moveX = currentX - (float)i * stepX;
//        float moveY = currentY - (float)i * stepY;
//
//        moveX *= dynamicFactor;
//        moveY *= dynamicFactor;
//        MoveMouse(moveX, moveY);
//    }
//
//    // ����λ������
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
//    if (length > 0.0001f) { // ���������
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

// Aimbot�ྲ̬��Ա������ʼ��������ԭʼ���壩
bool     Aimbot::Lock = false;
uint64_t Aimbot::Target = NULL;
float    Aimbot::ScreenDistance = 100000000.f;
float    Aimbot::recoilTime = 0.0f;
float    Aimbot::RemainMouseX = 0.f;
float    Aimbot::RemainMouseY = 0.f;
uint64_t Aimbot::TempObject = 0;


// ֹͣ��׼�߼�������ԭʼʵ�֣�
void Aimbot::StopAiming()
{
    Lock = false;
    RemainMouseX = 0.f;
    RemainMouseY = 0.f;
}


// ��ȡ��Ӧ�����İ���������ԭʼswitchʵ�֣�
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


// �ײ�����ƶ��������ã�����δ�����Drv_MoveTo��
void MoveMouse(float dx, float dy)
{
    Drv_MoveTo(static_cast<LONG>(dx), static_cast<LONG>(dy), 1);  // Drv_MoveToδ����
}


// ����[min, max]��Χ���������������ԭʼʵ�֣�
float randomFloat(float min, float max)
{
    return min + (float)rand() / (float)RAND_MAX * (max - min);
}


// ����1.0f~10.0f��Χ���������������ԭʼʵ�֣�
float randomFloat1To10()
{
    return randomFloat(1.0f, 10.0f);
}


// ģ����������ƶ��켣ģ�⣨����ԭʼ�߼���
void humanMouseMove(float dx, float dy, float speed = 5.0f)
{
    // ������ӳ�ʼ�������̰߳�ȫ���Ᵽ����
    static bool initialized = false;
    if (!initialized)
    {
        srand((unsigned int)time(NULL));  // ���̻߳����¿����ظ���ʼ��
        initialized = true;
    }

    // �����벽������
    float distance = sqrtf(dx * dx + dy * dy);
    int steps = max(5, (int)(distance / (11.0f - speed)));
    int delay = max(1, (int)(16.0f - speed));  // delayδʵ��ʹ��

    // ��������
    float stepX = dx / (float)steps;
    float stepY = dy / (float)steps;

    float currentX = 0.0f;
    float currentY = 0.0f;

    // �ֲ��ƶ�ģ��
    for (int i = 0; i < steps; i++)
    {
        // �������
        float jitterX = randomFloat(-1.5f, 1.5f);
        float jitterY = randomFloat(-1.5f, 1.5f);

        // �����˥������
        float progress = (float)i / (float)steps;
        jitterX *= (1.0f - progress) * 1.5f;
        jitterY *= (1.0f - progress) * 1.5f;

        // �ۻ�λ��
        currentX += stepX + jitterX;
        currentY += stepY + jitterY;

        // ��̬�ٶ����ӣ�����-�������ߣ�
        float dynamicFactor = 1.0f;
        if (steps > 10)
        {
            if (progress < 0.3f)
                dynamicFactor = progress / 0.3f;  // ���ٽ׶�
            else if (progress > 0.7f)
                dynamicFactor = (1.0f - progress) / 0.3f;  // ���ٽ׶�
        }

        // ����ʵ���ƶ���
        float moveX = currentX - (float)i * stepX;
        float moveY = currentY - (float)i * stepY;

        moveX *= dynamicFactor;
        moveY *= dynamicFactor;
        MoveMouse(moveX, moveY);
    }

    // ����λ������
    float remainingX = dx - currentX;
    float remainingY = dy - currentY;
    if (fabsf(remainingX) > 1.0f || fabsf(remainingY) > 1.0f)
    {
        MoveMouse(remainingX, remainingY);
    }
}


// ��׼Ƶ�ʿ���ʱ�������̬����δ��ʼ����
static DWORD aimbot_ms;  // δ��ʽ��ʼ��������Ĭ��ֵ0


// ���ÿ�����ת������δ����������������ռ䣩
void Aimbot::SetControlRotation(FVector2D ScreenPos)  // FVector2Dδ����
{
    FVector2D HitPosition = ScreenPos;

    // ������Ļ����ƫ�ƣ�Dx11Dataδ������
    float x = HitPosition.X - (Dx11Data::ScreenWidth / 2.f);  // Dx11Dataδ����
    float y = HitPosition.Y - (Dx11Data::ScreenHeight / 2.f);

    // Ӧ��ƽ��ϵ����Configsδ������
    x *= Configs::Aimbot::SmoothInt;  // Configs::Aimbotδ����
    y *= Configs::Aimbot::SmoothInt;

    float smooth_x = 0.00f;
    float smooth_y = 0.00f;
    DWORD ms = 0;

    if (Configs::Aimbot::Smooth >= 1.0f)  // ���ܷ���δ�����Ա
    {
        // X��ƽ������
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

        // Y��ƽ������
        if (abs(y) > 1.0f)
        {
            if (smooth_y < y)
                smooth_y = smooth_y + 1.0f + (y / Configs::Aimbot::SmoothY);  // SmoothY����δ����
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

    // ������׼Ƶ��
    DWORD current_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();

    if (current_ms - aimbot_ms >= ms)
    {
        aimbot_ms = current_ms;
        humanMouseMove(smooth_x, smooth_y, randomFloat1To10());
    }
}


// ������׼��ת�Ƕȣ�����δ��������ͣ�
FRotator Aimbot::GetAimRotation(FVector EnemyPos, FVector CameraPos)  // FRotator��FVectorδ����
{
    FVector diff{
        EnemyPos.X - CameraPos.X,
        EnemyPos.Y - CameraPos.Y,
        EnemyPos.Z - CameraPos.Z
    };

    FRotator AimRotation;
    // �Ƕȼ��㣨��ֵ���ƿ������뾫�����⣩
    AimRotation.Yaw = atan2f(diff.Y, diff.X) * 180 / (float)3.1415926;  // 3.1415926��������
    AimRotation.Pitch = atan2f(diff.Z, sqrt(diff.X * diff.X + diff.Y * diff.Y)) * 180 / (float)3.1415926;

    return AimRotation;
}


// �����ά�������ȣ�����ԭʼʵ�֣�
float Aimbot::VectorLength(const FVector2D& vec)  // FVector2Dδ����
{
    return sqrtf(vec.X * vec.X + vec.Y * vec.Y);
}


// ��һ����ά����������ԭʼʵ�֣�
FVector2D Aimbot::VectorNormalize(const FVector2D& vec)  // FVector2Dδ����
{
    float length = VectorLength(vec);
    if (length > 0.0001f)  // ��ֵ�̶���δ�ó���
    {
        return { vec.X / length, vec.Y / length };
    }
    return { 0.0f, 0.0f };
}


// ��ȡָ�������任������δ��������ͣ�
FTransform Aimbot::GetAimBoneTransForm(int index, Player player)  // FTransform��Playerδ����
{
    FTransform checkTransform{};

    // ��������ӳ�䣨BoneIndexδ������
    switch (index)
    {
    case 0:  checkTransform = player.Skeleton.Bones[BoneIndex::Head_Joint]; break;  // BoneIndexδ����
    case 1:  checkTransform = player.Skeleton.Bones[BoneIndex::Head];        break;
    case 2:  checkTransform = player.Skeleton.Bones[BoneIndex::Spine];       break;
    case 3:  checkTransform = player.Skeleton.Bones[BoneIndex::LeftFoot];    break;
    default: break;
    }

    return checkTransform;
}
