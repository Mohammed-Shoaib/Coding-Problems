# Problem Statement: https://www.hackerrank.com/challenges/np-array-mathematics/problem

import numpy as np

N, M = np.array(input().split(), dtype='int32')
A = np.array([input().split() for _ in range(N)], dtype='int32')
B = np.array([input().split() for _ in range(N)], dtype='int32')
print(A + B, A - B, A * B, A // B, A % B, A**B, sep='\n')