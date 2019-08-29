# Problem Statement: https://www.hackerrank.com/challenges/np-sum-and-prod/problem

import numpy as np

N, M = np.array(input().split(), dtype='int32')
arr = np.array([input().split() for _ in range(N)], dtype='int32')
print(np.prod(np.sum(arr, axis=0)))