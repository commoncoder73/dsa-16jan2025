#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& adj, int node, int parent,
         vector<bool>& visited) {
  for (auto neigh : adj[node]) {
    if (neigh == parent) {
        continue;
    }
    if (visited[neigh]) {
      return true;
    }
    visited[neigh] = true;
    if (dfs(adj, neigh, node, visited)) {
      return true;
    }
  }
  return false;
}

bool isCyclePresent(vector<vector<int>>& edgeList, int n) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    if (dfs(adj, i, -1, visited)) {
      return true;
    }
  }

  return false;
}

