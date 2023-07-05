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
		,mHdc(NULL) // �ڵ鿡 ó�� �ΰ��� �־�� (�ʱ�ȭ) 
		,mWidth(0) // �ܻ��� ���� ���簢���� ����, ���� ũ�� 
		,mHeight(0) // .. �� 0 ���� ����
		,mBackBuffer(NULL) // �ι�° ��ȭ���� ������ ���� 
		,mBackHdc(NULL) // f12�� ������ ������ Ÿ������ �� �� �ִ�. 
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
		mHdc = GetDC(mHwnd);
		// GetDC == mHdc ���� �����ִ� �Լ�. 
		// >> ������ �������� �ڵ鰪 2���� ���� �־���. 

		// �� ��ǲ, Ÿ�� �ʱ�ȭ�� ���ؼ� ���� ����. 
		// input & time �ʱ�ȭ 
		//Input::Initailize(); // Ű 

		// �ܻ� �����ִ� ���簢���� �������� ���⼭ �ʱ�ȭ! (���� ��)
		mWidth = 1600; 
		mHeight = 900; 

		// **Ŭ���̾�Ʈ ������ ���� ���ϴ� ũ��� ���� �� ȭ�� ���� ����**
		RECT rect = { 0,0, mWidth, mHeight }; 

		//RECT�� ���ڷ� left, top, right, bottom�� �����ϴ� ����ü. 
		// �� Ŭ���̾�Ʈ ȭ��(������� �ϴ� ũ�� ���� ���⿡ ����) 
		//Ŭ���̾�Ʈ ����: ������ ���� ȭ��
		//��Ŭ���̾�Ʈ ����: ����â, �� ��... 

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		// rect�� ũ�⸦ �޾Ƽ�, "��Ŭ���̾�Ʈ"�������� ������ ������ ũ�⸦ ���. 
		
		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		// ����� ������ ũ�⸸ŭ�� �� ���� (���� ȭ�� �� �������) 

		ShowWindow(mHwnd, true);
		// ��������(�Լ�): �� ������ ��ģ ������â�� ���� ȭ�鿡 ����ش�. 

		// a. ��ȭ�� (������)
		// = ������ API �⺻ �Լ�(ȭ�� ������ִ� ��: �ʿ����ڰ� �⺻�������� ���ڵ�)
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// b.��ȭ��(������)�� ���� mBackHdc ���� = ������ API �⺻ �Լ�(mHdc) �ְ� ��� ��. 
		mBackHdc = CreateCompatibleDC(mHdc);

		// c. �� ��Ʈ�ʿ� �� HDC�� �������־�� �Ѵ�. 
		HBITMAP defaultBitmap  // ��ȯ�ϴ� �� ��ȭ�� �������� ����Ʈ DC
		= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
				// �������ִ� �Լ� (�� HDC, �� ��ȭ��); 

		// d. ��ȯ�� ����Ʈ DC�� �޸𸮿��� ����~
		DeleteObject(defaultBitmap); 

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
		Time::Update(); // Ÿ�� ������Ʈ 
		//Input::Update(); // Ű �Է� ������Ʈ 
		
		newcircle1::direct(); // ���� ������ ����. 
	}

	void Application::Render() // ������ ���¸� "�׸�" & ȭ�鿡 ����ִ� �Լ� 
	{
		Time::Render(mBackHdc); // fps �����.    ** �̰� �� �� �ߴ� �ɱ�?? ** 

		// ** �ܻ� ����� ** // 
		// = �� �̹����� ������. ���׶�� ũ�⸸ŭ�� ���簢���� �׷��� ������. 
		Rectangle(mBackHdc, -1, -1, mWidth+1, mHeight+1);
		// ������ ���� �� ������� �����ҰŰ�, -1, +1�� ȭ�� ũ�⺸�� �� ũ�� �׷������ �Ϻη� ���� ���̰� �÷��� �� 
		// ����: �� �׸���, ���簢�� ���׷����� �ݺ��Ǳ� ������ �������� �����. 


		// �ذ���: �˰��� = ���� ���۸� (����� ȭ���� ��� ���ҵȴٴ� ��) 
		// >> api���� �� �˰����� �������� �����Ƿ�, ����ϰԳ��� �����ؾ� �Ѵ�. 
		// �� ���ۿ� �׸��� �׸���, ������ ����. (���� ������ȭ���� ����) 
		// �� �� ������ �ݺ�. ( = ������ ���� ��) 
		// ����: ȭ���� 2�� ��� (��ȭ�� ������ó�� �����ڴٴ� ��) 


		Ellipse(mBackHdc,
		300 + test.Player.x, 
			300 + test.Player.y, 
			400 + test.Player.x, 
			400 + test.Player.y); // ó�� ��.  

		// ** ���������� ��ȭ���� ������ �� ** 
		// �ʱ�ȭ(�̴ϼȶ�����)���� �� ���۸� �����, HDC�� �������� ����
		// ���⿡���� ���� ��ȭ����, �� ��ȭ���� �������ִ� ������ �Ѵ�. 
		
		BitBlt(mHdc, 0, 0, mWidth, mHeight 
			, mBackHdc, 0, 0, SRCCOPY);  
		// ** ��Ʈ��Ʈ �Լ�(mHDC, �տ��� ���� ��ȭ�� // �ڿ��� ����� ��ȭ�� )) 
		// ����� ��ȭ���� ���� ������ ��� ���� (SRCCOPY) �� ���� ��ȭ���� ī���Ѵ�. 
		// **�׸��� ������ : �鵵ȭ������ �̷�����Ƿ�, ������ HDC�´ٸ� HDC�� �ٲ��� ��**


		// ���� �׸���: main.cpp - WM_PAINT�� �ִ� �׸� �Լ��� �����.
		// ���� main�� �ƴ϶� console���� �׸� �� �ְ� ��.

		// **������ ��ǥ��**
		// ���� �ֻ�� 0,0
		// �Ʒ��� �������� y�� ++ 
		// ���������� ���� x�� ++ 
	}
}

