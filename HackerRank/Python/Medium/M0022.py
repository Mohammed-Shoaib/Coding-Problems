# Problem Statement: https://www.hackerrank.com/challenges/default-arguments/problem

def print_from_stream(n, stream=EvenStream()):
	stream.__init__()
	for _ in range(n):
		print(stream.get_next())