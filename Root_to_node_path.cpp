// Root to node path in a binary tree

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

bool helper(TreeNode* root, int k, vector<int>& ans) {
    if(root == nullptr) {
        return false;
    }
    ans.push_back(root->val);
    if(root->val == k) {
        return true;
    }

    if(helper(root->left, k, ans) || helper(root->right, k, ans)) {
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode* root, int k) {
    vector<int> ans;
    if(root == nullptr) {
        return ans;
    }
    helper(root, k, ans);

    return ans;
}