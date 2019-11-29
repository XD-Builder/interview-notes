# https://www.hackerrank.com/challenges/sock-merchant

#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    eleMap = {}
    total = 0
    for i in ar:
        if i in eleMap:
            eleMap[i] += 1
        else:
            eleMap[i] = 1
    for values in eleMap.values():
        print("values %s " % values)
        total += values // 2
    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()

