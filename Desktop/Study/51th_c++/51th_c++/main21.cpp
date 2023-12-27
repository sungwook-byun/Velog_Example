#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <set>
using std::set;

#include <map>
using std::map;
using std::make_pair;


#include "CArr.h"



class CTest
{
public:
	CTest()
	{}
	~CTest()
	{}
};

std::vector<int> g_vecInt;


int main()
{
	// C++ 스타일의 동적 할당과 해제
	// malloc, free
	// new, new [], delete, delete[]

	int size = sizeof(CTest);
	CTest* pArr = (CTest*)malloc(16);
	free(pArr);


	// C++ 에서는 동적할당을 new, delete 템플릿으로 처리한다.
	// 힙 메모리에 요청할 메모리의 크기를 전달한 자료형 타입의 크기로 처리하고
	// 해당 공간을 알려준 자료형 단위로 쓰인다고 판단하고 해당 자료형이 클래스라면
	// 그 클래스의 생성자 or 소멸자 까지 호출해준다.
	CTest* pArr1 = new CTest;
	delete pArr1;

	// 연속된 공간에 동적할당 및 해제 하기
	CTest* pArr2 = new CTest[10];
	delete[] pArr2;


	CArr<int> arr;
	CArr<int> arr1;
	arr.push_back(10);
	arr.push_back(20);
	arr1.push_back(30);

	int value = 0;
	value = arr.at(0);
	value = arr.at(1);
	value = arr.at(2);

	CArr<float> arr_float;

	arr_float.push_back(1.1f);
	arr_float.push_back(2.2f);
	arr_float.push_back(3.3f);

	float fvalue = 0;
	fvalue = arr_float.at(0);
	fvalue = arr_float.at(1);
	fvalue = arr_float.at(2);


	std::vector<float> vecFloat;
	vecFloat.push_back(1.1f);
	fvalue = vecFloat.at(0);
	fvalue = vecFloat[0];

	vecFloat.size();
	vecFloat.capacity();

	// 동적배열(vector) 를 효율적으로 사용하기
	// iterator(반복자) 패턴
	vecFloat.reserve(10);
	vecFloat.resize(10);


	// reserve 는 동적배열의 특징상 데이터가 입력될때 
	// 공간이 모자라면 새로 확장하는 구조를 피하기 위해 넉넉하게 
	// 미리 데이터를 넣을 공간을 할당해둠
	// 따라서 현재 입력된 데이터 개수는 0, Capacity 가 늘어남

	// resize 는 reserve 처럼 동적배열이 관리하는 데이터를 입력하는 공간의 크기를
	// 늘리는 점은 같으나, reserve 와 다르게 resize 는 입력 데이터타입의 기본 값으로 공간을 채움
	// 따라서 입력 데이터 개수(size) 자체가 늘어남

	std::vector<int> vecInt;
	vecInt.reserve(100);
	//vecInt.at(10) = 11;

	//vecInt.resize(110);
	//vecInt[10] = 20;

	// 지역 변수 vector 객체와 관리공간을 교체해서 늘어난 공간을 다시 줄일 수 있다.
	std::vector<int> vecTemp;
	vecTemp = g_vecInt;
	g_vecInt.swap(vecTemp);


	// 디자인 패턴 (설계 유형)
	// 매니저 패턴, 반복자 패턴, 싱글턴 패턴
	// 반복자(iterator) 패턴(유형)

	// 컨테이너가 가지고 있는 데이터를 접근할때
	// 반복자를 통해서 특정 데이터에 접근하는 방식
	// iterator 를 통해 다음으로 이동하면 컨테이너의 특징에 맞추어서 다음 데이터에 접근이 가능
	// 컨테이너가 관리하는 데이터를 접근하는 데 있어서 종류에 구분없이 통일성있게 사용 가능
	std::vector<short> vecShort;

	for (int i = 0; i < 100; ++i)
	{
		vecShort.push_back((short)(i + 1));
	}


	//for (size_t i = 0; i < vecShort.size(); ++i)
	//{
	//	//printf("%d\n", vecShort.at(i));
	//	//cout << vecShort.at(i) << endl;
	//	cout << vecShort[i] << endl;
	//}	

	vector<short>::iterator vec_iter = vecShort.begin();

	for (; vec_iter != vecShort.end(); ++vec_iter)
	{
		cout << *vec_iter << endl;
	}


	list<short> shortList;

	for (int i = 0; i < 100; ++i)
	{
		shortList.push_back(short(i + 1));
	}

	//for (size_t i = 0; i < shortList.size(); ++i)
	//{
	//	//printf("%d\n", vecShort.at(i));
	//	//cout << vecShort.at(i) << endl;
	//	//cout << shortList << endl;
	//}

	list<short>::iterator list_iter = shortList.begin();

	for (; list_iter != shortList.end(); ++list_iter)
	{
		cout << *list_iter << endl;
	}

	set<int> intset;

	for (int i = 0; i < 100; ++i)
	{
		intset.insert(i);
	}

	set<int>::iterator setiter = intset.begin();

	for (; setiter != intset.end(); ++setiter)
	{
		cout << *setiter << endl;
	}

	return 0;
}