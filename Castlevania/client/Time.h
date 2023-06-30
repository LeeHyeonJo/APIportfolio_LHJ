#pragma once
#include "Commoninclude.h"
// 만드는 목적; CPU가 다른 컴퓨터에서도 게임이 동일한 성능으로 돌아가게 하기 위함. 
// 델타 타임을 이용해서, 시간 차를 계산해 움직이는 함수에 더해준다. 

// **델타 타임: 프레임이 다른 컴터에서도 동일하게 이동할 수 있도록 보정해주기 위해 사용함. 

// 30 프레임 : 0.1x 30 바퀴 x 2 <- 이 2가,  보정해주는 델타 타임 
// 60 프레임 : 0.1x60 바퀴 

// ** 몬스터들, 플레이어 다 움직이므로 퍼블릭에 넣어줘야 함  (스테틱 변수, 스테틱 함수 선언ㅇ) 

// 사용법: 3개의 변수가 필요함 (private 참고) 
// 1. cpu진동수, 2. 이전 진동수(prev), 3.현재 진동수(cur)

namespace game
{
	class Time
	{
	public:
		// 1. 초기화 함수 (헤더에 전방선언) 
		static void Initiailize(); 
		// 2. 업데이트 함수(네임 스페이스 덕에 각각 다른 역할임) 
		static void Update(); 
		// 3. 렌더 함수 (인자 주의, 그려주는 함수이므로 핸들이 필요함)  
		static void Render(HDC hdc); 

		// 4. 델타 타임을 불러오는 함수 (private에 있으니까, 쉽게 쓸 수 있도록 퍼블릭 함수로) 
		__forceinline  static float Deltatime()
		{
			return mDeltaTime;  // 인라인 역할; Deltatime을 부른 곳에 return mDeltatime을 그대로 복붙 (속도향상)
		}
		

	private: 
		static LARGE_INTEGER mCPUFrequency;  
		//자료형: 시간은 16바이트, 그걸 담기 위한 자료형 (크기가 커서 8바이트 2개 합침)- 구조체임
		// 1.시간측정용 (cpu 고유 진동수를 담을 거임) 
		static LARGE_INTEGER mPreFrequency;
		// 2.내 이전 진동수를 담는 변수 
		static LARGE_INTEGER mCurFrequency;
		// 3.내 현재 진동수를 담는 변수 

		static float mDeltaTime; //  델타 타임을 저장할 변수 
	};
}

