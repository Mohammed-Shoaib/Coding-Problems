// Problem Statement: https://www.hackerrank.com/challenges/js10-count-objects/problem

function getCount(objects) {
	let count = 0;
	for (let o of objects)
		if (o.x === o.y)
			count++;
	return count;
}