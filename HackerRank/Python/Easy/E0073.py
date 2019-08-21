# Problem Statement: https://www.hackerrank.com/challenges/np-transpose-and-flatten/problem

import numpy as np

N, M = np.array(input().split(), dtype='int32')
arr = np.array([input().split() for _ in range(N)], dtype='int32')
print(np.transpose(arr))
print(arr.flatten())