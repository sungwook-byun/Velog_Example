#include <iostream>

struct object
{
	const int id;
	int hp;
	int mp;

};


int main()
{
	//����
	// ���� == ����
	// ����Ÿ�Կ� ���ڸ� ������ �ƽ�Ű�ڵ�ǥ�� �ִ� ���ڿ� ��Ī�ϴ� ���ڸ� �����ͼ� ������
	short s = 49;
	wchar_t wc = 50; // wchar_t wc = '2';
	char c = 61;

	// ���� �迭
	char cname[10] = "Hello"; // ���� �ϳ��ϳ��� 1����Ʈ ��� �ǹ�
//	wchar_t name[10] = { L'1',L'2',L'3',};
	wchar_t name[10] = L"Hello"; // ���� �ϳ��ϳ��� 2����Ʈ ��� �ǹ�, wchar_t�� ������ ���


	// ���ڿ�
	


	// const ������
	const char* pString = "abcdef";

	// const * Ÿ��
	// �ּҸ� �����ϰ�, ����(�б�) ������ ����
	// ���� ������ ���� �� �� ����
	int data = 0;
	int data2 = 2;

	const int* pData = &data;

	int i = *pData; // ������ ����
	// *pData = 100;  �ٸ� ������ �Ұ���

	pData = &data2;
	// &pData = 200;
	
	// * const Ÿ��
	int* const pConst = &data;
	*pConst = 500; // �� ������ ����
	// pConst = &data2; �ٸ� ������ �Ұ���


	// const Ű����
	int value = 100;

	// ������ ���ȭ
	const int cvalue = 100;

	// ���� ĳ�������� const�� ���� ���� �����ͷ� �ٲܼ� ����
	int* pForce =(int*) & cvalue;
	*pForce = 200;


	{
		object a = {10};
		object b = {11};
		object c = {12};

		a.hp = 10;
	}


	{
		int a = 0;
		int b = 0;

		// ������ ���� ��ü�� ���ȭ��
		int* const pInt = &a;
		*pInt = 100;

		int b = 0;
		// pInt = &b;

		// �����ͷ� ������ �����ϴ� ����� ����
		const int* pInt2 = &a;
		pInt2 = &b;
		// *pInt2 = 200;

		// �ѹ� ����Ų ����� �ٸ� ������� ������ ���� ����
		// ����Ű�� �ִ� ������ �����Ҽ��� ����
		const int* const pInt3 = &a;

		

	}




	return 0;
}