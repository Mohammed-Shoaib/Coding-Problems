# Problem Statement: https://www.hackerrank.com/challenges/programming-language-detection/problem

import re
import sys

code = sys.stdin.read()

if re.search(r'#include', code):
	print('C')
elif re.search('import', code):
	print('Java')
else:
	print('Python')