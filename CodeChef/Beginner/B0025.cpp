// Problem Code: PRB01

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sieveOfEratosthenes(vector<int> &primes){
	int i, j, size = 100000;
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

string primalityTest(int N, vector<int> &primes){
	bool isPrime = (find(primes.begin(), primes.end(), N) != primes.end());
	return (isPrime) ? "yes" : "no";
}

int main()
{
	int T, N;
	vector<int> primes;
	sieveOfEratosthenes(primes);
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N;
		cout << primalityTest(N, primes) << endl;
	}
	return 0;
}