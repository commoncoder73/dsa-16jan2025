#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPathThoroughK(vector<vector<int>> edges, int n, int k,
                                  vector<vector<int>> mQueries) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> memo(n, 0);
  dfs(r, -1, memo, adj);
  vector<int> ans;
  for (auto query : mQueries) {
    ans.push_back(memo[query[0] + memo[query[1]]]);
  }
  return ans;
}

void dfs(int startNode, int parent, vector<int>& memo,
         vector<vector<int>>& adj) {
  if (parent != -1) {
    memo[startNode] = memo[parent] + 1;
  }

  for (auto neighbour : adj[startNode]) {
    if (neighbour == parent) {
      continue;
    }
    dfs(neighbour, startNode, memo, adj);
  }
}