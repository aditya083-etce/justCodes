#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

TreeNode* root = NULL;

void insertNode(int data) {
    TreeNode* newTreeNode = new TreeNode(data);

    if(!root) {
        root = newTreeNode;
        return;
    }

    queue<TreeNode*> Q;
    Q.push(root);

    while(!Q.empty()) {
        TreeNode* curr = Q.front();
        Q.pop();

        if(curr->left == NULL) {
            curr->left = newTreeNode;
            return;
        } else Q.push(curr->left);

        if(curr->right == NULL) {
            curr->right = newTreeNode;
            return;
        } else Q.push(curr->right);
    }
}

void printTree() {
    if(!root) return;

    queue<TreeNode*> Q;
    Q.push(root);

    while(!Q.empty()) {
        int size = Q.size();
        while(size--) {
            TreeNode* curr = Q.front();
            cout << curr->data << " ";
            Q.pop();

            if(curr->left != NULL) Q.push(curr->left);
            if(curr->right != NULL) Q.push(curr->right);
        }
        cout << endl;
    }
}

void levelOrder() {
    if(!root) return;

    queue<TreeNode*> Q;
    Q.push(root);

    while(!Q.empty()) {
        TreeNode* curr = Q.front();
        cout << curr->data << " ";
        Q.pop();

        if(curr->left) Q.push(curr->left);
        if(curr->right) Q.push(curr->right);
    }
}

void preOrder(TreeNode* root) {
    if(!root) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if(!root) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if(!root) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preorder_iter(TreeNode *root) {
    if (!root) return;
    
    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* curr = st.top();
        cout << curr->data << " ";
        st.pop();

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);
    }
}

void inorder_iter(TreeNode *root) {
    if (!root) return;
    
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(true) {
        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            if (st.empty() == true) return;

            curr = st.top();
            cout << curr->data << " ";
            st.pop();
            curr = curr->right;
        }
    }
}

void postorder_iter(TreeNode *root) {
    if (!root) return;

    stack<TreeNode*> S1, S2;
    S1.push(root);

    while(!S1.empty()) {
        TreeNode* curr = S1.top();
        S2.push(curr);
        S1.pop();

        if(curr->left) S1.push(curr->left);
        if(curr->right) S1.push(curr->right);

    }

    while(!S2.empty()) {
        cout << S2.top()->data << " ";
        S2.pop();
    }
}

// SINGLE STACK PREORDER ITERATIVE
void postorder_iter_single_stack(TreeNode *root) {
    if (!root) return;

    stack<TreeNode*> st;
    TreeNode* curr = root;

    while(curr != NULL or !st.empty()) {

        if (curr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* temp = st.top()->right;
            if (temp == NULL) {
                temp = st.top();
                cout << temp->data << " ";
                st.pop();

                while (!st.empty() and temp == st.top()->right)
                {
                    temp = st.top();
                    cout << temp->data << " ";
                    st.pop(); 
                }
            } else {
                curr = temp;
            }
        }
    }
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n; cin >> n;

    for(int i = 0; i<n; i++) {
        int node; cin >> node;
        insertNode(node);
    }

    cout << endl;
    printTree();
    cout << endl;


    cout << endl;
    cout << "LevelOrder: ";
    levelOrder();
    cout << endl;


    cout << endl;
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;


    cout << endl;
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;


    cout << endl;
    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;


    cout << endl;
    cout << "Iterative PreOrder: ";
    preorder_iter(root);
    cout << endl;


    cout << endl;
    cout << "Iterative InOrder: ";
    inorder_iter(root);
    cout << endl;


    cout << endl;
    cout << "Iterative PostOrder: ";
    postorder_iter(root);
    cout << endl;


    cout << endl;
    cout << "Iterative PostOrder Single Stack: ";
    postorder_iter_single_stack(root);
    cout << endl;
    

    return 0;
}