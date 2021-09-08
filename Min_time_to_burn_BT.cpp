// Minimum time to burn a binary tree starting from a given node.
// node value can be a integer or node itself.

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

void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res;

    while(!q.empty()) {
        TreeNode* cur_node = q.front();
        if(cur_node->val == start) {
            res = cur_node;
        }
        q.pop();

        if(cur_node->left != nullptr) {
            parent[cur_node->left] = cur_node;
            q.push(cur_node->left);
        }
        if(cur_node->right != nullptr) {
            parent[cur_node->right] = cur_node;
            q.push(cur_node->right);
        }
    }
}

int minTimeToBurn(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* target = mark_parent(root, parent, start);

    unordered_map<TreeNode*, bool> vis;
    queue<TreeNode*> q;
    q.push(start);
    vis[start] = true;
    int min_time = 0;
    while(!q.empty()) {
        int q_size = q.size();
        // min_time++;  // gives 1 more than expected.

        for(int i = 0; i < q_size; i++) {
            TreeNode* cur_node = q.front();
            q.pop();

            if(cur_node->left && !vis[cur_node->left]) {
                q.push(cur_node->left);
                vis[cur_node->left] = true;
            }
            if(cur_node->right && !vis[cur_node->right]) {
                q.push(cur_node->right);
                vis[cur_node->right] = true;
            }
            if(parent[cur_node] && !vis[parent[cur_node]]) {
                q.push(parent[cur_node]);
                vis[parent[cur_node]] = true;
            }
        }
        // correct way of calculating time
        // increase time when the nodes are in the queue
        if(!q.empty()) {
            min_time++;
        }

    }

    return min_time;
}