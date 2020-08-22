// Problem Statement: https://www.hackerrank.com/challenges/js10-arrays/problem

function getSecondLargest(nums) {
	let first = 0, second = 0;
	for (let num of nums) {
		if (first < num) {
			second = first;
			first = num;
		} else if (num < first && second < num) {
			second = num;
		}
	}
	return second;
}