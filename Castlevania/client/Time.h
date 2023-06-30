#pragma once
#include "Commoninclude.h"

// 델타 타임: 프레임이 다른 컴터에서도 동일하게 이동할 수 있도록
// 보정해주는 시간 값

// 30 프레임 : 0.1x 30 바퀴 x 2 <- 이 2가,  보정해주는 델타 타임 
// 60 프레임 : 0.1x60 바퀴 

// ** 몬스터들, 플레이어 다 움직이므로 퍼블릭에 넣어줘야 함  (스테틱 변수, 스테텍 함수 선언ㅇ) 

// 사용법: 3개의 변수가 필요함 (private 참고) 

namespace game
{
	class Time
	{
	public:
		// 1. 초기화 함수
		// 2. 업데이트 함수 
		// 3. 렌더 함수 (인자 주의 HDC hdc) 

		// 4. 델타 타임을 계산해주는 함수 () { return mDeltaTime} // 인라인은 헤더에서만 구현 

	private: 
		LARGE_INTEGER mCPUFrequency;  
		//자료형: 시간은 16바이트, 그걸 담기 위한 자료형 (크기가 커서 8바이트 2개 합침)- 구조체임
		// 1.시간측정용 (cpu 고유 진동수를 담을 거임) 
		LARGE_INTEGER mPreFrequency;
		// 2.내 이전 진동수를 담는 변수 
		LARGE_INTEGER mCurFrequency;
		// 3.내 현재  진동수를 담는 변수 

		float mDelaTime; //  이거 다시 질문하기 
	};
}

