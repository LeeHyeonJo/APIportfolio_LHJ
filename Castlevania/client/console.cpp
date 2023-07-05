#include "console.h"
#include "Inputclass.h" 
#include "Time.h" 
#include "newcircle.h"   

// #imgui.h 설치 :: vcpck 다운 & 연결 
// https://cheongpark.tistory.com/15 보고 따라하기 (이때는 <>로 선언) 
// 페키지 > 인스톨드 > 64윈도우기>인클루드orlib에 imgui.h가 설치된걸 확인할 수 있음. 

// 또는 깃헙에서 직접 코드를 따와도 됨. (이때는 ""으로 선언) 
// 헤더파일에는 선언을, 실제 실행은 cpp에서 구현함. 

namespace game
{
	extern player test; // 서클 cpp에서 전역선언한 변수를 부러올때 .extern, 

	Application::Application() // 생성자 
		:mHwnd(NULL)
		,mHdc(NULL) // 핸들에 처음 널값을 넣어둠 (초기화) 
		,mWidth(0) // 잔상을 덮을 직사각형의 가로, 세로 크기 
		,mHeight(0) // .. 를 0 으로 생성
		,mBackBuffer(NULL) // 두번째 도화지용 변수들 생성 
		,mBackHdc(NULL) // f12로 들어가보면 포인터 타입임을 알 수 있다. 
	{
	}

	Application::~Application() //소멸자 
	{
	}

	// ☆모든 초기화를 담당 
	// ** main에서 윈도우가 생성된 후 , 첫 초기화 // 인자로 윈도우 창 생성 후 반환된 핸들이 mHwnd1값으로 들어가고 
	void Application::Initialize(HWND mHwnd1)   // mHwnd 에 인자값 넣어주고 & mHdc에 GetDC 함수로 인자 넣어주기 
	{	// 이 변수들 console.h에서 선언했음. 
		mHwnd = mHwnd1;
		mHdc = GetDC(mHwnd);
		// GetDC == mHdc 값을 구해주는 함수. 
		// >> 생성된 윈도우의 핸들값 2개를 각각 넣어줌. 

		// ★ 인풋, 타입 초기화를 안해서 생긴 문제. 
		// input & time 초기화 
		//Input::Initailize(); // 키 

		// 잔상 덮어주는 직사각형용 변수들을 여기서 초기화! (생성 후)
		mWidth = 1600; 
		mHeight = 900; 

		// **클라이언트 영역을 내가 원하는 크기로 조정 후 화면 띄우는 과정**
		RECT rect = { 0,0, mWidth, mHeight }; 

		//RECT는 인자로 left, top, right, bottom을 저장하는 구조체. 
		// ㄴ 클라이언트 화면(만들고자 하는 크기 값을 여기에 저장) 
		//클라이언트 영역: 순수한 게임 화면
		//비클라이언트 영역: 상태창, 바 등... 

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		// rect의 크기를 받아서, "비클라이언트"영역까지 포함한 윈도우 크기를 계산. 
		
		SetWindowPos(mHwnd
			, nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		// 계산한 윈도우 크기만큼을 재 세팅 (아직 화면 안 만들어짐) 

		ShowWindow(mHwnd, true);
		// 쇼윈도우(함수): 위 과정을 거친 윈도우창을 드디어 화면에 띄워준다. 

		// a. 도화지 (엠버퍼)
		// = 윈도우 API 기본 함수(화면 만들어주는 것: 필요인자가 기본윈도우의 인자들)
		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);

		// b.도화지(엠버퍼)를 위한 mBackHdc 생성 = 윈도우 API 기본 함수(mHdc) 넣고 뱉게 함. 
		mBackHdc = CreateCompatibleDC(mHdc);

		// c. 새 비트맵에 새 HDC를 연결해주어야 한다. 
		HBITMAP defaultBitmap  // 반환하는 건 도화지 엠버퍼의 디폴트 DC
		= (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
				// 연결해주는 함수 (새 HDC, 새 도화지); 

		// d. 반환된 디폴트 DC를 메모리에서 해제~
		DeleteObject(defaultBitmap); 

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
		Time::Update(); // 타임 업데이트 
		//Input::Update(); // 키 입력 업데이트 
		
		newcircle1::direct(); // 원이 움직일 방향. 
	}

	void Application::Render() // 증가한 상태를 "그림" & 화면에 띄워주는 함수 
	{
		Time::Render(mBackHdc); // fps 띄워줌.    ** 이건 왜 안 뜨는 걸까?? ** 

		// ** 잔상 지우기 ** // 
		// = 흰 이미지를 덮어씌운다. 동그라미 크기만큼의 직사각형을 그려서 덮어씌운다. 
		Rectangle(mBackHdc, -1, -1, mWidth+1, mHeight+1);
		// 변수는 따로 이 헤더에서 저장할거고, -1, +1은 화면 크기보다 더 크게 그려지라고 일부러 숫자 줄이고 늘려준 것 
		// 문제: 원 그리고, 직사각형 덧그려지고 반복되기 때문에 깜빡임이 생긴다. 


		// 해결방식: 알고리즘 = 더블 버퍼링 (교대로 화면이 계속 스왑된다는 뜻) 
		// >> api에선 이 알고리즘을 제공하지 않으므로, 비슷하게나마 구현해야 한다. 
		// 백 버퍼에 그림을 그리고, 원본에 복사. (눈은 원래도화지에 고정) 
		// ㄴ 이 과정을 반복. ( = 깜빡임 제거 용) 
		// 원리: 화면을 2개 사용 (만화경 프레임처럼 돌리겠다는 뜻) 


		Ellipse(mBackHdc,
		300 + test.Player.x, 
			300 + test.Player.y, 
			400 + test.Player.x, 
			400 + test.Player.y); // 처음 원.  

		// ** 렌더에서는 도화지를 복사할 것 ** 
		// 초기화(이니셜라이즈)에서 백 버퍼를 만들고, HDC를 연결해준 다음
		// 여기에서는 원래 도화지에, 뉴 도화지를 복사해주는 역할을 한다. 
		
		BitBlt(mHdc, 0, 0, mWidth, mHeight 
			, mBackHdc, 0, 0, SRCCOPY);  
		// ** 비트비트 함수(mHDC, 앞에가 원래 도화지 // 뒤에가 백버퍼 도화지 )) 
		// 백버퍼 도화지의 시작 값부터 모든 영역 (SRCCOPY) 을 원래 도화지에 카피한다. 
		// **그리는 과정은 : 백도화지에서 이루어지므로, 렌더의 HDC는다른 HDC로 바뀌어야 함**


		// 원을 그릴것: main.cpp - WM_PAINT에 있던 그림 함수가 여기로.
		// 원을 main이 아니라 console에서 그릴 수 있게 됨.

		// **윈도우 좌표계**
		// 좌측 최상단 0,0
		// 아래로 내려가면 y축 ++ 
		// 오른쪽으로 가면 x축 ++ 
	}
}

