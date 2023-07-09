#pragma once
#include "Entity.h" // ���⿡ commoninclude ������� 

// ��ƼƼ�� ��� �޴´�
// �� > ���̾�(���͹迭) > ���� ������Ʈ(���͹迭) > ���� ������Ʈ(Ʈ����/����)

// ����: ���̾ ����� �ٰ���. ( = �����ڿ��� ����) 
namespace game
{
	class Scene : public Entity 
	{
	public:
		Scene(); 
		~Scene() override; 
		// ��ƼƼ -> �� ���. 
		// ���� �Ҹ��ڴ� ��ƼƼ�� �������̵� �ް� ���� (����� ǥ��) 

		void Initialize(); // �ʱ�ȭ (��� ���� - ���̾� ũ�� �Ҵ�..) 
		void Update(); // ������Ʈ (��� ������Ʈ - ���̾� ����..)
		void Render(HDC hdc); // Update�� ���� �ٲ� Pos�� ����, �׸��� ���.  

	private:
		std::vector<Layer>mLayers;
		// ������ �迭
	};
}
