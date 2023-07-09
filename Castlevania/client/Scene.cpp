#include "Scene.h"

// 목적: 씬 헤더에서 구현한 함수가 돌아가야 함
// Layer에 관련된 처리를 함. 

namespace game
{
	Scene::Scene()
	{
		// Scene의 생성자가 먼저 호출
		// resize(); = 배열의 크기를 할당하는 함수 
		mLayers.resize((int)enums::eLayerType::End);    
		// 특: 여기는 레이어 배열의 크기만 할당됨. (0~5번까지) 
	}

	Scene::~Scene()
	{
	}

	// 게임오브젝트는 *씬이 초기화될때* 추가되기 시작한다. 
	// 할당된 레이어 배열(0~5)에 "게임 오브젝트"를 넣어준다.  
	void Scene::Initialize() 
	{
		mLayers[(int)enums::eLayerType::Player].Addgameobject; 
	}

	// 씬 업데이트: 모든 레이어 배열을 돌면서, 레이어를 "업데이트" 한다. 
	// 업데이트 한다는 기능만 구현하는 것 
	void Scene::Update()
	{
		// for - each 문 
		// (자료형& 객체 : 배열이름) == 배열이 0~끝까지 돌면서 객체에 들어가며 비교됨
		for (Layer& layer : mLayers) // == 모든 레이어를 돈다는 뜻 
		{
			layer.Update(); // 레이어의 업데이트로 이동 
		}
	}

	void Scene::Render(HDC hdc)
	{
		// 모든 레이어를 돌면서 그린다. 딱 그 기능까지. 
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc); // 레이어의 렌더로 이동 
		}
	}
}