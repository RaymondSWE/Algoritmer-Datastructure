#include <iostream>
using namespace std;
/*
 T(n) = T(n - 1) + T(n/2) + n
 T(1) = 1
 where n/2 is the least integer greater than n/2.

Task 4.1 Design a trivial(the most obvious solution) recursive algorithm that
calculates T(n) in the expression(2).Implement the algorithm in C / C ++
*/
int calculateTC(int n) {
	if (n == 1) {
		return n;
	}
	int currentValue { (n-1) + ceil(n / 2) + n}; 
	cout << currentValue << endl; 
	return calculateTC(currentValue);
}

int main() {

}

