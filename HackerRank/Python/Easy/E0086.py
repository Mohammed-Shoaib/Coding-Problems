# Problem Statement: https://www.hackerrank.com/challenges/html-parser-part-1/problem

import sys
from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
	def handle_starttag(self, tag, attrs):
		print('Start :', tag)
		for attr in attrs:
			print('->', attr[0], '>', attr[1])

	def handle_endtag(self, tag):
		print('End   :', tag)

	def handle_startendtag(self, tag, attrs):
		print('Empty :', tag)
		for attr in attrs:
			print('->', attr[0], '>', attr[1])


N = input()
parser = MyHTMLParser()
parser.feed(sys.stdin.read())
parser.close()