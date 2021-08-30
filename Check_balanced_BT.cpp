// Check for balanced binary tree
// Balanced BT: for each node, height(left) - height(right) <= 1

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

int helper(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int left_height = helper(root->left);
    int right_height = helper(root->right);

    if(left_height == -1 || right_height == -1) {
        return -1;
    }
    if(abs(left_height - right_height) > 1) {
        return -1;
    }

    return 1 + max(left_height, right_height);
}

bool isBalanced(TreeNode* root) {
    if(helper(root) == -1) {
        return false;
    }

    return true;
}