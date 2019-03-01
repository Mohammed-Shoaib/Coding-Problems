/*
Problem Statement: https://www.hackerrank.com/challenges/insertionsort1/problem
*/

#include <iostream>
#include <vector>

using namespace std;

void printArray(int n, vector<int> arr) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort1(int n, vector<int> arr) {
    bool flag;
    int key;
    for (int j, i = 1; i < n; i++) {
        key = arr[i];
        flag = (arr[i] < arr[i - 1]) ? true : false;
        for (j = i; j > 0 && key < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
            printArray(n, arr);
        }
        if (flag) {
            arr[j] = key;
            printArray(n, arr);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    insertionSort1(n, arr);
    return 0;
}