# Problem Statement: https://www.hackerrank.com/challenges/alphabet-rangoli/problem

import string

def print_rangoli(N):
	lines = []
	for i in range(N):
		line = string.ascii_lowercase[i:N]
		line = line[-1:0:-1] + line
		line = '-'.join(line).center(4*N - 3, '-')
		lines.append(line)
	lines = lines[-1:0:-1] + lines
	print('\n'.join(lines))