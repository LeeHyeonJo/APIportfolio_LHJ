#include "Scene.h"

// ����: �� ������� ������ �Լ��� ���ư��� ��
// Layer�� ���õ� ó���� ��. 

namespace game
{
	Scene::Scene()
	{
		// Scene�� �����ڰ� ���� ȣ��
		// resize(); = �迭�� ũ�⸦ �Ҵ��ϴ� �Լ� 
		mLayers.resize((int)enums::eLayerType::End);    
		// Ư: ����� ���̾� �迭�� ũ�⸸ �Ҵ��. (0~5������) 
	}

	Scene::~Scene()
	{
	}

	// ���ӿ�����Ʈ�� *���� �ʱ�ȭ�ɶ�* �߰��Ǳ� �����Ѵ�. 
	// �Ҵ�� ���̾� �迭(0~5)�� "���� ������Ʈ"�� �־��ش�.  
	void Scene::Initialize() 
	{
		mLayers[(int)enums::eLayerType::Player].Addgameobject; 
	}

	// �� ������Ʈ: ��� ���̾� �迭�� ���鼭, ���̾ "������Ʈ" �Ѵ�. 
	// ������Ʈ �Ѵٴ� ��ɸ� �����ϴ� �� 
	void Scene::Update()
	{
		// for - each �� 
		// (�ڷ���& ��ü : �迭�̸�) == �迭�� 0~������ ���鼭 ��ü�� ���� �񱳵�
		for (Layer& layer : mLayers) // == ��� ���̾ ���ٴ� �� 
		{
			layer.Update(); // ���̾��� ������Ʈ�� �̵� 
		}
	}

	void Scene::Render(HDC hdc)
	{
		// ��� ���̾ ���鼭 �׸���. �� �� ��ɱ���. 
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc); // ���̾��� ������ �̵� 
		}
	}
}