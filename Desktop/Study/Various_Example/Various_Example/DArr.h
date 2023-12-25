#pragma once


struct DArr
{
	int* pData;     // 데이터를 저장시킬 힙 영역 공간의 시작 주소
	int  MaxCount;	// 허용 가능한 최대 공간 개수
	int  CurCount;  // 현재 채워진 데이터 개수
};

void InitDArr(DArr* _pArr);


void PushData(DArr* _pArr, int _Data);


void Realloc(DArr* _pArr);