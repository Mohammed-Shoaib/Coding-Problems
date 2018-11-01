// Problem Code: PERMUT2

#include <iostream>
#include <vector>

using namespace std;

string ambiguousPermutations(vector<int> numbers){
    vector<int> positions(numbers.size());
    for(int i=0 ; i<numbers.size() ; i++)
        positions[numbers[i]-1] = i+1;
    return (positions == numbers) ? "ambiguous" : "not ambiguous";
}

int main()
{
    int n, num;
    vector<int> numbers;
    while(cin >> n && n!= 0){
        for(int i=0 ; i<n ; i++){
            cin >> num;
            numbers.push_back(num);
        }
        cout << ambiguousPermutations(numbers) << endl;
        numbers.clear();
    }
    return 0;
}