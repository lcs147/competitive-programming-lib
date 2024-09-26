#!/bin/bash
make brute
make gen
make checker
make ../a

for((i = 1; ; ++i)); do
    echo $i
    ./gen $i > int
    diff -w <(../a < int) <(./brute < int) || break
    # ../a < int > sol
    # (cat int sol | ./checker) || break
done

echo "test case:"
cat int

echo "brute ans: "
echo $(./brute < int)
echo "sol ans: "
echo $(../a < int)