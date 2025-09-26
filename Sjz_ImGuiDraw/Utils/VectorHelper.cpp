
#include "VectorHelper.h"
#include"../Engine.h"
FVector VectorHelper::RotateVector(const FMatrix& RotationMatrix, const FVector& Vec) {
	FVector AxisX = RotationMatrix.GetScaledAxisX();
	FVector AxisY = RotationMatrix.GetScaledAxisY();
	FVector AxisZ = RotationMatrix.GetScaledAxisZ();

	return FVector{
		Vec.X * AxisX.X + Vec.Y * AxisY.X + Vec.Z * AxisZ.X,
		Vec.X * AxisX.Y + Vec.Y * AxisY.Y + Vec.Z * AxisZ.Y,
		Vec.X * AxisX.Z + Vec.Y * AxisY.Z + Vec.Z * AxisZ.Z
	};
}

FVector VectorHelper::GetBoneWithRotation(FTransform BoneArray, FTransform ComponentToWorld)
{
	FVector& Bone = BoneArray.Translation;

	
	if (MAX(MAX(abs(Bone.X), abs(Bone.Y)), abs(Bone.Z)) >= 500)
	{
		return FVector(INFINITY, INFINITY, INFINITY);
	}
	FMatrix Matrix = BoneArray.ToMatrixWithScale() * ComponentToWorld.ToMatrixWithScale();
	return FVector(Matrix._41, Matrix._42, Matrix._43);
}



FVector2D VectorHelper::WorldToScreen(const FVector& WorldLocation) {

	
	FVector2D ScreenLocation;

	FMatrix RotationMatrix = LocalData::LocalCameraData.Rotation.GetMatrix();
	

	FVector AxisX = RotationMatrix.GetScaledAxisX();
	FVector AxisY = RotationMatrix.GetScaledAxisY();
	FVector AxisZ = RotationMatrix.GetScaledAxisZ();

	FVector vDelta(WorldLocation - LocalData::LocalCameraData.Location);
	FVector vTransformed(vDelta | AxisY, vDelta | AxisZ, vDelta | AxisX);

	if (vTransformed.Z == 0.0f)
		vTransformed.Z = -0.001f;

	auto VieW = vTransformed.Z;

	if (vTransformed.Z < 0.0f)
		vTransformed.Z = -vTransformed.Z;

	float ScreenCenterX = Dx11Data::ScreenWidth / 2.0f;
	float ScreenCenterY = Dx11Data::ScreenHeight / 2.0f;


	float TangentFOV = tanf(ConvertToRadians(LocalData::LocalCameraData.FOV / 2.0f));

	ScreenLocation.X = (ScreenCenterX + vTransformed.X * (ScreenCenterX / TangentFOV) / vTransformed.Z);
	ScreenLocation.Y = (ScreenCenterY - vTransformed.Y * (ScreenCenterX / TangentFOV) / vTransformed.Z);

	if (VieW != INFINITY && VieW > 0.0f)
		return ScreenLocation;


	return FVector2D(INFINITY, INFINITY);
	
}


bool VectorHelper::IsInScreen(const FVector2D WorldToScreen) {
	const float ScreenMargin = 100.0f;

	
	const float MinX = -ScreenMargin;
	const float MinY = -ScreenMargin;
	const float MaxX = Dx11Data::ScreenWidth + ScreenMargin;
	const float MaxY = Dx11Data::ScreenHeight + ScreenMargin;

	
	return (WorldToScreen.X >= MinX) &&
		(WorldToScreen.X <= MaxX) &&
		(WorldToScreen.Y >= MinY) &&
		(WorldToScreen.Y <= MaxY);
}



