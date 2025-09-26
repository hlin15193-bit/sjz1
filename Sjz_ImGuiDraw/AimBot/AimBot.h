#pragma once
#include"../base.h"
#include"../Engine.h"
#include"../Class.h"

class Aimbot
{
public:
	static Aimbot& GetInstance()
	{
		static Aimbot Instance;
		return Instance;
	}

	static bool Lock;
	static uint64_t Target;
	static float ScreenDistance;
	static float recoilTime;
	static float RemainMouseX;
	static float RemainMouseY;
	static  uint64_t TempObject;

public:

	static void StopAiming();

	//static void MoveMouse(float dx, float dy);

	static FTransform GetAimBoneTransForm(int index, Player player);

	static int GetAsyncKey(int index);

	static void SetControlRotation(FVector2D ScreenPos);

	static FRotator GetAimRotation(FVector EnemyPos, FVector CameraPos);

   static float VectorLength(const FVector2D& vec);

    // 将向量归一化（单位化）
   static FVector2D VectorNormalize(const FVector2D& vec);
 
	FVector2D screenLocation{};

	float Distance = 0.0f;

private:

	Aimbot() {};
	Aimbot(Aimbot&) {};


};
