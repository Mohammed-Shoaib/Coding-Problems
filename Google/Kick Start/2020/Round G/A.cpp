#include <iostream>
#include <string>

using namespace std;

int64_t kick_start(string& S) {
	int64_t kicks, lucky;
	kicks = lucky = 0;
	
	for (int i = 3; i < S.length(); i++) {
		if (S.substr(i - 3, 4) == "KICK")
			kicks++;
		else if (i > 3 && S.substr(i - 4, 5) == "START")
			lucky += kicks;
	}
	
	return lucky;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		string S;
		cin >> S;
		cout << "Case #" << x << ": " << kick_start(S) << endl;
	}
	return 0;
}