#include"base.h"
#include"Engine.h"



void SetThreadHighPriority(std::thread& t);


namespace MainThread
{
	//获取主要数据线程
	void UpdataGlobalData();

	//刷新相机
	void UpdataLocalCameraData();

	//分类线程
	void UpdataActorsData();

	//刷新玩家数据
	void UpdataPlayersData();

	//处理物资数据
	void UpdataItemsData();
	
	//刷新大地图雷达
	void UpdataMapRadar();

	//刷新本人数据
	void UpdateLocalPlayer();

	//更新按键状态
	void UpdateKeyState();

	//自瞄线程
	void RunAimBot();

	//清理缓存
	void ReflashData();
	
}

