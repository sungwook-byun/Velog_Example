#include <iostream>
#include <typeinfo>

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
	// Child 클래스 맴버함수
	void SetChild(int _child) { m_Child = _child; }

	// Child 클래스에서 추가된 가상함수
	virtual void Test()
	{

	}

	// 부모 클래스의 가상함수를 재정의 한 경우
	virtual void OutputMyData() override
	{
		cout << "Child" << endl;
		cout << "m_Parent : " << m_Parent << endl;
		cout << "m_Child : " << m_Child << endl;
	}

	// 부모 클래스의 가상함수를 재정의 한 경우
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


	// 부모 클래스 포인터 타입으로 자식 클래스 객체의 주소를 가리킨 경우
	// 가상함수는 테이블에 등록된 함수를 호출하기 때문에, 각 클래스에서 오버라이딩한 원래 버전을 사용할 수 있지만,
	// 순수하게 자식클래스부터 구현된 함수는 부모 클래스 포인터로 알 수가 없다.

	// 해결 방안
	// 1. 다운 캐스팅
	//  - 부모 클래스 포인터에 저장된 주소가 특정 자식클래스 객체임이 확실하다면,
	//    해당 자식 클래스 포인터 타입으로 강제로 캐스팅해서 실제 그 객체를 온전히 접근하는 방법
	((Child*)pParent)->SetChild(10); // 강제 캐스팅

	// 2. RTTI(Runtime Type Idendification / Information )
	// dynamic_cast
	{
		Child* pChild = dynamic_cast<Child*>(pParent);

		if (pChild != nullptr)
		{
			pChild->SetChild(100);
		}
	}

	// 특정 클래스의 타입 정보를 가져오기
	const type_info& info = typeid(Parent);
	unsigned __int64 id = info.hash_code();
	const char* pClassName = info.name();



	// 동적할당 클래스
	Child* pChild = new Child;
	delete pChild;

	Parent* pParent = new Child;
	delete pParent;


	return 0;
}