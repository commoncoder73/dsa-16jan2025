#include <bits/stdc++.h>

using namespace std;

// Assume that target is N and total elements in nums array is M
// TC: O(M^N)
// SC: O(N)
// Given nums only contains positive number
int maxPossibleLength(vector<int> nums, int target) {
  if (target < 0) {
    return -1;
  }
  if (target == 0) {
    return 0;
  }
  int max = -1;
  for (auto num : nums) {
    int ans = maxPossibleLength(nums, target - num);
    if (ans != -1) {
      max = max < ans ? ans : max;
    }
  }
  return max != -1 ? max + 1 : -1;
}

// Assume that target is N and total elements in nums array is M
// TC: O(M*N)
// SC: O(N)
// Given nums only contains positive number
int maxPossibleLengthOptimized(vector<int>& nums, int target) {
  vector<int> memo(target + 1, -2);
  return maxPossibleLengthOptimized(nums, target, memo);
}

int maxPossibleLengthOptimized(vector<int>& nums, int target,
                               vector<int>& memo) {
  if (target < 0) {
    return -1;
  }
  if (target == 0) {
    return 0;
  }
  if (memo[target] != -2) {
    return memo[target];
  }
  int max = -1;
  for (auto num : nums) {
    int ans = maxPossibleLength(nums, target - num, memo);
    if (ans != -1) {
      max = max < ans ? ans : max;
    }
  }
  memo[target] = max != -1 ? max + 1 : -1;
  return memo[target];
}