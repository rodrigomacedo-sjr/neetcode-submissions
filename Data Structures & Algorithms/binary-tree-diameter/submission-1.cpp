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
private:
    int max_len = 1;

    int dfs(TreeNode* root, int len) {
        if (root == nullptr) return len;
        
        int i_start = max(dfs(root->left, len + 1), dfs(root->right, len + 1));
        int im_a_twist = 1 + dfs(root->left, 0) + dfs(root->right, 0);
        max_len = max({i_start, im_a_twist, max_len});

        return i_start;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return max(max_len, dfs(root, 0)) - 1;
    }
};
