# Problem Statement: https://www.hackerrank.com/challenges/python-string-formatting/problem

def print_formatted(N):
    l = N.bit_length()
    for i in range(1, N + 1):
        print(f'{i:{l}d} {i:{l}o} {i:{l}X} {i:{l}b}')