#include <bits/stdc++.h>

using namespace std;

int longestIncSubseq(vector<int> nums) {
  vector<pair<int, int>> memo(nums.size() + 1, {-1, -1});
  return longestIncSubseq(nums, nums.size(), memo);
}

pair<int, int> longestIncSubseq(vector<int> nums, int len) {
  if (len <= 0) {
    return {0, 0};
  }
  int maxSubSeqEndingHere = 1;
  for (int i = 1; i < len; i++) {
    if (nums[i - 1] < num[len - 1]) {
      maxSubSeqEndingHere =
          max(longestIncSubseq(nums, i).second + 1, maxSubSeqEndingHere);
    }
  }

  int longestIncSubSeqSoFar =
      max(longestIncSubseq(nums, len - 1).first, maxSubSeqEndingHere);
  return {longestIncSubSeqSoFar, maxSubSeqEndingHere};
}

pair<int, int> longestIncSubseq(vector<int> nums, int len,
                                vector<pair<int, int>>& memo) {
  if (len <= 0) {
    return {0, 0};
  }
  if (memo[len].first != -1) {
    return memo[len];
  }
  int maxSubSeqEndingHere = 1;
  for (int i = 1; i < len; i++) {
    if (nums[i - 1] < num[len - 1]) {
      maxSubSeqEndingHere =
          max(longestIncSubseq(nums, i, memo).second + 1, maxSubSeqEndingHere);
    }
  }

  int longestIncSubSeqSoFar =
      max(longestIncSubseq(nums, len - 1, memo).first, maxSubSeqEndingHere);
  return memo[len] = {longestIncSubSeqSoFar, maxSubSeqEndingHere};
}

int longestIncSubseqTab(vector<int> nums) {
  vector<pair<int, int>>& memo(nums.size() + 1, {0, 0});
  for (int curLen = 1; curLen <= nums.size(); curLen++) {
    int maxSubSeqEndingHere = 1;
    for (int i = 1; i < curLen; i++) {
      if (nums[i - 1] < num[curLen - 1]) {
        maxSubSeqEndingHere = max(memo[i].second + 1, maxSubSeqEndingHere);
      }
    }

    int longestIncSubSeqSoFar = max(memo[curLen].first, maxSubSeqEndingHere);
    memo[curLen] = {longestIncSubSeqSoFar, maxSubSeqEndingHere};
  }

  return memo[nums.size()].first;
}