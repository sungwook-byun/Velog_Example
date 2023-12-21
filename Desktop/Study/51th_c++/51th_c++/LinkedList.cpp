#include "LinkedList.h"

#include <iostream>
#include <assert.h>

void PushBack(LinkedList* _List, int _Data)
{
	// �Էµ� �����͸� ������ ���ο� ��带 �Ҵ�ް�, �Էµ� �����͸� ���ȿ� �����Ѵ�.
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;
	pNewNode->pNext = nullptr;

	// ���� ����Ʈ�� �ԷµǴ� �����Ͱ� ó���̶��
	if (nullptr == _List->pHeadNode)
	{
		_List->pHeadNode = pNewNode;
	}

	// ����Ʈ�� �Էµ� �����Ͱ� 1�� �̻��̶��
	else
	{
		// 1. ����Ʈ�� ������ ��� ��, ���� ������ ��带 ã�´�.
		Node* pNode = _List->pHeadNode;

		/*while (true)
		{
			pNode = pNode->pNext;

			if (nullptr == pNode->pNext)
				break;
		}*/

		while (pNode->pNext) { pNode = pNode->pNext; }

		// 2 . ã�� ����� pNext �� ���� ������ ��带 ����Ų��(����)
		pNode->pNext = pNewNode;
	}

	// ������ ī��Ʈ�� 1 ������Ų��.
	_List->CurCount++;
}

int GetData(LinkedList* _List, int _Idx)
{
	// ����Ʈ�� �Էµ� ������ ���� �̻��� �ε����� ������ ���
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
	// 1. �Էµ� �����͸� ������ ��� 1�� ��ŭ�� �޸𸮸� �����Ҵ� �Ѵ�.
	//    �Էµ� �����͸� �ش� ���ȿ� �����Ѵ�.
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->Data = _Data;

	// 2. ���� ������ ��尡 ���� ó���� �Ǿ�� �ϴϱ�, ����Ʈ�� ��������ͷ� �ش� ��带 ����Ų��.
	pNewNode->pNext = _List->pHeadNode;
	_List->pHeadNode = pNewNode;

	// 3. ������ ī��Ʈ ����
	_List->CurCount++;
}


// ��� �Լ�
void Reverse_Re(Node* _Node, LinkedList* _List)
{
	// ���ȣ���� ���߱� ���� ����
	if (_Node == nullptr) 
	{
		return;
	}
	// ������尡 0�̶�°� ������ ����°� �ǹ��ϰ�, �׷��ٸ� �� ��带 ��� ����� ���۳��� ������
	if (_Node->pNext == nullptr) 
	{
		_List->pHeadNode = _Node;
		return;
	}

	// ����Լ��� ȣ�������ν� ����ؼ� ���� ���� �̵��ϸ鼭 ������ �̵���
	// �ι�° ���� �ҷ����� �� ���� �� ȣ�� �ȴٸ� _Node 3��° ���� �ҷ����� ������ ��� ȣ���� ��
	// ������ �߿��Ѱ� ���� ������ _Node->pNext�� null������ �߿��ϱ� ������ �׶����� �ݺ��ؼ� ��
	Reverse_Re(_Node->pNext, _List);

	// ������ ������ ������
	_Node->pNext->pNext = _Node;

	// ���� ����� ������ �η� ������� (����������̱� ����)
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