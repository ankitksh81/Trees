// Flatten a binary tree to Linked list: 3 approaches

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Approach 1: Using reverse pre-order traversal (right->left->root)

TreeNode* prev = nullptr;
void flattenBinaryTreeHelper(TreeNode* root) {
    if(root == nullptr) {
        return;
    }

    flattenBinaryTreeHelper(root->right);
    flattenBinaryTreeHelper(root->left);

    root->right = prev;
    root->left = nullptr;
    prev = root;
}

void flattenBinaryTree(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    flattenBinaryTreeHelper(root);
}


// Approach 2: using reverse pre-order traversal with stack

void flattenBinaryTreeHelper(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    TreeNode* cur_node;
    while(!st.empty()) {
        cur_node = st.top();
        st.pop();

        if(cur_node->right) {
            st.push(cur_node->right);
        }
        if(cur_node->left) {
            st.push(cur_node->left);
        }

        if(!st.empty()) {
            cur_node->right = st.top();
        }
        cur_node->left = nullptr;
    }
}


void flattenBinaryTree(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    flattenBinaryTreeHelper(root);
}


// Approach 3: using Morris Traversal

void flattenBinaryTreeHelper(TreeNode* root) {
    TreeNode* cur_node = root, *prev;
    while(cur_node != nullptr) {
        if(cur_node->left) {
            prev = cur_node->left;
            
            while(prev->right) {
                prev = prev->right;
            }
            prev->right = cur_node->right;
            cur_node->right = cur_node->left;
            cur_node->left = nullptr;
        }
        cur_node = cur_node->right;
    }
}

void flattenBinaryTree(TreeNode* root) {
    if(root == nullptr) {
        return;
    }
    flattenBinaryTreeHelper(root);
}