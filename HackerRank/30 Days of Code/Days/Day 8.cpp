/*
Problem Statement: https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, d;
    string name;
    unordered_map<string, int> map;

    cin >> n;
    while (n--) {
        cin >> name >> d;
        map[name] = d;
    }
    while (cin >> name) {
        if (map.find(name) != map.end())
            cout << name << "=" << map[name] << endl;
        else
            cout << "Not found" << endl;
    }
    
    return 0;
}