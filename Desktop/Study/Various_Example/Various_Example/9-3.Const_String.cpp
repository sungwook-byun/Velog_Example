#include<stdio.h>

int main()
{
	/*
	int iarr[10] = {10,20,30,};
	int* pointer_a = iarr;
	printf("*pointer_a 의 값은 : %d \n", *pointer_a);

	*(pointer_a + 1) = 400;
	printf("iarr[1] 의 값은 : %d \n", iarr[1]);
	*/
	
	char cname[10] = "Hello";
	unsigned char cname2[100] = "안녕"; // 배열의 총 4칸을 차지


	wchar_t wname[10] = L"Hello";
	wchar_t wname2[10] = L"안녕"; // 배열의 총 2칸을 차지

	
	{
		int a = 10;
		int b = 20;


		// 포인터로 원본을 수정하는 기능이 막힘
		const int* pointer_val = &a;
		// *pointer_val = 100; 수정하는건 불가능하지만 참조하는건 가능함
		pointer_val = &b;
		printf("*pointer_val의 값은 : %d \n", *pointer_val);
		printf("a의 값은 : %d \n", a);



		// 포인터 변수 자체가 상수화됨
		int* const pointer_val2 = &a;
		*pointer_val2 = 100;
		printf("a의 값은 : %d \n", a);

		 // pointer_val2 = &b; 값 자체를 수정하는건 가능하지만 참조하는건 불가능
	}

	{
		// const 키워드
		int value = 100;
		int a = 20;

		// 변수를 상수화
		const int cvalue = 100;
		//cvalue = 200;

		// 문법대로
		// const int* pForce = &cvalue;
		// (int*)pForce = 200;

		// const 무시하기 1
		int* pForce = (int*)&cvalue;
		*pForce = 200;

		// const 무시하기 2
		const int* pForce1 = &cvalue;
		printf("pForce1의 값은 : %d \n", *pForce1);
//		pForce1 = 200;
		*((int*)pForce1) = 200;


	}




	return 0;

}