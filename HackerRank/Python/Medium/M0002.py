# Problem Statement: https://www.hackerrank.com/challenges/the-minion-game/problem

def minion_game(S):
	kevin = stuart = 0

	for i in range(len(S)):
		if S[i] in 'AEIOU':
			kevin += len(S) - i
		else:
			stuart += len(S) - i

	if kevin > stuart:
		print('Kevin', kevin)
	elif kevin < stuart:
		print('Stuart', stuart)
	else:
		print('Draw')