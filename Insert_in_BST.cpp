// Insert a given node in Binary search tree

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == nullptr) {
        return new TreeNode(val);
    }

    TreeNode* cur = root;
    while(true) {
        if(cur->val < val && cur->right) {
            cur = cur->right;
        }
        else if(cur->val > val && cur->left) {
            cur = cur->left;
        }
        else {
            break;
        }
    }

    if(cur->val > val) {
        cur->left = new TreeNode(val);
    }
    else {
        cur->right = new TreeNode(val);
    }

    return root;
}