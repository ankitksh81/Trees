// Children sum property in a binary tree O(n)
// we can only add 1 to a node any number of times but not subtract from a node

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

void changeTree(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    int child_val = 0;
    
    if(root->left != nullptr) {
        child_val += root->left->val;
    }
    if(root->right != nullptr) {
        child_val += root->right->val;
    }

    if(child_val >= root->val) {
        root->val = child_val;
    }
    else {
        if(root->left != nullptr) {
            root->left->val = root->val;
        }
        else if(root->right != nullptr) {
            root->right->val = root->val;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left != nullptr) {
        total += root->left->val;
    }
    if(root->right != nullptr) {
        total += root->right->val;
    }
    if(root->left != nullptr || root->right != nullptr) {
        root->val = total;
    }
}