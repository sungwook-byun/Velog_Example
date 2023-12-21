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
	// 재귀호출을 멈추기 위한 조건
	if (_Node == nullptr) 
	{
		return;
	}
	// 다음노드가 0이라는건 마지막 노드라는걸 의미하고, 그렇다면 그 노드를 헤드 노드인 시작노드로 설정함
	if (_Node->pNext == nullptr) 
	{
		_List->pHeadNode = _Node;
		return;
	}

	// 재귀함수를 호출함으로써 계속해서 다음 노드로 이동하면서 끝까지 이동함
	// 두번째 값을 불러오고 그 다음 또 호출 된다면 _Node 3번째 값을 불러오는 식으로 계속 호출을 함
	// 하지만 중요한건 위에 조건인 _Node->pNext가 null인지가 중요하기 때문에 그때까지 반복해서 들어감
	Reverse_Re(_Node->pNext, _List);

	// 노드들의 방향이 뒤집힘
	_Node->pNext->pNext = _Node;

	// 현재 노드의 다음을 널로 비워야함 (마지막노드이기 때문)
	_Node->pNext = nullptr;
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