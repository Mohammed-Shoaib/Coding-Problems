/*
Problem Statement: https://www.hackerrank.com/challenges/grading/problem
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> gradingStudents(vector<int> grades) {
    for(int i=0 ; i<grades.size() ; i++){
        if(grades[i] < 38)
            continue;
        else if(grades[i]%5 >= 3)
            grades[i] += 5 - grades[i]%5;
    }
    return grades;
}

int main()
{
    int len,num;
    vector<int> grades;
    cin>>len;
    for(int i=0 ; i<len ; i++){
        cin>>num;
        grades.push_back(num);
    }
    grades = gradingStudents(grades);
    for(int grade: grades)
        cout<<grade<<endl;
    return 0;
}
