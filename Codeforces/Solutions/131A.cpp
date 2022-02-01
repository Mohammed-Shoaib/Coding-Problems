// Problem Code: 131A
 
#include <iostream>
#include <string>

using namespace std;

string cAPS_lOCK(string word) {
	bool is_upper = true;
	
	for (int i = 1; i < word.length(); i++)
		is_upper &= isupper(word[i]) != 0;
	
	if (is_upper) {
		for (char& c: word) {
			if (islower(c))
				c = toupper(c);
			else
				c = tolower(c);
		}
	}
	
	return word;
}

int main() {
	string word;
	cin >> word;
	cout << cAPS_lOCK(word);
	return 0;
}