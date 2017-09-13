# Assignment 1: Search

In this assignment you will create an agent to solve an n-puzzle (visit mypuzzle.org/sliding to review the rules of the game, discussed in class).

You are given Problem.h, which contains, among other things, a Node class implementation and the virtual class Problem, which contains two virtual methods that will be implemented by any subclass: isGoalState() and expand(). It also contains a solve() method, in which you will implement the search algorithm discussed in class. The fringe data structure will be passed as an argument, so that it can be either a stack, queue, or priority queue, which will determine whether the search strategy is depth-first, breadth-first, or informed.

You are also given NPuzzle.h, which holds the NPuzzle class, an instantiation of the Problem virtual class. 

Both files contain methods marked TODO, which you are to fill in.

## Extra credit
* Create another subclass of Problem.h to implement the Knuth search problem. (Highly recommend) (5 points)
* As always, completing the homework within the first two days (or discovering a fatal flaw within that time frame) will earn one point of extra credit.

## Testing
This repository contains two files called npuzzle.txt and solutions_done.txt. In testing, main.cpp will be run with the arguments npuzzle.txt and 'a', which will generate a file called solutions.out containing an optimal solution for each puzzle in npuzzle.h. compare_two_files.cpp will then be run to validate that the two files are identical. This is a shallow evaluation that requires you to use the same action names and evaluate actions in the same order as specified in the TODO.

## Languages
You are provided with a lot of C++ code that you are welcome to rewrite in the language of your choice and complete in that language. If you choose to do this, you must update the .travis.yml configuration with the command sequence that will generate solutions.out.

[![Build Status](https://travis-ci.com/cisc3410/1-search.svg?token=sGqTPYKnjS4iVpK7fKg1&branch=assignment)](https://travis-ci.com/cisc3410/1-search)
