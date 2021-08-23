// Inorder Traversal iterative - [left, root, right]

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

// Storing Inorder in vector in
vector<int> in;

void inorder(Node* root) {
	stack<Node*> st;
	Node* node = root;

	while(true) {
		if(node != nullptr) {
			st.push(node);
			node = node->left;
		}
		else {
			if(st.empty())
				break;
			node = st.top();
			st.pop();
			in.push_back(node->val);
			node = node->right;
		}
	}	
}