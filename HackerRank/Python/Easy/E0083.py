# Problem Statement: https://www.hackerrank.com/challenges/np-polynomials/problem

import numpy as np

coeff, x = np.array(input().split(), dtype='float64'), float(input())
print(np.polyval(coeff, x))