#pragma once

struct Node
{
	int Data;
	Node* Next;
};

struct LinkedList
{
	Node* Head;
	int Count;
};

void push(LinkedList* Arr, int _data);

int get(LinkedList* Arr, int index);

void front(LinkedList* Arr, int _data);

void Reverse(LinkedList* _List);