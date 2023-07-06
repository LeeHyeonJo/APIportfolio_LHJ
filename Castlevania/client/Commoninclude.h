// �� ������ ����:: ���̺귯���� ������ �ڷᱸ������ �����ͼ� ����Ұ���. 
// �׸��� ���α׷�(console)�� �ʿ��� ������� �� ���� ��Ƶξ���.

#pragma once // ��ġ�� ����� ������ �־ �ϳ��� �����ͼ� ����� �� �ְ� ���ִ� ���� 
#include <vector> // �迭 ���̺귯�� (���� �迭) 
#include <list> // ��ũ�� ����Ʈ ���̺귯�� 
#include <map> // Ʈ�� ���� 
#include <set> // �ؽ� ���̺� ���� 
#include <functional> // �Լ� �����͵� ��ü�� �����ؼ� ���� ����� �� ����. 
#include <string>

// ������ - ����� �ִ� ����� common  ���� �����ִ°ǰ�? Ȯ���غ��� 
#include "framework.h"

// ���� ���� ��� (- ���͸� ������ ���� - ) : ���� ��ġ�� �޾��ִ� �� 
// ������ ���⼭ �ϰ�, ������ consoleMath.h���� �صδ� ��. 
#include "consoleMath.h" 
#include "Time.h"


namespace game::enums 
{
	enum class eLayerType
	{
		Background,
		Player,
		Monster,
		Effect,
		UI, 
		End, 
	};

	// �ι�° �̳� Ŭ���� 
	// ���۳�Ʈ�ȿ��� �����ɶ�, ��������� �༮���� �̸��� �ٿ��ִ� �뵵. 
	// �̰� ������ ����Ƽ ������ ����Ŭ�� ����. 
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		End,
	};
}
