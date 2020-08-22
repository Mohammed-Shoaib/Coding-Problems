/*
Problem Statement: https://www.hackerrank.com/challenges/cavity-map/problem
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> cavityMap(vector<string> grid) {
	for(int i=1 ; i<grid.size()-1 ; i++){
		for(int j=1 ; j<grid[i].length()-1 ; j++){
			int cur_depth = int(grid[i][j]) - '0';
			int top_depth = int(grid[i-1][j]) - '0';
			int bottom_depth = int(grid[i+1][j]) - '0';
			int left_depth = int(grid[i][j-1]) - '0';
			int right_depth = int(grid[i][j+1]) - '0';
			if(top_depth == 40 || bottom_depth == 40 || left_depth == 40 || right_depth == 40)
				continue;
			else if(top_depth < cur_depth && bottom_depth < cur_depth && left_depth < cur_depth && right_depth < cur_depth)
				grid[i][j] = 'X';
		}
	}
	return grid;
}

int main()
{
	int n;
	string s;
	vector<string> map, results;
	cin>>n;
	cin.ignore();
	for(int i=0 ; i<n ; i++){
		getline(cin, s);
		map.push_back(s);
	}
	results = cavityMap(map);
	for(int i=0 ; i<results.size() ; i++)
		cout<<results[i]<<endl;
	return 0;
}