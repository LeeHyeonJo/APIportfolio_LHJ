#include "console.h"
// #imgui.h ��ġ :: vcpck �ٿ� & ���� 
// https://cheongpark.tistory.com/15 ���� �����ϱ� (�̶��� <>�� ����) 
// ��Ű�� > �ν���� > 64�������>��Ŭ���orlib�� imgui.h�� ��ġ�Ȱ� Ȯ���� �� ����. 

// �Ǵ� ���鿡�� ���� �ڵ带 ���͵� ��. (�̶��� ""���� ����) 
// ������Ͽ��� ������, ���� ������ cpp���� ������. 


// **���� �����̽� �������־�� �ϳ�??**
namespace console 
{
	Application::Application()
		:mHwnd(NULL)
		, mHdc(NULL) // �ڵ鿡 ó�� �ΰ��� �־�� 
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND mHwnd1) // mHwnd1���� ���� 
		// mHwnd �� ���ڰ� �־��ְ� 
		// mHdc�� GetDC �Լ��� ���� �־��ֱ� 
	{
		mHwnd = mHwnd1;

		mHdc = GetDC(mHwnd);
	}

	void Application::Run()
	{
		int a = 0; // �޼����� �������� Ȯ���ϱ� ���� 
		Update();
		Render(); // �̷��� Run �ѹ����� ���°� �������̶�� �� 
	}

	void Application::Update() // �׸� �׸� ���: ���¸� ������Ű�� 
	{
		// vmffpdlddj vhtm.x += 0.1f

		// �ʹ� ������ �׷����Ƿ� Ű �Է��� �־��ֱ�� ��
		// �����쿡�� �⺻���� �����ϴ� �Լ� 

		// Ű���� �����¿� �Լ� ���⿡ �־��� **
	}

	void Application::Render() // ������ ���¸� �׸� 
	{
		// �׸� �׸��� �Լ��� ��;�� ������ 
		// mHDC�� �ڵ��̹ٲ� 
		// ��Ŭ���� �Լ��� ����� ���� ** 
	}
}

