#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials-filter-an-array-with-patterns/problem

grep -i "^[^a]*$"

if [ $? -eq 1 ]; then   # grep sets $? to 1 if there were no matches
    echo ""
fi