# Problem Statement: https://www.hackerrank.com/challenges/ginorts/problem

S = ''.join(sorted(input(), key=lambda x: (not x.islower(),
										   not x.isupper(),
										   not x in '13579',
										   x)))
print(S)