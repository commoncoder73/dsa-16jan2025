#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>>& adj, vector<bool>& visited, int startNode) {
  queue<int> q;
  q.push(startNode);
  visited[startNode] = true;
  while (!q.empty()) {
    int node = q.front();
    cout << node << " ";
    q.pop();
    for (auto neigh : adj[node]) {
      if (visited[neigh]) {
        continue;
      }
      q.push(neigh);
      visited[neigh] = true;
    }
  }
}

vector<int> singleSourceShortestDistances(vector<vector<int>>& edgeList, int n,
                                          int startNode) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }
  vector<int> ans(n, -1);
  queue<int> q;
  q.push(startNode);
  ans[startNode] = 0;
  int currentDistance = 1;
  while (!q.empty()) {
    int qSize = q.size();
    while (qSize > 0) {
      int node = q.front();
      q.pop();
      
      for (auto neigh : adj[node]) {
        if (ans[node] != -1) {
          continue;
        }
        q.push(neigh);
        ans[neigh] = currentDistance;
      }
      qSize--;
    }
    currentDistance++;
  }

  return ans;
}