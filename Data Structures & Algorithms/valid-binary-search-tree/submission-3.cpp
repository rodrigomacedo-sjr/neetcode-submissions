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
    bool isValidBST(TreeNode* root) {
        return checkBST(root);
    }
private:
    bool checkBST(TreeNode *root, TreeNode *min = nullptr, TreeNode *max = nullptr) {
        if (!root) return true;

        if (min && root->val <= min->val) return false;

        if (max && root->val >= max->val) return false;

        return checkBST(root->left, min, root) && checkBST(root->right, root, max);
    }
};
