#include "TheoryTestFunctions.h"

#include <iostream>
#include <cassert>
#include <vector>
#include <map>

void Test_CheckForDuplicates()
{
	int* testArray = nullptr;

	testArray[0] = 3;
	testArray[1] = 6;
	testArray[2] = 3;
	testArray[3] = 1;
	testArray[4] = 7;
	testArray[5] = 8;

	CheckForDuplicates(testArray, 6);
}

void Test_FizzBuzz()
{
	FizzBuzz(14);
}

void Test_FindIndex()
{
	int* pSortedArray = nullptr;

	pSortedArray[0] = 1;
	pSortedArray[1] = 2;
	pSortedArray[2] = 3;
	pSortedArray[3] = 4;
	pSortedArray[4] = 5;

	FindIndex(pSortedArray, 5, 2);
}

bool IsMultiple(int number, int factor, int factor2)
{
	return number % factor == 0 && number % factor2 == 0;
}

bool CheckForDuplicates(int* pArray, int size)
{
	for(int i = 0; i < size; ++i)
	{
		for(int j = 0; j < size; ++j)
		{
			if(i != j && pArray[i] == pArray[j])
			{
				return true;
			}
		}
	}

	return false;
}

int FindIndex(const int* pArray, int size, int valueToFind)
{
	assert(size > 2);
	assert(pArray != nullptr);

	int start = 0;
	int end = size - 1;

	for(int i = 0; i < size; ++i)
	{
		int mid = start + (end - start) / 2;

		if(end < start)
		{
			return end;
		}

		if(pArray[mid] == valueToFind)
		{
			return mid;
		}

		if(pArray[mid] > valueToFind)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
}

void FizzBuzz(int maxValue)
{
	for(int i = 0; i < maxValue; ++i)
	{
		std::cout << GetPrintMessage(i);
	}
}

std::string GetPrintMessage(int number)
{
	if(IsMultiple(number, 3))
	{
		return "Fizz";
	}
	else if (IsMultiple(number, 4))
	{
		return "Buzz";
	}
	else if (IsMultiple(number, 4) && IsMultiple(number, 3))
	{
		return "FizzBuzz";
	}
	else
	{
		return "Number is: " + number;
	}
}

bool IsMultiple(int number, int factor)
{
	return number % factor == 0;
}

