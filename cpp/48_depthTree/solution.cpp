#include <bits/stdc++.h>

using namespace std;

vector<int> subtreeSum(vector<vector<int>> edges, int n, int startNode) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> depths(n, 0);
  dfs(startNode, -1, adj, depths);

  return depths;
}

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& depths) {
  if (parent != -1) {
    depths[node] = depths[parent] + 1;
  }
  for (auto neighbour : adj[node]) {
    if (neighbour == parent) {
      continue;
    }
    dfs(neighbour, node, adj, depths);
  }
}