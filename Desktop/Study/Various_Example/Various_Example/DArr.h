#pragma once


struct DArr
{
	int* pData;     // �����͸� �����ų �� ���� ������ ���� �ּ�
	int  MaxCount;	// ��� ������ �ִ� ���� ����
	int  CurCount;  // ���� ä���� ������ ����
};

void InitDArr(DArr* _pArr);


void PushData(DArr* _pArr, int _Data);


void Realloc(DArr* _pArr);