void preorder(TreeNode* root) {

    while(root) {

        // Check the left child of root.
        if(root->left == NULL) {

            cout << root->data << " ";

            root = root->right;
        } else {

            // Find the inorder predecessor of the root node.
            TreeNode* current = root->left;

            // Link may be present for the inorder predecessor.
            while(current->right and current->right != root) {

                current = current->right;
            }

            // Check for link.
            if(!current->right) {

                cout << root->data << " ";

                current->right = root;

                root = root->left;
            } else {

                current->right = NULL;
                root = root->right;
            }
        }
    }
}


void Inorder(TreeNode* root) {

    while(root) {

        // Check the left child of root.
        if(root->left == NULL) {

            cout << root->data << " ";

            root = root->right;
        } else {

            // Find the inorder predecessor of the root node.
            TreeNode* current = root->left;

            // Link may be present for the inorder predecessor.
            while(current->right and current->right != root) {

                current = current->right;
            }

            // Check for link.
            if(!current->right) {

                current->right = root;

                root = root->left;
            } else {

                cout << root->data << " ";

                current->right = NULL;

                root = root->right;
            }
        }
    }
}


void inorder(TreeNode* root)
{
    while(root) {
        if (root->left == NULL) {
            cout<<root->data << " ";
            root = root->right;
        }else{
            TreeNode* current =root->left;

            while(current->right and current->right!=root) {
                current = current->right;
            }

            if (current->right == NULL) {
                current->right = root;
                root = root->left;
            }else{
                cout<<current->data << " ";
                current->right = NULL;
                root = root->right;
            }
        }
    }
}