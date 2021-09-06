// Right view of a binary tree using traversal: root->right->left

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

// recursive solution
void helper(TreeNode* root, int level, vector<int>& ans) {
    if(root == nullptr) {
        return;
    }

    if(ans.size() == level) {
        ans.push_back(root->val);
    }
    if(root->right != nullptr) {
        helper(root->right, level+1, ans);
    }
    if(root->left != nullptr) {
        helper(root->left, level+1, ans);
    }
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) {
        return ans;
    }
    int level = 0;
    helper(root, level, ans);

    return ans;
}

// iterative solution
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        ans.push_back(q.back()->val);
        int q_size = q.size();
        for(int i = 0; i < q_size; i++) {
            TreeNode* cur_node = q.front();
            q.pop();

            if(cur_node->left != nullptr) {
                q.push(cur_node->left);
            }
            if(cur_node->right != nullptr) {
                q.push(cur_node->right);
            }
        }
    }

    return ans;
}