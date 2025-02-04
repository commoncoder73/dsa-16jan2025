#include <bits/stdc++.h>

using namespace std;

int swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int partition(vector<int>& nums, int start, int end, int pivot) {
  int partitionIndex = 0;
  while (start <= end) {
    if (nums[partitionIndex] >= pivot) {
      start++;
      continue;
    }
    swap(nums[partitionIndex], nums[start]);
    partitionIndex++;
    start++;
  }
  return partitionIndex;
}

void quickSort(vector<int>& nums, int start, int end) {
  if (start >= end) {
    return;
  }
  int pivot = nums[end];
  int partitionIndex = partition(nums, start, end, pivot);

  quickSort(nums, start, partitionIndex - 1);
  quickSort(nums, partitionIndex + 1, end);
}

// Avg case
// TC: O(N*logN)
// SC: O(logN)

// Worst case
// TC: O(N*N)
// SC: O(N)
void quickSort(vector<int>& nums) {
  return quickSort(nums, 0, nums.size() - 1);
}

// assuming 1 <= k <= nums.size()
int kthElementInSortedArray(vector<int>& nums, int start, int end, int k) {
  if (start >= end) {
    return nums[start];
  }
  int pivot = nums[end];
  int partitionIndex = partition(nums, start, end, pivot);
  if (partitionIndex == k - 1) {
    return pivot;
  }
  swap(nums[partitionIndex], nums[end]);
  if (partitionIndex < (k - 1)) {
    return kthElementInSortedArray(nums, partitionIndex + 1, end,
                                   k - partitionIndex - i);
  } else {  // partitionIndex > (k-1)
    return kthElementInSortedArray(nums, start, partitionIndex - 1, k);
  }
}

// Avg case
// TC: O(N)
// SC: O(logN)

// Worst case
// TC: O(N*N)
// SC: O(N)
// assuming 1 <= k <= nums.size()
int kthElementInSortedArray(vector<int>& nums, int k) {
  return kthElementInSortedArray(nums, 0, nums.size() - 1, k);
}

// Avg case
// TC: O(N)
// SC: O(1)

// Worst case
// TC: O(N*N)
// SC: O(1)
// assuming 1 <= k <= nums.size()
int kthElementInSortedArrayItr(vector<int>& nums, int k) {
  int start = 0;
  int end = nums.size() - 1;

  while (start <= end) {
    int pivot = nums[end];
    int partitionIndex = partition(nums, start, end, pivot);
    if (partitionIndex == k - 1) {
      return pivot;
    }
    swap(nums[partitionIndex], nums[end]);
    if (partitionIndex < (k - 1)) {
      start = partitionIndex + 1;
      k = k - partitionIndex - i;
    } else {  // partitionIndex > (k-1)
      end = partitionIndex - 1;
    }
  }
  return -1;
}
