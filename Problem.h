// author: levitan
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <unistd.h>


template <class T>
const T& next(std::stack<T> s) { return s.top(); }
template <class T>
const T& next(std::queue<T> q) { return q.front(); }
template <class T, class Compare>
const T& next(std::priority_queue<T, std::vector<T>, Compare> pq) { return pq.top(); }

template <class State>
struct Node {
	Node<State>* parent;
	std::string action;
	int pathCost;
	State state;
	Node(Node<State>* p, const std::string& a, int c, State s) :
		parent(p), action(a), pathCost(c), state(s) {}
	friend std::ostream& operator<<(std::ostream& stream, Node<State>* n) {
		stream << n->state << std::endl << "action: " << n->action;
		if (n->parent) stream << ", parent action: " << n->parent->action;
		else stream << ", startState";
		stream << "\ncost: " << n->pathCost; //<< ", heuristic: " << n->state.nMisplaced();
		stream << std::endl;
		return stream;
	}
	bool operator==(const Node<State> &rhs){
		if(pathCost == rhs.pathCost && state == rhs.state)
			return true;
		return false;
	}
};

template <class State>
struct AstarCompare {
	/*
		compares pathcost of two nodes
		pathcost = parent.pathcost + heurstic from NPuzzleState
	*/
	bool operator()(Node<State>* lhs, Node<State>* rhs) {
		// TODO Remember that the node with the LOWER cost should be
		// GREATER
		return lhs->pathCost+lhs->state.evaluation() > rhs->pathCost+rhs->state.evaluation();
	}

};

template <class State>
class Problem {
	State startState;

	public:
	Problem(State s) : startState(s) {}
	virtual bool isGoalState(const State& s) const =0;
	virtual std::vector<std::pair<std::string, State> > expand(const State& s) const =0;
	const State& getStartState() { return startState; }



	bool checkIfSeen(Node<State>* com, std::vector<Node<State>* > seen){
		for(int i = 0; i < seen.size(); i++){
			if(*(com) == *(seen[i])){
				return true;
			}
		}
		return false;
	}

	template <class C>
	std::string solve(C fringe) {
		Node<State>* n = new Node<State>(NULL, "START", 0, startState);
		std::vector<Node<State>* > seen;
		// TODO
		fringe.push(n);
		while(!fringe.empty()){
			n = next(fringe);
			seen.push_back(next(fringe));
			fringe.pop();

			if(isGoalState(n->state)){
				std::string path = n->action;
				while(n->parent != NULL){
					n = n->parent;
					path = n->action + " " + path;
				}
				return path;
			}
			else{
				std::vector<std::pair<std::string, State> > newChildren = expand(n->state);
				for(int i = 0; i < newChildren.size(); i++){
					Node<State>* newChild = new Node<State>(n,std::get<0>(newChildren[i]),n->pathCost+1,std::get<1>(newChildren[i]));
					if(!checkIfSeen(newChild,seen))
						fringe.push(newChild);

				}
			}

		}
		return "failure";


	}


	std::string BFS() {
		// TODO
		return solve(std::queue<Node<State>* >());
	}

	std::string DFS() {
		return solve(std::stack<Node<State>* >());
	}

	std::string Astar() {
		// TODO
		return solve(std::priority_queue<Node<State>*, std::vector<Node<State>* >, AstarCompare<State> >());
	}

	std::string solve(char c) {
		switch (c) {
			case 'b': return BFS();
			case 'd': return DFS();
			case 'a': return Astar();
		}
	}
};
