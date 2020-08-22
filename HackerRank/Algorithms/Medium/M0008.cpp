/*
Problem Statement: https://www.hackerrank.com/challenges/the-grid-search/problem
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
	int i, j, find_pos;
	vector<pair<int, int>> pos;
	bool present = false;
	for(i=0, j=0 ; i<G.size()-P.size()+1 ; i++){
		find_pos = G[i].find(P[j]);
		while(find_pos != string::npos){
			pos.push_back(pair<int, int>(i, find_pos));
			find_pos = G[i].find(P[j], find_pos+1);
		}
	}
	for(int k=0 ; k<pos.size() ; k++){
		i = pos[k].first + 1;
		find_pos = pos[k].second;
		for(j=1 ; j<P.size() ; i++, j++){
			int curr_pos = G[i].find(P[j]);
			while(curr_pos != string::npos){
				if(curr_pos == find_pos)
					break;
				curr_pos = G[i].find(P[j], curr_pos+1);
			}
			if(curr_pos != find_pos)
				break;
		}
		if(j == P.size()){
			present = true;
			break;
		}
	}
	return (present) ? "YES" : "NO";
}

int main()
{
	int t, R, C, r, c;
	string s;
	vector<string> G, P;
	cin>>t;
	for(int i=1 ; i<=t ; i++){
		cin>>R>>C;
		cin.ignore();
		for(int j=0 ; j<R ; j++){
			getline(cin, s);
			G.push_back(s);
		}
		cin>>r>>c;
		cin.ignore();
		for(int j=0 ; j<r ; j++){
			getline(cin, s);
			P.push_back(s);
		}
		cout<<gridSearch(G, P)<<endl;
		G.clear();
		P.clear();
	}
	return 0;
}