# Problem Statement: https://www.hackerrank.com/challenges/np-zeros-and-ones/problem

import numpy as np

shape = np.array(input().split(), dtype='int32')
print(np.zeros(shape, dtype='int8'))
print(np.ones(shape, dtype='int8'))