# Problem Statement: https://www.hackerrank.com/challenges/np-linear-algebra/problem

import numpy as np

np.set_printoptions(legacy='1.13')
A = np.array([input().split() for _ in range(int(input()))], dtype='float32')
print(np.linalg.det(A))