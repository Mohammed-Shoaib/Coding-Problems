# Problem Statement: https://www.hackerrank.com/challenges/python-time-delta/problem

from datetime import datetime

for _ in range(int(input())):
	t1, t2 = (datetime.strptime(input(), "%a %d %b %Y %H:%M:%S %z") for _ in range(2))
	sec = int(abs((t1 - t2).total_seconds()))
	print(sec)