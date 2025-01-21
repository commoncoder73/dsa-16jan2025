#include <bits/stdc++.h>

using namespace std;

// how many subarrays are possible given maxPerSubarray
int compMaxSubarrays(vector<int>& nums, int maxPerSubarray) {
  int totalSubarrays = 0;
  int consSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (consSum + nums[i] <= maxPerSubarray) {
      consSum += nums[i];
    } else {
      totalSubarrays++;
      consSum = nums[i];
    }
  }
  return totalSubarrays + 1;
}

int compMaxPerSubarray(vector<int>& nums, int maxPerSubarray) {
  int maxVal = 0;
  int consSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (consSum + nums[i] <= maxPerSubarray) {
      consSum += nums[i];
      maxVal = maxVal < consSum ? consSum : maxVal;
    } else {
      consSum = 0;
      i--;
    }
  }
  return maxVal;
}

int splitArray(vector<int>& nums, int k) {
  int maxVal = 0;
  int totalVal = 0;
  for (auto num : nums) {
    maxVal = maxVal < num ? num : maxVal;
    totalVal += num;
  }
  int start = maxVal;
  int end = totalVal;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (compMaxSubarrays(nums, mid) <= k) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return compMaxPerSubarray(nums, start);
}
