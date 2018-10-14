/*
Problem Statement: https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>> &a, int rowStart, int rowEnd, int colStart,int colEnd, int r){
    vector<int> temp;
    for(int j=colEnd ; j>colStart ; j--)
        temp.push_back(a[rowStart][j]);
    for(int i=rowStart ; i<rowEnd ; i++)
        temp.push_back(a[i][colStart]);
    for(int j=colStart ; j<colEnd ; j++)
        temp.push_back(a[rowEnd][j]);
    for(int i=rowEnd ; i>rowStart ; i--)
        temp.push_back(a[i][colEnd]);
    int new_r = (r - 1) % temp.size() + 1;
    rotate(temp.begin(), temp.end()-new_r, temp.end());
    int k=0;
    for(int j=colEnd ; j>colStart ; j--, k++)
        a[rowStart][j] = temp[k];
    for(int i=rowStart ; i<rowEnd ; i++, k++)
        a[i][colStart] = temp[k];
    for(int j=colStart ; j<colEnd ; j++, k++)
        a[rowEnd][j] = temp[k];
    for(int i=rowEnd ; i>rowStart ; i--, k++)
        a[i][colEnd] = temp[k];

    if( (rowEnd - rowStart == 1) || (colEnd - colStart == 1) )
       return;
    else
        rotate(a, rowStart+1, rowEnd-1, colStart+1, colEnd-1, r);
}

void matrixRotation(vector<vector<int>> matrix, int r) {
    rotate(matrix, 0, matrix.size()-1, 0, matrix[0].size()-1, r);
    for(int i=0 ; i<matrix.size() ; i++){
        for(int j=0 ; j<matrix[i].size() ; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int m, n, r, num;
    vector<vector<int>> a;
    cin>>m>>n>>r;
    for(int i=0 ; i<m ; i++){
        a.push_back(vector<int>());
        for(int j=0 ; j<n ; j++){
            cin>>num;
            a[i].push_back(num);
        }
    }
    matrixRotation(a, r);
    return 0;
}