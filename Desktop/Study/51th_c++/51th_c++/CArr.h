#pragma once


class CArr
{
private:
	int* m_pData;
	int		m_MaxCount;
	int		m_CurCount;

public:
	void push_back(int _Data);

private:
	void Realloc();

	// ����� �ɹ��Լ��� ���� �� ���
	// �ζ��� �Լ��� ó��	
	// ����� ���� ������ �����ν�, ȣ��� �ش� ������ �״�� �����Ѵ�.
	// ��ũ�� �Լ��� ����, �Լ� ȣ�� �� ������ ���� ���� ���� ����� ����.

	// �ζ��� �Լ��� �����ϴ� ��� �߻��ϴ� ����.
	// �Լ� ������ �������� ȣ���ϴ� ������ ����Ǿ �ڵ��� ���� ��û���� �þ �� �ִ�.

	// �ζ��� ó���� �� �Լ����� Ư¡.
	// ������ ª��(����� �����Ѵ�, Get, Set ������ �Լ�)
	// ���� ȣ�� �Ǵ� �Լ�
public:
	int size() { return m_CurCount; }
	int capacity() { return m_MaxCount; }
	int at(int _Idx) { return m_pData[_Idx]; }

	// ��ȯŸ���� �������·� ��ȯ, ��ȯ�� ���� �����ϸ� �������� �����Ǵ� ����
	int& operator[](int _Idx) 
	{ 
		return m_pData[_Idx];
	}


public:
	CArr();
	~CArr();
};