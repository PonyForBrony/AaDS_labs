#include "stdafx.h"
#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList<int> list = SinglyLinkedList<int>();

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	cout << list;
	getchar();
	return 0;
}