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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIdx[inorder[i]] = i;
        }

        return buildSubTree(preorder, 0, inorder, 0, inorder.size() - 1);
    }
private:
    unordered_map<int, int> inorderIdx;

    TreeNode* buildSubTree(vector<int>& preorder, int preIdx, vector<int>& inorder, int inLeft, int inRight) {
        if (inLeft > inRight || inRight >= inorder.size() || preIdx >= preorder.size()) return nullptr;

        TreeNode* newNode = new TreeNode(preorder[preIdx]);

        if (inRight - inLeft <= 0) return newNode;

        int inIdx = inorderIdx[preorder[preIdx]];
        newNode->left = buildSubTree(preorder, preIdx + 1, inorder, inLeft, inIdx - 1);

        int leftSize = inIdx - inLeft;
        newNode->right = buildSubTree(preorder, preIdx + leftSize + 1, inorder, inIdx + 1, inRight);

        return newNode;
    }
};
