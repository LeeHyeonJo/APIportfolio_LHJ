#pragma once
#include "Entity.h"

// 엔티티를 상속 받는다
// 씬 > 레이어(벡터배열) > 게임 오브젝트(벡터배열) > 게임 컴포넌트(트랜스/렌더)

namespace game
{
	class Scene : public Entity 
	{
	public:
		Scene(); // 생성자 
		virtual ~Scene(); // 소멸자 

		void Initialize(); // 초기화 (1번) 
		void Update(); // 업데이트 
		void Render(HDC hdc); // 렌더 

	private:

	};
}
