/*
 * defines.hpp
 * 
 * 09-12-2024 by madpl (aka madpl1239)
 */
#pragma once

#include <fstream>
#include <sstream>
#include <vector>


using tabInt_t = std::vector<int>;
inline tabInt_t data{};


inline void printArray(const tabInt_t& arr)
{
	for(int num : arr)
		std::cout << num << " ";

	std::cout << std::endl;
}


void readFileToVector(const std::string& fileName, tabInt_t& data)
{
	std::ifstream inFile(fileName);
	if(!inFile)
		throw std::runtime_error("Error: Failed to open file " + fileName);

	std::string line;
	while(getline(inFile, line))
	{
		// stream for line analysis
		std::stringstream ss(line);
		int number;
		
		// load space separated numbers
		while(ss >> number)
			data.push_back(number);
	}

	inFile.close();
}
