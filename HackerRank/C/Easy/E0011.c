/*
Problem Statement: https://www.hackerrank.com/challenges/too-high-boxes/problem
*/

struct box {
	int length, width, height;
};

typedef struct box box;

int get_volume(box b) {
	return b.length * b.width * b.height;
}

int is_lower_than_max_height(box b) {
	return b.height < 41;
}