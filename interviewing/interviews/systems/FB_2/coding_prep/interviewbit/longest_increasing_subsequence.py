def longestIncreasingSubsequence(sequence):
    # Assume the length to be at least 1 and set default memoization
    n = len(sequence)
    lis = [1] * n

    for i in range(1, n):
        for j in range (0, i):
            # check greater sequence and increment the length
            if sequence[i] > sequence[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1
    maximum = 0
    for i in range(n):
        maximum = max(maximum, lis[i])

    return maximum

_max = longestIncreasingSubsequence([0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15])
print(_max)