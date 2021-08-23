// Postorder Traversal iterative - [left, right, root]

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

// Storing Postorder in vector post
vector<int> post;

// using 2 stacks
void postorder(Node* root) {
    if(root == nullptr) {
        return post;
    }
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left) {
            st1.push(root->left);
        }
        if(root->right) {
            st1.push(root->right);
        }
    }

    while(!st2.empty()) {
        post.push_back(st2.top()->val);
        st2.pop();
    }
}

// using 1 stack
void postorder(Node* root) {
    Node* cur = root, temp;
    stack<Node*> st;

    while(cur != nullptr || !st.empty()) {
        if(cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        else {
            temp = st.top()->right;
            if(temp == nullptr) {
                temp = st.top();
                st.pop();
                post.push_back(temp->val);

                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);
                }
            }
            else {
                cur = temp;
            }
        }
    }
}