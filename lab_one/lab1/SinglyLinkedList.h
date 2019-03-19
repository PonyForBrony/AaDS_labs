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

	void push_back(const T data);
	void push_front(const T data);
	T pop_back();
	T pop_front();
	void insert(const int index, const T data);
	T at(const int index);
	T remove(const int index);
	void set(const int index, const T data);
	int get_size();
	void clear();
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
	clear();
}

template<class T>
void SinglyLinkedList<T>::push_back(const T data)
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
void SinglyLinkedList<T>::push_front(const T data)
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
		throw out_of_range("List empty");

	T deletedData;
	if (length > 1)
	{
		Node* prevLastNode;
		for (prevLastNode = first; prevLastNode->next->next != nullptr; prevLastNode = prevLastNode->next);
		deletedData = prevLastNode->next->data;
		delete prevLastNode->next;
		prevLastNode->next = nullptr;
	}
	else
	{
		deletedData = first->data;
		delete first;
		first = nullptr;
	}

	length--;

	return deletedData;
}

template<class T>
T SinglyLinkedList<T>::pop_front()
{
	if (isEmpty())
		throw out_of_range("List empty");

	Node* firstNode = first;
	first = first->next;
	T deletedData = firstNode->data;
	delete firstNode;

	length--;

	return deletedData;
}

template<class T>
void SinglyLinkedList<T>::insert(const int index, const T data)
{
	if ((index < 0 || index >= length) && index != 0)
		throw out_of_range("Index is greater than list size");

	if (index == 0)
		push_front(data);
	else
	{
		Node* newNode = new Node(data);

		Node* currNode = first;
		for (int i = 0; i + 1 != index; i++, currNode = currNode->next);

		newNode->next = currNode->next;
		currNode->next = newNode;

		length++;
	}
}

template<class T>
T SinglyLinkedList<T>::at(const int index)
{
	if (index < 0 || index >= length)
		throw out_of_range("Index is greater than list size");

	Node* currNode = first;
	for (int i = 0; i != index; i++, currNode = currNode->next);

	return currNode->data;
}

template<class T>
T SinglyLinkedList<T>::remove(const int index)
{
	if (index < 0 || index >= length)
		throw out_of_range("Index is greater than list size");

	if (index == 0)
		return pop_front();
	else
	{
		Node* currNode = first;
		for (int i = 0; i + 1 != index; i++, currNode = currNode->next);

		Node* nodeToDelete = currNode->next;
		currNode->next = nodeToDelete->next;
		T deletedData = nodeToDelete->data;
		delete nodeToDelete;

		length--;

		return deletedData;
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

	length = 0;
}

template<class T>
void SinglyLinkedList<T>::set(const int index, const T data)
{
	if (index < 0 || index >= length)
		throw out_of_range("Index is greater than list size");

	Node* currNode = first;
	for (int i = 0; i != index; i++, currNode = currNode->next);

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