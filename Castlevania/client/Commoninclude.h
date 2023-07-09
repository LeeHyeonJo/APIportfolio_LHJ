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

namespace game::enums // �̳� Ŭ�����ΰ� ǥ���Ϸ��� �̸��� �̷��� ���� 
{
	enum class eLayerType
	{
		Background, //0
		Player,
		Monster,
		Effect,
		UI,
		End, //5 (~6��)
	};
}

