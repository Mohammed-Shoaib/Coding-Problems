/*
Problem Statement: https://www.hackerrank.com/challenges/arrays-introduction/problem
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    reverse(A, A + N);
    for (int i = 0; i < N; i++)
        cout << A[i] << " ";
    return 0;
}