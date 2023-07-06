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

		for (Layers& layer : mLayers) // mLayers 배열을 객체 layer에 처음부터 끝까지 넣어주면서 비교. 
		{
			layer.Update(); // 들어오는 객체마다 업데이트 
		}

	}

	void Scene::Render(HDC hdc) // 업데이트와 동일한 원리
	{
		for (Layers& layer : mLayers) 
		{
			layer.Render(HDC hdc); 
		}
	}

}

// 지난번 숙제부터 따라잡고. 
// 오늘 필기는 보면서 따라하기. 

// 유니티 좀 검색해면서 찾기. 
// 0706은 영상 있음. 

// 환희가 보내준 내력 보면서 체크. 

// 숙제: 필요한 씬들의 구성을 클래스 나눠서 해오기 
// 씬 메니저에서 크리에이트 씬 ~ (타이틀 씬 코드 참고) 
// ㄴ 각 씬을 구분할 수 있도록 뭔가 띄워둘 것. (글씨 또는 도형 등) 
// 로드씬이 씬을 바꿔주는 함수. 