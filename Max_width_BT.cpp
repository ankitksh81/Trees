// Maximum width of a binary tree
// Width: no of nodes in a level between any 2 nodes.

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

int widthOfBinaryTree(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    int max_width = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        int q_size = q.size();
        int min_idx = q.front().second;
        int first_idx, last_idx;
        for(int i = 0; i < q_size; i++) {
            int cur_idx = q.front().second - min_idx;
            TreeNode* cur_node = q.front().first;
            q.pop();

            if(i == 0) {
                first_idx = cur_idx;
            }
            if(i == q_size-1) {
                last_idx = cur_idx;
            }

            if(cur_node->left != nullptr) {
                q.push({cur_node->left, cur_idx * 2 + 1});
            }
            if(cur_node->right != nullptr) {
                q.push({cur_node->right, cur_idx * 2 + 2});
            }
        }
        max_width = max(max_width, last_idx - first_idx + 1);
    }

    return max_width;
}