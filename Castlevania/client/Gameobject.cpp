#include "Gameobject.h"
// Ʈ���� ���
// ��������Ʈ ��� 

namespace game
{ 
	Gameobject::Gameobject()
	{
		mComponents.push_back(new Transform()); 
		// 1. Ʈ������ mComponents �迭�� �־��� 
		// �����ڿ��� ��ü ���� �� ������Ʈ ������ Ÿ���� m������Ʈ �迭�� �־���
	

		mComponents.push_back(new Spriterenderer());
		// 2. ��������Ʈ �������� mComponents �迭�� �־���
		// �����ڿ��� ��ü ���� �� ������Ʈ ������ Ÿ���� m������Ʈ �迭�� �־���
	}
	// ���̾�� ȣ���� Addgameobject�� ���ؼ� ����� �Ѿ��.
	// ���� ������Ʈ�� ������Ʈ ���� �迭�� ��� ����. 
	// ���� ������Ʈ�� ��ƼƼ�� ���. 
	// ������Ʈ �ȿ� �� Ʈ����/�������� ������Ʈ�� �����. 
	// * ������Ʈ�� ��.������ ���Ե� ��, ��ӹް��ִ°� �ƴ��� ����. 

	Gameobject::~Gameobject()
	{
	}

	void Gameobject::Initialize()
	{
	}

	void Gameobject::Update()
	{
		// ���� ������Ʈ ���鶧 
	}

	void Gameobject::Render(HDC hdc)
	{
		// ���� ���� ���鶧 
	}

}
