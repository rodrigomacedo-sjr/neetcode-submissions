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
        queue<TreeNode*> qu;
        queue<int> levelQ;
        if (root) qu.push(root);
        levelQ.push(0);

        vector<vector<int>> ans;

        int level;
        TreeNode *it;
        while (!qu.empty()) {
            it = qu.front();
            qu.pop();

            level = levelQ.front();
            levelQ.pop();

            while (level + 1 > ans.size())
                ans.push_back({});
            
            ans[level].push_back(it->val);

            if (it->left) {
                qu.push(it->left);
                levelQ.push(level + 1);
            }
            if (it->right) {
                qu.push(it->right);
                levelQ.push(level + 1);
            }
        }
        return ans;
    }
};
