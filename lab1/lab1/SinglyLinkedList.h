#pragma once

#include "stdafx.h"

template <class T> class SinglyLinkedList
{
	struct Node
	{
		Node* next;
		T data;

		Node(T data) : next(nullptr), data(data)
		{}
	};

	Node * first;
	int length;

public:
	SinglyLinkedList();
	~SinglyLinkedList();

	void push_back(T data);
	void push_front(T data);
	T pop_back();
	T pop_front();
	void insert(int index, T data);
	T at(int index);
	T remove(int index);
	int get_size();
	void clear();
	void set(int index, T data);
	bool isEmpty();

	template <class U>
	friend ostream & operator << (ostream &out, const SinglyLinkedList<U> &list);
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	first = nullptr;
	length = 0;
}

template<class T>
inline SinglyLinkedList<T>::~SinglyLinkedList()
{
}

template<class T>
void SinglyLinkedList<T>::push_back(T data)
{
	Node* newNode = new Node(data);

	if (!isEmpty())
	{
		Node* lastNode;
		for (lastNode = first; lastNode->next != nullptr; lastNode = lastNode->next);

		lastNode->next = newNode;
	}
	else
		first = newNode;

	length++;
}

template<class T>
void SinglyLinkedList<T>::push_front(T data)
{
	Node* newNode = new Node(data);
	newNode->next = first;
	first = newNode;

	length++;
}

template<class T>
T SinglyLinkedList<T>::pop_back()
{
	if (isEmpty())
		throw out_of_range("");

	if (length > 1)
	{
		Node* prevLastNode;
		for (prevLastNode = first; prevLastNode->next->next != nullptr; prevLastNode = prevLastNode->next);
		delete prevLastNode->next;
		prevLastNode->next = nullptr;
	}
	else
	{
		delete first;
		first = nullptr;
	}

	length--;
}

template<class T>
T SinglyLinkedList<T>::pop_front()
{
	if (isEmpty())
		throw out_of_range("");

	Node* firstNode = first;
	first = first->next;
	delete firstNode;

	length--;
}

template<class T>
void SinglyLinkedList<T>::insert(int index, T data)
{
	if ((index < 0 || index >= length) && index != 0)
		throw out_of_range("");

	if (index == 0)
		push_front(data);
	else
	{
		Node* newNode = new Node(data);

		Node* currNode;
		for (int i = 0, currNode = first; i + 1 != index; i++, currNode = currNode->next);

		newNode->next = currNode->next;
		currNode->next = newNode;

		length++;
	}
}

template<class T>
T SinglyLinkedList<T>::at(int index)
{
	if (index < 0 || index >= length)
		throw out_of_range("");

	Node* currNode;
	for (int i = 0, currNode = first; i != index; i++, currNode = currNode->next);

	return currNode->data;
}

template<class T>
T SinglyLinkedList<T>::remove(int index)
{
	if (index < 0 || index >= length)
		throw out_of_range("");

	if (index == 0)
		return pop_front();
	else
	{
		Node* currNode;
		for (int i = 0, currNode = first; i + 1 != index; i++, currNode = currNode->next);

		Node* nodeToDelete = currNode->next;
		currNode->next = nodeToDelete->next;
		delete nodeToDelete;

		length--;
	}
}

template<class T>
int SinglyLinkedList<T>::get_size()
{
	return length;
}

template<class T>
void SinglyLinkedList<T>::clear()
{
	if (isEmpty())
		return;

	Node* currNode = first;
	do
	{
		Node *nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	} while (currNode != nullptr);
}

template<class T>
void SinglyLinkedList<T>::set(int index, T data)
{
	if (index < 0 || index >= length)
		throw out_of_range("");

	Node* currNode;
	for (int i = 0, currNode = first; i != index; i++, currNode = currNode->next);

	currNode->data = data;
}

template<class T>
bool SinglyLinkedList<T>::isEmpty()
{
	return length == 0;
}

template <class T>
ostream & operator << (ostream &out, const SinglyLinkedList<T> &list)
{
	out << "[";
	for (SinglyLinkedList<T>::Node* currNode = list.first; currNode != nullptr; currNode = currNode->next)
	{
		out << currNode->data;
		if (currNode->next != nullptr)
			out << ", ";
	}
	out << "]";

	return out;
}