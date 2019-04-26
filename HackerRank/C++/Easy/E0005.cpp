/*
Problem Statement: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
*/

#include <iostream>

using namespace std;

int main() {
    int a, b;
    string nos [] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (i <= 9)
            cout << nos[i] << endl;
        else if(i & 1)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
    return 0;
}