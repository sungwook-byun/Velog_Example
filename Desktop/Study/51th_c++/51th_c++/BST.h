#pragma once
// 루트로 진입해서 첫루트랑 비교 후 작으면 왼쪽 크면 오른쪽으로 놓이는게 반복됨
// 루트 노드 : 부모노드
// 단말 노드 : 자식이 없는 노드(Leaf Node)

// Binary Search Tree(BST)

template<typename T>
struct BSTNode
{
	T	Data;

	BSTNode* pParent;
	BSTNode* pLeftChild;
	BSTNode* pRightChild;
};