// Serialize and De-serialize a binary tree

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

string serialize(TreeNode* root) {
    if(root == nullptr) {
        return "";
    }

    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* cur_node = q.front();
        q.pop();

        if(cur_node == nullptr) {
            s.append("#,");
        }
        else {
            s.append(to_string(cur_node->val) + ',');
        }
        if(cur_node != nullptr) {
            q.push(cur_node->left);
            q.push(cur_node->right);
        }
    }

    return s;
}

TreeNode* deserialize(string data) {
    if(data.size() == 0) {
        return nullptr;
    }
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        getline(s, str, ',');
        if(str == "#") {
            node->left = nullptr;
        }
        else {
            TreeNode* left_node = new TreeNode(stoi(str));
            node->left = left_node;
            q.push(left_node);
        }

        getline(s, str, ',');
        if(str == "#") {
            node->right = nullptr;
        }
        else {
            TreeNode* right_node = new TreeNode(stoi(str));
            node->right = right_node;
            q.push(right_node);
        }
    }

    return root;
}