# Problem Statement: https://www.hackerrank.com/challenges/find-a-string/problem

import re

def count_substring(string, sub_string):
    return len(re.findall('(?=' + sub_string + ')', string))