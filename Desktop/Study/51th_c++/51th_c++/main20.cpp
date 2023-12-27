#include <iostream>

#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include "CArr.h"
//using namespace std;
using std::vector;

std::string;
std::wstring;
std::list<int>;


namespace MY_SPACE
{
	void TestFunc()
	{

	}

	int g_Global = 0;
}

int g_Global = 0;
int g_Global2 = 0;

void TestFunc()
{

}


namespace MY_SPACE
{
	int g_Global2 = 0;
}

//using namespace MY_SPACE;

#include "CArr.h"

// 네임 스페이스
// namespace, ::(스코프 연산자)
// 변수명, 함수명, 클래스명, 매크로이름 등등, 모든 부분에서 이름적으로 겹치는 일이 없도록
// 각자 자기만의 namespace 안에 기능들을 구현

// using namespace 네임스페이스이름;  - 해당 네임스페이스를 무효화 처리, 
//									   namespace 안에 모든것을 해제시키기 때문에, 원래 목적을 상실
// using 네임스페이스이름::기능;       - 해당 네임스페이스 안에 특정 기능만 namespace 범위 해제


// 함수 템플릿
template<typename T>
T Add(T a, T b)
{
	return a + b;
}


int data = 10;

int main()
{
	// namespace 사용, 범위지정 연산자를 이용해서 원하는 namespace 안에 구현된 기능에 접근할 수 있다.
	MY_SPACE::TestFunc();
	TestFunc();

	MY_SPACE::g_Global = 100;
	g_Global = 100;

	// 스코프 연산자
	int data = 0;
	data = 10;

	// 함수 지역안에서 호출할 변수의 우선순위를 전역변수로 바꾸고 싶은 경우
	// 맴버 함수내에서 호출할 함수의 우선순위를 전역함수로 바꾸고 싶은 경우
	::data = 10;


	// 원칙적으로는 함수 템플릿에 타입을 지정해줘야 하지만,
	// 컴파일러가 입력 인자의 타입을 분석해서 자동으로 특정 타입을 정해서 함수 템플릿을 작성한다.
	// 따라서 겉으로 보기에 마치 일반 전역 함수를 호출하는 것 처럼 보일 수 있으나 
	// 염연히 함수 템플릿을 사용 한 것
	int value = Add(10, 10);
	value = Add(1.2f, 3.5f);

	Add<float>(1.2f, 3.5f);
	Add<float>(1.2f, 3.5f);


	// 표준 라이브러리 동적배열 vector 는 클래스 템플릿이다.
	std::vector<int>	vecInt;
	std::vector<float>	vecFloat;

	CArr arr;


	int i = 0;
	i = arr.size();
	i = arr.capacity();

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);

	int a = arr[2];
	arr[2] = 60;

	for (int i = 0; i < arr.size(); ++i)
	{
		printf("입력 데이터 : %d\n", arr.at(i));
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		printf("입력 데이터 : %d\n", arr[i]);
	}

	return 0;
}