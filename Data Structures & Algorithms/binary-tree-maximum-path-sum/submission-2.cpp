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
    int maxPathSum(TreeNode* root) {
        check(root);
        return max;
    }

private:
    int max = INT_MIN;

    int check(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxL = check(root->left);
        int maxR = check(root->right);

        int addL = maxL > 0 ? maxL : 0;
        int addR = maxR > 0 ? maxR : 0;

        int imTheTurn = root->val + addL + addR;

        if (imTheTurn > max)
            max = imTheTurn;

        int imNotTheTurn = addL > addR ? root->val + addL : root->val + addR;

        return imNotTheTurn; // someone else is
    }
};
