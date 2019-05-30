/*
Problem Statement: https://www.hackerrank.com/challenges/preprocessor-solution/problem
*/

#define toStr(a) #a
#define io(a) cin >> a
#define FUNCTION(f, op) void f(int &a, int b) { if (b op a) a = b; };
#define INF 10000000
#define foreach(v, i) for (int i = 0; i < v.size(); i++)

#include <iostream>
#include <vector>

using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}