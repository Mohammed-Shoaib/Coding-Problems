// Problem Code: MUFFINS3

#include <iostream>

using namespace std;

int main()
{
	int T, N;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> N;
		cout << (N/2 + 1) << endl;
	}
	return 0;
}