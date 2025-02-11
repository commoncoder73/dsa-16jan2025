#include <bits/stdc++.h>

using namespace std;

vector<int>* exploreSnakesAndLadders(vector<vector<int>>& adj, int node) {
  vector<int>* newNodes = new vector<int>();
  if (adj[node].size() == 0) {
    newNodes->push_back(node);
    return newNodes;
  }
  for (int newNode : adj[nodes]) {
    newNodes->push_back(newNode);
  }
  return newNodes;
}

// TC: O(N^2)
// SC: O(N^2)
int min_dice_throws(int n, vector<pair<int, int>> snakes,
                    vector<pair<int, int>> ladders) {
  vector<vector<int>> adj(n + 1, vector<int>());
  for (auto edge : snakes) {
    adj[edge.first].push_back(edge.second);
  }
  for (auto edge : ladders) {
    adj[edge.first].push_back(edge.second);
  }

  vector<bool> visited(n + 1, false);
  queue<int> q;
  visited[1] = true;
  q.push(1);
  int diceThrows = 0;

  while (!q.empty()) {
    int qSize = q.size();
    while (qSize > 0) {
      int node = q.front();
      q.pop();

      if (node == n) {
        return diceThrows;
      }

      // Explore 1-6 dice throw combinations
      for (int i = 1; i <= 6; i++) {
        // Discard any out of bound
        if (node + i > n) {
          continue;
        }

        // For each new cell check for snakes and ladder
        vector<int>* newNodes = exploreSnakesAndLadders(adj, node + i);

        for (int newNode : *newNodes) {
          // Those that are already visited discard
          if (visited[newNode]) {
            continue;
          }
          // remaining ones mark them as visited and publish them into the q!
          visited[newNode] = true;
          q.push(newNode);
        }
        delete newNodes;
      }
      qSize--;
    }
    diceThrows++;
  }

  return -1;
}