// Problem Code: PRGIFT

#include <iostream>
#include <vector>

using namespace std;

string chefAndGift(int k, vector<int> a) {
	int even = 0;
	for(int i=0 ; i<a.size() ; i++)
		if(a[i] % 2 == 0)
			even++;
	if( (even == a.size() && k == 0) || k > even)
		return "NO";
	else
		return "YES";
}

int main() {
	int T, n, k, num;
	vector<int> a;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		for(int i=0 ; i<n ; i++) {
			cin >> num;
			a.push_back(num);
		}
		cout << chefAndGift(k, a) << endl;
		a.clear();
	}
	return 0;
}