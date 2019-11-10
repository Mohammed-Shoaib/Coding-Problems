#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-2/problem

uniq -c | tr -s ' ' | cut -b 2-