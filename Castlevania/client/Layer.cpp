#include "Layer.h"

namespace game
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		// ���� ���� x
	}

	void Layer::Update()
	{
		// �� �������� ȣ���. 
		// ��� ���� ������Ʈ�� ���鼭 "���� ������Ʈ"�� ���¸� ������Ʈ. 

		for (Gameobject* obj : mGameobjects)
		{
			obj->Update();
			// ��ü ������Ʈ�� �ڷ����� Gameobject���̹Ƿ� 
			// �������� �̵� 
		}
	}

	void Layer::Render(HDC hdc) 
	{
		// �� �������� ȣ���
		// ��� ���� ������Ʈ�� ���鼭 "���� ������Ʈ"�� ���¸� ����

		for (Gameobject* obj : mGameobjects) 
		{
			obj->Render(hdc); 
			// ��ü ������Ʈ�� �ڷ����� Gameobject���̹Ƿ� 
			// �������� �̵� 
		}
	}
}

