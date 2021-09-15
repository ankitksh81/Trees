// Ceil val of a key in Binary search tree

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

int findCeil(TreeNode* root, int key) {
    int ceil = -1;
    while(root) {
        if(root->val == key) {
            ceil = root->val;
            return ceil;
        }

        if(key > root->val) {
            root = root->right;
        }
        else {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}