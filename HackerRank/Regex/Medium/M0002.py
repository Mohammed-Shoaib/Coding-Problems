# Problem Statement: https://www.hackerrank.com/challenges/find-a-word/problem

import re

sentence = '\n'.join([input() for _ in range(int(input()))])

for _ in range(int(input())):
    words = re.findall(r'(?<!\w)' + input() + r'(?!\w)', sentence)
    print(len(words))