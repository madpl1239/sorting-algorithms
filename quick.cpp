/*
 * quick.cpp
 * 
 * Quick sort algorithm.
 * 
 * 09-12-2024 by madpl
 */
#include <iostream>
#include "defines.hpp"


// helper function to split the array into two parts
int partition(tabInt_t& arr, int low, int high)
{
	int pivot = arr[high]; // selecting the last item as pivot
	int i = low - 1;	   // index of smaller element

	for(int j = low; j < high; ++j)
	{
		if(arr[j] < pivot)
		{
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	
	// placing the pivot in the right place
	std::swap(arr[i + 1], arr[high]);
	
	// return pivot index
	return i + 1;
}


void quickSort(tabInt_t& arr, int low, int high)
{
	if(low < high)
	{
		// table split
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
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
	quickSort(data, 0, data.size() - 1);
	std::cout << "finish sorting...\n ";
	
	return 0;
}
