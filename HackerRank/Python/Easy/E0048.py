# Problem Statement: https://www.hackerrank.com/challenges/python-mod-divmod/problem

d = divmod(int(input()), int(input()))
print(*d, d, sep='\n')