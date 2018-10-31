// Problem Code: TSORT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T, N;
    vector<int> numbers;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        numbers.push_back(N);
    }
    sort(numbers.begin(), numbers.end());
    for(int i=0 ; i<numbers.size() ; i++)
        cout << numbers[i] << endl;
    return 0;
}