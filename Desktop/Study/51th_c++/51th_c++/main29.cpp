#include <iostream>
using std::cout;
using std::endl;

// 상속		- 부모 클래스의 기능을 물려받음, 코드 재사용성
//			- 오버 라이딩, 부모 클래스의 기능을 재정의
// 다형성	- 부모 클래스 포인터 타입으로, 파생되는 모든 자식 클래스 객체들의 주소를 가리킬 수 있다.
//			- virtual (가상함수) 
//			- 자식 클래스에서부터 추가된 함수에 대한 접근 ==> 다운 캐스팅(강제 캐스팅, dynamic_cast)
// 
// 추상화	- 추상 클래스(Abstract Class)
//			  상속을 목적으로, 파생되는 자식클래스들의 공통분모 역할을 하는 클래스
//			  구체성이 없기 때문에 해당 클래스로 객체가 생성되는 것을 방지해야 함


// 순수 가상함수(Pure Virtual Function) 이 정의되어있는 클래스는
// 추상 클래스로 취급한다. ==> 객체 생성이 불가능
class Animal
{
public:
	// 순수 가상함수
	// Animal 을 상속받는 모든 자식 클래스들은 추상클래스를 벗어나기 위해서
	// 순수 가상함수를 구현해야 한다.
	virtual void Eat() = 0; // 인터페이스

	virtual void Move()
	{
		cout << "Move" << endl;
	}
};

class Bird
	: public Animal
{

public:
	//virtual void Eat()
	//{
	//	cout << "Pack" << endl;
	//}

	virtual void Move()
	{
		cout << "Fly" << endl;
	}
};

class Eagle
	: public Bird
{
private:



public:
	virtual void Move()
	{
		cout << "Fly" << endl;
	}
};

// 가상함수 사용시 주의점
// 상속 과정에서 부모 클래스의 가상함수를 오버라이딩 한 경우
// virtual 키워드를 붙이지 않아도 되지만, 일반 맴버함수와의 구별을 위해서 
// virtual 키워드를 붙이는 것이 좋다.

// 가상함수를 오버라이딩 한 경우와, 새로 해당 클래스에서 구현한 가상함수 끼리 구별하기 위해
// 함수 뒤에 override 키워드를 붙여서 부모의 가상함수를 오버라이딩한 것인지, 새로 구현된 가상함수인지
// 구별해 주는것이 가독성이 좋다.

// 상속구조의 클래스를 동적할당하는 경우, 다형성을 위해서 부모 포인터로 자식 객체의 주소를 받는
// 상황이 많은데, 이때 객체를 소멸할때 부모 포인터로 delete 를 요청하기 때문에, 
// 소멸자에 virtual 을 붙이지 않았으면, 최상위 부모 클래스의 소멸자만 호출되고 
// 자식 클래스에 구현한 소멸자들은 호출되지 않는 문제가 있다.
// 상속구조를 설계할 때에는 최상위 부모 클래스의 소멸자에 virtual 키워드를 붙이는 것을 
// 반드시 잊으면 안된다.


int main()
{
	//Animal animal;
	//Bird  bird;
	//Eagle eagle;





	return 0;
}