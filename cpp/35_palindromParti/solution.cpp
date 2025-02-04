#include <bits/stdc++.h>

using namespace std;

bool isPalin(string& s, int start, int end) {
  while (start < end) {
    if (s[start] != s[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

bool isPalin(string& s, int start, int end, vector<vector<int>>& memo) {
  if (memo[start][end] != 2) {
    return memo[start][end];
  }
  if ((end - start) <= 1) {
    return memo[end][start] = true;
  }
  if (s[start] == s[end]) {
    return memo[start][end] = isPalin(s, start + 1, end - 1);
  }
  return memo[start][end] = false;
}

void buildPalinMemo(string& s, vector<vector<int>>& memo) {
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      isPalin(s, i, j, memo);
    }
  }
}

int costToMakePartsPalin(string& s) {
  vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
  return costToMakePartsPalin(s, 0, s.size() - 1, memo);
}

int costToMakePartsPalin(string& s, int start, int end,
                         vector<vector<int>>& memoAns,
                         vector<vector<int>>& memoPalin) {
  if ((end - start) <= 1) {
    return 0;
  }
  if (memoAns[start][end] != -1) {
    return memoAns[start][end];
  }
  if (memoPalin[start][end]) {
    return 0;
  }
  int minVal = INT_MAX;

  for (int i = end - 1; i >= start; i--) {
    int leftCost = costToMakePartsPalin(s, start, i, memoAns, memoPalin);
    int rightCost = costToMakePartsPalin(s, i + 1, end, memoAns, memoPalin);
    minVal = min(minVal, leftCost + rightCost + 1);
  }

  return memoAns[start][end] = minVal;
}

int costToMakePartsPalintTab(string& s) {
  vector<vector<int>> memoAns(s.size(), vector<int>(s.size(), 0));
  vector<vector<int>> memoPalin(s.size(), vector<int>(d.size(), -1));
  buildPalinMemo(s, memoPalin);

  int start = 0;
  for (int k = 1; k < s.size(); k++) {
    start = 0;
    for (int end = k; end < s.size(); start++, end++) {
      if (memoPalin[start][end]) {
        continue;
      }
      int minVal = INT_MAX;
      for (int i = end - 1; i >= start; i--) {
        int leftCost = memo[start][i];
        int rightCost = memo[i + 1][end];
        minVal = min(minVal, 1 + leftCost + rightCost);
      }
      memo[start][end] = minVal;
    }
  }

  if ((end - start) <= 1) {
    return 0;
  }
  if (memoAns[start][end] != -1) {
    return memoAns[start][end];
  }
  if (memoPalin[start][end]) {
    return 0;
  }
  int minVal = INT_MAX;

  for (int i = end - 1; i >= start; i--) {
    int leftCost = costToMakePartsPalin(s, start, i, memoAns, memoPalin);
    int rightCost = costToMakePartsPalin(s, i + 1, end, memoAns, memoPalin);
    minVal = min(minVal, leftCost + rightCost + 1);
  }

  return memoAns[start][end] = minVal;
}


// TC: O(n*2)
// SC: O(n*2)
int costToMakePartsPalinTimeOpti(int end, vector<int>& memoAns,
                                 vector<vector<int>>& memoPalin) {
  if (end <= 0) {
    return 0;
  }
  if (memoPalin[0][end]) {
    return 0;
  }
  if (memoAns[end] != -1) {
    return memo[end];
  }

  int minVal = INT_MAX;
  for (int i = end; i >= 1; i--) {
    if (memoPalin[i][end]) {
      minVal = min(minVal, 1 + costToMakePartsPalinTimeOpti( i - 1, memoAns,
                                                            memoPalin));
    }
  }
  return memo[end] = minVal;
}
