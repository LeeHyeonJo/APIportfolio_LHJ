#pragma once
#include "Commoninclude.h"
#include "console.h" 

// rand, time �Լ��� ��� 
#include <iostream>
#include <cstdlib> // rand, srand  
#include <ctime> // time 


// ���⿡�� ���� ������� 
// 1) ����
// 2) �浹���� 

namespace game
{
	class player
	{
	public:
		Vector2 Player;
		bool is_start;
		direct1 saveDirect; 
		// direct1 �� ��~ �޾��ִ� ����. �ڷ����� enum class�� �̸�����.
	};

	class newcircle1
	{
	public: 

		static void direct(); // ���� 
		static void crash(); // �浹
	};

	enum class direct1 // ������ ���ڷ� ���� 
	{
		up, // 0
		down, 
		left,
		right, 

		up_right,
		down_right,
		up_left,
		down_left //7
	};
}                         

