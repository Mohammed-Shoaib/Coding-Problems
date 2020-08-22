// Problem Statement: https://www.hackerrank.com/challenges/js10-if-else/problem

function getGrade(score) {
	if (score > 25)
		return 'A';
	else if (score > 20)
		return 'B';
	else if (score > 15)
		return 'C';
	else if (score > 10)
		return 'D';
	else if (score > 5)
		return 'E';
	else
		return 'F';
}