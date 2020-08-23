// Problem Code: INTEST

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, t, count = 0;
	cin >> n >> k;
	for(int i=1 ; i<=n ; i++){
		cin >> t;
		if(t % k == 0)
			count++;
	}
	cout << count;
	return 0;
}