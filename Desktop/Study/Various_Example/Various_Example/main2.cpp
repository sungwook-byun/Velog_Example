#include<iostream>

#include "LinkedList.h"

int main()
{
	int data = 0;

	LinkedList list = {};
	
	push(&list, 10);
	push(&list, 20);
	push(&list, 30);

	data = get(&list, 0);
	data = get(&list, 1);
	data = get(&list, 2);

	Reverse(&list);

	data = get(&list, 0);
	data = get(&list, 1);
	data = get(&list, 2);

	return 0;
}