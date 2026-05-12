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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if ((!root && subRoot) || (root && !subRoot)) return false;

        bool ans = isEqual(root, subRoot);
        ans = ans || isSubtree(root->left, subRoot);
        ans = ans || isSubtree(root->right, subRoot);
        return ans;
    }
private:
    bool isEqual(TreeNode *a, TreeNode *b) {
        if (!a && !b) return true;
        if ((!a && b) || (a && !b)) return false;
    
        if (a->val == b->val)
            return isEqual(a->left, b->left) && isEqual(a->right, b->right);

        return false;
    }
};
