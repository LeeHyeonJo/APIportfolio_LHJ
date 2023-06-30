#include "inputclass.h"

namespace game
{
	std::vector<Input::Key> Input::mKeys = {};   
	//<Input::key>가 (eKeycode code, eKeyState state, bool bpressed) 라서 {}로 초기화 

	// ★ 이건 인풋클래스 헤더파일에 있던 변수를 초기화하는 것이므로 
	// key, mkeys가 소속된 클래스를 밝혀주어야 한다. Input::key, Input::mkey 이렇게. 
	// static 변수(= 전역변수)는 반드시 외부에서 초기화를 해준다.  (= 전역변수니까 전역에서 초기화) 

	// ★아스키 배열을 만들어준다. (이건 복붙해옴) 
	// ★(int)로 형변환, End 는 걍 숫자 26 만들려고. 

	int ASCII[(int)eKeycode::End] =  // (int) 26이라는 뜻 
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initailize() // 키 값을 받아줄 배열을 초기화 ~~~ 하는 함수 
	{
		// 원리: for문 26번 돌면서 무슨 키가 눌렸는지 / 키의 상태가 무엇인지 / 눌렸는지 상태를 체크함. 
		// ㄴ 정확히는 눌리지 않은 채로 초기화해줌. 

		for (int i = 0; i < (int)eKeycode::End; i++)
		{
			Key key = {}; // ☆26개의 모든 키보드 배열을 만들고 초기화하는중.. 
			key.code = (eKeycode)i; // 알파벳  
			key.state = eKeystate::None;  
			key.bpressed = false;  

			mKeys.push_back(key); // push_back() =  vector의 제일 끝에 값을 추가. (벡터의 크기 1증가)  
			//ㄴ mKeys에 모든 값을 넣어줌. (A~z까지 모든 키보드가 눌리지 않은 채로 초기화 됨.) 
		}

	}

	void Input::Update() // 눌린 키 값이 ~~눌렸는지~~ 여부를 체크하기 
		// ★ 여기 안에 조건 직접 구현해보기!! 할 수 있을듯. 
		// ★ ★ 여기가 포인트임. 언제 업, 다운, 프레스드~ 
	{
		 // 포문을 26번 돌면서 (엠키의 상태 체크) 
		for (int i = 0; i < (int)eKeycode::End; i++)
		{
			// 1. 해당키가 현재 눌린 상태
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				// 유니티 함수 ★  API에서 기본 제공하는 함수 (누른것만 체크한다) 사용
				// ㄴ 눌린거일때의 값만 리턴값으로 체크해서 사용한다는 것이다. 
			{
				// 1-1. 이전 프레임에서도 눌려있었다면 (mkey는 내가 입력한 키의 상태를 저장) 
				if (mKeys[i].bpressed == true)
				{
					mKeys[i].state = eKeystate::Pressed; // 예전부터 꾹 눌린 상태 
				}
				else // 1-2. 이전 프레임에서 안 눌려있었다면
				{
					mKeys[i].state = eKeystate::Down; 
				}

				// pressed도 체크해주어야 함
				mKeys[i].bpressed == true;  
			}

			// 2. 해당키가 현재 눌리지 않았다.
			else
			{
				// 2-1. 이전 프레임에서 눌려있었다면 
				if (mKeys[i].bpressed == true)
				{
					mKeys[i].state = eKeystate::Up; 
				}

				// 2-2. 이전 프레임에서 안 눌려있었다면
				else
				{
					mKeys[i].state = eKeystate::None; 
				}

				// pressed도 체크해주어야 함
				mKeys[i].bpressed == false;  
			}
			
		}
	}
}

