#include <iostream>
#include <vector>		
#include "TreeWrapper.h"
#pragma once

using namespace std;


Tree::Tree(int w, char c) {

	weight = w;
	this->c = c;
}

Tree::Tree(int w, Tree* t1, Tree* t2) {
	
	weight = w; 
	c = -2;
	left = t1; 
	right = t2; 
};

Tree::~Tree() {

}

int Tree::getWeight() const{
	return weight;
}

void Tree::printTree(vector<char>& bitString) const{
	// wordstring is the word that gets processed by the priorityqueue

	for (int i = 0; i < bitString.size(); i++) {
		/*if (bitString[i] > 2) {*/
			cout << " " << bitString[i];
		/*}
		else {
			cout << " " << (int)bitString[i];
		}*/
	}
	cout << endl; 
}

Tree* Tree::getLeft()
{
	return left;
}

Tree* Tree::getRight()
{
	return right;
}

bool Tree::isLeaf(Tree* root1, Tree* root2)
{
	if (root1 == NULL && root2 == NULL) {
		return true; 
	}
	return false;
}

char Tree::treeTraversal(Tree* root, char leftOrRight)
{
	char currElementValue = -3;
	
	if (root == NULL) {
		return NULL; 
	}

	if (leftOrRight == '0' || leftOrRight == '1') {
		currElementValue = leftOrRight;
	}
	

	/*if (root->c == -2 && leftOrRight != -1) {
		currElementValue = leftOrRight;
	}else {
		if (root->c != -2) {
			bitString.push_back(':');
			currElementValue = root->c;
		}
	}*/
	if (currElementValue != -2) {
		bitString.push_back(currElementValue);
	}
	
	treeTraversal(root->getLeft(), '0');
	treeTraversal(root->getRight(), '1');
	

	if (isLeaf(root->left, root->right)) {
		if (root->c != -2) {
			bitString.push_back(':');
			bitString.push_back(currElementValue = root->c);
		}
		printTree(bitString);
	}

	/*if (root->c != -2) {
		printTree(bitString);
	}*/
	bitString.pop_back();
	bitString.pop_back();

	
	

	return currElementValue;
}





