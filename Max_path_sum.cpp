// Find maximum path sum in a binary tree

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

int find_maxPath(TreeNode* root, int &max_sum) {
    if(root == nullptr) {
        return 0;
    }

    int left_path = max(0, find_maxPath(root->left, max_sum));
    int right_path = max(0, find_maxPath(root->right, max_sum));

    max_sum = max(max_sum, left_path + right_path + root->val);

    return root->val + max(left_path, right_path);
}

int maxPathSum(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    int max_sum = INT_MIN;
    find_maxPath(root, max_sum);

    return max_sum;
}