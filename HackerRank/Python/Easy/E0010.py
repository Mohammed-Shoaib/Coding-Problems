# Problem Statement: https://www.hackerrank.com/challenges/python-lists/problem

n = int(input())
l = []
for _ in range(n):
    cmd = input().split()
    if cmd[0] == 'print':
        print(l)
    else:
        getattr(l, cmd[0])(*(map(int, cmd[1:])))