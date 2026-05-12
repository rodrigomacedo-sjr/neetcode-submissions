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
        vector<vector<int>> ans;
        createLevelList(root, 0, ans);
        return ans;
    }
private:
    void createLevelList(TreeNode* node, int level, vector<vector<int>> &levelList) {
        if (!node) return;

        if (level + 1 > levelList.size())
            levelList.resize(level + 1);

        levelList[level].push_back(node->val);

        createLevelList(node->left, level + 1, levelList);
        createLevelList(node->right, level + 1, levelList);
    }
};
