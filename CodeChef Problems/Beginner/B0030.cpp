// Problem Code: SMPAIR

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int smallestPair(vector<int> N){
    int first, second;
    first = second = numeric_limits<int>::max();
    for(int i=0 ; i<N.size() ; i++){
        if(N[i] < first){
            second = first;
            first = N[i];
        }
        else if(N[i] < second && N[i] != first)
            second = N[i];
    }
    return first + second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, num;
    vector<int> numbers;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        for(int j=0 ; j<N ; j++){
            cin >> num;
            numbers.push_back(num);
        }
        cout << smallestPair(numbers) << endl;
        numbers.clear();
    }
    return 0;
}