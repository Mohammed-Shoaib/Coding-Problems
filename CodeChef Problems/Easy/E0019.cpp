// Problem Code: POTATOES

#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(vector<int> &primes){
    int i, j, size = 2003;
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

int farmerFeb(int x, int y, vector<int> &primes){
    vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), x+y+1);
    return *it-(x+y);
}

int main()
{
    
    int T, x, y;
    vector<int> primes;
    sieveOfEratosthenes(primes);
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> x >> y;
        cout << farmerFeb(x, y, primes) << endl;
    }
    return 0;
}