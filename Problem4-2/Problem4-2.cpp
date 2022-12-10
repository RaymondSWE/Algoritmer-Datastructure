#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

// T(n) = T(n - 1) + T(n/2) + n             //n + T(n-1) + T(n/2)????
// T(1) = 1
// 
// where n/2 is the least integer greater than n/2.
// 
//Task 4.1 Design a trivial(the most obvious solution) recursive algorithm that
//calculates T(n) in the expression(2).Implement the algorithm in C / C ++
//code.

int calculateTC(int n);											// Trivial version 
int topDownTC(int n, vector<vector<int>>& resultVector);		// dynamic programing version
void pushBackFunction(int n, vector<vector<int>>& resultVector);

int main() {
	vector<vector<int>> resultVector;							// 2D-vector to store n:values and equation results

	auto start = high_resolution_clock::now();					// timer

	cout << calculateTC(50) << endl;
	cout << topDownTC(50, resultVector) << endl;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << duration.count() << " milliseconds" << endl;
	return 0;
}

// The trivial solution for problem 4
int calculateTC(int n) {
	if (n == 1) {
		return n;
	}
	int cielValue = (n / 2) + ((n % 2) != 0);
	int currentValue = calculateTC(n - 1) + calculateTC(cielValue) + n;

	return currentValue;
};

// Pushes values into the back of the vector 
void pushBackFunction(int n, vector<vector<int>>& resultVector) {
	int tempValue;
	int cielValue = (n / 2) + ((n % 2) != 0);
	tempValue = topDownTC((n - 1), resultVector) + topDownTC(cielValue, resultVector) + n;
	resultVector.push_back({ n , tempValue });
}

// solves problem 4 with dynamic proraming 
int topDownTC(int n, vector<vector<int>>& resultVector) {
	if (n == 1) {
		return n;
	}
	else {

		int result;

		// pushes the first values into the vector, privents nullptr exeptions 
		if (resultVector.size() == 0) {			
			pushBackFunction(n, resultVector);
		}

		// checks the already regesterd results for current value of n
		for (int i = 0; i < resultVector.size(); i++) {	
			if (resultVector[i][0] == n) {
				result = resultVector[i][1];
			}
		}

		// if the current value of n, did not have and answare
		if (result == NULL) {		
			pushBackFunction(n, resultVector);
		}

		return result;
	}
};