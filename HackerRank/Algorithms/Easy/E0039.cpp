/*
Problem Statement: https://www.hackerrank.com/challenges/lisa-workbook/problem
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int workbook(int n, int k, vector<int> arr) {
	int special = 0;
	int curPage = 1;
	for(int i=0 ; i<arr.size() ; i++){
		int numOfPages = ceil((float)arr[i]/k);
		for(int page=1 ; page<=numOfPages ; page++){
			int start = (page-1)*k + 1;
			int end = min(page*k, arr[i]);
			if(curPage>=start && curPage<=end)
				special++;
			curPage++;
		}
	}
	return special;
}

int main()
{
	int n, k, num;
	vector<int> arr;
	cin>>n>>k;
	for(int i=0 ; i<n ; i++){
		cin>>num;
		arr.push_back(num);
	}
	cout<<workbook(n, k, arr);
	return 0;
}