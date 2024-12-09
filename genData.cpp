/*
 * genData.cpp
 * 
 * The code generates a file of 10000 integers.
 * 
 * 09-12-2024 by madpl (or madpl1239)
 */
#include <iostream>
#include <fstream>
#include <random>


int main(void)
{
	const std::string fileName = "data.txt";

	std::ofstream outFile(fileName);
	if(!outFile)
	{
		std::cerr << "Error: Failed to create file " << fileName << std::endl;
	
		return -1;
	}

	std::random_device rd;
	
	// engine Mersenne Twister
	std::mt19937 gen(rd());
	
	std::uniform_int_distribution<> dist(1, 10000);

	const int count = 10000;
	for(int i = 0; i < count; ++i)
	{
		outFile << dist(gen);
		
		if(i < count - 1)
			outFile << " ";
	}

	outFile.close();
	
	std::cout << "done.\n";

	return 0;
}
