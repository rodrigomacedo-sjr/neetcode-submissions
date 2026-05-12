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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* it = root, *prev = nullptr;

        while (it != nullptr) {
            prev = it;
            if (it->val > val) {
                it = it->left;
            } else {
                it = it->right;
            }
        }
        if (prev->val > val) {
            prev->left = new TreeNode(val);
        } else if (prev->val < val) {
            prev->right = new TreeNode(val);
        }


        return root;
    }
};