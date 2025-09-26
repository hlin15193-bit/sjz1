#include"base.h"
#include"Engine.h"



void SetThreadHighPriority(std::thread& t);


namespace MainThread
{
	//��ȡ��Ҫ�����߳�
	void UpdataGlobalData();

	//ˢ�����
	void UpdataLocalCameraData();

	//�����߳�
	void UpdataActorsData();

	//ˢ���������
	void UpdataPlayersData();

	//������������
	void UpdataItemsData();
	
	//ˢ�´��ͼ�״�
	void UpdataMapRadar();

	//ˢ�±�������
	void UpdateLocalPlayer();

	//���°���״̬
	void UpdateKeyState();

	//�����߳�
	void RunAimBot();

	//������
	void ReflashData();
	
}

