// Problem Code: TWTCLOSE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K, count;
	string s;
	count = 0;
	cin >> N >> K;
	cin.ignore();
	vector<bool> open(K);
	for(int i=1 ; i<=K ; i++){
		getline(cin, s);
		if(s == "CLOSEALL"){
			fill(open.begin(), open.end(), false);
			count = 0;
		}
		else{
			int tweet = stoi(s.substr(6));
			open[tweet-1] ? count-- : count++;
			open[tweet-1] = !open[tweet-1];
		}
		cout << count << endl;
	}
	return 0;
}