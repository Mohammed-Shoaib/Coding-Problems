/*
Problem Code: https://www.hackerrank.com/challenges/overload-operators/problem
*/

Complex operator+(Complex &x, Complex &y) {
	return {x.a + y.a, x.b + y.b};
}

ostream& operator<<(ostream &os, Complex &z) {
	os << z.a << "+i" << z.b;
	return os;
}