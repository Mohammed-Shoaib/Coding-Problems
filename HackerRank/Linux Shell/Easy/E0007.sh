#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials---comparing-numbers/problem

read X
read Y

if (($X > $Y)); then
    echo "X is greater than Y"
elif (($X == $Y)); then
    echo "X is equal to Y"
else
    echo "X is less than Y"
fi