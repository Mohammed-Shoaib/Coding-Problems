# Problem Statement: https://www.hackerrank.com/challenges/finding-the-percentage/problem

def average(l):
    return sum(l) / len(l)


N = int(input())
Marks = {}
for _ in range(N):
    line = input().split()
    Marks[line[0]] = list(map(float, line[1:]))
print(f'{average(Marks[input()]):.2f}')