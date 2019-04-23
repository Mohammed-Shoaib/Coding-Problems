// Problem Code: FLOW011

#include <iostream>
#include <stdio.h>

using namespace std;

double grossSalary(int salary){
    double hra, da;
    if(salary < 1500){
        hra = salary*0.1;
        da = salary*0.9;
    }else{
        hra = 500;
        da = salary*0.98;
    }
    return salary + hra + da;
}

int main()
{
    int T, salary;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> salary;
        printf("%.2f\n", grossSalary(salary));
    }
    return 0;
}