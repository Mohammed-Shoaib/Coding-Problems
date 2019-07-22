# Problem Statement: https://www.hackerrank.com/challenges/py-set-mutations/problem

_, A = int(input()), set(map(int, input().split()))

for _ in range(int(input())):
	cmd, _ = input().split()
	B = set(map(int, input().split()))
	getattr(A, cmd)(B)

print(sum(A))