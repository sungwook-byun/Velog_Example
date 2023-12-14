#include<stdio.h>	


int main()
{
	// volatile�� ���� ������ cpu�� �̹� cint���� ����� ����Ѵٴ� ��������
	// �ٲ��� ���� ���� �˱⶧���� �������ּҷ� �����ؼ� ���� �����߾
	// Ȯ�� ������ ����ġ �ʰ� ��������� ������������ ���� �ٸ�����
	// �����صа� ����� ����ϱ� ������ 100�� ��µ�
	// volatile�� �ǹ̴� �ֹ߼��ϼ� ������ ������ ���� �ƴ� ���� ��������
	// Ȯ���϶�� �ǹ��̴�.
	volatile const int cint = 100;

	int *Pointer_int = nullptr;

	Pointer_int = (int*)&cint;
	*Pointer_int = 300;

	printf("cint ��� : %d \n\n", cint);

	int a = 1;
	int b = 2;
	int* pInt = &a;

	// 1�� ����
	// const ������
	// a�� �ּҰ� ���ȭ�� �ȰŶ� ������ ���� ���� ������
	//	*pIntConst = 400;  ������ �ּ� ���� �ٲܼ��� ����
	const int* pConstInt = &a;
	pConstInt = &b;

	printf("*pConstInt�� ���� : %d \n", *pConstInt);


	// 2�� ����
	// ������ const
	// ���� ��ü�� ���ȭ�� ��
	//	pIntConst = &b;  ��� �̰� �Ұ�����
	int* const pIntConst = &a;
	*pIntConst = 400;
	printf("a�� ���� : %d \n", a);

	return 0;
}