// Problem Code: FLOW007

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int reverseTheNumber(int N){
    string s = to_string(N);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        cout << reverseTheNumber(N) << endl;
    }
    return 0;
}