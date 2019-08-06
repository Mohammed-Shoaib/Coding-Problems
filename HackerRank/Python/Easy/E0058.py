# Problem Statement: https://www.hackerrank.com/challenges/xml-1-find-the-score/problem

def get_attr_number(node):
	return sum(len(child.attrib) for child in node.iter())