/*
 * insertion.cpp
 * 
 * Insertion sort algorithm.
 * 
 * 09-12-2024 by madpl
 */
#include <iostream>
#include <vector>
#include "defines.hpp"


void insertionSort(tabInt_t& arr)
{
	int n = arr.size();

	for(int i = 1; i < n; ++i)
	{
		// item to insert
		int key = arr[i];
		int j = i - 1;
		
		// moving elements larger than `key` to the right
		while(j >= 0 and arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		
		// inserting the `key` element into the appropriate place
		arr[j + 1] = key;
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
	insertionSort(data);
	std::cout << "finish sorting...\n ";

	return 0;
}
