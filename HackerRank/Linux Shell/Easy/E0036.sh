#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials-read-in-an-array/problem

arr=( $(cat) )
echo "${arr[@]}"