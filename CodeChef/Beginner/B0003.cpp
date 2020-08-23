// Problem Code: FCTRL2

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string fact(int n){
	int num, temp, len, i;
	vector<int> prod;
	string result;
	i = 0;
	temp = n;
	while(temp){
		prod.push_back(temp % 10);
		temp /= 10;
		i++;
	}
	len = i;
	for(int j=2 ; j<n ; j++){
		temp = i = 0;
		while(i < len){
			num = prod[i] * j + temp;
			prod[i] = num % 10;
			temp = num / 10;
			i++;
		}
		while(temp){
			prod.push_back(temp % 10);
			temp /= 10;
			i++;
		}
		len = i;
	}
	reverse(prod.begin(), prod.end());
	for(i=0 ; i<prod.size() ; i++)
		result += to_string(prod[i]);
	return result;
}

int main()
{
	int t, n;
	cin >> t;
	for(int i=1 ; i<=t ; i++){
		cin >> n;
		cout << fact(n) << endl;
	}
	return 0;
}