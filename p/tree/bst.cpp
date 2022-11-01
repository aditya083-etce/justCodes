#include<bits/stdc++.h>
using namespace std;

struct TreeNode {

    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* root = NULL;

TreeNode* insertNode(TreeNode* root, int data) {

    if(!root) {

        TreeNode* newNode = new TreeNode;
        newNode->data = data;
        newNode->left = newNode->right = NULL;

        return newNode;
    }

    if(root->data == data) {

        cout << "Already present";

        return root;
    } else if(root->data > data) {

        root->left = insertNode(root->left, data);
    } else {

        root->right = insertNode(root->right, data);
    }

    return root;
}

bool searchNode(TreeNode* root, int data) {

    if(!root) {

        return false;
    } else if(root->data == data) {

        return true;
    } else if(root->data > data) {

        return searchNode(root->left, data);
    } else {

        return searchNode(root->right, data);
    }
}

void printLevelOrder() {

    if(root == NULL) {

        return;
    }

    queue<TreeNode*> Q;

    Q.push(root);

    while(!Q.empty()) {

        if(Q.front()->left != NULL) {

            Q.push(Q.front()->left);
        }

        if(Q.front()->right != NULL){

            Q.push(Q.front()->right);
        }

        cout << Q.front()->data << " ";

        Q.pop();
    }
}

int main() {


    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 3);

    int x;
    cin >> x;

    if(searchNode(root, x)) {

        cout << "Present";
    } else {

        cout << "Not present";
    }
     
    return 0;
}