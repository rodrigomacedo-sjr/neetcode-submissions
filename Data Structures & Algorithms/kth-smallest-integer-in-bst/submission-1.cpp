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
        TreeNode* it = root;
        stack<TreeNode*> st;
        vector<int> nums;
        while (!st.empty() || it) {
            while (it) {
                st.push(it);
                it = it->left;
            }
            it = st.top();
            st.pop();
            nums.push_back(it->val);

            it = it->right;
        }
        return nums[k - 1];
    }
};
