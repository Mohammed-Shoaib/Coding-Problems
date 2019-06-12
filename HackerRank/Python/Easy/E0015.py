# Problem Statement: https://www.hackerrank.com/challenges/python-mutations/problem

def mutate_string(s, i, c):
    return s[:i] + c + s[i + 1:]