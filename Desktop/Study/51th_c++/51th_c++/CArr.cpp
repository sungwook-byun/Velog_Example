#include "CArr.h"

#include <iostream>

CArr::CArr()
	: m_pData(nullptr)
	, m_CurCount(0)
	, m_MaxCount(2)
{
	m_pData = (int*)malloc(sizeof(int) * m_MaxCount);
}

CArr::~CArr()
{
	free(m_pData);
}

void CArr::push_back(int _Data)
{
	// 데이터가 꽉 차있으면, 
	if (m_MaxCount <= m_CurCount)
	{
		// 저장 공간 추가할당
		Realloc();
	}

	m_pData[m_CurCount++] = _Data;
}

void CArr::Realloc()
{
	// 1. 새로운 공간 할당
	m_MaxCount *= 2;
	int* pNew = (int*)malloc(sizeof(int) * m_MaxCount);

	// 2. 기존 데이터 이동
	for (int i = 0; i < m_CurCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간 해제
	free(m_pData);

	// 4. 새로운 공간을 가리킨다.
	m_pData = pNew;
}