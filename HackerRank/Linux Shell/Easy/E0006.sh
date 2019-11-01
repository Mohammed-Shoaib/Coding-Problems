#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials---getting-started-with-conditionals/problem

read -n1 c

if [ "${c,,}" == "y" ]; then
    echo "YES"
else
    echo "NO"
fi