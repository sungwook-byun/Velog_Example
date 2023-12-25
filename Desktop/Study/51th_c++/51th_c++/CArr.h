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

	// 헤더에 맴버함수를 구현 한 경우
	// 인라인 함수로 처리	
	// 헤더에 실제 구현을 함으로써, 호출시 해당 구현을 그대로 복사한다.
	// 매크로 함수와 유사, 함수 호출 시 별도의 스택 생성 해제 비용이 없다.

	// 인라인 함수를 남발하는 경우 발생하는 문제.
	// 함수 구문이 여기저기 호출하는 곳마다 복사되어서 코드의 양이 엄청나게 늘어날 수 있다.

	// 인라인 처리를 할 함수들의 특징.
	// 구문이 짧다(기능이 간단한다, Get, Set 종류의 함수)
	// 자주 호출 되는 함수
public:
	int size() { return m_CurCount; }
	int capacity() { return m_MaxCount; }
	int at(int _Idx) { return m_pData[_Idx]; }

	// 반환타입을 참조형태로 반환, 반환된 값을 수정하면 원본값이 수정되는 개념
	int& operator[](int _Idx) 
	{ 
		return m_pData[_Idx];
	}


public:
	CArr();
	~CArr();
};