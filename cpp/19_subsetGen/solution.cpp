#include <bits/stdc++.h>

using namespace std;

// TC: N*2^N
// SC: N*2^N considering output
// SC: N without considering output
vector<vector<int>> genSubsets(vector<int> arr) {
  vector<vector<int>> ans;
  vector<int> subsetBuilder;
  genSubsets(0, arr, subsetBuilder, ans);
  return ans;
}

void genSubsets(int i, vector<int>& arr, vector<int>& subsetBuilder,
                vector<vector<int>>& ans) {
  if (i >= arr.size()) {
    ans.push_back(subsetBuilder);
    return;
  }
  genSubsets(i + 1, arr, subsetBuilder, ans);

  subsetBuilder.push_back(arr[i]);
  genSubsets(i + 1, arr, subsetBuilder, ans);
  subsetBuilder.pop_back();
}

// TC: N*2^N
// SC: N*2^N considering output
// SC: N without considering output
vector<vector<int>> genSubsetsIterative(vector<int> arr) {
  vector<vector<int>> ans;
  int n = arr.size();
  long int allPossibleLength = 1 << (n);
  for (long int i = 0; i < allPossibleLength; i++) {
    int currentNum = i;
    vector<int> subsetBuilder;
    int currentIndexInArr = 0;
    while (currentNum) {
      if (currentNum & 1) {
        subsetBuilder.push_back(arr[currentIndexInArr]);
      }
      currentNum = currentNum >> 1;
      currentIndexInArr++;
    }
    ans.push_back(subsetBuilder);
  }
  return ans;
}
