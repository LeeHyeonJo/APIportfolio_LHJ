#include "Scene.h"
#include "Layers.h" 

namespace game
{
	Scene::Scene() // 레이어 백터 배열을 생성(크기만 할당) 
	{ 
		mLayers.resize((int)enums::eLayerType::End);  
		// enum class eLayerType는 Commoninclude.h에 구현. 
		// ㄴ 네임스페이스를 제대로 표기하지 않은것에 주의! 

		// 총 5개의 레이어 생성. 
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		mLayers[(int)enums::eLayerType::Player].AddGameObject(); 
		// 첫번째 레이어에 게임 오브젝트를 생성하는 함수를 호출. 
	}

	void Scene::Update()
	{
		// 모든 레이어가 한번에 업데이트 되어야 하므로 
		// 반복문을 돌면서 업데이트 한다 (for - each 문 참고) 

		for (Layer& layer : mLayers) // mLayers 배열을 객체 layer에 처음부터 끝까지 넣어주면서 비교. 
		{
			layer.Update(); // 들어오는 객체마다 업데이트 
		}

	}

	void Scene::Render(HDC hdc) // 업데이트와 동일한 원리
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(HDC hdc); 
		}
	}

}