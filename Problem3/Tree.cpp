#include <iostream>
#include <vector>		
#include "TreeWrapper.h"
#pragma once

using namespace std;

// Creates a tree without children
Tree::Tree(int w, char c) {

	weight = w;
	this->c = c;
}

// Creates a tree with children 
Tree::Tree(int w, Tree* t1, Tree* t2) {
	
	weight = w; 
	c = -2;
	left = t1; 
	right = t2; 
};

Tree::~Tree() {}

// provides the tree weight
int Tree::getWeight() const{
	return weight;
}

// prints out the values of the provided vector
void Tree::printTree(vector<char>& bitString) const{
	// wordstring is the word that gets processed by the priorityqueue
	for (int i = 0; i < bitString.size(); i++) {
		cout << " " << bitString[i];
	}
	cout << endl; 
}

// pointer to the left child of the tree
Tree* Tree::getLeft()
{
	return left;
}

// pointer to the right child of the tree
Tree* Tree::getRight()
{
	return right;
}

// checks if it it a leaf-node
bool Tree::isLeaf(Tree* root1, Tree* root2)
{
	if (root1 == NULL && root2 == NULL) {
		return true; 
	}
	return false;
}

// function for treaversing the tree in pre orderd fashion 
char Tree::treeTraversal(Tree* root, char leftOrRight)
{
	char currElementValue = -2;
	
	if (root == NULL) { // nothing to visit 
		return NULL; 
	}
	
	// regesters the path taken to this node 
	if (leftOrRight == '0' || leftOrRight == '1') {
		currElementValue = leftOrRight;
	}
	// places the regesterd path on the vector
	if (currElementValue != -2) {
		bitString.push_back(currElementValue);
	}
	
	// visits left and right child nodes
	treeTraversal(root->getLeft(), '0');
	treeTraversal(root->getRight(), '1');
	
	// checks if this is leaf-node
	// if it is regesters ':' and current char value and then starts the print process
	if (isLeaf(root->left, root->right)) {
		if (root->c != -2) {
			bitString.push_back(':');
			bitString.push_back(root->c);
		}
		printTree(bitString); // prints the current value of the vector
		// removes the added char values from vector 
		// think of it as erasing your steps when walking back to the previus node
		bitString.pop_back();
		bitString.pop_back();
	}
	
	// when needed removes an aditional char value from vector
	if (!bitString.empty()) {
		bitString.pop_back();
	}

	return currElementValue;
}