#include <bits/stdc++.h>

using namespace std;

// Try to memomize and compare TC


void dfs(vector<vector<int>>& adj, int node, int n, vector<vector<int>>& ans,
         vector<int>& pathBuilder) {
  if (node == n - 1) {
    pathBuilder.push_back(node);
    ans.push_back(pathBuilder);
    pathBuilder.pop_back();
    return;
  }

  pathBuilder.push_back(node);
  for (int neigh : adj[node]) {
    dfs(adj, neigh, n, ans, pathBuilder);
  }
  pathBuilder.pop_back();
}

vector<vector<int>> allPossiblePaths(vector<vector<int>>& edgeList, int n) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
  }
  vector<vector<int>> ans;
  vector<int> pathBuilder;
  dfs(adj, 0, n, ans, pathBuilder);

  return ans;
}
