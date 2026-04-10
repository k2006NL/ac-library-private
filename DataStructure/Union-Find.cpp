struct UnionFind {
  vector<int> parent, size;
  UnionFind(int n) : parent(n + 1, -1), size(n + 1, 1) {}
    
  int root(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = root(parent[x]);
  }
  bool unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) return false;

    if (size[rx] < size[ry]) swap(rx, ry);
    parent[ry] = rx;
    size[rx] += size[ry];
    return true;
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};