// Problem Code: FLOW014

#include <iostream>

using namespace std;

int gradeTheSteel(int hardness, float carbon, int strength) {
	bool c1, c2, c3;
	c1 = (hardness > 50) ? true : false;
	c2 = (carbon < 0.7) ? true : false;
	c3 = (strength > 5600) ? true : false;
	if(c1 && c2 && c3)
		return 10;
	else if(c1 && c2)
		return 9;
	else if(c2 && c3)
		return 8;
	else if(c1 && c3)
		return 7;
	else if(c1 || c2 || c3)
		return 6;
	else
		return 5;
}

int main() {
	int T, hardness, strength;
	float carbon;
	cin >> T;
	while(T--) {
		cin >> hardness >> carbon >> strength;
		cout << gradeTheSteel(hardness, carbon, strength) << endl;
	}
	return 0;
}