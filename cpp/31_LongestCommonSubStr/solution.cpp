#include <bits/stdc++.h>

using namespace std;

int longestCommonSubstr(string& s1, string& s2) {
  vector<vector<pair<int, int>>> memo(
      s1.size() + 1, vector<pair<int, int>>(s2.size() + 1, {-1, -1}));
  return longestCommonSubstr(s1, s2, s1.size(), s2.size(), memo).first;
}

pair</*overAllLongestCommonSubstr*/ int, /*commonSubStrEndingHere*/ int>
longestCommonSubstr(string& s1, string& s2, int s1Len, int s2Len) {
  if (s1Len <= 0 || s2Len <= 0) {
    return {0, 0};
  }
  int commonSubStrEndingHere = 0;
  if (s1[s1Len - 1] == s2[s2Len - 1]) {
    commonSubStrEndingHere =
        1 + longestCommonSubstr(s1, s2, s1Len - 1, s2Len - 1).second;
  }
  int longestCommonSubStr =
      max(commonSubStrEndingHere,
          max(longestCommonSubstr(s1, s2, s1Len - 1, s2Len).first,
              longestCommonSubstr(s1, s2, s1Len, s2Len - 1).first));
  return pair<int, int>(longestCommonSubStr, commonSubStrEndingHere);
}

pair</*overAllLongestCommonSubstr*/ int, /*commonSubStrEndingHere*/ int>
longestCommonSubstr(string& s1, string& s2, int s1Len, int s2Len,
                    vector<vector<pair<int, int>>>& memo) {
  if (s1Len <= 0 || s2Len <= 0) {
    return {0, 0};
  }
  if (memo[s1Len][s2Len].first != -1) {
    return memo[s1Len][s2Len];
  }
  int commonSubStrEndingHere = 0;
  if (s1[s1Len - 1] == s2[s2Len - 1]) {
    commonSubStrEndingHere =
        1 + longestCommonSubstr(s1, s2, s1Len - 1, s2Len - 1, memo).second;
  }
  int longestCommonSubStr =
      max(commonSubStrEndingHere,
          max(longestCommonSubstr(s1, s2, s1Len - 1, s2Len, memo).first,
              longestCommonSubstr(s1, s2, s1Len, s2Len - 1, memo).first));
  return memo[s1Len][s2Len] =
             pair<int, int>(longestCommonSubStr, commonSubStrEndingHere);
}

pair</*overAllLongestCommonSubstr*/ int, /*commonSubStrEndingHere*/ int>
longestCommonSubstrTab(string& s1, string& s2) {
  vector<vector<pair<int, int>>> memo(
      s1.size() + 1, vector<pair<int, int>>(s2.size() + 1, {0, 0}));

  for (int s1Len = 1; s1Len <= s1.size(); s1Len++) {
    for (int s2Len = 1; s2Len <= s2.size(); s2Len++) {
      int commonSubStrEndingHere = 0;
      if (s1[s1Len - 1] == s2[s2Len - 1]) {
        commonSubStrEndingHere = 1 + memo[s1Len - 1][s2Len - 1].second;
      }

      int longestCommonSubStr =
          max(commonSubStrEndingHere,
              max(memo[s1Len - 1][s2Len].first, memo[s1Len][s2Len - 1].first));

      memo[s1Len][s2Len] = {longestCommonSubStr, commonSubStrEndingHere};
    }
  }

  return memo[s1.size()][s2.size()];
}