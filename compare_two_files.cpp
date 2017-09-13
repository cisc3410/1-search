// author: levitan

#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	if (argc != 3) {
		std::cout << "USAGE: ./a.out <GENERATED SOLUTION FILE> <CORRECT SOLUTION FILE>\n";
		return 1;
	}

	std::ifstream checkfile(argv[1]), correctfile(argv[2]);
	std::string checksolution, correctsolution;
	std::vector<int> correct, incorrect;
	int i = 0;
	while (std::getline(checkfile, checksolution) && std::getline(correctfile, correctsolution)) {
		std::cout << checksolution << ", " << correctsolution << std::endl;
		if (checksolution == correctsolution) correct.push_back(i);
		else incorrect.push_back(i);
		i++;
	}

	std::cout << "Correct: ";
	for (int i : correct) std::cout << i << " ";
	std::cout << std::endl;

	std::cout << "Incorrect: ";
	for (int i : incorrect) std::cout << i << " ";
	std::cout << std::endl;

	return incorrect.size();
}
