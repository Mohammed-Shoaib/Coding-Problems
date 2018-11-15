// Problem Code: SUMTRIAN

#include <iostream>
#include <vector>

using namespace std;

int largestSum(vector<vector<int>> &triangle){
    for(int i=triangle.size()-1 ; i>0 ; i--){
        for(int j=0 ; j<triangle[i].size()-1 ; j++)
            triangle[i-1][j] += max(triangle[i][j], triangle[i][j+1]);
    }
    return triangle[0][0];
}

int main()
{
    int n, t, num;
    vector<vector<int>> triangle;
    cin >> n;
    while(n--){
        cin >> t;
        for(int i=0 ; i<t ; i++){
            triangle.push_back(vector<int>());
            for(int j=0 ; j<=i ; j++){
                cin >> num;
                triangle[i].push_back(num);
            }
        }
        cout << largestSum(triangle) << endl;
        triangle.clear();
    }
    return 0;
}