#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/sed-command-4/problem

sed -E "s/[0-9]+/x&x/4; s/\b[0-9]+\b/****/g; s/x([0-9]+)x/\1/"