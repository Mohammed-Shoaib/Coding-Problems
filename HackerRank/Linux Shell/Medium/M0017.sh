#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials---arithmetic-operations/problem

read exp
printf "%0.3f" "$(echo $exp | bc -l)"