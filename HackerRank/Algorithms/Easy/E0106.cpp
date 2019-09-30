/*
Problem Statement: https://www.hackerrank.com/challenges/strange-code/problem
*/

#include <iostream>

using namespace std;

long long strangeCounter(long long t) {
    long long value, time;
    value = time = 3;
    while (time < t) {
        value *= 2;
        time += value;
    }
    return time - t + 1;
}

int main() {
    long long t;
    cin >> t;
    cout << strangeCounter(t);
	return 0;
}