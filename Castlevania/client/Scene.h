#pragma once
#include "Entity.h"

// ��ƼƼ�� ��� �޴´�
// �� > ���̾�(���͹迭) > ���� ������Ʈ(���͹迭) > ���� ������Ʈ(Ʈ����/����)

namespace game
{
	class Scene : public Entity 
	{
	public:
		Scene(); // ������ 
		virtual ~Scene(); // �Ҹ��� 

		void Initialize(); // �ʱ�ȭ (1��) 
		void Update(); // ������Ʈ 
		void Render(HDC hdc); // ���� 

	private:

	};
}
