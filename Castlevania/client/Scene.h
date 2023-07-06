#pragma once
#include "Entity.h"

// ** 화면을 띄울 것 ** // 
// 화면 > 리소스 수 만큼의 레이어 벡터 배열 > 그 안에 게임 오브젝트 배열 > 게임 오브젝트는 컴포넌트를 들고 있음 

namespace game
{
	class Scene : public Entity // 씬은 엔티티의 상속을 받는다~
	{
	public:
		Scene(); // 씬의 생성자 (여기서 레이어 벡터 배열을 만듦)
		virtual ~Scene(); // 씬의 소멸자 호출

		virtual void Initialize(); // 초기화 함수
		// ㄴ 컴포넌트가 상속받게 되므로, 붙여준것. 
		virtual void Update(); // 업데이트 
		virtual void Render(HDC hdc); // 렌더
		// (그려주니 인자로 핸들을 받음)

	private: 
		// 씬은 화면에 뜨는 객체(이미지 전반)들을 들고 있어야 함. (게임 오브젝트라고 부를 것) 
		// *주소값으로 받지 않으면 객체의 원본이 아니라, 복사된 객체가 넘어가게 됨*
		// ㄴ <>는 자료형인데, <int*> 이렇게 되면 자료형. 자료형이 너무 길면 int라고 생각하기 

		// 게임 오브젝트들은 레이어 배열에 정리되어서 차례대로 뜰 수 있게 구현한다. 
		// 자료형:Layer인 벡터 배열. 이름은 mLayers 정도로. 
		std::vector<Layer> mLayers; 
	};

}

