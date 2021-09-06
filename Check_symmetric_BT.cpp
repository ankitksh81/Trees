// Check if the binary tree is symmetric

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

bool helper(TreeNode* left_root, TreeNode* right_root) {
    if(left_root == nullptr || right_root == nullptr) {
        return left_root == right_root;
    }
    if(left_root->val != right_root->val) {
        return false;
    }

    return helper(left_root->left, right_root->right) && helper(left_root->right, right_root->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) {
        return true;
    }
    if(helper(root->left, root->right)) {
        return true;
    }
    return false;
}