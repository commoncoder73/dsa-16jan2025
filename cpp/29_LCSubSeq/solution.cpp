#include <bits/stdc++.h>

using namespace std;

// Assuming S1 is s1's length and S2 is s2's length
// TC: O(2^(max(S1, S2)))
// SC: O(max(S1, S2))

// Assuming S1 is s1's length and S2 is s2's length
// TC: O(S1*S2)
// SC: O(S1*S2)
int longestCommonSubSeq(string& s1, string& s2) {
  vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  return longestCommonSubSeq(s1, s2, s1.size(), s2.size());
}

int longestCommonSubSeq(string& s1, string& s2, int s1Len, int s2Len) {
  if (s1Len <= 0 || s2Len <= 0) {
    return 0;
  }

  if (s1[s1Len - 1] == s2[s2Len - 1]) {
    return longestCommonSubSeq(s1, s2, s1Len - 1, s2Len - 1) + 1;
  }
  return max(longestCommonSubSeq(s1, s2, s1Len - 1, s2Len),
             longestCommonSubSeq(s1, s2, s1Len, s2Len - 1))
}

int longestCommonSubSeq(string& s1, string& s2, int s1Len, int s2Len,
                        vector<vector<int>> memo) {
  if (s1Len <= 0 || s2Len <= 0) {
    return 0;
  }

  if (memo[s1Len][s2Len] != -1) {
    return memo[s1Len][s2Len];
  }

  int ans;
  if (s1[s1Len - 1] == s2[s2Len - 1]) {
    ans = longestCommonSubSeq(s1, s2, s1Len - 1, s2Len - 1, memo) + 1;
  } else {
    ans = max(longestCommonSubSeq(s1, s2, s1Len - 1, s2Len, memo),
              longestCommonSubSeq(s1, s2, s1Len, s2Len - 1, memo));
  }
  return memo[s1Len][s2Len] = ans;
}

int longestCommonSubSeqTab(string& s1, string& s2) {
  vector<int>* memoPast = new vector<int>(s2.size(), 0);
  for (int i = 1; i <= s1.size(); i++) {
    vector<int>* memoCurrent = new vector<int>(s2.size(), 0);
    for (int j = 1; j <= s2.size(); i++) {
      if (s1[i - 1] == s2[j - 1]) {
        memoCurrent[j] = memoPast[j - 1] + 1;
      } else {
        memoCurrent[j] = max(memoPast[j], memoCurrent[j - 1]);
      }
    }
    vector<int>* memoPastPtr = memoPast;
    memoPast = memoCurrent;
    delete memoPastPtr;
  }
  return memoPast[s2.size()];
}