// Problem Code: MARCHA1

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string payingUp(int m, vector<int> n){
    int sum, subsetSize;
    subsetSize = pow(2, n.size());
    for(int i=0 ; i<subsetSize ; i++){
        sum = 0;
        for(int j=0 ; j<n.size() ; j++)
            if(i & (1<<j))
                sum += n[j];
        if(sum == m)
            return "Yes";
    }
    return "No";
}

int main()
{
    int t, n, m, num;
    vector<int> banknotes;
    cin >> t;
    for(int i=1 ; i<=t ; i++){
        cin >> n >> m;
        for(int j=0 ; j<n ; j++){
            cin >> num;
            banknotes.push_back(num);
        }
        cout << payingUp(m, banknotes) << endl;
        banknotes.clear();
    }
    return 0;
}