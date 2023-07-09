#pragma once
#include "Entity.h" 
#include "Gameobject.h" 

namespace game
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer() override; // ��ƼƼ�� ����� �ް� ���� 

		void Initialize(); // �� �̴ϼȶ����� ���� �ѹ� ȣ�� 
		// �� ���� ���δ� ���� ���� x 

		void Update(); // �� ������Ʈ���� ��� ���̾ ���� ������Ʈ 
		void Render(HDC hdc); // �� �������� ��� ���̾ ���� ���� 

		void Addgameobject() // ���̾ "���� ������Ʈ"�� ����.
			// *�̴ϼȶ���� �ƴ� ���� - ������ ����ϴ� �Լ��̱� ���� 
		{
			// ���� ������Ʈ�� ��ü obj�� �����Ҵ�
			Gameobject* obj = new Gameobject(); 

			// ���ӿ�����Ʈ�� ���͹迭�� ������ ��
			// ������ ��ü�� ���ӿ�����Ʈ�� ���͹迭�� �־��ش�
			mGameobjects.push_back(obj); 
		}

	private: 
		// ���ӿ�����Ʈ�� ���͹迭
		std::vector<Gameobject*> mGameobjects; 

		// �ڷ���: Gameobject* == �������� 
		// for - each �� ���� Gameobject* �� ��ġ ����. 
	};
}


