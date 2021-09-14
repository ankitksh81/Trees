// Morris Traversal O(1) space for Preorder and Inorder
// It uses threaded binary tree

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

// Inorder Morris Traversal

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> in;
    TreeNode* cur = root;
    while(cur != nullptr) {
        if(cur->left == nullptr) {
            in.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {
                prev->right = cur;
                cur = cur->left;
            }
            else {
                prev->right = nullptr;
                in.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
}


// Preorder Morris Traversal

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> pre;
    TreeNode* cur = root;
    while(cur != nullptr) {
        if(cur->left == nullptr) {
            pre.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }

            if(prev->right == nullptr) {
                prev->right = cur;
                pre.push_back(cur->val);
                cur = cur->left;
            }
            else {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
    return pre;
}