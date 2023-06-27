#include "console.h"
// #imgui.h 설치 :: vcpck 다운 & 연결 
// https://cheongpark.tistory.com/15 보고 따라하기 (이때는 <>로 선언) 
// 페키지 > 인스톨드 > 64윈도우기>인클루드orlib에 imgui.h가 설치된걸 확인할 수 있음. 

// 또는 깃헙에서 직접 코드를 따와도 됨. (이때는 ""으로 선언) 
// 헤더파일에는 선언을, 실제 실행은 cpp에서 구현함. 


// **네임 스페이스 지정해주어야 하나??**
namespace console 
{
	Application::Application()
		:mHwnd(NULL)
		, mHdc(NULL) // 핸들에 처음 널값을 넣어둠 
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND mHwnd1) // mHwnd1값이 들어가고 
		// mHwnd 에 인자값 넣어주고 
		// mHdc에 GetDC 함수로 인자 넣어주기 
	{
		mHwnd = mHwnd1;

		mHdc = GetDC(mHwnd);
	}

	void Application::Run()
	{
		int a = 0; // 메세지가 들어오는지 확인하기 위해 
		Update();
		Render(); // 이렇게 Run 한바퀴가 도는걸 프레임이라고 함 
	}

	void Application::Update() // 그림 그릴 경우: 상태를 증가시키고 
	{
		// vmffpdlddj vhtm.x += 0.1f

		// 너무 빠르게 그려지므로 키 입력을 넣어주기로 함
		// 윈도우에서 기본으로 제공하는 함수 

		// 키보드 상하좌우 함수 여기에 넣어줌 **
	}

	void Application::Render() // 증가한 상태를 그림 
	{
		// 그림 그리는 함수를 역;로 가져욤 
		// mHDC로 핸들이바뀜 
		// 이클립스 함수가 여기로 들어옴 ** 
	}
}

