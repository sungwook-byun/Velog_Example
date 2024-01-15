#include <iostream>

using std::cout;
using std::endl;

// 다형성의 문제점
// 부모 클래스 포인터 변수로 자식 클래스 객체의 주소를 받았을 때
// 포인터가 부모 클래스 타입이기 때문에, 부모 클래스의 기능까지밖에 접근이 안된다.
// 가상함수를 통해서 자식 클래스에서 오버라이딩한 함수를 호출할 수 있게 한다.

// 가상함수가 1개 이상 있으면 각 클래스는 타입 정보가 만들어진다.
// 타입 정보에는 해당 클래스가 보유하고 있는 가상함수의 주소를 모아놓은 가상함수 테이블도 있다.
// 부모 클래스에 보이지 않는 맴버(가상함수 테이블 포인터)가 추가된다.
// 가상함수를 호출할 경우, 부모클래스의 맴버인 가상함수테이블 포인터를 이용해서 가상함수 테이블로 접근,
// 가상함수 테이블에서 호출하려는 함수를 호출(탐색 x, 인덱싱 o)
class Parent
{
public:
	int m_Parent;

public:
	// 가상 함수
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