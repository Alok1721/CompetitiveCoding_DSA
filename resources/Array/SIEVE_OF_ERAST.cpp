class PrimeSieve {
public:
    vector<bool> isPrime;
    vector<int> primes;

    PrimeSieve(int n) {
        isPrime.assign(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        for (int i = 2; i <= n; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    bool checkPrime(int num) {
        return num < isPrime.size() ? isPrime[num] : false;
    }

    const vector<int>& getPrimes() {
        return primes;
    }
};
