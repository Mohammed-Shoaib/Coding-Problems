// Problem Code: OJUMPS

#include <iostream> 

using namespace std;

int main(){
	long a;
	cin >> a;
	if( !(a % 3) || !((a - 1) % 6) )
		cout << "yes";
	else
		cout << "no";
	return 0;
}