#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited,
         vector<int>& ans) {
  if (visited[node] == 1) {
    return true;
  }
  if (visited[node] == 2) {
    return false;
  }
  visited[node] = 1;
  for (int neigh : adj[node]) {
    if (dfs(adj, neigh, visited, ans)) {
      return true;
    }
  }
  ans.push_back(node);
  visited[node] = 2;
  return false;
}

pair<vector<int>, bool> topoSort(vector<vector<int>>& edgeList, int n) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
  }
  vector<int> visited(n, 0);
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    if (dfs(adj, i, visited, ans)) {
      return {vector<int>(), true};
    }
  }

  reverse(ans.begin(), ans.end());

  //   for (int i = 0, int j = ans.size() - 1; i < j; i++, j--) {
  //     int temp = ans[i];
  //     ans[i] = ans[j];
  //     ans[j] = temp;
  //   }
  return {ans, false};
}

pair<vector<int>, bool> topoSortBfs(vector<vector<int>>& edgeList, int n) {
  vector<vector<int>> adj(n, vector<int>());
  vector<int> indeg(n, 0);
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
    indeg[edge[1]]++;
  }

  vector<int> ans;
  queue<int> q;

  for (int i = 0; i < n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  // At any point if there are multiple nodes inside Q, that means all those
  // nodes have indeg as 0 i.e. all those nodes were ready to pick up and we
  // could have chosen anyone of them first. Single sorted order is possible if
  // for each iteration, we have only single node to pickup.
  while (!q.empty()) {
    int node = q.front();
    q.pop();

    ans.push_back(node);
    for (int neigh : adj[node]) {
      indeg[neigh]--;
      if (indeg[neigh] == 0) {
        q.push(neig);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (indeg[i] != 0) {
      return {vector<int>(), true};
    }
  }

  return {ans, false};
}
