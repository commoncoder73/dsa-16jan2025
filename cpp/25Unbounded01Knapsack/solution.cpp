#include <bits/stdc++.h>

using namespace std;

// Assume that capacity as W and total elements in nums array is M
// TC: O(M^W)
// SC: O(W)
int maxPossibleProfit(vector<int> weights, vector<int> profits, int capacity) {
  if (capacity == 0) {
    return 0;
  }
  int maxProfit = 0;
  for(int i=0; i<weights.size(); i++) {
    if (weights[i] > capacity) {
        continue;
    }
    int ans = maxPossibleProfit(weights, profits, capacity - weights[i]);
    if (ans == -1) {
        continue;
    }
    ans += profits[i];
    maxProfit = max(ans, maxProfit);
  }
  return maxProfit;
}

// Assume that capacity as W and total elements in nums array is M
// TC: O(W*M)
// SC: O(W)
int maxPossibleProfitOptimized(vector<int> weights, vector<int> profits, int capacity) {
  vector<int> memo(capacity + 1, -1);
  return maxPossibleProfitOptimized(weights, profits, capacity, memo);
}

int maxPossibleProfitOptimized(vector<int> weights, vector<int> profits, int capacity,
                               vector<int>& memo) {
  if (capacity == 0) {
    return 0;
  }
  if (memo[capacity] != -1) {
    return memo[capacity];
  }
  int maxProfit = 0;
  for(int i=0; i<weights.size(); i++) {
    if (weights[i] > capacity) {
        continue;
    }
    int ans = maxPossibleProfitOptimized(weights, profits, capacity - weights[i], memo);
    if (ans == -1) {
        continue;
    }
    ans += profits[i];
    maxProfit = max(ans, maxProfit);
  }
  return memo[capacity] = maxProfit;
}