# Problem Statement: https://www.hackerrank.com/challenges/most-commons/problem

from collections import Counter

counts = sorted(Counter(input()).items(), key=lambda count: (-count[1], count[0]))[:3]

for count in counts:
	print(*count)