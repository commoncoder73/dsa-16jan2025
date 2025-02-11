//https://leetcode.com/problems/rotting-oranges/
#include <bits/stdc++.h>

using namespace std;

const int DX = {1, -1, 0, 0};
const int DY = {0, 0, 1, -1};

int minMinutes(vector<vector<int>> grid) {
  int r = grid.size();
  int c = grid[0].size();
  queue<pair<int, int>> q;
  int totalFreshOranges = 0;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 1) {
        totalFreshOranges++;
      }
      if (grid[i][j] == 2) {
        q.push({i, j});
      }
    }
  }

  int minutes = 0;
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
        if (grid[newX][newY] != 1) {
          continue;
        }
        grid[newX][newY] = 2;
        q.push({newX, newY});
        totalFreshOranges--;
      }
    }
    if (!q.empty()) {
      minutes++;
    }
  }

  return totalFreshOranges == 0 ? minutes : -1;
}