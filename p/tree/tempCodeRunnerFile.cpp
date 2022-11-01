void printPreorder(TreeNode* root) {

//     if(root == NULL) {

//         return;
//     }

//     cout << root->data << " ";

//     printPreorder(root->left);

//     printPreorder(root->right);
// }

// void printInorder(TreeNode* root) {

//     if(root == NULL) {

//         return;
//     }

//     printInorder(root->left);

//     cout << root->data << " ";

//     printInorder(root->right);
// }

// void printPostorder(TreeNode* root) {

//     if(root == NULL) {

//         return;
//     }

//     printPostorder(root->left);

//     printPostorder(root->right);

//     cout << root->data << " ";
// }

// void preorder_iter(TreeNode *root) {

//     if (root == NULL) return;
    
//     stack<TreeNode*> S;
//     TreeNode* current = root;

//     while(current or !S.empty()) {

//         if(current) {
//             cout << current->data << " ";
//             if(current->right) S.push(current->right);
//             current = current->left;
//         } else {
//             current = S.top();
//             S.pop();
//         }
//     }
// }

// void inorder_iter(TreeNode *root) {

//     if (root == NULL) return;

//     stack<TreeNode*> S;
//     TreeNode* current = root;

//     while(current or !S.empty()) {

//         if(current) {
//             S.push(current);           
//             current = current->left;
//         } else {
//             current = S.top();
//             S.pop();
//             cout << current->data << " ";
//             current = current->right;
//         }
//     }
// }

// void postorder_iter(TreeNode *root) {

//     stack<TreeNode*> S1, S2;

//     S1.push(root);
//     while(!S1.empty()) {

//         S2.push(S1.top());
//         S1.pop();

//         if(S2.top()->left) S1.push(S2.top()->left);
//         if(S2.top()->right) S1.push(S2.top()->right);

//     }

//     while(!S2.empty()) {
//         cout << S2.top()->data << " ";
//         S2.pop();
//     }
// }

// // Iterative Postorder Traversal using 1 stacks and 1 vector.
// void printPostorderIterative(TreeNode *root) {

//     if(!root) return;

//     stack<TreeNode*> S;
//     vector<int> ans;

//     S.push(root);

//     while(!S.empty()) {

//         TreeNode* temp = S.top();
//         S.pop();
//         ans.push_back(temp->data);

//         if(temp->left) S.push(temp->left);

//         if(temp->right) S.push(temp->right);
//     }

//     reverse(ans.begin(), ans.end());

//     for(int i : ans) {

//         cout << i << " ";
//     }
// }

// // One stack
// void printPostorderIterative(TreeNode* root) {

//     stack<TreeNode*> S;
//     TreeNode* prev = NULL;
//     TreeNode* current = root;

//     while(current or !S.empty()) {

//         if(current) {

//             S.push(current);

//             current = current->left;
//         } else {

//             current = S.top();

//             if(!current->right or current->right == prev) {

//                 cout << current->data << " ";
                
//                 S.pop();
//                 prev = current;
//                 current = NULL;
//             } else {

//                 current = current->right;
//             }
//         }
//     }
// }
