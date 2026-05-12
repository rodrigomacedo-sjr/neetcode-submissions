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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> qu;
        qu.push(root);

        vector<vector<int>> ans;

        TreeNode *it;
        while (!qu.empty()) {
            int levelSize = qu.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; ++i) {
                it = qu.front();
                qu.pop();

                currentLevel.push_back(it->val);

                if (it->left) qu.push(it->left);
                if (it->right) qu.push(it->right);
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }
};
