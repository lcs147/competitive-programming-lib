#!/bin/bash
for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    diff -w <(./a < int) <(./brute < int) || break
done