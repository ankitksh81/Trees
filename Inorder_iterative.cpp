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
	if(root == nullptr) {
		return in;
	}

	
}