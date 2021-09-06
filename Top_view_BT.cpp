// Top view of a binary tree

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

vector<int> topView(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) {
        return ans;
    }
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int line = it.second;

        if(mp.find(line) == mp.end()) {
            mp[line] = node->data;
        }
        
        if(node->left != nullptr) {
            q.push({node->left, line - 1});
        }
        if(node->right != nullptr) {
            q.push({node->right, line + 1});
        }
    }

    for(auto it: mp) {
        ans.push_back(it.second);
    }

    return ans;
}