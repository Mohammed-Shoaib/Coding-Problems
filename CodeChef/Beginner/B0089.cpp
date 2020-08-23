// Problem Code: TEMPLELA

#include <iostream>
#include <vector>

using namespace std;

string templeLand(vector<int> H) {
	if(H.size() % 2 == 0 || H[0] != 1 || H[0] != H[H.size()-1])
		return "no";
	for(int i=1, j=H.size()-2 ; i<=H.size()/2 ; i++,j--)
		if(H[i] != H[j] || H[i] != H[i-1] + 1)
			return "no";
	return "yes";
}

int main(){
	int S, N, num;
	vector<int> H;
	cin >> S;
	while(S--) {
		cin >> N;
		for(int i=0 ; i<N ; i++) {
			cin >> num;
			H.push_back(num);
		}
		cout << templeLand(H) << endl;
		H.clear();
	}
	return 0;
}