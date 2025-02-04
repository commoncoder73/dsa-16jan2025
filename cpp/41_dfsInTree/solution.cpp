#include <bits/stdc++.h>

using namespace std;

vector<int> dfs(vector<vector<int>> edges, int n, int startNode) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> ans;
  dfs(startNode, -1, ans, adj);
  return ans;
}

void dfs(int startNode, int parent, vector<int>& ans,
         vector<vector<int>>& adj) {
            
  for (auto neighbour : adj[startNode]) {
    if (neighbour == parent) {
      continue;
    }
    dfs(neighbour, startNode, ans, adj);
  }
  ans.push_back(startNode);
  
}