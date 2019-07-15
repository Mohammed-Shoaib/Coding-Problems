# Problem Statement: https://www.hackerrank.com/challenges/py-collections-namedtuple/problem

from collections import namedtuple

N, fields = int(input()), input().split()
Student = namedtuple('Student', fields)
students = [Student(*input().split()) for _ in range(N)]
marks = [int(student.MARKS) for student in students]
print('%.2f' % (sum(marks) / N))