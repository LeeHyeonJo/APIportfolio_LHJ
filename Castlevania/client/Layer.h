#pragma once
#include "Entity.h" 
#include "Gameobject.h" 

namespace game
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer() override; // 엔티티의 상속을 받고 있음 

		void Initialize(); // 씬 이니셜라이즈 돌때 한번 호출 
		// ㄴ 여기 내부는 아직 구현 x 

		void Update(); // 씬 업데이트에서 모든 레이어를 돌며 업데이트 
		void Render(HDC hdc); // 씬 렌더에서 모든 레이어를 돌며 렌더 

		void Addgameobject() // 레이어에 "게임 오브젝트"를 넣음.
			// *이니셜라이즈가 아닌 이유 - 여러번 사용하는 함수이기 때문 
		{
			// 게임 오브젝트를 객체 obj에 동적할당
			Gameobject* obj = new Gameobject(); 

			// 게임오브젝트는 벡터배열로 관리할 것
			// 생성한 객체를 게임오브젝트의 벡터배열에 넣어준다
			mGameobjects.push_back(obj); 
		}

	private: 
		// 게임오브젝트의 벡터배열
		std::vector<Gameobject*> mGameobjects; 

		// 자료형: Gameobject* == 포인터형 
		// for - each 문 사용시 Gameobject* 로 서치 가능. 
	};
}


