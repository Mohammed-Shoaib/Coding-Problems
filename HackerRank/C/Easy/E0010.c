/*
Problem Statement: https://www.hackerrank.com/challenges/students-marks-sum/problem
*/

int marks_summation(int* marks, int n, char gender) {
    int sum = 0;
    for (int i = (gender == 'g'); i < n; i += 2)
        sum += marks[i];
    return sum;
}