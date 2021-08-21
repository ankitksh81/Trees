// Binary tree representation with node definitioin and creation

// Node definition
struct Node {
	int data;
	Node *left;
	Node *right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

int main() {
	Node *root = new Node(1); // Node creation
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
}