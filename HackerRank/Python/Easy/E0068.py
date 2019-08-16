# Problem Statement: https://www.hackerrank.com/challenges/validating-named-email-addresses/problem

import re
from email.utils import parseaddr, formataddr

def validate(email):
	return re.match(r'[a-z][-.\w]*@[a-z]+\.[a-z]{1,3}$', email[1], re.IGNORECASE)

emails = [parseaddr(input()) for _ in range(int(input()))]
emails = filter(validate, emails)
emails = map(formataddr, emails)
print(*emails, sep='\n')