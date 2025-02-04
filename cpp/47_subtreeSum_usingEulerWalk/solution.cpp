#include <bits/stdc++.h>

using namespace std;

vector<int> subtreeSum(vector<vector<int>> edges, int n, int startNode,
                       vector<int> mQueries) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> eulersWalkAns;
  vector<pair<int, int>> startEndMarker(n, pair(0, 0));
  dfs(startNode, -1, eulersWalkAns, adj);

// Prefix sum will work only if you don't want to support updates.
// In case if you want to support updates, segment tree or other similar data structure can be used
// SegmentTree segTree(eulersWalkAns);
// segTee.lazyQuery(...)
// segTee.lazyUpdate(...)
  vector<int> prefixSum;
  int sum = 0;
  for (int node : eulersWalkAns) {
    sum += node;
    prefixSum.push_back(sum);
  }

  vector<int> ans;
  for (int node : mQueries) {
    int start = startEndMarker[node].first;
    int end = startEndMarker[node].second;
    int subtreeSum = prefixSum[end];
    if (start - 1 >= 0) {
      subtreeSum -= prefixSum[start - 1];
    }
    ans.push_back(subtreeSum / 2);
  }
  return ans;
}

void dfs(int startNode, int parent, vector<int>& eulersWalkAns,
         vector<vector<int>>& adj, vector<pair<int, int>>& startEndMarker) {
  // visiting this startNode for the first time, so will add it to our walk!
  startEndMarker[startNode].first = eulersWalkAns.size();
  eulersWalkAns.push_back(startNode);
  for (auto neighbour : adj[startNode]) {
    if (neighbour == parent) {
      continue;
    }
    dfs(neighbour, startNode, eulersWalkAns, adj, startEndMarker);
  }
  // everything is processed in this subtree and we have to exit this startNode
  // now! So we will add it to our walk.
  startEndMarker[startNode].second = eulersWalkAns.size();
  eulersWalkAns.push_back(startNode);
}