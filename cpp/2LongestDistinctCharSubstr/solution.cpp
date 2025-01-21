#include <bits/stdc++.h>

using namespace std;


pair<int, int> longestDistinctCharSubStr(string s) {
  int start = 0;
  int endv = -1;
  int n = s.length();
  int maxLen = 0;
  unordered_set<char> visited;
  int finalStart = 0;
  while(endv < n - 1) {
    endv++;
    char nc = s[endv];
    while(visited.find(nc) != visited.end()) {
        visited.erase(s[start]);
        start++;
    }
    visited.insert(nc);

    if (maxLen < endv - start + 1) {
        maxLen = endv - start + 1;
        finalStart = start;
    }
  }

  
  return pair(maxLen, finalStart);
}


int main() {
  auto subString = longestDistinctCharSubStr("aaracbiibbb");
  cout << subString.first << " " << subString.second << endl;
  return 0;
}
