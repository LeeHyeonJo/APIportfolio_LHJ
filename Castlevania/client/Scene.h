#pragma once
#include "Commoninclude.h"
// 레이어 헤더 

namespace game
{
	class Scene : public Entity // 이거 상속이었나? 
	{
	public:
		// 씬의 생성자
		// 씬의소멸자 호출 (버추얼 붙여줌)


		// 가상함수로 virtual void Initialize();  - 초기화 함수
		// 가상함수로 virtual void Initialize();  - 업데이트 함수
		// 가상함수로 virtual void Initialize();  - 렌더 함수 (인자  hdc 받겠죠) 

	private: 
		// 씬이 들고 있을 것
		// 타이틀 화면에 뜨는 객체들을 들고 있어야 함. (게임 오브젝트라고 부를 것) 
		// 주소값으로 받지 않으면 객체의 원본이 아니라, 복사된 객체가 넘어가게 됨. 
		// ㄴ <>는 자료형인데, 주소로 받아주는거임. 잊지마셈. 
		std::vector<GameObject*> mGameObjects;
		// ㄴ 게임오브젝트레어 레이어로 바뀜. (게임오브젝트가 레이어 안으로 들어각ㅁ) 

		// 오브젝트가 "레이어" 에 따라서 층층히 나올 수 있도록 해야 함
		// >> 레이어를 구현할 것. 
	};

}

