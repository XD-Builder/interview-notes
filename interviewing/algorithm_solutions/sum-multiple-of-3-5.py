# Given factors [3,5] and find sum of all natural numbers that's multiple of given factors below 16
# Then 3 + 5 + 6 + 9 + 10 + 12 + 15 = 60

import itertools

nums = [3, 5]

maximum = 16
total = 0

# Calculate the sum of all individual factor up to 16
for num in nums:
    count = (maximum-1) / num
    t = (count+1) * num * count / 2
    total += t

# Remove duplicate by calculating combinations for all nums
for L in range(2, len(nums)+1):
    for subset in itertools.combinations(nums, L):
        prod = 1

        # get product of the subset combination nCL where factors provided and L is the number of items for combination
        for i in subset:
            prod *= i

        # prod is found and it's less than max, so we need to remove it from total
        if prod < maximum:
            count = (maximum-1) / prod
            t = (count+1) * prod * count / 2
            total -= t

print(total)
