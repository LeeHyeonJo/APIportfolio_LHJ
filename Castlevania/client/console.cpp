#include "console.h"
// #imgui.h ��ġ :: vcpck �ٿ� & ���� 
// https://cheongpark.tistory.com/15 ���� �����ϱ� (�̶��� <>�� ����) 
// ��Ű�� > �ν���� > 64�������>��Ŭ���orlib�� imgui.h�� ��ġ�Ȱ� Ȯ���� �� ����. 

// �Ǵ� ���鿡�� ���� �ڵ带 ���͵� ��. (�̶��� ""���� ����) 
// ������Ͽ��� ������, ���� ������ cpp���� ������. 

namespace console 
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
	}

	void Application::Run()
	{
		Update();
		Render(); // �̷��� Run �ѹ����� ���°� �������̶�� �� 
	}

	void Application::Update() // �׸� �׸� ���: ���¸� ����(ex. �̵�)�ϴ� ����
	{
		// �׷����� ���� ���¸� ���⿡�� üũ 
		//mPlayerPos.x += 0.01f;
		//mPlayerPos.y += 0.01f;

		// ** ����Ű �Է¿� ���� �̵��ϰ� ������. 
		// ** �����쿡�� �����ϴ� ����Ű �ν� �Լ� 
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			// ��
			mPlayerPos.x -= 0.01f; 
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			// ��
			mPlayerPos.x += 0.01f; 
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			// ��
			mPlayerPos.y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			// �Ʒ�
			mPlayerPos.y += 0.01f; 
		}
	}

	void Application::Render() // ������ ���¸� "�׸�" 
	{
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

