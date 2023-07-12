#include "Gameobject.h"
// 트랜스 헤더
// 스프라이트 헤더 

namespace game
{ 
	Gameobject::Gameobject()
	{
		mComponents.push_back(new Transform()); 
		// 1. 트랜스를 mComponents 배열에 넣어줌 
		// 생성자에서 객체 생성 후 컴포넌트 포인터 타입의 m컴포넌트 배열에 넣어줌
	

		mComponents.push_back(new Spriterenderer());
		// 2. 스프라이트 랜더러를 mComponents 배열에 넣어줌
		// 생성자에서 객체 생성 후 컴포넌트 포인터 타입의 m컴포넌트 배열에 넣어줌
	}
	// 레이어에서 호출한 Addgameobject에 의해서 여기로 넘어옴.
	// 게임 오브젝트는 컴포넌트 벡터 배열을 들고 있음. 
	// 게임 오브젝트는 엔티티를 상속. 
	// 컴포넌트 안에 들어갈 트랜스/렌더러가 컴포넌트를 상속함. 
	// * 컴포넌트는 겜.옵젝에 포함될 뿐, 상속받고있는게 아님을 주의. 

	Gameobject::~Gameobject()
	{
	}

	void Gameobject::Initialize()
	{
	}

	void Gameobject::Update()
	{
		// 여긴 업데이트 만들때 
	}

	void Gameobject::Render(HDC hdc)
	{
		// 여긴 렌더 만들때 
	}

}
