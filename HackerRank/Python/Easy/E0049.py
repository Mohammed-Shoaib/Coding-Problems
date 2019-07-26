# Problem Statement: https://www.hackerrank.com/challenges/python-power-mod-power/problem

a, b, m = (int(input()) for _ in range(3))
print(pow(a, b), pow(a, b, m), sep='\n')