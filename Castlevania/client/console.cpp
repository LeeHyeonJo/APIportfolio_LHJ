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
		, mHdc(NULL) // 핸들에 처음 널값을 넣어둠 (초기화) 
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

		// 와이드 = 1800
		// 헤이트 = 900

		// **상태창 빼고 띄우기 위한 함수. 
		// 리엑트 
		// 어드저스트윈도우리엑트(함수)
		// 셋 윈도우포스(함수)
		// 쇼윈도우(함수)

		// 도화지 (엠버퍼) = 윈도우 API 기본 함수( 화면 만들어주는 것: 필요인자가 기본윈도우의 인자들 ); 
		// 도화지를 위한 mBackHdc = 윈도우 API 기본 함수(mHDC) 넣고 뱉게 함. 
		//ㄴ * 기존 HDC 쓸 수 있는 거 아닌가? :: 그냥 .. 권장사항이 그럴 뿐 

		// >> 새 비트맵에 새 HDC를 연결해주어야 한다. 
		// 연결해주는 함수 (새 HDC, 새 도화지); 

		// 딜리트는 뭐지? 

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
		
		newcircle1::direct(); // 방향 됐다. 

		// 원이 움직이는 방향 
		//mPlayerPos.y -= 300.0f * Time::Deltatime(); // w 위
		//mPlayerPos.x -= 300.0f * Time::Deltatime(); // a 왼
		//mPlayerPos.y += 300.0f * Time::Deltatime(); // s 아래
		//mPlayerPos.x += 300.0f * Time::Deltatime();  // d 우
	}

	void Application::Render() // 증가한 상태를 "그림"  & 화면에 띄워주는 함수 
	{
		Time::Render(mHdc); // ~여기서 fps 띄워주기   

		// ** 잔상 지우기 ** // 
		// = 흰 이미지를 덮어씌운다. 동그라미 크기만큼의 직사각형을 그려서 덮어씌운다. 

		Rectangle(mHdx, -1, -1, mWidth + 1, mHeight + 1); 
		// 변수는 따로 이 헤더에서 저장할거고, -1, +1은 화면 크기보다 더 크게 그려지라고 
		// 일부러 숫자 줄이고 늘려준 것 

		// 문제: 원 그리고, 직사각형 덧그려지고 반복되기 때문에 깜빡임이 생긴다. 


		// 해결방식: 알고리즘 = 더블 버퍼링 (교대로 화면이 계속 스왑된다는 뜻) 
		// >> api에선 이 알고리즘을 제공하지 ㅇ낳으므로, 비슷하게나마 구현해야 한다. 
		// 백 버퍼에 그림을 그리고, 원본에 복사. (눈은 원래도화지에 고정) 
		// ㄴ 이 과정을 반복. ( = 깜빡임 제거 용) 
		// 원리: 화면을 2개 사용 (만화경 프레임처럼 돌리겠다는 뜻) 


		Ellipse(mHdc,
			0 + test.Player.x, 
			0 + test.Player.y, 
			100 + test.Player.x, 
			100 + test.Player.y); // 처음 원.  


		// 업데이트에서 백 버퍼를 만들고, HDC를 연결해준 다음
		// 여기에서는 원래 도화지에, 뉴 도화지를 복사해주는 역할을 한다. 
		// ** 비트비트(mHDC, 앞에가 원래 도화지 // 뒤에가 백버퍼 도화지 )) 

		// ㄴ 그리는 과정은 : 백도화지에서 이루어지므로, 렌더의 HDC는다른 HDC로 바뀌어야 함. 


		// 원을 그릴것: main.cpp - WM_PAINT에 있던 그림 함수가 여기로.
		// 원을 main이 아니라 console에서 그릴 수 있게 됨.

		// **윈도우 좌표계**
		// 좌측 최상단 0,0
		// 아래로 내려가면 y축 ++ 
		// 오른쪽으로 가면 x축 ++ 
	}
}

