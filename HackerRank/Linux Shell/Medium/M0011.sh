#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/awk-2/problem

awk '{
printf "%s : ", $1
if ($2 >= 50 && $3 >= 50 && $4 >= 50)
    print "Pass"
else
    print "Fail"
}'