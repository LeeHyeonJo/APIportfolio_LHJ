#pragma once
#include "CommonInclude.h"
// �ڸ�� Ŭ������ ��ƼƼ�� ����ϹǷ�, �׵鵵 commoninclude �� ����� �� �ְ� �ȴ�. 

// ** Entity��, ����Ŀ��� ��� ��ü���� �̸��� ���� �� �ֵ��� �Ѵ� ** //
// ** �ֻ����� �θ� Ŭ���� ** // 

namespace game
{
	class Entity
	{
	public: 
		Entity(); // ������ 
		virtual ~Entity(); // �Ҹ���
		// �� �ֻ��� �θ�. ��� �� �����ٰŶ� �տ� virtual ����
		// �� �̳༮�� ��ӹ��� �ڽĵ鵵 �տ� virtual�� �ٴ´�. 

		void Setname (std::wstring& name) // ����� �ڽĵ��� �̸� ���̴� ���� 
		{
			mName = name; 
		}

		std::wstring& Getname() // Setname���� ������ mName(�����̺� ����)�� �������� �� 
		{
			return mName; 
		}

	private:
		std::wstring mName; 
	};

}
