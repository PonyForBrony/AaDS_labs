#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab1/SinglyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(Array_tests)
{
public:

	TEST_METHOD(is_equal_test)
	{
		int array1[5] = { 1, 2, 3, 4, 5 };
		int array2[5] = { 1, 2, 5, 4, 5 };
		Assert::IsFalse(is_equal(array1, 5, array2, 5));
	}

};