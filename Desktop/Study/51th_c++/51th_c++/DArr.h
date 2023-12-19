#pragma once

// 스택, 데이터, ROM, 힙


// 동적배열 역할을 수행할 수 있는 자료형
struct DArr
{
	// 동적 배열로서의 기능을 수행하기위해 필요한 맴버
	int* pData;		// 데이터를 저장시킬 힙 영역 공간의 시작 주소
	int  MaxCount;	// 허용 가능한 최대 공간 개수
	int  CurCount;	// 현재 채워진 데이터 개수
};

void InitDArr(DArr* _pArr);

void PushData(DArr* _pArr, int _Data);

int GetData(DArr* _pArr, int _Idx);