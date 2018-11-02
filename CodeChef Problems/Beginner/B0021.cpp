// Problem Code: RECIPE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cuttingRecipes(vector<int> &ingredients){
    int gcd = ingredients[0];
    for(int i=1 ; i<ingredients.size() ; i++)
        gcd = __gcd(ingredients[i], gcd);
    if(gcd == 1)
        return;
    for(int i=0 ; i<ingredients.size() ; i++)
        ingredients[i] /= gcd;
}

int main()
{
    int T, N, num;
    vector<int> ingrediants, results;
    cin >> T;
    for(int i=1 ; i<=T ; i++){
        cin >> N;
        for(int i=0 ; i<N ; i++){
            cin >> num;
            ingrediants.push_back(num);
        }
        cuttingRecipes(ingrediants);
        for(int i=0 ; i<ingrediants.size() ; i++)
            cout << ingrediants[i] << " ";
        cout << endl;
        ingrediants.clear();
    }
    return 0;
}