#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
}


// TC: O(N)
// SC: O(N)
vector<TreeNode*>
verticalOrderTraversal(TreeNode* root) {
  unordered_map<int, vector<TreeNode*>*> hviMap;
  queue<pair<TreeNode*, int>> q;
  q.push({root, 0});
  int minHIndex = INT_MAX;
  int maxHIndex = INT_MIN;
  while (!q.empty()) {
    auto frontNode = q.front();
    minHIndex = min(minHIndex, frontNode.second);
    maxHIndex = max(maxHIndex, frontNode.second);

    if (hviMap.find(frontNode.second) != hviMap.end()) {
      hviMap[frontNode.second]->push_back(frontNode.first);
    } else {
      vector<TreeNode*>* hVector = new vector<TreeNode*>();
      hVector->push_back(frontNode.first);
      hviMap[frontNode.second] = hVector;
    }

    if (frontNode.first->left) {
      q.push({frontNode.first->left, frontNode.second - 1});
    }

    if (frontNode.first->right) {
      q.push({frontNode.first->right, frontNode.second + 1});
    }
  }

  vector<TreeNode*> ans;
  for (int i = minHIndex; i <= maxHIndex; i++) {
    for (auto node : hviMap[i]) {
      ans.push_back(node);
    }
  }

  return ans;
}