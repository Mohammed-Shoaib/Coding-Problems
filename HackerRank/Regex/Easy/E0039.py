# Problem Statement: https://www.hackerrank.com/challenges/html-attributes/problem

import re
import sys
from collections import defaultdict

_ = input()
tags = defaultdict(set)

for match in re.findall(r'<(\w+)((?:\s\w+=.*?)*)>', sys.stdin.read()):
	tags[match[0]].update(re.findall(r'\s(\w+)=', match[1]))

for tag, attributes in sorted(tags.items()):
	attributes = ','.join(sorted(attributes))
	print(f'{tag}:{attributes}')