#pragma once

// ����, ������, ROM, ��


// �����迭 ������ ������ �� �ִ� �ڷ���
struct DArr
{
	// ���� �迭�μ��� ����� �����ϱ����� �ʿ��� �ɹ�
	int* pData;		// �����͸� �����ų �� ���� ������ ���� �ּ�
	int  MaxCount;	// ��� ������ �ִ� ���� ����
	int  CurCount;	// ���� ä���� ������ ����
};

void InitDArr(DArr* _pArr);

void PushData(DArr* _pArr, int _Data);

int GetData(DArr* _pArr, int _Idx);