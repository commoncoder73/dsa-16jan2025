#include <bits/stdc++.h>

using namespace std;

const int DX = {1, -1, 0, 0};
const int DY = {0, 0, 1, -1};

vector<vector<int>> shortestDistancesFromOnes(vector<vector<int>> grid) {
  int r = grid.size();
  int c = grid[0].size();
  vector<vector<int>> ans(r, vector<int>(c, -1));
  queue<pair<int, int>> q;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 1) {
        q.push({i, j});
        ans[i][j] = 0;
      }
    }
  }

  int distance = 1;
  while (!q.empty()) {
    int qSize = q.size();
    while (qSize-- > 0) {
      auto cell = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int newX = cell.first + DX[i];
        int newY = cell.second + DY[i];
        if (newX < 0 || newX >= r || newY < 0 || newY >= c) {
          continue;
        }
        if (ans[newX][newY] != -1) {
          continue;
        }
        q.push({newX, newY});
        ans[newX][newY] = distance;
      }
    }
    distance++;
  }

  return ans;
}