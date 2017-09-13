// author: levitan

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "Problem.h"

struct NPuzzleState {
	std::vector<std::vector<int>> board;
	int emptyi, emptyj, size;
	std::vector<int> operator[](int i) { return board[i]; }

	NPuzzleState(const std::string& str) {
		// split string into vector by whitespace
		int n;
		std::vector<int> v;
		std::stringstream iss(str);
		while (iss >> n) { v.push_back(n); }
		
		size = sqrt(v.size());
		// error checking
		if (sqrt(v.size()) != size) {
			throw "Error: input puzzle length is not square.";
		}

		// populate board (vector of vectors)
		for(int i = 0; i < size; i++) {
			std::vector<int> vv;
			for (int j = 0; j < size; j++) {
				vv.push_back(v[i * size + j]);
			}
			board.push_back(vv);
		}

		// find and save blank space location
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j]==0) {
					emptyi = i; emptyj = j;
					return;
				}
			}
		} throw "Error: did not find 0 in input puzzle.";
	}

	// copy constructor
	NPuzzleState(const NPuzzleState& rhs) {
		board = rhs.board;
		emptyi = rhs.emptyi;
		emptyj = rhs.emptyj;
		size = rhs.size;
	}

	// TODO: implement a heuristic estimate of cost to solve 
	// (will be called by A*)

	// operator overloads
	bool operator==(const NPuzzleState& rhs) const {
		return board==rhs.board; 
	}
	friend std::ostream& operator<<(std::ostream& stream, const NPuzzleState& rhs) {
		int ndigits = ceil(log10(rhs.board.size()^2));
		for (int i = 0; i < rhs.board.size(); i++) {
			for (int j = 0; j < rhs.board[i].size(); j++) {
				stream << std::setw(ndigits) << rhs.board[i][j] << " ";
			}
			if (i < rhs.board.size()-1) stream << std::endl;
		}
		return stream;
	}
	bool operator<(const NPuzzleState& rhs) const { // must be overloaded so can put states in set.
		return board < rhs.board;
	}

};


class NPuzzle : public Problem<NPuzzleState> {
	public:
	NPuzzle(const std::string& str) :
			Problem<NPuzzleState>(NPuzzleState(str)) {}

	bool isGoalState(const NPuzzleState& s) const {
		// TODO: return true if state is a goal state (numbers are in order
		// with 0 at location 0, 0)
	}

	std::vector<std::pair<std::string, NPuzzleState> > expand(const NPuzzleState& s) const {
		// TODO: return vector of child states resulting from applying
		// all possible moves IN ORDER: left, right, up, down, paired with
		// the corresponding move
		// structure is { (move, state), (move, state), ... }
	}
};
