def count_pure_sequences(d):
    MOD = 10**9 + 7
    
    # Precompute for each digit (0-9) which digits are allowed to follow it
    # A digit x can be placed if any of its divisors (except 1) has been used before
    # or if x is 0 (which can be placed after first position)
    
    # First, precompute all proper divisors (excluding 1) for digits 1-9
    proper_divisors = [
        [],           # 0
        [],           # 1
        [2],          # 2
        [3],          # 3
        [2, 4],       # 4
        [5],          # 5
        [2, 3, 6],    # 6
        [7],          # 7
        [2, 4, 8],    # 8
        [3, 9]        # 9
    ]
    
    # dp[mask] = number of ways with the given set of used digits (mask)
    # Initialize with first digit (1-9)
    dp = [0] * 1024  # 2^10 possible masks
    for i in range(1, 10):
        dp[1 << i] = 1
    
    for _ in range(1, d):
        new_dp = [0] * 1024
        for mask in range(1024):
            if dp[mask] == 0:
                continue
                
            # Try to place each digit 0-9
            for digit in range(10):
                if digit == 0:
                    # Can place 0 if not first digit
                    if mask != 0:  # Not first digit
                        new_mask = mask | (1 << digit)
                        new_dp[new_mask] = (new_dp[new_mask] + dp[mask]) % MOD
                else:
                    # Can place digit if it has no proper divisors or any of its divisors were used
                    can_place = True
                    if proper_divisors[digit]:  # If it has proper divisors
                        can_place = any((mask & (1 << d)) for d in proper_divisors[digit])
                    
                    if can_place:
                        new_mask = mask | (1 << digit)
                        new_dp[new_mask] = (new_dp[new_mask] + dp[mask]) % MOD
        
        dp = new_dp
    
    return sum(dp) % MOD

# Test with given examples
print(f"d=1: {count_pure_sequences(1)}")  # Expected: 9
print(f"d=2: {count_pure_sequences(2)}")  # Expected: 23