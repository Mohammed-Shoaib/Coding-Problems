/*
Problem Statement: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
*/

#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	vector<int> results;
	set<int> temp;
	for(int i=0 ; i<scores.size() ; i++)
		temp.insert(scores[i]);
	scores.assign(temp.begin(), temp.end());
	sort(scores.begin(), scores.end(), greater<int>());
	for(int j=0 ; j<alice.size() ; j++){
		int rank;
		int low = 0;
		int high = scores.size() - 1;
		while(low <= high){
			int mid = (low + high)/2;
			if(scores[mid] == alice[j]){
				rank = mid + 1;
				break;
			}
			else if(scores[mid] > alice[j])
				low = mid + 1;
			else
				high = mid - 1;
		}
		if(low <= high){
			results.push_back(rank);
			continue;
		}
		if(low == 0 || high == scores.size() - 1)
			rank = low + 1;
		else
			rank = high + 2;
		results.push_back(rank);
	}
	return results;
}

int main()
{
	int n, m, num;
	vector<int> scores, alice, results;
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		scores.push_back(num);
	}
	cin>>m;
	for(int j=0 ; j<m ; j++){
		cin>>num;
		alice.push_back(num);
	}
	results = climbingLeaderboard(scores, alice);
	for(int j=0 ; j<results.size() ; j++)
		cout<<results[j]<<endl;
	return 0;
}