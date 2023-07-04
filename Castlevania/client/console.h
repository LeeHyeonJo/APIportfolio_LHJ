#pragma once
#include "Commoninclude.h"
// ���� ������ �������� �۾��� �ϴ� ���� 
/// ���������� ���/�Լ��� ���⿡ ��Ƶΰ�, �������� ������ console.cpp���� ����. 

namespace game
{
	using namespace math;  
	// �ܼ�>����>Ŭ����:���ø����̼� ~ �̷��� ����ִ� ��. 
	class Application
	{
	public: // �Լ��� ���⿡ 
		Application(); // ������ 
		~Application(); // �Ҹ��� 

		void Initialize(HWND mHwnd, POINT resolution); // �ʱ�ȭ
		void Run(); // ���α׷� ����
		void Update(); // ������Ʈ 
		void Render(); // ���ҽ�(�׸�) ����� 

		// **11�� ����~17�� ���� ����� 
		// **��Ŭ�� => ���� �۾�/�����丵 => ����/���Ǹ����
		// **���� ���� �Լ����� cpp ���Ϸ� ������. (�����Ⱑ) 
		// �� �� �� cpp���� namespace�� �����ϰ� �������� ��. 

	private: 
		// ������ private�� ����. 
		// **�ڵ��� �����Ұ���
		HWND mHwnd; // �ڷ��� �� ��ü�� ������ Ŭ���� (typedef void* ptr ���� �� ptr �ڷ��� ���� ��) 
		HDC mHdc; // ��, H���� ���� ���� ������ ������� �����ϸ� ��. 

		Vector2 player;
		// �÷��̾��� ��ġ(y,x)�� �޾���. 
		// consolemath ���� vecter2 Ŭ������ ������. �װ��� ��ü�� ���. 
		// ��밡���� ����: consolemath.h�� �ʿ�. �ٵ� ��� ����� ��Ƶ� commoninclude.h����
		// consolemath.h �� ������. �׷��Ƿ� commonincluse.h�� �־��� ��. 

		static float circletime; // �� ����� ���� 
		struct resolution // �������� ���ο� ũ�� 
		{
			float x;
			float y;
		};
	}; 
}

