#include "Str.h"

#include <iostream>

Str::Str()
	: m_pStr(nullptr)
	, m_MaxLength(10)
	, m_Length(0)
{
	m_pStr = new wchar_t[m_MaxLength + 1];
}

Str::Str(const wchar_t* _str)
	: m_pStr(nullptr)
	, m_MaxLength(10)
	, m_Length(0)
{
	m_pStr = new wchar_t[m_MaxLength + 1];
	(*this) = _str;
}

Str::~Str()
{
	if (nullptr != m_pStr)
		delete m_pStr;
}



void Str::Realloc()
{
	// ���� ������ 2��� Ȯ���ϱ�
	m_MaxLength *= 2;

	// ���ο� ������ ������.
	wchar_t* pNew = new wchar_t[m_MaxLength + 1];

	// ���� �ִ� �����͸� ���ο������ �ű��.
	for (int i = 0; i < m_Length; ++i)
	{
		pNew[i] = m_pStr[i];
	}
	pNew[m_Length] = '\0';

	// ���� ������ �����Ѵ�.
	delete m_pStr;

	// ���ο� ������ ����Ų��.
	m_pStr = pNew;
}

void Str::operator=(const wchar_t* _str)
{
	// �ԷµǷ��� ���ڿ��� ���� ����(����) �ľ�
	int len = 0;
	while ('\0' != _str[len]) { ++len; }

	// �ԷµǷ��� ���ڿ��� ���̰� �ִ� ���밳���� �Ѿ�� ���� ���� Ȯ��
	while (m_MaxLength < len)
	{
		Realloc();
	}

	// �Է� ���ڿ��� ����, �� �������� �ϳ��� �ű��
	int i = 0;
	for (; i < len; ++i)
	{
		m_pStr[i] = _str[i];
	}

	// �������� �ι��ڷ� ����
	m_pStr[i] = '\0';

	// ���ڿ� ���� ����(�Էµ� ���ڿ� ���̷�)
	m_Length = len;
}

Str Str::operator+(const Str& _string)
{
	Str strNew;
	strNew = m_pStr;
	strNew += _string.m_pStr;

	return strNew;
}

Str Str::operator+(const char* _Str)
{
	Str strNew;
	return strNew;
}

void Str::operator+=(const wchar_t* _Str)
{
	// �ڿ� ���� ���ڿ��� ���� ����(����) �ľ�
	int len = 0;
	while ('\0' != _Str[len]) { ++len; }

	// ���� ���ڿ� ���� + ���� �ڿ� ���� ���ڿ��� ���̰� �ִ� ���� ũ�⸦ ������� Ȯ��
	while (m_MaxLength < m_Length + len)
	{
		Realloc();
	}

	// �ڿ����� ���ڿ��� ��������
	for (int i = 0; i < len; ++i)
	{
		m_pStr[i + m_Length] = _Str[i];
	}

	// �����ϰ� �ִ� ���ڿ� ���� ����
	m_Length += len;
	m_pStr[m_Length] = '\0';
}

bool Str::operator==(const Str& _Other) const
{
	return false;
}

bool Str::operator!=(const Str& _Other)const
{
	return false;
}

bool Str::operator<(const Str& _Other)const
{
	return false;
}

bool Str::operator>(const Str& _Other)const
{
	return false;
}

bool Str::operator<=(const Str& _Other)const
{
	return false;
}

bool Str::operator>=(const Str& _Other)const
{
	return false;
}
