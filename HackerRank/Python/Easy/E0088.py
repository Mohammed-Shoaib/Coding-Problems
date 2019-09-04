# Problem Statement: https://www.hackerrank.com/challenges/detect-html-tags-attributes-and-attribute-values/problem

import sys
from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
	def handle_starttag(self, tag, attrs):
		print(tag)
		for attr in attrs:
			print('->', ' > '.join(attr))


N = input()
parser = MyHTMLParser()
parser.feed(sys.stdin.read())
parser.close()