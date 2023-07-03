#include "console.h"
#include "Inputclass.h" 
#include "Time.h" 

// rand, time �Լ��� ��� 
#include <iostream>
#include <cstdlib> // rand, srand 
#include <ctime> // time 

// #imgui.h ��ġ :: vcpck �ٿ� & ���� 
// https://cheongpark.tistory.com/15 ���� �����ϱ� (�̶��� <>�� ����) 
// ��Ű�� > �ν���� > 64�������>��Ŭ���orlib�� imgui.h�� ��ġ�Ȱ� Ȯ���� �� ����. 

// �Ǵ� ���鿡�� ���� �ڵ带 ���͵� ��. (�̶��� ""���� ����) 
// ������Ͽ��� ������, ���� ������ cpp���� ������. 

namespace game
{
	Application::Application() // ������ 
		:mHwnd(NULL)
		, mHdc(NULL) // �ڵ鿡 ó�� �ΰ��� �־�� (�ʱ�ȭ) 
	{
	}

	Application::~Application() //�Ҹ��� 
	{
	}
	// �ٸ�� �ʱ�ȭ�� ��� 
	// ** main���� �����찡 ������ �� , ù �ʱ�ȭ // ���ڷ� ������ â ���� �� ��ȯ�� �ڵ��� mHwnd1������ ���� 
	void Application::Initialize(HWND mHwnd1, POINT resolution1)   // mHwnd �� ���ڰ� �־��ְ� & mHdc�� GetDC �Լ��� ���� �־��ֱ� 
	{	// �� ������ console.h���� ��������. 
		mHwnd = mHwnd1;
		mHdc = GetDC(mHwnd);
		// GetDC == mHdc ���� �����ִ� �Լ�. 
		// >> ������ �������� �ڵ鰪 2���� ���� �־���. 

		//			   ���ο��� ������ 900,600
		RECT rect = { 0, 0, resolution1.x, resolution1.y }; 
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true); //&rect�� rect�� ����. (����â �� ũ��)
		SetWindowPos(mHwnd, nullptr, 100, 100, rect.right - rect.left, rect.bottom - rect.top, 0);
		// ����â �� ũ�Ⱑ 900,600�ΰɷ� ȭ�� �����. 908, -8, 608, -51

		// �� ��ǲ, Ÿ�� �ʱ�ȭ�� ���ؼ� ���� ����. 
		// input & time �ʱ�ȭ 
		//Input::Initailize(); // Ű 
		Time::Initiailize();  // �ð� 
	}

	void Application::Run()
	{
		Update();
		Render(); // �̷��� Run �ѹ����� ���°� �������̶�� �� 
	}

	// �׸� �׸� ���: ���¸� ����(ex. �̵�)�ϴ� ����
	void Application::Update()
	{
		Time::Update(); // ~���⼭ Ÿ�� ������Ʈ 
		//Input::Update(); // Ű ������Ʈ 
		
		srand((unsigned int)time(NULL)); 
		int randnum = rand() % 8 + 1; // 1~8����

		// randnum�� ���ڿ� ���� ���α׷� �����Ҷ����� ���� ��ȯ 

		if (randnum == 1) // ��
		{
			mPlayerPos.y -= 500.0f * Time::Deltatime();
		}

		else if (randnum == 2) // �Ʒ�
		{
			mPlayerPos.y += 500.0f * Time::Deltatime();

		}

		else if (randnum == 3) // ��
		{
			mPlayerPos.x -= 500.0f * Time::Deltatime();

		}

		else if (randnum == 4) // ��
		{
			mPlayerPos.x += 500.0f * Time::Deltatime(); 

		}

		else if (randnum == 5) // ���� �� �밢��
		{
			mPlayerPos.y -= 500.0f * Time::Deltatime(); // w ��
			mPlayerPos.x += 500.0f * Time::Deltatime();  // d ��

		}

		else if (randnum == 6) // ���� �Ʒ� �밢��
		{
			mPlayerPos.y += 500.0f * Time::Deltatime(); // s �Ʒ�
			mPlayerPos.x += 500.0f * Time::Deltatime();   // d ��

		}

		else if (randnum == 7) // ���� �� �밢�� 
		{
			mPlayerPos.y -= 500.0f * Time::Deltatime(); // w ��
			mPlayerPos.x -= 500.0f * Time::Deltatime(); // a �� 

		}

		else if (randnum == 8) // ���� �Ʒ� �밢�� 
		{
			mPlayerPos.y += 500.0f * Time::Deltatime(); // s �Ʒ�
			mPlayerPos.x -= 500.0f * Time::Deltatime(); // a �� 
		}

		// ���� �����̴� ���� 
		//mPlayerPos.y -= 300.0f * Time::Deltatime(); // w ��
		//mPlayerPos.x -= 300.0f * Time::Deltatime(); // a ��
		//mPlayerPos.y += 300.0f * Time::Deltatime(); // s �Ʒ�
		//mPlayerPos.x += 300.0f * Time::Deltatime();  // d ��
	}

	void Application::Render() // ������ ���¸� "�׸�"  & ȭ�鿡 ����ִ� �Լ� 
	{
		Time::Render(mHdc); // ~���⼭ fps ����ֱ�   

		static float circletime = 0.0f;
		circletime += Time::Deltatime(); // �ð� üũ 

		srand((unsigned int)time(NULL));
		int randnum2 = rand() % 5 + 1; // 1~5����

		int x1 = randnum2 * 100; 
		int y1 = randnum2 * 100 + 100; 


		if (circletime >= 1.0f) // �� �߰� 
		{
			Ellipse(mHdc, x1 + mPlayerPos.x, x1 + mPlayerPos.y, y1 + mPlayerPos.x, y1 + mPlayerPos.y); 

			circletime = 0.0f; 
		}

	  Ellipse(mHdc, 0 + mPlayerPos.x, 0 + mPlayerPos.y, 100 + mPlayerPos.x, 100 + mPlayerPos.y); // ó�� ��. 



		// ���� �׸���: main.cpp - WM_PAINT�� �ִ� �׸� �Լ��� �����.
		// ���� main�� �ƴ϶� console���� �׸� �� �ְ� ��.

		// **������ ��ǥ��**
		// ���� �ֻ�� 0,0
		// �Ʒ��� �������� y�� ++ 
		// ���������� ���� x�� ++ 
	}
}

