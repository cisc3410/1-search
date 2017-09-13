// author: levitan

#include <fstream>
#include <iostream>
#include <sstream>

#include "NPuzzle.h"

int main(int argc, char* argv[]) {
	char c = argv[2][0];
	if (argc != 3 || !(c=='b' || c=='d' || c=='a' || c=='u')) {
		std::cout << "Usage: ./a.out <FILENAME> <SEARCHTYPE>\n"
				<< "<FILENAME> should be a text file where each line contains a puzzle.\n"
				<< "<SEARCHTYPE> should be 'd' for depth-first search, "
				<< "'b' for breadth-first search, 'a' for A*\n";
		return 0;
	}

	std::ifstream infile(argv[1]);
	std::string line;
	std::ofstream outfile("solutions.out");
	while (getline(infile, line)) {
		NPuzzle np(line);
		outfile << np.solve(c) << "\n";
	}
}
