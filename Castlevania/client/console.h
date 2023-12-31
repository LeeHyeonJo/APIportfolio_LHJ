#pragma once
#include "Commoninclude.h"
// 게임 엔진의 전반적인 작업을 하는 역할 
/// 마찬가지로 헤더/함수를 여기에 모아두고, 본격적인 구현은 console.cpp에서 진행. 

namespace game
{
	using namespace math;  
	// 콘솔>수학>클래스:어플리케이션 ~ 이렇게 들어있는 것. 
	class Application
	{
	public: // 함수는 여기에 
		Application(); // 생성자 
		~Application(); // 소멸자 

		void Initialize(HWND mHwnd); // 초기화
		void Run(); // 프로그램 실행
		void Update(); // 업데이트 
		void Render(); // 리소스(그림) 띄워줌 

		// **11번 라인~17번 라인 블럭잡기 
		// **우클릭 => 빠른 작업/리팩토링 => 선언/정의만들기
		// **내가 잡은 함수들이 cpp 파일로 구현됨. (껍데기가) 
		// ㄴ 그 후 cpp에서 namespace로 간략하게 정리해준 것. 

	private: 
		// 변수는 private에 저장. 
		// **핸들을 저장할거임
		HWND mHwnd; // 자료형 이 자체가 포인터 클래스 (typedef void* ptr 선언 후 ptr 자료형 쓰면 됨) 
		HDC mHdc; // 즉, H지가 들어가면 전부 포인터 변수라고 생각하면 됨. 

		Vector2 player;
		// 플레이어의 위치(y,x)를 받아줌. 
		// consolemath 에서 vecter2 클래스로 선언함. 그것의 객체를 사용. 
		// 사용가능한 이유: consolemath.h가 필요. 근데 모든 헤더를 모아둔 commoninclude.h에도
		// consolemath.h 가 존재함. 그러므로 commonincluse.h를 넣어준 것. 

		// ** 여기에 직사각형 크기 저장할 변수. (네모 하나, 화면 크기만큼 그릴거임) 
		// (** ㄱ콘솔 생성자에서 0으로 생성, 초기화에서 크기 지정. 


		// 잔상을 지워볼 것: 원리는 원이 그려진 후, 그 위를 큰 네모로 덧씌우기. 
		// 네모가 그려질 크기를 저장할 변수를 넣어줌. 

		UINT mWidth;  // unit = unsigned int (양의 정수) 
		UINT mHeight;  

		// ** 알고리즘: 더블 버퍼링 .. 을 따라한 과정 // 
		// 선행: 클라이언트 영역을 할당한 크기만큼 윈도우 창 띄워준다. 그것을 복사. 
		// 두번째 화면 생성에 사용할 변수 선언 

		HBITMAP mBackBuffer; // 두번째 도화지(화면)용
		// ㄴ 24바이트 짜리 RGB만 들어있음. 
		HDC mBackHdc; 
		// ㄴ 두번째 도화지용 hdc가 하나 더 필요함. (윈도우 APPI 권장사항) 
	}; 
}

