# Given [4,3,5,6]
# It should produce 36

# Steps:
# First merge smallest two parts: 3 + 4 = 7 seconds
# Then merge next smallest two parts, 5 + 6 = 11 seconds
# Last merge next smallest two parts, 7 + 11 = 18 seconds
# Add all seconds used to merge all parts into one 7 + 11 + 18
# We arrive to answer 36 seconds

import random
import time
import bisect

def minimumCombineParts(parts):
    if len(parts) < 2:
        return 0

    sortedParts = sorted(parts.copy())

    partsSum = 0
    for i in range (1, len(sortedParts)):
        partsMerge = sum(sortedParts[0:2])
        partsSum += partsMerge
        del sortedParts[0:2]
        bisect.insort(sortedParts, partsMerge)
    
    return partsSum

# parts = [random.randint(1, 1000000) for i in range (1000000)]
parts = [4,3,5,6]

start_time = time.time()*1000
print(minimumCombineParts(parts))
print("It took %d milliseconds to run minimumCombineParts" % (time.time()*1000 - start_time))