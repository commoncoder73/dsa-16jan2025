#include <bits/stdc++.h>

using namespace std;

vector<int> eulersWalk(vector<vector<int>> edges, int n, int startNode, ) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> eulersWalkAns;
  dfs(startNode, -1, eulersWalkAns, adj);
  return eulersWalkAns;
}

void dfs(int startNode, int parent, vector<int>& eulersWalkAns,
         vector<vector<int>>& adj) {
  // visiting this startNode for the first time, so will add it to our walk!
  eulersWalkAns.push_back(startNode);
  for (auto neighbour : adj[startNode]) {
    if (neighbour == parent) {
      continue;
    }
    dfs(neighbour, startNode, eulersWalkAns, adj);
  }
  // everything is processed in this subtree and we have to exit this startNode
  // now! So we will add it to our walk.
  eulersWalkAns.push_back(startNode);
}