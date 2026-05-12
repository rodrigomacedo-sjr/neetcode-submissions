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

    TreeNode* deserializeSubData(string& data, int& idx) {
        string subData = processData(data, idx);

        if (subData == "n") return nullptr;

        int val = stoi(subData);

        TreeNode* newNode = new TreeNode(val);
        newNode->left = deserializeSubData(data, idx);
        newNode->right = deserializeSubData(data, idx);

        return newNode;
    }

    string processData(string& data, int& idx) {
        while (data[idx] == ' ') idx++;

        if (data[idx] == 'n') {
            idx++;
            return "n";
        }

        string num_str;
        while (data[idx] != ' ') {
            num_str += data[idx++];
        }
        return num_str;
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
        int idx = 0;
        return deserializeSubData(data, idx);
    }
};
