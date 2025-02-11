#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>>& adj, int node, int parent, vector<int>& visited) {
  int minLenCycle = INT_MAX;
  for (auto neigh : adj[node]) {
    if (neigh == parent) {
      continue;
    }
    if (visited[neigh]) {
      minLenCycle = min(minLenCycle, visited[node] - visited[neigh] + 1);
      continue;
    }
    visited[neigh] = visited[node] + 1;
    minLenCycle = min(minLenCycle, dfs(adj, neigh, node, visited));
  }
  return minLenCycle;
}

int shortestCycle(vector<vector<int>>& edgeList, int n) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  vector<int> visited(n, 0);
  int minLenCycle = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = 1;
    minLenCycle = min(minLenCycle, dfs(adj, i, -1, visited));
  }

  return minLenCycle == INT_MAX ? -1 : minLenCycle;
}
