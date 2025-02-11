#include <bits/stdc++.h>

using namespace std;

// bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited) {
//   for (int neigh : adj[node]) {
//     // If we are visiting neigh in same recursion i.e. it's visited value is 1
//     // then that means cycle is present
//     if (visited[neigh] == 1) {
//       return true;
//     }
//     if (visited[neigh] == 2) {
//       continue;
//     }
//     visited[neigh] = 1;
//     if (dfs(adj, neigh, visited)) {
//       return true;
//     }
//     visited[neigh] = 2;
//   }
//   return false;
// }

// bool isCyclePresent(vector<vector<int>>& edgeList, int n) {
//   vector<vector<int>> adj(n, vector<int>());
//   for (auto edge : edgeList) {
//     adj[edge[0]].push_back(edge[1]);
//   }
//   vector<int> visited(n, 0);

//   for (int i = 0; i < n; i++) {
//     if (visited[i]) {
//       continue;
//     }
//     visited[i] = 1;
//     if (dfs(adj, i, visited)) {
//       return true;
//     }
//     visited[i] = 2;
//   }

//   return false;
// }

bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited) {
  if (visited[node] == 1) {
    return true;
  }
  if (visited[node] == 2) {
    return false;
  }
  visited[node] = 1;
  for (int neigh : adj[node]) {
    if (dfs(adj, neigh, visited)) {
      return true;
    }
  }
  visited[node] = 2;
  return false;
}

bool isCyclePresent(vector<vector<int>>& edgeList, int n) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
  }
  vector<int> visited(n, 0);

  for (int i = 0; i < n; i++) {
    if (dfs(adj, i, visited)) {
      return true;
    }
  }

  return false;
}
