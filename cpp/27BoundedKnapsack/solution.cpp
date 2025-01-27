#include <bits/stdc++.h>

using namespace std;


// Assuming capacity is N and there are M elements in the provided
// TC O(2^N)
// SC O(N)
int maximizeProfit(vector<int>& weights, vector<int>& profits, int capacity) {
    return maximizeProfit(weights, profits, weights.size(), capacity);
}

int maximizeProfit(vector<int>& weights, vector<int>& profits, int n, int capacity) {
    if (capacity == 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    int profitIncluding = 0;
    if (weights[n-1] <= capacity) {
        profitIncluding = profits[n-1] + maximizeProfit(weights, profits, n-1, capacity-weights[n-1]);
    }
    int profitExcluding = maximizeProfit(weights, profits, n-1, capacity);
    return max(profitIncluding, profitExcluding);
}

// Assuming capacity is N and there are M elements in the provided
// TC O(N*M)
// SC O(N*M)
int maximizeProfit(vector<int>& weights, vector<int>& profits, int capacity) {
    vector<vector<int>> memo(capacity+1, vector<int>(weights.size() +1, -1));
    return maximizeProfit(weights, profits, weights.size(), capacity);
}

int maximizeProfit(vector<int>& weights, vector<int>& profits, int n, int capacity, vector<vector<int>>& memo) {
    if (capacity == 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    if (memo[capacity][n] != -1) {
        return memo[capacity][n];
    }
    int profitIncluding = 0;
    if (weights[n-1] <= capacity) {
        profitIncluding = profits[n-1] + maximizeProfit(weights, profits, n-1, capacity-weights[n-1], memo);
    }
    int profitExcluding = maximizeProfit(weights, profits, n-1, capacity, memo);
    return memo[capacity][n] = max(profitIncluding, profitExcluding);
}