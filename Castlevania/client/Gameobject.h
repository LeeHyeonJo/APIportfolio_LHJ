#pragma 
#include "Entity.h"
// ������Ʈ�� ������ �� ����� ���;� ��

namespace game
{
	class Gameobject : public Entity // ��ƼƼ�� ��� 
	{
	public:
		Gameobject(); // ������ (Layer�� AddGameobject���� ����� �Ѿ��)
					// �����Ҵ� �����Ƿ�!! �����ڰ� ȣ��ȴ�. 
		virtual ~Gameobject(); // �Ҹ��� 
 
		void Initialize() override; // �ʱ�ȭ (����x) 
		void Update() override; // �� ���� �迭�� ���鼭, ���θ� ����. 
		void Render(HDC hdc) override; // �� ���� �迭�� ���鼭, ���θ� ����.

	private:
		// ���� ������Ʈ�� �ȿ� ������Ʈ�� ���͹迭�� �������
		// ��Ȯ���� ������Ʈ�� �ּҸ� �޾��ٰ���. 
		// �� �ּҸ� �����ؼ� �ö󰥰Ŵϱ�. 
		std::vector<Component*> mComponents; 
	};
}
