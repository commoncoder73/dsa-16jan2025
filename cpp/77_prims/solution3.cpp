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

// TC: O(V^2+E)
// SC: O(V)
MstAnswer
mst(vector<vector<int>> edges, int n) {
  vector<vector<pair<int, int>>> adj(n, vector<int>());
  unordered_set<int> unvisited;
  for (auto edge : edgeList) {
    unvisited.insert(edge[0]);
    unvisited.insert(edge[1]);
    adj[edge[0]].push_back({edge[1], edge[2]});
    adj[edge[1]].push_back({edge[0], edge[2]});
  }

  unordered_map<int, Edge> vertexEdgeMap;

  vector<vector<int>> mstEdges;
  int minWeight = 0;

  Edge firstEdge = Edge(0, 0, 0) primSet.insert(firstEdge);
  vertexEdgeMap[0] = firstEdge;

  while (!unvisited.empty()) {
    Edge unvisitedVertexEdgeWithMinWeight;
    int currentMinWeight = INT_MAX;
    for (auto i = vertexEdgeMap.begin(); i != vertexEdgeMap.end(); i++) {
      if (unvisited.find(i->first) == unvisited.end()) {
        continue;
      }
      if (i->second.weight < currentMinWeight) {
        currentMinWeight = i->second.weight;
        unvisitedVertexEdgeWithMinWeight = i->second;
      }
    }

    unvisited.erase(unvisitedVertexEdgeWithMinWeight.second.dest);

    // Don't add dummy edge in out final ans
    if (unvisitedVertexEdgeWithMinWeight.src !=
        unvisitedVertexEdgeWithMinWeight.dest) {
      mstEdges.push_back({unvisitedVertexEdgeWithMinWeight.src,
                          unvisitedVertexEdgeWithMinWeight.dest,
                          unvisitedVertexEdgeWithMinWeight.weight});
      minWeight += unvisitedVertexEdgeWithMinWeight.weight;
    }

    for (auto neigh : adj[edge.dest]) {
      if (vertexEdgeMap.find(neigh.first) == vertexEdgeMap.end() ||
          vertexEdgeMap.find(neigh.first)->second->weight > neigh.second) {
        // update the entry in set and map
        Edge edgeToConsider = Edge(edge.dest, neigh.first, neigh.second);
        vertexEdgeMap[neigh.first] = edgeToConsider;
      }
    }
  }
  return MstAnswer(mstEdges, minWeight);
}