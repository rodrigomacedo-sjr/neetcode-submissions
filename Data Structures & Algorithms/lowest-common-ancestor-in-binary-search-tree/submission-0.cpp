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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *pit = root, *qit = root, *latest;

        while ((pit && pit != p) || (qit && qit != q)) {
            if (pit->val == qit->val) latest = pit;

            if (pit == p) ;
            else if (pit->val < p->val) pit = pit->right;
            else if (pit->val > p->val) pit = pit->left;

            if (qit == q) ;
            else if (qit->val < q->val) qit = qit->right;
            else if (qit->val > q->val) qit = qit->left;
        }

        return latest;
    }
};
