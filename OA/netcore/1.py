def mod_inverse(a, mod):
    def extended_gcd(a, b):
        if a == 0:
            return b, 0, 1
        gcd, x1, y1 = extended_gcd(b % a, a)
        x = y1 - (b // a) * x1
        y = x1
        return gcd, x, y

    _, x, _ = extended_gcd(a, mod)
    return (x % mod + mod) % mod

def solve(n, m, s, r, q, x, y):
    MOD = 998244353
    
    # Precompute factorials and their inverses
    fact = [1] * (n + 1)
    inv_fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    inv_fact[n] = mod_inverse(fact[n], MOD)
    for i in range(n - 1, -1, -1):
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD
    
    # Compute frequency of characters in r
    freq_r = [0] * 26
    for c in r:
        freq_r[ord(c) - ord('a')] += 1
    
    # Build prefix frequency array
    prefix = [[0] * 26 for _ in range(n + 1)]
    for i in range(n):
        for c in range(26):
            prefix[i + 1][c] = prefix[i][c]
        prefix[i + 1][ord(s[i]) - ord('a')] += 1
    
    # Process queries
    result = []
    for i in range(q):
        start, end = x[i] - 1, y[i]  # Convert to 0-based indexing
        if end - start < m:  # Substring too short to form r
            result.append(0)
            continue
        
        # Compute frequency in substring s[start:end]
        freq_s = [0] * 26
        valid = True
        for c in range(26):
            freq_s[c] = prefix[end][c] - prefix[start][c]
            if freq_s[c] < freq_r[c]:
                valid = False
        
        if not valid:
            result.append(0)
            continue
        
        # Compute number of ways
        ways = 1
        for c in range(26):
            if freq_r[c] > 0:
                # Use binomial coefficient: C(freq_s[c], freq_r[c])
                if freq_s[c] < freq_r[c]:
                    ways = 0
                    break
                ways = ways * (fact[freq_s[c]] * inv_fact[freq_r[c]] % MOD * inv_fact[freq_s[c] - freq_r[c]] % MOD) % MOD
        result.append(ways)
    
    return result

# Input
n = 8
m = 3
s = "abcdeaab"
r = "abc"
q = 3
x = [1, 2, 3]
y = [8, 4, 8]

# Output
print(solve(n, m, s, r, q, x, y))