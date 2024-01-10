#pragma once

class Str
{
private:
	wchar_t*	m_pStr;			// �����Ҵ��� ���ڿ��� �ּ�
	int			m_MaxLength;	// ���ڿ��� ������ �� �ִ� �ִ� ����
	int			m_Length;		// ���ڿ��� ����

public:
	int Length() { return m_Length; }
	const wchar_t* GetStr() { return m_pStr; }

private:
	void Realloc();

	// ������ �����ε�
public:
	void operator = (const wchar_t* _str);
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
	~Str();
};

