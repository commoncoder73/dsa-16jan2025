#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
}


// Balanced Bst - O(logN)
// Not balanced - O(N)
TreeNode*
lca(TreeNode* root, int u, int v) {
  if (!root) {
    return nullptr;
  }
  if (u > v) {
    int temp = u;
    u = v;
    v = u;
  }

  if (root->val == u || root->val == v || (u <= root->val && root->val < v)) {
    return root;
  }

  if (u <= root->val && v <= root->val) {
    return lca(root->left, u, v);
  } 
  else {
    return lca(root->right, u, v);
  }
}