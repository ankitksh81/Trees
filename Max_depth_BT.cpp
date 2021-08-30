// Maximum Depth of Binary tree

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

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}