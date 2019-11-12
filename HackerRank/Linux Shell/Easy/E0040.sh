#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials-count-the-number-of-elements-in-an-array/problem

arr=( $(cat) )
echo "${#arr[@]}"