# Problem Statement: https://www.hackerrank.com/challenges/np-mean-var-and-std/problem

import numpy as np

np.set_printoptions(legacy='1.13')
N, M = np.array(input().split(), dtype='int32')
arr = np.array([input().split() for _ in range(N)], dtype='int32')
print(np.mean(arr, axis=1), np.var(arr, axis=0), np.std(arr), sep='\n')