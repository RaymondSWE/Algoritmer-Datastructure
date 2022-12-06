#include <iostream>
#include <vector>		
#include "TreeWrapper.h"
#pragma once

using namespace std;


Tree::Tree(int w, char c) {

	this->weight = w;
	this->c = c;
}

Tree::Tree(int w, Tree* t1, Tree* t2) {
	
	this->weight = w; 
	this->left = t1; 
	this->right = t2; 
};

Tree::~Tree() {

}

int Tree::getWeight() const{
	return weight;
}

void Tree::printTree(vector<char>& bitString) const{
	// wordstring is the word that gets processed by the priorityqueue
	for (int i = 0 ; i < bitString.size(); i++) {
		cout << bitString[i]; 
	}
}

Tree* Tree::getLeft()
{
	return left;
}

Tree* Tree::getRight()
{
	return right;
}

char Tree::treeTraversal(Tree* root, int leftOrRight)
{
	char currElementValue;
	
	if (root == NULL) {
		cout << "end" << endl; 
		return NULL; 
	}
	else { cout << "root not null" << endl; }

	if (c == NULL) {
		currElementValue = leftOrRight;
	}else {
		cout << c; 
		currElementValue = c; 
	}
	cout << currElementValue;
	currElementValue = treeTraversal(root->getLeft(), 0);
	
	currElementValue = treeTraversal(root->getRight(), 1);
	 
	

	return currElementValue;
}




