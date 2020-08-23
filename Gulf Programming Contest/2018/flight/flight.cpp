#include <cstdio>
#include <utility>
#include <tuple>

using namespace std;

pair<int, int> flight(int h1, int m1, int d1, int h2, int m2, int d2) {
	int h, m;
	h = (h2 - d2) - (h1 - d1);
	m = m2 - m1;
	if (m < 0) {
		m += 60;
		h--;
	}
	if (h < 0)
		h += 24;
	else if (h > 24)
		h -= 24;
	return make_pair(h, m);
}

int main() {
	freopen("flight.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T, k = 1;
	scanf("%d", &T);
	while (T--) {
		int h, m, h1, m1, d1, h2, m2, d2;
		scanf("%d:%d %dGMT", &h1, &m1, &d1);
		scanf("%d:%d %dGMT", &h2, &m2, &d2);
		tie(h, m) = flight(h1, m1, d1, h2, m2, d2);
		printf("%d. %d:%02d\n", k, h, m);
		k++;
	}
	
	return 0;
}