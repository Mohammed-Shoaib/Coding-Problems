# Problem Statement: https://www.hackerrank.com/challenges/np-eye-and-identity/problem

import numpy as np

np.set_printoptions(legacy='1.13')
N, M = np.array(input().split(), dtype='int32')
print(np.eye(N, M))