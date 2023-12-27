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
	// C++ ��Ÿ���� ���� �Ҵ�� ����
	// malloc, free
	// new, new [], delete, delete[]

	int size = sizeof(CTest);
	CTest* pArr = (CTest*)malloc(16);
	free(pArr);


	// C++ ������ �����Ҵ��� new, delete ���ø����� ó���Ѵ�.
	// �� �޸𸮿� ��û�� �޸��� ũ�⸦ ������ �ڷ��� Ÿ���� ũ��� ó���ϰ�
	// �ش� ������ �˷��� �ڷ��� ������ ���δٰ� �Ǵ��ϰ� �ش� �ڷ����� Ŭ�������
	// �� Ŭ������ ������ or �Ҹ��� ���� ȣ�����ش�.
	CTest* pArr1 = new CTest;
	delete pArr1;

	// ���ӵ� ������ �����Ҵ� �� ���� �ϱ�
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

	// �����迭(vector) �� ȿ�������� ����ϱ�
	// iterator(�ݺ���) ����
	vecFloat.reserve(10);
	vecFloat.resize(10);


	// reserve �� �����迭�� Ư¡�� �����Ͱ� �Էµɶ� 
	// ������ ���ڶ�� ���� Ȯ���ϴ� ������ ���ϱ� ���� �˳��ϰ� 
	// �̸� �����͸� ���� ������ �Ҵ��ص�
	// ���� ���� �Էµ� ������ ������ 0, Capacity �� �þ

	// resize �� reserve ó�� �����迭�� �����ϴ� �����͸� �Է��ϴ� ������ ũ�⸦
	// �ø��� ���� ������, reserve �� �ٸ��� resize �� �Է� ������Ÿ���� �⺻ ������ ������ ä��
	// ���� �Է� ������ ����(size) ��ü�� �þ

	std::vector<int> vecInt;
	vecInt.reserve(100);
	//vecInt.at(10) = 11;

	//vecInt.resize(110);
	//vecInt[10] = 20;

	// ���� ���� vector ��ü�� ���������� ��ü�ؼ� �þ ������ �ٽ� ���� �� �ִ�.
	std::vector<int> vecTemp;
	vecTemp = g_vecInt;
	g_vecInt.swap(vecTemp);


	// ������ ���� (���� ����)
	// �Ŵ��� ����, �ݺ��� ����, �̱��� ����
	// �ݺ���(iterator) ����(����)

	// �����̳ʰ� ������ �ִ� �����͸� �����Ҷ�
	// �ݺ��ڸ� ���ؼ� Ư�� �����Ϳ� �����ϴ� ���
	// iterator �� ���� �������� �̵��ϸ� �����̳��� Ư¡�� ���߾ ���� �����Ϳ� ������ ����
	// �����̳ʰ� �����ϴ� �����͸� �����ϴ� �� �־ ������ ���о��� ���ϼ��ְ� ��� ����
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