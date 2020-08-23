// Problem Code: COMM3

#include <iostream>
#include <cmath>

using namespace std;

string threeWayCommunications(int R, int X1, int Y1, int X2, int Y2, int X3, int Y3){
	float a = sqrt(pow(X1-X2, 2) + pow(Y1-Y2, 2));
	float b = sqrt(pow(X2-X3, 2) + pow(Y2-Y3, 2));
	float c = sqrt(pow(X3-X1, 2) + pow(Y3-Y1, 2));
	if( (a<=R && b<=R) || (b<=R && c<=R) || (a<=R && c<=R) )
		return "yes";
	else
		return "no";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, R, X1, Y1, X2, Y2, X3, Y3;
	cin >> T;
	for(int i=1 ; i<=T ; i++){
		cin >> R >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
		cout << threeWayCommunications(R, X1, Y1, X2, Y2, X3, Y3) << endl;
	}
	return 0;
}