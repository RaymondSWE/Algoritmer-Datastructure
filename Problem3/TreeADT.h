#include <vector>
#pragma once

using namespace std;

class Tree {

public:

	Tree(int w, char c);							// Creates a tree without children
	Tree(int w, Tree* t1, Tree* t2);				// Creates a tree with children 
	~Tree();
	int getWeight() const;							// provides the tree weight
	void printTree(vector<char>& bitString) const;	// prints out the values of the provided vector
	Tree* getLeft();								// pointer to the left child of the tree
	Tree* getRight(); 								// pointer to the right child of the tree
	char treeTraversal(Tree* root, char leftOrRight);	// function for treaversing the tree in pre orderd fashion 
	bool isLeaf(Tree* root1, Tree* root2);			// checks if it it a leaf-node
	
private:
	Tree* left;
	Tree* right;
	int weight;
	char c;
	vector<char> bitString;
	
};

