# Problem Statement: https://www.hackerrank.com/challenges/np-dot-and-cross/problem

import numpy as np

N = int(input())
A = np.array([input().split() for _ in range(N)], dtype='int32')
B = np.array([input().split() for _ in range(N)], dtype='int32')
print(np.matmul(A, B))