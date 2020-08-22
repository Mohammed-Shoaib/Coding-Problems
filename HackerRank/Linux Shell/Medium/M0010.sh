#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/awk-1/problem

awk '{
if ($4 == "")
	print "Not all scores are available for", $1
}'