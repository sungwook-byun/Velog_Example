#include <iostream>


int main()
{
	// 배열(Array)
	int i0 = 0;
	int i1 = 0;
	int i2 = 0;
	int i3 = 0;
	int i4 = 0;

	// 자료형 배열이름[개수] = {전부다 안에 있는 값을 0으로 초기화};
	// 인트형 Arr이름의 10개의 값이 있고 맨 앞에 0,1,2,3번의 값은 1,2,3,4로 채우고 나머지는 0으로 채움
	int Arr_ex[10] = {1, 2, 3, 4};

	// 배열의 메모리 구조는 연속적인 구조이다.
	// 배열의 이름은 해당 배열의 시작위치(주소)
	int Arr[10] = {};
	
	// 5번째 인덱스에 10을 넣음
	Arr[4] = 10;

	// 버블정렬 기능 구현
	// O(1) -> O(logN) -> O(N) -> O(N * logN) -> O(N^2)
	// O(N^2) : 버블정렬, 삽입정렬 
	// O(N * logN) : 퀵소트(쾌속정렬)- 불안정정렬, 머지소트(합병정렬)-안정 정렬, 힙소트

	// 안정 정렬, 불안정 정렬
	// 정렬의 기준이 여러개인 경우, 이전 정렬 순서가 남아있는지 아닌지 여부

	int iArray[10] = { 44, 99, 47, 76, 26, 11, 46, 87, 56, 28 };

	int iNum = sizeof(iArray) / sizeof(int);  // 배열은 인트형이 10개 모인거니 40바이트인데 인트는 4바이트니 10이 나옴

	// 비교작업은 10개 사이사이이기 떄문에 9번이므로 iNum - 1
	
	// 정렬이 완료되었다면 반복문 종료
	// continue, break 
	for (int j = 0; j < iNum - 1; ++j)
	{
		for (int i = 0; i < iNum - (1 + j); ++i)
		{
			if (iArray[i] > iArray[i + 1])
			{
				int Temp = iArray[i];
				iArray[i] = iArray[i + 1];
				iArray[i + 1] = Temp;
			}
		}

	}

	return 0;
}