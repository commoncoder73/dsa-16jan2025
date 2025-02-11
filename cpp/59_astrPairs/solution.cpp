// https://www.hackerrank.com/contests/alcoding-summer-challenge/challenges/astronaut-pairs
#include <bits/stdc++.h>

using namespace std;


int dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node]= true;
    int nodesCount = 1;
    for(auto neigh: adj[node]) {
        if (visited[neigh]) {
            continue;
        }
        nodesCount += dfs(adj, neigh, visited);
    }
    return nodesCount;
}

// TC: O(N^2)
int countPairs(vector<vector<int>>& edgeList, int n) {
    vector<vector<int>> adj(n, vector<int>());
    for(auto edge: edgeList) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    vector<int> astrCounts;
    for(int i=0; i<n; i++) {
        if (visited[i]) {
            continue;
        }
        astrCounts.push_back(
            dfs(adj, i, visited);
        )
    }
    int totalPossiblePairs = 0;
    for(int i=0; i<astrCounts.size(); i++) {
        for(int j=i+1; j<astrCounts.size(); j++) {
            totalPossiblePairs += astrCounts[i]*astrCounts[j];
        }
    }
    return totalPossiblePairs;
}
