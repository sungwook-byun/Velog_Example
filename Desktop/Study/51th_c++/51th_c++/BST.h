#pragma once
// ��Ʈ�� �����ؼ� ù��Ʈ�� �� �� ������ ���� ũ�� ���������� ���̴°� �ݺ���
// ��Ʈ ��� : �θ���
// �ܸ� ��� : �ڽ��� ���� ���(Leaf Node)

// Binary Search Tree(BST)

template<typename T>
struct BSTNode
{
	T	Data;

	BSTNode* pParent;
	BSTNode* pLeftChild;
	BSTNode* pRightChild;
};