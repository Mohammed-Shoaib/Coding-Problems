#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials---more-on-conditionals/problem

arr=($(cat -| sort -u))

if (("${#arr[@]}" == 3)); then
    echo "SCALENE"
elif (("${#arr[@]}" == 2)); then
    echo "ISOSCELES"
else
    echo "EQUILATERAL"
fi