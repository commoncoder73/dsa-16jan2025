#include <bits/stdc++.h>

using namespace std;

// Assuming S1 is s1's length and S2 is s2's length
// TC: O(2^(max(S1, S2)))
// SC: O(max(S1, S2))

// Assuming S1 is s1's length and S2 is s2's length
// TC: O(S1*S2)
// SC: O(S1*S2)
int minAddDelOperations(string& s1, string& s2) {
  vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
  return minAddDelOperations(s1, s2, s1.size(), s2.size());
}

int minAddDelOperations(string& s1, string& s2, int s1Len, int s2Len) {
  if (s1Len <= 0) {
    return s2Len;
  }
  if (s2Len <= 0) {
    return s1Len;
  }

  if (s1[s1Len - 1] == s2[s2Len - 1]) {
    return minAddDelOperations(s1, s2, s1Len - 1, s2Len - 1);
  }
  return 1 + min(min(minAddDelOperations(s1, s2, s1Len - 1, s2Len),
                 minAddDelOperations(s1, s2, s1Len, s2Len - 1)),
                 minAddDelOperations(s1, s2, s1Len-1, s2Len - 1))
}

int minAddDelOperations(string& s1, string& s2, int s1Len, int s2Len,
                        vector<vector<int>> memo) {
  if (s1Len <= 0) {
    return s2Len;
  }
  if (s2Len <= 0) {
    return s1Len;
  }

  if (memo[s1Len][s2Len] != -1) {
    return memo[s1Len][s2Len];
  }

  int ans;
  if (s1[s1Len - 1] == s2[s2Len - 1]) {
    ans = minAddDelOperations(s1, s2, s1Len - 1, s2Len - 1, memo) + 1;
  } else {
    ans = max(minAddDelOperations(s1, s2, s1Len - 1, s2Len, memo),
              minAddDelOperations(s1, s2, s1Len, s2Len - 1, memo));
  }
  return memo[s1Len][s2Len] = ans;
}

int longestCommonSubSeqTab(string& s1, string& s2) {
  vector<vector<int>> memo =
      vector<int>(s1.size() + 1, vector<int>(s2.size() + 1, 0));
  for (int i = 0; i <= s1.size(); i++) {
    memo[i][0] = i;
  }
  for (int i = 0; i <= s2.size(); i++) {
    memo[0][i] = i;
  }
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); i++) {
      if (s1[i - 1] == s2[j - 1]) {
        memo[i][j] = memo[i - 1][j - 1];
      } else {
        memo[i][j] = 1 + min(memo[i - 1][j], memo[i][j - 1]);
      }
    }
  }
  return memo[s1.size()][s2.size()];
}

int longestCommonSubSeqTabOpti(string& s1, string& s2) {
  vector<int>* memoPast = new vector<int>(s2.size(), 0);
  for (int i = 0; i <= s2.size(); i++) {
    memoPast[i] = i;
  }

  for (int i = 1; i <= s1.size(); i++) {;
    vector<int>* memoCurrent = new vector<int>(s2.size(), 0);
    memoCurrent[0] = i
    for (int j = 1; j <= s2.size(); i++) {
      if (s1[i - 1] == s2[j - 1]) {
        memoCurrent[j] = memoPast[j - 1];
      } else {
        memoCurrent[j] = 1 + min(memoPast[j], memoCurrent[j - 1]);
      }
    }
    vector<int>* memoPastPtr = memoPast;
    memoPast = memoCurrent;
    delete memoPastPtr;
  }
  return memo[s2.size()];
}