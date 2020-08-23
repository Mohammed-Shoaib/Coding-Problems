// Problem Code: TTENIS

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string chefAndTableTennis(string S) {
	vector<int> player(2);
	string chef;
	for(int i=0 ; i<S.length() ; i++) {
		player[S[i]-'0']++;
		if(player[0] > 10 && player[0] > player[1]+1) {
			chef = "LOSE";
			break;
		}else if(player[1] > 10 && player[1] > player[0]+1) {
			chef = "WIN";
			break;
		}
	}
	return chef;
}

int main() {
	int T;
	string S;
	cin >> T;
	while(T--) {
		cin >> S;
		cout << chefAndTableTennis(S) << endl;
	}
	return 0;
}