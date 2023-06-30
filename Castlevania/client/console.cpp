#include "console.h"
#include "Inputclass.h" 
#include "Time.h" 

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

	// ** 여기 흘러가는 구조 파악하기. 
	void Application::Initialize(HWND mHwnd1) // 인자로 mHwnd1값이 들어가고 
		// mHwnd 에 인자값 넣어주고 & mHdc에 GetDC 함수로 인자 넣어주기 
	{// 이 변수들 console.h에서 선언했음. 
		mHwnd = mHwnd1;
		mHdc = GetDC(mHwnd); // GetDC == mHdc 값을 구해주는 함수. 

		// ★ 인풋, 타입 초기화를 안해서 생긴 문제. 
		Input::Initailize(); // 키 
		Time::Initiailize();  // 시간 
	}

	void Application::Run()
	{
		Update();
		Render(); // 이렇게 Run 한바퀴가 도는걸 프레임이라고 함 
	}

	void Application::Update() // 그림 그릴 경우: 상태를 증가(ex. 이동)하는 역할
	{
	//★여기를 if문이 아니라...~ 
		// input 클래스를 이용해서 구현할 것임. WASD 입력에 따라서 움직이도록 구현한다. 

		Time::Update(); // ~여기서 타임 업데이트 
		Input::Update(); // 키 업데이트 

		if (Input::GetKey(eKeycode::W))
		{
			mPlayerPos.y -= 300.0f * Time::Deltatime();
			// 델타타임으로 보정한 값을 넣는다(곱)
			// mDeltaTime은 private라 접근 불가능, public함수로 만들어서 접근. 
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

	void Application::Render() // 증가한 상태를 "그림"  & 화면에 띄워주는 함수 
	{
		Time::Render(mHdc); // ~여기서 타임 - 시간 띄워주기 
		// 원을 그릴것: main.cpp - WM_PAINT에 있던 그림 함수가 여기로.
		Ellipse(mHdc, 
			 200 + mPlayerPos.x
			,200 + mPlayerPos.y

			,400 + mPlayerPos.x
			,400 + mPlayerPos.y
		); // 원을 main이 아니라 console에서 그릴 수 있게 됨. 

		// **윈도우 좌표계**
		// 좌측 최상단 0,0
		// 아래로 내려가면 y축 ++ 
		// 오른쪽으로 가면 x축 ++ 
	}
}

