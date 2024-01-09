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

// ����Ʈ, ������Ʈ, ����Ʈ
// O(N logN)



// �׷��� - ��尣�� ������踦 ǥ��

// Ʈ�� - ��ȯ�� �Ұ����� �׷���

// ����Ʈ�� - �ڽ��� ������ 2���� ������ Ʈ��

// ����Ž��Ʈ�� - �Է� �����͸� ũ�⿡ ���� �¿�(�������� ����, ū���� ������)�� �����ϴ� Ʈ��

// Self Balanced Binary Search Tree
// �ڰ����� ����Ž��Ʈ��
// Red-Black, AVL

// Ž��
// ���� Ž�� O(N)
// ���� Ž�� O(logN)
// - �����Ͱ� ���ĵǾ��־�� �Ѵ�.
// - N(������ ũ��) �� ���ݾ� �ٿ������� ���

// �����̳�		 vector			list			  map,set
// �ڷᱸ��		�����迭		������ ����Ʈ		   ����Ž��Ʈ��
// �Է�			 O(1)			O(1)			 O(logN)
// ����			 O(N)			O(1)			 O(1)
// �ε���		 O(1)			O(N)			 O(N)
// Ž��			 O(N)			O(N)			 O(logN)

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
	// find �Լ��� �Էµ� �����Ͷ� ������ �����Ͱ� �ִ��� ã�Ƽ� �� �����͸� ����Ű�� iterator �� ��ȯ.
	// ���� �ش� �����Ͱ� �����̳� �ȿ� ��������, end iterator �� ��ȯ
	set<int>::iterator iter = intset.find(125);
	iter = intset.find(124);
	if (iter != intset.end())
	{

	}
	else
	{

	}

	// map ���
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

	// BST insert �׽�Ʈ
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

// ���� ������ ���ϱ�
// BST iterator -- �����ϱ�

// 1. erase ���� ������
// 2. iterator -> operator
// 3. ���ڿ� Ű�� ���

