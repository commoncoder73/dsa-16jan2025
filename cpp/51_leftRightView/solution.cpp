#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  vector<TreeNode*> children;
}

pair<vector<TreeNode*>>
leftRightView(TreeNode* root) {
  vector<TreeNode*> leftView;
  vector<TreeNode*> rightView;
  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int levelSize = q.size();
    for (int i = 0; i < levelSize; i++) {
      TreeNode* front = q.front();
      q.pop();

      if (i == 0) {
        leftView.push_back(front);
      }

      if (i == levelSize - 1) {
        rightView.push_back(front);
      }

      for (auto child : front->children) {
        q.push(child);
      }
    }
  }

  return pair(leftView, rightView);
}