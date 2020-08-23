// Problem Code: RESQ

#include <iostream>
#include <cmath>

using namespace std;

int minimumDifference(int N){
	int first, second, root;
	root = sqrt(N);
	for(int i=root ; i>0 ; i--)
		if(N % i == 0){
			first = i;
			break;
		}
	second = N/first;
	return abs(first-second);
}

int main()
{
	int T, N;
	cin >> T;
	while(T--){
		cin >> N;
		cout << minimumDifference(N) << endl;
	}
	return 0;
}