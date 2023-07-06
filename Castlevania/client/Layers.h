#pragma once
#include "Entity.h" 
#include "Gameobject.h"

// 레이어들 (이넘 클래스만큼 생성) 
// 엔티티를 상속받아야 이름이 만들어진다 

// 레이어들 안에 "게임 오브젝트"를 채워줄것이다. 
// ㄴ 생성자 호출시 게임 오브젝트가 생성 

namespace game
{
	class Layers : public Entity
	{
	public:
		Layers(); // 생성자 
		virtual ~Layers();
		// 소멸자는 버추얼 반드시
		// 부모가 삭제되는 불상사 방지 

		virtual void Initialize(); 
		virtual void Update();
		virtual void Render(HDC hdc); 

		// 레이어 상속하게 되는 클래스를 위해
		// 미리 버추얼을 써뒀을 뿐. 

		// 레이어를 상속받는 클래스가 생기게 되면
		// 그 자식 클래스의 함수에 버추얼과 오버라이드를 붙여주면 된다~ 

		void AddGameObject()
			// 만들어진 레이어 안에 게임 오브젝트 넣어주는 함수 
		{
			Gameobject* obj = new Gameobject(); 
			// 객체 obj를 동적할당 (1개)
			mGameobjects.push_back(obj); 
			// 벡터배열 mGameobjects에 obj를 넣기 

		}

	private: // 벡터 배열 게임옵젝이 있어야겠지
		std::vector<Gameobject*> mGameobjects;  
	};
}

