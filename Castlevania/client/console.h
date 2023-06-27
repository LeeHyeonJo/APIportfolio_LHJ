#pragma once
#include "Commoninclude.h"
using namespace math; 

// ���� ������ �������� �۾��� �ϴ� ���� 

namespace console
{
	class Application
	{
	public:
		Application(); // ������ 
		~Application(); // �Ҹ��� 

		void Initialize(HWND mHwnd); // �ʱ�ȭ  // **�����ϱ� 
		void Run(); // ����
		void Update(); // ������Ʈ 
		void Render(); // ���ҽ�(�׸�) ����� 

		// **11�� ����~17�� ���� ����� 
		// **��Ŭ�� => ���� �۾�/�����丵 => ����/���Ǹ����
		// **���� ���� �Լ����� cpp ���Ϸ� ������. (�����Ⱑ) 

	private:
		// ������ private �� ����Ǿ�����. 
		// �ڵ��� �����Ұ���
		HWND mHwnd; // �ڷ��� �� ��ü�� ������ Ŭ���� (typedef void* ptr ���� �� ptr �ڷ��� ���� ��) 
		HDC mHdc; // ��, H���� ���� ���� ������ ������� �����ϸ� ��. (�����ϱ� �ȵǴ� ������) 

		Vector2 mPlayerPos; 
	};
}

