#include <vector>
#pragma once

using namespace std;

class Tree {

public:

	Tree(int w, char c);
	Tree(int w, Tree* t1, Tree* t2);
	~Tree();
	int getWeight() const;
	void printTree(vector<char>& bitString) const;
	Tree* getLeft();  // dont know if allowed to use these 
	Tree* getRight(); // dont know if allowed to use these
	char treeTraversal(Tree* root, char leftOrRight);// dont know if allowed to use these
	bool isLeaf(Tree* root1, Tree* root2);
	
private:
	Tree* left;
	Tree* right;
	int weight;
	char c;
	char bitValue; // testing
	vector<char> bitString; // dont know if allowed to use
	
};

