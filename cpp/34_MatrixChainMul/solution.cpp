#include <bits/stdc++.h>

using namespace std;

int optimalCostToMulMatrices(vector<int>& dims) {
    vector<vector<int>> memo(dims.size(), vector<int>(dims.size(), -1));
    return optimalCostToMulMatrices(dims, 1, dims.size()-1, memo);
}

int optimalCostToMulMatrices(vector<int>& dims, int firstMatrix, int lastMatrix, vector<vector<int>>& memo) {
    if ((lastMatrix - firstMatrix) <= 0) {
        return 0;
    }
    if (memo[firstMatrix][lastMatrix] != -1) {
        return memo[firstMatrix][lastMatrix];
    }
    int minCost = INT_MAX;
    for(int i=lastMatrix-1; i>=firstMatrix; i--) {
        int leftGroupMulCost = optimalCostToMulMatrices(dims, firstMatrix, i, memo);
        int rightGroupMulCost = optimalCostToMulMatrices(dims, i+1, lastMatrix, memo);
        int currentMulCost = dims[firstMatrix-1]*dims[i]*dims[lastMatrix];
        minCost = min(minCost, leftGroupMulCost + rightGroupMulCost + currentMulCost);
    }
    return memo[firstMatrix][lastMatrix] = minCost;
}