# Problem Statement: https://www.hackerrank.com/challenges/decorators-2-name-directory/problem

def person_lister(f):
	def inner(people):
		people.sort(key=lambda x: int(x[2]))
		return map(f, people)
	return inner