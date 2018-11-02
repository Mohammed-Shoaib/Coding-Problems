// Problem Code: FLOW005

#include <iostream>
#include <vector>

using namespace std;

int totalNotes(int N){
    int count = 0;
    vector<int> notes({1, 2, 5, 10, 50, 100});
    for(int i=notes.size()-1 ; i>=0 ; i--){
        if(N == 0)
            break;
        else if(N < notes[i])
            continue;
        count += N/notes[i];
        N %= notes[i];
    }
    return count;
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        cout << totalNotes(N) << endl;
    }
    return 0;
}