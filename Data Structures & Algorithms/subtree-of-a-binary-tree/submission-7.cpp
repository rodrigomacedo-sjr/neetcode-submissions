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
        if (!subRoot) return true;
        if (!root) return false;

        if (isEqual(root, subRoot)) return true;
        else if (isSubtree(root->left, subRoot)) return true;
        else if(isSubtree(root->right, subRoot)) return true;

        return false;
    }
private:
    bool isEqual(TreeNode *a, TreeNode *b) {
        if (!a || !b) return a == b;
    
        if (a->val != b->val) return false;
        
        return isEqual(a->left, b->left) && isEqual(a->right, b->right);
    }
};
