#pragma once

class Str
{
private:
	wchar_t* m_pStr;			// 동적할당한 문자열의 주소
	int			m_MaxLength;	// 문자열을 저장할 수 있는 최대 길이
	int			m_Length;		// 문자열의 길이

public:
	int Length() { return m_Length; }
	const wchar_t* GetStr() { return m_pStr; }

private:
	void Realloc();

	// 연산자 오버로딩
public:
	void operator = (const wchar_t* _str);

	template<int Size>
	void operator =(const wchar_t(&_buffer)[Size])
	{
		(*this) = _buffer;
	}

	Str operator+ (const Str& _string);
	Str operator+ (const char* _Str);
	void operator +=(const wchar_t* _Str);

	bool operator ==(const Str& _Other) const;
	bool operator !=(const Str& _Other) const;
	bool operator <(const Str& _Other) const;
	bool operator >(const Str& _Other) const;
	bool operator <=(const Str& _Other) const;
	bool operator >=(const Str& _Other) const;


public:
	Str();
	Str(const wchar_t* _str);

	template<int Size>
	Str(const wchar_t(&_buffer)[Size])
		: m_pStr(nullptr)
		, m_MaxLength(10)
		, m_Length(0)
	{
		m_pStr = new wchar_t[m_MaxLength + 1];
		(*this) = _buffer;
	}

	~Str();
};

