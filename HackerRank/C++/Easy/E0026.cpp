/*
Problem Code: https://www.hackerrank.com/challenges/c-class-templates/problem
*/

template <class T>
class AddElements {
private:
	T value;
public:
	AddElements(T value) {
		this->value = value;
	}

	T add(T v2) {
		return value + v2;
	}
};

template <>
class AddElements <string> {
private:
	string s;
public:
	AddElements(string s) {
		this->s = s;
	}

	string concatenate(string s2) {
		return s + s2;
	}
};