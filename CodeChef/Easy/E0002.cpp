// Problem Code: FCTRL

#include <iostream>
#include <cmath>

using namespace std;

int findTrailingZeros(int N){
	int rem, i, count;
	count = 0;
	i = 1;
	while(rem = N/pow(5, i)){
		count += rem;
		i++;
	}
	return count;
}

int main()
{
	int T, N;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N;
		cout << findTrailingZeros(N) << endl;
	}
	return 0;
}