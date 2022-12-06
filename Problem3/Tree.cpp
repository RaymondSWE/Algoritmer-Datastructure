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
	if (t)
}




