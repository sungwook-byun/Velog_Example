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
	// �����Ͱ� �� ��������, 
	if (m_MaxCount <= m_CurCount)
	{
		// ���� ���� �߰��Ҵ�
		Realloc();
	}

	m_pData[m_CurCount++] = _Data;
}

void CArr::Realloc()
{
	// 1. ���ο� ���� �Ҵ�
	m_MaxCount *= 2;
	int* pNew = (int*)malloc(sizeof(int) * m_MaxCount);

	// 2. ���� ������ �̵�
	for (int i = 0; i < m_CurCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ���� ����
	free(m_pData);

	// 4. ���ο� ������ ����Ų��.
	m_pData = pNew;
}