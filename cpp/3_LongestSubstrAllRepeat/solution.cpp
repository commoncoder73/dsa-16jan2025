#include <bits/stdc++.h>

using namespace std;

int getMaxCount(int charCounts[]) {
  int maxVal = 0;
  for (int i = 0; i < 26; i++) {
    if (maxVal < charCounts[i]) {
      maxVal = charCounts[i];
    }
  }
  return maxVal;
}

// TC: O(N)
// SC: O(1) (since a-z chars)
pair<int, int> longestSubStrAllSame(string s, int k) {
  int start = 0;
  int endv = -1;
  int n = s.length();
  int maxLen = 0;
  int charCounts[26]{0};
  int finalStart = 0;
  while (endv < n - 1) {
    endv++;
    char nc = s[endv];
    charCounts[nc - 'a']++;
    int currentMaxRepeatingCharCount = getMaxCount(charCounts);
    while ((endv - start + 1) - currentMaxRepeatingCharCount > k) {
      charCounts[s[start] - 'a']--;
      start++;
    }

    if (maxLen < endv - start + 1) {
      maxLen = endv - start + 1;
      finalStart = start;
    }
  }

  return pair(maxLen, finalStart);
}
