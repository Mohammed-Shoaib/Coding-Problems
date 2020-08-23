// Problem Code: VCS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void versionControlSystem(int N, vector<int> A, vector<int> B) {
	int c1, c2;
	vector<int> v1;
	vector<bool> v2(N);
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(v1));
	for(int i=0 ; i<A.size() ; i++)
		v2[A[i]-1] = true;
	for(int j=0 ; j<B.size() ; j++)
		v2[B[j]-1] = true;
	c1 = v1.size();
	c2 = count(v2.begin(), v2.end(), false);
	cout << c1 << " " << c2 << endl;
}

int main() {
	int T, N, M, K, num;
	vector<int> A, B;
	cin >> T;
	while(T--) {
		cin >> N >> M >> K;
		for(int i=0 ; i<M ; i++) {
			cin >> num;
			A.push_back(num);
		}
		for(int j=0 ; j<K; j++) {
			cin >> num;
			B.push_back(num);
		}
		versionControlSystem(N, A, B);
		A.clear();
		B.clear();
	}
	return 0;
}