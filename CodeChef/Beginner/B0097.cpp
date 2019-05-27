// Problem Code: ELEVSTRS

#include <iostream>
#include <cmath>

using namespace std;

string elevatorOrStairs(int N, int V1, int V2) {
	float v, e;
	v = (sqrt(2) * N) / V1;
	e = (2.0 * N) / V2;
	return (v < e) ? "Stairs" : "Elevator";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, V1, V2;
		cin >> N >> V1 >> V2;
		cout << elevatorOrStairs(N, V1, V2) << endl;
	}
    return 0;
}