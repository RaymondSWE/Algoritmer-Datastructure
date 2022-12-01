#include <iostream>
#include <queue>

#include "TreeWrapper.h"

using namespace std; 

int main()
{
    Tree tree(1, 'h');
    cout << tree.getWeight() << endl; 

    /*priority_queue <TreeWrapper, vector<TreeWrapper>, greater<TreeWrapper> > pqueue;
    
    pqueue.push(TreeWrapper(new Tree(1, 'h')));
    pqueue.push(TreeWrapper(new Tree(1, 'e')));
    pqueue.push(TreeWrapper(new Tree(1, 'l')));
    pqueue.push(TreeWrapper(new Tree(2, '0')));*/

    //while (pqueue.size()) {
    //    
    //   // cout >> pqueue.top >> endl; 
    //   /* pqueue.push(TreeWrapper(new Tree(
    //        pqueue.
    //    )))
    //    pqueue.top*/ 
    //}
}

