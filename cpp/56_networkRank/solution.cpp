// https://leetcode.com/problems/maximal-network-rank
#include <bits/stdc++.h>

using namespace std;

// TC: O(V^2)
// SC: O(V^2)
int networkRankAdjMatrix(vector<vector<int>>& edges, int n) {
  bool adjMatrix[n][n]{false};
  int count[n]{0};

  for (auto edge : edges) {
    adjMatrix[edge[0]][edge[1]] = true;
    adjMatrix[edge[1]][edge[0]] = true;
    count[edge[0]]++;
    count[edge[1]]++;
  }

  int maxRank = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int rank = count[i] + count[j];
      if (adjMatrix[i][j]) {
        rank--;
      }
      maxRank = max(maxRank, rank);
    }
  }
  return maxRank;
}

int networkRankAdjList(vector<vector<int>>& edges, int n) {
  vector<int, unordered_set<int>> adjList

      for (auto edge : edges) {
    adjList[edge[0]].insert(edge[1]);
    adjList[edge[1]].insert(edge[0]);
  }

  int maxRank = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int rank = adjList[i].size() + adjList[j].size();
      if (adjList[i].contains(j)) {
        rank--;
      }
      maxRank = max(maxRank, rank);
    }
  }
  return maxRank;
}