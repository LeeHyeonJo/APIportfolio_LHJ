#include "Time.h" // 여기서 전방선언한 함수들을 Time.cpp에서 구현한다. 
// 목적: 델타타임 구하려는 것 (델타타임 = 각 프레임 사이에 걸리는 시간) 
// 30프레임(fps) : 1초에 30번 프로그램이 돌았다 => 이 경우 델타타임은 1/30초.  
// 원리: 현 시간(cur) - 이전 시간(prev) / 현 cpu의 진동수 

namespace game
{
	// 1. 스테틱 변수는 외부에서 초기화 (단, 풀네임으로 쓸 것) 
	// 이때 쓰인 자료형은 구조체 이므로, 초기화는 숫자가 아니라 {}로 해주어야 함. 
	LARGE_INTEGER Time::mCPUFrequency = {}; // 구조체
	LARGE_INTEGER Time::mPreFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {}; 
	float Time::mDeltaTime = 0.0f; // 실수를 초기화할땐 원래 숫자 뒤에 f를 붙인다. 이건 0(0.0)인거임. 

	//**LARGE_INTEGER 란? & QuardPart란? 
	// 쿼리퍼포먼스카운터, 쿼리퍼포먼스프리퀀시같은 함수를 사용하기 위해선 크기가 더 큰 정수형이 필요 (자세한 시간을 저장하기 위해) , 64비트 정수형 데이터를 저장하기 위해 선언된 사용자 정의 자료형.
	// 구조체임. LOWpart & HIGHpart 는 운영체제가 32비트인 경우 64비트 측정값을 나눠서 저장. 
	// QuardPart는 구조체가 64비트인 경우 여기에 저장에서 한번에 사용. (내 컴은 64비트 운영체제라서 여기에 시간을 저장)
	// 참고: https://novemberfirst.tistory.com/36 

	// 2. 함수 구현
	void Time::Initiailize() // a.초기화 함수 
	{
		// 2-1.현 컴퓨터의 CPU 고유의 진동수를 가져온다. (주소값을 받음)
		QueryPerformanceFrequency(&mCPUFrequency);

		// 2-2. 프로그램이 시작됐을때의 진동수를 가져온다. 
		// https://is03.tistory.com/91 설명 조금 참고 
		QueryPerformanceCounter(&mPreFrequency);
		// ㄴ 현재의 카운터를 알아내는데 사용하는 함수 (넘겨준 주소..그것의 진동수를 카운팅) 
	}

	void Time::Update() // b.상태 업데이트 :: 여기서 델타값을 구한다. 
	{
		// 2-3. 현재의 진동수를 구한다. 
		QueryPerformanceCounter(&mCurFrequency);

		//★현 진동수 - 이전 진동수를 d.F에 저장
		float differenceFrequency
			= static_cast<float>(mCurFrequency.QuadPart - mPreFrequency.QuadPart); 
			//**C++ 스타일의 형변환: static_cast<변환할 타입>(변환할 대상) 
			//**static_cast: 정적 캐스팅(변환). 값과 포인터를 캐스팅한다. 
			//ㄴLARGE_INTEGER 이 64비트 정수인가 그럴거임. 그래서 float 타입 정수로 형변환.   

		//★델타타임 
		mDeltaTime = differenceFrequency / static_cast<float>(mCPUFrequency.QuadPart);  
		// <델타값 구하는 법: 진동수 차이 / 씨피유 고유 진동수> 
		// 분자의 자료형이 float이므로 분모도 형변환을 해준 후 나눈다. 
		// https://maxlevel-trace.tistory.com/4  참고 

		//★ prev 진동값을 현재의 진동값으로 갱신한다. 
		mPreFrequency.QuadPart = mCurFrequency.QuadPart; 
	}

	void Time::Render(HDC hdc) // c. 렌더 (델타 타임을 이용해 fps를 구하고 화면에 표시) 
		// 배열에 값을 채워주고 띄운다. 
	{ // 너무 빨라서 초단위로 띄워주기로 함. 

		static float timeCheck = 0.0f; 
		timeCheck += mDeltaTime;

		if (timeCheck >= 1.0f)
		{
			wchar_t szFloat[50] = {}; // 1.FPs 숫자를 담을 배열을 만든다 (fps숫자를 저장할거임) 
			float fps = 1.0f / mDeltaTime;  // ★델타타임의 역수 = fps (역수 구하는 법: 1/델타타임) 

			// ★2.swprintf_s 함수는 szFloat배열에 값을 넣어준다 
			// (배열이름,크기, 넣을 값1, 넣을 값2) 우에서 좌로 읽는다 (fps가 "FPS : %f"로 들어감. 그것이  szfloat로) 
			swprintf_s(szFloat, 50, L"FPS : %f", fps); // %f는 실수, %d는 정수 
			int strlen = wcsnlen_s(szFloat, 50); // 3. szFloat 안에 있는 요소의 길이를 구한다. 

			// 3. 화면에 내부를 채운 szFloat를 띄운다. 
			TextOut(hdc, 10, 10, szFloat, strlen); // 배열을 길이만큼 띄운다.  

			timeCheck = 0.0f; 
		}
	}
}
