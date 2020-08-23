// Problem Code: EVENT

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<string, int> days({
	{"saturday", 0},
	{"sunday", 1},
	{"monday", 2},
	{"tuesday", 3},
	{"wednesday", 4},
	{"thursday", 5},
	{"friday", 6}
});

string eventDuration(string S, string E, int L, int R) {
	int d = days[E] - days[S] + 1;
	if(d < 0)
		d += 7;
	if (L > d) {
		int div = ceil((L - d) / 7.0);
		d += 7*div;
	}
	if (R < d)
		return "impossible";
	else if (R < d + 7)
		return to_string(d);
	else
		return "many";
}

int main() {
	int T, L, R;
	string S, E;
	cin >> T;
	while (T--) {
		cin >> S >> E >> L >> R;
		cout << eventDuration(S, E, L, R) << endl;
	}
	return 0;
}