#include "Str.h"

#include <iostream>
#include <assert.h>

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
	// 수용 공간을 2배로 확장하기
	m_MaxLength *= 2;

	// 새로운 공간을 만들어낸다.
	wchar_t* pNew = new wchar_t[m_MaxLength + 1];

	// 원래 있던 데이터를 새로운곳으로 옮긴다.
	for (int i = 0; i < m_Length; ++i)
	{
		pNew[i] = m_pStr[i];
	}
	pNew[m_Length] = '\0';

	// 기존 공간을 해제한다.
	delete m_pStr;

	// 새로운 공간을 가리킨다.
	m_pStr = pNew;
}

void Str::operator=(const wchar_t* _str)
{
	// 입력되려는 문자열의 문자 개수(길이) 파악
	int len = 0;
	while ('\0' != _str[len]) { ++len; }

	// 입력되려는 문자열의 길이가 최대 수용개수를 넘어서면 저장 공간 확장
	while (m_MaxLength < len)
	{
		Realloc();
	}

	// 입력 문자열의 값을, 힙 공간으로 하나씩 옮기기
	int i = 0;
	for (; i < len; ++i)
	{
		m_pStr[i] = _str[i];
	}

	// 마지막에 널문자로 막기
	m_pStr[i] = '\0';

	// 문자열 길이 갱신(입력된 문자열 길이로)
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
	// 뒤에 붙을 문자열의 문자 개수(길이) 파악
	int len = 0;
	while ('\0' != _Str[len]) { ++len; }

	// 원래 문자열 길이 + 새로 뒤에 붙을 문자열의 길이가 최대 저장 크기를 벗어나는지 확인
	while (m_MaxLength < m_Length + len)
	{
		Realloc();
	}

	// 뒤에붙을 문자열을 가져오기
	for (int i = 0; i < len; ++i)
	{
		m_pStr[i + m_Length] = _Str[i];
	}

	// 저장하고 있는 문자열 길이 갱신
	m_Length += len;
	m_pStr[m_Length] = '\0';
}

bool Str::operator==(const Str& _Other) const
{
	// 각 객체의 문자열의 길이가 동일하지 않으면 같지 않음
	if (m_Length != _Other.m_Length)
		return false;

	// 모든 문자가 같은지 비교
	for (int i = 0; i < m_Length; ++i)
	{
		// 중간에 하나라도 다르면 두 문자열은 같지 않음
		if (m_pStr[i] != _Other.m_pStr[i])
		{
			return false;
		}
	}

	// 문자열의 길이가 같고, 모든 문자가 동일하면 두 문자열은 같은 문자열이다.
	return true;
}

bool Str::operator!=(const Str& _Other)const
{
	return !((*this) == _Other);
}

bool Str::operator<(const Str& _Other)const
{
	// 비교하려는 두 문자열이 모두 문자가 하나도 없다면 비교할 수 없다.
	assert(m_Length || _Other.m_Length);

	int MinLen = m_Length < _Other.m_Length ? m_Length : _Other.m_Length;

	for (int i = 0; i < MinLen; ++i)
	{
		if (m_pStr[i] < _Other.m_pStr[i])
			return true;
		else if (m_pStr[i] > _Other.m_pStr[i])
			return false;
	}

	// 모든 문자가 동일했다면 문자열이 길이가 더 짧은 문자열이 더 작다.
	if (m_Length < _Other.m_Length)
		return true;
	else
		return false;
}

bool Str::operator >(const Str& _Other)const
{
	// 비교하려는 두 문자열이 모두 문자가 하나도 없다면 비교할 수 없다.
	assert(m_Length || _Other.m_Length);

	int MinLen = m_Length < _Other.m_Length ? m_Length : _Other.m_Length;

	for (int i = 0; i < MinLen; ++i)
	{
		if (m_pStr[i] > _Other.m_pStr[i])
			return true;
		else if (m_pStr[i] < _Other.m_pStr[i])
			return false;
	}

	// 모든 문자가 동일했다면 문자열이 길이가 더 짧은 문자열이 더 작다.
	if (m_Length > _Other.m_Length)
		return true;
	else
		return false;
}

bool Str::operator<=(const Str& _Other)const
{
	// 비교하려는 두 문자열이 모두 문자가 하나도 없다면 비교할 수 없다.
	if (!(m_Length || _Other.m_Length))
		return true;

	int MinLen = m_Length < _Other.m_Length ? m_Length : _Other.m_Length;

	for (int i = 0; i < MinLen; ++i)
	{
		if (m_pStr[i] < _Other.m_pStr[i])
			return true;
		else if (m_pStr[i] > _Other.m_pStr[i])
			return false;
	}

	// 모든 문자가 동일했다면 문자열이 길이가 더 짧은 문자열이 더 작다.
	if (m_Length <= _Other.m_Length)
		return true;
	else
		return false;
}

bool Str::operator>=(const Str& _Other)const
{
	// 비교하려는 두 문자열이 모두 문자가 하나도 없다면 비교할 수 없다.
	if (!(m_Length || _Other.m_Length))
		return true;

	int MinLen = m_Length < _Other.m_Length ? m_Length : _Other.m_Length;

	for (int i = 0; i < MinLen; ++i)
	{
		if (m_pStr[i] > _Other.m_pStr[i])
			return true;
		else if (m_pStr[i] < _Other.m_pStr[i])
			return false;
	}

	// 모든 문자가 동일했다면 문자열이 길이가 더 짧은 문자열이 더 작다.
	if (m_Length >= _Other.m_Length)
		return true;
	else
		return false;
}
