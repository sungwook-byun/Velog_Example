#include <iostream>

using std::cout;
using std::endl;

#include "BST.h"


template<typename T1, typename T2>
class MyTemplateClass
{
	T1	m_Data1;
	T2  m_Data2;
};

MyTemplateClass<int, float> obj;





#include <set>
#include <map>
using std::set;
using std::map;
using std::make_pair;

// 퀵소트, 머지소트, 힙소트
// O(N logN)



// 그래프 - 노드간의 연결관계를 표현

// 트리 - 순환이 불가능한 그래프

// 이진트리 - 자식의 개수를 2개로 제한한 트리

// 이진탐색트리 - 입력 데이터를 크기에 따라 좌우(작은것을 왼쪽, 큰것을 오른쪽)로 정렬하는 트리

// Self Balanced Binary Search Tree
// 자가균형 이진탐색트리
// Red-Black, AVL

// 탐색
// 순차 탐색 O(N)
// 이진 탐색 O(logN)
// - 데이터가 정렬되어있어야 한다.
// - N(문제의 크기) 을 절반씩 줄여나가는 방식

// 컨테이너		 vector			list			  map,set
// 자료구조		동적배열		연결형 리스트		   이진탐색트리
// 입력			 O(1)			O(1)			 O(logN)
// 삭제			 O(N)			O(1)			 O(1)
// 인덱싱		 O(1)			O(N)			 O(N)
// 탐색			 O(N)			O(N)			 O(logN)

int main()
{
	set<int> intset;

	intset.insert(100);

	intset.insert(150);
	intset.insert(170);
	intset.insert(125);

	intset.insert(80);
	intset.insert(90);
	intset.insert(50);

	//			100
	//		   /	\
	//		80		 150
	//		/\		 /\
	//	  50  90  125	170
	// find 함수는 입력된 데이터랑 동일한 데이터가 있는지 찾아서 그 데이터를 가리키는 iterator 를 반환.
	// 만약 해당 데이터가 컨테이너 안에 없었으면, end iterator 를 반환
	set<int>::iterator iter = intset.find(125);
	iter = intset.find(124);
	if (iter != intset.end())
	{

	}
	else
	{

	}

	// map 사용
	map<int, int> intmap;

	intmap.insert(make_pair(100, 1));

	intmap.insert(make_pair(150, 2));
	intmap.insert(make_pair(170, 3));
	intmap.insert(make_pair(125, 4));

	intmap.insert(make_pair(80, 5));
	intmap.insert(make_pair(90, 6));
	intmap.insert(make_pair(50, 7));

	//			 100-1
	//		   /	   \
	//		80-5	  150-2
	//	   /    \	   /  \
	//	  50-7  90-6 125-4 170-3

	map<int, int>::iterator mapiter = intmap.find(50);

	if (mapiter != intmap.end())
	{
		(*mapiter).first;
		(*mapiter).second;
	}

	// BST insert 테스트
	BST<int, float> bst;
	bst.insert(make_bstpair(100, 1.1f));
	bst.insert(make_bstpair(150, 2.2f));
	bst.insert(make_bstpair(50, 2.2f));
	bst.insert(make_bstpair(170, 1.1f));
	bst.insert(make_bstpair(125, 2.2f));
	bst.insert(make_bstpair(25, 2.2f));
	bst.insert(make_bstpair(75, 2.2f));

	//			    100
	//		 50				150
	//	  25	75		125		170

	bst.Circit();
	BST<int, float>::iterator myiter = bst.begin();
	for (; myiter != bst.end(); ++myiter)
	{
		cout << (*myiter).first << endl;
	}

	myiter = bst.find(74);
	BST<int, float>::iterator TestIter = bst.end();

	--TestIter;
	--TestIter;
	--TestIter;
	--TestIter;
	--TestIter;
	--TestIter;
	--TestIter;

	TestIter = bst.begin();
	TestIter = bst.erase(TestIter);

	return 0;
}

// 중위 선행자 구하기
// BST iterator -- 구현하기

// 1. erase 구현 마무리
// 2. iterator -> operator
// 3. 문자열 키값 사용

