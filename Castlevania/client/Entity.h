#pragma once
#include "CommonInclude.h"
// ★모든 클래스가 엔티티를 상속하므로, 그들도 commoninclude 를 사용할 수 있게 된다. 

// ** Entity는, 조사식에서 모든 객체들이 이름을 가질 수 있도록 한다 ** //
// ** 최상위의 부모 클래스 ** // 

namespace game
{
	class Entity
	{
	public: 
		Entity(); // 생성자 
		virtual ~Entity(); // 소멸자
		// ㄴ 최상위 부모. 상속 쭉 내려줄거라 앞에 virtual 붙임
		// ㄴ 이녀석을 상속받은 자식들도 앞에 virtual이 붙는다. 

		void Setname (std::wstring& name) // 상속한 자식들의 이름 붙이는 역할 
		{
			mName = name; 
		}

		std::wstring& Getname() // Setname으로 세팅한 mName(프라이빗 변수)을 꺼내쓰는 용 
		{
			return mName; 
		}

	private:
		std::wstring mName; 
	};

}
