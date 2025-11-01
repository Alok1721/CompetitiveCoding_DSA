def solve(N, K, L, R, Sn, Sk):
    special = set(Sk)

    prefix = [0] * (N + 1)
    for i in range(N):
        prefix[i + 1] = prefix[i] + (1 if Sn[i] in special else 0)

    count = 0
    leftL = leftR = 0

    for right in range(1, N + 1):
        # Move leftL until number of specials <= R
        while leftL < right and prefix[right] - prefix[leftL] > R:
            leftL += 1
        # Move leftR until number of specials < L
        while leftR < right and prefix[right] - prefix[leftR] >= L:
            leftR += 1
        count += (leftR - leftL)

    print(count)
N, K, L, R = 9,2,1,2
Sn = "adebfgbhd"
Sk = "ab"
solve(N, K, L, R, Sn, Sk)
