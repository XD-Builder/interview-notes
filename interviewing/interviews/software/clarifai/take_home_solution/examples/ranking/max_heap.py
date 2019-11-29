#!/usr/bin/python
import heapq
import random
import time

def createArray():
    array = range( 10 * 1000 * 1000 )
    random.shuffle( array )
    return array

def linearSearch( bigArray, k ):
    return sorted(bigArray, reverse=True)[:k]

def heapSearch( bigArray, k ):
    heap = bigArray[:k]
    for item in bigArray:
        if item > heap[0]:
            heapq.heappop(heap)
            heapq.heappush(heap, item)

    return sorted(heap)

start = time.time()
bigArray = createArray()
print ( "Creating array took %g s" % (time.time() - start) )

start = time.time()
print (  linearSearch( bigArray, 10 )  )
print (  "Linear search took %g s" % (time.time() - start)  )

start = time.time()
print (  heapSearch( bigArray, 10 )  )
print (  "Heap search took %g s" % (time.time() - start)  )
