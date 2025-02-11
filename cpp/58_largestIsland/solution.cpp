// https://leetcode.com/problems/max-area-of-island/description/
#include <bits/stdc++.h>

using namespace std;

int DiffI[] = {0, 0, 1, -1};
int DiffJ[] = {1, -1, 0, 0};

// int DiffI[] = {0, 0, 1, -1, -1, 1, 1, -1};
// int DiffJ[] = {1, -1, 0, 0, -1, 1, -1, 1};

int dfsCountNodes(vector<vector<int>>& grid, int i,
                  int j vector<vector<bool>>& visited) {
  int n = grid.size();
  int m = grid[0].size();
  if (i < 0 || j < 0 || i >= n || j >= m) {
    return 0;
  }
  if (visited[i][j]) {
    return 0;
  }
  visited[i][j] = true;
  if (grid[i][j] == 0) {
    return 0;
  }

  int count = 1;
  for (int k = 0; k < 4; k++) {
    // k = 0 -> i+0 = i      j+1   (i, j+1)
    // k = 1 -> i+0 = i      j-1   (i, j-1)
    // k = 2 -> i+1      j+0       (i+1, j)
    // k = 3 -> i-1      j+0       (i-1, j)
    count += dfsCountNodes(grid, i + DiffI[k], j + DiffJ[k], visited);
  }
  return count;
}

// int dfsCountNodes(vector<vector<int>>& grid, int i,
//                   int j vector<vector<bool>>& visited) {
//   int n = grid.size();
//   int m = grid[0].size();
//   if (i < 0 || j < 0 || i >= n || j >= m) {
//     return 0;
//   }
//   if (visited[i][j]) {
//     return 0;
//   }
//   visited[i][j] = true;
//   if (grid[i][j] == 0) {
//     return 0;
//   }

//   return 1 + dfsCountNodes(grid, i + 1, j, visited) +
//          dfsCountNodes(grid, i - 1, j, visited) +
//          dfsCountNodes(grid, i, j + 1, visited) +
//          dfsCountNodes(grid, i, j - 1, visited);
// }

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<bool>> visited(n, vector<bool>(m, false));

  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        int area = dfsCountNodes(grid, i, j, visited);
        maxArea = max(maxArea, area);
      }
    }
  }
  return maxArea;
}