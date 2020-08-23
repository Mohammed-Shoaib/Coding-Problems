// Problem Code: PRIME1

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void sieveOfEratosthenes(vector<int> &primes){
	int i, j, size;
	size = pow(10, 5);
	vector<bool> isPrime(size+1, true);
	for(i=2 ; i*i<=size ; i++)
		if(isPrime[i]){
			primes.push_back(i);
			for(j=2*i ; j<=size ; j+=i)
				isPrime[j] = false;
		}
	for(; i<=size ; i++)
		if(isPrime[i])
			primes.push_back(i);
}

void primeGenerator(int m, int n, vector<int> &primes){
	int i, j, root;
	if(m < 2)
		m = 2;
	vector<bool> range(n-m+1, true);
	root = sqrt(n);
	for(int i=0 ; primes[i] <= root ; i++){
		j = floor(m/primes[i])*primes[i];
		if(j <= primes[i])
			j = 2*primes[i];
		else if(j < m)
			j += primes[i];
		for(; j<=n ; j+=primes[i])
			range[j-m] = false;
	}
	for(i=m ; i<=n ; i++)
		if(range[i-m])
			cout << i << endl;
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, m, n;
	vector<int> primes;
	sieveOfEratosthenes(primes);
	cin >> t;
	while(t--){
		cin >> m >> n;
		primeGenerator(m, n, primes);
	}
	return 0;
}