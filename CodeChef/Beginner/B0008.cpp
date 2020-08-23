// Problem Code: TLG

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void theLeadGame(vector<int> S, vector<int> T){
	int winner, lead, p1, p2;
	lead = p1 = p2 = 0;
	for(int i=0 ; i<S.size() ; i++){
		p1 += S[i];
		p2 += T[i];
		if(abs(p1-p2) > lead){
			lead = abs(p1 - p2);
			winner = (p1 > p2) ? 1 : 2;
		}
	}
	cout << winner << " " << lead;
}

int main()
{
	int N, num;
	vector<int> S, T;
	cin >> N;
	for(int i=1 ; i<=N ; i++){
		cin >> num;
		S.push_back(num);
		cin >> num;
		T.push_back(num);
	}
	theLeadGame(S, T);
	return 0;
}