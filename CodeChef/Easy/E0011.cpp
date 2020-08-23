// Problem Code: NUKES

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int A, N, K;
	cin >> A >> N >> K;
	vector<int> chambers(K);
	for(int i=0 ; i<K ; i++){
		chambers[i] = A % (N+1);
		A /= N+1;
	}
	for(int i=0 ; i<chambers.size() ; i++)
		cout << chambers[i] << " ";
	return 0;
}