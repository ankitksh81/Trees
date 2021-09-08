// All nodes at a distance K in a binary tree

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

void mark_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* cur_node = q.front();
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

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent; // node -> parent
    mark_parents(root, parent);

    unordered_map<TreeNode*, bool> vis;
    queue<TreeNode*> q;
    vis[target] = true;
    q.push(target);
    int cur_level = 0;

    while(!q.empty()) { // second BFS to go upto K level from target node
        int q_size = q.size();
        if(cur_level == k) {
            break;
        }
        cur_level++;

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
    }

    vector<int> ans;
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        ans.push_back(node->val);
    }
    return ans;
}