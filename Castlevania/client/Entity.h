#pragma once
#include "CommonInclude.h"

// ** Entity��, ����Ŀ��� ��� ��ü���� �̸��� ���� �� �ֵ��� �Ѵ� ** //
// ** �ֻ����� �θ� Ŭ���� ** // 

namespace game
{
	class Entity
	{
	public: 
		Entity(); // ������ 
		virtual ~Entity(); // �Ҹ���
		// �� �ֻ��� �θ�. ����� �����ٰŶ� �տ� virtual ����
		// �� �̳༮�� ��ӹ��� �ڽĵ鵵 �տ� virtual�� �ٴ´�. 

		void SetNmae (std::wstring& name) // �̸� ���̴� ���� 
		{
			mName = name; 
		}

		std::wstring& Getname() // �����̺� ������ �������� �� 
		{
			return mName; 
		}

	private:
		std::wstring mName; 
	};

}
