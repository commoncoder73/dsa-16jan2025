#include <bits/stdc++.h>

using namespace std;

// TC: O(N)
// SC: O(1) (since a-z chars)
int maxSubArraySum(int nums[], int n) {
  int sum = 0;
  int maxSum = 0;
  int start = 0;
  int finalStart = 0;
  int finalEnd = -1;
  for (int i = 0; i < n; i++) {
    sum += nums[i];
    if (maxSum < sum) {
      finalStart = start;
      finalEnd = i;
      maxSum = sum;
    }

    if (sum < 0) {
      start = i + 1;
      sum = 0;
    }
  }
  cout << finalStart << " " << finalEnd;
  return maxSum;
}
