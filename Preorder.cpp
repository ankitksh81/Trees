// Preorder Traversal using recursion - [root, left, right]

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

void preorder(Node* root) {
	if(root == nullptr) {
		return;
	}

	pre.push_back(root->val);
	preorder(root->left);
	preorder(root->right);
}