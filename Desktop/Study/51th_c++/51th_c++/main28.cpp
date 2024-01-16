#include <iostream>
#include <typeinfo>

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

	virtual ~Parent()
	{

	}
};


class Child
	: public Parent
{
public:
	int	m_Child;

public:
	// Child Ŭ���� �ɹ��Լ�
	void SetChild(int _child) { m_Child = _child; }

	// Child Ŭ�������� �߰��� �����Լ�
	virtual void Test()
	{

	}

	// �θ� Ŭ������ �����Լ��� ������ �� ���
	virtual void OutputMyData() override
	{
		cout << "Child" << endl;
		cout << "m_Parent : " << m_Parent << endl;
		cout << "m_Child : " << m_Child << endl;
	}

	// �θ� Ŭ������ �����Լ��� ������ �� ���
	virtual void VirtualFunc() override
	{

	}

public:
	Child() :m_Child(0) {}
	Child(int _P, int _C) : Parent(_P), m_Child(_C) {}

	~Child()
	{

	}
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

	Parent* pParent = nullptr;

	Child c5;
	c5.SetChild(10);

	pParent = &c5;

	Child* pChild = &c5;
	pChild->SetChild(10);


	// �θ� Ŭ���� ������ Ÿ������ �ڽ� Ŭ���� ��ü�� �ּҸ� ����Ų ���
	// �����Լ��� ���̺� ��ϵ� �Լ��� ȣ���ϱ� ������, �� Ŭ�������� �������̵��� ���� ������ ����� �� ������,
	// �����ϰ� �ڽ�Ŭ�������� ������ �Լ��� �θ� Ŭ���� �����ͷ� �� ���� ����.

	// �ذ� ���
	// 1. �ٿ� ĳ����
	//  - �θ� Ŭ���� �����Ϳ� ����� �ּҰ� Ư�� �ڽ�Ŭ���� ��ü���� Ȯ���ϴٸ�,
	//    �ش� �ڽ� Ŭ���� ������ Ÿ������ ������ ĳ�����ؼ� ���� �� ��ü�� ������ �����ϴ� ���
	((Child*)pParent)->SetChild(10); // ���� ĳ����

	// 2. RTTI(Runtime Type Idendification / Information )
	// dynamic_cast
	{
		Child* pChild = dynamic_cast<Child*>(pParent);

		if (pChild != nullptr)
		{
			pChild->SetChild(100);
		}
	}

	// Ư�� Ŭ������ Ÿ�� ������ ��������
	const type_info& info = typeid(Parent);
	unsigned __int64 id = info.hash_code();
	const char* pClassName = info.name();



	// �����Ҵ� Ŭ����
	Child* pChild = new Child;
	delete pChild;

	Parent* pParent = new Child;
	delete pParent;


	return 0;
}