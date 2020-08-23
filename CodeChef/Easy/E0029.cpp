// Problem Code: AMSGAME2

#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> A;
map<pair<int, int>, long long> dp;

long long f(int pos, int gcd) {
	if(pos == A.size())
		return (gcd == 1) ? 1 : 0;
	else if(gcd == 1)
		return pow(2, A.size()-pos);
	pair<int, int> key = make_pair(pos, gcd);
	if(dp.find(key) != dp.end())
		return dp[key];
	dp[key] = f(pos+1, gcd) + f(pos+1, __gcd(A[pos], gcd));
	return dp[key];
}

long long subtractionGame2(vector<int> A) {
	long long sum = 0;
	for(int i=0 ; i<A.size()-1 ; i++)
		sum += f(i+1, A[i]);
	return sum;
}

int main() {
	int T, N, num;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			A.push_back(num);
		}
		cout << subtractionGame2(A) << endl;
		A.clear();
		dp.clear();
	}
	return 0;
}