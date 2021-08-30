// Diamerter: longest path between any two nodes.(Path may or may not pass through the root)

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

int helper(TreeNode* root, int &diameter) {
    if(root == nullptr) {
        return 0;
    }

    int left_height = helper(root->left, diameter);
    int right_height = helper(root->right, diameter);

    diameter = max(diameter, left_height + right_height);

    return 1 + max(left_height, right_height);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = -1;
    helper(root, diameter);

    return diameter;
}