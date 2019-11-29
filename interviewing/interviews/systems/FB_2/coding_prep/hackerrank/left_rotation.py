#!/bin/python3
import math
import os
import random
import re
import sys



if __name__ == '__main__':
    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    a = list(map(int, input().rstrip().split()))

    print(" ".join(map(str,a[d:] + a[:d])))

# https://www.hackerrank.com/challenges/array-left-rotation/problem?h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
