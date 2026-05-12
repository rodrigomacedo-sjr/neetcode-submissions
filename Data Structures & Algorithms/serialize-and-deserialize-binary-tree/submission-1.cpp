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

class Codec {
private:
    void preOrder(TreeNode* node, string& serialized) {
        if (!node) {
            serialized += "n ";
            return;
        }

        serialized += to_string(node->val) + " ";
        preOrder(node->left, serialized);
        preOrder(node->right, serialized);
    }

    TreeNode* deserializeSubData(stringstream& data) {
        string token;
        data >> token;

        if (token == "n") return nullptr;

        int val = stoi(token);

        TreeNode* newNode = new TreeNode(val);
        newNode->left = deserializeSubData(data);
        newNode->right = deserializeSubData(data);

        return newNode;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized;

        preOrder(root, serialized);

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeSubData(ss);
    }
};
