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
        return maxSum;
    }

private:
    int maxSum = INT_MIN;

    int check(TreeNode* root) {
        if (root == nullptr) return 0;

        int maxL = check(root->left);
        int maxR = check(root->right);

        int addL = max(maxL, 0);
        int addR = max(maxR, 0);

        int imTheTurn = root->val + addL + addR;

        if (imTheTurn > maxSum)
            maxSum = imTheTurn;

        int imNotTheTurn = root->val + max(addL, addR);

        return imNotTheTurn; // someone else is
    }
};
