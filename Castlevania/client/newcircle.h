#pragma once
#include "Commoninclude.h"
#include "console.h" 

// rand, time 함수용 헤더 
#include <iostream>
#include <cstdlib> // rand, srand  
#include <ctime> // time 


// 여기에서 원을 만들거임 
// 1) 방향
// 2) 충돌여부 

namespace game
{
	class player
	{
	public:
		Vector2 Player;
		bool is_start;
		direct1 saveDirect; 
		// direct1 을 어~ 받아주는 변수. 자료형은 enum class의 이름으로.
	};

	class newcircle1
	{
	public: 

		static void direct(); // 방향 
		static void crash(); // 충돌
	};

	enum class direct1 // 방향을 숫자로 저장 
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

