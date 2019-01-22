/*
Problem Statement: https://www.hackerrank.com/challenges/time-conversion/problem
*/

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

void timeConversion(string s) {
    int hr, min, sec;
    bool meridiem = (s.substr(s.length()-2) == "PM") ? true: false;
    sscanf (s.c_str(), "%d:%d:%d", &hr, &min, &sec);
    if(meridiem && hr != 12)
        hr += 12;
    else if(!meridiem && hr == 12)
        hr = 0;
    printf("%02d:%02d:%02d", hr, min, sec);
}

int main()
{
    string s;
    getline(cin,s);
    timeConversion(s);
    return 0;
}