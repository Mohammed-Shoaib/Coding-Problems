# Problem Statement: https://www.hackerrank.com/challenges/hackerrank-language/problem

import re

for _ in range(int(input())):
	langs = 'C:CPP:JAVA:PYTHON:PERL:PHP:RUBY:CSHARP:HASKELL:CLOJURE:BASH:SCALA:ERLANG:CLISP:LUA:BRAINFUCK:JAVASCRIPT:GO:D:OCAML:R:PASCAL:SBCL:DART:GROOVY:OBJECTIVEC'.replace(':', '|')
	print('VALID' if re.search(f' ({langs})$', input()) else 'INVALID')