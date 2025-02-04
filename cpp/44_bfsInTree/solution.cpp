#include <bits/stdc++.h>

using namespace std;

struct Node {
  int nodeToProcess;
  int parent;
}

vector<int>
bfs(vector<vector<int>> edges, int n, int startNode) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<int> ans;
  queue<Node*> q;
  q.push(new Node(startNode, -1));

  while (!q.empty()) {
    Node* front = q.pop();
    ans.push_back(front->nodeToProcess);
    for (auto child : adj[front->nodeToProcess]) {
      if (child == front->parent) {
        continue;
      }
      q.push(new Node(child, front->nodeToProcess));
    }
    delete front;
  }

  return ans;
}

vector<vector<int>> bfsLevelByLevl(vector<vector<int>> edges, int n,
                                   int startNode) {
  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    adj[edge[0]].push_back[edge[1]];
    adj[edge[1]].push_back[edge[0]];
  }
  vector<vector<int>> ans;
  queue<Node*> q;
  q.push(new Node(startNode, -1));

  while (!q.empty()) {
    int currentLevelSize = q.size();
    vector<int> subAns;
    while (currentLevelSize > 0) {
      Node* front = q.pop();
      subAns.push_back(front->nodeToProcess);
      for (auto child : adj[front->nodeToProcess]) {
        if (child == front->parent) {
          continue;
        }
        q.push(new Node(child, front->nodeToProcess));
      }
      delete front;
    }
    ans.push_back(subAns);
  }

  return ans;
}