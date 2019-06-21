# Problem Statement: https://www.hackerrank.com/challenges/compress-the-string/problem

from itertools import groupby

for key, group in groupby(input()):
	print((len(list(group)), int(key)), end=' ')