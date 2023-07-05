#pragma once
namespace game
{
	// 목적: 
	class Entity // 씬을 상속바을것. 
	{
	public:
		Entity(); // 생성자 
		virtual ~Entity();  // 소멸자 (상속받으므로 앞에 가상함수 - 안붙여주면 부모것만 지워짐) 

		// 이름 셍팅 
		void SetName(// v프라이빗 인자) {}; 
		// 여기 이해 안감 

	private:
		std::wstring nName;
	
	};


}

