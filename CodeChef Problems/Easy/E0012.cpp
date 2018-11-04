// Problem Code: CARVANS

#include <iostream>
#include <vector>

using namespace std;

int carvans(vector<int> N){
    int count = 1;
    for(int i=1 ; i<N.size() ; i++){
        if(N[i] <= N[i-1])
            count++;
        else
            N[i] = N[i-1];
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, num;
    vector<int> speeds;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        for(int j=0 ; j<N ; j++){
            cin >> num;
            speeds.push_back(num);
        }
        cout << carvans(speeds) << endl;
        speeds.clear();
    }
    return 0;
}