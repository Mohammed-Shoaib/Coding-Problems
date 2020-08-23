// Problem Code: VOTERS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getList(int N, vector<int> &L){
	int num;
	for(int i=0 ; i<N ; i++){
		cin >> num;
		L.push_back(num);
	}
}

vector<int> votersList(vector<int> L1, vector<int> L2, vector<int> L3){
	vector<int> L12, L23, L31, L123, L;
	set_intersection(L1.begin(), L1.end(), L2.begin(), L2.end(), back_inserter(L12));
	set_intersection(L2.begin(), L2.end(), L3.begin(), L3.end(), back_inserter(L23));
	set_intersection(L3.begin(), L3.end(), L1.begin(), L1.end(), back_inserter(L31));
	set_union(L12.begin(), L12.end(), L23.begin(), L23.end(), back_inserter(L));
	set_union(L31.begin(), L31.end(), L.begin(), L.end(), back_inserter(L123));
	return L123;
}

int main()
{
	int N1, N2, N3, num;
	vector<int> L1, L2, L3, results;
	cin >> N1 >> N2 >> N3;
	getList(N1, L1);
	getList(N2, L2);
	getList(N3, L3);
	results = votersList(L1, L2, L3);
	cout << results.size() << endl;
	for(int i=0 ; i<results.size() ; i++)
		cout << results[i] << endl;
	return 0;
}