// Problem Statement: https://www.hackerrank.com/challenges/js10-objects/problem

function Rectangle(a, b) {
    this.length = a;
    this.width = b;
    this.perimeter = 2 * (a + b);
    this.area = a * b;
}