// Problem Statement: https://www.hackerrank.com/challenges/js10-arrows/problem

function modifyArray(nums) {
	return nums.map(num => (num & 1) ? num * 3 : num * 2);
}