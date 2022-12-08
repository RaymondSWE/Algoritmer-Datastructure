#include <iostream>
using namespace std;

// T (n) = T (n - 1) + T (dn/2e) + n
// T (1) = 1
// 
// where dn/2e is the least integer greater than n/2.
// 
//Task 4.1 Design a trivial(the most obvious solution) recursive algorithm that
//calculates T(n) in the expression(2).Implement the algorithm in C / C ++
//code.
void calculateTC(int n);

int main() {

}

int calculateTC() {
	return calculateTC(), calculateTC();
};