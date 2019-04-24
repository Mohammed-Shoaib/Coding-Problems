/*
Problem Statement: https://www.hackerrank.com/challenges/inherited-code/problem
*/

class BadLengthException: public exception {
private:
    int n;
public:
    BadLengthException(int n) {
        this->n = n;
    }

    int what() {
        return n;
    }
};