#!/bin/sh

# compile the cpp file
file_name="traffic_signaling"
g++ -std=c++14 -O2 -Wall $file_name.cpp -o $file_name.o

# only run on test files if specified
if [ "$1" != "y" ]; then
	exit
fi
sum=0

# run the program on individual test files
for x in {a..f}
do
	echo -n "Running $x: "
	score=$(./$file_name.o $x 2>&1 | tail -1)
	sum="$((score + sum))"
	echo $score
done

# print the final score
echo "Score: $sum"