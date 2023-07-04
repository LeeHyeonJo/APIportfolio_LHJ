#include "console.h"
#include "Inputclass.h" 
#include "Time.h" 
#include "newcircle.h"   

// #imgui.h ��ġ :: vcpck �ٿ� & ���� 
// https://cheongpark.tistory.com/15 ���� �����ϱ� (�̶��� <>�� ����) 
// ��Ű�� > �ν���� > 64�������>��Ŭ���orlib�� imgui.h�� ��ġ�Ȱ� Ȯ���� �� ����. 

// �Ǵ� ���鿡�� ���� �ڵ带 ���͵� ��. (�̶��� ""���� ����) 
// ������Ͽ��� ������, ���� ������ cpp���� ������. 

namespace game
{
	extern player test; // ��Ŭ cpp���� ���������� ������ �η��ö� .extern, 

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
		
		newcircle1::direct(); // ���� �ƴ�. 

		// ���� �����̴� ���� 
		//mPlayerPos.y -= 300.0f * Time::Deltatime(); // w ��
		//mPlayerPos.x -= 300.0f * Time::Deltatime(); // a ��
		//mPlayerPos.y += 300.0f * Time::Deltatime(); // s �Ʒ�
		//mPlayerPos.x += 300.0f * Time::Deltatime();  // d ��
	}

	void Application::Render() // ������ ���¸� "�׸�"  & ȭ�鿡 ����ִ� �Լ� 
	{
		Time::Render(mHdc); // ~���⼭ fps ����ֱ�   


		Ellipse(mHdc,
			0 + test.Player.x, 
			0 + test.Player.y, 
			100 + test.Player.x, 
			100 + test.Player.y); // ó�� ��.  



		// ���� �׸���: main.cpp - WM_PAINT�� �ִ� �׸� �Լ��� �����.
		// ���� main�� �ƴ϶� console���� �׸� �� �ְ� ��.

		// **������ ��ǥ��**
		// ���� �ֻ�� 0,0
		// �Ʒ��� �������� y�� ++ 
		// ���������� ���� x�� ++ 
	}
}

