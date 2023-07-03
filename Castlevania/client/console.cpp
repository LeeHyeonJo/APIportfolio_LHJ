#include "console.h"
#include "Inputclass.h" 
#include "Time.h" 

// rand, time 함수용 헤더 
#include <iostream>
#include <cstdlib> // rand, srand 
#include <ctime> // time 

// #imgui.h 설치 :: vcpck 다운 & 연결 
// https://cheongpark.tistory.com/15 보고 따라하기 (이때는 <>로 선언) 
// 페키지 > 인스톨드 > 64윈도우기>인클루드orlib에 imgui.h가 설치된걸 확인할 수 있음. 

// 또는 깃헙에서 직접 코드를 따와도 됨. (이때는 ""으로 선언) 
// 헤더파일에는 선언을, 실제 실행은 cpp에서 구현함. 

namespace game
{
	Application::Application() // 생성자 
		:mHwnd(NULL)
		, mHdc(NULL) // 핸들에 처음 널값을 넣어둠 (초기화) 
	{
	}

	Application::~Application() //소멸자 
	{
	}
	// ☆모든 초기화를 담당 
	// ** main에서 윈도우가 생성된 후 , 첫 초기화 // 인자로 윈도우 창 생성 후 반환된 핸들이 mHwnd1값으로 들어가고 
	void Application::Initialize(HWND mHwnd1, POINT resolution1)   // mHwnd 에 인자값 넣어주고 & mHdc에 GetDC 함수로 인자 넣어주기 
	{	// 이 변수들 console.h에서 선언했음. 
		mHwnd = mHwnd1;
		mHdc = GetDC(mHwnd);
		// GetDC == mHdc 값을 구해주는 함수. 
		// >> 생성된 윈도우의 핸들값 2개를 각각 넣어줌. 

		//			   메인에서 생성시 900,600
		RECT rect = { 0, 0, resolution1.x, resolution1.y }; 
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true); //&rect로 rect를 받음. (상태창 뺀 크기)
		SetWindowPos(mHwnd, nullptr, 100, 100, rect.right - rect.left, rect.bottom - rect.top, 0);
		// 상태창 뺀 크기가 900,600인걸로 화면 재생성. 908, -8, 608, -51

		// ★ 인풋, 타입 초기화를 안해서 생긴 문제. 
		// input & time 초기화 
		//Input::Initailize(); // 키 
		Time::Initiailize();  // 시간 
	}

	void Application::Run()
	{
		Update();
		Render(); // 이렇게 Run 한바퀴가 도는걸 프레임이라고 함 
	}

	// 그림 그릴 경우: 상태를 증가(ex. 이동)하는 역할
	void Application::Update()
	{
		Time::Update(); // ~여기서 타임 업데이트 
		//Input::Update(); // 키 업데이트 
		
		srand((unsigned int)time(NULL)); 
		int randnum = rand() % 8 + 1; // 1~8까지

		// randnum의 숫자에 따라 프로그램 실행할때마다 방향 전환 

		if (randnum == 1) // 위
		{
			mPlayerPos.y -= 500.0f * Time::Deltatime();
		}

		else if (randnum == 2) // 아래
		{
			mPlayerPos.y += 500.0f * Time::Deltatime();

		}

		else if (randnum == 3) // 왼
		{
			mPlayerPos.x -= 500.0f * Time::Deltatime();

		}

		else if (randnum == 4) // 우
		{
			mPlayerPos.x += 500.0f * Time::Deltatime(); 

		}

		else if (randnum == 5) // 우측 위 대각선
		{
			mPlayerPos.y -= 500.0f * Time::Deltatime(); // w 위
			mPlayerPos.x += 500.0f * Time::Deltatime();  // d 우

		}

		else if (randnum == 6) // 우측 아래 대각선
		{
			mPlayerPos.y += 500.0f * Time::Deltatime(); // s 아래
			mPlayerPos.x += 500.0f * Time::Deltatime();   // d 우

		}

		else if (randnum == 7) // 좌측 위 대각선 
		{
			mPlayerPos.y -= 500.0f * Time::Deltatime(); // w 위
			mPlayerPos.x -= 500.0f * Time::Deltatime(); // a 왼 

		}

		else if (randnum == 8) // 좌측 아래 대각선 
		{
			mPlayerPos.y += 500.0f * Time::Deltatime(); // s 아래
			mPlayerPos.x -= 500.0f * Time::Deltatime(); // a 왼 
		}

		// 원이 움직이는 방향 
		//mPlayerPos.y -= 300.0f * Time::Deltatime(); // w 위
		//mPlayerPos.x -= 300.0f * Time::Deltatime(); // a 왼
		//mPlayerPos.y += 300.0f * Time::Deltatime(); // s 아래
		//mPlayerPos.x += 300.0f * Time::Deltatime();  // d 우
	}

	void Application::Render() // 증가한 상태를 "그림"  & 화면에 띄워주는 함수 
	{
		Time::Render(mHdc); // ~여기서 fps 띄워주기   

		static float circletime = 0.0f;
		circletime += Time::Deltatime(); // 시간 체크 

		srand((unsigned int)time(NULL));
		int randnum2 = rand() % 5 + 1; // 1~5까지

		int x1 = randnum2 * 100; 
		int y1 = randnum2 * 100 + 100; 


		if (circletime >= 1.0f) // 원 추가 
		{
			Ellipse(mHdc, x1 + mPlayerPos.x, x1 + mPlayerPos.y, y1 + mPlayerPos.x, y1 + mPlayerPos.y); 

			circletime = 0.0f; 
		}

	  Ellipse(mHdc, 0 + mPlayerPos.x, 0 + mPlayerPos.y, 100 + mPlayerPos.x, 100 + mPlayerPos.y); // 처음 원. 



		// 원을 그릴것: main.cpp - WM_PAINT에 있던 그림 함수가 여기로.
		// 원을 main이 아니라 console에서 그릴 수 있게 됨.

		// **윈도우 좌표계**
		// 좌측 최상단 0,0
		// 아래로 내려가면 y축 ++ 
		// 오른쪽으로 가면 x축 ++ 
	}
}

