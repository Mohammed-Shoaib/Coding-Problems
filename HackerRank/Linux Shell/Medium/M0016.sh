#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials---compute-the-average/problem

awk '{
if (NR == 1)
	N = $1
else
	avg += $1
} END {
printf "%0.3f", avg / N
}'