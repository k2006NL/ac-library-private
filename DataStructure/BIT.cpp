struct BIT {
    int n;
    vector<long long> tree;

    BIT (int n): n(n), tree(n+1, 0) {}

    void add(int i, int x) {
        for (; i <= n; i += i & -i) {
            tree[i] += x;
        }
    }

    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res += tree[i];
        }      
        return res;
    }
};