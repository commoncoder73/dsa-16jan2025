#include <bits/stdc++.h>

using namespace std;


// SC - O(N)
class UnionFind {
 public:
  UnionFind(int n) {
    this->nodes = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
      nodes[i] = i;
    }
    this->componentsCount = n;
  }

  // TC: O(N)
  void connect(int p, int q) {
    if (find(p, q)) {
      return;
    }
    int qVal = nodes[q];
    int pVal = nodes[p];
    for (int i = 0; i < n; i++) {
      if (nodes[i] == qVal) {
        nodes[i] = pVal;
      }
    }
    noOfComponents--;
  }

  // TC: O(1)
  bool find(int p, int q) { return nodes[p] == nodes[q]; }

  // TC: O(1)
  int noOfComponents() { return componentsCount; }

 private:
  vector<int> nodes;
  int componentsCount;
}