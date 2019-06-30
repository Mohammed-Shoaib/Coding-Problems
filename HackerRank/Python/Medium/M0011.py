# Problem Statement: https://www.hackerrank.com/challenges/word-order/problem

from collections import OrderedDict

d = OrderedDict()

for _ in range(int(input())):
	w = input()
	d[w] = d.get(w, 0) + 1

print(len(d))
print(*d.values())