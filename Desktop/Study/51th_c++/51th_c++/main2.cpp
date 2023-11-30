#include<stdio.h>


int main()
{
// 반복문
	// for문
	// for( 변수 초기화; 반복 조건테스트(참 or 거짓); 반복 수행마다 실행 )

	for (int i = 0; i < 5; ++i)
	{
		// continue;
		// break;
		if (i == 2)
		{
			continue; // i가 2일때는 continue로 생략하기 때문에 바로 3으로 넘어감
		}
		if (i == 4)
		{
			break; // 4에서 멈추기 때문에 0,1,3만 출력되니까 3번만 출력됨
		}

		printf("for문 출력 \n");
	}

	// while 문
	int j = 0;
	while (j < 5) // (조건에는 횟수를 기입해야함)
	{
		printf("while문 출력 \n");
		++j;
	}




// 비트 쉬프트
	// >>, <<
	{
		// << 2의 승수 배수
		// >> 2의 승수로 나눈 몫
		int i = 1 << 1;
		i <<= 1;
	}



}