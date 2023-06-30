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

		void Initialize(HWND mHwnd); // �ʱ�ȭ
		void Run(); // ���α׷� ����
		void Update(); // ������Ʈ 
		void Render(); // ���ҽ�(�׸�) ����� 

		// **11�� ����~17�� ���� ����� 
		// **��Ŭ�� => ���� �۾�/�����丵 => ����/���Ǹ����
		// **���� ���� �Լ����� cpp ���Ϸ� ������. (�����Ⱑ) 
		// �� �� �� cpp���� namespace�� �����ϰ� �������� ��. 

	private: // ������ private�� ����. 
		// **�ڵ��� �����Ұ���
		HWND mHwnd; // �ڷ��� �� ��ü�� ������ Ŭ���� (typedef void* ptr ���� �� ptr �ڷ��� ���� ��) 
		HDC mHdc; // ��, H���� ���� ���� ������ ������� �����ϸ� ��. 

		Vector2 mPlayerPos; // �÷��̾��� ��ġ�� �޾���. 
		// consolemath ���� vecter2 Ŭ������ ������. �װ��� ��ü�� ���. 
		// ��밡���� ����: consolemath.h�� �ʿ�. �ٵ� ��� ����� ��Ƶ� commoninclude.h����
		// consolemath.h �� ������. �׷��Ƿ� commonincluse.h�� �־��� ��. 
	};
}

