// Problem Statement: https://www.hackerrank.com/challenges/js10-try-catch-and-finally/problem

function reverseString(s) {
	try {
		s = s.split('').reverse().join('');
	} catch (e) {
		console.log(e.message);
	} finally {
		console.log(s);
	}
}