#include <chrono>
#include <vector>
#include <iostream>
using namespace std::chrono;
using namespace std;
int topDown(int n, vector<vector<int>> &result)
{
    int cielValue; 
    int currentValue; 

if(n==1)
return n;
if(result.empty())
{
cielValue= (n / 2) + ((n % 2) != 0);
	currentValue= topDown(n - 1, result) + topDown(cielValue, result) + n;
result[0].push_back(n);
result[0].push_back(currentValue);
}

for(int i=0; i<result.size(); ++i)
{
	if(result[i][0]!=n)
{
cielValue= (n / 2) + ((n % 2) != 0);
	currentValue= topDown(n - 1, result) + topDown(cielValue, result) + n;
result[i].push_back(n);
result[i].push_back(currentValue);

}

}

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
	vector<vector<int> > result;
//    vector<vector<int> >    result(8, vector<int>(3));
		cout << topDown(3, result);

for(int i=0; i<result.size(); ++i)
{
cout << result[i][1];
}
/*
    auto start = high_resolution_clock::now();
    cout << calculateTC(3) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << duration.count() << " milliseconds" << endl;
	*/
    return 0;
}