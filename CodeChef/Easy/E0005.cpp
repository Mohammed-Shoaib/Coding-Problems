// Problem Code: CLEANUP

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, vector<int>> cleanUp(int n, vector<int> m){
	vector<int> chef, assistant;
	sort(m.begin(), m.end());
	for(int i=1, j=0, k=0 ; i<=n ; i++){
		if(j != m.size() && i == m[j]){
			j++;
			continue;
		}
		(k&1) ? assistant.push_back(i) : chef.push_back(i);
		k++;
	}
	return make_pair(chef, assistant);
} 

int main()
{
	int T, n, m, num;
	vector<int> completed, chef, assistant;
	pair<vector<int>, vector<int>> results;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> n >> m;
		for(int j=0 ; j<m ; j++){
			cin >> num;
			completed.push_back(num);
		}
		results = cleanUp(n, completed);
		chef = results.first;
		assistant = results.second;
		for(int j=0 ; j<chef.size() ; j++)
			cout << chef[j] << " ";
		cout << endl;
		for(int j=0 ; j<assistant.size() ; j++)
			cout << assistant[j] << " ";
		cout << endl;
		completed.clear();
	}
	return 0;
}