#include "Scene.h"
#include "Layers.h" 

namespace game
{
	Scene::Scene() // ���̾� ���� �迭�� ����(ũ�⸸ �Ҵ�) 
	{ 
		mLayers.resize((int)enums::eLayerType::End);  
		// enum class eLayerType�� Commoninclude.h�� ����. 
		// �� ���ӽ����̽��� ����� ǥ������ �����Ϳ� ����! 

		// �� 5���� ���̾� ����. 
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		mLayers[(int)enums::eLayerType::Player].AddGameObject(); 
		// ù��° ���̾ ���� ������Ʈ�� �����ϴ� �Լ��� ȣ��. 
	}

	void Scene::Update()
	{
		// ��� ���̾ �ѹ��� ������Ʈ �Ǿ�� �ϹǷ� 
		// �ݺ����� ���鼭 ������Ʈ �Ѵ� (for - each �� ����) 

		for (Layer& layer : mLayers) // mLayers �迭�� ��ü layer�� ó������ ������ �־��ָ鼭 ��. 
		{
			layer.Update(); // ������ ��ü���� ������Ʈ 
		}

	}

	void Scene::Render(HDC hdc) // ������Ʈ�� ������ ����
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(HDC hdc); 
		}
	}

}