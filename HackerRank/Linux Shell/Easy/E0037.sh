#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/bash-tutorials-slice-an-array/problem

arr=( $(cat) )
echo "${arr[@]:3:5}"