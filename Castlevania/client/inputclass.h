#pragma once
#include "Commoninclude.h" // ���� ������~ 

// ** Ű���� �Է�!! �� ���⿡ Ŭ������ ��ƵѰ��� ** // 
// �̰� for���� ���鼭 �Է´����, �ȵƴ��� üũ�ϴ°� ����Ʈ. 

// ��� 
namespace game
{  // 0. Ű���� ���� 
	enum class eKeycode // enum�� ���� ����: �ڵ忡�� ���ڸ� �����ϴ� ���ڷ� �ٲٱ� ���� (�Ź� 'A' �̷��� ���� ����) 
	{ 
		Q, W, E, R, T, Y, U, I, O, P, // Ű���� ���ĺ��� ���� 
		A, S, D, F, G, H, J, K, L, 
		Z, X, C, V, B, N, M, 
		End,  // End = 26 
	};

	// ���ԷµǴ� Ű�� ���� 
	enum class eKeystate // enum = ��ȣ �ȿ� �Էµ� ���ڸ� ���ڷ� �ٲ��ִ� ��. 
	{
		Down, // enum 0 : ���� �������� �� �����־�����, ������ ���� ���� 
		Up, // �� // enum 1.. : ���� �������� �����־�����, ������ �� ���� 
		Pressed, // ������Ʈ : ���� �����Ӻ��� �� ������ �ִ� ���� 
		None, // �� : ���� �����ӵ�, ���� �����ӵ� ������ ���� ����
	};

	//// ** enum ���� ����:(�ܵ� ����)  
	//// ���� ����{}�� ������ �ߺ� ����� �ȴ�
	// ** ���� 
	//enum ekeysyaye
	//{
	//	down, // 0 
	//	// �� // 1.. 
	//	// ������Ʈ 
	//	// ��
	//};

	//enum ekeysyaye2
	//{
	//	down, // 0 
	//	// �� // 1.. 
	//	// ������Ʈ 
	//	// ��
	//};

	//// enum class �� ����ϸ� enum::(Ŭ���� �̸�) Down�� �ǹǷ� ��ġ�� �ʰ� �ȴ�. 
	//�׷��� ��ġ�� �һ�縦 �����ϱ� ���� enum class�� ����� ���̴�. 

	// 1. �ԷµǴ� Ű���� ���� �ޱ� 
	class Input
	{
	public:
		struct Key 
		{
			eKeycode code; // �ԷµǴ� Ű ���� �������� (ABCDE..), 1 2 3 4 ���ڷ� �����  
			eKeystate state; // �ԷµǴ� Ű ���� ���� (��,�ٿ�,��������,��) 
			bool bpressed; // �����ִ��� ����  
		};

		static void Initailize(); // Ű�� ���� �ʱ�ȭ  
		static void Update(); // Ű�� ���� ������Ʈ 

		// ������ �Լ����� �Է��� Ű ���� �ٿ�����, ������, �������������� Ʈ�� �޽��� üũ 
		// **static: ��ü�� �� ���� ��밡���ϰ� ����. ��, ���� �Լ� �����. 

		// && �� �κ� ���� ���ư��°� ���� // 
		__forceinline static bool GetKeyDown(eKeycode code) // �Է��� Ű��, mkey �迭�� �Էµ� ���� �������� üũ 
		{
			return mKeys[(int)code].state == eKeystate::Down;  // ���װ� �Էµ�  �ڵ��� state�� ���Ͻ� true ����
		} 
		__forceinline static bool GetKeyUp(eKeycode code)
		{
			return mKeys[(int)code].state == eKeystate::Up; 
		}
		__forceinline static bool GetKey(eKeycode code) 
		{
			return mKeys[(int)code].state == eKeystate::Pressed;   
		}

		// �ζ����� ���; ���� �Լ��� ���ϰ���, �� ���� �Լ��� ������ �ϴµ�. 
		// �� ������ �����ϰ� ���� ��. A �Լ��� ���ڸ� B�Լ��� �״�� �����ؼ� �� �� �ӵ��� ���� �� �ִ�. 
		// inline�� �ٿ��� ���տ��δ� �����Ϸ��� �Ǵ��Ѵ�. 

		// ** �ݵ�� �ζ����� ��Ű�� ���� ���� " ������ �ζ��� " ������ ����ϸ� �ȴ�. 
		// __forceinline: �̷���. 

	private: // ���� 
		static int g; // �������� 
		static std::vector<Key> mKeys; // ��Ŭ��� ����� ����. �Ž��� �Լ��� ���͸� ������. 
		// �� Ű���� eKeycode code, eKeyState state, bool bpressed�� �����. 
		// �̰� ��ǲ cpp���� ���� 
	};
}



