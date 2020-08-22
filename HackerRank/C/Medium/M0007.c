/*
Problem Statement: https://www.hackerrank.com/challenges/variadic-functions-in-c/problem
*/

int sum(int count, ...) {
	int n = 0;
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++)
		n += va_arg(ap, int);
	va_end(ap);
	return n;
}

int min(int count, ...) {
	int curr, n = MAX_ELEMENT;
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++) {
		curr = va_arg(ap, int);
		if (curr < n)
			n = curr;
	}
	va_end(ap);
	return n;
}

int max(int count, ...) {
	int curr, n = MIN_ELEMENT;
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; i++) {
		curr = va_arg(ap, int);
		if (curr > n)
			n = curr;
	}
	va_end(ap);
	return n;
}