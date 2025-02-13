#include <bits/stdc++.h>

using namespace std;

struct MstAnswer {
  vector<vector<int>> edges;
  int minWeight;
}

struct Edge {
  int src;
  int dest;
  int weight;
}

// TC: O(ElogE)
// SC: O(E)
MstAnswer
mst(vector<vector<int>> edges, int n) {
  vector<vector<pair<int, int>>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back({edge[1], edge[2]});
    adj[edge[1]].push_back({edge[0], edge[2]});
  }

  // https://stackoverflow.com/a/48587737
  auto cmp = [](const Edge e1, const Edge e2) { return e1.weight < e2.weight; };
  priority_queue<Edge, vector<Edge>, cmp> pq(cmp);

  vector<vector<int>> mstEdges;
  int minWeight = 0;
  vector<bool> visited(n, false);
  pq.push(Edge(0, 0, 0));
  while (!pq.empty()) {
    Edge frontEdge = pq.front();
    pq.pop();
    if (visited[frontEdge.dest]) {
      continue;
    }
    visited[frontEdge.dest] = true;

    // Don't add dummy edge in out final ans
    if (frontEgde.src != frontEdge.dest) {
      mstEdges.push_back({frontEdge.src, frontEdge.dest, frontEdge.weight});
      minWeight += frontEdge.weight;
    }

    for (auto neigh : adj[edge.dest]) {
      if (visited[neigh.frist]) {
        continue;
      }
      pq.push(Edge(edge.dest, neigh.frist, neigh.second));
    }
  }
  return MstAnswer(mstEdges, minWeight);
}