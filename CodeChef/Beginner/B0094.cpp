// Problem Code: VOWELTB

#include <iostream>

using namespace std;

string vowelOrConsonant(char c) {
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < 5; i++)
        if (c == vowels[i])
            return "Vowel";
    return "Consonant";
}

int main() {
    char c;
    cin >> c;
    cout << vowelOrConsonant(c);
    return 0;
}