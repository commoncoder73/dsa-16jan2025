#include <bits/stdc++.h>

using namespace std;

vector<int> countNodes(vector<vector<int>> edges, int n, int r, vector<int> mQueries) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> memo(n, -1);
  dfs(r, -1, memo, adj);
  vector<int> ans;
  for(int query: mQueries) {
    ans.push_back(memo[query]);
  }
  return ans;
}

int dfs(int startNode, int parent, vector<int>& memo,
         vector<vector<int>>& adj) {
  int totalNodes = 0;
  for (auto neighbour : adj[startNode]) {
    if (neighbour == parent) {
      continue;
    }
    totalNodes += dfs(neighbour, startNode, memo, adj);
  }
  return memo[startNode] = (totalNodes+1);
}