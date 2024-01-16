#include <iostream>
using std::cout;
using std::endl;

// ���		- �θ� Ŭ������ ����� ��������, �ڵ� ���뼺
//			- ���� ���̵�, �θ� Ŭ������ ����� ������
// ������	- �θ� Ŭ���� ������ Ÿ������, �Ļ��Ǵ� ��� �ڽ� Ŭ���� ��ü���� �ּҸ� ����ų �� �ִ�.
//			- virtual (�����Լ�) 
//			- �ڽ� Ŭ������������ �߰��� �Լ��� ���� ���� ==> �ٿ� ĳ����(���� ĳ����, dynamic_cast)
// 
// �߻�ȭ	- �߻� Ŭ����(Abstract Class)
//			  ����� ��������, �Ļ��Ǵ� �ڽ�Ŭ�������� ����и� ������ �ϴ� Ŭ����
//			  ��ü���� ���� ������ �ش� Ŭ������ ��ü�� �����Ǵ� ���� �����ؾ� ��


// ���� �����Լ�(Pure Virtual Function) �� ���ǵǾ��ִ� Ŭ������
// �߻� Ŭ������ ����Ѵ�. ==> ��ü ������ �Ұ���
class Animal
{
public:
	// ���� �����Լ�
	// Animal �� ��ӹ޴� ��� �ڽ� Ŭ�������� �߻�Ŭ������ ����� ���ؼ�
	// ���� �����Լ��� �����ؾ� �Ѵ�.
	virtual void Eat() = 0; // �������̽�

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

// �����Լ� ���� ������
// ��� �������� �θ� Ŭ������ �����Լ��� �������̵� �� ���
// virtual Ű���带 ������ �ʾƵ� ������, �Ϲ� �ɹ��Լ����� ������ ���ؼ� 
// virtual Ű���带 ���̴� ���� ����.

// �����Լ��� �������̵� �� ����, ���� �ش� Ŭ�������� ������ �����Լ� ���� �����ϱ� ����
// �Լ� �ڿ� override Ű���带 �ٿ��� �θ��� �����Լ��� �������̵��� ������, ���� ������ �����Լ�����
// ������ �ִ°��� �������� ����.

// ��ӱ����� Ŭ������ �����Ҵ��ϴ� ���, �������� ���ؼ� �θ� �����ͷ� �ڽ� ��ü�� �ּҸ� �޴�
// ��Ȳ�� ������, �̶� ��ü�� �Ҹ��Ҷ� �θ� �����ͷ� delete �� ��û�ϱ� ������, 
// �Ҹ��ڿ� virtual �� ������ �ʾ�����, �ֻ��� �θ� Ŭ������ �Ҹ��ڸ� ȣ��ǰ� 
// �ڽ� Ŭ������ ������ �Ҹ��ڵ��� ȣ����� �ʴ� ������ �ִ�.
// ��ӱ����� ������ ������ �ֻ��� �θ� Ŭ������ �Ҹ��ڿ� virtual Ű���带 ���̴� ���� 
// �ݵ�� ������ �ȵȴ�.


int main()
{
	//Animal animal;
	//Bird  bird;
	//Eagle eagle;





	return 0;
}