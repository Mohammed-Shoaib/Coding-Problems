# Problem Statement: https://www.hackerrank.com/challenges/np-concatenate/problem

import numpy as np

N, M, P = np.array(input().split(), dtype='int32')
arr = np.array([input().split() for _ in range(N)], dtype='int32')
brr = np.array([input().split() for _ in range(M)], dtype='int32')
print(np.concatenate((arr, brr)))