#include <iostream>

using std::cout;
using std::endl;

// 오버 로딩

// 오버 라이딩
// 부모 클래스에 있는 기능(함수) 를 자식 클래스에서 재정의 한다.
// 부모 클래스에 있는 기능이 맞지 않아서 재정의를 하거나, 모자란 부분이 있어서 추가 구현을 해야 할 경우

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

	// 정확한 구현 범위를 지정하지 않았다면,
	// 컴파일러는 자식 클래스 쪽에서 오버라이딩한 함수를 호출 시킨다.
	// 그렇다고 부모 클래스에 구현해놓은 원본 함수를 호출할 수 없는 것은 아니다.
	c.OutputMyData();
	c.Parent::OutputMyData();


	// 1. 은닉성 
	// 2. 캡슐화
	// 3. 상속(생성자, 소멸자 실행 순서)
	// 4. 다형성 (하나의 타입으로 여러 형태를 나타낼 수 있음)
	// 5. 추상화

	// 상속 + 포인터
	Parent p1;
	Child  c1;

	// (1) 은 부모 클래스 타입 포인터로 자식 클래스 객체의 주소를 받았기 때문에,
	// 포인터를 이용해서 원본에 접근할 경우, Parent 클래스 영역까지밖에 접근할 수 없다.

	// (2) 은 자식 클래스 타입 포인터로, 부모 클래스 객체의 주소를 받으려고 하기 때문에
	// 이게 허용될 경우 포인터로 원본 데이터의 크기에 맞지 않게 초과	해서 메모리에 접근할 수 있기 때문에
	// 컴파일러 에러로 처리된다.

	Parent* pP = &c1;		//(1)  부모 포인터 <= 자식객체 주소
	//Child* pC = &p1;		//(2)  자식 포인터 <= 부모객체 주소	

	//pP->m_Parent = 10;
	//pC->m_Child = 10;


	return 0;
}