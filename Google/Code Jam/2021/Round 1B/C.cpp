#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

void digit_blocks(int N, int B) {
	int pos, curr = 0;
	vector<int> towers(N);
	queue<int> high_1, high_2;
	
	// helper functions
	auto push_1 = [&]() {
		pos = high_1.front();
		towers[pos]++;
		high_1.pop();
	};
	auto push_2 = [&]() {
		pos = high_2.front();
		towers[pos]++;
		high_1.push(pos);
		high_2.pop();
	};
	
	for (int x = 1; x <= N * B; x++) {
		int D;
		cin >> D;
		
		// greedy approach, passes 50% of the time
		if (D == 9 && !high_1.empty())
			push_1();
		else if (D >= 7 && !high_2.empty())
			push_2();
		else if (curr < N) {
			pos = curr;
			if (++towers[pos] == B - 2) {
				curr++;
				high_2.push(pos);
			}
		}
		else if (!high_2.empty())
			push_2();
		else
			push_1();
		
		cout << pos + 1 << endl;
	}
}

int main() {
	int64_t P;
	int T, N, B;
	cin >> T >> N >> B >> P;
	for (int x = 1; x <= T; x++)
		digit_blocks(N, B);
	return 0;
}