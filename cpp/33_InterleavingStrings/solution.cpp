#include <bits/stdc++.h>

using namespace std;

bool areStringsInterleaving(string& s1, string& s2, string& s3) {
  if (s1.size() + s2.size() != s3.size()) return false;
  return areStringsInterleaving(s1, s2, s3, s1.size(), s2.size());
}

bool areStringsInterleaving(string& s1, string& s2, string& s3, int s1Len,
                            int s2Len) {
  if (s1Len == 0 && s2Len == 0) return true;
  int s3Len = s1Len + s2Len;

  bool matchingWithS1 = false;
  if (s1Len > 0 && s1[s1Len - 1] == s3[s3Len - 1]) {
    matchingWithS1 = areStringsInterleaving(s1, s2, s3, s1Len - 1, s2Len);
  }

  if (matchingWithS1) return true;

  bool matchingWithS2 = false;
  if (s2Len > 0 && s2[s2Len - 1] == s3[s3Len - 1]) {
    matchingWithS2 = areStringsInterleaving(s1, s2, s3, s1Len, s2Len - 1);
  }

  return matchingWithS2;
}