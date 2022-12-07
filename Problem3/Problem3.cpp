#include <iostream>
#include <queue>
#include "TreeWrapper.h"

using namespace std;

int main()
{

    TreeWrapper treeWrapper; 
    string wordString = "heeelllloo";
    cout << wordString << endl;
	
	// converts the string to a char vector 
    vector<char> vectorString(wordString.begin(), wordString.end());

	vector<char> tempCharVector(vectorString.size());
	vector<int>	tempWeightVector(vectorString.size());


	
	int tempVectorIteratorValue = 0;

	priority_queue <TreeWrapper> pqueue;

	for (int i = 0; i < vectorString.size(); i++) {
		bool isDistinct = true;

		// searchs for duplicates of the current character
		for (int j = 0; j < vectorString.size(); j++) {
			if (vectorString[i] == tempCharVector[j] && i != j) {
				tempWeightVector[j]++;
				isDistinct = false;

			}
		}
		// varifyes that duplicate characters dont get registerd  
		if (isDistinct) {
			tempCharVector[tempVectorIteratorValue] = vectorString[i];
			tempWeightVector[tempVectorIteratorValue] = 1;
			tempVectorIteratorValue++;
		}
	}
	//creates trees for distinct nodes with the calculated weight
	for (int i = 0; i < tempCharVector.size(); i++) {
		if (tempWeightVector[i] > 0) {
			cout << tempCharVector[i] << ":  " << tempWeightVector[i] << endl;
			pqueue.push(TreeWrapper(new Tree(tempWeightVector[i], tempCharVector[i])));
		}
	}


	// assembles the tree 
	while (pqueue.size() > 1) {
		TreeWrapper treeWrapper1 = pqueue.top();
		pqueue.pop();
		TreeWrapper treeWrapper2 = pqueue.top();
		pqueue.pop();

		int combWaight = treeWrapper1.tree->getWeight() + treeWrapper2.tree->getWeight();
		pqueue.push(TreeWrapper(new Tree(combWaight, treeWrapper1.tree, treeWrapper2.tree)));
	}

	pqueue.top().tree->treeTraversal(pqueue.top().tree, -1);
	pqueue.top().tree->printTree(vectorString);
	
}
