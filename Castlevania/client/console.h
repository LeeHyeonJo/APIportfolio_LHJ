#pragma once
#include "Commoninclude.h"
using namespace math; 

// 게임 엔진의 전반적인 작업을 하는 역할 

namespace console
{
	class Application
	{
	public:
		Application(); // 생성자 
		~Application(); // 소멸자 

		void Initialize(HWND mHwnd); // 초기화  // **질문하기 
		void Run(); // 실행
		void Update(); // 업데이트 
		void Render(); // 리소스(그림) 띄워줌 

		// **11번 라인~17번 라인 블럭잡기 
		// **우클릭 => 빠른 작업/리팩토링 => 선언/정의만들기
		// **내가 잡은 함수들이 cpp 파일로 구현됨. (껍데기가) 

	private:
		// 변수가 private 에 선언되어있음. 
		// 핸들을 저장할거임
		HWND mHwnd; // 자료형 이 자체가 포인터 클래스 (typedef void* ptr 선언 후 ptr 자료형 쓰면 됨) 
		HDC mHdc; // 즉, H지가 들어가면 전부 포인터 변수라고 생각하면 됨. (질문하기 안되는 이유를) 

		Vector2 mPlayerPos; 
	};
}

