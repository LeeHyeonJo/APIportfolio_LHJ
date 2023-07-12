#pragma once
#include "Entity.h" // 여기에 commoninclude 들어있음 
#include "Layer.h" 

// 엔티티를 상속 받는다
// 씬 > 레이어(벡터배열) > 게임 오브젝트(벡터배열) > 게임 컴포넌트(트랜스/렌더)

// 목적: 레이어를 만들어 줄거임. ( = 생성자에서 진행) 
namespace game
{
	class Scene : public Entity 
	{
	public:
		Scene(); 
		~Scene() override; 
		// 엔티티 -> 씬 상속. 
		// 씬의 소멸자는 엔티티를 오버라이드 받고 있음 (명시적 표기) 

		void Initialize(); // 초기화 (장면 생성 - 레이어 크기 할당..) 
		void Update(); // 업데이트 (장면 업데이트 - 레이어 업뎃..)
		void Render(HDC hdc); // Update로 통해 바뀐 Pos를 참고, 그림을 띄움.  

	private:
		std::vector<Layer>mLayers;
		// 벡터 배열, 자료형은 Layer
		// ㄴ 나중에 질문하기. 이건 왜 Layer 형태 그대로? 

		// 자료형 Layer 
		// each for문을 사용할때 참조 (&)로 서치 
	};
}
