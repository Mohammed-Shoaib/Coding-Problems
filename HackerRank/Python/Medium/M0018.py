# Problem Statement: https://www.hackerrank.com/challenges/validate-list-of-email-address-with-filter/problem

import re

def fun(s):
	return re.match(r'[-\w]+@[a-z\d]+\.[a-z]{1,3}$', s, re.IGNORECASE)