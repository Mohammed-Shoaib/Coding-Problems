// Problem Code: PCYCLE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> permutationCycles(vector<int> A){
	int i, j;
	vector<bool> visited(A.size());
	vector<vector<int>> cycles(1);
	i = j = 0;
	while(true){
		cycles[j].push_back(i+1);
		if(visited[i]){
			i = distance(visited.begin(), find(visited.begin(), visited.end(), false));
			if(i == visited.size())
				break;
			cycles.push_back(vector<int>());
			j++;
		}else{
			visited[i] = true;
			i = A[i] - 1;
		}
	}
	return cycles;
}

int main(){
	int N, num;
	vector<int> A;
	vector<vector<int>> cycles;
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> num;
		A.push_back(num);
	}
	cycles = permutationCycles(A);
	cout << cycles.size() << endl;
	for(int i=0 ; i<cycles.size() ; i++){
		for(int j=0 ; j<cycles[i].size() ; j++)
			cout << cycles[i][j] << " ";
		cout << endl;
	}
	return 0;
}