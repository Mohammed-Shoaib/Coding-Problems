#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials-remove-the-first-capital-letter-from-each-array-element/problem

sed -E "s/[A-Z]/./" | paste -s -d ' '