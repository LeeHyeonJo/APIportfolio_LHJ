#include "Time.h" // ���⼭ ���漱���� �Լ����� Time.cpp���� �����Ѵ�. 
// ����: ��ŸŸ�� ���Ϸ��� �� (��ŸŸ�� = �� ������ ���̿� �ɸ��� �ð�) 
// 30������(fps) : 1�ʿ� 30�� ���α׷��� ���Ҵ� => �� ��� ��ŸŸ���� 1/30��.  
// ����: �� �ð�(cur) - ���� �ð�(prev) / �� cpu�� ������ 

namespace game
{
	// 1. ����ƽ ������ �ܺο��� �ʱ�ȭ (��, Ǯ�������� �� ��) 
	// �̶� ���� �ڷ����� ����ü �̹Ƿ�, �ʱ�ȭ�� ���ڰ� �ƴ϶� {}�� ���־�� ��. 
	LARGE_INTEGER Time::mCPUFrequency = {}; // ����ü
	LARGE_INTEGER Time::mPreFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {}; 
	float Time::mDeltaTime = 0.0f; // �Ǽ��� �ʱ�ȭ�Ҷ� ���� ���� �ڿ� f�� ���δ�. �̰� 0(0.0)�ΰ���. 

	//**LARGE_INTEGER ��? & QuardPart��? 
	// ���������ս�ī����, ���������ս��������ð��� �Լ��� ����ϱ� ���ؼ� ũ�Ⱑ �� ū �������� �ʿ� (�ڼ��� �ð��� �����ϱ� ����) , 64��Ʈ ������ �����͸� �����ϱ� ���� ����� ����� ���� �ڷ���.
	// ����ü��. LOWpart & HIGHpart �� �ü���� 32��Ʈ�� ��� 64��Ʈ �������� ������ ����. 
	// QuardPart�� ����ü�� 64��Ʈ�� ��� ���⿡ ���忡�� �ѹ��� ���. (�� ���� 64��Ʈ �ü���� ���⿡ �ð��� ����)
	// ����: https://novemberfirst.tistory.com/36 

	// 2. �Լ� ����
	void Time::Initiailize() // a.�ʱ�ȭ �Լ� 
	{
		// 2-1.�� ��ǻ���� CPU ������ �������� �����´�. (�ּҰ��� ����)
		QueryPerformanceFrequency(&mCPUFrequency);

		// 2-2. ���α׷��� ���۵������� �������� �����´�. 
		// https://is03.tistory.com/91 ���� ���� ���� 
		QueryPerformanceCounter(&mPreFrequency);
		// �� ������ ī���͸� �˾Ƴ��µ� ����ϴ� �Լ� (�Ѱ��� �ּ�..�װ��� �������� ī����) 
	}

	void Time::Update() // b.���� ������Ʈ :: ���⼭ ��Ÿ���� ���Ѵ�. 
	{
		// 2-3. ������ �������� ���Ѵ�. 
		QueryPerformanceCounter(&mCurFrequency);

		//���� ������ - ���� �������� d.F�� ����
		float differenceFrequency
			= static_cast<float>(mCurFrequency.QuadPart - mPreFrequency.QuadPart); 
			//**C++ ��Ÿ���� ����ȯ: static_cast<��ȯ�� Ÿ��>(��ȯ�� ���) 
			//**static_cast: ���� ĳ����(��ȯ). ���� �����͸� ĳ�����Ѵ�. 
			//��LARGE_INTEGER �� 64��Ʈ �����ΰ� �׷�����. �׷��� float Ÿ�� ������ ����ȯ.   

		//�ڵ�ŸŸ�� 
		mDeltaTime = differenceFrequency / static_cast<float>(mCPUFrequency.QuadPart);  
		// <��Ÿ�� ���ϴ� ��: ������ ���� / ������ ���� ������> 
		// ������ �ڷ����� float�̹Ƿ� �и� ����ȯ�� ���� �� ������. 
		// https://maxlevel-trace.tistory.com/4  ���� 

		//�� prev �������� ������ ���������� �����Ѵ�. 
		mPreFrequency.QuadPart = mCurFrequency.QuadPart; 
	}

	void Time::Render(HDC hdc) // c. ���� (��Ÿ Ÿ���� �̿��� fps�� ���ϰ� ȭ�鿡 ǥ��) 
		// �迭�� ���� ä���ְ� ����. 
	{ // �ʹ� ���� �ʴ����� ����ֱ�� ��. 

		static float timeCheck = 0.0f; 
		timeCheck += mDeltaTime;

		if (timeCheck >= 1.0f)
		{
			wchar_t szFloat[50] = {}; // 1.FPs ���ڸ� ���� �迭�� ����� (fps���ڸ� �����Ұ���) 
			float fps = 1.0f / mDeltaTime;  // �ڵ�ŸŸ���� ���� = fps (���� ���ϴ� ��: 1/��ŸŸ��) 

			// ��2.swprintf_s �Լ��� szFloat�迭�� ���� �־��ش� 
			// (�迭�̸�,ũ��, ���� ��1, ���� ��2) �쿡�� �·� �д´� (fps�� "FPS : %f"�� ��. �װ���  szfloat��) 
			swprintf_s(szFloat, 50, L"FPS : %f", fps); // %f�� �Ǽ�, %d�� ���� 
			int strlen = wcsnlen_s(szFloat, 50); // 3. szFloat �ȿ� �ִ� ����� ���̸� ���Ѵ�. 

			// 3. ȭ�鿡 ���θ� ä�� szFloat�� ����. 
			TextOut(hdc, 10, 10, szFloat, strlen); // �迭�� ���̸�ŭ ����.  

			timeCheck = 0.0f; 
		}
	}
}
