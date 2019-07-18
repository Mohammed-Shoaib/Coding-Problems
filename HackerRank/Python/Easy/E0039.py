# Problem Statement: https://www.hackerrank.com/challenges/py-set-discard-remove-pop/problem

_, s = int(input()), set(map(int, input().split()))

for _ in range(int(input())):
	cmd, *args = input().split()
	getattr(s, cmd)(*map(int, args))

print(sum(s))