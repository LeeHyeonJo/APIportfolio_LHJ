#include "inputclass.h"

namespace game
{
	std::vector<Input::Key> Input::mKeys = {};   
	//<Input::key>�� (eKeycode code, eKeyState state, bool bpressed) �� {}�� �ʱ�ȭ 

	// �� �̰� ��ǲŬ���� ������Ͽ� �ִ� ������ �ʱ�ȭ�ϴ� ���̹Ƿ� 
	// key, mkeys�� �Ҽӵ� Ŭ������ �����־�� �Ѵ�. Input::key, Input::mkey �̷���. 
	// static ����(= ��������)�� �ݵ�� �ܺο��� �ʱ�ȭ�� ���ش�.  (= ���������ϱ� �������� �ʱ�ȭ) 

	// �ھƽ�Ű �迭�� ������ش�. (�̰� �����ؿ�) 
	// ��(int)�� ����ȯ, End �� �� ���� 26 �������. 

	int ASCII[(int)eKeycode::End] =  // (int) 26�̶�� �� 
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	void Input::Initailize() // Ű ���� �޾��� �迭�� �ʱ�ȭ ~~~ �ϴ� �Լ� 
	{
		// ����: for�� 26�� ���鼭 ���� Ű�� ���ȴ��� / Ű�� ���°� �������� / ���ȴ��� ���¸� üũ��. 
		// �� ��Ȯ���� ������ ���� ä�� �ʱ�ȭ����. 

		for (int i = 0; i < (int)eKeycode::End; i++)
		{
			Key key = {}; // ��26���� ��� Ű���� �迭�� ����� �ʱ�ȭ�ϴ���.. 
			key.code = (eKeycode)i; // ���ĺ�  
			key.state = eKeystate::None;  
			key.bpressed = false;  

			mKeys.push_back(key); // push_back() =  vector�� ���� ���� ���� �߰�. (������ ũ�� 1����)  
			//�� mKeys�� ��� ���� �־���. (A~z���� ��� Ű���尡 ������ ���� ä�� �ʱ�ȭ ��.) 
		}

	}

	void Input::Update() // ���� Ű ���� ~~���ȴ���~~ ���θ� üũ�ϱ� 
		// �� ���� �ȿ� ���� ���� �����غ���!! �� �� ������. 
		// �� �� ���Ⱑ ����Ʈ��. ���� ��, �ٿ�, ��������~ 
	{
		 // ������ 26�� ���鼭 (��Ű�� ���� üũ) 
		for (int i = 0; i < (int)eKeycode::End; i++)
		{
			// 1. �ش�Ű�� ���� ���� ����
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
				// ����Ƽ �Լ� ��  API���� �⺻ �����ϴ� �Լ� (�����͸� üũ�Ѵ�) ���
				// �� �������϶��� ���� ���ϰ����� üũ�ؼ� ����Ѵٴ� ���̴�. 
			{
				// 1-1. ���� �����ӿ����� �����־��ٸ� (mkey�� ���� �Է��� Ű�� ���¸� ����) 
				if (mKeys[i].bpressed == true)
				{
					mKeys[i].state = eKeystate::Pressed; // �������� �� ���� ���� 
				}
				else // 1-2. ���� �����ӿ��� �� �����־��ٸ�
				{
					mKeys[i].state = eKeystate::Down; 
				}

				// pressed�� üũ���־�� ��
				mKeys[i].bpressed == true;  
			}

			// 2. �ش�Ű�� ���� ������ �ʾҴ�.
			else
			{
				// 2-1. ���� �����ӿ��� �����־��ٸ� 
				if (mKeys[i].bpressed == true)
				{
					mKeys[i].state = eKeystate::Up; 
				}

				// 2-2. ���� �����ӿ��� �� �����־��ٸ�
				else
				{
					mKeys[i].state = eKeystate::None; 
				}

				// pressed�� üũ���־�� ��
				mKeys[i].bpressed == false;  
			}
			
		}
	}
}

