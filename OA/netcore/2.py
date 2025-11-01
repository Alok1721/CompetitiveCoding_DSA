def find_maximum_remainder(N, A, k):
    evens = [x for x in A if x % 2 == 0]
    odds = [x for x in A if x % 2 == 1]

    max_rem = 0
    for e in evens:
        for o in odds:
            rem = (e + o) % k
            if rem > max_rem:
                max_rem = rem
    return max_rem
N = 6
A = [1, 2, 3, 4, 5, 6]
k = 4
print(find_maximum_remainder(N, A, k))
