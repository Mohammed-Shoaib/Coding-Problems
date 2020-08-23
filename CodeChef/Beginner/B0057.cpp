// Problem Code: LONGSEQ

#include <iostream>
#include <string>

using namespace std;

string chefAndDigits(string D) {
	int ones, zeros;
	ones = zeros = 0;
	for(int i=0 ; i<D.length() ; i++) {
		(D[i] == '1') ? ones++ : zeros++;
		if(ones > 1 && zeros > 1)
			break;
	}
	return (ones == 1 || zeros == 1) ? "Yes" : "No";
}

int main() {
	int T;
	string D;
	cin >> T;
	while(T--) {
		cin >> D;
		cout << chefAndDigits(D) << endl;
	}
	return 0;
}