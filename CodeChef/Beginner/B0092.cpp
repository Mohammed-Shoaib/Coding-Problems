// Problem Code: TRUEDARE

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

string truthAndDare(vector<int> TR, vector<int> DR, vector<int> TS, vector<int> DS) {
	vector<unordered_set<int>> ram(2);
	ram[0] = unordered_set<int>(TR.begin(), TR.end());
	ram[1] = unordered_set<int>(DR.begin(), DR.end());
	for(int i=0 ; i<TS.size() ; i++)
		if(ram[0].find(TS[i]) == ram[0].end())
			return "no";
	for(int i=0 ; i<DS.size() ; i++)
		if(ram[1].find(DS[i]) == ram[1].end())
			return "no";
	return "yes";
}

int main() {
	int T, tR, dR, tS, dS, num;
	vector<int> TR, DR, TS, DS;
	cin >> T;
	while(T--) {
		cin >> tR;
		for(int i=0 ; i<tR ; i++) {
			cin >> num;
			TR.push_back(num);
		}
		cin >> dR;
		for(int i=0 ; i<dR ; i++) {
			cin >> num;
			DR.push_back(num);
		}
		cin >> tS;
		for(int i=0 ; i<tS ; i++) {
			cin >> num;
			TS.push_back(num);
		}
		cin >> dS;
		for(int i=0 ; i<dS ; i++) {
			cin >> num;
			DS.push_back(num);
		}
		cout << truthAndDare(TR, DR, TS, DS) << endl;
		TR.clear();
		DR.clear();
		TS.clear();
		DS.clear();
	}
	return 0;
}