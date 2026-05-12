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
        stack<TreeNode*> st;
        int count = 0;

        TreeNode* it = root;
        while (!st.empty() || it) {
            while (it) {
                st.push(it);
                it = it->left;
            }

            it = st.top();
            st.pop();
            if (++count >= k) return it->val;

            it = it->right;
        }
        return -1;
    }
};
