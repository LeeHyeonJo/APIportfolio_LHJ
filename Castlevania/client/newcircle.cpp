#include "newcircle.h"
#include "consoleMath.h" 

namespace game
{
	player test; 

	void newcircle1::direct()
	{
		if (test.is_start == true) // 첫 시작 랜덤하게 돌아갈 수 있도록. 
		{
			srand((unsigned int)time(NULL));
			int randnum = rand() % 8; // 0~7까지
			test.saveDirect = (direct1)randnum;  // 랜덤한 방향으로 처음 시작. 
			test.is_start = false; 
		}

		// randnum의 숫자에 따라 프로그램 실행할때마다 방향 전환 
		if (test.saveDirect == direct1::up) // 위 
		{
			test.Player.x -= 500.0f * Time::Deltatime();
		}

		else if (test.saveDirect == direct1::down) // 아래
		{
			test.Player.y+= 500.0f * Time::Deltatime();
		}

		else if (test.saveDirect == direct1::left) // 왼
		{
			test.Player.x -= 500.0f * Time::Deltatime();

		}

		else if (test.saveDirect == direct1::right) // 우
		{
			test.Player.x += 500.0f * Time::Deltatime();

		}

		else if (test.saveDirect == direct1::up_right) // 우측 위 대각선
		{
			test.Player.y -= 500.0f * Time::Deltatime(); // w 위
			test.Player.x += 500.0f * Time::Deltatime();  // d 우 

		}

		else if (test.saveDirect == direct1::down_right) // 우측 아래 대각선
		{
			test.Player.y += 500.0f * Time::Deltatime(); // s 아래
			test.Player.x += 500.0f * Time::Deltatime();   // d 우
			 
		}

		else if (test.saveDirect == direct1::up_left) // 좌측 위 대각선 
		{
			test.Player.y -= 500.0f * Time::Deltatime(); // w 위
			test.Player.x -= 500.0f * Time::Deltatime(); // a 왼 

		}

		else if (test.saveDirect == direct1::up_left) // 좌측 아래 대각선 
		{
			test.Player.y += 500.0f * Time::Deltatime(); // s 아래
			test.Player.x -= 500.0f * Time::Deltatime(); // a 왼 
		}
	}

	void newcircle1::crash() // 충돌
	{
		// 900x600

		if (test.Player.x < 0 || test.Player.x>900 || test.Player.y<0 || test.Player.y>600)
		{  
			// 다른곳으로 가~!

			
		}
	}
}
