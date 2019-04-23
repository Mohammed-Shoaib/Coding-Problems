/*
Problem Statement: https://www.hackerrank.com/challenges/the-time-in-words/problem
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string timeInWords(int h, int m) {
    vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    vector<string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens = "twenty";
    string time, hour;
    int n = (m<30) ? m : 60-m;
    if(m == 15 || m == 45)
        time += "quarter";
    else if(m == 30)
        time += "half";
    else{
        if(n > 0 && n < 10)
            time += ones[n];
        else if(n < 20)
            time += teens[n-10];
        else
            time += tens + " " + ones[n%10];
        time += " minute";
        time += (m == 1) ? "" : "s";
    }
    if(m <= 30){
        time += " past ";
        n = h;
    }else{
        time += " to ";
        n = h+1;
    }
    n = (n <= 12) ? n : n-12;
    if(n == 0)
        hour = teens[2];
    else if(n > 0 && n < 10)
        hour = ones[n];
    else
        hour = teens[n-10];
    if(m == 0)
        time = hour + " o' clock";
    else
        time += hour;
    return time;
}

int main()
{
    int h, m;
    cin>>h>>m;
    cout<<timeInWords(h, m);
    return 0;
}