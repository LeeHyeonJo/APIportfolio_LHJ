#include "console.h"
#include "Inputclass.h" 
#include "Time.h" 

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

	// ** ���� �귯���� ���� �ľ��ϱ�. 
	void Application::Initialize(HWND mHwnd1) // ���ڷ� mHwnd1���� ���� 
		// mHwnd �� ���ڰ� �־��ְ� & mHdc�� GetDC �Լ��� ���� �־��ֱ� 
	{// �� ������ console.h���� ��������. 
		mHwnd = mHwnd1;
		mHdc = GetDC(mHwnd); // GetDC == mHdc ���� �����ִ� �Լ�. 

		// �� ��ǲ, Ÿ�� �ʱ�ȭ�� ���ؼ� ���� ����. 
		Input::Initailize(); // Ű 
		Time::Initiailize();  // �ð� 
	}

	void Application::Run()
	{
		Update();
		Render(); // �̷��� Run �ѹ����� ���°� �������̶�� �� 
	}

	void Application::Update() // �׸� �׸� ���: ���¸� ����(ex. �̵�)�ϴ� ����
	{
	//�ڿ��⸦ if���� �ƴ϶�...~ 
		// input Ŭ������ �̿��ؼ� ������ ����. WASD �Է¿� ���� �����̵��� �����Ѵ�. 

		Time::Update(); // ~���⼭ Ÿ�� ������Ʈ 
		Input::Update(); // Ű ������Ʈ 

		if (Input::GetKey(eKeycode::W))
		{
			mPlayerPos.y -= 300.0f * Time::Deltatime();
			// ��ŸŸ������ ������ ���� �ִ´�(��)
			// mDeltaTime�� private�� ���� �Ұ���, public�Լ��� ���� ����. 
		}
		if (Input::GetKey(eKeycode::A))
		{
			mPlayerPos.x -= 300.0f * Time::Deltatime(); 
		}
		if (Input::GetKey(eKeycode::S))
		{
			mPlayerPos.y += 300.0f * Time::Deltatime(); 
		}
		if (Input::GetKey(eKeycode::D))
		{
			mPlayerPos.x += 300.0f * Time::Deltatime();  
		}
	
	}

	void Application::Render() // ������ ���¸� "�׸�"  & ȭ�鿡 ����ִ� �Լ� 
	{
		Time::Render(mHdc); // ~���⼭ Ÿ�� - �ð� ����ֱ� 
		// ���� �׸���: main.cpp - WM_PAINT�� �ִ� �׸� �Լ��� �����.
		Ellipse(mHdc, 
			 200 + mPlayerPos.x
			,200 + mPlayerPos.y

			,400 + mPlayerPos.x
			,400 + mPlayerPos.y
		); // ���� main�� �ƴ϶� console���� �׸� �� �ְ� ��. 

		// **������ ��ǥ��**
		// ���� �ֻ�� 0,0
		// �Ʒ��� �������� y�� ++ 
		// ���������� ���� x�� ++ 
	}
}

