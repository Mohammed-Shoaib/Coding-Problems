# Problem Statement: https://www.hackerrank.com/challenges/np-inner-and-outer/problem

import numpy as np

A = np.array(input().split(), dtype='int32')
B = np.array(input().split(), dtype='int32')
print(np.inner(A, B), np.outer(A, B), sep='\n')