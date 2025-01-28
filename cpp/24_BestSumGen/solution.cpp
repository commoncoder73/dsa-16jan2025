#include <bits/stdc++.h>

using namespace std;

// Assume that target is N and total elements in nums array is M
// TC: O(M^N)
// SC: O(N)
// Given nums only contains positive number
vector<int>* maxPossibleLenGen(vector<int> nums, int target) {
  if (target < 0) {
    return nullptr;
  }
  if (target == 0) {
    return new vector<int>();
  }
  vector<int>* maxGenerated = nullptr;
  int maxProvidingElement;
  for (auto num : nums) {
    vector<int>* ans = maxPossibleLenGen(nums, target - num);
    if (!ans) {
      continue;
    }
    if (!maxGenerated || maxGenerated->size() < ans->size()) {
      maxGenerated = ans;
      maxProvidingElement = num;
    }
  }
  if (maxGenerated) {
    maxGenerated->push_back(maxProvidingElement);
  }
  return maxGenerated;
}

vector<int>* maxPossibleLenGenOptimized(vector<int> nums, int target) {
    vector<pair<bool, vector<int>*>> memo(target+1, pair(false, nullptr));
    maxPossibleLenGenOptimized(nums, target, memo);
    vector<int>* ans = memo[target].second;
    for(int i=0; i<target; i++) {
        if (memo[i].second)
            delete memo[i].second;
    }
    return ans;
}
// Assume that target is N and total elements in nums array is M
// TC: O(N(M+N))
// SC: O(N^2)
// Given nums only contains positive number
vector<int>* maxPossibleLenGenOptimized(vector<int> nums, int target, vector<pair<bool, vector<int>*>>& memo) {
  if (target < 0) {
    return nullptr;
  }
  if (target == 0) {
    return new vector<int>();
  }
  if (memo[target].first) {
    return memo[target].second;
  }
  vector<int>* maxGenerated = nullptr;
  int maxProvidingElement;
  for (auto num : nums) {
    vector<int>* ans = maxPossibleLenGenOptimized(nums, target - num, memo);
    if (!ans) {
      continue;
    }
    if (!maxGenerated || maxGenerated->size() < ans->size()) {
      maxGenerated = ans;
      maxProvidingElement = num;
    }
  }
  if (maxGenerated) {
    maxGenerated = new vector<int>(*maxGenerated);
    maxGenerated->push_back(maxProvidingElement);
  }
  memo[target] = pair(true, maxGenerated);
  return maxGenerated;
}
