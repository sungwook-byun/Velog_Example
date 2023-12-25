#include "LinkedList.h"
#include<iostream>

void push(LinkedList* Arr, int _data)
{
	Node* New = (Node*)malloc(sizeof(Node));
	New->Data = _data;
	New->Next = nullptr;

	// 데이터가 아예 없을떄
	if (Arr->Head == 0)
	{
		Arr->Head = New;
	}
	// 데이터가 1개 이상일때
	else
	{
		// 1. 보유한 노드 중, 가장 마지막 노드를 찾는다
		Node* pNode = Arr->Head;

		while (pNode->Next)
		{
			pNode = pNode->Next;
		}
		// 2 . 찾은 노드의 Next 를 현재 생성된 노드를 가리킨다(연결)
		pNode->Next = New;
	}
	Arr->Count++;
}

int get(LinkedList* Arr, int index)
{
	Node* Znode = Arr->Head;
	
	for (int i = 0; i < index; ++i)
	{
		Znode = Znode->Next;
	}

	return Znode->Data;
}

void front(LinkedList* Arr, int _data)
{
	// 1. 입력된 데이터를 저장할 노드 1개 만큼의 메모리를 동적할당 한다.
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = _data;

	// 2. 새로 생성된 노드가 가정 처음이 되어야 하니까, 리스트가 헤드포인터로 해당 노드를 가리킨다.
	NewNode->Next = Arr->Head; 
	Arr->Head = NewNode; 

	// 3. 데이터 카운트 증가
	Arr->Count++;

}

void Reverse_Re(Node* _Node, LinkedList* _List)
{
	if (nullptr != _Node->Next)
	{
		Reverse_Re(_Node->Next, _List);

		_Node->Next->Next = _Node;
	}
	else
	{
		// _Node 가 가리키고 있는 노드가 현재 가장 마지막 노드이다.
		_List->Head = _Node;
	}
}

void Reverse(LinkedList* _List)
{
	Reverse_Re(_List->Head, _List);

	Node* pNode = _List->Head;
	while (pNode->Next)
	{
		pNode = pNode->Next;
	}	
	pNode->Next = nullptr;
}
