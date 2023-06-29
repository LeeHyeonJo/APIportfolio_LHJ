#pragma once
#include "Commoninclude.h" // 벡터 쓸려고 

// ** 키보드 입력!! 을 여기에 클래스로 모아둘거임 ** 

// 헤더 
namespace Input 
{
	enum class eKeycode // enum을 쓰는 이유: 코드에서 숫자를 대응하는 문자로 바꾸기 위해 
	{
		// 여기에는 알파벳이 들어감. 
		// 키보드의 키들 
	};

	// 입력되는 키의 상태 
	enum class eKeyState // enum = 괄호 안에 입력된 글자를 숫자로 바꿔주는 것. 
	{
		Down, // enum 0 : 이전 프레임이 안 눌러있었으나, 지금은 누른 상태 
		// 업 // enum 1.. : 이전 프레임은 눌려있었으나, 지금은 뗀 상태 
		// 프레스트 : 에전 프레임부터 꾹 누르고 있는 상태 
		// 논 : 이전 프레임도, 현재 프레임도 눌리지 않은 상태
	};

	////이넘 문의 단점: 
	//// 내부 내용이 같으면 중복 취급이 된다 

	//// 클래스로 사용하면 이덤::클래스 이름 다운이 되므로 겹치지 않게 된다. 
	//enum ekeysyaye
	//{
	//	down, // 0 
	//	// 업 // 1.. 
	//	// 프레스트 
	//	// 논
	//};

	//enum ekeysyaye2
	//{
	//	down, // 0 
	//	// 업 // 1.. 
	//	// 프레스트 
	//	// 논
	//};

	class Input
	{
	public:
		struct key
		{
			eKeycode code; // 입력되는 키 값이 무엇인지 
			eKeyState state; // 입력되는 키 값의 상태 (업,다운,프레스드,논) 
			bool bpressed; // 눌려있는지 여부  
		};

		static void Initailize(); // 이것도 초기화 
		static void Update(); // 상태 업데이트 

		// 입력한 키 값이 다운인지, 업인지, 프레스드인지 트루 펄스로 체크 
		// static: 객체를 안 만들어도 사용가능하게 해줌. 즉, 전역 함수 취급임. 
		inline static bool GetKeyDown(eKeycode code) {}; // 입력한 키가, 엠키 배열에 입력된 값과 동일한지 체크 
		inline static bool GetKeyUp(eKeycode code);
		inline static bool GetKey(eKeycode code);

		// 인라인의 기능; 원래 함수의 리턴값을, 그 다음 함수로 보내야 하는데. 
		// 그 과정을 생략하고 싶을 때. A 함수의 인자를 B함수에 그대로 복붙해서 좀 더 속도를 높일 수 있다. 
		// inline을 붙여도 적합여부는 컴파일럭다 판단한다. 

		// ** 반드시 인라인을 시키고 싶은 경우는 " 포스드 인라인 " 문법을 사용하면 된다. 
		// _forceinline: 이렇게. 

	private: // 변수 
		static int g; // 정적변수 
		static std::vector<key> mkeys; // 인클루드 헤더로 삽입. 매스에 함수한 벡터를 가져옴. 
		// 엠 키에는 eKeycode code, eKeyState state, bool bpressed이 저장됨. 
		// 이걸 인풋 cpp에서 구현 
	};
}



