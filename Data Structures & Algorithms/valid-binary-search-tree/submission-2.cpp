/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isValidBST(TreeNode* root, int l = INT_MIN, int r = INT_MAX) {
        if (!root) return true;

        if (root->val <= l || root->val >= r) return false;

        if (root->left && root->val > root->left->val) {
            if (!isValidBST(root->left, l, root->val)) return false;
        }
        else if (root->left) return false;

        if (root->right && root->val < root->right->val) {
            if (!isValidBST(root->right, root->val, r)) return false;
        }
        else if (root->right) return false;

        return true;
    }
};
