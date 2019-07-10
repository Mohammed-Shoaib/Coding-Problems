# Problem Statement: https://www.hackerrank.com/challenges/polar-coordinates/problem

from cmath import polar

z = complex(input())
r, phi = polar(z)
print(r, phi, sep='\n')