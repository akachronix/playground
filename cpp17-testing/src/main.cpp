#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "VectorStuff.hpp"

template <typename Value>
void print(const Value x)
{
	std::cout << x << '\n';
}

static std::vector<std::string> getFileContents(const char* _fileName)
{
	std::vector<std::string> fileContents;
	std::ifstream file(_fileName);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			fileContents.push_back(line);
	}

	file.close();
	return fileContents;
}

int main(int argc, const char* argv[])
{
	std::ofstream file("test.txt");
	file << "hello, world!\n";
	file.close();

	const std::vector<std::string> fileContents = getFileContents("test.txt");
	forInVector(fileContents, &print);

	std::vector<std::string> fileContentsCopy;
	forInVector(fileContents, &copyVector, &fileContentsCopy);
	forInVector(fileContentsCopy, &print);

	return 0;
}
