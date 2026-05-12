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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {
            auto [pit, qit] = st.top();
            st.pop();

            if (!qit || !pit) {
                if (qit != pit) return false;
                else continue;
            }
            
            if (qit->val != pit->val) return false;

            st.push({pit->left, qit->left});
            st.push({pit->right, qit->right});
        }

        return true;
    }
};
