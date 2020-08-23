// Problem Code: STONES

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int jewelsAndStones(string J, string S){
	int count = 0;
	unordered_set<char> jewels(J.begin(), J.end());
	for(char &stone : S)
		if(jewels.find(stone) != jewels.end())
			count++;
	return count;
}

int main()
{
	int T;
	string J, S;
	cin >> T;
	cin.ignore();
	for(int i=1 ; i<=T ; i++){
		cin >> J >> S;
		cout << jewelsAndStones(J, S) << endl;
	}
	return 0;
}