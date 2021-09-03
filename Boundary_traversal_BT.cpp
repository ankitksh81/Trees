// Print Boundary of a binary tree

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

bool is_leaf(TreeNode* root) {
    if(root->left == nullptr && root->right == nullptr) {
        return true;
    }
    return false;
}

void left_boundary(TreeNode* root, vector<int> &ans) {
    TreeNode* cur_node = root->left;
    while(cur_node) {
        if(!is_leaf(cur_node)) {
            ans.push_back(cur_node->val);
        }
        if(cur_node->left) {
            cur_node = cur_node->left;
        }
        else {
            cur_node = cur_node->right;
        }
    }
}

void leaf_nodes(TreeNode* root, vector<int> &ans) {
    if(is_leaf(root)) {
        ans.push_back(root->val);
        return;
    }
    if(root->left != nullptr) {
        leaf_nodes(root->left, ans);
    }
    if(root->right != nullptr) {
        leaf_nodes(root->right, ans);
    }
}

void right_boundary(TreeNode* root, vector<int> &ans) {
    TreeNode* cur_node = root->right;
    vector<int> temp;
    while(cur_node) {
        if(!is_leaf(cur_node)) {
            temp.push_back(cur_node->val);
        }
        if(cur_node->right) {
            cur_node = cur_node->right;
        }
        else {
            cur_node = cur_node->left;
        }
    }

    for(int i = temp.size()-1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

vector<int> printBoundary(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) {
        return ans;
    }

    if(!is_leaf(root)) {
        ans.push_back(root->val);
    }

    left_boundary(root, ans);
    leaf_nodes(root, ans);
    right_boundary(root, ans);

    return ans;
}