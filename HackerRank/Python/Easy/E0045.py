# Problem Statement: https://www.hackerrank.com/challenges/py-the-captains-room/problem

seen, cap = set(), set()
_, rooms = int(input()), map(int, input().split())

for room in rooms:
	if room in seen:
		cap.discard(room)
	else:
		seen.add(room)
		cap.add(room)

print(*cap)