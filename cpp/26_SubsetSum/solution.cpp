#include <bits/stdc++.h>

using namespace std;

// Assuming target is N and there are M elements in the provided array
// TC O(2^N)
// SC O(N)
bool canSubsetSum(vector<int>& nums, int target) {
  return canSubsetSum(nums, nums.size(), target);
}

bool canSubsetSum(vector<int>& nums, int n, int target) {
  if (target == 0) {
    return true;
  }
  if (n <= 0) {
    return false;
  }
  int possibleAnsByIncluding = false;
  if (nums[n - 1] <= target) {
    possibleAnsByIncluding = canSubsetSum(nums, n - 1, target - nums[n - 1]);
  }
  return possibleAnsByIncluding || canSubsetSum(nums, n - 1, target);
}


// Assuming target is N and there are M elements in the provided array
// TC O(N*M)
// SC O(N*M)
bool canSubsetSumOptimized(vector<int>& nums, int target) {
  vector<vector<int>> memo(target + 1, vector<int>(nums.size() + 1, -1));
  return canSubsetSumOptimized(nums, nums.size(), target, memo);
}


bool canSubsetSumOptimized(vector<int>& nums, int n, int target,
                           vector<vector<int>>& memo) {
  if (target == 0) {
    return true;
  }
  if (n <= 0) {
    return false;
  }
  if (memo[target][n] != -1) {
    return memo[target][n];
  }
  int possibleAnsByIncluding = false;
  if (nums[n - 1] <= target) {
    possibleAnsByIncluding =
        canSubsetSumOptimized(nums, n - 1, target - nums[n - 1], memo);
  }
  return memo[target][n] =
             possibleAnsByIncluding || canSubsetSumOptimized(nums, n - 1, target, memo);
}