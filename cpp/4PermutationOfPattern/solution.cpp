#include <bits/stdc++.h>

using namespace std;

void fillFreq(int arr[], string s) {
  for (int i = 0; i < s.length(); i++) {
    arr[s[i] - 'a']++;
  }
}

bool areFreqMatching(int fm1[], int fm2[]) {
  for(int i=0; i<26; i++) {
    if (fm1[i] != fm2[i]) {
      return false;
    }
  }
  return true;
}

// TC: O(N)
// SC: O(1) (since a-z chars)
vector<int> isPermutationOfPatternPresent(string s, string pattern) {
  vector<int> startingIndexOfPermutations;
  int start = 0;
  int endv = -1;
  int n = s.length();
  int patternFm[26]{0};
  fillFreq(patternFm, pattern);
  int subStrFm[26]{0};
  while (endv < n - 1) {
    endv++;
    char nc = s[endv];
    subStrFm[nc - 'a']++;

    while(endv-start+1 > pattern.length()) {
      subStrFm[s[start] - 'a']--;
      start++;
    }

    if (areFreqMatching(patternFm, subStrFm)) {
      startingIndexOfPermutations.push_back(start);
    }
  }
  return startingIndexOfPermutations;
}
