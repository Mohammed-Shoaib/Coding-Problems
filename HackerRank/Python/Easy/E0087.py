# Problem Statement: https://www.hackerrank.com/challenges/html-parser-part-2/problem

import sys
from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
	def handle_data(self, data):
		if data != '\n':
			print(f'>>> Data\n{data}')

	def handle_comment(self, data):
		if '\n' in data:
			print('>>> Multi-line Comment')
		else:
			print('>>> Single-line Comment')
		print(data)


N = input()
parser = MyHTMLParser()
parser.feed(sys.stdin.read())
parser.close()