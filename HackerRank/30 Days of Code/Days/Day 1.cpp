/*
Problem Statement: https://www.hackerrank.com/challenges/30-data-types/problem
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";

    int i2;
    double d2;
    string s2;
    
    cin >> i2 >> d2;
    cin.ignore();
    getline(cin, s2);
    
    i2 += i;
    d2 += d;
    s2 = s + s2;
    
    cout << fixed << setprecision(1);
    cout << i2 << endl;
    cout << d2 << endl;
    cout << s2;

    return 0;
}