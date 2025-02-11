#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
}

bool isValidBst(TreeNode* root) {
  if (!root) {
    return true;
  }
  if (root->left && root->val < root->left->val) {
    return false;
  }

  if (root->right && root->val >= root->right->val) {
    return false;
  }
  return isValidBst(root->left) && isValidBst(root->right);
}

bool isValidBst(TreeNode* root, int minVal, int maxVal) {
  if (!root) {
    return true;
  }
  if (root->val <= minVal || root->val > maxVal) {
    return false;
  }
  return isValidBst(root->left, minVal, root->val) && isValidBst(root->right, root->val, maxVal);
}