// Problem Code: ANUBTG

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int surajGoesShopping(vector<int> C) {
	int cost = 0;
	sort(C.begin(), C.end(), greater<int>());
	for(int i=0 ; i<C.size() ; i++)
		if(i % 4 < 2)
			cost += C[i];
	return cost;
}

int main() {
	int T, N, num;
	vector<int> C;
	cin >> T;
	while(T--) {
		cin >> N;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			C.push_back(num);
		}
		cout << surajGoesShopping(C) << endl;
		C.clear();
	}
	return 0;
}