/*
 * merge.cpp
 * 
 * Merge sort algorithm.
 * 
 * 09-12-2024 by madpl
 */
#include <iostream>
#include "defines.hpp"


// function to merge two sorted subarrays
void merge(tabInt_t& arr, int left, int mid, int right)
{
	int n1 = mid - left + 1;	// size of left subarray
	int n2 = right - mid;		// size of right subarray

	// we create temporary arrays
	tabInt_t leftArr(n1), rightArr(n2);

	// we copying data to temp arrays
	for(int i = 0; i < n1; ++i)
		leftArr[i] = arr[left + i];
	
	for(int i = 0; i < n2; ++i)
		rightArr[i] = arr[mid + 1 + i];

	// initial indices in subarrays
	// and the result table
	int i = 0, j = 0, k = left;

	// merging subarrays
	while(i < n1 && j < n2)
	{
		if(leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		
		k++;
	}

	// we copy the remaining elements
	// from the left subarray (if any)
	while(i < n1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	// we copy the remaining elements 
	// from the right subtarray (if any)
	while(j < n2)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}
}


void mergeSort(tabInt_t& arr, int left, int right)
{
	if(left < right)
	{
		// origin
		int mid = left + (right - left) / 2;
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		
		merge(arr, left, mid, right);
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
	mergeSort(data, 0, data.size() - 1);
	std::cout << "finish sorting...\n ";

	return 0;
}
