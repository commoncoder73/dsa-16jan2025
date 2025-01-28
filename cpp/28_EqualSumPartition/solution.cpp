#include <bits/stdc++.h>

using namespace std;

bool canEqualPartition(vector<int>& nums) {
    int sum = 0;
    for(int num: nums) {
        sum+=num;
    }
    if (sum&1) {
        return false;
    }
    return canSubsetSumOptimized(nums, sum/2);   
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



int f(vector<int> nums, int totalSumOfNums, int currSum, int i) {
    if (i == nums.size()) {
        return abs(total-2*currSum);
    }
    return min(f(nums, totalSumOfNums, currSum, i+1), f(nums, totalSumOfNums, currSum+nums[i], i+1))
}