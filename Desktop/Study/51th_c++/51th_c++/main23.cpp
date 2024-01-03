#include <iostream>

#include <set>
#include <map>
using std::set;
using std::map;
using std::make_pair;






// �׷��� - ��尣�� ������踦 ǥ��

// Ʈ�� - ��ȯ�� �Ұ����� �׷���

// ����Ʈ�� - �ڽ��� ������ 2���� ������ Ʈ��

// ����Ž��Ʈ�� - �Է� �����͸� ũ�⿡ ���� �¿�(�������� ����, ū���� ������)�� �����ϴ� Ʈ��


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



	return 0;
}