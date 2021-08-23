// Level order Traversal

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

// Storing level order in vector level
vector<vector<int>> level;

void levelorder(Node* root) {
    if(root == nullptr){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> cur_level;

        for(int i = 0; i < size; i++) {
            Node* cur_node = q.front();
            q.pop();

            if(cur_node->left != nullptr) {
                q.push(cur_node->left);
            }
            if(cur_node->right != nullptr) {
                q.push(cur_node->right);
            }
            cur_level.push_back(cur_node->val);
        }

        level.push_back(cur_level);
    }
}