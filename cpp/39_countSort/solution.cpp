#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> nums) {
  int maxVal = INT_MIN;
  for (auto num : nums) {
    maxVal = max(maxVal, num);
  }

  vector<int> counts(maxVal + 1, 0);
  for (auto num : nums) {
    counts[num]++;
  }

  int resultPtr = 0;

  for (int i = 0; i < counts.size(); i++) {
    while (counts[i] > 0) {
      nums[resultPtr++] = i;
      counts[i]--;
    }
  }
}