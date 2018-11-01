// Problem Code: CIELRCPT

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cielAndReceipt(int p){
    int menus = p / 2048;
    if(menus != 0)
        p = p % 2048;
    while(p != 0){
        if(p & 1)
            menus++;
        p >>= 1;
    }
    return menus;
}

int main()
{
    int T, p;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> p;
        cout << cielAndReceipt(p) << endl;
    }
    return 0;
}