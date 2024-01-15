#include <iostream>

using std::cout;
using std::endl;

// ���� �ε�

// ���� ���̵�
// �θ� Ŭ������ �ִ� ���(�Լ�) �� �ڽ� Ŭ�������� ������ �Ѵ�.
// �θ� Ŭ������ �ִ� ����� ���� �ʾƼ� �����Ǹ� �ϰų�, ���ڶ� �κ��� �־ �߰� ������ �ؾ� �� ���

class Parent
{
public:
	int m_Parent;

public:
	void OutputMyData()
	{
		cout << "m_Parent : " << m_Parent << endl;
	}

public:
	Parent() : m_Parent(0) {}
	Parent(int _P) : m_Parent(_P) {}
};


class Child
	: public Parent
{
public:
	int	m_Child;

public:
	void OutputMyData()
	{
		//cout << "m_Parent : " << m_Parent << endl;
		Parent::OutputMyData();
		cout << "m_Child : " << m_Child << endl;
	}

public:
	Child() :m_Child(0) {}
	Child(int _P, int _C) : Parent(_P), m_Child(_C) {}
};

int main()
{
	Parent	p(10);
	Child	c(10, 20);

	p.OutputMyData();

	// ��Ȯ�� ���� ������ �������� �ʾҴٸ�,
	// �����Ϸ��� �ڽ� Ŭ���� �ʿ��� �������̵��� �Լ��� ȣ�� ��Ų��.
	// �׷��ٰ� �θ� Ŭ������ �����س��� ���� �Լ��� ȣ���� �� ���� ���� �ƴϴ�.
	c.OutputMyData();
	c.Parent::OutputMyData();


	// 1. ���м� 
	// 2. ĸ��ȭ
	// 3. ���(������, �Ҹ��� ���� ����)
	// 4. ������ (�ϳ��� Ÿ������ ���� ���¸� ��Ÿ�� �� ����)
	// 5. �߻�ȭ

	// ��� + ������
	Parent p1;
	Child  c1;

	// (1) �� �θ� Ŭ���� Ÿ�� �����ͷ� �ڽ� Ŭ���� ��ü�� �ּҸ� �޾ұ� ������,
	// �����͸� �̿��ؼ� ������ ������ ���, Parent Ŭ���� ���������ۿ� ������ �� ����.

	// (2) �� �ڽ� Ŭ���� Ÿ�� �����ͷ�, �θ� Ŭ���� ��ü�� �ּҸ� �������� �ϱ� ������
	// �̰� ���� ��� �����ͷ� ���� �������� ũ�⿡ ���� �ʰ� �ʰ�	�ؼ� �޸𸮿� ������ �� �ֱ� ������
	// �����Ϸ� ������ ó���ȴ�.

	Parent* pP = &c1;		//(1)  �θ� ������ <= �ڽİ�ü �ּ�
	//Child* pC = &p1;		//(2)  �ڽ� ������ <= �θ�ü �ּ�	

	//pP->m_Parent = 10;
	//pC->m_Child = 10;


	return 0;
}