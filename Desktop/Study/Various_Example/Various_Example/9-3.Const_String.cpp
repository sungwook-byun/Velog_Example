#include<stdio.h>

int main()
{
	/*
	int iarr[10] = {10,20,30,};
	int* pointer_a = iarr;
	printf("*pointer_a �� ���� : %d \n", *pointer_a);

	*(pointer_a + 1) = 400;
	printf("iarr[1] �� ���� : %d \n", iarr[1]);
	*/
	
	char cname[10] = "Hello";
	unsigned char cname2[100] = "�ȳ�"; // �迭�� �� 4ĭ�� ����


	wchar_t wname[10] = L"Hello";
	wchar_t wname2[10] = L"�ȳ�"; // �迭�� �� 2ĭ�� ����

	
	{
		int a = 10;
		int b = 20;


		// �����ͷ� ������ �����ϴ� ����� ����
		const int* pointer_val = &a;
		// *pointer_val = 100; �����ϴ°� �Ұ��������� �����ϴ°� ������
		pointer_val = &b;
		printf("*pointer_val�� ���� : %d \n", *pointer_val);
		printf("a�� ���� : %d \n", a);



		// ������ ���� ��ü�� ���ȭ��
		int* const pointer_val2 = &a;
		*pointer_val2 = 100;
		printf("a�� ���� : %d \n", a);

		 // pointer_val2 = &b; �� ��ü�� �����ϴ°� ���������� �����ϴ°� �Ұ���
	}

	{
		// const Ű����
		int value = 100;
		int a = 20;

		// ������ ���ȭ
		const int cvalue = 100;
		//cvalue = 200;

		// �������
		// const int* pForce = &cvalue;
		// (int*)pForce = 200;

		// const �����ϱ� 1
		int* pForce = (int*)&cvalue;
		*pForce = 200;

		// const �����ϱ� 2
		const int* pForce1 = &cvalue;
		printf("pForce1�� ���� : %d \n", *pForce1);
//		pForce1 = 200;
		*((int*)pForce1) = 200;


	}




	return 0;

}