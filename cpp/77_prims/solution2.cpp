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

// TC: O(ElogV)
// SC: O(V)
MstAnswer
mst(vector<vector<int>> edges, int n) {
  vector<vector<pair<int, int>>> adj(n, vector<int>());
  for (auto edge : edgeList) {
    adj[edge[0]].push_back({edge[1], edge[2]});
    adj[edge[1]].push_back({edge[0], edge[2]});
  }

  // https://stackoverflow.com/a/46128321
  auto cmp = [](const Edge e1, const Edge e2) { return e1.weight < e2.weight; };
  set<Edge, decltype(cmp)> primSet(cmp);
  unordered_map<int, Edge> vertexEdgeMap;

  vector<vector<int>> mstEdges;
  int minWeight = 0;
  vector<bool> visited(n, false);
  Edge firstEdge = Edge(0, 0, 0) primSet.insert(firstEdge);
  vertexEdgeMap[0] = firstEdge;
  while (!primSet.empty()) {
    auto frontEdge = primSet.begin();
    primSet.erase(frontEdge);

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

      if (vertexEdgeMap.find(neigh.first) == vertexEdgeMap.end() ||
          vertexEdgeMap.find(neigh.first)->second->weight > neigh.second) {
        // remove existing entry from the set
        if (vertexEdgeMap.find(neigh.first) != vertexEdgeMap.end()) {
          primSet.erase(vertexEdgeMap.find(neigh.first).second);
        }

        // update the entry in set and map
        Edge edgeToConsider = Edge(edge.dest, neigh.first, neigh.second);
        primSet.insert(edgeToConsider);
        vertexEdgeMap[neigh.first] = edgeToConsider;
      }
    }
  }
  return MstAnswer(mstEdges, minWeight);
}