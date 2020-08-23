// Problem Code: CIELAB

#include <iostream>
#include <string>

using namespace std;

string cielsWaiter(int A, int B){
	string s = to_string(A - B);
	int first = s[0] - '0';
	if(first){
		if(first == 9)
			first--;
		else
			first++;
	}
	else
		first++;
	s[0] = first + '0';     
	return s;
}

int main()
{
	int A, B;
	cin >> A >> B;
	cout << cielsWaiter(A, B);
	return 0;
}