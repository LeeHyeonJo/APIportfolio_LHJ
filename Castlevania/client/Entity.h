#pragma once
namespace game
{
	// ����: 
	class Entity // ���� ��ӹ�����. 
	{
	public:
		Entity(); // ������ 
		virtual ~Entity();  // �Ҹ��� (��ӹ����Ƿ� �տ� �����Լ� - �Ⱥٿ��ָ� �θ�͸� ������) 

		// �̸� ���� 
		void SetName(// v�����̺� ����) {}; 
		// ���� ���� �Ȱ� 

	private:
		std::wstring nName;
	
	};


}

