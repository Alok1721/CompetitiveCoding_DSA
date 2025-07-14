class FenwickTree {
public:
    vector<int> bit;  // Binary Indexed Tree
    int n;

    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);  // 1-based indexing
    }

    // Adds 'val' at index 'i' (0-based)
    void update(int i, int val) {
        i++; // Convert to 1-based
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);  // Move to next
        }
    }

    // Returns prefix sum from [0 ... i] (0-based)
    int query(int i) {
        i++; // Convert to 1-based
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);  // Move to parent
        }
        return sum;
    }

    // Sum of range [l ... r] (0-based inclusive)
    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
