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
	void Application::Initialize(HWND mHwnd1)   // mHwnd �� ���ڰ� �־��ְ� & mHdc�� GetDC �Լ��� ���� �־��ֱ� 
	{	// �� ������ console.h���� ��������. 
		mHwnd = mHwnd1;
		mHdc = GetDC(mHwnd); // GetDC == mHdc ���� �����ִ� �Լ�. 
		// >> ������ �������� �ڵ鰪 2���� ���� �־��� 

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

	void Application::Update() // �׸� �׸� ���: ���¸� ����(ex. �̵�)�ϴ� ����
	{
		Time::Update(); // ~���⼭ Ÿ�� ������Ʈ 
		//Input::Update(); // Ű ������Ʈ 
		
		srand((unsigned int)time(NULL)); 
		int randnum = rand() % 8 + 1; // 1~8����

		// randnum�� ���ڿ� ���� ���α׷� �����Ҷ����� ���� ��ȯ 

		if (randnum == 1) // ��
		{
			mPlayerPos.y -= 200.0f * Time::Deltatime();
		}

		else if (randnum == 2) // �Ʒ�
		{
			mPlayerPos.y += 200.0f * Time::Deltatime();
		}

		else if (randnum == 3) // ��
		{
			mPlayerPos.x -= 200.0f * Time::Deltatime();
		}

		else if (randnum == 4) // ��
		{
			mPlayerPos.x += 200.0f * Time::Deltatime(); 
		}

		else if (randnum == 5) // ���� �� �밢��
		{
			mPlayerPos.y -= 200.0f * Time::Deltatime(); // w ��
			mPlayerPos.x += 200.0f * Time::Deltatime();  // d ��
		}

		else if (randnum == 6) // ���� �Ʒ� �밢��
		{
			mPlayerPos.y += 200.0f * Time::Deltatime(); // s �Ʒ�
			mPlayerPos.x += 200.0f * Time::Deltatime();   // d ��
		}

		else if (randnum == 7) // ���� �� �밢�� 
		{
			mPlayerPos.y -= 200.0f * Time::Deltatime(); // w ��
			mPlayerPos.x -= 200.0f * Time::Deltatime(); // a �� 
		}

		else if (randnum == 8) // ���� �Ʒ� �밢�� 
		{
			mPlayerPos.y += 200.0f * Time::Deltatime(); // s �Ʒ�
			mPlayerPos.x -= 200.0f * Time::Deltatime(); // a �� 
		}

		// ���� �����̴� ���� 
		//mPlayerPos.y -= 300.0f * Time::Deltatime(); // w ��
		//mPlayerPos.x -= 300.0f * Time::Deltatime(); // a ��
		//mPlayerPos.y += 300.0f * Time::Deltatime(); // s �Ʒ�
		//mPlayerPos.x += 300.0f * Time::Deltatime();  // d ��
	
	}

	void Application::Render() // ������ ���¸� "�׸�"  & ȭ�鿡 ����ִ� �Լ� 
	{
		Time::Render(mHdc); // ~���⼭ Ÿ�� - �ð� ����ֱ� 
		// ���� �׸���: main.cpp - WM_PAINT�� �ִ� �׸� �Լ��� �����.
		Ellipse(mHdc, 
			 300 + mPlayerPos.x
			,300 + mPlayerPos.y

			,400 + mPlayerPos.x
			,400 + mPlayerPos.y
		); // ���� main�� �ƴ϶� console���� �׸� �� �ְ� ��. 

		// **������ ��ǥ��**
		// ���� �ֻ�� 0,0
		// �Ʒ��� �������� y�� ++ 
		// ���������� ���� x�� ++ 
	}
}

