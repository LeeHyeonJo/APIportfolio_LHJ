#pragma once
#include "Commoninclude.h"
// ����� ����; CPU�� �ٸ� ��ǻ�Ϳ����� ������ ������ �������� ���ư��� �ϱ� ����. 
// ��Ÿ Ÿ���� �̿��ؼ�, �ð� ���� ����� �����̴� �Լ��� �����ش�. 

// **��Ÿ Ÿ��: �������� �ٸ� ���Ϳ����� �����ϰ� �̵��� �� �ֵ��� �������ֱ� ���� �����. 

// 30 ������ : 0.1x 30 ���� x 2 <- �� 2��,  �������ִ� ��Ÿ Ÿ�� 
// 60 ������ : 0.1x60 ���� 

// ** ���͵�, �÷��̾� �� �����̹Ƿ� �ۺ��� �־���� ��  (����ƽ ����, ����ƽ �Լ� ����) 

// ����: 3���� ������ �ʿ��� (private ����) 
// 1. cpu������, 2. ���� ������(prev), 3.���� ������(cur)

namespace game
{
	class Time
	{
	public:
		// 1. �ʱ�ȭ �Լ� (����� ���漱��) 
		static void Initiailize(); 
		// 2. ������Ʈ �Լ�(���� �����̽� ���� ���� �ٸ� ������) 
		static void Update(); 
		// 3. ���� �Լ� (���� ����, �׷��ִ� �Լ��̹Ƿ� �ڵ��� �ʿ���)  
		static void Render(HDC hdc); 

		// 4. ��Ÿ Ÿ���� �ҷ����� �Լ� (private�� �����ϱ�, ���� �� �� �ֵ��� �ۺ� �Լ���) 
		__forceinline  static float Deltatime()
		{
			return mDeltaTime;  // �ζ��� ����; Deltatime�� �θ� ���� return mDeltatime�� �״�� ���� (�ӵ����)
		}
		

	private: 
		static LARGE_INTEGER mCPUFrequency;  
		//�ڷ���: �ð��� 16����Ʈ, �װ� ��� ���� �ڷ��� (ũ�Ⱑ Ŀ�� 8����Ʈ 2�� ��ħ)- ����ü��
		// 1.�ð������� (cpu ���� �������� ���� ����) 
		static LARGE_INTEGER mPreFrequency;
		// 2.�� ���� �������� ��� ���� 
		static LARGE_INTEGER mCurFrequency;
		// 3.�� ���� �������� ��� ���� 

		static float mDeltaTime; //  ��Ÿ Ÿ���� ������ ���� 
	};
}

