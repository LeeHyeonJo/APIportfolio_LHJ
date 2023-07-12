#pragma 
#include "Entity.h"
// 컴포넌트를 구현한 후 헤더가 들어와야 함

namespace game
{
	class Gameobject : public Entity // 엔티티의 상속 
	{
	public:
		Gameobject(); // 생성자 (Layer의 AddGameobject에서 여기로 넘어옴)
					// 동적할당 했으므로!! 생성자가 호출된다. 
		virtual ~Gameobject(); // 소멸자 
 
		void Initialize() override; // 초기화 (구현x) 
		void Update() override; // 겜 옵젝 배열을 돌면서, 내부를 업뎃. 
		void Render(HDC hdc) override; // 겜 옵젝 배열을 돌면서, 내부를 렌더.

	private:
		// 게임 오브젝트는 안에 컴포넌트를 벡터배열로 들고있음
		// 정확히는 컴포넌트의 주소를 받아줄것임. 
		// ㄴ 주소를 참고해서 올라갈거니까. 
		std::vector<Component*> mComponents; 
	};
}
