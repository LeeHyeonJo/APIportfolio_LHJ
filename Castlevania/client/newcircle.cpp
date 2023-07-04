#include "newcircle.h"
#include "consoleMath.h" 

namespace game
{
	player test; 

	void newcircle1::direct()
	{
		if (test.is_start == true) // ù ���� �����ϰ� ���ư� �� �ֵ���. 
		{
			srand((unsigned int)time(NULL));
			int randnum = rand() % 8; // 0~7����
			test.saveDirect = (direct1)randnum;  // ������ �������� ó�� ����. 
			test.is_start = false; 
		}

		// randnum�� ���ڿ� ���� ���α׷� �����Ҷ����� ���� ��ȯ 
		if (test.saveDirect == direct1::up) // �� 
		{
			test.Player.x -= 500.0f * Time::Deltatime();
		}

		else if (test.saveDirect == direct1::down) // �Ʒ�
		{
			test.Player.y+= 500.0f * Time::Deltatime();
		}

		else if (test.saveDirect == direct1::left) // ��
		{
			test.Player.x -= 500.0f * Time::Deltatime();

		}

		else if (test.saveDirect == direct1::right) // ��
		{
			test.Player.x += 500.0f * Time::Deltatime();

		}

		else if (test.saveDirect == direct1::up_right) // ���� �� �밢��
		{
			test.Player.y -= 500.0f * Time::Deltatime(); // w ��
			test.Player.x += 500.0f * Time::Deltatime();  // d �� 

		}

		else if (test.saveDirect == direct1::down_right) // ���� �Ʒ� �밢��
		{
			test.Player.y += 500.0f * Time::Deltatime(); // s �Ʒ�
			test.Player.x += 500.0f * Time::Deltatime();   // d ��
			 
		}

		else if (test.saveDirect == direct1::up_left) // ���� �� �밢�� 
		{
			test.Player.y -= 500.0f * Time::Deltatime(); // w ��
			test.Player.x -= 500.0f * Time::Deltatime(); // a �� 

		}

		else if (test.saveDirect == direct1::up_left) // ���� �Ʒ� �밢�� 
		{
			test.Player.y += 500.0f * Time::Deltatime(); // s �Ʒ�
			test.Player.x -= 500.0f * Time::Deltatime(); // a �� 
		}
	}

	void newcircle1::crash() // �浹
	{
		// 900x600

		if (test.Player.x < 0 || test.Player.x>900 || test.Player.y<0 || test.Player.y>600)
		{  
			// �ٸ������� ��~!

			
		}
	}
}
