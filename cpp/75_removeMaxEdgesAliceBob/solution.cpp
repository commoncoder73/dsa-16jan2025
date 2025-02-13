#include <bits/stdc++.h>

using namespace std;

class UnionFind {
 public:
  UnionFind(int n) {
    this->parents = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }
    this->heights = vector<int>(n, 1);
    this->componentsCount = n;
  }

  // TC: O(logN)
  void connect(int p, int q) {
    if (find(p, q)) {
      return;
    }
    noOfComponents--;
    int rootP = root(p);
    int rootQ = root(q);

    // p's root has larger tree than q's root
    if (heights[rootP] >= heights[rootQ]) {
      parents[rootQ] = rootP;
      heights[rootP] = max(heights[rootP], heights[rootQ] + 1);
      // if you use number of nodes as weights instead of heights then
      // weights[rootP] = weights[rootP] + weights[rootQ]
    } else {  // q's root has larger tree than p's root
      parents[rootP] = rootQ;
      heights[rootQ] = max(heights[rootQ], heights[rootP] + 1);
    }
  }

  // TC: O(logN)
  bool find(int p, int q) { return root(p) == root(q); }

  // TC: O(1)
  int noOfComponents() { return componentsCount; }

 private:
  vector<int> parents;
  vector<int> heights;
  int componentsCount;

  int root(int node) {
    int originalNode = node;
    while (node != parents[node]) {
      node = parents[node];
    }
    // path compression
    int root = node;
    node = originalNode;
    while (node != root) {
      int parent = parents[node];
      parents[node] = root;
      node = parent;
    }

    return root;
  }
}

// O(2E)
int removeMaxEdges(vector<vector<int>> edges, int n) {
  UnionFind ufAlice(n);
  UnionFind ufBob(n);

  int edgesConsidered = 0;

  // consider common edges first
  for (auto edge : edges) {
    // if this is not a common edge, don't consider it for now
    if (edge[0] != 3) {
      continue;
    }

    // If nodes are already connected in Alice's graph i.e. they are also
    // connected in Bob's graph, we don't need to consider this common egde!
    if (ufAlice.find(edge[1], edge[2])) {
      continue;
    }

    edgesConsidered++;
    ufAlice.connect(edge[1], edge[2]);
    ufBob.connect(edge[1], edge[2]);
  }

  // now consider specific egdes
  for (auto edge : edges) {
    // if this is  a common edge, don't consider it now
    if (edge[0] == 3) {
      continue;
    }

    // If this edge is for Alice and nodes are not connected, consider it
    if (edge[0] == 1 && !ufAlice.find(edge[1], edge[2])) {
      edgesConsidered++;
      ufAlice.connect(edge[1], edge[2]);
    }

    // If this edge is for Bob and nodes are not connected, consider it
    if (edge[0] == 2 && !ufBob.find(edge[1], edge[2])) {
      edgesConsidered++;
      ufBob.connect(edge[1], edge[2]);
    }
  }

  if (ufAlice.noOfComponents() != 1 || ufBob.noOfComponents() != 1) {
    return -1;
  }

  return edges.size() - edgesConsidered;
}