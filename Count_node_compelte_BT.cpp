// Count the number of nodes in a complete tree

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

int find_left_height(TreeNode* root) {
    int height = 0;
    while(root) {
        height++;
        root = root->left;
    }

    return height;
}

int find_right_height(TreeNode* root) {
    int height = 0;
    while(root) {
        height++;
        root = root->right;
    }

    return height;
}

int countNodes(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int lHeight = find_left_height(root);
    int rHeight = find_right_height(root);

    if(lHeight == rHeight) {
        return (1 << lHeight) - 1; // 2 ^ height - 1
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}