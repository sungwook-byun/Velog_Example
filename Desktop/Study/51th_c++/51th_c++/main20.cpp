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

// ���� �����̽�
// namespace, ::(������ ������)
// ������, �Լ���, Ŭ������, ��ũ���̸� ���, ��� �κп��� �̸������� ��ġ�� ���� ������
// ���� �ڱ⸸�� namespace �ȿ� ��ɵ��� ����

// using namespace ���ӽ����̽��̸�;  - �ش� ���ӽ����̽��� ��ȿȭ ó��, 
//									   namespace �ȿ� ������ ������Ű�� ������, ���� ������ ���
// using ���ӽ����̽��̸�::���;       - �ش� ���ӽ����̽� �ȿ� Ư�� ��ɸ� namespace ���� ����


// �Լ� ���ø�
template<typename T>
T Add(T a, T b)
{
	return a + b;
}


int data = 10;

int main()
{
	// namespace ���, �������� �����ڸ� �̿��ؼ� ���ϴ� namespace �ȿ� ������ ��ɿ� ������ �� �ִ�.
	MY_SPACE::TestFunc();
	TestFunc();

	MY_SPACE::g_Global = 100;
	g_Global = 100;

	// ������ ������
	int data = 0;
	data = 10;

	// �Լ� �����ȿ��� ȣ���� ������ �켱������ ���������� �ٲٰ� ���� ���
	// �ɹ� �Լ������� ȣ���� �Լ��� �켱������ �����Լ��� �ٲٰ� ���� ���
	::data = 10;


	// ��Ģ�����δ� �Լ� ���ø��� Ÿ���� ��������� ������,
	// �����Ϸ��� �Է� ������ Ÿ���� �м��ؼ� �ڵ����� Ư�� Ÿ���� ���ؼ� �Լ� ���ø��� �ۼ��Ѵ�.
	// ���� ������ ���⿡ ��ġ �Ϲ� ���� �Լ��� ȣ���ϴ� �� ó�� ���� �� ������ 
	// ������ �Լ� ���ø��� ��� �� ��
	int value = Add(10, 10);
	value = Add(1.2f, 3.5f);

	Add<float>(1.2f, 3.5f);
	Add<float>(1.2f, 3.5f);


	// ǥ�� ���̺귯�� �����迭 vector �� Ŭ���� ���ø��̴�.
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
		printf("�Է� ������ : %d\n", arr.at(i));
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		printf("�Է� ������ : %d\n", arr[i]);
	}

	return 0;
}