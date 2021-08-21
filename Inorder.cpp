// Inorder Traversal using recursion - [left, root, right]

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

// Storing preorder in vector in
vector<int> in;

void inorder(Node* root) {
	if(root == nullptr) {
		return;
	}

	inorder(root->left);
	in.push_back(root->val);
	inorder(root->right);
}