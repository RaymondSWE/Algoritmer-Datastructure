#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std::chrono;
using namespace std;
int topDown(int n, int (&result)[15])
{
    int cielValue=0; 
    int currentValue=0; 

if(result[n]!=-1)
return result[n];

if(n>0)
{
cielValue= (n / 2) + ((n % 2) != 0);
	currentValue= topDown(n - 1, result) + topDown(cielValue, result) + n;
}
result[n]=currentValue;
return currentValue;
}

int calculateTC(int n) {    
    if (n == 1) {
        return n;
    }
    int cielValue = (n / 2) + ((n % 2) != 0);
    int currentValue = calculateTC(n - 1) + calculateTC(cielValue) + n;
    
    return currentValue;
};
int main() {
int result[15];
std::fill_n(result, 15, -1);
    	cout << topDown(3, result) << '\n';

/*
    auto start = high_resolution_clock::now();
    cout << calculateTC(3) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << " milliseconds" << endl;
	*/
    return 0;
}