#include <bits/stdc++.h>

using namespace std;

// TC: O(NlogN)
// SC: O(N)
int getInversionCount(vector<int> nums) {
  return mergeSort(nums, 0, nums.size() - 1);
}

int mergeSort(vector<int>& nums, int start, int end) {
  if (start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  int inversionsFirstHalf = mergeSort(nums, start, mid);
  int inversionsSecondHalf = mergeSort(nums, mid + 1, end);
  return inversionsFirstHalf + inversionsSecondHalf +
         merge(nums, start, mid, end);
}

int merge(vector<int>& nums, int start, int mid, int end) {
  vector<int>& tempMerged(nums.size());
  int resultIndex = 0;
  int i = start;
  int j = mid + 1;
  int inversions = 0;
  while (i <= mid && j <= end) {
    if (nums[i] <= nums[j]) {
      tempMerged[resultIndex++] = nums[i++];
    } else {
      tempMerged[resultIndex++] = nums[j++];
      inversions += (mid - i + 1);
    }
  }
  while (i <= mid) {
    tempMerged[resultIndex++] = nums[i++];
  }
  while (j <= end) {
    tempMerged[resultIndex++] = nums[j++];
  }
  for (int i = start; i <= end; i++) {
    nums[i] = tempMerged[i];
  }
  return inversions;
}
