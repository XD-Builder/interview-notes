#!/bin/python3
# https://www.hackerrank.com/challenges/jumping-on-the-clouds
import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(c):
    size = len(c)
    count = 0
    index = 0
    while True:
        if index + 1 == size:
            break
        if c[index] == 0:
            print(index)
            count += 1

        if index+2 < size and c[index+2] == 0:
            index += 2
        else:
            index += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    c = list(map(int, input().rstrip().split()))

    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')

    fptr.close()
