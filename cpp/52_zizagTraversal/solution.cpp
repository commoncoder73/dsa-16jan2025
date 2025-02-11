#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  vector<TreeNode*> children;
}

// TC: O(N)
vector<TreeNode*>
zigZag(TreeNode* root) {
  vector<TreeNode*> ans;
  queue<TreeNode*> q;
  q.push(root);

  int levelNum = 0;
  while (!q.empty()) {
    int levelSize = q.size();
    vector<TreeNode*> subAnsForLevel;
    for (int i = 0; i < levelSize; i++) {
      TreeNode* front = q.front();
      q.pop();

      subAnsForLevel.push_back(front);

      for (auto child : front->children) {
        q.push(child);
      }
    }

    // if even move left to right
    if (levelNum % 2 == 0) {
      for (auto val : subAnsForLevel) {
        ans.push_back(val);
      }
    } else {
      for (int i = subAnsForLevel.size() - 1; i >= 0; i--) {
        ans.push_back(subAnsForLevel[i]);
      }
    }
  }

  return ans;
}

// TC: O(N)
vector<vector<TreeNode*>> zigZagSplitted(TreeNode* root) {
  vector<vector<TreeNode*>> ans;
  queue<TreeNode*> q;
  q.push(root);

  int levelNum = 0;
  while (!q.empty()) {
    int levelSize = q.size();
    vector<TreeNode*> subAnsForLevel(levelSize);
    for (int i = 0; i < levelSize; i++) {
      TreeNode* front = q.front();
      q.pop();

      if (levelNum % 2 == 0) {
        ans[i] = front;
      } else {
        ans[levelSize - i - 1] = front;
      }

      for (auto child : front->children) {
        q.push(child);
      }
    }

    ans.push_back(subAnsForLevel);
  }

  return ans;
}