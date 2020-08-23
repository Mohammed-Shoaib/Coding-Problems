// Problem Code: NAME2

#include <iostream>
#include <string>

using namespace std;

string canMarry(string M, string W){
	int i, j;
	if(M.length() == W.length())
		return (M == W) ? "YES" : "NO";
	else if(M.length() > W.length()){
		string temp = M;
		M = W;
		W = temp;
	}
	for(i=0, j=0 ; i<M.length() && j<W.length() ; j++)
		if(M[i] == W[j])
			i++;
	return (i == M.length()) ? "YES" : "NO";
}

int main(){
	int T;
	string M, W;
	cin >> T;
	while(T--){
		cin >> M >> W;
		cout << canMarry(M, W) << endl;
	}
	return 0;
}