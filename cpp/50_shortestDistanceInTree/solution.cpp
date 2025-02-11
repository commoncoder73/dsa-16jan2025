#include <bits/stdc++.h>

using namespace std;

vector<int> lca(int u, int v, vector<int>& depths, vector<vector<int>>& ancestors) {
    if (depths[u] < depths[v]) {
      int temp = u;
      u = v;
      v - temp;
    }
    int diff = depths[u] - depths[v];
    int possibleJumps = ((int)log2(diff));
    while (possibleJumps >= 0) {
      if (diff & (1 << possibleJumps)) {
        u = ancestors[u][possibleJumps];
      }
      possibleJumps--;
    }
    // If u and v are currently equal, that means that originally u and v were
    // on the same path! and that means v is our LCA!
    if (u == v) {
      return u;
    }
    // Else try to jump to just below lca!
    for (int i = ancestors[0].size() - 1; i >= 0; i--) {
      if (ancestors[u][i] == ancestors[v][i]) {
        continue;
      }
      u = ancestors[u][i];
      v = ancestors[v][i];
    }
    return ancestors[u][0];
}

void dfsToFillAncestors(int node, int parent, vector<vector<int>>& adj,
                        vector<int>& depths, vector<vector<int>>& ancestors) {
  if (parent != -1) {
    depths[node] = depths[parent] + 1;
  }

  // Fill all powers of 2 ancestors
  ancestors[node][/*2^0 i.e. 1st parent of node*/ 0] = parent;
  for (int i = 1; i < ancestors[node].size(); i++) {
    // who is my 2^(i-1) parent of node
    int twoPowerIMinusOneParent = ancestors[node][i - 1];

    // If the ancestor is already imaginary then we don't need to lookup further
    if (twoPowerIMinusOneParent == -1) {
      continue;
    }

    // who is my 2^(i-1) parent of twoPowerIMinusOneParent
    ancestors[node][/*2^ith of node*/ i] =
        ancestors[twoPowerIMinusOneParent][i - 1];
  }

  for (auto neighbour : adj[node]) {
    if (neighbour == parent) {
      continue;
    }
    dfsToFillAncestors(neighbour, node, adj, depths, ancestors);
  }
}

// TC: O(M*N)
vector<int> shortestDistances(vector<vector<int>> edges, int n,
                              vector<vector<int>> mQueries) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> depths(n, 0);
  int colSizeForAncestors = ((int)log2(n)) + 1;
  vector<vector<int>> ancestors(n, vector<int>(colSizeForAncestors, -1));
  dfsToFillAncestors(0, -1, adj, depths, ancestors);
  vector<int> ans;
  for (auto query: mQueries) {
    int u = query[0];
    int v = query[1];
    int lcaNode = lca(u, v, depths, ancestors);
    ans.push_back(
        depths[u] + depths[v] - 2*depths[lcaNode] ;
    )
  }
  return ans;
}