// Problem Code: CHRL2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chefAndString(string S) {
    vector<int> count(4);
    for(int i=0 ; i<S.length() ; i++) {
        if(S[i] == 'C')
            count[0]++;
        else if(S[i] == 'H' && count[0] > count[1])
            count[1]++;
        else if(S[i] == 'E' && count[1] > count[2])
            count[2]++;
        else if(S[i] == 'F' && count[2] > count[3])
            count[3]++;
    }
    return *min_element(count.begin(), count.end());
}

int main() {
    string S;
    cin >> S;
    cout << chefAndString(S);
    return 0;
}