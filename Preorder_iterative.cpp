// Preorder Traversal iterative - [root, left, right]

/* Node definition
struct Node {
	int val;
	Node *left;
	Node *right;

	Node(int data) {
		val = data;
		left = right = NULL;
	}
};
*/

// Storing preorder in vector pre
vector<int> pre;

void Preorder(Node* root) {
	if(root == nullptr) {
		return pre;
	}

	stack<Node*> st;
	st.push_back(root);
	while(!st.empty()) {
		auto it = st.top();
		st.pop();
		pre.push_back(it->val);
		
		if(it->right) {
			st.push(it->right);
		}
		if(it->left) {
			st.push(it->left);
		}
	}
}