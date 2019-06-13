# Problem Statement: https://www.hackerrank.com/challenges/string-validators/problem

S = input()
for cond in ['isalnum', 'isalpha', 'isdigit', 'islower', 'isupper']:
    print(any(getattr(c, cond)() for c in S))