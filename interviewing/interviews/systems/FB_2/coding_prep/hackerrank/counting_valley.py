#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    prevLevel = 0
    level = 0
    valleys = 0
    for i in s:
        if i == 'U':
            level += 1
        if i == 'D':
            level -= 1

        if level == 0 and prevLevel == -1:
            valleys += 1

        prevLevel = level
    return valleys

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
