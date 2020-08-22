// Problem Statement: https://www.hackerrank.com/challenges/js10-template-literals/problem

function sides(literals, ...expressions) {
	let s1, s2, root, A, P;
	[A, P] = expressions;
	root = Math.sqrt(P * P - 16 * A);
	s1 = (P - root) / 4;
	s2 = (P + root) / 4;
	return [s1, s2];
}