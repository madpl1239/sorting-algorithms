/*
 * selection.cpp
 * 
 * Selection sort algorithm.
 * 
 * 09-12-2024 by madpl (or madpl1239)
 */
#include <iostream>
#include "defines.hpp"


void selectionSort(tabInt_t& arr)
{
	int n = arr.size();
	bool to_swap = false;

	for(int i = 0; i < n - 1; ++i)
	{
		// we take the index of this element
		// as the smallest (or as the largest)
		int minIndex = i;
		
		// we are looking for an even smaller index
		// (or even bigger)
		for(int j = i + 1; j < n; ++j)
		{
			// most important operation - comparison
			if(arr[j] < arr[minIndex])
			{
				minIndex = j;
				to_swap = true;
			}
 		}
		
		if(to_swap)
		{
			std::swap(arr[i], arr[minIndex]);
			to_swap = false;
		}
	}
}


int main(void)
{
	try
	{
		readFileToVector("data.txt", data);
	}
	
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << "start sorting...\n";
	selectionSort(data);
	std::cout << "finish sorting...\n ";

	return 0;
}
