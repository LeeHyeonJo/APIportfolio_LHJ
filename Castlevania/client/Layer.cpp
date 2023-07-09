#include "Layer.h"

namespace game
{
	Layer::Layer()
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		// 아직 구현 x
	}

	void Layer::Update()
	{
		// 씬 업뎃에서 호출됨. 
		// 모든 게임 오브젝트를 돌면서 "게임 오브젝트"의 상태를 업데이트. 

		for (Gameobject* obj : mGameobjects)
		{
			obj->Update();
			// 객체 오브젝트의 자료형이 Gameobject형이므로 
			// 그쪽으로 이동 
		}
	}

	void Layer::Render(HDC hdc) 
	{
		// 씬 렌더에서 호출됨
		// 모든 게임 오브젝트를 돌면서 "게임 오브젝트"의 상태를 랜더

		for (Gameobject* obj : mGameobjects) 
		{
			obj->Render(hdc); 
			// 객체 오브젝트의 자료형이 Gameobject형이므로 
			// 그쪽으로 이동 
		}
	}
}

