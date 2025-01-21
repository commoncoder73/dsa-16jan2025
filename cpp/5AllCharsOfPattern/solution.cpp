#include <bits/stdc++.h>

using namespace std;

void fillFreq(int arr[], string s) {
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 'a']++;
  }
}

bool isPatternCharPresent(int subStrFm[], int patternFm[]) {
  for(int i=0; i<26; i++) {
    if (subStrFm[i] < patternFm[i]) {
      return false;
    }
  }
  return true;
}

// TC: O(N)
// SC: O(1) (since a-z chars)
pair<int, int> allCharsOfPatternMinSubString(string s, string pattern) {
  int start = 0;
  int endv = -1;
  int n = s.length();
  int patternFm[26]{0};
  fillFreq(patternFm, pattern);
  int subStrFm[26]{0};
  int minLen = INT_MAX;
  int finalStart = 0;
  while (endv < n - 1) {
    endv++;
    char nc = s[endv];
    subStrFm[nc-'a']++;

    while (isPatternCharPresent(subStrFm, patternFm)) {
      if (minLen > endv - start + 1) {
        minLen = endv - start + 1;
        finalStart = start;
      }
      subStrFm[s[start] - 'a']--;
      start++;

    }
  }
  return pair(minLen, finalStart);
}
