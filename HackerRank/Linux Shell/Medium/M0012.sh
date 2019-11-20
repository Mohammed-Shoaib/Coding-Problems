#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/awk-3/problem

awk '{
printf "%s : ", $0
avg = ($2 + $3 + $4) / 3
if (avg >= 80)
    print "A"
else if (avg >= 60)
    print "B"
else if (avg >= 50)
    print "C"
else
    print "FAIL"
}'