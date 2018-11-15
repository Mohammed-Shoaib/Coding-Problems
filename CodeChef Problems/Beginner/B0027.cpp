// Problem Code: FLOW010

#include <iostream>
#include <ctype.h>
#include <string>
#include <unordered_map>

using namespace std;

string idAndShip(char c, unordered_map<char, string> &map){
    c = toupper(c);
    return map.at(c);
}

void constructMap(unordered_map<char, string> &map){
    map['B'] = "BattleShip";
    map['C'] = "Cruiser";
    map['D'] = "Destroyer";
    map['F'] = "Frigate";
}

int main()
{
    int T;
    char c;
    unordered_map<char, string> map;
    constructMap(map);
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> c;
        cout << idAndShip(c, map) << endl;
    }
    return 0;
}