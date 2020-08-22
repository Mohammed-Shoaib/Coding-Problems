/*
Problem Statement: https://www.hackerrank.com/challenges/3d-surface-area/problem
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int surfaceArea(vector<vector<int>> A) {
	int area = 2 * (A.size() - 2) * (A[A.size() - 2].size() - 2);
	for(int i=1 ; i<A.size()-1 ; i++)
		for(int j=1 ; j<A[i].size()-1 ; j++){
			area += 4*A[i][j];
			area -= 2*min(A[i][j], A[i][j+1]);
			area -= 2*min(A[i][j], A[i+1][j]);
		}
	return area;
}

int main()
{
	int H, W, num;
	vector<vector<int>> A;
	cin>>H>>W;
	A.push_back(vector<int>(W+2));
	for(int i=1 ; i<=H ; i++){
		A.push_back(vector<int>());
		A[i].push_back(0);
		for(int j=1 ; j<=W ; j++){
			cin>>num;
			A[i].push_back(num);
		}
		A[i].push_back(0);
	}
	A.push_back(vector<int>(W+2));
	cout<<surfaceArea(A);
	return 0;
}