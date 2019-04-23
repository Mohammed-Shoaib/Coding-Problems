/*
Problem Statement: https://www.hackerrank.com/challenges/day-of-the-programmer/problem
*/

#include <iostream>
#include <string>

using namespace std;

string dayOfProgrammer(int y) {
    int d, m;
    string s;
    d = 13;
    m = 9;
    if (y == 1918)
        d += 13;
    else if (y > 1918 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
        d -= 1;
    else if (y < 1918 && y % 4 == 0)
        d -= 1;
    s = to_string(d) + ".0" + to_string(m) + "." + to_string(y);
    return s;
}

int main() {
    int y;
    cin >> y;
    cout << dayOfProgrammer(y);
    return 0;
}