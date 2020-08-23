// Problem Code: FLOW006

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int sumOfDigits(int N){
	int sum = 0;
	string s = to_string(N);
	for(char c : s)
		sum += c - '0';
	return sum;
}

int main()
{
	int T, N;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N;
		cout << sumOfDigits(N) << endl;
	}
	return 0;
}