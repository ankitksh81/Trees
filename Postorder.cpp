// Postorder Traversal using recursion - [left, right, root]

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

// Storing Postorder in vector in
vector<int> post;

void postorder(Node* root) {
	if(root == nullptr) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	post.push_back(root->val);
}