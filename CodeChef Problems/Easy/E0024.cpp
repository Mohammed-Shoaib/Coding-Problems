// Problem Code: SPCANDY

#include <iostream>
#include <utility>

using namespace std;

pair<long, long> splittingCandies(long N, long K){
    long student, teacher;
    if(K == 0){
        student = 0;
        teacher = N;
    }else{
        student = N / K;
        teacher = N % K;
    }
    return make_pair(student, teacher);
}

int main()
{
    int T;
    long N, K;
    pair<long, long> candies;
    cin >> T;
    while(T--){
        cin >> N >> K;
        candies = splittingCandies(N, K);
        cout << candies.first << " " << candies.second << endl;
    }
    return 0;
}