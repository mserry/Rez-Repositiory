#include "TheoryTestFunctions.h"

bool CheckForDuplicates(int* pArray, const int size)
{
	// O(N^2)
	for(int i = 0; i < size; ++i)
	{
		for(int j = size - 1; j >= 0; --j)
		{
			if(pArray[i] == pArray[j])
			{
				return true;
			}
		}
	}

	return false;
}
