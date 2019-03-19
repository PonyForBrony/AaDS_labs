#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab1/SinglyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(Singly_Linked_List)
{
public:
	SinglyLinkedList<int> * list_int;
	SinglyLinkedList<char> * list_char;
	// before each test
	TEST_METHOD_INITIALIZE(setUp)
	{
		list_int = new SinglyLinkedList<int>();
		list_char = new SinglyLinkedList<char>();
	}
	// after each test
	TEST_METHOD_CLEANUP(cleanUp)
	{
		delete list_int;
		delete list_char;
	}

	TEST_METHOD(isEmpty_empty_list)
	{
		Assert::IsTrue(list_int->isEmpty());
	}

	TEST_METHOD(isEmpty_not_empty_list)
	{
		list_int->push_back(0);
		Assert::IsFalse(list_int->isEmpty());
	}

	TEST_METHOD(clear_not_empty_list)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->clear();
		Assert::IsTrue(list_int->isEmpty());
	}

	TEST_METHOD(clear_empty_list)
	{
		list_int->clear();
		Assert::IsTrue(list_int->isEmpty());
	}

	TEST_METHOD(get_size_not_empty_list)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->push_back(3);
		Assert::AreEqual(list_int->get_size(), 4);
	}

	TEST_METHOD(push_back_int)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->push_back(3);
		Assert::AreEqual(list_int->at(0), 0);
		Assert::AreEqual(list_int->at(1), 1);
		Assert::AreEqual(list_int->at(2), 2);
		Assert::AreEqual(list_int->at(3), 3);
	}

	TEST_METHOD(push_back_char)
	{
		list_char->push_back('0');
		list_char->push_back('1');
		list_char->push_back('2');
		list_char->push_back('3');
		Assert::AreEqual(list_char->at(0), '0');
		Assert::AreEqual(list_char->at(1), '1');
		Assert::AreEqual(list_char->at(2), '2');
		Assert::AreEqual(list_char->at(3), '3');
	}

	TEST_METHOD(push_front_int)
	{
		list_int->push_front(0);
		list_int->push_front(1);
		list_int->push_front(2);
		list_int->push_front(3);
		Assert::AreEqual(list_int->at(0), 3);
		Assert::AreEqual(list_int->at(1), 2);
		Assert::AreEqual(list_int->at(2), 1);
		Assert::AreEqual(list_int->at(3), 0);
	}

	TEST_METHOD(push_front_char)
	{
		list_char->push_front('0');
		list_char->push_front('1');
		list_char->push_front('2');
		list_char->push_front('3');
		Assert::AreEqual(list_char->at(0), '3');
		Assert::AreEqual(list_char->at(1), '2');
		Assert::AreEqual(list_char->at(2), '1');
		Assert::AreEqual(list_char->at(3), '0');
	}

	TEST_METHOD(pop_back_int)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->push_back(3);
		list_int->pop_back();
		Assert::AreEqual(list_int->get_size(), 3);
		Assert::AreEqual(list_int->at(0), 0);
		Assert::AreEqual(list_int->at(1), 1);
		Assert::AreEqual(list_int->at(2), 2);
	}

	TEST_METHOD(pop_back_char)
	{
		list_char->push_back('0');
		list_char->push_back('1');
		list_char->push_back('2');
		list_char->push_back('3');
		list_char->pop_back();
		Assert::AreEqual(list_char->get_size(), 3);
		Assert::AreEqual(list_char->at(0), '0');
		Assert::AreEqual(list_char->at(1), '1');
		Assert::AreEqual(list_char->at(2), '2');
	}

	TEST_METHOD(pop_front_int)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->push_back(3);
		list_int->pop_front();
		Assert::AreEqual(list_int->get_size(), 3);
		Assert::AreEqual(list_int->at(0), 1);
		Assert::AreEqual(list_int->at(1), 2);
		Assert::AreEqual(list_int->at(2), 3);
	}

	TEST_METHOD(pop_front_char)
	{
		list_char->push_back('0');
		list_char->push_back('1');
		list_char->push_back('2');
		list_char->push_back('3');
		list_char->pop_front();
		Assert::AreEqual(list_char->get_size(), 3);
		Assert::AreEqual(list_char->at(0), '1');
		Assert::AreEqual(list_char->at(1), '2');
		Assert::AreEqual(list_char->at(2), '3');
	}

	TEST_METHOD(insert_not_empty_list)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->insert(2, 10);
		Assert::AreEqual(list_int->at(0), 0);
		Assert::AreEqual(list_int->at(1), 1);
		Assert::AreEqual(list_int->at(2), 10);
		Assert::AreEqual(list_int->at(3), 2);
	}

	TEST_METHOD(insert_empty_list)
	{
		list_int->insert(0, 10);
		Assert::AreEqual(list_int->at(0), 10);
	}

	TEST_METHOD(insert_incorrect_index)
	{
		try
		{
			list_int->insert(-1, 10);
		}
		catch (out_of_range e)
		{
			Assert::AreEqual("Index is greater than list size", e.what());
		}
	}

	TEST_METHOD(at_correct_index)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		Assert::AreEqual(list_int->at(1), 1);
	}

	TEST_METHOD(at_incorrect_index)
	{
		try {
			list_int->at(-1);
		}
		catch (std::out_of_range e) {
			Assert::AreEqual("Index is greater than list size", e.what());
		}
	}

	TEST_METHOD(remove_correct_index)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		Assert::AreEqual(list_int->remove(1), 1);
		Assert::AreEqual(list_int->get_size(), 2);
		Assert::AreEqual(list_int->at(0), 0);
		Assert::AreEqual(list_int->at(1), 2);
	}

	TEST_METHOD(remove_incorrect_index)
	{
		try {
			list_int->at(-1);
		}
		catch (std::out_of_range e) {
			Assert::AreEqual("Index is greater than list size", e.what());
		}
	}
	
	TEST_METHOD(set_correct_index)
	{
		list_int->push_back(0);
		list_int->push_back(1);
		list_int->push_back(2);
		list_int->set(1, 10);
		Assert::AreEqual(list_int->get_size(), 3);
		Assert::AreEqual(list_int->at(0), 0);
		Assert::AreEqual(list_int->at(1), 10);
		Assert::AreEqual(list_int->at(2), 2);
	}

	TEST_METHOD(set_incorrect_index)
	{
		try {
			list_int->set(-1, 10);
		}
		catch (std::out_of_range e) {
			Assert::AreEqual("Index is greater than list size", e.what());
		}
	}
};