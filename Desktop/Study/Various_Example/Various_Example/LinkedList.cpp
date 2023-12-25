#include "LinkedList.h"
#include<iostream>

void push(LinkedList* Arr, int _data)
{
	Node* New = (Node*)malloc(sizeof(Node));
	New->Data = _data;
	New->Next = nullptr;

	// �����Ͱ� �ƿ� ������
	if (Arr->Head == 0)
	{
		Arr->Head = New;
	}
	// �����Ͱ� 1�� �̻��϶�
	else
	{
		// 1. ������ ��� ��, ���� ������ ��带 ã�´�
		Node* pNode = Arr->Head;

		while (pNode->Next)
		{
			pNode = pNode->Next;
		}
		// 2 . ã�� ����� Next �� ���� ������ ��带 ����Ų��(����)
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
	// 1. �Էµ� �����͸� ������ ��� 1�� ��ŭ�� �޸𸮸� �����Ҵ� �Ѵ�.
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = _data;

	// 2. ���� ������ ��尡 ���� ó���� �Ǿ�� �ϴϱ�, ����Ʈ�� ��������ͷ� �ش� ��带 ����Ų��.
	NewNode->Next = Arr->Head; 
	Arr->Head = NewNode; 

	// 3. ������ ī��Ʈ ����
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
		// _Node �� ����Ű�� �ִ� ��尡 ���� ���� ������ ����̴�.
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
