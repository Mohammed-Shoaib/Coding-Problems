# Problem Statement: https://www.hackerrank.com/challenges/list-comprehensions/problem

X, Y, Z, N = (int(input()) for _ in range(4))
l = [[i, j, k] for i in range(X + 1) for j in range(Y + 1) for k in range(Z + 1) if i + j + k != N]
print(l)