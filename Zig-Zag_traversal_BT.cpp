// Zig-Zag or Spiral traversal in BT

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	if(root == nullptr) {
		return {};
	}
	vector<vector<int>> ans;
	queue<TreeNode*> q;
	bool left_to_right = true;
	
	q.push(root);
	while(!q.empty()) {
		int q_size = q.size();
		vector<int> cur_level;
		for(int i = 0; i < q_size; i++) {
			auto node = q.front();
			q.pop();

			if(node->left != nullptr) {
				q.push(node->left);
			}
			if(node->right != nullptr) {
				q.push(node->right);
			}

			cur_level.push_back(node->val);
		}

		if(!left_to_right) {
			reverse(cur_level.begin(), cur_level.end());
			left_to_right = true;
		}
		else {
			left_to_right = false;
		}
		ans.push_back(cur_level);
	}

	return ans;
}