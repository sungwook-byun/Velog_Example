#include<stdio.h>

// 전처리기
#define BLEED 1   // 0x1
#define SLOW  2	  // 0x2
#define STURN 4   // 0x4
#define SHORK 8   // 0x8
#define BURN  16  // 0x10
#define ICE   32  // 0x20
#define TIRED 64  // 0x40



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

// 비트 연산자
	// &(곱), |(합), ~(반전), ^(xor)
	// 비트단위로 연산을 진행
	{
		// & 둘 다 참(1) 인 경우에만 1
		// | 둘 중 하나라도 참(1) 이면 1
		int i = 10 & 8;
		i = 10 | 8;

		// ~ 모든 비트를 0은 1로, 1은 0으로 반전시킨다.
		char c = 0;
		c = ~c; 

		// ^ 같으면 0, 다르면 1
		i = 10 ^ 8;

		// 비트연산자로 상태값을 표현하기
		unsigned int status = 0;

		// 1, 2, 4, 8, 16...... 상태값을 원하는 2진법으로 원하는 자리에 넣을 수 있음.
		// 하지만 이렇게 표현하면 작성한 사람만 알아보기 쉽기 때문에 맨 위에서 전처리기로 알아보고 판별하기 쉽게 선언함
		status |= BLEED;
		status |= SLOW;


		// 상태 확인
		int hp = 100;
		if (status & SLOW)
		{
			printf("슬로우 상태를 가지고 있다. \n");
			hp -= 30;
		}
		
		// 상태 제거
		if (status &= ~BLEED)
		{
			printf("출혈을 제거한다. \n");
		}
		



		status;

	}

	return 0;

}