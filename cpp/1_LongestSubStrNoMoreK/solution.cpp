#include <bits/stdc++.h>

using namespace std;

pair<int, int> longestSubStrNoMoreThanKDistinct(string s, int k) {
  int start = 0;
  int endv = -1;
  unordered_map<char, int> chars;
  int maximum = 0;
  int finalStart = 0;
  int n = s.length();
  while (endv < n - 1) {
    endv++;
    int c = s.at(endv);
    if (chars.find(c) != chars.end()) {
      chars[c]++;
    } else {
      chars[c] = 1;
      // check if more distinct than k
      while (chars.size() > k) {
        chars[s[start]]--;
        if (chars[s[start]] == 0) {
          chars.erase(s[start]);
        }
        start++;
      }
    }
    if (maximum < endv - start + 1) {
      maximum = endv - start + 1;
      finalStart = start;
    }
  }
  return pair(maximum, finalStart);
}

int main() {
  auto subString = longestSubStrNoMoreThanKDistinct("aaracbiibbb", 2);
  cout << subString.first << " " << subString.second << endl;
  return 0;
}