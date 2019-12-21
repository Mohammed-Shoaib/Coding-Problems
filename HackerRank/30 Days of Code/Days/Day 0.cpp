/*
Problem Statement: https://www.hackerrank.com/challenges/30-hello-world/problem
*/

#include <iostream>
#include <string>

using namespace std;

int main () {
    string s;
    getline(cin, s);
    cout << "Hello, World." << endl;
    cout << s << endl;
    return 0;
}