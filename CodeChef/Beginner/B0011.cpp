// Problem Code: LUCKFOUR

#include <iostream>
#include <string>

using namespace std;

int luckyFour(int N){
	int count = 0;
	string s = to_string(N);
	for(char c : s)
		if(c == '4')
			count++;
	return count;
}

int main()
{
	int T, N;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N;
		cout << luckyFour(N) << endl;
	}
	return 0;
}