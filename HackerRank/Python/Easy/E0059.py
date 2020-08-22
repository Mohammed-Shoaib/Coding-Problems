# Problem Statement: https://www.hackerrank.com/challenges/xml2-find-the-maximum-depth/problem

maxdepth = 0
def depth(elem, level):
	global maxdepth
	level += 1
	maxdepth = max(level, maxdepth)
	for child in elem:
		depth(child, level)