// Problem Code: CHEFGR

#include <stdio.h>

char *chefAndGround(int N, int M, int A[]) {
	int diff, max;
	diff = 0;
	max = -1;
	for (int i = 0 ; i < N ; i++)
		if (max < A[i])
			max = A[i];
	for (int i = 0 ; i < N ; i++)
		diff += max - A[i];
	if ((M - diff) % N == 0)
		return "Yes";
	else
		return "No";
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		int A[N];
		for (int i = 0 ; i < N ; i++)
			scanf("%d", &A[i]);
		printf("%s\n", chefAndGround(N, M, A));
	}
	return 0;
}