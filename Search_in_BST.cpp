// Search in a Binary Search Tree

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

TreeNode* searchBST(TreeNode* root, int val) {
    if(root == nullptr) {
        return root;
    }

    TreeNode* cur_node = root;
    while(cur_node != nullptr) {
        if(cur_node->val == val) {
            return cur_node;
        }
        if(cur_node->val < val) {
            cur_node = cur_node->right;
        }
        else {
            cur_node = cur_node->left;
        }
    }

    return nullptr;
}