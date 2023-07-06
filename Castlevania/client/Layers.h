#pragma once
#include "Entity.h" 
#include "Gameobject.h"

// ���̾�� (�̳� Ŭ������ŭ ����) 
// ��ƼƼ�� ��ӹ޾ƾ� �̸��� ��������� 

// ���̾�� �ȿ� "���� ������Ʈ"�� ä���ٰ��̴�. 
// �� ������ ȣ��� ���� ������Ʈ�� ���� 

namespace game
{
	class Layers : public Entity
	{
	public:
		Layers(); // ������ 
		virtual ~Layers();
		// �Ҹ��ڴ� ���߾� �ݵ��
		// �θ� �����Ǵ� �һ�� ���� 

		virtual void Initialize(); 
		virtual void Update();
		virtual void Render(HDC hdc); 

		// ���̾� ����ϰ� �Ǵ� Ŭ������ ����
		// �̸� ���߾��� ����� ��. 

		// ���̾ ��ӹ޴� Ŭ������ ����� �Ǹ�
		// �� �ڽ� Ŭ������ �Լ��� ���߾�� �������̵带 �ٿ��ָ� �ȴ�~ 

		void AddGameObject()
			// ������� ���̾� �ȿ� ���� ������Ʈ �־��ִ� �Լ� 
		{
			Gameobject* obj = new Gameobject(); 
			// ��ü obj�� �����Ҵ� (1��)
			mGameobjects.push_back(obj); 
			// ���͹迭 mGameobjects�� obj�� �ֱ� 

		}

	private: // ���� �迭 ���ӿ����� �־�߰���
		std::vector<Gameobject*> mGameobjects;  
	};
}

