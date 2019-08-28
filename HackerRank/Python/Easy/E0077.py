# Problem Statement: https://www.hackerrank.com/challenges/floor-ceil-and-rint/problem

import numpy as np

np.set_printoptions(legacy='1.13')
A = np.array(input().split(), dtype='float32')
print(np.floor(A), np.ceil(A), np.rint(A), sep='\n')