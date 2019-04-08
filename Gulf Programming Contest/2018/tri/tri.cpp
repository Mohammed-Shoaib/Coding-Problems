#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int size = (-1 + sqrt(800000001)) / 2;
vector<int> ferm(size + 1);

void preprocess() {
    ferm[0] = 0;
    for (int i = 1; i <= size; i++)
        ferm[i] = i * (i + 1) / 2;
}

vector<int> tri(int N) {
    int low, high, sum;
    vector<int> res;
    for (int i = 0; i < ferm.size() && res.size() == 0; i++) {
        low = i;
        high = ferm.size() - 1;
        while (low <= high && res.size() == 0) {
            sum = ferm[i] + ferm[low] + ferm[high];
            if (sum == N)
                res = vector<int>({ferm[i], ferm[low], ferm[high]});
            else if (sum < N)
                low++;
            else
                high--;
        }
    }
    for (int i = res.size() - 1; i >= 0; i--)
        if (res[i] == 0)
            res.erase(res.begin() + i);
    return res;
}

int main() {
    freopen("tri.in", "r", stdin);
    freopen("output.out", "w", stdout);
    preprocess();
    
    int T, k = 1;
    cin >> T;
    while (T--) {
        int N;
        vector<int> res;
        cin >> N;
        res = tri(N);
        cout << k << ".";
        for (int i = 0; i < res.size(); i++)
            cout << " " << res[i];
        cout << endl;
        k++;
    }
    
    return 0;
}