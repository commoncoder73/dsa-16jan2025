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

struct MstAnswer {
  vector<vector<int>> edges;
  int minWeight;
}

// java (int a, int b) -> { c }
// cpp [c](int a, int b) { c }

/*
    class CustomCompator {
        int compare(int a, int b) {

        }
    }

*/
MstAnswer
mst(vector<vector<int>> edges, int n) {
  UnionFind uf(n);
  sort(edges.begin(), edges.end(),
       [](const vector<int> edge1, const vector<int> edge2) {
         return edge1[2] < edge2[2];
       });

  vector<vector<int>> mstEdges;
  int minWeight = 0;
  for (auto edge : edges) {
    // If both the nodes are already connected
    if (uf.find(edge[0], edge[1])) {
      continue;
    }

    uf.connect(edge[0], edge[1]);
    mstEdges.push_back(edge);
    minWeight += edge[2];
  }
  return MstAnswer(mstEdges, minWeight);
}