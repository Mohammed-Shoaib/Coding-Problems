/*
Problem Statement: https://www.hackerrank.com/challenges/playing-with-characters/problem
*/

#include <stdio.h>

int main() {
	char ch;
	char s[20], sen[100];
	scanf("%c", &ch);
	scanf("%s%*c", s);
	fgets(sen, sizeof(sen), stdin);
	printf("%c\n%s\n%s", ch, s, sen);
	return 0;
}