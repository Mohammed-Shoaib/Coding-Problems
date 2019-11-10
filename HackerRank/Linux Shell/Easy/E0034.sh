#!/bin/bash
# Problem Statement: https://www.hackerrank.com/challenges/text-processing-in-linux-the-uniq-command-3/problem

uniq -i -c | tr -s ' ' | cut -b 2-