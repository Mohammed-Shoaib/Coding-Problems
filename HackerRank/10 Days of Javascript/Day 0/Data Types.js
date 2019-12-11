// Problem Statement: https://www.hackerrank.com/challenges/js10-data-types/problem

function performOperation(secondInteger, secondDecimal, secondString) {
    const firstInteger = 4, firstDecimal = 4.0, firstString = 'HackerRank ';
    console.log(firstInteger + parseInt(secondInteger));
    console.log(firstDecimal + parseFloat(secondDecimal));
    console.log(firstString + secondString);
}