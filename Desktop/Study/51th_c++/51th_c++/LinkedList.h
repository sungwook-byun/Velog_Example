#pragma once

// 연결형 리스트
struct Node
{
	int		Data;
	Node* pNext;
};

struct LinkedList
{
	Node* pHeadNode;
	int		CurCount;
};

void PushBack(LinkedList* _List, int _Data);
int GetData(LinkedList* _List, int _Idx);

void Reverse(LinkedList* _List);



void PushFront(LinkedList* _List, int _Data);

