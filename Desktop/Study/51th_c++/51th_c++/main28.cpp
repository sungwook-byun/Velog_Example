#include <iostream>

using std::cout;
using std::endl;

// �������� ������
// �θ� Ŭ���� ������ ������ �ڽ� Ŭ���� ��ü�� �ּҸ� �޾��� ��
// �����Ͱ� �θ� Ŭ���� Ÿ���̱� ������, �θ� Ŭ������ ��ɱ����ۿ� ������ �ȵȴ�.
// �����Լ��� ���ؼ� �ڽ� Ŭ�������� �������̵��� �Լ��� ȣ���� �� �ְ� �Ѵ�.

// �����Լ��� 1�� �̻� ������ �� Ŭ������ Ÿ�� ������ ���������.
// Ÿ�� �������� �ش� Ŭ������ �����ϰ� �ִ� �����Լ��� �ּҸ� ��Ƴ��� �����Լ� ���̺� �ִ�.
// �θ� Ŭ������ ������ �ʴ� �ɹ�(�����Լ� ���̺� ������)�� �߰��ȴ�.
// �����Լ��� ȣ���� ���, �θ�Ŭ������ �ɹ��� �����Լ����̺� �����͸� �̿��ؼ� �����Լ� ���̺�� ����,
// �����Լ� ���̺��� ȣ���Ϸ��� �Լ��� ȣ��(Ž�� x, �ε��� o)
class Parent
{
public:
	int m_Parent;

public:
	// ���� �Լ�
	virtual void OutputMyData()
	{
		cout << "Parent" << endl;
		cout << "m_Parent : " << m_Parent << endl;
	}

	virtual void VirtualFunc()
	{

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
		cout << "Child" << endl;
		cout << "m_Parent : " << m_Parent << endl;
		cout << "m_Child : " << m_Child << endl;
	}

	void VirtualFunc()
	{

	}

public:
	Child() :m_Child(0) {}
	Child(int _P, int _C) : Parent(_P), m_Child(_C) {}
};


class ChidlChild
	: public Child
{

};


int main()
{
	Parent	parent;
	Child	child;

	Parent* pP = &parent;
	parent.OutputMyData();
	pP->OutputMyData();

	pP = &child;
	child.OutputMyData();
	pP->OutputMyData();


	Child* pC = &child;
	pC->OutputMyData();



	Parent p1;
	Parent p2;
	Parent p3;
	Parent p4;

	Child c1;
	Child c2;
	Child c3;
	Child c4;


	Parent* pPP = &c1;
	pPP->VirtualFunc();


	ChidlChild cc;
	pPP = &cc;
	pPP->VirtualFunc();


	return 0;
}