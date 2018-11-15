// Problem Code: COPS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int copsAndThief(int x, int y, vector<int> M) {
    vector<bool> houses(101);
    int lower, upper, prod = x*y;
    houses[0] = true;
    for(int i=0 ; i<M.size() ; i++) {
        lower = max(1, M[i] - prod);
        upper = min(100, M[i] + prod);
        for(int j=lower ; j<=upper ; j++)
            houses[j] = true;
    }
    return count(houses.begin(), houses.end(), false);
}

int main() {
    int T, M, x, y, num;
    vector<int> cops;
    cin >> T;
    while(T--) {
        cin >> M >> x >> y;
        for(int i=0 ; i<M ; i++) {
            cin >> num;
            cops.push_back(num);
        }
        cout << copsAndThief(x, y, cops) << endl;
        cops.clear();
    }
    return 0;
}