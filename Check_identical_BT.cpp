// Check for identical binary tree

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

bool isSameTree(TreeNode* root1, TreeNode* root2) {
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if(root1 == nullptr || root2 == nullptr) {
        return false;
    }

    if(root1->val != root2->val) {
        return false;
    }

    return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
}