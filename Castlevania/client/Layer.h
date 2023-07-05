#pragma once
// 엔티티 헤더 
// 게임 오브젝트 헤더 

namespace game
{
	class Layer
	{


	private:
		std::vector<Gameobject*> mGameObjects; 
	};
}


// 씬 >> 레이어 (배열) >> 각 배열 안에 게임 오브젝트가 들어감. 

