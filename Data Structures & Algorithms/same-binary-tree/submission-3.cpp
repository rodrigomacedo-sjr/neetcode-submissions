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
        if (!p && !q) return true;

        stack<TreeNode*> pst, qst;
        pst.push(p);
        qst.push(q);

        TreeNode *pit, *qit;
        while (!pst.empty() || !qst.empty()) {
            pit = pst.top(); pst.pop();
            qit = qst.top(); qst.pop();

            if ((pit && !qit) || (!pit && qit)) return false;
            if (pit && qit && pit->val != qit->val) return false;

            if (pit->left && qit->left) {
                pst.push(pit->left);
                qst.push(qit->left);
            } else if (pit->left || qit->left) return false;


            if (pit->right && qit->right) {
                pst.push(pit->right);
                qst.push(qit->right);
            } else if (pit->right || qit->right) return false;
        }
        return true;
    }
};
