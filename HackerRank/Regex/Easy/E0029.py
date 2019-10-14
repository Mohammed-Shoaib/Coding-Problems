# Problem Statement: https://www.hackerrank.com/challenges/ip-address-validation/problem

import re

for _ in range(int(input())):
	line = input()
	ipv4 = re.match(r'([1]?\d{1,2}|[2][0-5]{2})(\.([1]?\d{1,2}|[2][0-5]{2})){3}$', line)
	ipv6 = re.match(r'[\da-f]{1,4}(:[\da-f]{1,4}){7}$', line)
	print('IPv4' if ipv4 else 'IPv6' if ipv6 else 'Neither')