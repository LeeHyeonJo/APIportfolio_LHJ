// 이 파일의 역할:: 라이브러리에 구현된 자료구조들을 가져와서 사용할거임. 
// 그리고 프로그램(console)에 필요한 헤더들을 한 곳에 모아두었다.

#pragma once // 겹치는 헤더가 여러개 있어도 하나만 가져와서 사용할 수 있게 해주는 역할 
#include <vector> // 배열 라이브러리 (동적 배열) 
#include <list> // 링크드 리스트 라이브러리 
#include <map> // 트리 구조 
#include <set> // 해시 테이블 구조 
#include <functional> // 함수 포인터도 객체로 저장해서 쉽게 사용할 수 있음. 
#include <string>

// 윈도우 - 헤더에 있던 헤더를 common  으로 보내주는건가? 확인해보기 
#include "framework.h"

// 수학 관련 기능 (- 벡터만 구현된 상태 - ) : 원의 위치를 받아주는 것 
// 선언은 여기서 하고, 구현은 consoleMath.h에서 해두는 것. 
#include "consoleMath.h" 
#include "Time.h"


namespace game::enums 
{
	enum class eLayer
	{
			// 배경
			// 배경
			// 배경
			// 등ㄷㅇ.. 

	};

	// 두번째 이넘 클래스 
	// 컴퍼넌트 용
	// 이거 순서는 유니티 라이프 사이클을 따라감. 
}

// class 전방선언: 포인터 타입만 정의해줌. 
// 다이나믹케스팅: 부모자식간의 형변환. 
// 겟 컴포넌스: >> T에 찾으려는 타입. c는 부모 타입. 
// 일치하면 반환, 안 일치하면 NULL반환. \\// 트랜스에선 위치가 바뀌고, 렌더레어서 트랜스만 가져옴. 