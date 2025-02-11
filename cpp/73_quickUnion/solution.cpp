#include <bits/stdc++.h>

using namespace std;

// SC - O(N)
class UnionFind {
 public:
  UnionFind(int n) {
    this->parents = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    this->componentsCount = n;
  }

  // TC: O(N) - worst
  // TC: O(logN) - balanced tree
  void union(int p, int q) {
    if (find(p, q)) {
      return;
    }
    noOfComponents--;
    int rootP = root(p);
    int rootQ = root(q);
    parents[rootQ] = rootP;
  }

  // TC: O(N) - worst
  // TC: O(logN) - balanced tree
  bool find(int p, int q) { return root(p) == root(q); }

  // TC: O(1)
  int noOfComponents() { return componentsCount; }

 private:
  vector<int> parents;
  int componentsCount;

  int root(int node) {
    while (node != parents[node]) {
      node = parents[node];
    }
    return node;
  }
}