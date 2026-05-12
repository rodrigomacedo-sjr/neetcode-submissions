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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return nums[k - 1];
    }

private:
    vector<int> nums;
    void dfs(TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        nums.push_back(node->val);
        dfs(node->right);
    }
};
