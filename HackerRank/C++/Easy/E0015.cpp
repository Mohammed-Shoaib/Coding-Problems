/*
Problem Statement: https://www.hackerrank.com/challenges/box-it/problem
*/

class Box {
private:
	int l, b, h;
public:
	Box() {
		l = b = h = 0;
	}

	Box(int l, int b, int h) {
		this->l = l;
		this->h = h;
		this->b = b;
	}

	Box(Box &b) {
		this->l = b.l;
		this->b = b.b;
		this->h = b.h;
	}

	int getLength() {
		return l;
	}

	int getBreadth() {
		return b;
	}

	int getHeight() {
		return h;
	}

	long long CalculateVolume() {
		return (long long) l * b * h;
	}

	bool operator< (Box &B) {
		if (l == B.l) {
			if (b == B.b)
				return h < B.h;
			else
				return b < B.b;
		}
		else
			return l < B.l;
	}

	friend ostream& operator<< (ostream &os, Box &B) {
		os << B.l << " " << B.b << " " << B.h;
		return os;
	}
};