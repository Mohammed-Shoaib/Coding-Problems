# Problem Statement: https://www.hackerrank.com/challenges/find-angle/problem

from math import atan2, degrees

AB, BC = int(input()), int(input())
MBC = round(degrees(atan2(AB, BC)))
print(f'{MBC}°')