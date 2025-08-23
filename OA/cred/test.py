def solve():
    d = int(input())
    MOD = 10**9 + 7

    dp = [[0] * (1 << 10) for _ in range(d + 1)]
    dp[0][0] = 1

    for i in range(1, d + 1):
        for mask in range(1 << 10):
            if dp[i-1][mask] == 0:
                continue
            for j in range(10):
                new_mask = mask
                if j == 0:
                    new_mask = mask | (1 << 0)
                else:
                    is_valid = True
                    for k in range(2, j):
                        if j % k == 0 and (mask & (1 << k)) == 0:
                            is_valid = False
                            break
                    if is_valid:
                       new_mask = mask | (1 << j)
                dp[i][new_mask] = (dp[i][new_mask] + dp[i-1][mask]) % MOD
    
    ans = 0
    for mask in range(1 << 10):
        ans = (ans + dp[d][mask]) % MOD

    print(ans)
solve()