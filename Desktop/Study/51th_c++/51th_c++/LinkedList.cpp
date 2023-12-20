#include "LinkedList.h"

#include <iostream>
#include <assert.h>

void PushBack(LinkedList* _List, int _Data)
{
	// 입력된 데이터를 저장할 새로운 노드를 할당받고, 입력된 데이터를 노드안에 복사한다.
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;
	pNewNode->pNext = nullptr;

	// 만약 리스트에 입력되는 데이터가 처음이라면
	if (nullptr == _List->pHeadNode)
	{
		_List->pHeadNode = pNewNode;
	}

	// 리스트에 입력된 데이터가 1개 이상이라면
	else
	{
		// 1. 리스트가 보유한 노드 중, 가장 마지막 노드를 찾는다.
		Node* pNode = _List->pHeadNode;

		/*while (true)
		{
			pNode = pNode->pNext;

			if (nullptr == pNode->pNext)
				break;
		}*/

		while (pNode->pNext) { pNode = pNode->pNext; }

		// 2 . 찾은 노드의 pNext 를 현재 생성된 노드를 가리킨다(연결)
		pNode->pNext = pNewNode;
	}

	// 데이터 카운트를 1 증가시킨다.
	_List->CurCount++;
}

int GetData(LinkedList* _List, int _Idx)
{
	// 리스트에 입력된 데이터 개수 이상의 인덱스를 지정한 경우
	assert(!(_List->CurCount <= _Idx));

	Node* pNode = _List->pHeadNode;

	for (int i = 0; i < _Idx; ++i)
	{
		pNode = pNode->pNext;
	}

	return pNode->Data;
}

void PushFront(LinkedList* _List, int _Data)
{
	// 1. 입력된 데이터를 저장할 노드 1개 만큼의 메모리를 동적할당 한다.
	//    입력된 데이터를 해당 노드안에 복사한다.
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;

	// 2. 새로 생성된 노드가 가정 처음이 되어야 하니까, 리스트가 헤드포인터로 해당 노드를 가리킨다.
	pNewNode->pNext = _List->pHeadNode;
	_List->pHeadNode = pNewNode;

	// 3. 데이터 카운트 증가
	_List->CurCount++;
}


// 재귀 함수
void Reverse_Re(Node* _Node, LinkedList* _List)
{
	if (nullptr != _Node->pNext)
	{
		bool bHead = false;
		if (_Node == _List->pHeadNode)
			bHead = true;

		Reverse_Re(_Node->pNext, _List);

		_Node->pNext->pNext = _Node;

		if (bHead)
			_Node->pNext = nullptr;
	}
	else
	{
		// _Node 가 가리키고 있는 노드가 현재 가장 마지막 노드이다.
		_List->pHeadNode = _Node;
	}
}


void Reverse(LinkedList* _List)
{
	Reverse_Re(_List->pHeadNode, _List);

	//Node* pNode = _List->pHeadNode;
	//while (pNode->pNext)
	//{
	//	pNode = pNode->pNext;
	//}	
	//pNode->pNext = nullptr;
}