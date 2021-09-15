// Floor val of a key in Binary search tree

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

int findFloor(TreeNode* root, int key) {
    int floor = -1;
    while(root) {
        if(root->val == key) {
            floor = root->val;
            return floor;
        }

        if(root->val > key) {
            root = root->left;
        }
        else {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}