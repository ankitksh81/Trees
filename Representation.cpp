// Binary tree representation with node definitioin and creation

// Node definition
struct Node {
    int val;
    Node *left;
    Node *right;

    Node(int data) {
        val = data;
        left = right = NULL;
    }
};

// 2nd definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int main() {
    Node *root = new Node(1); // Node creation
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    // To print
    cout << root->val << "\n"; 
    cout << root->left->val << "\n";
    cout << root->right->val << "\n";
}