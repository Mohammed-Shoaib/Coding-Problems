def tetrahedral(n):
	return n * (n + 1) * (n + 2) // 6 

def pyramids(n, m):
	return tetrahedral(n) - tetrahedral(m)

with open("pyramids.in", "r") as fin:
	with open("output.out", "w") as fout:
		n, m = map(int, fin.readline().split())
		while n or m:
			fout.write(f'{pyramids(n, m)}\n')
			n, m = map(int, fin.readline().split())