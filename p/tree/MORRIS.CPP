vector<int> inorder(TreeNode* root)
{
    TreeNode* curr = root;
    vector<int> ans;
    while (curr)
    {
        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* temp = curr->left;
            while(temp->right != NULL and temp->right != curr) {
                temp = temp->right;
            }

            if(temp->right == NULL) {
                temp->right = curr;
                curr = curr->left;
            } else {
                temp->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}


vector<int> preorder(TreeNode* root)
{
    TreeNode* curr = root;
    vector<int> ans;
    while (curr)
    {
        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* temp = curr->left;
            while(temp->right != NULL and temp->right != curr) {
                temp = temp->right;
            }

            if(temp->right == NULL) {
                temp->right = curr;
                ans.push_back(curr->val);
                curr = curr->left;
            } else {
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
    return ans;
}